---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/macro.hpp\"\n#include <bits/stdc++.h>\n\n#define\
    \ each(x, v) for (auto&& x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n#define repr(i, N)\
    \ for (long long i = (long long)(N)-1; i >= 0; i--)\n#define rep1(i, N) for (long\
    \ long i = 1; i <= (long long)(N); i++)\n#define repr1(i, N) for (long long i\
    \ = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for (long long i = (a);\
    \ i < (b); i++)\n#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n\
    #define repc(i, a, cond) for (long long i = (a); (cond); i++)\n\n#define die(...)\
    \      \\\n  do {                \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;\
    \           \\\n  } while (0)\n"
  code: "#include <bits/stdc++.h>\n\n#define each(x, v) for (auto&& x : v)\n#define\
    \ all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0; i < (long\
    \ long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1; i >=\
    \ 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n\
    #define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n#define\
    \ reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for\
    \ (long long i = (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long\
    \ i = (a); (cond); i++)\n\n#define die(...)      \\\n  do {                \\\n\
    \    Nyaan::out(__VA_ARGS__); \\\n    return;           \\\n  } while (0)\n"
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
