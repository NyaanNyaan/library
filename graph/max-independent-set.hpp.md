---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
    title: verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/max-independent-set.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <int m>\nvector<int> max_independent_set(const\
    \ vector<vector<int>> &g) {\n  constexpr int M = (m + 63) / 64 * 64;\n  int N\
    \ = g.size();\n  vector<bitset<M>> bs(N);\n  for (int i = 0; i < N; i++)\n   \
    \ for (auto &j : g[i]) bs[i][j] = bs[j][i] = 1;\n  bitset<M> res, cur, ignore;\n\
    \  auto dfs = [&](auto rec, int i) -> void {\n    if (i == N) {\n      if (cur.count()\
    \ > res.count()) res = cur;\n      return;\n    }\n    if ((bs[i] & cur).any()\
    \ || (bs[i] & ~ignore).count() >= 2) {\n      ignore[i] = 1;\n      rec(rec, i\
    \ + 1);\n      ignore[i] = 0;\n    }\n    if ((bs[i] & cur).none()) {\n      cur[i]\
    \ = 1;\n      rec(rec, i + 1);\n      cur[i] = 0;\n    }\n  };\n  dfs(dfs, 0);\n\
    \  vector<int> res2;\n  for (int i = 0; i < N; i++)\n    if (res[i]) res2.push_back(i);\n\
    \  return res2;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <int m>\nvector<int> max_independent_set(const vector<vector<int>> &g) {\n \
    \ constexpr int M = (m + 63) / 64 * 64;\n  int N = g.size();\n  vector<bitset<M>>\
    \ bs(N);\n  for (int i = 0; i < N; i++)\n    for (auto &j : g[i]) bs[i][j] = bs[j][i]\
    \ = 1;\n  bitset<M> res, cur, ignore;\n  auto dfs = [&](auto rec, int i) -> void\
    \ {\n    if (i == N) {\n      if (cur.count() > res.count()) res = cur;\n    \
    \  return;\n    }\n    if ((bs[i] & cur).any() || (bs[i] & ~ignore).count() >=\
    \ 2) {\n      ignore[i] = 1;\n      rec(rec, i + 1);\n      ignore[i] = 0;\n \
    \   }\n    if ((bs[i] & cur).none()) {\n      cur[i] = 1;\n      rec(rec, i +\
    \ 1);\n      cur[i] = 0;\n    }\n  };\n  dfs(dfs, 0);\n  vector<int> res2;\n \
    \ for (int i = 0; i < N; i++)\n    if (res[i]) res2.push_back(i);\n  return res2;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/max-independent-set.hpp
  requiredBy: []
  timestamp: '2020-09-01 01:49:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
documentation_of: graph/max-independent-set.hpp
layout: document
redirect_from:
- /library/graph/max-independent-set.hpp
- /library/graph/max-independent-set.hpp.html
title: graph/max-independent-set.hpp
---
