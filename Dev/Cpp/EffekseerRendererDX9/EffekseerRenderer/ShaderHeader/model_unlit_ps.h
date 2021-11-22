#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_3_0 /Emain /Fh ShaderHeader/model_unlit_ps.h
//    Shader/model_unlit_ps.fx
//
//
// Parameters:
//
//   sampler2D Sampler_sampler_colorTex;
//   float4 _113_fEmissiveScaling;
//   float4 _113_miscFlags;
//
//
// Registers:
//
//   Name                     Reg   Size
//   ------------------------ ----- ----
//   _113_fEmissiveScaling    c10      1
//   _113_miscFlags           c17      1
//   Sampler_sampler_colorTex s0       1
//

    ps_3_0
    def c0, 1.1920929e-007, 0.416666657, 1.05499995, -0.0549999997
    def c1, 0.305306017, 0.682171106, 0, 0
    def c2, 0, -1, -0, 0.0125228781
    dcl_texcoord_centroid v0
    dcl_texcoord1_centroid v1.xy
    dcl_2d s0
    texld r0, v1, s0
    abs r1.x, c17.x
    max r1.yzw, r0_abs.xxyz, c0.x
    log r2.x, r1.y
    log r2.y, r1.z
    log r2.z, r1.w
    mul r1.yzw, r2.xxyz, c0.y
    exp r2.x, r1.y
    exp r2.y, r1.z
    exp r2.z, r1.w
    mad r1.yzw, r2.xxyz, c0.z, c0.w
    max r2.xyz, r1.yzww, c2.x
    cmp r0.xyz, -r1.x, r0, r2
    mul r0, r0, v0
    cmp r2, -r0_abs.w, c2.y, c2.z
    texkill r2
    mul r0.xyz, r0, c10.x
    mad r1.yzw, r0.xxyz, c1.x, c1.y
    mad r1.yzw, r0.xxyz, r1, c2.w
    mul r1.yzw, r0.xxyz, r1
    min r2.xyz, r1.yzww, r0
    cmp oC0.xyz, -r1.x, r0, r2
    mov oC0.w, r0.w

// approximately 23 instruction slots used (1 texture, 22 arithmetic)
#endif

const BYTE g_ps30_main[] =
{
      0,   3, 255, 255, 254, 255, 
     62,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 194,   0, 
      0,   0,   0,   3, 255, 255, 
      3,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
    187,   0,   0,   0,  88,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   2,   0, 116,   0, 
      0,   0,   0,   0,   0,   0, 
    132,   0,   0,   0,   2,   0, 
     10,   0,   1,   0,  42,   0, 
    156,   0,   0,   0,   0,   0, 
      0,   0, 172,   0,   0,   0, 
      2,   0,  17,   0,   1,   0, 
     70,   0, 156,   0,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    115,  97, 109, 112, 108, 101, 
    114,  95,  99, 111, 108, 111, 
    114,  84, 101, 120,   0, 171, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     95,  49,  49,  51,  95, 102, 
     69, 109, 105, 115, 115, 105, 
    118, 101,  83,  99,  97, 108, 
    105, 110, 103,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  95,  49, 
     49,  51,  95, 109, 105, 115, 
     99,  70, 108,  97, 103, 115, 
      0, 112, 115,  95,  51,  95, 
     48,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171,  81,   0, 
      0,   5,   0,   0,  15, 160, 
      0,   0,   0,  52,  85,  85, 
    213,  62,  61,  10, 135,  63, 
    174,  71,  97, 189,  81,   0, 
      0,   5,   1,   0,  15, 160, 
     18,  81, 156,  62, 196, 162, 
     46,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  81,   0, 
      0,   5,   2,   0,  15, 160, 
      0,   0,   0,   0,   0,   0, 
    128, 191,   0,   0,   0, 128, 
    194,  44,  77,  60,  31,   0, 
      0,   2,   5,   0,   0, 128, 
      0,   0,  79, 144,  31,   0, 
      0,   2,   5,   0,   1, 128, 
      1,   0,  67, 144,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      1,   0, 228, 144,   0,   8, 
    228, 160,  35,   0,   0,   2, 
      1,   0,   1, 128,  17,   0, 
      0, 160,  11,   0,   0,   3, 
      1,   0,  14, 128,   0,   0, 
    144, 139,   0,   0,   0, 160, 
     15,   0,   0,   2,   2,   0, 
      1, 128,   1,   0,  85, 128, 
     15,   0,   0,   2,   2,   0, 
      2, 128,   1,   0, 170, 128, 
     15,   0,   0,   2,   2,   0, 
      4, 128,   1,   0, 255, 128, 
      5,   0,   0,   3,   1,   0, 
     14, 128,   2,   0, 144, 128, 
      0,   0,  85, 160,  14,   0, 
      0,   2,   2,   0,   1, 128, 
      1,   0,  85, 128,  14,   0, 
      0,   2,   2,   0,   2, 128, 
      1,   0, 170, 128,  14,   0, 
      0,   2,   2,   0,   4, 128, 
      1,   0, 255, 128,   4,   0, 
      0,   4,   1,   0,  14, 128, 
      2,   0, 144, 128,   0,   0, 
    170, 160,   0,   0, 255, 160, 
     11,   0,   0,   3,   2,   0, 
      7, 128,   1,   0, 249, 128, 
      2,   0,   0, 160,  88,   0, 
      0,   4,   0,   0,   7, 128, 
      1,   0,   0, 129,   0,   0, 
    228, 128,   2,   0, 228, 128, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      0,   0, 228, 144,  88,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0, 255, 140,   2,   0, 
     85, 160,   2,   0, 170, 160, 
     65,   0,   0,   1,   2,   0, 
     15, 128,   5,   0,   0,   3, 
      0,   0,   7, 128,   0,   0, 
    228, 128,  10,   0,   0, 160, 
      4,   0,   0,   4,   1,   0, 
     14, 128,   0,   0, 144, 128, 
      1,   0,   0, 160,   1,   0, 
     85, 160,   4,   0,   0,   4, 
      1,   0,  14, 128,   0,   0, 
    144, 128,   1,   0, 228, 128, 
      2,   0, 255, 160,   5,   0, 
      0,   3,   1,   0,  14, 128, 
      0,   0, 144, 128,   1,   0, 
    228, 128,  10,   0,   0,   3, 
      2,   0,   7, 128,   1,   0, 
    249, 128,   0,   0, 228, 128, 
     88,   0,   0,   4,   0,   8, 
      7, 128,   1,   0,   0, 129, 
      0,   0, 228, 128,   2,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   8,   8, 128,   0,   0, 
    255, 128, 255, 255,   0,   0
};
