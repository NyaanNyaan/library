---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/determinant-arbitrary-mod.hpp\"\n\n#include <vector>\n\
    using namespace std;\n\ntemplate <typename mint>\nmint determinant_arbitrary_mod(vector<vector<mint>>\
    \ a) {\n  int n = a.size();\n  mint det = 1;\n  for (int j = 0; j < n; j++) {\n\
    \    for (int i = j; i < n; i++) {\n      if (a[i][j] == 0) continue;\n      if\
    \ (i != j) swap(a[i], a[j]), det = -det;\n      break;\n    }\n    if (a[j][j]\
    \ == 0) return 0;\n    for (int i = j + 1; i < n; i++) {\n      while (a[i][j]\
    \ != 0) {\n        long long q = a[j][j].get() / a[i][j].get();\n        mint\
    \ c = -q;\n        for (int k = j; k < n; k++) a[j][k] += a[i][k] * c;\n     \
    \   swap(a[i], a[j]), det = -det;\n      }\n    }\n  }\n\n  for (int i = 0; i\
    \ < n; i++) det *= a[i][i];\n  return det;\n}\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ mint>\nmint determinant_arbitrary_mod(vector<vector<mint>> a) {\n  int n = a.size();\n\
    \  mint det = 1;\n  for (int j = 0; j < n; j++) {\n    for (int i = j; i < n;\
    \ i++) {\n      if (a[i][j] == 0) continue;\n      if (i != j) swap(a[i], a[j]),\
    \ det = -det;\n      break;\n    }\n    if (a[j][j] == 0) return 0;\n    for (int\
    \ i = j + 1; i < n; i++) {\n      while (a[i][j] != 0) {\n        long long q\
    \ = a[j][j].get() / a[i][j].get();\n        mint c = -q;\n        for (int k =\
    \ j; k < n; k++) a[j][k] += a[i][k] * c;\n        swap(a[i], a[j]), det = -det;\n\
    \      }\n    }\n  }\n\n  for (int i = 0; i < n; i++) det *= a[i][i];\n  return\
    \ det;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/determinant-arbitrary-mod.hpp
  requiredBy: []
  timestamp: '2023-09-02 22:21:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
documentation_of: matrix/determinant-arbitrary-mod.hpp
layout: document
redirect_from:
- /library/matrix/determinant-arbitrary-mod.hpp
- /library/matrix/determinant-arbitrary-mod.hpp.html
title: matrix/determinant-arbitrary-mod.hpp
---
