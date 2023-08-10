---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/string-search.hpp
    title: string/string-search.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix-array.hpp
    title: string/suffix-array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/sparse-table.test.cpp
    title: verify/verify-unit-test/sparse-table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/string-search.test.cpp
    title: verify/verify-unit-test/string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
    title: verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
    title: verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2231.test.cpp
    title: verify/verify-yuki/yuki-2231.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"data-structure/sparse-table.hpp\"\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct SparseTable {\n  inline static constexpr T INF = numeric_limits<T>::max()\
    \ / 2;\n  int N;\n  vector<vector<T> > table;\n  T f(T a, T b) { return min(a,\
    \ b); }\n  SparseTable() {}\n  SparseTable(const vector<T> &v) : N(v.size()) {\n\
    \    int b = 1;\n    while ((1 << b) <= N) ++b;\n    table.push_back(v);\n   \
    \ for (int i = 1; i < b; i++) {\n      table.push_back(vector<T>(N, INF));\n \
    \     for (int j = 0; j + (1 << i) <= N; j++) {\n        table[i][j] = f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n  // [l, r)\n\
    \  T query(int l, int r) {\n    assert(0 <= l and l <= r and r <= N);\n    if\
    \ (l == r) return INF;\n    int b = 31 - __builtin_clz(r - l);\n    return f(table[b][l],\
    \ table[b][r - (1 << b)]);\n  }\n};\n\n/**\n * @brief Sparse Table\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    using namespace std;\n\ntemplate <typename T>\nstruct SparseTable {\n  inline\
    \ static constexpr T INF = numeric_limits<T>::max() / 2;\n  int N;\n  vector<vector<T>\
    \ > table;\n  T f(T a, T b) { return min(a, b); }\n  SparseTable() {}\n  SparseTable(const\
    \ vector<T> &v) : N(v.size()) {\n    int b = 1;\n    while ((1 << b) <= N) ++b;\n\
    \    table.push_back(v);\n    for (int i = 1; i < b; i++) {\n      table.push_back(vector<T>(N,\
    \ INF));\n      for (int j = 0; j + (1 << i) <= N; j++) {\n        table[i][j]\
    \ = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\
    \  // [l, r)\n  T query(int l, int r) {\n    assert(0 <= l and l <= r and r <=\
    \ N);\n    if (l == r) return INF;\n    int b = 31 - __builtin_clz(r - l);\n \
    \   return f(table[b][l], table[b][r - (1 << b)]);\n  }\n};\n\n/**\n * @brief\
    \ Sparse Table\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - string/suffix-array.hpp
  - string/string-search.hpp
  timestamp: '2023-01-31 00:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-number-of-substrings.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-suffixarray.test.cpp
  - verify/verify-yosupo-string/yosupo-suffix-array.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp
  - verify/verify-yuki/yuki-2231.test.cpp
  - verify/verify-unit-test/sparse-table.test.cpp
  - verify/verify-unit-test/string-search.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: Sparse Table
---
