#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstdlib>
#include <cassert>

void APIENTRY DebugCallbackGL(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    fprintf(stderr, "DebugCallbackGL: %s\n", message);
}

int main()
{

    if (!glfwInit())
    {
        fprintf(stderr, "Error: GLFW initialization failed\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Error: Window or context creation failed\n");
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));


    // Enable OpenGL debugging
#ifdef _DEBUG
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(DebugCallbackGL, 0);
#endif

    printf("GL_VENDOR: %s\n", glGetString(GL_VENDOR));
    printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
    printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
    printf("\n");

    const unsigned int width = 2;

    unsigned char all8bitpixels[width * 4];
    for (int i = 0; i < width; i++)
    {
        int r = i / (float)(width - 1) * 0xFF;
        all8bitpixels[i * 4 + 0] = r;
        all8bitpixels[i * 4 + 1] = r;
        all8bitpixels[i * 4 + 2] = r;
        all8bitpixels[i * 4 + 3] = r;
        printf("%d: 0x%02X (%d)\n", i, r, sizeof(all8bitpixels));
    }

    // Initialize the texture with raw 8-bit data in it.
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_1D, texture);
    glTexStorage1D(GL_TEXTURE_1D, 1, GL_RGBA8UI, width);
    glTexSubImage1D(GL_TEXTURE_1D, 0, 0, width, GL_RGBA_INTEGER, GL_UNSIGNED_BYTE, all8bitpixels);
    glBindTexture(GL_TEXTURE_1D, 0);

    // Create a UNORM view of the 8-bit data
    GLuint unormView;
    glGenTextures(1, &unormView);
    glTextureView(unormView, GL_TEXTURE_1D, texture, GL_RGBA8, 0, 1, 0, 1);

    // Create a SNORM view of the 8-bit data
    GLuint snormView;
    glGenTextures(1, &snormView);
    glTextureView(snormView, GL_TEXTURE_1D, texture, GL_RGBA8_SNORM, 0, 1, 0, 1);

    // Create a SRGB view of the 8-bit data
    GLuint srgbView;
    glGenTextures(1, &srgbView);
    glTextureView(srgbView, GL_TEXTURE_1D, texture, GL_SRGB8_ALPHA8, 0, 1, 0, 1);

    // Create a buffer to store the results of the test
    unsigned int steps = 1 << 8; // above 256 will resolve the same pixel
    GLuint resultsBuf;
    glGenBuffers(1, &resultsBuf);
    glBindBuffer(GL_ARRAY_BUFFER, resultsBuf);
    glBufferStorage(GL_ARRAY_BUFFER, sizeof(GLfloat) * width * steps, NULL, GL_MAP_READ_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Compute shader that just converts every 8-bit value into a float and stores the result in a buffer.
    const char* srcs[] = {
R"GLSL(
#version 420 core

#extension GL_ARB_compute_shader : require
#extension GL_ARB_shader_storage_buffer_object : require

layout(binding = 0)
uniform sampler1D all8bitpixels;

uniform uint steps;
uniform uint width;

layout(std430, binding = 0)
buffer ResultsBuffer { float Results[]; };

layout(local_size_x = 1) in;
void main()
{
    for (int i = 0; i < width * steps; i++)
    {
        Results[i] = texture(all8bitpixels, 0.5 / float(width) + i / float(width * steps)).r;
    }
}
)GLSL"
    };

    GLuint program = glCreateShaderProgramv(GL_COMPUTE_SHADER, sizeof(srcs) / sizeof(*srcs), srcs);
    GLint logLength;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0)
    {
        GLchar* infolog = (GLchar*)malloc(logLength);
        glGetProgramInfoLog(program, logLength, NULL, infolog);
        fprintf(stderr, "%s", infolog);
        free(infolog);
    }

    // Run the test once for each view
    GLuint views[] = { unormView, snormView, srgbView };
    const char* viewNames[] = { "GL_RGBA8 (= GL_RGBA8_UNORM)", "GL_RGBA8_SNORM", "GL_SRGB8_ALPHA8" };

    for (int viewIdx = 0; viewIdx < sizeof(views) / sizeof(*views); viewIdx++)
    {
        GLuint view = views[viewIdx];
        const char* viewName = viewNames[viewIdx];

        // Bind shader resources
        glBindTextures(0, 1, &view);
        glBindBuffersBase(GL_SHADER_STORAGE_BUFFER, 0, 1, &resultsBuf);

        // Run the test
        glUseProgram(program);
        glUniform1ui(glGetUniformLocation(program, "steps"), steps);
        glUniform1ui(glGetUniformLocation(program, "width"), width);
        glDispatchCompute(1, 1, 1);
        glUseProgram(0);

        // Unbind shader resources
        glBindTextures(0, 1, NULL);
        glBindBuffersBase(GL_SHADER_STORAGE_BUFFER, 0, 1, NULL);

        // Make sure all writes to the buffer are done before reading them.
        glMemoryBarrier(GL_ALL_BARRIER_BITS);

        // Map the buffer to be able to read its data.
        glBindBuffer(GL_ARRAY_BUFFER, resultsBuf);
        GLfloat* results = (GLfloat*)glMapBufferRange(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * width * steps, GL_MAP_READ_BIT);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Output the table of values
        printf("%s:\n", viewName);
        int nCols = 2;
        int nRows = width / nCols * steps;
        assert(nCols * nRows == width * steps);
        for (int row = 0; row < nRows; row++)
        {
            printf("| ");
            for (int col = 0; col < nCols; col++)
            {
                int i = row + col * nRows;

                if (view == unormView || view == srgbView || (view == snormView && i < width/2 * steps))
                {
                    printf("%6.2f -> %6.3f | ", i / (float)steps, results[i]);
                }
                else
                {
                    printf("%6.2f (%7.2f) -> %6.3f | ", i / (float)steps, i / (float)steps - (float)width, results[i]);
                }
            }
            printf("\n");
        }
        printf("\n");

        // Unmap the buffer
        glBindBuffer(GL_ARRAY_BUFFER, resultsBuf);
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
