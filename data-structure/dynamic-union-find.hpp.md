---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-union-find.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct DynamicUnionFind {\n  unordered_map<int, int> m;\n\
    \  DynamicUnionFind() {}\n\n  int data(int k) {\n    auto itk = m.find(k);\n \
    \   return itk == m.end() ? m[k] = -1 : itk->second;\n  }\n  int find(int k) {\n\
    \    int datk = data(k);\n    return datk < 0 ? k : m[k] = find(datk);\n  }\n\n\
    \  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return false;\n\
    \    auto itx = m.find(x), ity = m.find(y);\n    if (itx->second > ity->second)\
    \ {\n      ity->second += itx->second;\n      itx->second = y;\n    } else {\n\
    \      itx->second += ity->second;\n      ity->second = x;\n    }\n    return\
    \ true;\n  }\n\n  int size(int k) { return -data(find(k)); }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct DynamicUnionFind\
    \ {\n  unordered_map<int, int> m;\n  DynamicUnionFind() {}\n\n  int data(int k)\
    \ {\n    auto itk = m.find(k);\n    return itk == m.end() ? m[k] = -1 : itk->second;\n\
    \  }\n  int find(int k) {\n    int datk = data(k);\n    return datk < 0 ? k :\
    \ m[k] = find(datk);\n  }\n\n  int unite(int x, int y) {\n    if ((x = find(x))\
    \ == (y = find(y))) return false;\n    auto itx = m.find(x), ity = m.find(y);\n\
    \    if (itx->second > ity->second) {\n      ity->second += itx->second;\n   \
    \   itx->second = y;\n    } else {\n      itx->second += ity->second;\n      ity->second\
    \ = x;\n    }\n    return true;\n  }\n\n  int size(int k) { return -data(find(k));\
    \ }\n\n  int same(int x, int y) { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic-union-find.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
documentation_of: data-structure/dynamic-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-union-find.hpp
- /library/data-structure/dynamic-union-find.hpp.html
title: data-structure/dynamic-union-find.hpp
---
