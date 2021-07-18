---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two-sat.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nusing namespace std;\n\nnamespace TwoSatImpl\
    \ {\nnamespace internal {\n\ntemplate <class E>\nstruct csr {\n  vector<int> start;\n\
    \  vector<E> elist;\n  csr(int n, const vector<pair<int, E>>& edges)\n      :\
    \ start(n + 1), elist(edges.size()) {\n    for (auto e : edges) {\n      start[e.first\
    \ + 1]++;\n    }\n    for (int i = 1; i <= n; i++) {\n      start[i] += start[i\
    \ - 1];\n    }\n    auto counter = start;\n    for (auto e : edges) {\n      elist[counter[e.first]++]\
    \ = e.second;\n    }\n  }\n};\n\nstruct scc_graph {\n public:\n  scc_graph(int\
    \ n) : _n(n) {}\n\n  int num_vertices() { return _n; }\n\n  void add_edge(int\
    \ from, int to) { edges.push_back({from, {to}}); }\n\n  pair<int, vector<int>>\
    \ scc_ids() {\n    auto g = csr<edge>(_n, edges);\n    int now_ord = 0, group_num\
    \ = 0;\n    vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n    visited.reserve(_n);\n\
    \    auto dfs = [&](auto self, int v) -> void {\n      low[v] = ord[v] = now_ord++;\n\
    \      visited.push_back(v);\n      for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n        auto to = g.elist[i].to;\n        if (ord[to] == -1) {\n   \
    \       self(self, to);\n          low[v] = min(low[v], low[to]);\n        } else\
    \ {\n          low[v] = min(low[v], ord[to]);\n        }\n      }\n      if (low[v]\
    \ == ord[v]) {\n        while (true) {\n          int u = visited.back();\n  \
    \        visited.pop_back();\n          ord[u] = _n;\n          ids[u] = group_num;\n\
    \          if (u == v) break;\n        }\n        group_num++;\n      }\n    };\n\
    \    for (int i = 0; i < _n; i++) {\n      if (ord[i] == -1) dfs(dfs, i);\n  \
    \  }\n    for (auto& x : ids) {\n      x = group_num - 1 - x;\n    }\n    return\
    \ {group_num, ids};\n  }\n\n  vector<vector<int>> scc() {\n    auto ids = scc_ids();\n\
    \    int group_num = ids.first;\n    vector<int> counts(group_num);\n    for (auto\
    \ x : ids.second) counts[x]++;\n    vector<vector<int>> groups(ids.first);\n \
    \   for (int i = 0; i < group_num; i++) {\n      groups[i].reserve(counts[i]);\n\
    \    }\n    for (int i = 0; i < _n; i++) {\n      groups[ids.second[i]].push_back(i);\n\
    \    }\n    return groups;\n  }\n\n  void add_node_size(int m) { _n += m; }\n\
    \  int size() { return _n; }\n\n private:\n  int _n;\n  struct edge {\n    int\
    \ to;\n  };\n  vector<pair<int, edge>> edges;\n};\n\n}  // namespace internal\n\
    \nstruct two_sat {\n public:\n  two_sat() : _n(0), scc(0) {}\n  two_sat(int n)\
    \ : _n(n), scc(2 * n) {}\n\n  int add_var() {\n    scc.add_node_size(2);\n   \
    \ return _n++;\n  }\n\n  // (not i) \u306F ~i \u3067\u6E21\u3059\n  void add_clause(int\
    \ i, int j) {\n    i = max(2 * i, -1 - 2 * i);\n    j = max(2 * j, -1 - 2 * j);\n\
    \    assert(0 <= i && i < 2 * _n);\n    assert(0 <= j && j < 2 * _n);\n    scc.add_edge(i\
    \ ^ 1, j);\n    scc.add_edge(j ^ 1, i);\n  }\n  void if_then(int i, int j) { add_clause(~i,\
    \ j); }\n  void set_val(int i) { add_clause(i, i); }\n\n  // (not i) \u306F ~i\
    \ \u3067\u6E21\u3059\n  void at_most_one(const vector<int>& nodes) {\n    if ((int)nodes.size()\
    \ <= 1) return;\n    int cur = ~nodes[0];\n    for (int i = 2; i < (int)nodes.size();\
    \ i++) {\n      int nxt = add_var(), n_i = ~nodes[i];\n      add_clause(cur, n_i);\n\
    \      add_clause(cur, nxt);\n      add_clause(n_i, nxt);\n      cur = ~nxt;\n\
    \    }\n    add_clause(cur, ~nodes[1]);\n  }\n\n  bool satisfiable() {\n    _answer.resize(_n);\n\
    \    auto id = scc.scc_ids().second;\n    for (int i = 0; i < _n; i++) {\n   \
    \   if (id[2 * i] == id[2 * i + 1]) return false;\n      _answer[i] = id[2 * i]\
    \ < id[2 * i + 1];\n    }\n    return true;\n  }\n  vector<bool> answer() {\n\
    \    assert((int)_answer.size() == _n);\n    return _answer;\n  }\n\n private:\n\
    \  int _n;\n  vector<bool> _answer;\n  internal::scc_graph scc;\n};\n\n}  // namespace\
    \ TwoSatImpl\n\nusing TwoSatImpl::two_sat;\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nusing namespace std;\n\nnamespace TwoSatImpl {\nnamespace\
    \ internal {\n\ntemplate <class E>\nstruct csr {\n  vector<int> start;\n  vector<E>\
    \ elist;\n  csr(int n, const vector<pair<int, E>>& edges)\n      : start(n + 1),\
    \ elist(edges.size()) {\n    for (auto e : edges) {\n      start[e.first + 1]++;\n\
    \    }\n    for (int i = 1; i <= n; i++) {\n      start[i] += start[i - 1];\n\
    \    }\n    auto counter = start;\n    for (auto e : edges) {\n      elist[counter[e.first]++]\
    \ = e.second;\n    }\n  }\n};\n\nstruct scc_graph {\n public:\n  scc_graph(int\
    \ n) : _n(n) {}\n\n  int num_vertices() { return _n; }\n\n  void add_edge(int\
    \ from, int to) { edges.push_back({from, {to}}); }\n\n  pair<int, vector<int>>\
    \ scc_ids() {\n    auto g = csr<edge>(_n, edges);\n    int now_ord = 0, group_num\
    \ = 0;\n    vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n    visited.reserve(_n);\n\
    \    auto dfs = [&](auto self, int v) -> void {\n      low[v] = ord[v] = now_ord++;\n\
    \      visited.push_back(v);\n      for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n        auto to = g.elist[i].to;\n        if (ord[to] == -1) {\n   \
    \       self(self, to);\n          low[v] = min(low[v], low[to]);\n        } else\
    \ {\n          low[v] = min(low[v], ord[to]);\n        }\n      }\n      if (low[v]\
    \ == ord[v]) {\n        while (true) {\n          int u = visited.back();\n  \
    \        visited.pop_back();\n          ord[u] = _n;\n          ids[u] = group_num;\n\
    \          if (u == v) break;\n        }\n        group_num++;\n      }\n    };\n\
    \    for (int i = 0; i < _n; i++) {\n      if (ord[i] == -1) dfs(dfs, i);\n  \
    \  }\n    for (auto& x : ids) {\n      x = group_num - 1 - x;\n    }\n    return\
    \ {group_num, ids};\n  }\n\n  vector<vector<int>> scc() {\n    auto ids = scc_ids();\n\
    \    int group_num = ids.first;\n    vector<int> counts(group_num);\n    for (auto\
    \ x : ids.second) counts[x]++;\n    vector<vector<int>> groups(ids.first);\n \
    \   for (int i = 0; i < group_num; i++) {\n      groups[i].reserve(counts[i]);\n\
    \    }\n    for (int i = 0; i < _n; i++) {\n      groups[ids.second[i]].push_back(i);\n\
    \    }\n    return groups;\n  }\n\n  void add_node_size(int m) { _n += m; }\n\
    \  int size() { return _n; }\n\n private:\n  int _n;\n  struct edge {\n    int\
    \ to;\n  };\n  vector<pair<int, edge>> edges;\n};\n\n}  // namespace internal\n\
    \nstruct two_sat {\n public:\n  two_sat() : _n(0), scc(0) {}\n  two_sat(int n)\
    \ : _n(n), scc(2 * n) {}\n\n  int add_var() {\n    scc.add_node_size(2);\n   \
    \ return _n++;\n  }\n\n  // (not i) \u306F ~i \u3067\u6E21\u3059\n  void add_clause(int\
    \ i, int j) {\n    i = max(2 * i, -1 - 2 * i);\n    j = max(2 * j, -1 - 2 * j);\n\
    \    assert(0 <= i && i < 2 * _n);\n    assert(0 <= j && j < 2 * _n);\n    scc.add_edge(i\
    \ ^ 1, j);\n    scc.add_edge(j ^ 1, i);\n  }\n  void if_then(int i, int j) { add_clause(~i,\
    \ j); }\n  void set_val(int i) { add_clause(i, i); }\n\n  // (not i) \u306F ~i\
    \ \u3067\u6E21\u3059\n  void at_most_one(const vector<int>& nodes) {\n    if ((int)nodes.size()\
    \ <= 1) return;\n    int cur = ~nodes[0];\n    for (int i = 2; i < (int)nodes.size();\
    \ i++) {\n      int nxt = add_var(), n_i = ~nodes[i];\n      add_clause(cur, n_i);\n\
    \      add_clause(cur, nxt);\n      add_clause(n_i, nxt);\n      cur = ~nxt;\n\
    \    }\n    add_clause(cur, ~nodes[1]);\n  }\n\n  bool satisfiable() {\n    _answer.resize(_n);\n\
    \    auto id = scc.scc_ids().second;\n    for (int i = 0; i < _n; i++) {\n   \
    \   if (id[2 * i] == id[2 * i + 1]) return false;\n      _answer[i] = id[2 * i]\
    \ < id[2 * i + 1];\n    }\n    return true;\n  }\n  vector<bool> answer() {\n\
    \    assert((int)_answer.size() == _n);\n    return _answer;\n  }\n\n private:\n\
    \  int _n;\n  vector<bool> _answer;\n  internal::scc_graph scc;\n};\n\n}  // namespace\
    \ TwoSatImpl\n\nusing TwoSatImpl::two_sat;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/two-sat.hpp
  requiredBy: []
  timestamp: '2021-07-18 18:42:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/two-sat.hpp
layout: document
redirect_from:
- /library/graph/two-sat.hpp
- /library/graph/two-sat.hpp.html
title: graph/two-sat.hpp
---
