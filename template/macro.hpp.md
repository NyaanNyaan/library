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
  bundledCode: "#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x :\
    \ v)\n#define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long\
    \ i = 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long\
    \ long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long\
    \ long)(N); i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) >\
    \ 0; i--)\n#define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define\
    \ regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n#define repc(i, a, cond)\
    \ for (long long i = (a); (cond); i++)\n\n#define ini(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define in2(s, t)                           \\\n  for (int i = 0; i < (int)s.size();\
    \ i++) { \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s,\
    \ t, u)                        \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u,\
    \ v)                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)     \
    \        \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n\
    \    return;                  \\\n  } while (0)\n"
  code: "#define each(x, v) for (auto&& x : v)\n#define all(v) (v).begin(), (v).end()\n\
    #define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i,\
    \ N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for\
    \ (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long\
    \ i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define repc(i, a, cond) for (long long i = (a); (cond); i++)\n\n#define ini(...)\
    \   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)         \\\n\
    \  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)      \\\n  string\
    \ __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inc(...)    \\\n  char __VA_ARGS__;\
    \ \\\n  in(__VA_ARGS__)\n#define in2(s, t)                           \\\n  for\
    \ (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);              \
    \           \\\n  }\n#define in3(s, t, u)                        \\\n  for (int\
    \ i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);             \
    \      \\\n  }\n#define in4(s, t, u, v)                     \\\n  for (int i =\
    \ 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);           \
    \  \\\n  }\n\n#define die(...)             \\\n  do {                       \\\
    \n    Nyaan::out(__VA_ARGS__); \\\n    return;                  \\\n  } while\
    \ (0)\n"
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-11-30 22:35:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-yuki/yuki-1283.test.cpp
  - verify/verify-yuki/yuki-0886.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yuki/yuki-0697.test.cpp
  - verify/verify-yuki/yuki-0890.test.cpp
  - verify/verify-yuki/yuki-0896.test.cpp
  - verify/verify-yuki/yuki-0125.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
