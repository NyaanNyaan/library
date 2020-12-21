---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
    title: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/flow-on-bipartite-graph.md
    document_title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30D5\u30ED\u30FC"
    links: []
  bundledCode: "#line 2 \"flow/flow-on-bipartite-graph.hpp\"\n\n#line 1 \"atcoder/maxflow.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <vector>\n\n#line 1 \"atcoder/internal_queue.hpp\"\n\n\n\n\
    #line 5 \"atcoder/internal_queue.hpp\"\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\ntemplate <class T> struct simple_queue {\n    std::vector<T> payload;\n\
    \    int pos = 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size()\
    \ const { return int(payload.size()) - pos; }\n    bool empty() const { return\
    \ pos == int(payload.size()); }\n    void push(const T& t) { payload.push_back(t);\
    \ }\n    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace atcoder\n\n\n#line 11 \"atcoder/maxflow.hpp\"\n\nnamespace atcoder\
    \ {\n\ntemplate <class Cap> struct mf_graph {\n  public:\n    mf_graph() : _n(0)\
    \ {}\n    mf_graph(int n) : _n(n), g(n) {}\n\n    virtual int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        int from_id = int(g[from].size());\n\
    \        int to_id = int(g[to].size());\n        if (from == to) to_id++;\n  \
    \      g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 4 \"flow/flow-on-bipartite-graph.hpp\"\n\nnamespace BipartiteGraphImpl\
    \ {\nusing namespace atcoder;\nstruct BipartiteGraph : mf_graph<long long> {\n\
    \  int L, R, s, t;\n\n  explicit BipartiteGraph(int N, int M)\n      : mf_graph<long\
    \ long>(N + M + 2), L(N), R(M), s(N + M), t(N + M + 1) {\n    for (int i = 0;\
    \ i < L; i++) mf_graph<long long>::add_edge(s, i, 1);\n    for (int i = 0; i <\
    \ R; i++) mf_graph<long long>::add_edge(i + L, t, 1);\n  }\n\n  int add_edge(int\
    \ n, int m, long long cap = 1) override {\n    assert(0 <= n && n < L);\n    assert(0\
    \ <= m && m < R);\n    return mf_graph<long long>::add_edge(n, m + L, cap);\n\
    \  }\n\n  long long flow() { return mf_graph<long long>::flow(s, t); }\n\n  vector<pair<int,\
    \ int>> MaximumMatching() {\n    auto es = mf_graph<long long>::edges();\n   \
    \ vector<pair<int, int>> ret;\n    for (auto &e : es) {\n      if (e.flow > 0\
    \ && e.from != s && e.to != t) {\n        ret.emplace_back(e.from, e.to - L);\n\
    \      }\n    }\n    return ret;\n  }\n\n  // call after calclating flow !\n \
    \ pair<vector<int>, vector<int>> MinimumVertexCover() {\n    auto colored = PreCalc();\n\
    \    vector<int> nl, nr;\n    for (int i = 0; i < L; i++)\n      if (!colored[i])\
    \ nl.push_back(i);\n    for (int i = 0; i < R; i++)\n      if (colored[i + L])\
    \ nr.push_back(i);\n    return make_pair(nl, nr);\n  }\n\n  // call after calclating\
    \ flow !\n  pair<vector<int>, vector<int>> MaximumIndependentSet() {\n    auto\
    \ colored = PreCalc();\n    vector<int> nl, nr;\n    for (int i = 0; i < L; i++)\n\
    \      if (colored[i]) nl.push_back(i);\n    for (int i = 0; i < R; i++)\n   \
    \   if (!colored[i + L]) nr.push_back(i);\n    return make_pair(nl, nr);\n  }\n\
    \n private:\n  vector<bool> PreCalc() {\n    vector<vector<int>> ag(L + R);\n\
    \    vector<bool> used(L, false);\n    for (auto &e : mf_graph<long long>::edges())\
    \ {\n      if (e.from == s || e.to == t) continue;\n      if (e.flow > 0) {\n\
    \        ag[e.to].push_back(e.from);\n        used[e.from] = true;\n      } else\
    \ {\n        ag[e.from].push_back(e.to);\n      }\n    }\n    vector<bool> colored(L\
    \ + R, false);\n    auto dfs = [&](auto rc, int cur) -> void {\n      for (auto\
    \ &d : ag[cur]) {\n        if (!colored[d]) colored[d] = true, rc(rc, d);\n  \
    \    }\n    };\n    for (int i = 0; i < L; i++)\n      if (!used[i]) colored[i]\
    \ = true, dfs(dfs, i);\n    return colored;\n  }\n};\n\n}  // namespace BipartiteGraphImpl\n\
    \nusing BipartiteGraphImpl::BipartiteGraph;\n\n/**\n * @brief \u4E8C\u90E8\u30B0\
    \u30E9\u30D5\u306E\u30D5\u30ED\u30FC\n * @docs docs/flow/flow-on-bipartite-graph.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../atcoder/maxflow.hpp\"\n\nnamespace BipartiteGraphImpl\
    \ {\nusing namespace atcoder;\nstruct BipartiteGraph : mf_graph<long long> {\n\
    \  int L, R, s, t;\n\n  explicit BipartiteGraph(int N, int M)\n      : mf_graph<long\
    \ long>(N + M + 2), L(N), R(M), s(N + M), t(N + M + 1) {\n    for (int i = 0;\
    \ i < L; i++) mf_graph<long long>::add_edge(s, i, 1);\n    for (int i = 0; i <\
    \ R; i++) mf_graph<long long>::add_edge(i + L, t, 1);\n  }\n\n  int add_edge(int\
    \ n, int m, long long cap = 1) override {\n    assert(0 <= n && n < L);\n    assert(0\
    \ <= m && m < R);\n    return mf_graph<long long>::add_edge(n, m + L, cap);\n\
    \  }\n\n  long long flow() { return mf_graph<long long>::flow(s, t); }\n\n  vector<pair<int,\
    \ int>> MaximumMatching() {\n    auto es = mf_graph<long long>::edges();\n   \
    \ vector<pair<int, int>> ret;\n    for (auto &e : es) {\n      if (e.flow > 0\
    \ && e.from != s && e.to != t) {\n        ret.emplace_back(e.from, e.to - L);\n\
    \      }\n    }\n    return ret;\n  }\n\n  // call after calclating flow !\n \
    \ pair<vector<int>, vector<int>> MinimumVertexCover() {\n    auto colored = PreCalc();\n\
    \    vector<int> nl, nr;\n    for (int i = 0; i < L; i++)\n      if (!colored[i])\
    \ nl.push_back(i);\n    for (int i = 0; i < R; i++)\n      if (colored[i + L])\
    \ nr.push_back(i);\n    return make_pair(nl, nr);\n  }\n\n  // call after calclating\
    \ flow !\n  pair<vector<int>, vector<int>> MaximumIndependentSet() {\n    auto\
    \ colored = PreCalc();\n    vector<int> nl, nr;\n    for (int i = 0; i < L; i++)\n\
    \      if (colored[i]) nl.push_back(i);\n    for (int i = 0; i < R; i++)\n   \
    \   if (!colored[i + L]) nr.push_back(i);\n    return make_pair(nl, nr);\n  }\n\
    \n private:\n  vector<bool> PreCalc() {\n    vector<vector<int>> ag(L + R);\n\
    \    vector<bool> used(L, false);\n    for (auto &e : mf_graph<long long>::edges())\
    \ {\n      if (e.from == s || e.to == t) continue;\n      if (e.flow > 0) {\n\
    \        ag[e.to].push_back(e.from);\n        used[e.from] = true;\n      } else\
    \ {\n        ag[e.from].push_back(e.to);\n      }\n    }\n    vector<bool> colored(L\
    \ + R, false);\n    auto dfs = [&](auto rc, int cur) -> void {\n      for (auto\
    \ &d : ag[cur]) {\n        if (!colored[d]) colored[d] = true, rc(rc, d);\n  \
    \    }\n    };\n    for (int i = 0; i < L; i++)\n      if (!used[i]) colored[i]\
    \ = true, dfs(dfs, i);\n    return colored;\n  }\n};\n\n}  // namespace BipartiteGraphImpl\n\
    \nusing BipartiteGraphImpl::BipartiteGraph;\n\n/**\n * @brief \u4E8C\u90E8\u30B0\
    \u30E9\u30D5\u306E\u30D5\u30ED\u30FC\n * @docs docs/flow/flow-on-bipartite-graph.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/flow-on-bipartite-graph.hpp
  requiredBy: []
  timestamp: '2020-12-21 18:22:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
documentation_of: flow/flow-on-bipartite-graph.hpp
layout: document
redirect_from:
- /library/flow/flow-on-bipartite-graph.hpp
- /library/flow/flow-on-bipartite-graph.hpp.html
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30D5\u30ED\u30FC"
---
## 二部グラフのフロー

#### 使い方

- `BipartiteGraph(int N, int M)`
- `add_edge(int n, int m, long long cap = 1)`
- `flow()`
- `MaximumMatching()`
- `MinimumVertexCover()`
- `MaximumIndependentSet()`

