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
    \ namespace std;\n\n// start : \u59CB\u70B9\n// goal  : \u5230\u9054\u3057\u305F\
    \u7D42\u70B9 (goal \u304C\u7121\u3044/\u7740\u304B\u306A\u3044\u5834\u5408 Index{})\n\
    // dist  : start - goal \u9593\u306E\u8DDD\u96E2\n// reachable : goal \u306B\u7740\
    \u3044\u305F\u304B\uFF1F\u3092\u610F\u5473\u3059\u308B bool\n// path  : start\
    \ \u304B\u3089 goal \u3078\u306E\u30D1\u30B9 (reachable = false \u306E\u5834\u5408\
    \u306F\u7A7A)\n// mp    : mp[\u9802\u70B9] = (\u6700\u77ED\u8DDD\u96E2, 1 \u3064\
    \u524D\u306E\u9802\u70B9) \u3092\u7BA1\u7406\u3059\u308B map\ntemplate <typename\
    \ Index, typename Cost>\nstruct DijkstraResult {\n  Index start, goal;\n  Cost\
    \ dist;\n  bool reachable;\n  map<Index, pair<Cost, Index>> mp;\n  vector<Index>\
    \ path;\n\n  DijkstraResult(const Index& s, const Index& g, Cost d, bool r,\n\
    \                 const map<Index, pair<Cost, Index>>& m)\n      : start(s), goal(g),\
    \ dist(d), reachable(r), mp(m) {\n    if (reachable) {\n      for (Index c = g;\
    \ c != s; c = mp[c].second) path.push_back(c);\n      path.push_back(s);\n   \
    \   reverse(begin(path), end(path));\n    }\n  }\n};\n\n// \u5F15\u6570 f \u306F\
    \ (\u9802\u70B9 v, s-v \u9593\u306E\u8DDD\u96E2, \u95A2\u6570 g) \u3092\u5F15\u6570\
    \u306B\u53D6\u308B\n// f \u306E\u5185\u90E8\u3067 g(\u6B21\u306E\u9802\u70B9 w,\
    \ s-w \u9593\u306E\u8DDD\u96E2) \u3092\u547C\u3073\u51FA\u3057\u3066\u4F7F\u3046\
    \n//\n// \u8FD4\u308A\u5024\u306F DijkstraResult<Index, Cost> \u3092\u8FD4\u3059\
    \n//\n// goal \u306F lambda \u5F0F or \u5024 \u3092\u6E21\u305B\u308B, goal \u304C\
    \u8907\u6570\u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    \n// (\u59CB\u70B9\u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306F\u8D85\u9802\
    \u70B9\u3092\u4F7F\u3046\u3053\u3068\u306B\u3059\u308B)\ntemplate <typename Index,\
    \ typename Cost, bool has_goal = true>\nDijkstraResult<Index, Cost> dijkstra_abstruct(\n\
    \    const function<void(Index, Cost, function<void(Index, Cost)>)>& f,\n    const\
    \ Index& start, const function<bool(Index)>& is_goal) {\n  using P = pair<Cost,\
    \ Index>;\n\n  map<Index, P> d;\n  priority_queue<P, vector<P>, greater<P>> Q;\n\
    \  d[start] = P(0, Index{});\n  Q.emplace(0, start);\n\n  while (!Q.empty()) {\n\
    \    auto [u, t] = Q.top();\n    Q.pop();\n    if (d[t].first != u) continue;\n\
    \    if constexpr (has_goal) {\n      if (is_goal(t)) return {start, t, u, true,\
    \ d};\n    }\n    auto add = [&](Index nt, Cost nu) {\n      if (d.count(nt) ==\
    \ 0 or nu < d[nt].first) {\n        d[nt] = P(nu, t);\n        Q.emplace(nu, nt);\n\
    \      }\n    };\n    f(t, u, add);\n  }\n  return {start, Index{}, Cost{}, false,\
    \ d};\n}\n\n// \u5F15\u6570 f \u306F (\u9802\u70B9 v, s-v \u9593\u306E\u8DDD\u96E2\
    , \u95A2\u6570 g) \u3092\u5F15\u6570\u306B\u53D6\u308B\n// f \u306E\u5185\u90E8\
    \u3067 g(\u6B21\u306E\u9802\u70B9 w, s-w \u9593\u306E\u8DDD\u96E2) \u3092\u547C\
    \u3073\u51FA\u3057\u3066\u4F7F\u3046\n//\n// \u8FD4\u308A\u5024\u306F DijkstraResult<Index,\
    \ Cost> \u3092\u8FD4\u3059\n//\n// goal \u306F lambda \u5F0F or \u5024 \u3092\u6E21\
    \u305B\u308B, goal \u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\n// (\u59CB\u70B9\u304C\u8907\u6570\u3042\u308B\u5834\
    \u5408\u306F\u8D85\u9802\u70B9\u3092\u4F7F\u3046\u3053\u3068\u306B\u3059\u308B\
    )\ntemplate <typename Index, typename Cost, bool has_goal = true>\nDijkstraResult<Index,\
    \ Cost> dijkstra_abstruct(\n    const function<void(Index, Cost, function<void(Index,\
    \ Cost)>)>& f,\n    const Index& start, const Index& goal = Index{}) {\n  const\
    \ function<bool(Index)> is_goal = [&goal](Index i) -> bool {\n    return i ==\
    \ goal;\n  };\n  return dijkstra_abstruct<Index, Cost, has_goal>(f, start, is_goal);\n\
    }\n"
  code: "#pragma once\n\n#include <functional>\n#include <map>\n#include <queue>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n// start : \u59CB\
    \u70B9\n// goal  : \u5230\u9054\u3057\u305F\u7D42\u70B9 (goal \u304C\u7121\u3044\
    /\u7740\u304B\u306A\u3044\u5834\u5408 Index{})\n// dist  : start - goal \u9593\
    \u306E\u8DDD\u96E2\n// reachable : goal \u306B\u7740\u3044\u305F\u304B\uFF1F\u3092\
    \u610F\u5473\u3059\u308B bool\n// path  : start \u304B\u3089 goal \u3078\u306E\
    \u30D1\u30B9 (reachable = false \u306E\u5834\u5408\u306F\u7A7A)\n// mp    : mp[\u9802\
    \u70B9] = (\u6700\u77ED\u8DDD\u96E2, 1 \u3064\u524D\u306E\u9802\u70B9) \u3092\u7BA1\
    \u7406\u3059\u308B map\ntemplate <typename Index, typename Cost>\nstruct DijkstraResult\
    \ {\n  Index start, goal;\n  Cost dist;\n  bool reachable;\n  map<Index, pair<Cost,\
    \ Index>> mp;\n  vector<Index> path;\n\n  DijkstraResult(const Index& s, const\
    \ Index& g, Cost d, bool r,\n                 const map<Index, pair<Cost, Index>>&\
    \ m)\n      : start(s), goal(g), dist(d), reachable(r), mp(m) {\n    if (reachable)\
    \ {\n      for (Index c = g; c != s; c = mp[c].second) path.push_back(c);\n  \
    \    path.push_back(s);\n      reverse(begin(path), end(path));\n    }\n  }\n\
    };\n\n// \u5F15\u6570 f \u306F (\u9802\u70B9 v, s-v \u9593\u306E\u8DDD\u96E2,\
    \ \u95A2\u6570 g) \u3092\u5F15\u6570\u306B\u53D6\u308B\n// f \u306E\u5185\u90E8\
    \u3067 g(\u6B21\u306E\u9802\u70B9 w, s-w \u9593\u306E\u8DDD\u96E2) \u3092\u547C\
    \u3073\u51FA\u3057\u3066\u4F7F\u3046\n//\n// \u8FD4\u308A\u5024\u306F DijkstraResult<Index,\
    \ Cost> \u3092\u8FD4\u3059\n//\n// goal \u306F lambda \u5F0F or \u5024 \u3092\u6E21\
    \u305B\u308B, goal \u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\n// (\u59CB\u70B9\u304C\u8907\u6570\u3042\u308B\u5834\
    \u5408\u306F\u8D85\u9802\u70B9\u3092\u4F7F\u3046\u3053\u3068\u306B\u3059\u308B\
    )\ntemplate <typename Index, typename Cost, bool has_goal = true>\nDijkstraResult<Index,\
    \ Cost> dijkstra_abstruct(\n    const function<void(Index, Cost, function<void(Index,\
    \ Cost)>)>& f,\n    const Index& start, const function<bool(Index)>& is_goal)\
    \ {\n  using P = pair<Cost, Index>;\n\n  map<Index, P> d;\n  priority_queue<P,\
    \ vector<P>, greater<P>> Q;\n  d[start] = P(0, Index{});\n  Q.emplace(0, start);\n\
    \n  while (!Q.empty()) {\n    auto [u, t] = Q.top();\n    Q.pop();\n    if (d[t].first\
    \ != u) continue;\n    if constexpr (has_goal) {\n      if (is_goal(t)) return\
    \ {start, t, u, true, d};\n    }\n    auto add = [&](Index nt, Cost nu) {\n  \
    \    if (d.count(nt) == 0 or nu < d[nt].first) {\n        d[nt] = P(nu, t);\n\
    \        Q.emplace(nu, nt);\n      }\n    };\n    f(t, u, add);\n  }\n  return\
    \ {start, Index{}, Cost{}, false, d};\n}\n\n// \u5F15\u6570 f \u306F (\u9802\u70B9\
    \ v, s-v \u9593\u306E\u8DDD\u96E2, \u95A2\u6570 g) \u3092\u5F15\u6570\u306B\u53D6\
    \u308B\n// f \u306E\u5185\u90E8\u3067 g(\u6B21\u306E\u9802\u70B9 w, s-w \u9593\
    \u306E\u8DDD\u96E2) \u3092\u547C\u3073\u51FA\u3057\u3066\u4F7F\u3046\n//\n// \u8FD4\
    \u308A\u5024\u306F DijkstraResult<Index, Cost> \u3092\u8FD4\u3059\n//\n// goal\
    \ \u306F lambda \u5F0F or \u5024 \u3092\u6E21\u305B\u308B, goal \u304C\u8907\u6570\
    \u3042\u308B\u5834\u5408\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\n// (\u59CB\
    \u70B9\u304C\u8907\u6570\u3042\u308B\u5834\u5408\u306F\u8D85\u9802\u70B9\u3092\
    \u4F7F\u3046\u3053\u3068\u306B\u3059\u308B)\ntemplate <typename Index, typename\
    \ Cost, bool has_goal = true>\nDijkstraResult<Index, Cost> dijkstra_abstruct(\n\
    \    const function<void(Index, Cost, function<void(Index, Cost)>)>& f,\n    const\
    \ Index& start, const Index& goal = Index{}) {\n  const function<bool(Index)>\
    \ is_goal = [&goal](Index i) -> bool {\n    return i == goal;\n  };\n  return\
    \ dijkstra_abstruct<Index, Cost, has_goal>(f, start, is_goal);\n}"
  dependsOn: []
  isVerificationFile: false
  path: shortest-path/dijkstra-abstruct.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
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
