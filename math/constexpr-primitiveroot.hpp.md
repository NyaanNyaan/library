---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/dual-fps.hpp
    title: "\u5468\u6CE2\u6570\u9818\u57DF\u3067\u306E\u5024\u3092\u4FDD\u6301\u3059\
      \u308BFPS"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dual-fps.test.cpp
    title: verify/verify-unit-test/dual-fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primitive-root.test.cpp
    title: verify/verify-unit-test/primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1504.test.cpp
    title: verify/verify-yuki/yuki-1504.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/constexpr-primitiveroot.hpp\"\n\nconstexpr unsigned\
    \ int constexpr_primitive_root(unsigned int mod) {\n  using u32 = unsigned int;\n\
    \  using u64 = unsigned long long;\n  if(mod == 2) return 1;\n  u64 m = mod -\
    \ 1, ds[32] = {}, idx = 0;\n  for (u64 i = 2; i * i <= m; ++i) {\n    if (m %\
    \ i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n    }\n \
    \ }\n  if (m != 1) ds[idx++] = m;\n  for (u32 _pr = 2, flg = true;; _pr++, flg\
    \ = true) {\n    for (u32 i = 0; i < idx && flg; ++i) {\n      u64 a = _pr, b\
    \ = (mod - 1) / ds[i], r = 1;\n      for (; b; a = a * a % mod, b >>= 1)\n   \
    \     if (b & 1) r = r * a % mod;\n      if (r == 1) flg = false;\n    }\n   \
    \ if (flg == true) return _pr;\n  }\n}\n\n"
  code: "#pragma once\n\nconstexpr unsigned int constexpr_primitive_root(unsigned\
    \ int mod) {\n  using u32 = unsigned int;\n  using u64 = unsigned long long;\n\
    \  if(mod == 2) return 1;\n  u64 m = mod - 1, ds[32] = {}, idx = 0;\n  for (u64\
    \ i = 2; i * i <= m; ++i) {\n    if (m % i == 0) {\n      ds[idx++] = i;\n   \
    \   while (m % i == 0) m /= i;\n    }\n  }\n  if (m != 1) ds[idx++] = m;\n  for\
    \ (u32 _pr = 2, flg = true;; _pr++, flg = true) {\n    for (u32 i = 0; i < idx\
    \ && flg; ++i) {\n      u64 a = _pr, b = (mod - 1) / ds[i], r = 1;\n      for\
    \ (; b; a = a * a % mod, b >>= 1)\n        if (b & 1) r = r * a % mod;\n     \
    \ if (r == 1) flg = false;\n    }\n    if (flg == true) return _pr;\n  }\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/constexpr-primitiveroot.hpp
  requiredBy:
  - fps/dual-fps.hpp
  timestamp: '2021-05-18 09:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/dual-fps.test.cpp
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-yuki/yuki-1504.test.cpp
documentation_of: math/constexpr-primitiveroot.hpp
layout: document
redirect_from:
- /library/math/constexpr-primitiveroot.hpp
- /library/math/constexpr-primitiveroot.hpp.html
title: math/constexpr-primitiveroot.hpp
---
