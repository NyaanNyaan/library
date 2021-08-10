---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primitive-root.test.cpp
    title: verify/verify-unit-test/primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"inner/inner_math.hpp\"\n\nnamespace inner {\n\nusing i32\
    \ = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\
    \ntemplate <typename T>\nT gcd(T a, T b) {\n  while (b) swap(a %= b, b);\n  return\
    \ a;\n}\n\ntemplate <typename T>\nT inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n\
    \  while (a) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n\
    \  }\n  assert(b == 1);\n  return y < 0 ? y + p : y;\n}\n\ntemplate <typename\
    \ T, typename U>\nT modpow(T a, U n, T p) {\n  T ret = 1 % p;\n  for (; n; n >>=\
    \ 1, a = U(a) * a % p)\n    if (n & 1) ret = U(ret) * a % p;\n  return ret;\n\
    }\n\n}  // namespace inner\n"
  code: "#pragma once\n\nnamespace inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\n\
    using i64 = int64_t;\nusing u64 = uint64_t;\n\ntemplate <typename T>\nT gcd(T\
    \ a, T b) {\n  while (b) swap(a %= b, b);\n  return a;\n}\n\ntemplate <typename\
    \ T>\nT inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b\
    \ / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n\
    \  return y < 0 ? y + p : y;\n}\n\ntemplate <typename T, typename U>\nT modpow(T\
    \ a, U n, T p) {\n  T ret = 1 % p;\n  for (; n; n >>= 1, a = U(a) * a % p)\n \
    \   if (n & 1) ret = U(ret) * a % p;\n  return ret;\n}\n\n}  // namespace inner\n"
  dependsOn: []
  isVerificationFile: false
  path: inner/inner_math.hpp
  requiredBy:
  - modulo/mod-log.hpp
  - modulo/mod-kth-root.hpp
  - prime/fast-factorize.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-unit-test/osak.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: inner/inner_math.hpp
layout: document
redirect_from:
- /library/inner/inner_math.hpp
- /library/inner/inner_math.hpp.html
title: inner/inner_math.hpp
---
