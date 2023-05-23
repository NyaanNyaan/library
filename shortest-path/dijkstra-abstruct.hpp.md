---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra-abstruct.hpp\"\n\n#include <functional>\n\
    #include <map>\n#include <queue>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\n// (start \u304B\u3089\u306E\u8DDD\u96E2, 1 \u500B\u524D\u306E\
    \u9802\u70B9) \u3092\u683C\u7D0D\u3059\u308B map \u3092\u8FD4\u3059\n// \u305F\
    \u3060\u3057\u59CB\u70B9\u306F d[start] = {0, Index{}}\ntemplate <typename Index,\
    \ typename Cost, bool has_goal = true>\nmap<Index, pair<Cost, Index>> dijkstra_abstruct(\n\
    \    const function<void(Index, Cost, function<void(Index, Cost)>)>& f,\n    const\
    \ Index& start, const Index& goal) {\n  using P = pair<Cost, Index>;\n\n  map<Index,\
    \ P> d;\n  priority_queue<P, vector<P>, greater<P>> Q;\n  d[start] = P(0, Index{});\n\
    \  Q.emplace(0, start);\n\n  while (!Q.empty()) {\n    auto [u, t] = Q.top();\n\
    \    Q.pop();\n    if (d[t].first != u) continue;\n    if (has_goal && t == goal)\
    \ return d;\n    auto add = [&](Index nt, Cost nu) {\n      if (d.count(nt) ==\
    \ 0 or nu < d[nt].first) {\n        d[nt] = P(nu, t);\n        Q.emplace(nu, nt);\n\
    \      }\n    };\n    f(t, u, add);\n  }\n  return d;\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <map>\n#include <queue>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n// (start \u304B\
    \u3089\u306E\u8DDD\u96E2, 1 \u500B\u524D\u306E\u9802\u70B9) \u3092\u683C\u7D0D\
    \u3059\u308B map \u3092\u8FD4\u3059\n// \u305F\u3060\u3057\u59CB\u70B9\u306F d[start]\
    \ = {0, Index{}}\ntemplate <typename Index, typename Cost, bool has_goal = true>\n\
    map<Index, pair<Cost, Index>> dijkstra_abstruct(\n    const function<void(Index,\
    \ Cost, function<void(Index, Cost)>)>& f,\n    const Index& start, const Index&\
    \ goal) {\n  using P = pair<Cost, Index>;\n\n  map<Index, P> d;\n  priority_queue<P,\
    \ vector<P>, greater<P>> Q;\n  d[start] = P(0, Index{});\n  Q.emplace(0, start);\n\
    \n  while (!Q.empty()) {\n    auto [u, t] = Q.top();\n    Q.pop();\n    if (d[t].first\
    \ != u) continue;\n    if (has_goal && t == goal) return d;\n    auto add = [&](Index\
    \ nt, Cost nu) {\n      if (d.count(nt) == 0 or nu < d[nt].first) {\n        d[nt]\
    \ = P(nu, t);\n        Q.emplace(nu, nt);\n      }\n    };\n    f(t, u, add);\n\
    \  }\n  return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: shortest-path/dijkstra-abstruct.hpp
  requiredBy: []
  timestamp: '2023-05-23 20:26:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
documentation_of: shortest-path/dijkstra-abstruct.hpp
layout: document
redirect_from:
- /library/shortest-path/dijkstra-abstruct.hpp
- /library/shortest-path/dijkstra-abstruct.hpp.html
title: shortest-path/dijkstra-abstruct.hpp
---
