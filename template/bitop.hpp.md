---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
    title: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0125.test.cpp
    title: verify/verify-yuki/yuki-0125.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0697.test.cpp
    title: verify/verify-yuki/yuki-0697.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0886.test.cpp
    title: verify/verify-yuki/yuki-0886.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0890.test.cpp
    title: verify/verify-yuki/yuki-0890.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0896.test.cpp
    title: verify/verify-yuki/yuki-0896.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1283.test.cpp
    title: verify/verify-yuki/yuki-1283.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    \n__attribute__((target(\"bmi\"))) inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n\
    }\n__attribute__((target(\"bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n\
    }\n\n__attribute__((target(\"lzcnt\"))) inline int msb(const u64 &a) {\n  return\
    \ 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"lzcnt\"))) inline int clz64(const\
    \ u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate <typename T>\ninline int gbit(const\
    \ T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename T>\ninline void\
    \ sbit(T &a, int i, bool b) {\n  a ^= (gbit(a, i) == b ? 0 : (T(b) << i));\n}\n\
    \nconstexpr long long PW(int n) { return 1LL << n; }\n\nconstexpr long long MSK(int\
    \ n) { return (1LL << n) - 1; }\n\n}  // namespace Nyaan\n"
  code: "namespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n"
  dependsOn: []
  isVerificationFile: false
  path: template/bitop.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-12-03 14:17:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - verify/verify-yuki/yuki-0896.test.cpp
  - verify/verify-yuki/yuki-0697.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yuki/yuki-0890.test.cpp
  - verify/verify-yuki/yuki-0125.test.cpp
  - verify/verify-yuki/yuki-0886.test.cpp
  - verify/verify-yuki/yuki-1283.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-unit-test/debug.test.cpp
documentation_of: template/bitop.hpp
layout: document
redirect_from:
- /library/template/bitop.hpp
- /library/template/bitop.hpp.html
title: template/bitop.hpp
---
