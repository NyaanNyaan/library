---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
    title: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
    title: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse-table.hpp\"\n\ntemplate <typename\
    \ T>\nstruct SparseTable {\n  vector<vector<T> > table;\n  vector<int> log_table;\n\
    \n  inline T f(T a, T b) { return min(a, b); }\n\n  SparseTable(const vector<T>\
    \ &v) {\n    int b = 0;\n    while ((1 << b) <= (int)v.size()) ++b;\n    table.assign(b,\
    \ vector<T>(1 << b));\n    for (int i = 0; i < (int)v.size(); i++) {\n      table[0][i]\
    \ = v[i];\n    }\n    for (int i = 1; i < b; i++) {\n      for (int j = 0; j +\
    \ (1 << i) <= (1 << b); j++) {\n        table[i][j] = f(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n      }\n    }\n    log_table.resize(v.size() +\
    \ 1);\n    for (int i = 2; i < (int)log_table.size(); i++) {\n      log_table[i]\
    \ = log_table[i >> 1] + 1;\n    }\n  }\n\n  // [l, r)\n  inline T query(int l,\
    \ int r) {\n    int b = log_table[r - l];\n    return f(table[b][l], table[b][r\
    \ - (1 << b)]);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SparseTable {\n  vector<vector<T>\
    \ > table;\n  vector<int> log_table;\n\n  inline T f(T a, T b) { return min(a,\
    \ b); }\n\n  SparseTable(const vector<T> &v) {\n    int b = 0;\n    while ((1\
    \ << b) <= (int)v.size()) ++b;\n    table.assign(b, vector<T>(1 << b));\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n      table[0][i] = v[i];\n    }\n  \
    \  for (int i = 1; i < b; i++) {\n      for (int j = 0; j + (1 << i) <= (1 <<\
    \ b); j++) {\n        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 <<\
    \ (i - 1))]);\n      }\n    }\n    log_table.resize(v.size() + 1);\n    for (int\
    \ i = 2; i < (int)log_table.size(); i++) {\n      log_table[i] = log_table[i >>\
    \ 1] + 1;\n    }\n  }\n\n  // [l, r)\n  inline T query(int l, int r) {\n    int\
    \ b = log_table[r - l];\n    return f(table[b][l], table[b][r - (1 << b)]);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - string/suffix-array.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  - verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
