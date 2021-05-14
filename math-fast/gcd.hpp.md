---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math-fast.test.cpp
    title: verify/verify-unit-test/math-fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: binary GCD
    links: []
  bundledCode: "#line 2 \"math-fast/gcd.hpp\"\n\n#include <algorithm>\nusing namespace\
    \ std;\n\nnamespace BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8\
    \ = char;\n\ninline u64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return\
    \ a + b;\n  i8 n = __builtin_ctzll(a);\n  i8 m = __builtin_ctzll(b);\n  a >>=\
    \ n;\n  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u64 d = a - b;\n \
    \   i8 s = __builtin_ctzll(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a\
    \ = (f ? d : -d) >> s;\n  }\n  return a << n;\n}\n}  // namespace BinaryGCDImpl\n\
    \nlong long gcd(long long a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a),\
    \ abs(b));\n}\nlong long lcm(long long a, long long b) { return a / gcd(a, b)\
    \ * b; }\n\n/**\n * @brief binary GCD\n */\n"
  code: "#pragma once\n\n#include <algorithm>\nusing namespace std;\n\nnamespace BinaryGCDImpl\
    \ {\nusing u64 = unsigned long long;\nusing i8 = char;\n\ninline u64 binary_gcd(u64\
    \ a, u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  i8 n = __builtin_ctzll(a);\n\
    \  i8 m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while\
    \ (a != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n    bool f =\
    \ a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a << n;\n\
    }\n}  // namespace BinaryGCDImpl\n\nlong long gcd(long long a, long long b) {\n\
    \  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\nlong long lcm(long long\
    \ a, long long b) { return a / gcd(a, b) * b; }\n\n/**\n * @brief binary GCD\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/gcd.hpp
  requiredBy: []
  timestamp: '2021-05-15 01:48:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/math-fast.test.cpp
documentation_of: math-fast/gcd.hpp
layout: document
redirect_from:
- /library/math-fast/gcd.hpp
- /library/math-fast/gcd.hpp.html
title: binary GCD
---
