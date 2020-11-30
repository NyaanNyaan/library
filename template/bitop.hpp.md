---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    \n__attribute__((target(\"bmi\"))) inline int botbit(const u64 &a) {\n  return\
    \ _tzcnt_u64(a);\n}\n__attribute__((target(\"bmi\"))) inline int ctz(const u64\
    \ &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"lzcnt\"))) inline\
    \ int topbit(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n"
  code: "namespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int botbit(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int topbit(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n\
    __attribute__((target(\"lzcnt\"))) inline int clz64(const u64 &a) {\n  return\
    \ _lzcnt_u64(a);\n}\n\ntemplate <typename T>\ninline int gbit(const T &a, int\
    \ i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void sbit(T &a,\
    \ int i, bool b) {\n  a ^= (gbit(a, i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr\
    \ long long PW(int n) { return 1LL << n; }\n\nconstexpr long long MSK(int n) {\
    \ return (1LL << n) - 1; }\n\n}  // namespace Nyaan\n"
  dependsOn: []
  isVerificationFile: false
  path: template/bitop.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/bitop.hpp
layout: document
redirect_from:
- /library/template/bitop.hpp
- /library/template/bitop.hpp.html
title: template/bitop.hpp
---
