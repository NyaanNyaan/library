---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1778.test.cpp
    title: verify/verify-yuki/yuki-1778.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/inclusion-tree.hpp\"\n\n// [0, N) \u306E\u5305\u542B\
    \u95A2\u4FC2\u306B\u95A2\u3059\u308B\u6728\n//\n// \u5165\u529B : \u533A\u9593\
    [L, R) \u306E\u7D44 (\u5305\u542B OK, \u4EA4\u5DEE NG)\n// \u51FA\u529B : g :\
    \ \u30B0\u30E9\u30D5\n//   AB : \u7834\u58CA\u7684, (first, -second) \u306E\u6607\
    \u9806\u3067\u30BD\u30FC\u30C8\u3055\u308C\u308B\n//        & AB[0] \u306B\u8D85\
    \u9802\u70B9 (-1, N + 1) \u304C\u5165\u308B\ntemplate <typename Pair>\nvector<vector<int>>\
    \ inclusion_tree(vector<Pair>& AB, int N) {\n  int M = AB.size();\n  AB.emplace_back(-1,\
    \ N + 1);\n  sort(begin(AB), end(AB), [](auto l, auto r) {\n    return l.first\
    \ == r.first ? l.second > r.second : l.first < r.first;\n  });\n  vector<vector<int>>\
    \ g(M + 1);\n  vector<int> par(M + 1, -1);\n  for (int i = 1; i <= M; i++) {\n\
    \    auto [a, b] = AB[i];\n    int p = i - 1;\n    while (p <= M) {\n      trc(i,\
    \ p);\n      auto [v, pb] = AB[p];\n      assert(v <= a);\n      if (b <= pb)\
    \ break;\n      assert(!(a < pb && pb < b));\n      p = par[p];\n    }\n    g[p].push_back(i);\n\
    \    par[i] = p;\n  }\n  return g;\n}\n"
  code: "#pragma once\n\n// [0, N) \u306E\u5305\u542B\u95A2\u4FC2\u306B\u95A2\u3059\
    \u308B\u6728\n//\n// \u5165\u529B : \u533A\u9593[L, R) \u306E\u7D44 (\u5305\u542B\
    \ OK, \u4EA4\u5DEE NG)\n// \u51FA\u529B : g : \u30B0\u30E9\u30D5\n//   AB : \u7834\
    \u58CA\u7684, (first, -second) \u306E\u6607\u9806\u3067\u30BD\u30FC\u30C8\u3055\
    \u308C\u308B\n//        & AB[0] \u306B\u8D85\u9802\u70B9 (-1, N + 1) \u304C\u5165\
    \u308B\ntemplate <typename Pair>\nvector<vector<int>> inclusion_tree(vector<Pair>&\
    \ AB, int N) {\n  int M = AB.size();\n  AB.emplace_back(-1, N + 1);\n  sort(begin(AB),\
    \ end(AB), [](auto l, auto r) {\n    return l.first == r.first ? l.second > r.second\
    \ : l.first < r.first;\n  });\n  vector<vector<int>> g(M + 1);\n  vector<int>\
    \ par(M + 1, -1);\n  for (int i = 1; i <= M; i++) {\n    auto [a, b] = AB[i];\n\
    \    int p = i - 1;\n    while (p <= M) {\n      trc(i, p);\n      auto [v, pb]\
    \ = AB[p];\n      assert(v <= a);\n      if (b <= pb) break;\n      assert(!(a\
    \ < pb && pb < b));\n      p = par[p];\n    }\n    g[p].push_back(i);\n    par[i]\
    \ = p;\n  }\n  return g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/inclusion-tree.hpp
  requiredBy: []
  timestamp: '2022-01-13 01:09:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1778.test.cpp
documentation_of: tree/inclusion-tree.hpp
layout: document
redirect_from:
- /library/tree/inclusion-tree.hpp
- /library/tree/inclusion-tree.hpp.html
title: tree/inclusion-tree.hpp
---
