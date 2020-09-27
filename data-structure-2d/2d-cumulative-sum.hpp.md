---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure-2d/2d-cumulative-sum.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Don't Forget to call build() !!!!!\ntemplate <class\
    \ T>\nstruct CumulativeSum2D {\n  vector<vector<T> > data;\n\n  CumulativeSum2D(int\
    \ H, int W) : data(H + 3, vector<int>(W + 3, 0)) {}\n\n  void add(int i, int j,\
    \ T z) {\n    ++i, ++j;\n    if (i >= (int)data.size() || j >= (int)data[0].size())\
    \ return;\n    data[i][j] += z;\n  }\n\n  // add [ [i1,j1], [i2,j2] )\n  void\
    \ imos(int i1, int j1, int i2, int j2, T z) {\n    add(i1, j1, 1);\n    add(i1,\
    \ j2, -1);\n    add(i2, j1, -1);\n    add(i2, j2, 1);\n  }\n\n  void build() {\n\
    \    for (int i = 1; i < (int)data.size(); i++) {\n      for (int j = 1; j < (int)data[i].size();\
    \ j++) {\n        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j\
    \ - 1];\n      }\n    }\n  }\n\n  T query(int i1, int j1, int i2, int j2) {\n\
    \    return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n  }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Don't\
    \ Forget to call build() !!!!!\ntemplate <class T>\nstruct CumulativeSum2D {\n\
    \  vector<vector<T> > data;\n\n  CumulativeSum2D(int H, int W) : data(H + 3, vector<int>(W\
    \ + 3, 0)) {}\n\n  void add(int i, int j, T z) {\n    ++i, ++j;\n    if (i >=\
    \ (int)data.size() || j >= (int)data[0].size()) return;\n    data[i][j] += z;\n\
    \  }\n\n  // add [ [i1,j1], [i2,j2] )\n  void imos(int i1, int j1, int i2, int\
    \ j2, T z) {\n    add(i1, j1, 1);\n    add(i1, j2, -1);\n    add(i2, j1, -1);\n\
    \    add(i2, j2, 1);\n  }\n\n  void build() {\n    for (int i = 1; i < (int)data.size();\
    \ i++) {\n      for (int j = 1; j < (int)data[i].size(); j++) {\n        data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n      }\n    }\n \
    \ }\n\n  T query(int i1, int j1, int i2, int j2) {\n    return (data[i2][j2] -\
    \ data[i1][j2] - data[i2][j1] + data[i1][j1]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/2d-cumulative-sum.hpp
  requiredBy: []
  timestamp: '2020-09-27 16:45:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
documentation_of: data-structure-2d/2d-cumulative-sum.hpp
layout: document
redirect_from:
- /library/data-structure-2d/2d-cumulative-sum.hpp
- /library/data-structure-2d/2d-cumulative-sum.hpp.html
title: data-structure-2d/2d-cumulative-sum.hpp
---
