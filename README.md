# SNormTest

Example of UNORM (GL_RGBA8) vs SNORM (GL_RGBA8_SNORM) vs SRGB (GL_SRGB8_ALPHA8) textures in GL.

Contains:

* Example of UNORM and SNORM and SRGB8_ALPHA8 textures in OpenGL.
* Example of using glTextureView to switch between them.
* Sample outputs (in this README.)

# Sample Output

This shows the result of converting an 8-bit value to a float value by either reading from a GL_R8 (aka GL_RGBA8_UNORM) texture or from a GL_RGBA8_SNORM texture or from a GL_SRGB8_ALPHA8 texture.

Each entry in the result shows the original 8-bit value and the float that it was converted to.

In the SNORM table, the signed value is also shown for 8-bit values that represent negative numbers in twos complement.

Results were produced on an Intel HD 540 GPU running Windows 10.

```
GL_VENDOR: Intel
GL_RENDERER: Intel(R) Iris(TM) Graphics 540
GL_VERSION: 4.4.0 - Build 21.20.16.4678

GL_RGBA8 (= GL_RGBA8_UNORM):
|   0 -> 0.000 |  64 -> 0.251 | 128 -> 0.502 | 192 -> 0.753 |
|   1 -> 0.004 |  65 -> 0.255 | 129 -> 0.506 | 193 -> 0.757 |
|   2 -> 0.008 |  66 -> 0.259 | 130 -> 0.510 | 194 -> 0.761 |
|   3 -> 0.012 |  67 -> 0.263 | 131 -> 0.514 | 195 -> 0.765 |
|   4 -> 0.016 |  68 -> 0.267 | 132 -> 0.518 | 196 -> 0.769 |
|   5 -> 0.020 |  69 -> 0.271 | 133 -> 0.522 | 197 -> 0.773 |
|   6 -> 0.024 |  70 -> 0.275 | 134 -> 0.525 | 198 -> 0.776 |
|   7 -> 0.027 |  71 -> 0.278 | 135 -> 0.529 | 199 -> 0.780 |
|   8 -> 0.031 |  72 -> 0.282 | 136 -> 0.533 | 200 -> 0.784 |
|   9 -> 0.035 |  73 -> 0.286 | 137 -> 0.537 | 201 -> 0.788 |
|  10 -> 0.039 |  74 -> 0.290 | 138 -> 0.541 | 202 -> 0.792 |
|  11 -> 0.043 |  75 -> 0.294 | 139 -> 0.545 | 203 -> 0.796 |
|  12 -> 0.047 |  76 -> 0.298 | 140 -> 0.549 | 204 -> 0.800 |
|  13 -> 0.051 |  77 -> 0.302 | 141 -> 0.553 | 205 -> 0.804 |
|  14 -> 0.055 |  78 -> 0.306 | 142 -> 0.557 | 206 -> 0.808 |
|  15 -> 0.059 |  79 -> 0.310 | 143 -> 0.561 | 207 -> 0.812 |
|  16 -> 0.063 |  80 -> 0.314 | 144 -> 0.565 | 208 -> 0.816 |
|  17 -> 0.067 |  81 -> 0.318 | 145 -> 0.569 | 209 -> 0.820 |
|  18 -> 0.071 |  82 -> 0.322 | 146 -> 0.573 | 210 -> 0.824 |
|  19 -> 0.075 |  83 -> 0.325 | 147 -> 0.576 | 211 -> 0.827 |
|  20 -> 0.078 |  84 -> 0.329 | 148 -> 0.580 | 212 -> 0.831 |
|  21 -> 0.082 |  85 -> 0.333 | 149 -> 0.584 | 213 -> 0.835 |
|  22 -> 0.086 |  86 -> 0.337 | 150 -> 0.588 | 214 -> 0.839 |
|  23 -> 0.090 |  87 -> 0.341 | 151 -> 0.592 | 215 -> 0.843 |
|  24 -> 0.094 |  88 -> 0.345 | 152 -> 0.596 | 216 -> 0.847 |
|  25 -> 0.098 |  89 -> 0.349 | 153 -> 0.600 | 217 -> 0.851 |
|  26 -> 0.102 |  90 -> 0.353 | 154 -> 0.604 | 218 -> 0.855 |
|  27 -> 0.106 |  91 -> 0.357 | 155 -> 0.608 | 219 -> 0.859 |
|  28 -> 0.110 |  92 -> 0.361 | 156 -> 0.612 | 220 -> 0.863 |
|  29 -> 0.114 |  93 -> 0.365 | 157 -> 0.616 | 221 -> 0.867 |
|  30 -> 0.118 |  94 -> 0.369 | 158 -> 0.620 | 222 -> 0.871 |
|  31 -> 0.122 |  95 -> 0.373 | 159 -> 0.624 | 223 -> 0.875 |
|  32 -> 0.125 |  96 -> 0.376 | 160 -> 0.627 | 224 -> 0.878 |
|  33 -> 0.129 |  97 -> 0.380 | 161 -> 0.631 | 225 -> 0.882 |
|  34 -> 0.133 |  98 -> 0.384 | 162 -> 0.635 | 226 -> 0.886 |
|  35 -> 0.137 |  99 -> 0.388 | 163 -> 0.639 | 227 -> 0.890 |
|  36 -> 0.141 | 100 -> 0.392 | 164 -> 0.643 | 228 -> 0.894 |
|  37 -> 0.145 | 101 -> 0.396 | 165 -> 0.647 | 229 -> 0.898 |
|  38 -> 0.149 | 102 -> 0.400 | 166 -> 0.651 | 230 -> 0.902 |
|  39 -> 0.153 | 103 -> 0.404 | 167 -> 0.655 | 231 -> 0.906 |
|  40 -> 0.157 | 104 -> 0.408 | 168 -> 0.659 | 232 -> 0.910 |
|  41 -> 0.161 | 105 -> 0.412 | 169 -> 0.663 | 233 -> 0.914 |
|  42 -> 0.165 | 106 -> 0.416 | 170 -> 0.667 | 234 -> 0.918 |
|  43 -> 0.169 | 107 -> 0.420 | 171 -> 0.671 | 235 -> 0.922 |
|  44 -> 0.173 | 108 -> 0.424 | 172 -> 0.675 | 236 -> 0.925 |
|  45 -> 0.176 | 109 -> 0.427 | 173 -> 0.678 | 237 -> 0.929 |
|  46 -> 0.180 | 110 -> 0.431 | 174 -> 0.682 | 238 -> 0.933 |
|  47 -> 0.184 | 111 -> 0.435 | 175 -> 0.686 | 239 -> 0.937 |
|  48 -> 0.188 | 112 -> 0.439 | 176 -> 0.690 | 240 -> 0.941 |
|  49 -> 0.192 | 113 -> 0.443 | 177 -> 0.694 | 241 -> 0.945 |
|  50 -> 0.196 | 114 -> 0.447 | 178 -> 0.698 | 242 -> 0.949 |
|  51 -> 0.200 | 115 -> 0.451 | 179 -> 0.702 | 243 -> 0.953 |
|  52 -> 0.204 | 116 -> 0.455 | 180 -> 0.706 | 244 -> 0.957 |
|  53 -> 0.208 | 117 -> 0.459 | 181 -> 0.710 | 245 -> 0.961 |
|  54 -> 0.212 | 118 -> 0.463 | 182 -> 0.714 | 246 -> 0.965 |
|  55 -> 0.216 | 119 -> 0.467 | 183 -> 0.718 | 247 -> 0.969 |
|  56 -> 0.220 | 120 -> 0.471 | 184 -> 0.722 | 248 -> 0.973 |
|  57 -> 0.224 | 121 -> 0.475 | 185 -> 0.725 | 249 -> 0.976 |
|  58 -> 0.227 | 122 -> 0.478 | 186 -> 0.729 | 250 -> 0.980 |
|  59 -> 0.231 | 123 -> 0.482 | 187 -> 0.733 | 251 -> 0.984 |
|  60 -> 0.235 | 124 -> 0.486 | 188 -> 0.737 | 252 -> 0.988 |
|  61 -> 0.239 | 125 -> 0.490 | 189 -> 0.741 | 253 -> 0.992 |
|  62 -> 0.243 | 126 -> 0.494 | 190 -> 0.745 | 254 -> 0.996 |
|  63 -> 0.247 | 127 -> 0.498 | 191 -> 0.749 | 255 -> 1.000 |

GL_RGBA8_SNORM:
|   0 -> 0.000 |  64 -> 0.504 | 128 (-128) -> -1.000 | 192 ( -64) -> -0.504 |
|   1 -> 0.008 |  65 -> 0.512 | 129 (-127) -> -1.000 | 193 ( -63) -> -0.496 |
|   2 -> 0.016 |  66 -> 0.520 | 130 (-126) -> -0.992 | 194 ( -62) -> -0.488 |
|   3 -> 0.024 |  67 -> 0.528 | 131 (-125) -> -0.984 | 195 ( -61) -> -0.480 |
|   4 -> 0.031 |  68 -> 0.535 | 132 (-124) -> -0.976 | 196 ( -60) -> -0.472 |
|   5 -> 0.039 |  69 -> 0.543 | 133 (-123) -> -0.969 | 197 ( -59) -> -0.465 |
|   6 -> 0.047 |  70 -> 0.551 | 134 (-122) -> -0.961 | 198 ( -58) -> -0.457 |
|   7 -> 0.055 |  71 -> 0.559 | 135 (-121) -> -0.953 | 199 ( -57) -> -0.449 |
|   8 -> 0.063 |  72 -> 0.567 | 136 (-120) -> -0.945 | 200 ( -56) -> -0.441 |
|   9 -> 0.071 |  73 -> 0.575 | 137 (-119) -> -0.937 | 201 ( -55) -> -0.433 |
|  10 -> 0.079 |  74 -> 0.583 | 138 (-118) -> -0.929 | 202 ( -54) -> -0.425 |
|  11 -> 0.087 |  75 -> 0.591 | 139 (-117) -> -0.921 | 203 ( -53) -> -0.417 |
|  12 -> 0.094 |  76 -> 0.598 | 140 (-116) -> -0.913 | 204 ( -52) -> -0.409 |
|  13 -> 0.102 |  77 -> 0.606 | 141 (-115) -> -0.906 | 205 ( -51) -> -0.402 |
|  14 -> 0.110 |  78 -> 0.614 | 142 (-114) -> -0.898 | 206 ( -50) -> -0.394 |
|  15 -> 0.118 |  79 -> 0.622 | 143 (-113) -> -0.890 | 207 ( -49) -> -0.386 |
|  16 -> 0.126 |  80 -> 0.630 | 144 (-112) -> -0.882 | 208 ( -48) -> -0.378 |
|  17 -> 0.134 |  81 -> 0.638 | 145 (-111) -> -0.874 | 209 ( -47) -> -0.370 |
|  18 -> 0.142 |  82 -> 0.646 | 146 (-110) -> -0.866 | 210 ( -46) -> -0.362 |
|  19 -> 0.150 |  83 -> 0.654 | 147 (-109) -> -0.858 | 211 ( -45) -> -0.354 |
|  20 -> 0.157 |  84 -> 0.661 | 148 (-108) -> -0.850 | 212 ( -44) -> -0.346 |
|  21 -> 0.165 |  85 -> 0.669 | 149 (-107) -> -0.843 | 213 ( -43) -> -0.339 |
|  22 -> 0.173 |  86 -> 0.677 | 150 (-106) -> -0.835 | 214 ( -42) -> -0.331 |
|  23 -> 0.181 |  87 -> 0.685 | 151 (-105) -> -0.827 | 215 ( -41) -> -0.323 |
|  24 -> 0.189 |  88 -> 0.693 | 152 (-104) -> -0.819 | 216 ( -40) -> -0.315 |
|  25 -> 0.197 |  89 -> 0.701 | 153 (-103) -> -0.811 | 217 ( -39) -> -0.307 |
|  26 -> 0.205 |  90 -> 0.709 | 154 (-102) -> -0.803 | 218 ( -38) -> -0.299 |
|  27 -> 0.213 |  91 -> 0.717 | 155 (-101) -> -0.795 | 219 ( -37) -> -0.291 |
|  28 -> 0.220 |  92 -> 0.724 | 156 (-100) -> -0.787 | 220 ( -36) -> -0.283 |
|  29 -> 0.228 |  93 -> 0.732 | 157 ( -99) -> -0.780 | 221 ( -35) -> -0.276 |
|  30 -> 0.236 |  94 -> 0.740 | 158 ( -98) -> -0.772 | 222 ( -34) -> -0.268 |
|  31 -> 0.244 |  95 -> 0.748 | 159 ( -97) -> -0.764 | 223 ( -33) -> -0.260 |
|  32 -> 0.252 |  96 -> 0.756 | 160 ( -96) -> -0.756 | 224 ( -32) -> -0.252 |
|  33 -> 0.260 |  97 -> 0.764 | 161 ( -95) -> -0.748 | 225 ( -31) -> -0.244 |
|  34 -> 0.268 |  98 -> 0.772 | 162 ( -94) -> -0.740 | 226 ( -30) -> -0.236 |
|  35 -> 0.276 |  99 -> 0.780 | 163 ( -93) -> -0.732 | 227 ( -29) -> -0.228 |
|  36 -> 0.283 | 100 -> 0.787 | 164 ( -92) -> -0.724 | 228 ( -28) -> -0.220 |
|  37 -> 0.291 | 101 -> 0.795 | 165 ( -91) -> -0.717 | 229 ( -27) -> -0.213 |
|  38 -> 0.299 | 102 -> 0.803 | 166 ( -90) -> -0.709 | 230 ( -26) -> -0.205 |
|  39 -> 0.307 | 103 -> 0.811 | 167 ( -89) -> -0.701 | 231 ( -25) -> -0.197 |
|  40 -> 0.315 | 104 -> 0.819 | 168 ( -88) -> -0.693 | 232 ( -24) -> -0.189 |
|  41 -> 0.323 | 105 -> 0.827 | 169 ( -87) -> -0.685 | 233 ( -23) -> -0.181 |
|  42 -> 0.331 | 106 -> 0.835 | 170 ( -86) -> -0.677 | 234 ( -22) -> -0.173 |
|  43 -> 0.339 | 107 -> 0.843 | 171 ( -85) -> -0.669 | 235 ( -21) -> -0.165 |
|  44 -> 0.346 | 108 -> 0.850 | 172 ( -84) -> -0.661 | 236 ( -20) -> -0.157 |
|  45 -> 0.354 | 109 -> 0.858 | 173 ( -83) -> -0.654 | 237 ( -19) -> -0.150 |
|  46 -> 0.362 | 110 -> 0.866 | 174 ( -82) -> -0.646 | 238 ( -18) -> -0.142 |
|  47 -> 0.370 | 111 -> 0.874 | 175 ( -81) -> -0.638 | 239 ( -17) -> -0.134 |
|  48 -> 0.378 | 112 -> 0.882 | 176 ( -80) -> -0.630 | 240 ( -16) -> -0.126 |
|  49 -> 0.386 | 113 -> 0.890 | 177 ( -79) -> -0.622 | 241 ( -15) -> -0.118 |
|  50 -> 0.394 | 114 -> 0.898 | 178 ( -78) -> -0.614 | 242 ( -14) -> -0.110 |
|  51 -> 0.402 | 115 -> 0.906 | 179 ( -77) -> -0.606 | 243 ( -13) -> -0.102 |
|  52 -> 0.409 | 116 -> 0.913 | 180 ( -76) -> -0.598 | 244 ( -12) -> -0.094 |
|  53 -> 0.417 | 117 -> 0.921 | 181 ( -75) -> -0.591 | 245 ( -11) -> -0.087 |
|  54 -> 0.425 | 118 -> 0.929 | 182 ( -74) -> -0.583 | 246 ( -10) -> -0.079 |
|  55 -> 0.433 | 119 -> 0.937 | 183 ( -73) -> -0.575 | 247 (  -9) -> -0.071 |
|  56 -> 0.441 | 120 -> 0.945 | 184 ( -72) -> -0.567 | 248 (  -8) -> -0.063 |
|  57 -> 0.449 | 121 -> 0.953 | 185 ( -71) -> -0.559 | 249 (  -7) -> -0.055 |
|  58 -> 0.457 | 122 -> 0.961 | 186 ( -70) -> -0.551 | 250 (  -6) -> -0.047 |
|  59 -> 0.465 | 123 -> 0.969 | 187 ( -69) -> -0.543 | 251 (  -5) -> -0.039 |
|  60 -> 0.472 | 124 -> 0.976 | 188 ( -68) -> -0.535 | 252 (  -4) -> -0.031 |
|  61 -> 0.480 | 125 -> 0.984 | 189 ( -67) -> -0.528 | 253 (  -3) -> -0.024 |
|  62 -> 0.488 | 126 -> 0.992 | 190 ( -66) -> -0.520 | 254 (  -2) -> -0.016 |
|  63 -> 0.496 | 127 -> 1.000 | 191 ( -65) -> -0.512 | 255 (  -1) -> -0.008 |

GL_SRGB8_ALPHA8:
|   0 -> 0.000 |  64 -> 0.051 | 128 -> 0.216 | 192 -> 0.528 |
|   1 -> 0.000 |  65 -> 0.053 | 129 -> 0.220 | 193 -> 0.534 |
|   2 -> 0.001 |  66 -> 0.055 | 130 -> 0.224 | 194 -> 0.541 |
|   3 -> 0.001 |  67 -> 0.056 | 131 -> 0.227 | 195 -> 0.547 |
|   4 -> 0.001 |  68 -> 0.058 | 132 -> 0.231 | 196 -> 0.553 |
|   5 -> 0.002 |  69 -> 0.060 | 133 -> 0.235 | 197 -> 0.559 |
|   6 -> 0.002 |  70 -> 0.061 | 134 -> 0.239 | 198 -> 0.566 |
|   7 -> 0.002 |  71 -> 0.063 | 135 -> 0.243 | 199 -> 0.572 |
|   8 -> 0.002 |  72 -> 0.065 | 136 -> 0.247 | 200 -> 0.579 |
|   9 -> 0.003 |  73 -> 0.067 | 137 -> 0.251 | 201 -> 0.585 |
|  10 -> 0.003 |  74 -> 0.069 | 138 -> 0.255 | 202 -> 0.592 |
|  11 -> 0.003 |  75 -> 0.070 | 139 -> 0.259 | 203 -> 0.598 |
|  12 -> 0.004 |  76 -> 0.072 | 140 -> 0.263 | 204 -> 0.605 |
|  13 -> 0.004 |  77 -> 0.074 | 141 -> 0.267 | 205 -> 0.611 |
|  14 -> 0.004 |  78 -> 0.076 | 142 -> 0.271 | 206 -> 0.618 |
|  15 -> 0.005 |  79 -> 0.078 | 143 -> 0.275 | 207 -> 0.625 |
|  16 -> 0.005 |  80 -> 0.080 | 144 -> 0.279 | 208 -> 0.632 |
|  17 -> 0.006 |  81 -> 0.082 | 145 -> 0.283 | 209 -> 0.639 |
|  18 -> 0.006 |  82 -> 0.084 | 146 -> 0.288 | 210 -> 0.645 |
|  19 -> 0.006 |  83 -> 0.086 | 147 -> 0.292 | 211 -> 0.652 |
|  20 -> 0.007 |  84 -> 0.089 | 148 -> 0.296 | 212 -> 0.659 |
|  21 -> 0.007 |  85 -> 0.091 | 149 -> 0.301 | 213 -> 0.666 |
|  22 -> 0.008 |  86 -> 0.093 | 150 -> 0.305 | 214 -> 0.673 |
|  23 -> 0.009 |  87 -> 0.095 | 151 -> 0.310 | 215 -> 0.680 |
|  24 -> 0.009 |  88 -> 0.098 | 152 -> 0.314 | 216 -> 0.687 |
|  25 -> 0.010 |  89 -> 0.100 | 153 -> 0.319 | 217 -> 0.695 |
|  26 -> 0.010 |  90 -> 0.102 | 154 -> 0.323 | 218 -> 0.702 |
|  27 -> 0.011 |  91 -> 0.105 | 155 -> 0.328 | 219 -> 0.709 |
|  28 -> 0.012 |  92 -> 0.107 | 156 -> 0.333 | 220 -> 0.716 |
|  29 -> 0.012 |  93 -> 0.109 | 157 -> 0.337 | 221 -> 0.724 |
|  30 -> 0.013 |  94 -> 0.112 | 158 -> 0.342 | 222 -> 0.731 |
|  31 -> 0.014 |  95 -> 0.114 | 159 -> 0.347 | 223 -> 0.739 |
|  32 -> 0.014 |  96 -> 0.117 | 160 -> 0.352 | 224 -> 0.746 |
|  33 -> 0.015 |  97 -> 0.119 | 161 -> 0.357 | 225 -> 0.754 |
|  34 -> 0.016 |  98 -> 0.122 | 162 -> 0.361 | 226 -> 0.761 |
|  35 -> 0.017 |  99 -> 0.125 | 163 -> 0.366 | 227 -> 0.769 |
|  36 -> 0.018 | 100 -> 0.127 | 164 -> 0.371 | 228 -> 0.776 |
|  37 -> 0.018 | 101 -> 0.130 | 165 -> 0.376 | 229 -> 0.784 |
|  38 -> 0.019 | 102 -> 0.133 | 166 -> 0.381 | 230 -> 0.792 |
|  39 -> 0.020 | 103 -> 0.136 | 167 -> 0.386 | 231 -> 0.800 |
|  40 -> 0.021 | 104 -> 0.138 | 168 -> 0.392 | 232 -> 0.807 |
|  41 -> 0.022 | 105 -> 0.141 | 169 -> 0.397 | 233 -> 0.815 |
|  42 -> 0.023 | 106 -> 0.144 | 170 -> 0.402 | 234 -> 0.823 |
|  43 -> 0.024 | 107 -> 0.147 | 171 -> 0.407 | 235 -> 0.831 |
|  44 -> 0.025 | 108 -> 0.150 | 172 -> 0.412 | 236 -> 0.839 |
|  45 -> 0.026 | 109 -> 0.153 | 173 -> 0.418 | 237 -> 0.847 |
|  46 -> 0.027 | 110 -> 0.156 | 174 -> 0.423 | 238 -> 0.855 |
|  47 -> 0.028 | 111 -> 0.159 | 175 -> 0.429 | 239 -> 0.864 |
|  48 -> 0.029 | 112 -> 0.162 | 176 -> 0.434 | 240 -> 0.872 |
|  49 -> 0.031 | 113 -> 0.165 | 177 -> 0.440 | 241 -> 0.880 |
|  50 -> 0.032 | 114 -> 0.168 | 178 -> 0.445 | 242 -> 0.888 |
|  51 -> 0.033 | 115 -> 0.171 | 179 -> 0.451 | 243 -> 0.897 |
|  52 -> 0.034 | 116 -> 0.174 | 180 -> 0.456 | 244 -> 0.905 |
|  53 -> 0.035 | 117 -> 0.178 | 181 -> 0.462 | 245 -> 0.913 |
|  54 -> 0.037 | 118 -> 0.181 | 182 -> 0.468 | 246 -> 0.922 |
|  55 -> 0.038 | 119 -> 0.184 | 183 -> 0.473 | 247 -> 0.930 |
|  56 -> 0.039 | 120 -> 0.187 | 184 -> 0.479 | 248 -> 0.939 |
|  57 -> 0.041 | 121 -> 0.191 | 185 -> 0.485 | 249 -> 0.947 |
|  58 -> 0.042 | 122 -> 0.194 | 186 -> 0.491 | 250 -> 0.956 |
|  59 -> 0.043 | 123 -> 0.198 | 187 -> 0.497 | 251 -> 0.965 |
|  60 -> 0.045 | 124 -> 0.201 | 188 -> 0.503 | 252 -> 0.974 |
|  61 -> 0.046 | 125 -> 0.205 | 189 -> 0.509 | 253 -> 0.982 |
|  62 -> 0.048 | 126 -> 0.208 | 190 -> 0.515 | 254 -> 0.991 |
|  63 -> 0.049 | 127 -> 0.212 | 191 -> 0.521 | 255 -> 1.000 |
```
