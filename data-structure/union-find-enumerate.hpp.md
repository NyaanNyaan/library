---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/parallel-union-find.hpp
    title: data-structure/parallel-union-find.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/parallel-union-find.test.cpp
    title: verify/verify-unit-test/parallel-union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/union-find-enumerate.hpp\"\n\n#include <vector>\n\
    using namespace std;\n\nstruct UnionFindEnumerate {\n  vector<int> data, nxt;\n\
    \  UnionFindEnumerate(int N) : data(N, -1), nxt(N) {\n    for (int i = 0; i <\
    \ N; i++) nxt[i] = i;\n  }\n\n  int find(int k) { return data[k] < 0 ? k : data[k]\
    \ = find(data[k]); }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) ==\
    \ (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  // f(x, y) : x \u306B y \u3092\u30DE\u30FC\u30B8\n  template <typename\
    \ F>\n  int unite(int x, int y, const F &f) {\n    if ((x = find(x)) == (y = find(y)))\
    \ return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    f(x, y);\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  int size(int k) { return -data[find(k)]; }\n\n  int same(int x, int\
    \ y) { return find(x) == find(y); }\n\n  vector<int> enumerate(int i) {\n    vector<int>\
    \ res{i};\n    for (int j = nxt[i]; j != i; j = nxt[j]) res.push_back(j);\n  \
    \  return res;\n  }\n};\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\nstruct UnionFindEnumerate\
    \ {\n  vector<int> data, nxt;\n  UnionFindEnumerate(int N) : data(N, -1), nxt(N)\
    \ {\n    for (int i = 0; i < N; i++) nxt[i] = i;\n  }\n\n  int find(int k) { return\
    \ data[k] < 0 ? k : data[k] = find(data[k]); }\n\n  int unite(int x, int y) {\n\
    \    if ((x = find(x)) == (y = find(y))) return false;\n    if (data[x] > data[y])\
    \ swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    swap(nxt[x], nxt[y]);\n\
    \    return true;\n  }\n\n  // f(x, y) : x \u306B y \u3092\u30DE\u30FC\u30B8\n\
    \  template <typename F>\n  int unite(int x, int y, const F &f) {\n    if ((x\
    \ = find(x)) == (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x,\
    \ y);\n    data[x] += data[y];\n    data[y] = x;\n    f(x, y);\n    swap(nxt[x],\
    \ nxt[y]);\n    return true;\n  }\n\n  int size(int k) { return -data[find(k)];\
    \ }\n\n  int same(int x, int y) { return find(x) == find(y); }\n\n  vector<int>\
    \ enumerate(int i) {\n    vector<int> res{i};\n    for (int j = nxt[i]; j != i;\
    \ j = nxt[j]) res.push_back(j);\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find-enumerate.hpp
  requiredBy:
  - data-structure/parallel-union-find.hpp
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/parallel-union-find.test.cpp
documentation_of: data-structure/union-find-enumerate.hpp
layout: document
redirect_from:
- /library/data-structure/union-find-enumerate.hpp
- /library/data-structure/union-find-enumerate.hpp.html
title: data-structure/union-find-enumerate.hpp
---
