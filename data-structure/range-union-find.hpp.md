---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1170.test.cpp
    title: verify/verify-yuki/yuki-1170.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range-union-find.hpp\"\n\nstruct RangeUnionFind\
    \ {\n  vector<int> data, left, right;\n  RangeUnionFind(int N) : data(N, -1) {\n\
    \    left.resize(N);\n    right.resize(N);\n    iota(begin(left), end(left), 0);\n\
    \    iota(begin(right), end(right), 1);\n  }\n\n  int find(int k) { return data[k]\
    \ < 0 ? k : data[k] = find(data[k]); }\n\n  int unite(int x, int y) {\n    if\
    \ ((x = find(x)) == (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x,\
    \ y);\n    data[x] += data[y];\n    data[y] = x;\n    left[x] = min(left[x], left[y]);\n\
    \    right[x] = max(right[x], right[y]);\n    return true;\n  }\n\n  // unite\
    \ [l, r)\n  void range_unite(int l, int r) {\n    if ((l = max(l, 0)) >= (r =\
    \ min(r, (int)data.size()))) return;\n    int m;\n    while ((m = right[find(l)])\
    \ < r) {\n      assert(left[find(m)] == m);\n      unite(l, m);\n    }\n  }\n\n\
    \  int size(int k) { return -data[find(k)]; }\n\n  int same(int x, int y) { return\
    \ find(x) == find(y); }\n};\n"
  code: "#pragma once\n\nstruct RangeUnionFind {\n  vector<int> data, left, right;\n\
    \  RangeUnionFind(int N) : data(N, -1) {\n    left.resize(N);\n    right.resize(N);\n\
    \    iota(begin(left), end(left), 0);\n    iota(begin(right), end(right), 1);\n\
    \  }\n\n  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]);\
    \ }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return\
    \ false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n  \
    \  data[y] = x;\n    left[x] = min(left[x], left[y]);\n    right[x] = max(right[x],\
    \ right[y]);\n    return true;\n  }\n\n  // unite [l, r)\n  void range_unite(int\
    \ l, int r) {\n    if ((l = max(l, 0)) >= (r = min(r, (int)data.size()))) return;\n\
    \    int m;\n    while ((m = right[find(l)]) < r) {\n      assert(left[find(m)]\
    \ == m);\n      unite(l, m);\n    }\n  }\n\n  int size(int k) { return -data[find(k)];\
    \ }\n\n  int same(int x, int y) { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range-union-find.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1170.test.cpp
documentation_of: data-structure/range-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/range-union-find.hpp
- /library/data-structure/range-union-find.hpp.html
title: data-structure/range-union-find.hpp
---
