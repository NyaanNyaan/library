---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1323.test.cpp
    title: verify/verify-yuki/yuki-1323.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/bfs-restore.hpp\"\n\nvector<pair<int, int>>\
    \ bfs_restore(vector<vector<int>>& g, int st = 0) {\n  vector<pair<int, int>>\
    \ d(g.size(), make_pair(-1, -1));\n  d[st] = make_pair(0, -1);\n  queue<int> Q;\n\
    \  Q.push(st);\n  while (!Q.empty()) {\n    int cur = Q.front();\n    Q.pop();\n\
    \    int cd = d[cur].first;\n    for (auto&& dst : g[cur]) {\n      if (d[dst].first\
    \ == -1) {\n        d[dst].first = cd + 1;\n        d[dst].second = cur;\n   \
    \     Q.push(dst);\n      }\n    }\n  }\n  return d;\n}\n"
  code: "#pragma once\n\nvector<pair<int, int>> bfs_restore(vector<vector<int>>& g,\
    \ int st = 0) {\n  vector<pair<int, int>> d(g.size(), make_pair(-1, -1));\n  d[st]\
    \ = make_pair(0, -1);\n  queue<int> Q;\n  Q.push(st);\n  while (!Q.empty()) {\n\
    \    int cur = Q.front();\n    Q.pop();\n    int cd = d[cur].first;\n    for (auto&&\
    \ dst : g[cur]) {\n      if (d[dst].first == -1) {\n        d[dst].first = cd\
    \ + 1;\n        d[dst].second = cur;\n        Q.push(dst);\n      }\n    }\n \
    \ }\n  return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: shortest-path/bfs-restore.hpp
  requiredBy: []
  timestamp: '2020-12-21 18:22:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1323.test.cpp
documentation_of: shortest-path/bfs-restore.hpp
layout: document
redirect_from:
- /library/shortest-path/bfs-restore.hpp
- /library/shortest-path/bfs-restore.hpp.html
title: shortest-path/bfs-restore.hpp
---
