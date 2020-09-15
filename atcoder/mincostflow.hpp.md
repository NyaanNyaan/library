---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"atcoder/mincostflow.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\ntemplate <class Cap, class Cost>\nstruct mcf_graph {\n public:\n\
    \  mcf_graph() {}\n  mcf_graph(int n) : _n(n), g(n) {}\n\n  int add_edge(int from,\
    \ int to, Cap cap, Cost cost) {\n    assert(0 <= from && from < _n);\n    assert(0\
    \ <= to && to < _n);\n    int m = int(pos.size());\n    pos.push_back({from, int(g[from].size())});\n\
    \    g[from].push_back(_edge{to, int(g[to].size()), cap, cost});\n    g[to].push_back(_edge{from,\
    \ int(g[from].size()) - 1, 0, -cost});\n    return m;\n  }\n\n  struct edge {\n\
    \    int from, to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int\
    \ i) {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n    auto _e\
    \ = g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n    return\
    \ edge{\n        pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,\n  \
    \  };\n  }\n  std::vector<edge> edges() {\n    int m = int(pos.size());\n    std::vector<edge>\
    \ result(m);\n    for (int i = 0; i < m; i++) {\n      result[i] = get_edge(i);\n\
    \    }\n    return result;\n  }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n\
    \    return flow(s, t, std::numeric_limits<Cap>::max());\n  }\n  std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n    return slope(s, t, flow_limit).back();\n\
    \  }\n  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n    return slope(s,\
    \ t, std::numeric_limits<Cap>::max());\n  }\n  std::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n    assert(0\
    \ <= t && t < _n);\n    assert(s != t);\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.from] - dual[e.to]) >= 0 for all edge\n    std::vector<Cost> dual(_n,\
    \ 0), dist(_n);\n    std::vector<int> pv(_n), pe(_n);\n    std::vector<bool> vis(_n);\n\
    \    auto dual_ref = [&]() {\n      std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());\n\
    \      std::fill(pv.begin(), pv.end(), -1);\n      std::fill(pe.begin(), pe.end(),\
    \ -1);\n      std::fill(vis.begin(), vis.end(), false);\n      struct Q {\n  \
    \      Cost key;\n        int to;\n        bool operator<(Q r) const { return\
    \ key > r.key; }\n      };\n      std::priority_queue<Q> que;\n      dist[s] =\
    \ 0;\n      que.push(Q{0, s});\n      while (!que.empty()) {\n        int v =\
    \ que.top().to;\n        que.pop();\n        if (vis[v]) continue;\n        vis[v]\
    \ = true;\n        if (v == t) break;\n        // dist[v] = shortest(s, v) + dual[s]\
    \ - dual[v]\n        // dist[v] >= 0 (all reduced cost are positive)\n       \
    \ // dist[v] <= (n-1)C\n        for (int i = 0; i < int(g[v].size()); i++) {\n\
    \          auto e = g[v][i];\n          if (vis[e.to] || !e.cap) continue;\n \
    \         // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual[e.to] + dual[v];\n          if\
    \ (dist[e.to] - dist[v] > cost) {\n            dist[e.to] = dist[v] + cost;\n\
    \            pv[e.to] = v;\n            pe[e.to] = i;\n            que.push(Q{dist[e.to],\
    \ e.to});\n          }\n        }\n      }\n      if (!vis[t]) {\n        return\
    \ false;\n      }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s, t) +\n        //         dual[t] + shortest(s,\
    \ v) = shortest(s, v) - shortest(s, t) >=\n        //         0 - (n-1)C\n   \
    \     dual[v] -= dist[t] - dist[v];\n      }\n      return true;\n    };\n   \
    \ Cap flow = 0;\n    Cost cost = 0, prev_cost = -1;\n    std::vector<std::pair<Cap,\
    \ Cost>> result;\n    result.push_back({flow, cost});\n    while (flow < flow_limit)\
    \ {\n      if (!dual_ref()) break;\n      Cap c = flow_limit - flow;\n      for\
    \ (int v = t; v != s; v = pv[v]) {\n        c = std::min(c, g[pv[v]][pe[v]].cap);\n\
    \      }\n      for (int v = t; v != s; v = pv[v]) {\n        auto& e = g[pv[v]][pe[v]];\n\
    \        e.cap -= c;\n        g[v][e.rev].cap += c;\n      }\n      Cost d = -dual[s];\n\
    \      flow += c;\n      cost += c * d;\n      if (prev_cost == d) {\n       \
    \ result.pop_back();\n      }\n      result.push_back({flow, cost});\n      prev_cost\
    \ = cost;\n    }\n    return result;\n  }\n\n private:\n  int _n;\n\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<int,\
    \ int>> pos;\n  std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \nusing namespace atcoder;\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\nnamespace atcoder {\n\ntemplate <class\
    \ Cap, class Cost>\nstruct mcf_graph {\n public:\n  mcf_graph() {}\n  mcf_graph(int\
    \ n) : _n(n), g(n) {}\n\n  int add_edge(int from, int to, Cap cap, Cost cost)\
    \ {\n    assert(0 <= from && from < _n);\n    assert(0 <= to && to < _n);\n  \
    \  int m = int(pos.size());\n    pos.push_back({from, int(g[from].size())});\n\
    \    g[from].push_back(_edge{to, int(g[to].size()), cap, cost});\n    g[to].push_back(_edge{from,\
    \ int(g[from].size()) - 1, 0, -cost});\n    return m;\n  }\n\n  struct edge {\n\
    \    int from, to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int\
    \ i) {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n    auto _e\
    \ = g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n    return\
    \ edge{\n        pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,\n  \
    \  };\n  }\n  std::vector<edge> edges() {\n    int m = int(pos.size());\n    std::vector<edge>\
    \ result(m);\n    for (int i = 0; i < m; i++) {\n      result[i] = get_edge(i);\n\
    \    }\n    return result;\n  }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n\
    \    return flow(s, t, std::numeric_limits<Cap>::max());\n  }\n  std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n    return slope(s, t, flow_limit).back();\n\
    \  }\n  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n    return slope(s,\
    \ t, std::numeric_limits<Cap>::max());\n  }\n  std::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n    assert(0\
    \ <= t && t < _n);\n    assert(s != t);\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.from] - dual[e.to]) >= 0 for all edge\n    std::vector<Cost> dual(_n,\
    \ 0), dist(_n);\n    std::vector<int> pv(_n), pe(_n);\n    std::vector<bool> vis(_n);\n\
    \    auto dual_ref = [&]() {\n      std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());\n\
    \      std::fill(pv.begin(), pv.end(), -1);\n      std::fill(pe.begin(), pe.end(),\
    \ -1);\n      std::fill(vis.begin(), vis.end(), false);\n      struct Q {\n  \
    \      Cost key;\n        int to;\n        bool operator<(Q r) const { return\
    \ key > r.key; }\n      };\n      std::priority_queue<Q> que;\n      dist[s] =\
    \ 0;\n      que.push(Q{0, s});\n      while (!que.empty()) {\n        int v =\
    \ que.top().to;\n        que.pop();\n        if (vis[v]) continue;\n        vis[v]\
    \ = true;\n        if (v == t) break;\n        // dist[v] = shortest(s, v) + dual[s]\
    \ - dual[v]\n        // dist[v] >= 0 (all reduced cost are positive)\n       \
    \ // dist[v] <= (n-1)C\n        for (int i = 0; i < int(g[v].size()); i++) {\n\
    \          auto e = g[v][i];\n          if (vis[e.to] || !e.cap) continue;\n \
    \         // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual[e.to] + dual[v];\n          if\
    \ (dist[e.to] - dist[v] > cost) {\n            dist[e.to] = dist[v] + cost;\n\
    \            pv[e.to] = v;\n            pe[e.to] = i;\n            que.push(Q{dist[e.to],\
    \ e.to});\n          }\n        }\n      }\n      if (!vis[t]) {\n        return\
    \ false;\n      }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s, t) +\n        //         dual[t] + shortest(s,\
    \ v) = shortest(s, v) - shortest(s, t) >=\n        //         0 - (n-1)C\n   \
    \     dual[v] -= dist[t] - dist[v];\n      }\n      return true;\n    };\n   \
    \ Cap flow = 0;\n    Cost cost = 0, prev_cost = -1;\n    std::vector<std::pair<Cap,\
    \ Cost>> result;\n    result.push_back({flow, cost});\n    while (flow < flow_limit)\
    \ {\n      if (!dual_ref()) break;\n      Cap c = flow_limit - flow;\n      for\
    \ (int v = t; v != s; v = pv[v]) {\n        c = std::min(c, g[pv[v]][pe[v]].cap);\n\
    \      }\n      for (int v = t; v != s; v = pv[v]) {\n        auto& e = g[pv[v]][pe[v]];\n\
    \        e.cap -= c;\n        g[v][e.rev].cap += c;\n      }\n      Cost d = -dual[s];\n\
    \      flow += c;\n      cost += c * d;\n      if (prev_cost == d) {\n       \
    \ result.pop_back();\n      }\n      result.push_back({flow, cost});\n      prev_cost\
    \ = cost;\n    }\n    return result;\n  }\n\n private:\n  int _n;\n\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<int,\
    \ int>> pos;\n  std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \nusing namespace atcoder;\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/mincostflow.hpp
  requiredBy: []
  timestamp: '2020-09-08 18:51:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/mincostflow.hpp
layout: document
redirect_from:
- /library/atcoder/mincostflow.hpp
- /library/atcoder/mincostflow.hpp.html
title: atcoder/mincostflow.hpp
---
