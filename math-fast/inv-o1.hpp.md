---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-inv-o1.test.cpp
    title: verify/verify-unit-test/fast-inv-o1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math-fast/inv-o1.hpp\"\n\n#include <cmath>\nusing namespace\
    \ std;\n\n// O(1) \u9006\u5143, \u7D20\u6570 mod \u3067\u52D5\u304F\ntemplate\
    \ <int MOD>\nstruct Inverse_O1 {\n  static constexpr int p = MOD;\n  static constexpr\
    \ int n = ceil(pow(p, 1.0 / 3));\n  static constexpr int n2 = n * n;\n  static\
    \ constexpr int preinv_size = n2 + (n << 10) + 10;\n\n  int g[(p >> 10) + 1],\
    \ preinv[preinv_size];\n  Inverse_O1() {\n    preinv[0] = preinv[1] = 1 % p;\n\
    \    for (int i = 2; i < preinv_size; i++) {\n      preinv[i] = 1LL * preinv[p\
    \ % i] * (p - p / i) % p;\n    }\n\n    int pre[n2 + 1], suf[n2 + 1];\n    for\
    \ (int i = 0; i <= n2; i++) pre[i] = suf[i] = 0;\n    for (int y = 1; y < n; y++)\
    \ {\n      for (int x = 0; x <= y; x++) {\n        int z = x * n2 / y;\n     \
    \   if (!pre[z]) pre[z] = suf[z] = (x << 16) + y;\n      }\n    }\n    for (int\
    \ i = 1; i <= n2; i++) {\n      if (!pre[i]) pre[i] = pre[i - 1];\n    }\n   \
    \ for (int i = n2 - 1; i >= 0; i--) {\n      if (!suf[i]) suf[i] = suf[i + 1];\n\
    \    }\n    for (int j = 0; (j << 10) < p; j++) {\n      int a = j << 10;\n  \
    \    int i = 1LL * a * n2 / p;\n      int x1 = pre[i] >> 16, y1 = pre[i] & 65535;\n\
    \      int x2 = suf[i] >> 16, y2 = suf[i] & 65535;\n      int u1 = 1LL * a * y1\
    \ - 1LL * p * x1;\n      int u2 = 1LL * a * y2 - 1LL * p * x2;\n      g[j] = abs(u1)\
    \ < abs(u2) ? y1 : y2;\n    }\n  }\n\n  int inv(int a) {\n    int y = g[a >> 10],\
    \ z = 1LL * a * y % p;\n    return 1LL * y * (z < preinv_size ? preinv[z] : p\
    \ - preinv[p - z]) % p;\n  }\n  int operator()(int a) { return inv(a); }\n};\n"
  code: "#pragma once\n\n#include <cmath>\nusing namespace std;\n\n// O(1) \u9006\u5143\
    , \u7D20\u6570 mod \u3067\u52D5\u304F\ntemplate <int MOD>\nstruct Inverse_O1 {\n\
    \  static constexpr int p = MOD;\n  static constexpr int n = ceil(pow(p, 1.0 /\
    \ 3));\n  static constexpr int n2 = n * n;\n  static constexpr int preinv_size\
    \ = n2 + (n << 10) + 10;\n\n  int g[(p >> 10) + 1], preinv[preinv_size];\n  Inverse_O1()\
    \ {\n    preinv[0] = preinv[1] = 1 % p;\n    for (int i = 2; i < preinv_size;\
    \ i++) {\n      preinv[i] = 1LL * preinv[p % i] * (p - p / i) % p;\n    }\n\n\
    \    int pre[n2 + 1], suf[n2 + 1];\n    for (int i = 0; i <= n2; i++) pre[i] =\
    \ suf[i] = 0;\n    for (int y = 1; y < n; y++) {\n      for (int x = 0; x <= y;\
    \ x++) {\n        int z = x * n2 / y;\n        if (!pre[z]) pre[z] = suf[z] =\
    \ (x << 16) + y;\n      }\n    }\n    for (int i = 1; i <= n2; i++) {\n      if\
    \ (!pre[i]) pre[i] = pre[i - 1];\n    }\n    for (int i = n2 - 1; i >= 0; i--)\
    \ {\n      if (!suf[i]) suf[i] = suf[i + 1];\n    }\n    for (int j = 0; (j <<\
    \ 10) < p; j++) {\n      int a = j << 10;\n      int i = 1LL * a * n2 / p;\n \
    \     int x1 = pre[i] >> 16, y1 = pre[i] & 65535;\n      int x2 = suf[i] >> 16,\
    \ y2 = suf[i] & 65535;\n      int u1 = 1LL * a * y1 - 1LL * p * x1;\n      int\
    \ u2 = 1LL * a * y2 - 1LL * p * x2;\n      g[j] = abs(u1) < abs(u2) ? y1 : y2;\n\
    \    }\n  }\n\n  int inv(int a) {\n    int y = g[a >> 10], z = 1LL * a * y % p;\n\
    \    return 1LL * y * (z < preinv_size ? preinv[z] : p - preinv[p - z]) % p;\n\
    \  }\n  int operator()(int a) { return inv(a); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/inv-o1.hpp
  requiredBy: []
  timestamp: '2023-12-22 19:57:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/fast-inv-o1.test.cpp
documentation_of: math-fast/inv-o1.hpp
layout: document
redirect_from:
- /library/math-fast/inv-o1.hpp
- /library/math-fast/inv-o1.hpp.html
title: math-fast/inv-o1.hpp
---
