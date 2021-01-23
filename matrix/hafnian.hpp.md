---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-hafnian-of-matrix.test.cpp
    title: verify/verify-yosupo-math/yosupo-hafnian-of-matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/hafnian.hpp\"\n\ntemplate <typename mint>\nmint Hafnian(vector<vector<mint>>\
    \ &mat) {\n  using vm = vector<mint>;\n  using vvm = vector<vector<mint>>;\n\n\
    \  int n = mat.size();\n  assert(n % 2 == 0);\n  int h = n / 2 + 1;\n\n  auto\
    \ ad = [&h](vm &x, const vm &a, const vm &b) -> void {\n    for (int i = 0; i\
    \ < h - 1; i++)\n      for (int j = 0; j < h - 1 - i; j++) x[i + j + 1] += a[i]\
    \ * b[j];\n  };\n  auto solve = [&](auto rc, const vector<vvm> &v) -> vm {\n \
    \   vm ans(h);\n    if (sz(v) == 0) {\n      ans[0] = 1;\n      return ans;\n\
    \    }\n    int m = v.size() - 2;\n    auto V = v;\n    V.resize(m);\n    vm zero\
    \ = rc(rc, V);\n    for (int i = 0; i < m; i++)\n      for (int j = 0; j < i;\
    \ j++) {\n        ad(V[i][j], v[m][i], v[m + 1][j]);\n        ad(V[i][j], v[m\
    \ + 1][i], v[m][j]);\n      }\n    vm one = rc(rc, V);\n    for (int i = 0; i\
    \ < h; i++) ans[i] += one[i] - zero[i];\n    ad(ans, one, v[m + 1][m]);\n    return\
    \ ans;\n  };\n\n  vector<vvm> v(n);\n  for (int i = 0; i < n; i++) {\n    v[i].resize(i,\
    \ vm(h, 0));\n    for (int j = 0; j < i; j++) v[i][j][0] = mat[i][j];\n  }\n \
    \ return solve(solve, v).back();\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nmint Hafnian(vector<vector<mint>>\
    \ &mat) {\n  using vm = vector<mint>;\n  using vvm = vector<vector<mint>>;\n\n\
    \  int n = mat.size();\n  assert(n % 2 == 0);\n  int h = n / 2 + 1;\n\n  auto\
    \ ad = [&h](vm &x, const vm &a, const vm &b) -> void {\n    for (int i = 0; i\
    \ < h - 1; i++)\n      for (int j = 0; j < h - 1 - i; j++) x[i + j + 1] += a[i]\
    \ * b[j];\n  };\n  auto solve = [&](auto rc, const vector<vvm> &v) -> vm {\n \
    \   vm ans(h);\n    if (sz(v) == 0) {\n      ans[0] = 1;\n      return ans;\n\
    \    }\n    int m = v.size() - 2;\n    auto V = v;\n    V.resize(m);\n    vm zero\
    \ = rc(rc, V);\n    for (int i = 0; i < m; i++)\n      for (int j = 0; j < i;\
    \ j++) {\n        ad(V[i][j], v[m][i], v[m + 1][j]);\n        ad(V[i][j], v[m\
    \ + 1][i], v[m][j]);\n      }\n    vm one = rc(rc, V);\n    for (int i = 0; i\
    \ < h; i++) ans[i] += one[i] - zero[i];\n    ad(ans, one, v[m + 1][m]);\n    return\
    \ ans;\n  };\n\n  vector<vvm> v(n);\n  for (int i = 0; i < n; i++) {\n    v[i].resize(i,\
    \ vm(h, 0));\n    for (int j = 0; j < i; j++) v[i][j][0] = mat[i][j];\n  }\n \
    \ return solve(solve, v).back();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/hafnian.hpp
  requiredBy: []
  timestamp: '2021-01-23 20:36:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-hafnian-of-matrix.test.cpp
documentation_of: matrix/hafnian.hpp
layout: document
redirect_from:
- /library/matrix/hafnian.hpp
- /library/matrix/hafnian.hpp.html
title: matrix/hafnian.hpp
---
