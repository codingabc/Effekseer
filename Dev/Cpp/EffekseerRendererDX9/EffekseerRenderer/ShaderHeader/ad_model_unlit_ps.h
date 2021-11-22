#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_3_0 /Emain /Fh ShaderHeader/ad_model_unlit_ps.h
//    Shader/ad_model_unlit_ps.fx
//
//
// Parameters:
//
//   sampler2D Sampler_sampler_alphaTex;
//   sampler2D Sampler_sampler_blendAlphaTex;
//   sampler2D Sampler_sampler_blendTex;
//   sampler2D Sampler_sampler_blendUVDistortionTex;
//   sampler2D Sampler_sampler_colorTex;
//   sampler2D Sampler_sampler_uvDistortionTex;
//   float4 _289_fBlendTextureParameter;
//   float4 _289_fCameraFrontDirection;
//   float4 _289_fEdgeColor;
//   float4 _289_fEdgeParameter;
//   float4 _289_fEmissiveScaling;
//   float4 _289_fFalloffBeginColor;
//   float4 _289_fFalloffEndColor;
//   float4 _289_fFalloffParameter;
//   float4 _289_fFlipbookParameter;
//   float4 _289_fUVDistortionParameter;
//   float4 _289_miscFlags;
//
//
// Registers:
//
//   Name                                 Reg   Size
//   ------------------------------------ ----- ----
//   _289_fFlipbookParameter              c3       1
//   _289_fUVDistortionParameter          c4       1
//   _289_fBlendTextureParameter          c5       1
//   _289_fCameraFrontDirection           c6       1
//   _289_fFalloffParameter               c7       1
//   _289_fFalloffBeginColor              c8       1
//   _289_fFalloffEndColor                c9       1
//   _289_fEmissiveScaling                c10      1
//   _289_fEdgeColor                      c11      1
//   _289_fEdgeParameter                  c12      1
//   _289_miscFlags                       c17      1
//   Sampler_sampler_colorTex             s0       1
//   Sampler_sampler_alphaTex             s1       1
//   Sampler_sampler_uvDistortionTex      s2       1
//   Sampler_sampler_blendTex             s3       1
//   Sampler_sampler_blendAlphaTex        s4       1
//   Sampler_sampler_blendUVDistortionTex s5       1
//

    ps_3_0
    def c0, 2, -1, 1.1920929e-007, 0.416666657
    def c1, 1.05499995, -0.0549999997, 0, 1
    def c2, -1, -2, -3, 0.0125228781
    def c13, 0.305306017, 0.682171106, 0, 0
    dcl_texcoord_centroid v0
    dcl_texcoord1_centroid v1
    dcl_texcoord2 v2.xyz
    dcl_texcoord3 v3
    dcl_texcoord4 v4
    dcl_texcoord5 v5
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    dcl_2d s5
    texld r0, v3.zwzw, s2
    mad r0.xy, r0, c0.x, c0.y
    mad r0.z, r0.y, -c4.w, c4.z
    mad r0.yw, r0.xxzz, c4.x, v1.xxzy
    texld r1, r0.ywzw, s0
    abs r0.y, c17.x
    max r2.xyz, r1_abs, c0.z
    log r3.x, r2.x
    log r3.y, r2.y
    log r3.z, r2.z
    mul r2.xyz, r3, c0.w
    exp r3.x, r2.x
    exp r3.y, r2.y
    exp r3.z, r2.z
    mad r2.xyz, r3, c1.x, c1.y
    max r3.xyz, r2, c1.z
    cmp r1.xyz, -r0.y, r1, r3
    mul r1, r1, v0
    mad r2.xy, r0.xzzw, c4.x, v5.zwzw
    texld r2, r2, s0
    mov r3.xy, c0
    add r0.w, r3.y, c3.y
    mad r2, r2, v0, -r1
    mad r2, v1.z, r2, r1
    cmp r2, -r0_abs.w, r2, r1
    cmp r1, -c3.x, r1, r2
    mad r0.xz, r0, c4.x, v3.xyyw
    texld r2, r0.xzzw, s1
    mul r0.x, r2.w, r2.x
    mul r2.w, r0.x, r1.w
    texld r4, v4.zwzw, s5
    mad r4.xy, r4, c0.x, c0.y
    mad r4.z, r4.y, -c4.w, c4.z
    mad r0.xz, r4, c4.y, v5.xyyw
    texld r5, r0.xzzw, s3
    max r0.xzw, r5_abs.xyyz, c0.z
    log r6.x, r0.x
    log r6.y, r0.z
    log r6.z, r0.w
    mul r0.xzw, r6.xyyz, c0.w
    exp r6.x, r0.x
    exp r6.y, r0.z
    exp r6.z, r0.w
    mad r0.xzw, r6.xyyz, c1.x, c1.y
    max r6.xyz, r0.xzww, c1.z
    cmp r0.xzw, -r0.y, r5.xyyz, r6.xyyz
    mad r3.zw, r4.xyxz, c4.y, v4.xyxy
    texld r4, r3.zwzw, s4
    mul r1.w, r4.w, r4.x
    mul r1.w, r1.w, r5.w
    abs r3.z, c5.x
    mul r4.xyz, r0.xzww, r1.w
    lrp r5.xyz, r1.w, r0.xzww, r1
    mov r6.xyz, c2
    add r6.xyz, r6, c5.x
    mad r7.xyz, r0.xzww, r1.w, r1
    mad r0.xzw, r0, -r1.w, r1.xyyz
    mul r4.xyz, r1, r4
    cmp r1.xyz, -r6_abs.z, r4, r1
    cmp r0.xzw, -r6_abs.y, r0, r1.xyyz
    cmp r0.xzw, -r6_abs.x, r7.xyyz, r0
    cmp r2.xyz, -r3.z, r5, r0.xzww
    add r0.xzw, -r3_abs.yyyx, c7.xyyy
    nrm r1.xyz, -c6
    nrm r3.xyz, v2
    dp3_sat r1.x, r1, r3
    pow r3.x, r1.x, c7.z
    mov r1, c9
    add r1, -r1, c8
    mad r1, r3.x, r1, c9
    abs r3.x, c7.y
    add r3.yzw, r1.xxyz, r2.xxyz
    add r4.xyz, -r1, r2
    mul r1.xyz, r1, r2
    cmp r1.xyz, -r0_abs.w, r1, r2
    cmp r1.xyz, -r0_abs.z, r4, r1
    cmp r3.xyz, -r3.x, r3.yzww, r1
    mul r3.w, r1.w, r2.w
    cmp r1, -r0_abs.x, r3, r2
    max r0.x, v1.w, c1.z
    add r0.x, -r1.w, r0.x
    cmp r2, r0.x, -c1.w, -c1.z
    texkill r2
    mov r2.y, c12.y
    mul r0.xzw, r2.y, c11.xyyz
    add r2.x, r1.w, -v1.w
    add r2.x, r2.x, -c12.x
    frc r2.y, -r2.x
    add r2.x, r2.y, r2.x
    mad r1.xyz, r1, c10.x, -r0.xzww
    mad r0.xzw, r2.x, r1.xyyz, r0
    mad r1.xyz, r0.xzww, c13.x, c13.y
    mad r1.xyz, r0.xzww, r1, c2.w
    mul r1.xyz, r0.xzww, r1
    min r2.xyz, r1, r0.xzww
    cmp oC0.xyz, -r0.y, r0.xzww, r2
    mov oC0.w, r1.w

