---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-characteristic-polynomial.test.cpp
    title: verify/verify-yosupo-math/yosupo-characteristic-polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/characteristric-polynomial.hpp\"\n\n// calculate\
    \ det(a - xI)\ntemplate <typename mint>\nvector<mint> CharacteristicPolynomial(vector<vector<mint>>\
    \ a) {\n  int N = a.size();\n\n  for (int j = 0; j < N - 2; j++) {\n    for (int\
    \ i = j + 1; i < N; i++) {\n      if (a[i][j] != 0) {\n        swap(a[j + 1],\
    \ a[i]);\n        for (int k = 0; k < N; k++) swap(a[k][j + 1], a[k][i]);\n  \
    \      break;\n      }\n    }\n    if (a[j + 1][j] != 0) {\n      mint inv = mint(1)\
    \ / a[j + 1][j];\n      for (int i = j + 2; i < N; i++) {\n        if (a[i][j]\
    \ == 0) continue;\n        mint coe = inv * a[i][j];\n        for (int l = j;\
    \ l < N; l++) a[i][l] -= coe * a[j + 1][l];\n        for (int k = 0; k < N; k++)\
    \ a[k][j + 1] += coe * a[k][i];\n      }\n    }\n  }\n\n  vector<vector<mint>>\
    \ p(N + 1);\n  p[0] = {mint(1)};\n  for (int i = 1; i <= N; i++) {\n    p[i].resize(i\
    \ + 1);\n    for (int j = 0; j < i; j++) {\n      p[i][j + 1] -= p[i - 1][j];\n\
    \      p[i][j] += p[i - 1][j] * a[i - 1][i - 1];\n    }\n    mint x = 1;\n   \
    \ for (int m = 1; m < i; m++) {\n      x *= -a[i - m][i - m - 1];\n      mint\
    \ coe = x * a[i - m - 1][i - 1];\n      for (int j = 0; j < i - m; j++) p[i][j]\
    \ += coe * p[i - m - 1][j];\n    }\n  }\n  return p[N];\n}\n"
  code: "#pragma once\n\n// calculate det(a - xI)\ntemplate <typename mint>\nvector<mint>\
    \ CharacteristicPolynomial(vector<vector<mint>> a) {\n  int N = a.size();\n\n\
    \  for (int j = 0; j < N - 2; j++) {\n    for (int i = j + 1; i < N; i++) {\n\
    \      if (a[i][j] != 0) {\n        swap(a[j + 1], a[i]);\n        for (int k\
    \ = 0; k < N; k++) swap(a[k][j + 1], a[k][i]);\n        break;\n      }\n    }\n\
    \    if (a[j + 1][j] != 0) {\n      mint inv = mint(1) / a[j + 1][j];\n      for\
    \ (int i = j + 2; i < N; i++) {\n        if (a[i][j] == 0) continue;\n       \
    \ mint coe = inv * a[i][j];\n        for (int l = j; l < N; l++) a[i][l] -= coe\
    \ * a[j + 1][l];\n        for (int k = 0; k < N; k++) a[k][j + 1] += coe * a[k][i];\n\
    \      }\n    }\n  }\n\n  vector<vector<mint>> p(N + 1);\n  p[0] = {mint(1)};\n\
    \  for (int i = 1; i <= N; i++) {\n    p[i].resize(i + 1);\n    for (int j = 0;\
    \ j < i; j++) {\n      p[i][j + 1] -= p[i - 1][j];\n      p[i][j] += p[i - 1][j]\
    \ * a[i - 1][i - 1];\n    }\n    mint x = 1;\n    for (int m = 1; m < i; m++)\
    \ {\n      x *= -a[i - m][i - m - 1];\n      mint coe = x * a[i - m - 1][i - 1];\n\
    \      for (int j = 0; j < i - m; j++) p[i][j] += coe * p[i - m - 1][j];\n   \
    \ }\n  }\n  return p[N];\n}"
  dependsOn: []
  isVerificationFile: false
  path: matrix/characteristric-polynomial.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:18:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-characteristic-polynomial.test.cpp
documentation_of: matrix/characteristric-polynomial.hpp
layout: document
redirect_from:
- /library/matrix/characteristric-polynomial.hpp
- /library/matrix/characteristric-polynomial.hpp.html
title: matrix/characteristric-polynomial.hpp
---
