---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-1-b.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-1-b.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/union-find-with-potential.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n// Potential\u3064\u304DUnion-Find\n\
    template <class T>\nstruct UnionFindWithPotential {\n  vector<int> par, rank;\n\
    \  // pot...\u6839\u306B\u5BFE\u3059\u308B\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \n  vector<T> pot;\n  T UNIT;\n\n  UnionFindWithPotential(int N, T UNIT_ = 0)\n\
    \      : par(N), rank(N), pot(N), UNIT(UNIT_) {\n    for (int i = 0; i < N; i++)\
    \ par[i] = i, rank[i] = 0, pot[i] = UNIT;\n  }\n\n  // x\u306E\u6839\u3092\u8FD4\
    \u3059\u95A2\u6570\n  int root(int x) {\n    if (par[x] == x) return x;\n    int\
    \ r = root(par[x]);\n    pot[x] += pot[par[x]];\n    return par[x] = r;\n  }\n\
    \n  // \u6839\u306B\u5BFE\u3059\u308B\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\
    \u8FD4\u3059\u95A2\u6570\n  T potential(int x) {\n    root(x);\n    return pot[x];\n\
    \  }\n\n  // \u6839\u304C\u540C\u3058\u304B\u3092\u5224\u5B9A\u3059\u308B\u95A2\
    \u6570\n  bool same(int x, int y) { return root(x) == root(y); }\n\n  // x\u306E\
    y\u306B\u5BFE\u3059\u308Bpotential\u3092\u8FD4\u3059\u95A2\u6570\n  T diff(int\
    \ x, int y) { return potential(x) - potential(y); }\n\n  // x\u306Ey\u306B\u5BFE\
    \u3059\u308Bpotential\u304Cp\u3067\u3042\u308B (x\u306Fy\u3088\u308A\u3082p\u5927\
    \u304D\u3044)\n  // false\u306E\u6642\u3001\u65E2\u5B58\u306E\u60C5\u5831\u3068\
    \u77DB\u76FE\n  bool merge(int x, int y, T p) {\n    p += potential(y) - potential(x);\n\
    \    x = root(x), y = root(y);\n    if (x == y) {\n      return p == UNIT;\n \
    \   }\n    if (rank[x] > rank[y]) swap(x, y), p = -p;\n    if (rank[x] == rank[y])\
    \ ++rank[x];\n    par[x] = y, pot[x] = p;\n    return true;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Potential\u3064\
    \u304DUnion-Find\ntemplate <class T>\nstruct UnionFindWithPotential {\n  vector<int>\
    \ par, rank;\n  // pot...\u6839\u306B\u5BFE\u3059\u308B\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\n  vector<T> pot;\n  T UNIT;\n\n  UnionFindWithPotential(int N, T\
    \ UNIT_ = 0)\n      : par(N), rank(N), pot(N), UNIT(UNIT_) {\n    for (int i =\
    \ 0; i < N; i++) par[i] = i, rank[i] = 0, pot[i] = UNIT;\n  }\n\n  // x\u306E\u6839\
    \u3092\u8FD4\u3059\u95A2\u6570\n  int root(int x) {\n    if (par[x] == x) return\
    \ x;\n    int r = root(par[x]);\n    pot[x] += pot[par[x]];\n    return par[x]\
    \ = r;\n  }\n\n  // \u6839\u306B\u5BFE\u3059\u308B\u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u3092\u8FD4\u3059\u95A2\u6570\n  T potential(int x) {\n    root(x);\n \
    \   return pot[x];\n  }\n\n  // \u6839\u304C\u540C\u3058\u304B\u3092\u5224\u5B9A\
    \u3059\u308B\u95A2\u6570\n  bool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n  // x\u306Ey\u306B\u5BFE\u3059\u308Bpotential\u3092\u8FD4\u3059\u95A2\u6570\
    \n  T diff(int x, int y) { return potential(x) - potential(y); }\n\n  // x\u306E\
    y\u306B\u5BFE\u3059\u308Bpotential\u304Cp\u3067\u3042\u308B (x\u306Fy\u3088\u308A\
    \u3082p\u5927\u304D\u3044)\n  // false\u306E\u6642\u3001\u65E2\u5B58\u306E\u60C5\
    \u5831\u3068\u77DB\u76FE\n  bool merge(int x, int y, T p) {\n    p += potential(y)\
    \ - potential(x);\n    x = root(x), y = root(y);\n    if (x == y) {\n      return\
    \ p == UNIT;\n    }\n    if (rank[x] > rank[y]) swap(x, y), p = -p;\n    if (rank[x]\
    \ == rank[y]) ++rank[x];\n    par[x] = y, pot[x] = p;\n    return true;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find-with-potential.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-1-b.test.cpp
documentation_of: data-structure/union-find-with-potential.hpp
layout: document
redirect_from:
- /library/data-structure/union-find-with-potential.hpp
- /library/data-structure/union-find-with-potential.hpp.html
title: data-structure/union-find-with-potential.hpp
---
