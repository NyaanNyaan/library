---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/bigint-all.hpp
    title: math/bigint-all.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint-gcd.hpp
    title: math/bigint-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint-rational.hpp
    title: math/bigint-rational.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational-binomial.hpp
    title: math/rational-binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational-fps.hpp
    title: math/rational-fps.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: math/rational.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
    title: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigint-gcd.test.cpp
    title: verify/verify-unit-test/bigint-gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigrational.test.cpp
    title: verify/verify-unit-test/bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/internal-math.test.cpp
    title: verify/verify-unit-test/internal-math.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math-fast-2.test.cpp
    title: verify/verify-unit-test/math-fast-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math-fast.test.cpp
    title: verify/verify-unit-test/math-fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rational-number.test.cpp
    title: verify/verify-unit-test/rational-number.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2262.test.cpp
    title: verify/verify-yuki/yuki-2262.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-3024.test.cpp
    title: verify/verify-yuki/yuki-3024.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: binary GCD
    links: []
  bundledCode: "#line 2 \"math-fast/gcd.hpp\"\n\n#include <algorithm>\nusing namespace\
    \ std;\n\nnamespace BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8\
    \ = char;\n\nu64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a\
    \ + b;\n  i8 n = __builtin_ctzll(a);\n  i8 m = __builtin_ctzll(b);\n  a >>= n;\n\
    \  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u64 d = a - b;\n    i8\
    \ s = __builtin_ctzll(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a = (f\
    \ ? d : -d) >> s;\n  }\n  return a << n;\n}\n\nusing u128 = __uint128_t;\n// a\
    \ > 0\nint ctz128(u128 a) {\n  u64 lo = a & u64(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n}\nu128 binary_gcd128(u128 a, u128 b) {\n\
    \  if (a == 0 || b == 0) return a + b;\n  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n\
    \  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u128 d = a\
    \ - b;\n    i8 s = ctz128(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a\
    \ = (f ? d : -d) >> s;\n  }\n  return a << n;\n}\n\n}  // namespace BinaryGCDImpl\n\
    \nlong long binary_gcd(long long a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a),\
    \ abs(b));\n}\n__int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a\
    \ < 0) a = -a;\n  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a,\
    \ b);\n}\n\n/**\n * @brief binary GCD\n */\n"
  code: "#pragma once\n\n#include <algorithm>\nusing namespace std;\n\nnamespace BinaryGCDImpl\
    \ {\nusing u64 = unsigned long long;\nusing i8 = char;\n\nu64 binary_gcd(u64 a,\
    \ u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  i8 n = __builtin_ctzll(a);\n\
    \  i8 m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while\
    \ (a != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n    bool f =\
    \ a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a << n;\n\
    }\n\nusing u128 = __uint128_t;\n// a > 0\nint ctz128(u128 a) {\n  u64 lo = a &\
    \ u64(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);\n\
    }\nu128 binary_gcd128(u128 a, u128 b) {\n  if (a == 0 || b == 0) return a + b;\n\
    \  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n  a >>= n;\n  b >>= m;\n  n = min(n,\
    \ m);\n  while (a != b) {\n    u128 d = a - b;\n    i8 s = ctz128(d);\n    bool\
    \ f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a\
    \ << n;\n}\n\n}  // namespace BinaryGCDImpl\n\nlong long binary_gcd(long long\
    \ a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\n\
    __int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a < 0) a = -a;\n\
    \  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a, b);\n}\n\n/**\n\
    \ * @brief binary GCD\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/gcd.hpp
  requiredBy:
  - math/bigint-rational.hpp
  - math/rational.hpp
  - math/bigint-all.hpp
  - math/bigint-gcd.hpp
  - math/rational-binomial.hpp
  - math/rational-fps.hpp
  timestamp: '2023-04-11 20:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/math-fast.test.cpp
  - verify/verify-unit-test/rational-number.test.cpp
  - verify/verify-unit-test/bigrational.test.cpp
  - verify/verify-unit-test/internal-math.test.cpp
  - verify/verify-unit-test/bigint-gcd.test.cpp
  - verify/verify-unit-test/math-fast-2.test.cpp
  - verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
  - verify/verify-yuki/yuki-2262.test.cpp
  - verify/verify-yuki/yuki-2266.test.cpp
  - verify/verify-yuki/yuki-3024.test.cpp
  - verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
documentation_of: math-fast/gcd.hpp
layout: document
redirect_from:
- /library/math-fast/gcd.hpp
- /library/math-fast/gcd.hpp.html
title: binary GCD
---