// approximately 103 instruction slots used (7 texture, 96 arithmetic)
#endif

const BYTE g_ps30_main[] =
{
      0,   3, 255, 255, 254, 255, 
    245,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 156,   3, 
      0,   0,   0,   3, 255, 255, 
     17,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
    149,   3,   0,   0, 112,   1, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   6,   0, 140,   1, 
      0,   0,   0,   0,   0,   0, 
    156,   1,   0,   0,   3,   0, 
      4,   0,   1,   0,  18,   0, 
    188,   1,   0,   0,   0,   0, 
      0,   0, 204,   1,   0,   0, 
      3,   0,   3,   0,   1,   0, 
     14,   0, 232,   1,   0,   0, 
      0,   0,   0,   0, 248,   1, 
      0,   0,   3,   0,   5,   0, 
      1,   0,  22,   0,  32,   2, 
      0,   0,   0,   0,   0,   0, 
     48,   2,   0,   0,   3,   0, 
      0,   0,   1,   0,   2,   0, 
     76,   2,   0,   0,   0,   0, 
      0,   0,  92,   2,   0,   0, 
      3,   0,   2,   0,   1,   0, 
     10,   0, 124,   2,   0,   0, 
      0,   0,   0,   0, 140,   2, 
      0,   0,   2,   0,   5,   0, 
      1,   0,  22,   0, 168,   2, 
      0,   0,   0,   0,   0,   0, 
    184,   2,   0,   0,   2,   0, 
      6,   0,   1,   0,  26,   0, 
    168,   2,   0,   0,   0,   0, 
      0,   0, 211,   2,   0,   0, 
      2,   0,  11,   0,   1,   0, 
     46,   0, 168,   2,   0,   0, 
      0,   0,   0,   0, 227,   2, 
      0,   0,   2,   0,  12,   0, 
      1,   0,  50,   0, 168,   2, 
      0,   0,   0,   0,   0,   0, 
    247,   2,   0,   0,   2,   0, 
     10,   0,   1,   0,  42,   0, 
    168,   2,   0,   0,   0,   0, 
      0,   0,  13,   3,   0,   0, 
      2,   0,   8,   0,   1,   0, 
     34,   0, 168,   2,   0,   0, 
      0,   0,   0,   0,  37,   3, 
      0,   0,   2,   0,   9,   0, 
      1,   0,  38,   0, 168,   2, 
      0,   0,   0,   0,   0,   0, 
     59,   3,   0,   0,   2,   0, 
      7,   0,   1,   0,  30,   0, 
    168,   2,   0,   0,   0,   0, 
      0,   0,  82,   3,   0,   0, 
      2,   0,   3,   0,   1,   0, 
     14,   0, 168,   2,   0,   0, 
      0,   0,   0,   0, 106,   3, 
      0,   0,   2,   0,   4,   0, 
      1,   0,  18,   0, 168,   2, 
      0,   0,   0,   0,   0,   0, 
    134,   3,   0,   0,   2,   0, 
     17,   0,   1,   0,  70,   0, 
    168,   2,   0,   0,   0,   0, 
      0,   0,  83,  97, 109, 112, 
    108, 101, 114,  95, 115,  97, 
    109, 112, 108, 101, 114,  95, 
     97, 108, 112, 104,  97,  84, 
    101, 120,   0, 171, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    115,  97, 109, 112, 108, 101, 
    114,  95,  98, 108, 101, 110, 
    100,  65, 108, 112, 104,  97, 
     84, 101, 120,   0, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    115,  97, 109, 112, 108, 101, 
    114,  95,  98, 108, 101, 110, 
    100,  84, 101, 120,   0, 171, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     83,  97, 109, 112, 108, 101, 
    114,  95, 115,  97, 109, 112, 
    108, 101, 114,  95,  98, 108, 
    101, 110, 100,  85,  86,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  84, 101, 120, 
      0, 171, 171, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  83,  97, 109, 112, 
    108, 101, 114,  95, 115,  97, 
    109, 112, 108, 101, 114,  95, 
     99, 111, 108, 111, 114,  84, 
    101, 120,   0, 171, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  83,  97, 
    109, 112, 108, 101, 114,  95, 
    115,  97, 109, 112, 108, 101, 
    114,  95, 117, 118,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  84, 101, 120,   0, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  95,  50, 
     56,  57,  95, 102,  66, 108, 
    101, 110, 100,  84, 101, 120, 
    116, 117, 114, 101,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     95,  50,  56,  57,  95, 102, 
     67,  97, 109, 101, 114,  97, 
     70, 114, 111, 110, 116,  68, 
    105, 114, 101,  99, 116, 105, 
    111, 110,   0,  95,  50,  56, 
     57,  95, 102,  69, 100, 103, 
    101,  67, 111, 108, 111, 114, 
      0,  95,  50,  56,  57,  95, 
    102,  69, 100, 103, 101,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0,  95,  50,  56, 
     57,  95, 102,  69, 109, 105, 
    115, 115, 105, 118, 101,  83, 
     99,  97, 108, 105, 110, 103, 
      0,  95,  50,  56,  57,  95, 
    102,  70,  97, 108, 108, 111, 
    102, 102,  66, 101, 103, 105, 
    110,  67, 111, 108, 111, 114, 
      0,  95,  50,  56,  57,  95, 
    102,  70,  97, 108, 108, 111, 
    102, 102,  69, 110, 100,  67, 
    111, 108, 111, 114,   0,  95, 
     50,  56,  57,  95, 102,  70, 
     97, 108, 108, 111, 102, 102, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0,  95,  50, 
     56,  57,  95, 102,  70, 108, 
    105, 112,  98, 111, 111, 107, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0,  95,  50, 
     56,  57,  95, 102,  85,  86, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  95,  50,  56,  57, 
     95, 109, 105, 115,  99,  70, 
    108,  97, 103, 115,   0, 112, 
    115,  95,  51,  95,  48,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  81,   0, 
      0,   5,   0,   0,  15, 160, 
      0,   0,   0,  64,   0,   0, 
    128, 191,   0,   0,   0,  52, 
     85,  85, 213,  62,  81,   0, 
      0,   5,   1,   0,  15, 160, 
     61,  10, 135,  63, 174,  71, 
     97, 189,   0,   0,   0,   0, 
      0,   0, 128,  63,  81,   0, 
      0,   5,   2,   0,  15, 160, 
      0,   0, 128, 191,   0,   0, 
      0, 192,   0,   0,  64, 192, 
    194,  44,  77,  60,  81,   0, 
      0,   5,  13,   0,  15, 160, 
     18,  81, 156,  62, 196, 162, 
     46,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   5,   0,   0, 128, 
      0,   0,  79, 144,  31,   0, 
      0,   2,   5,   0,   1, 128, 
      1,   0,  79, 144,  31,   0, 
      0,   2,   5,   0,   2, 128, 
      2,   0,   7, 144,  31,   0, 
      0,   2,   5,   0,   3, 128, 
      3,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   4, 128, 
      4,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   5, 128, 
      5,   0,  15, 144,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      1,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      2,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      3,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      4,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      5,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      3,   0, 238, 144,   2,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   0,   0,   0, 160, 
      0,   0,  85, 160,   4,   0, 
      0,   4,   0,   0,   4, 128, 
      0,   0,  85, 128,   4,   0, 
    255, 161,   4,   0, 170, 160, 
      4,   0,   0,   4,   0,   0, 
     10, 128,   0,   0, 160, 128, 
      4,   0,   0, 160,   1,   0, 
     96, 144,  66,   0,   0,   3, 
      1,   0,  15, 128,   0,   0, 
    237, 128,   0,   8, 228, 160, 
     35,   0,   0,   2,   0,   0, 
      2, 128,  17,   0,   0, 160, 
     11,   0,   0,   3,   2,   0, 
      7, 128,   1,   0, 228, 139, 
      0,   0, 170, 160,  15,   0, 
      0,   2,   3,   0,   1, 128, 
      2,   0,   0, 128,  15,   0, 
      0,   2,   3,   0,   2, 128, 
      2,   0,  85, 128,  15,   0, 
      0,   2,   3,   0,   4, 128, 
      2,   0, 170, 128,   5,   0, 
      0,   3,   2,   0,   7, 128, 
      3,   0, 228, 128,   0,   0, 
    255, 160,  14,   0,   0,   2, 
      3,   0,   1, 128,   2,   0, 
      0, 128,  14,   0,   0,   2, 
      3,   0,   2, 128,   2,   0, 
     85, 128,  14,   0,   0,   2, 
      3,   0,   4, 128,   2,   0, 
    170, 128,   4,   0,   0,   4, 
      2,   0,   7, 128,   3,   0, 
    228, 128,   1,   0,   0, 160, 
      1,   0,  85, 160,  11,   0, 
      0,   3,   3,   0,   7, 128, 
      2,   0, 228, 128,   1,   0, 
    170, 160,  88,   0,   0,   4, 
      1,   0,   7, 128,   0,   0, 
     85, 129,   1,   0, 228, 128, 
      3,   0, 228, 128,   5,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   0,   0, 
    228, 144,   4,   0,   0,   4, 
      2,   0,   3, 128,   0,   0, 
    232, 128,   4,   0,   0, 160, 
      5,   0, 238, 144,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   1,   0,   0,   2, 
      3,   0,   3, 128,   0,   0, 
    228, 160,   2,   0,   0,   3, 
      0,   0,   8, 128,   3,   0, 
     85, 128,   3,   0,  85, 160, 
      4,   0,   0,   4,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   0, 228, 144,   1,   0, 
    228, 129,   4,   0,   0,   4, 
      2,   0,  15, 128,   1,   0, 
    170, 144,   2,   0, 228, 128, 
      1,   0, 228, 128,  88,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0, 255, 140,   2,   0, 
    228, 128,   1,   0, 228, 128, 
     88,   0,   0,   4,   1,   0, 
     15, 128,   3,   0,   0, 161, 
      1,   0, 228, 128,   2,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,   5, 128,   0,   0, 
    228, 128,   4,   0,   0, 160, 
      3,   0, 212, 144,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0, 232, 128,   1,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,   1, 128,   2,   0, 
    255, 128,   2,   0,   0, 128, 
      5,   0,   0,   3,   2,   0, 
      8, 128,   0,   0,   0, 128, 
      1,   0, 255, 128,  66,   0, 
      0,   3,   4,   0,  15, 128, 
      4,   0, 238, 144,   5,   8, 
    228, 160,   4,   0,   0,   4, 
      4,   0,   3, 128,   4,   0, 
    228, 128,   0,   0,   0, 160, 
      0,   0,  85, 160,   4,   0, 
      0,   4,   4,   0,   4, 128, 
      4,   0,  85, 128,   4,   0, 
    255, 161,   4,   0, 170, 160, 
      4,   0,   0,   4,   0,   0, 
      5, 128,   4,   0, 228, 128, 
      4,   0,  85, 160,   5,   0, 
    212, 144,  66,   0,   0,   3, 
      5,   0,  15, 128,   0,   0, 
    232, 128,   3,   8, 228, 160, 
     11,   0,   0,   3,   0,   0, 
     13, 128,   5,   0, 148, 139, 
      0,   0, 170, 160,  15,   0, 
      0,   2,   6,   0,   1, 128, 
      0,   0,   0, 128,  15,   0, 
      0,   2,   6,   0,   2, 128, 
      0,   0, 170, 128,  15,   0, 
      0,   2,   6,   0,   4, 128, 
      0,   0, 255, 128,   5,   0, 
      0,   3,   0,   0,  13, 128, 
      6,   0, 148, 128,   0,   0, 
    255, 160,  14,   0,   0,   2, 
      6,   0,   1, 128,   0,   0, 
      0, 128,  14,   0,   0,   2, 
      6,   0,   2, 128,   0,   0, 
    170, 128,  14,   0,   0,   2, 
      6,   0,   4, 128,   0,   0, 
    255, 128,   4,   0,   0,   4, 
      0,   0,  13, 128,   6,   0, 
    148, 128,   1,   0,   0, 160, 
      1,   0,  85, 160,  11,   0, 
      0,   3,   6,   0,   7, 128, 
      0,   0, 248, 128,   1,   0, 
    170, 160,  88,   0,   0,   4, 
      0,   0,  13, 128,   0,   0, 
     85, 129,   5,   0, 148, 128, 
      6,   0, 148, 128,   4,   0, 
      0,   4,   3,   0,  12, 128, 
      4,   0, 132, 128,   4,   0, 
     85, 160,   4,   0,  68, 144, 
     66,   0,   0,   3,   4,   0, 
     15, 128,   3,   0, 238, 128, 
      4,   8, 228, 160,   5,   0, 
      0,   3,   1,   0,   8, 128, 
      4,   0, 255, 128,   4,   0, 
      0, 128,   5,   0,   0,   3, 
      1,   0,   8, 128,   1,   0, 
    255, 128,   5,   0, 255, 128, 
     35,   0,   0,   2,   3,   0, 
      4, 128,   5,   0,   0, 160, 
      5,   0,   0,   3,   4,   0, 
      7, 128,   0,   0, 248, 128, 
      1,   0, 255, 128,  18,   0, 
      0,   4,   5,   0,   7, 128, 
      1,   0, 255, 128,   0,   0, 
    248, 128,   1,   0, 228, 128, 
      1,   0,   0,   2,   6,   0, 
      7, 128,   2,   0, 228, 160, 
      2,   0,   0,   3,   6,   0, 
      7, 128,   6,   0, 228, 128, 
      5,   0,   0, 160,   4,   0, 
      0,   4,   7,   0,   7, 128, 
      0,   0, 248, 128,   1,   0, 
    255, 128,   1,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     13, 128,   0,   0, 228, 128, 
      1,   0, 255, 129,   1,   0, 
    148, 128,   5,   0,   0,   3, 
      4,   0,   7, 128,   1,   0, 
    228, 128,   4,   0, 228, 128, 
     88,   0,   0,   4,   1,   0, 
      7, 128,   6,   0, 170, 140, 
      4,   0, 228, 128,   1,   0, 
    228, 128,  88,   0,   0,   4, 
      0,   0,  13, 128,   6,   0, 
     85, 140,   0,   0, 228, 128, 
      1,   0, 148, 128,  88,   0, 
      0,   4,   0,   0,  13, 128, 
      6,   0,   0, 140,   7,   0, 
    148, 128,   0,   0, 228, 128, 
     88,   0,   0,   4,   2,   0, 
      7, 128,   3,   0, 170, 129, 
      5,   0, 228, 128,   0,   0, 
    248, 128,   2,   0,   0,   3, 
      0,   0,  13, 128,   3,   0, 
     21, 140,   7,   0,  84, 160, 
     36,   0,   0,   2,   1,   0, 
      7, 128,   6,   0, 228, 161, 
     36,   0,   0,   2,   3,   0, 
      7, 128,   2,   0, 228, 144, 
      8,   0,   0,   3,   1,   0, 
     17, 128,   1,   0, 228, 128, 
      3,   0, 228, 128,  32,   0, 
      0,   3,   3,   0,   1, 128, 
      1,   0,   0, 128,   7,   0, 
    170, 160,   1,   0,   0,   2, 
      1,   0,  15, 128,   9,   0, 
    228, 160,   2,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 129,   8,   0, 228, 160, 
      4,   0,   0,   4,   1,   0, 
     15, 128,   3,   0,   0, 128, 
      1,   0, 228, 128,   9,   0, 
    228, 160,  35,   0,   0,   2, 
      3,   0,   1, 128,   7,   0, 
     85, 160,   2,   0,   0,   3, 
      3,   0,  14, 128,   1,   0, 
    144, 128,   2,   0, 144, 128, 
      2,   0,   0,   3,   4,   0, 
      7, 128,   1,   0, 228, 129, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      1,   0, 228, 128,   2,   0, 
    228, 128,  88,   0,   0,   4, 
      1,   0,   7, 128,   0,   0, 
    255, 140,   1,   0, 228, 128, 
      2,   0, 228, 128,  88,   0, 
      0,   4,   1,   0,   7, 128, 
      0,   0, 170, 140,   4,   0, 
    228, 128,   1,   0, 228, 128, 
     88,   0,   0,   4,   3,   0, 
      7, 128,   3,   0,   0, 129, 
      3,   0, 249, 128,   1,   0, 
    228, 128,   5,   0,   0,   3, 
      3,   0,   8, 128,   1,   0, 
    255, 128,   2,   0, 255, 128, 
     88,   0,   0,   4,   1,   0, 
     15, 128,   0,   0,   0, 140, 
      3,   0, 228, 128,   2,   0, 
    228, 128,  11,   0,   0,   3, 
      0,   0,   1, 128,   1,   0, 
    255, 144,   1,   0, 170, 160, 
      2,   0,   0,   3,   0,   0, 
      1, 128,   1,   0, 255, 129, 
      0,   0,   0, 128,  88,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0,   0, 128,   1,   0, 
    255, 161,   1,   0, 170, 161, 
     65,   0,   0,   1,   2,   0, 
     15, 128,   1,   0,   0,   2, 
      2,   0,   2, 128,  12,   0, 
     85, 160,   5,   0,   0,   3, 
      0,   0,  13, 128,   2,   0, 
     85, 128,  11,   0, 148, 160, 
      2,   0,   0,   3,   2,   0, 
      1, 128,   1,   0, 255, 128, 
      1,   0, 255, 145,   2,   0, 
      0,   3,   2,   0,   1, 128, 
      2,   0,   0, 128,  12,   0, 
      0, 161,  19,   0,   0,   2, 
      2,   0,   2, 128,   2,   0, 
      0, 129,   2,   0,   0,   3, 
      2,   0,   1, 128,   2,   0, 
     85, 128,   2,   0,   0, 128, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   1,   0, 228, 128, 
     10,   0,   0, 160,   0,   0, 
    248, 129,   4,   0,   0,   4, 
      0,   0,  13, 128,   2,   0, 
      0, 128,   1,   0, 148, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      0,   0, 248, 128,  13,   0, 
      0, 160,  13,   0,  85, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   0,   0, 248, 128, 
      1,   0, 228, 128,   2,   0, 
    255, 160,   5,   0,   0,   3, 
      1,   0,   7, 128,   0,   0, 
    248, 128,   1,   0, 228, 128, 
     10,   0,   0,   3,   2,   0, 
      7, 128,   1,   0, 228, 128, 
      0,   0, 248, 128,  88,   0, 
      0,   4,   0,   8,   7, 128, 
      0,   0,  85, 129,   0,   0, 
    248, 128,   2,   0, 228, 128, 
      1,   0,   0,   2,   0,   8, 
      8, 128,   1,   0, 255, 128, 
    255, 255,   0,   0
};
