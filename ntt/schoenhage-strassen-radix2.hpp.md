---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Sch\xF6nhage-Strassen Algorithm(radix-2)"
    links: []
  bundledCode: "#line 2 \"ntt/schoenhage-strassen-radix2.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Schoenhage_Strassen_radix2 {\n  T* buf = nullptr;\n\n  void rot(T*\
    \ dst, T* src, int s, int d) {\n    assert(0 <= d and d < 2 * s);\n    bool f\
    \ = s <= d;\n    if (s <= d) d -= s;\n    int i = 0;\n    if (f) {\n      for\
    \ (; i < s - d; i++) dst[i + d] = -src[i];\n      for (; i < s; i++) dst[i + d\
    \ - s] = src[i];\n    } else {\n      for (; i < s - d; i++) dst[i + d] = src[i];\n\
    \      for (; i < s; i++) dst[i + d - s] = -src[i];\n    }\n  }\n\n  void in_add(T*\
    \ dst, T* src, int s) {\n    for (int i = 0; i < s; i++) dst[i] += src[i];\n \
    \ }\n  void in_sub(T* dst, T* src, int s) {\n    for (int i = 0; i < s; i++) dst[i]\
    \ -= src[i];\n  }\n\n  void cp(T* dst, T* src, int s) { memcpy(dst, src, s * sizeof(T));\
    \ }\n  void reset(T* dst, int s) { fill(dst, dst + s, T()); }\n\n  // R[x] / (1\
    \ + x^(2^m)) \u4E0A\u306E\u9577\u30552^L\u306EFFT\n  void fft(T* a, int l, int\
    \ m) {\n    if (l == 0) return;\n    int L = 1 << l, M = 1 << m;\n    assert(M\
    \ * 2 >= L);\n    assert(buf != nullptr);\n\n    vector<int> dw(l - 1);\n    for\
    \ (int i = 0; i < l - 1; i++) {\n      dw[i] = (1 << (l - 2 - i)) + (1 << (l -\
    \ 1 - i)) - (1 << (l - 1));\n      if (dw[i] < 0) dw[i] += L;\n      if (L ==\
    \ M) dw[i] *= 2;\n      if (2 * L == M) dw[i] *= 4;\n    }\n\n    for (int d =\
    \ L; d >>= 1;) {\n      int w = 0;\n      for (int s = 0, k = 0;;) {\n       \
    \ for (int i = s, j = s + d; i < s + d; ++i, ++j) {\n          T *ai = a + i *\
    \ M, *aj = a + j * M;\n          rot(buf, aj, M, w);\n          cp(aj, ai, M);\n\
    \          in_add(ai, buf, M);\n          in_sub(aj, buf, M);\n        }\n   \
    \     if ((s += 2 * d) >= L) break;\n        w += dw[__builtin_ctz(++k)];\n  \
    \      if (w >= 2 * M) w -= 2 * M;\n      }\n    }\n  }\n\n  // R[x] / (1 + x^(2^m))\
    \ \u4E0A\u306E\u9577\u30552^L\u306EIFFT\n  void ifft(T* a, int l, int m) {\n \
    \   if (l == 0) return;\n    int L = 1 << l, M = 1 << m;\n    assert(M * 2 >=\
    \ L);\n    assert(buf != nullptr);\n\n    vector<int> dw(l - 1);\n    for (int\
    \ i = 0; i < l - 1; i++) {\n      dw[i] = (1 << (l - 2 - i)) + (1 << (l - 1 -\
    \ i)) - (1 << (l - 1));\n      if (dw[i] < 0) dw[i] += L;\n      if (L == M) dw[i]\
    \ *= 2;\n      if (2 * L == M) dw[i] *= 4;\n    }\n\n    for (int d = 1; d < L;\
    \ d *= 2) {\n      int w = 0;\n      for (int s = 0, k = 0;;) {\n        for (int\
    \ i = s, j = s + d; i < s + d; ++i, ++j) {\n          T *ai = a + i * M, *aj =\
    \ a + j * M;\n          cp(buf, ai, M);\n          in_add(ai, aj, M);\n      \
    \    in_sub(buf, aj, M);\n          rot(aj, buf, M, w);\n        }\n        if\
    \ ((s += 2 * d) >= L) break;\n        w -= dw[__builtin_ctz(++k)];\n        if\
    \ (w < 0) w += 2 * M;\n      }\n    }\n  }\n\n  // a <- ab / (x^(2^n)+1)\n  int\
    \ naive_mul(T* a, T* b, int n) {\n    int N = 1 << n;\n    reset(buf, N);\n  \
    \  for (int i = 0; i < N; i++) {\n      int j = 0;\n      for (; j < N - i; j++)\
    \ buf[i + j] += a[i] * b[j];\n      for (; j < N; j++) buf[i + j - N] -= a[i]\
    \ * b[j];\n    }\n    cp(a, buf, N);\n    return 0;\n  }\n\n  // a <- ab / (x^(2^n)+1)\n\
    \  int inplace_mul(T* a, T* b, int n) {\n    if (n <= 5) {\n      naive_mul(a,\
    \ b, n);\n      return 0;\n    }\n\n    int l = (n + 1) / 2;\n    int m = n /\
    \ 2;\n    int L = 1 << l, M = 1 << m, N = 1 << n;\n    int cnt = 0;\n\n    //\
    \ R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n    vector<T> A(N * 2), B(N * 2);\n \
    \   reset(buf + M, M);\n    for (int i = 0, s = 0, ds = 2 * M / L; i < L; i++)\
    \ {\n      // y -> x^{2m/r} y\n      cp(buf, a + i * M, M);\n      rot(A.data()\
    \ + i * M * 2, buf, 2 * M, s);\n      cp(buf, b + i * M, M);\n      rot(B.data()\
    \ + i * M * 2, buf, 2 * M, s);\n      s += ds;\n      if (s >= 4 * M) s -= 4 *\
    \ M;\n    }\n\n    fft(A.data(), l, m + 1);\n    fft(B.data(), l, m + 1);\n  \
    \  for (int i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data() + i * M * 2,\
    \ B.data() + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m + 1);\n\n    for\
    \ (int i = 0, s = 0, ds = 2 * M / L; i < L; i++) {\n      // y -> x^{-2m/r} y\n\
    \      cp(buf, A.data() + i * M * 2, 2 * M);\n      rot(A.data() + i * M * 2,\
    \ buf, 2 * M, s);\n      s -= ds;\n      if (s < 0) s += 4 * M;\n    }\n\n   \
    \ for (int i = 0; i < L; i++) {\n      for (int j = 0; j < M; j++) {\n       \
    \ a[i * M + j] = A[i * M * 2 + j];\n        if (i == 0) {\n          a[i * M +\
    \ j] -= A[(L - 1) * M * 2 + M + j];\n        } else {\n          a[i * M + j]\
    \ += A[(i - 1) * M * 2 + M + j];\n        }\n      }\n    }\n    return cnt +\
    \ l;\n  }\n\n  // a <- ab / (x^(2^n)-1)\n  int inplace_mul2(T* a, T* b, int n)\
    \ {\n    if (n <= 5) {\n      naive_mul(a, b, n);\n      return 0;\n    }\n\n\
    \    int l = (n + 1) / 2;\n    int m = n / 2;\n    int L = 1 << l, M = 1 << m,\
    \ N = 1 << n;\n    int cnt = 0;\n\n    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n\
    \    vector<T> A(N * 2), B(N * 2);\n    for (int i = 0; i < L; i++) {\n      cp(A.data()\
    \ + i * M * 2, a + i * M, M);\n      cp(B.data() + i * M * 2, b + i * M, M);\n\
    \    }\n    fft(A.data(), l, m + 1);\n    fft(B.data(), l, m + 1);\n    for (int\
    \ i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data() + i * M * 2, B.data()\
    \ + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m + 1);\n    for (int i =\
    \ 0; i < L; i++) {\n      for (int j = 0; j < M; j++) {\n        a[i * M + j]\
    \ = A[i * M * 2 + j];\n        a[i * M + j] += A[(i ? i - 1 : L - 1) * M * 2 +\
    \ M + j];\n      }\n    }\n    return cnt + l;\n  }\n\n  pair<vector<T>, int>\
    \ multiply(const vector<T>& a, const vector<T>& b) {\n    int L = a.size() + b.size()\
    \ - 1;\n    int M = 1, m = 0;\n    while (M < L) M *= 2, m++;\n    buf = new T[M];\n\
    \    vector<T> s(M), t(M);\n    for (int i = 0; i < (int)a.size(); i++) s[i] =\
    \ a[i];\n    for (int i = 0; i < (int)b.size(); i++) t[i] = b[i];\n    int cnt\
    \ = inplace_mul2(s.data(), t.data(), m);\n    vector<T> u(L);\n    for (int i\
    \ = 0; i < L; i++) u[i] = s[i];\n    delete[] buf;\n    return make_pair(u, cnt);\n\
    \  }\n};\n\n/**\n * @brief Sch\xF6nhage-Strassen Algorithm(radix-2)\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Schoenhage_Strassen_radix2\
    \ {\n  T* buf = nullptr;\n\n  void rot(T* dst, T* src, int s, int d) {\n    assert(0\
    \ <= d and d < 2 * s);\n    bool f = s <= d;\n    if (s <= d) d -= s;\n    int\
    \ i = 0;\n    if (f) {\n      for (; i < s - d; i++) dst[i + d] = -src[i];\n \
    \     for (; i < s; i++) dst[i + d - s] = src[i];\n    } else {\n      for (;\
    \ i < s - d; i++) dst[i + d] = src[i];\n      for (; i < s; i++) dst[i + d - s]\
    \ = -src[i];\n    }\n  }\n\n  void in_add(T* dst, T* src, int s) {\n    for (int\
    \ i = 0; i < s; i++) dst[i] += src[i];\n  }\n  void in_sub(T* dst, T* src, int\
    \ s) {\n    for (int i = 0; i < s; i++) dst[i] -= src[i];\n  }\n\n  void cp(T*\
    \ dst, T* src, int s) { memcpy(dst, src, s * sizeof(T)); }\n  void reset(T* dst,\
    \ int s) { fill(dst, dst + s, T()); }\n\n  // R[x] / (1 + x^(2^m)) \u4E0A\u306E\
    \u9577\u30552^L\u306EFFT\n  void fft(T* a, int l, int m) {\n    if (l == 0) return;\n\
    \    int L = 1 << l, M = 1 << m;\n    assert(M * 2 >= L);\n    assert(buf != nullptr);\n\
    \n    vector<int> dw(l - 1);\n    for (int i = 0; i < l - 1; i++) {\n      dw[i]\
    \ = (1 << (l - 2 - i)) + (1 << (l - 1 - i)) - (1 << (l - 1));\n      if (dw[i]\
    \ < 0) dw[i] += L;\n      if (L == M) dw[i] *= 2;\n      if (2 * L == M) dw[i]\
    \ *= 4;\n    }\n\n    for (int d = L; d >>= 1;) {\n      int w = 0;\n      for\
    \ (int s = 0, k = 0;;) {\n        for (int i = s, j = s + d; i < s + d; ++i, ++j)\
    \ {\n          T *ai = a + i * M, *aj = a + j * M;\n          rot(buf, aj, M,\
    \ w);\n          cp(aj, ai, M);\n          in_add(ai, buf, M);\n          in_sub(aj,\
    \ buf, M);\n        }\n        if ((s += 2 * d) >= L) break;\n        w += dw[__builtin_ctz(++k)];\n\
    \        if (w >= 2 * M) w -= 2 * M;\n      }\n    }\n  }\n\n  // R[x] / (1 +\
    \ x^(2^m)) \u4E0A\u306E\u9577\u30552^L\u306EIFFT\n  void ifft(T* a, int l, int\
    \ m) {\n    if (l == 0) return;\n    int L = 1 << l, M = 1 << m;\n    assert(M\
    \ * 2 >= L);\n    assert(buf != nullptr);\n\n    vector<int> dw(l - 1);\n    for\
    \ (int i = 0; i < l - 1; i++) {\n      dw[i] = (1 << (l - 2 - i)) + (1 << (l -\
    \ 1 - i)) - (1 << (l - 1));\n      if (dw[i] < 0) dw[i] += L;\n      if (L ==\
    \ M) dw[i] *= 2;\n      if (2 * L == M) dw[i] *= 4;\n    }\n\n    for (int d =\
    \ 1; d < L; d *= 2) {\n      int w = 0;\n      for (int s = 0, k = 0;;) {\n  \
    \      for (int i = s, j = s + d; i < s + d; ++i, ++j) {\n          T *ai = a\
    \ + i * M, *aj = a + j * M;\n          cp(buf, ai, M);\n          in_add(ai, aj,\
    \ M);\n          in_sub(buf, aj, M);\n          rot(aj, buf, M, w);\n        }\n\
    \        if ((s += 2 * d) >= L) break;\n        w -= dw[__builtin_ctz(++k)];\n\
    \        if (w < 0) w += 2 * M;\n      }\n    }\n  }\n\n  // a <- ab / (x^(2^n)+1)\n\
    \  int naive_mul(T* a, T* b, int n) {\n    int N = 1 << n;\n    reset(buf, N);\n\
    \    for (int i = 0; i < N; i++) {\n      int j = 0;\n      for (; j < N - i;\
    \ j++) buf[i + j] += a[i] * b[j];\n      for (; j < N; j++) buf[i + j - N] -=\
    \ a[i] * b[j];\n    }\n    cp(a, buf, N);\n    return 0;\n  }\n\n  // a <- ab\
    \ / (x^(2^n)+1)\n  int inplace_mul(T* a, T* b, int n) {\n    if (n <= 5) {\n \
    \     naive_mul(a, b, n);\n      return 0;\n    }\n\n    int l = (n + 1) / 2;\n\
    \    int m = n / 2;\n    int L = 1 << l, M = 1 << m, N = 1 << n;\n    int cnt\
    \ = 0;\n\n    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n    vector<T> A(N * 2),\
    \ B(N * 2);\n    reset(buf + M, M);\n    for (int i = 0, s = 0, ds = 2 * M / L;\
    \ i < L; i++) {\n      // y -> x^{2m/r} y\n      cp(buf, a + i * M, M);\n    \
    \  rot(A.data() + i * M * 2, buf, 2 * M, s);\n      cp(buf, b + i * M, M);\n \
    \     rot(B.data() + i * M * 2, buf, 2 * M, s);\n      s += ds;\n      if (s >=\
    \ 4 * M) s -= 4 * M;\n    }\n\n    fft(A.data(), l, m + 1);\n    fft(B.data(),\
    \ l, m + 1);\n    for (int i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data()\
    \ + i * M * 2, B.data() + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m +\
    \ 1);\n\n    for (int i = 0, s = 0, ds = 2 * M / L; i < L; i++) {\n      // y\
    \ -> x^{-2m/r} y\n      cp(buf, A.data() + i * M * 2, 2 * M);\n      rot(A.data()\
    \ + i * M * 2, buf, 2 * M, s);\n      s -= ds;\n      if (s < 0) s += 4 * M;\n\
    \    }\n\n    for (int i = 0; i < L; i++) {\n      for (int j = 0; j < M; j++)\
    \ {\n        a[i * M + j] = A[i * M * 2 + j];\n        if (i == 0) {\n       \
    \   a[i * M + j] -= A[(L - 1) * M * 2 + M + j];\n        } else {\n          a[i\
    \ * M + j] += A[(i - 1) * M * 2 + M + j];\n        }\n      }\n    }\n    return\
    \ cnt + l;\n  }\n\n  // a <- ab / (x^(2^n)-1)\n  int inplace_mul2(T* a, T* b,\
    \ int n) {\n    if (n <= 5) {\n      naive_mul(a, b, n);\n      return 0;\n  \
    \  }\n\n    int l = (n + 1) / 2;\n    int m = n / 2;\n    int L = 1 << l, M =\
    \ 1 << m, N = 1 << n;\n    int cnt = 0;\n\n    // R[x] (x^(2^(m+1))-1) R[y] (y^(2^l)-1)\n\
    \    vector<T> A(N * 2), B(N * 2);\n    for (int i = 0; i < L; i++) {\n      cp(A.data()\
    \ + i * M * 2, a + i * M, M);\n      cp(B.data() + i * M * 2, b + i * M, M);\n\
    \    }\n    fft(A.data(), l, m + 1);\n    fft(B.data(), l, m + 1);\n    for (int\
    \ i = 0; i < L; i++) {\n      cnt = inplace_mul(A.data() + i * M * 2, B.data()\
    \ + i * M * 2, m + 1);\n    }\n    ifft(A.data(), l, m + 1);\n    for (int i =\
    \ 0; i < L; i++) {\n      for (int j = 0; j < M; j++) {\n        a[i * M + j]\
    \ = A[i * M * 2 + j];\n        a[i * M + j] += A[(i ? i - 1 : L - 1) * M * 2 +\
    \ M + j];\n      }\n    }\n    return cnt + l;\n  }\n\n  pair<vector<T>, int>\
    \ multiply(const vector<T>& a, const vector<T>& b) {\n    int L = a.size() + b.size()\
    \ - 1;\n    int M = 1, m = 0;\n    while (M < L) M *= 2, m++;\n    buf = new T[M];\n\
    \    vector<T> s(M), t(M);\n    for (int i = 0; i < (int)a.size(); i++) s[i] =\
    \ a[i];\n    for (int i = 0; i < (int)b.size(); i++) t[i] = b[i];\n    int cnt\
    \ = inplace_mul2(s.data(), t.data(), m);\n    vector<T> u(L);\n    for (int i\
    \ = 0; i < L; i++) u[i] = s[i];\n    delete[] buf;\n    return make_pair(u, cnt);\n\
    \  }\n};\n\n/**\n * @brief Sch\xF6nhage-Strassen Algorithm(radix-2)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/schoenhage-strassen-radix2.hpp
  requiredBy: []
  timestamp: '2021-06-12 11:33:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-schoenhage-radix2.test.cpp
documentation_of: ntt/schoenhage-strassen-radix2.hpp
layout: document
redirect_from:
- /library/ntt/schoenhage-strassen-radix2.hpp
- /library/ntt/schoenhage-strassen-radix2.hpp.html
title: "Sch\xF6nhage-Strassen Algorithm(radix-2)"
---
