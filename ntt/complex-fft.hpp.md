---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/complex-fft.test.cpp
    title: verify/verify-unit-test/complex-fft.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-toom-3.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-real-fft-toom-3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/complex-fft.hpp\"\n\nnamespace ArbitraryModConvolution\
    \ {\n\ntemplate <typename T>\nstruct Cp {\n  T x, y;\n  constexpr Cp() : x(0),\
    \ y(0) {}\n  constexpr Cp(T _x, T _y) : x(_x), y(_y) {}\n  constexpr inline Cp\
    \ operator+(const Cp& c) const {\n    return Cp(x + c.x, y + c.y);\n  }\n  constexpr\
    \ inline Cp operator-(const Cp& c) const {\n    return Cp(x - c.x, y - c.y);\n\
    \  }\n  constexpr inline Cp operator*(const Cp& c) const {\n    return Cp(x *\
    \ c.x - y * c.y, x * c.y + y * c.x);\n  }\n  constexpr inline Cp operator-() const\
    \ { return Cp(-x, -y); }\n  constexpr inline Cp conj() const { return Cp(x, -y);\
    \ }\n  constexpr inline Cp rotl() const { return Cp(-y, x); }\n  friend ostream&\
    \ operator<<(ostream& os, const Cp& c) {\n    os << \"(\" << c.x << \", \" <<\
    \ c.y << \")\" << endl;\n    return os;\n  }\n};\n\nusing C = Cp<double>;\nconst\
    \ long double PI = acosl(-1);\n\nstruct CooleyTukey {\n  static vector<C> w;\n\
    \n  static void setw(int k) {\n    --k;\n    if ((int)w.size() >= (1 << k)) return;\n\
    \    w.resize(1 << k);\n    vector<Cp<long double>> base(k);\n    const long double\
    \ arg = PI / (1 << k);\n    for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1)\
    \ {\n      complex<long double> z = exp(complex<long double>(1i) * (arg * j));\n\
    \      base[i] = Cp<long double>{z.real(), z.imag()};\n    }\n    genw(0, k -\
    \ 1, Cp<long double>{1, 0}, base);\n  }\n\n  static void genw(int i, int b, Cp<long\
    \ double> z,\n                   const vector<Cp<long double>>& base) {\n    if\
    \ (b == -1) {\n      w[i].x = z.x, w[i].y = z.y;\n    } else {\n      genw(i,\
    \ b - 1, z, base);\n      genw(i | (1 << b), b - 1, z * base[b], base);\n    }\n\
    \  }\n\n  static void fft(vector<C>& a, int k) {\n    if (k <= 0) return;\n  \
    \  if (k == 1) {\n      C a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] =\
    \ a[0] + a1;\n      return;\n    }\n    if (k & 1) {\n      int v = 1 << (k -\
    \ 1);\n      for (int j = 0; j < v; ++j) {\n        C ajv = a[j + v];\n      \
    \  a[j + v] = a[j] - ajv;\n        a[j] = a[j] + ajv;\n      }\n    }\n    int\
    \ u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));\n    while (v) {\n      {\n  \
    \      int j0 = 0;\n        int j1 = v;\n        int j2 = j1 + v;\n        int\
    \ j3 = j2 + v;\n        int je = v;\n        for (; j0 < je; ++j0, ++j1, ++j2,\
    \ ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n     \
    \     C t0p2 = t0 + t2, t1p3 = t1 + t3;\n          C t0m2 = t0 - t2, t1m3 = (t1\
    \ - t3) * w[1];\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n       \
    \   a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      // jh\
    \ >= 1\n      for (int jh = 1; jh < u; ++jh) {\n        int j0 = jh * v * 4;\n\
    \        int j1 = j0 + v;\n        int j2 = j1 + v;\n        int j3 = j2 + v;\n\
    \        int je = j1;\n        C ww = w[jh];\n        C xx = w[jh << 1];\n   \
    \     C wx = ww * xx;\n        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {\n   \
    \       C t0 = a[j0], t1 = a[j1] * xx, t2 = a[j2] * ww, t3 = a[j3] * wx;\n   \
    \       C t0p2 = t0 + t2, t1p3 = t1 + t3;\n          C t0m2 = t0 - t2, t1m3 =\
    \ (t1 - t3) * w[1];\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n   \
    \       a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      u\
    \ <<= 2, v >>= 2;\n    }\n  }\n\n  static void ifft(vector<C>& a, int k) {\n \
    \   if ((int)a.size() <= 1) return;\n    if (k == 1) {\n      C a1 = a[1];\n \
    \     a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n   \
    \ int u = 1 << (k - 2);\n    int v = 1;\n    while (u) {\n      // jh = 0\n  \
    \    {\n        int j0 = 0;\n        int j1 = v;\n        int j2 = j1 + v;\n \
    \       int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {\n \
    \         C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          C t0p1\
    \ = t0 + t1, t2p3 = t2 + t3;\n          C t0m1 = t0 - t1, t2m3 = (t2 - t3) * w[1].conj();\n\
    \          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n          a[j1] = t0m1 +\
    \ t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n      // jh >= 1\n      for\
    \ (int jh = 1; jh < u; ++jh) {\n        int j0 = (jh * v) << 2;\n        int j1\
    \ = j0 + v;\n        int j2 = j1 + v;\n        int j3 = j2 + v;\n        int je\
    \ = j1;\n        C ww = w[jh].conj();\n        C xx = w[jh << 1].conj();\n   \
    \     C yy = w[(jh << 1) + 1].conj();\n        for (; j0 < je; ++j0, ++j1, ++j2,\
    \ ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n     \
    \     C t0p1 = t0 + t1, t2p3 = t2 + t3;\n          C t0m1 = (t0 - t1) * xx, t2m3\
    \ = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\n\
    \          a[j1] = t0m1 + t2m3, a[j3] = (t0m1 - t2m3) * ww;\n        }\n     \
    \ }\n      u >>= 2;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k\
    \ - 1);\n      for (int j = 0; j < u; j++) {\n        C ajv = a[j] - a[j + u];\n\
    \        a[j] = a[j] + a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n  }\n\
    \n  static void fft_real(vector<C>& AL, vector<C>& AH, int k) {\n    fft(AL, k);\n\
    \    AH[0] = C{AL[0].y * 2.0, 0};\n    AL[0] = C{AL[0].x * 2.0, 0};\n    AH[1]\
    \ = C{AL[1].y * 2.0, 0};\n    AL[1] = C{AL[1].x * 2.0, 0};\n    for (int i = 2,\
    \ y = 2; y < (1 << k); y <<= 1) {\n      for (; i < 2 * y; i += 2) {\n       \
    \ int j = i ^ (y - 1);\n        AH[i] = (AL[j].conj() - AL[i]).rotl();\n     \
    \   AL[i] = (AL[j].conj() + AL[i]);\n        AH[j] = AH[i].conj();\n        AL[j]\
    \ = AL[i].conj();\n      }\n    }\n  }\n\n  // naive convolution for int\n  template\
    \ <typename T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr>\n  static\
    \ vector<long long> multiply(const vector<T>& s, const vector<T>& t) {\n    int\
    \ l = s.size() + t.size() - 1;\n    if (min(s.size(), t.size()) <= 40) {\n   \
    \   vector<long long> u(l);\n      for (int i = 0; i < (int)s.size(); i++) {\n\
    \        for (int j = 0; j < (int)t.size(); j++) u[i + j] += 1LL * s[i] * t[j];\n\
    \      }\n      return u;\n    }\n\n    int k = 2, M = 4;\n    while (M < l) M\
    \ <<= 1, ++k;\n    setw(k);\n    auto round = [](double x) -> long long {\n  \
    \    return (long long)(x + (x > 0 ? 0.5 : -0.5));\n    };\n\n    vector<C> a(M);\n\
    \    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];\n    for (int i =\
    \ 0; i < (int)t.size(); i++) a[i].y = t[i];\n    fft(a, k);\n\n    a[0].y = 4.0\
    \ * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x * a[1].y;\n    a[0].x = a[1].x\
    \ = 0.0;\n    for (int i = 2; i < M; i += 2) {\n      int c = 1 << (31 - __builtin_clz(i));\n\
    \      int j = i ^ (c - 1);\n      a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());\n\
    \      a[j] = -a[i].conj();\n    }\n\n    vector<C> b(M / 2);\n    for (int j\
    \ = 0; j < M / 2; j++) {\n      C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];\n      C\
    \ tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();\n      b[j] = tmp1 + tmp2.rotl();\n\
    \    }\n    ifft(b, k - 1);\n\n    vector<long long> u(l);\n    for (int i = 0;\
    \ i < l; i++) {\n      if (i & 1) {\n        u[i] = round(-b[i >> 1].x / (4.0\
    \ * M));\n      } else {\n        u[i] = round(b[i >> 1].y / (4.0 * M));\n   \
    \   }\n    }\n    return u;\n  }\n\n  static vector<double> multiply(const vector<double>&\
    \ s,\n                                 const vector<double>& t) {\n    int l =\
    \ s.size() + t.size() - 1;\n    if (min(s.size(), t.size()) <= 40) {\n      vector<double>\
    \ u(l);\n      for (int i = 0; i < (int)s.size(); i++) {\n        for (int j =\
    \ 0; j < (int)t.size(); j++) u[i + j] += s[i] * t[j];\n      }\n      return u;\n\
    \    }\n\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n    setw(k);\n\
    \n    vector<C> a(M);\n    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];\n\
    \    for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];\n    fft(a, k);\n\n\
    \    a[0].y = 4.0 * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x * a[1].y;\n  \
    \  a[0].x = a[1].x = 0.0;\n    for (int i = 2; i < M; i += 2) {\n      int c =\
    \ 1 << (31 - __builtin_clz(i));\n      int j = i ^ (c - 1);\n      a[i] = (a[i]\
    \ + a[j].conj()) * (a[i] - a[j].conj());\n      a[j] = -a[i].conj();\n    }\n\n\
    \    vector<C> b(M / 2);\n    for (int j = 0; j < M / 2; j++) {\n      C tmp1\
    \ = a[j * 2 + 0] + a[j * 2 + 1];\n      C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1])\
    \ * w[j].conj();\n      b[j] = tmp1 + tmp2.rotl();\n    }\n    ifft(b, k - 1);\n\
    \n    vector<double> u(l);\n    for (int i = 0; i < l; i++) {\n      if (i & 1)\
    \ {\n        u[i] = -b[i >> 1].x / (4.0 * M);\n      } else {\n        u[i] =\
    \ b[i >> 1].y / (4.0 * M);\n      }\n    }\n    return u;\n  }\n\n  template <unsigned\
    \ int MOD = -1u>\n  static conditional_t<MOD == -1u, vector<__uint128_t>, vector<int>>\n\
    \  multiply_15bit(const vector<int>& a, const vector<int>& b) {\n    using u64\
    \ = unsigned long long;\n    constexpr u64 B = 32000;\n    int l = a.size() +\
    \ b.size() - 1;\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n    setw(k);\n\
    \    auto round = [](double x) -> u64 { return u64(x + 0.5); };\n\n    vector<C>\
    \ AL(M), AH(M), BL(M), BH(M);\n    for (int i = 0; i < (int)a.size(); i++) {\n\
    \      AL[i] = C{double(a[i] % B), double(a[i] / B)};\n    }\n    for (int i =\
    \ 0; i < (int)b.size(); i++) {\n      BL[i] = C{double(b[i] % B), double(b[i]\
    \ / B)};\n    }\n\n    fft_real(AL, AH, k);\n    fft_real(BL, BH, k);\n\n    for\
    \ (int i = 0; i < M; i++) {\n      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();\n\
    \      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();\n      BL[i] = tmp;\n \
    \   }\n\n    ifft(BL, k);\n    ifft(BH, k);\n\n    using return_type =\n     \
    \   conditional_t<MOD + 1u == 0u, vector<__uint128_t>, vector<int>>;\n\n    return_type\
    \ u(l);\n    double im = 1.0 / (4.0 * M);\n    for (int i = 0; i < l; i++) {\n\
    \      BL[i].x *= im, BL[i].y *= im;\n      BH[i].x *= im, BH[i].y *= im;\n  \
    \    u64 s1 = round(BL[i].x);\n      u64 s2 = round(BH[i].x) + round(BH[i].y);\n\
    \      u64 s3 = round(BL[i].y);\n\n      if constexpr (MOD == -1u) {\n       \
    \ u[i] += __uint128_t(s1);\n        u[i] += __uint128_t(s2) * B;\n        u[i]\
    \ += __uint128_t(s3) * B * B;\n      } else {\n        u[i] += s1 % MOD;\n   \
    \     u[i] += s2 % MOD * B % MOD;\n        if (u[i] >= MOD) u[i] -= MOD;\n   \
    \     u[i] += s3 % MOD * (B * B % MOD) % MOD;\n        if (u[i] >= MOD) u[i] -=\
    \ MOD;\n      }\n    }\n    return u;\n  }\n};\nvector<C> CooleyTukey::w;\n\n\
    }  // namespace ArbitraryModConvolution\n"
  code: "#pragma once\n\nnamespace ArbitraryModConvolution {\n\ntemplate <typename\
    \ T>\nstruct Cp {\n  T x, y;\n  constexpr Cp() : x(0), y(0) {}\n  constexpr Cp(T\
    \ _x, T _y) : x(_x), y(_y) {}\n  constexpr inline Cp operator+(const Cp& c) const\
    \ {\n    return Cp(x + c.x, y + c.y);\n  }\n  constexpr inline Cp operator-(const\
    \ Cp& c) const {\n    return Cp(x - c.x, y - c.y);\n  }\n  constexpr inline Cp\
    \ operator*(const Cp& c) const {\n    return Cp(x * c.x - y * c.y, x * c.y + y\
    \ * c.x);\n  }\n  constexpr inline Cp operator-() const { return Cp(-x, -y); }\n\
    \  constexpr inline Cp conj() const { return Cp(x, -y); }\n  constexpr inline\
    \ Cp rotl() const { return Cp(-y, x); }\n  friend ostream& operator<<(ostream&\
    \ os, const Cp& c) {\n    os << \"(\" << c.x << \", \" << c.y << \")\" << endl;\n\
    \    return os;\n  }\n};\n\nusing C = Cp<double>;\nconst long double PI = acosl(-1);\n\
    \nstruct CooleyTukey {\n  static vector<C> w;\n\n  static void setw(int k) {\n\
    \    --k;\n    if ((int)w.size() >= (1 << k)) return;\n    w.resize(1 << k);\n\
    \    vector<Cp<long double>> base(k);\n    const long double arg = PI / (1 <<\
    \ k);\n    for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {\n      complex<long\
    \ double> z = exp(complex<long double>(1i) * (arg * j));\n      base[i] = Cp<long\
    \ double>{z.real(), z.imag()};\n    }\n    genw(0, k - 1, Cp<long double>{1, 0},\
    \ base);\n  }\n\n  static void genw(int i, int b, Cp<long double> z,\n       \
    \            const vector<Cp<long double>>& base) {\n    if (b == -1) {\n    \
    \  w[i].x = z.x, w[i].y = z.y;\n    } else {\n      genw(i, b - 1, z, base);\n\
    \      genw(i | (1 << b), b - 1, z * base[b], base);\n    }\n  }\n\n  static void\
    \ fft(vector<C>& a, int k) {\n    if (k <= 0) return;\n    if (k == 1) {\n   \
    \   C a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    if (k & 1) {\n      int v = 1 << (k - 1);\n      for (int j = 0; j\
    \ < v; ++j) {\n        C ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n   \
    \     a[j] = a[j] + ajv;\n      }\n    }\n    int u = 1 << (k & 1), v = 1 << (k\
    \ - 2 - (k & 1));\n    while (v) {\n      {\n        int j0 = 0;\n        int\
    \ j1 = v;\n        int j2 = j1 + v;\n        int j3 = j2 + v;\n        int je\
    \ = v;\n        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {\n          C t0 = a[j0],\
    \ t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          C t0p2 = t0 + t2, t1p3 = t1 +\
    \ t3;\n          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];\n          a[j0] =\
    \ t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2\
    \ - t1m3;\n        }\n      }\n      // jh >= 1\n      for (int jh = 1; jh < u;\
    \ ++jh) {\n        int j0 = jh * v * 4;\n        int j1 = j0 + v;\n        int\
    \ j2 = j1 + v;\n        int j3 = j2 + v;\n        int je = j1;\n        C ww =\
    \ w[jh];\n        C xx = w[jh << 1];\n        C wx = ww * xx;\n        for (;\
    \ j0 < je; ++j0, ++j1, ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1] * xx,\
    \ t2 = a[j2] * ww, t3 = a[j3] * wx;\n          C t0p2 = t0 + t2, t1p3 = t1 + t3;\n\
    \          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];\n          a[j0] = t0p2\
    \ + t1p3, a[j1] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 -\
    \ t1m3;\n        }\n      }\n      u <<= 2, v >>= 2;\n    }\n  }\n\n  static void\
    \ ifft(vector<C>& a, int k) {\n    if ((int)a.size() <= 1) return;\n    if (k\
    \ == 1) {\n      C a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] +\
    \ a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    while\
    \ (u) {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n\
    \        int j2 = j1 + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0,\
    \ ++j1, ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n\
    \          C t0p1 = t0 + t1, t2p3 = t2 + t3;\n          C t0m1 = t0 - t1, t2m3\
    \ = (t2 - t3) * w[1].conj();\n          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n\
    \          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n   \
    \   // jh >= 1\n      for (int jh = 1; jh < u; ++jh) {\n        int j0 = (jh *\
    \ v) << 2;\n        int j1 = j0 + v;\n        int j2 = j1 + v;\n        int j3\
    \ = j2 + v;\n        int je = j1;\n        C ww = w[jh].conj();\n        C xx\
    \ = w[jh << 1].conj();\n        C yy = w[(jh << 1) + 1].conj();\n        for (;\
    \ j0 < je; ++j0, ++j1, ++j2, ++j3) {\n          C t0 = a[j0], t1 = a[j1], t2 =\
    \ a[j2], t3 = a[j3];\n          C t0p1 = t0 + t1, t2p3 = t2 + t3;\n          C\
    \ t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3,\
    \ a[j2] = (t0p1 - t2p3) * ww;\n          a[j1] = t0m1 + t2m3, a[j3] = (t0m1 -\
    \ t2m3) * ww;\n        }\n      }\n      u >>= 2;\n      v <<= 2;\n    }\n   \
    \ if (k & 1) {\n      u = 1 << (k - 1);\n      for (int j = 0; j < u; j++) {\n\
    \        C ajv = a[j] - a[j + u];\n        a[j] = a[j] + a[j + u];\n        a[j\
    \ + u] = ajv;\n      }\n    }\n  }\n\n  static void fft_real(vector<C>& AL, vector<C>&\
    \ AH, int k) {\n    fft(AL, k);\n    AH[0] = C{AL[0].y * 2.0, 0};\n    AL[0] =\
    \ C{AL[0].x * 2.0, 0};\n    AH[1] = C{AL[1].y * 2.0, 0};\n    AL[1] = C{AL[1].x\
    \ * 2.0, 0};\n    for (int i = 2, y = 2; y < (1 << k); y <<= 1) {\n      for (;\
    \ i < 2 * y; i += 2) {\n        int j = i ^ (y - 1);\n        AH[i] = (AL[j].conj()\
    \ - AL[i]).rotl();\n        AL[i] = (AL[j].conj() + AL[i]);\n        AH[j] = AH[i].conj();\n\
    \        AL[j] = AL[i].conj();\n      }\n    }\n  }\n\n  // naive convolution\
    \ for int\n  template <typename T, enable_if_t<is_integral<T>::value, nullptr_t>\
    \ = nullptr>\n  static vector<long long> multiply(const vector<T>& s, const vector<T>&\
    \ t) {\n    int l = s.size() + t.size() - 1;\n    if (min(s.size(), t.size())\
    \ <= 40) {\n      vector<long long> u(l);\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        for (int j = 0; j < (int)t.size(); j++) u[i + j] += 1LL * s[i]\
    \ * t[j];\n      }\n      return u;\n    }\n\n    int k = 2, M = 4;\n    while\
    \ (M < l) M <<= 1, ++k;\n    setw(k);\n    auto round = [](double x) -> long long\
    \ {\n      return (long long)(x + (x > 0 ? 0.5 : -0.5));\n    };\n\n    vector<C>\
    \ a(M);\n    for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];\n    for (int\
    \ i = 0; i < (int)t.size(); i++) a[i].y = t[i];\n    fft(a, k);\n\n    a[0].y\
    \ = 4.0 * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x * a[1].y;\n    a[0].x =\
    \ a[1].x = 0.0;\n    for (int i = 2; i < M; i += 2) {\n      int c = 1 << (31\
    \ - __builtin_clz(i));\n      int j = i ^ (c - 1);\n      a[i] = (a[i] + a[j].conj())\
    \ * (a[i] - a[j].conj());\n      a[j] = -a[i].conj();\n    }\n\n    vector<C>\
    \ b(M / 2);\n    for (int j = 0; j < M / 2; j++) {\n      C tmp1 = a[j * 2 + 0]\
    \ + a[j * 2 + 1];\n      C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();\n\
    \      b[j] = tmp1 + tmp2.rotl();\n    }\n    ifft(b, k - 1);\n\n    vector<long\
    \ long> u(l);\n    for (int i = 0; i < l; i++) {\n      if (i & 1) {\n       \
    \ u[i] = round(-b[i >> 1].x / (4.0 * M));\n      } else {\n        u[i] = round(b[i\
    \ >> 1].y / (4.0 * M));\n      }\n    }\n    return u;\n  }\n\n  static vector<double>\
    \ multiply(const vector<double>& s,\n                                 const vector<double>&\
    \ t) {\n    int l = s.size() + t.size() - 1;\n    if (min(s.size(), t.size())\
    \ <= 40) {\n      vector<double> u(l);\n      for (int i = 0; i < (int)s.size();\
    \ i++) {\n        for (int j = 0; j < (int)t.size(); j++) u[i + j] += s[i] * t[j];\n\
    \      }\n      return u;\n    }\n\n    int k = 2, M = 4;\n    while (M < l) M\
    \ <<= 1, ++k;\n    setw(k);\n\n    vector<C> a(M);\n    for (int i = 0; i < (int)s.size();\
    \ i++) a[i].x = s[i];\n    for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];\n\
    \    fft(a, k);\n\n    a[0].y = 4.0 * a[0].x * a[0].y;\n    a[1].y = 4.0 * a[1].x\
    \ * a[1].y;\n    a[0].x = a[1].x = 0.0;\n    for (int i = 2; i < M; i += 2) {\n\
    \      int c = 1 << (31 - __builtin_clz(i));\n      int j = i ^ (c - 1);\n   \
    \   a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());\n      a[j] = -a[i].conj();\n\
    \    }\n\n    vector<C> b(M / 2);\n    for (int j = 0; j < M / 2; j++) {\n   \
    \   C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];\n      C tmp2 = (a[j * 2 + 0] - a[j\
    \ * 2 + 1]) * w[j].conj();\n      b[j] = tmp1 + tmp2.rotl();\n    }\n    ifft(b,\
    \ k - 1);\n\n    vector<double> u(l);\n    for (int i = 0; i < l; i++) {\n   \
    \   if (i & 1) {\n        u[i] = -b[i >> 1].x / (4.0 * M);\n      } else {\n \
    \       u[i] = b[i >> 1].y / (4.0 * M);\n      }\n    }\n    return u;\n  }\n\n\
    \  template <unsigned int MOD = -1u>\n  static conditional_t<MOD == -1u, vector<__uint128_t>,\
    \ vector<int>>\n  multiply_15bit(const vector<int>& a, const vector<int>& b) {\n\
    \    using u64 = unsigned long long;\n    constexpr u64 B = 32000;\n    int l\
    \ = a.size() + b.size() - 1;\n    int k = 2, M = 4;\n    while (M < l) M <<= 1,\
    \ ++k;\n    setw(k);\n    auto round = [](double x) -> u64 { return u64(x + 0.5);\
    \ };\n\n    vector<C> AL(M), AH(M), BL(M), BH(M);\n    for (int i = 0; i < (int)a.size();\
    \ i++) {\n      AL[i] = C{double(a[i] % B), double(a[i] / B)};\n    }\n    for\
    \ (int i = 0; i < (int)b.size(); i++) {\n      BL[i] = C{double(b[i] % B), double(b[i]\
    \ / B)};\n    }\n\n    fft_real(AL, AH, k);\n    fft_real(BL, BH, k);\n\n    for\
    \ (int i = 0; i < M; i++) {\n      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();\n\
    \      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();\n      BL[i] = tmp;\n \
    \   }\n\n    ifft(BL, k);\n    ifft(BH, k);\n\n    using return_type =\n     \
    \   conditional_t<MOD + 1u == 0u, vector<__uint128_t>, vector<int>>;\n\n    return_type\
    \ u(l);\n    double im = 1.0 / (4.0 * M);\n    for (int i = 0; i < l; i++) {\n\
    \      BL[i].x *= im, BL[i].y *= im;\n      BH[i].x *= im, BH[i].y *= im;\n  \
    \    u64 s1 = round(BL[i].x);\n      u64 s2 = round(BH[i].x) + round(BH[i].y);\n\
    \      u64 s3 = round(BL[i].y);\n\n      if constexpr (MOD == -1u) {\n       \
    \ u[i] += __uint128_t(s1);\n        u[i] += __uint128_t(s2) * B;\n        u[i]\
    \ += __uint128_t(s3) * B * B;\n      } else {\n        u[i] += s1 % MOD;\n   \
    \     u[i] += s2 % MOD * B % MOD;\n        if (u[i] >= MOD) u[i] -= MOD;\n   \
    \     u[i] += s3 % MOD * (B * B % MOD) % MOD;\n        if (u[i] >= MOD) u[i] -=\
    \ MOD;\n      }\n    }\n    return u;\n  }\n};\nvector<C> CooleyTukey::w;\n\n\
    }  // namespace ArbitraryModConvolution\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/complex-fft.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/complex-fft.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-real-fft-15bit.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-real-fft-toom-3.test.cpp
documentation_of: ntt/complex-fft.hpp
layout: document
redirect_from:
- /library/ntt/complex-fft.hpp
- /library/ntt/complex-fft.hpp.html
title: ntt/complex-fft.hpp
---
