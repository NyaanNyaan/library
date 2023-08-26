---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ntt/cooley-tukey-ntt.hpp
    title: Cooley-Tukey FFT Algorithm
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: ntt/rader-ntt.hpp
    title: Rader's FFT Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-inv.test.cpp
    title: verify/verify-unit-test/fast-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1783.test.cpp
    title: verify/verify-yuki/yuki-1783.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u539F\u59CB\u6839"
    links: []
  bundledCode: "#line 2 \"math/primitive-root.hpp\"\n\nconstexpr uint32_t PrimitiveRoot(uint32_t\
    \ mod) {\n  using u64 = uint64_t;\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n\
    \  int idx = 0;\n  u64 m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n  \
    \  if (m % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n\
    \    }\n  }\n  if (m != 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n\
    \    int flg = 1;\n    for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b =\
    \ (mod - 1) / ds[i], r = 1;\n      while (b) {\n        if (b & 1) r = r * a %\
    \ mod;\n        a = a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1)\
    \ {\n        flg = 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n\
    \    ++pr;\n  }\n  return pr;\n}\n\n/**\n * @brief \u539F\u59CB\u6839\n */\n"
  code: "#pragma once\n\nconstexpr uint32_t PrimitiveRoot(uint32_t mod) {\n  using\
    \ u64 = uint64_t;\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n  int idx =\
    \ 0;\n  u64 m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n    if (m % i\
    \ == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n    }\n  }\n\
    \  if (m != 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n    int flg\
    \ = 1;\n    for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b = (mod - 1) /\
    \ ds[i], r = 1;\n      while (b) {\n        if (b & 1) r = r * a % mod;\n    \
    \    a = a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1) {\n      \
    \  flg = 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n    ++pr;\n\
    \  }\n  return pr;\n}\n\n/**\n * @brief \u539F\u59CB\u6839\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/primitive-root.hpp
  requiredBy:
  - ntt/rader-ntt.hpp
  - ntt/cooley-tukey-ntt.hpp
  - ntt/multivariate-circular-convolution.hpp
  timestamp: '2021-02-27 00:51:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1783.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  - verify/verify-unit-test/fast-inv.test.cpp
documentation_of: math/primitive-root.hpp
layout: document
redirect_from:
- /library/math/primitive-root.hpp
- /library/math/primitive-root.hpp.html
title: "\u539F\u59CB\u6839"
---
