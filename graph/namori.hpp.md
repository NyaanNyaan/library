---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2891.test.cpp
    title: verify/verify-aoj-other/aoj-2891.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1254.test.cpp
    title: verify/verify-yuki/yuki-1254.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/functional-graph.md
    document_title: "Functional Graph(\u306A\u3082\u308A\u30B0\u30E9\u30D5)\u306E\u5206\
      \u89E3"
    links: []
  bundledCode: "#line 2 \"graph/namori.hpp\"\n\n#include <vector>\n\n#line 2 \"data-structure/union-find.hpp\"\
    \n\nstruct UnionFind {\n  vector<int> data;\n  UnionFind(int N) : data(N, -1)\
    \ {}\n\n  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]);\
    \ }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return\
    \ false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n  \
    \  data[y] = x;\n    return true;\n  }\n\n  // f ... merge function\n  template<typename\
    \ F>\n  int unite(int x, int y,const F &f) {\n    if ((x = find(x)) == (y = find(y)))\
    \ return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    f(x, y);\n    return true;\n  }\n\n  int size(int k) {\
    \ return -data[find(k)]; }\n\n  int same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n\n/**\n * @brief Union Find(Disjoint Set Union)\n * @docs docs/data-structure/union-find.md\n\
    \ */\n#line 2 \"tree/heavy-light-decomposition.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin\
    \ = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n\
    \    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n\
    \  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\n\
    vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n    \
    \                       bool is_directed = false, bool is_1origin = true) {\n\
    \  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n\
    \    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin\
    \ >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] =\
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate <typename G>\n\
    struct HeavyLightDecomposition {\n private:\n  void dfs_sz(int cur) {\n    size[cur]\
    \ = 1;\n    for (auto& dst : g[cur]) {\n      if (dst == par[cur]) {\n       \
    \ if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n          swap(g[cur][0],\
    \ g[cur][1]);\n        else\n          continue;\n      }\n      depth[dst] =\
    \ depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n      size[cur]\
    \ += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n        swap(dst, g[cur][0]);\n\
    \      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n    down[cur] = id++;\n   \
    \ for (auto dst : g[cur]) {\n      if (dst == par[cur]) continue;\n      nxt[dst]\
    \ = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n      dfs_hld(dst);\n\
    \    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pair<int, int>> ascend(int\
    \ u, int v) const {\n    vector<pair<int, int>> res;\n    while (nxt[u] != nxt[v])\
    \ {\n      res.emplace_back(down[u], down[nxt[u]]);\n      u = par[nxt[u]];\n\
    \    }\n    if (u != v) res.emplace_back(down[u], down[v] + 1);\n    return res;\n\
    \  }\n\n  // (u, v]\n  vector<pair<int, int>> descend(int u, int v) const {\n\
    \    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\n\
    \    auto res = descend(u, par[nxt[v]]);\n    res.emplace_back(down[nxt[v]], down[v]);\n\
    \    return res;\n  }\n\n public:\n  G& g;\n  int root, id;\n  vector<int> size,\
    \ depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int _root = 0)\n\
    \      : g(_g),\n        root(_root),\n        id(0),\n        size(g.size(),\
    \ 0),\n        depth(g.size(), 0),\n        down(g.size(), -1),\n        up(g.size(),\
    \ -1),\n        nxt(g.size(), root),\n        par(g.size(), root) {\n    dfs_sz(root);\n\
    \    dfs_hld(root);\n  }\n\n  pair<int, int> idx(int i) const { return make_pair(down[i],\
    \ up[i]); }\n\n  template <typename F>\n  void path_query(int u, int v, bool vertex,\
    \ const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l))\
    \ {\n      int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n  \
    \  if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v))\
    \ {\n      int s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\
    \n  template <typename F>\n  void path_noncommutative_query(int u, int v, bool\
    \ vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void\
    \ subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex),\
    \ up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n\
    \      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n   \
    \ return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return\
    \ depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light\
    \ Decomposition(\u91CD\u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n\
    \ */\n#line 8 \"graph/namori.hpp\"\n\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct Namori {\n  using G = WeightedGraph<T>;\n\n  int n;\n  G g;\n\n \
    \ // \u90E8\u5206\u30B0\u30E9\u30D5\n  vector<G> aux;\n\n  // \u30EB\u30FC\u30D7\
    \u90E8\u5206\u306E(\u9802\u70B9,\u8FBA\u306E\u91CD\u307F)\n  // loop[i].se \u306F\
    \ loop[i] \u3068 loop[i+1] \u306E\u9593\u306E\u8FBA\n  vector<pair<int, T>> loop;\n\
    \n  // \u9802\u70B9\u306E\u5BFE\u5FDC\u95A2\u4FC2\n  vector<pair<int, int>> mp;\n\
    \n  // HL\u5206\u89E3\n  vector<HeavyLightDecomposition<G>> hld;\n\n  Namori(int\
    \ _n = 0) : _uf(_n) { init(_n); }\n\n  void init(int _n) {\n    n = _n;\n    g.resize(n);\n\
    \    _uf.data.resize(n);\n    fill(begin(_uf.data), end(_uf.data), -1);\n    _is_loop.resize(n,\
    \ false);\n    mp.resize(n, make_pair(-1, -1));\n  }\n\n  void add_edge(int u,\
    \ int v, T w = 1) {\n    assert(_built == false);\n    if (_uf.same(u, v)) {\n\
    \      _root = u, _adj = v, _w = w;\n    } else {\n      _uf.unite(u, v);\n  \
    \    g[u].emplace_back(u, v, w);\n      g[v].emplace_back(v, u, w);\n    }\n \
    \   if (++_es == n) build();\n  }\n\n  void build() {\n    if (_built) return;\n\
    \n    _buf.resize(n, -1);\n    dfs1(_root, -1);\n\n    for (int c = _adj; c >=\
    \ 0; c = _buf[c]) {\n      loop.emplace_back(c, -1);\n      _is_loop[c] = true;\n\
    \      for (auto& e : g[c]) {\n        if (e == _buf[c]) loop.back().second =\
    \ e.cost;\n      }\n    }\n    assert(loop.back().first == _root);\n    loop.back().second\
    \ = _w;\n\n    _h.resize(n);\n    for (auto& [i, _] : loop) dfs2(i, -1);\n\n \
    \   fill(begin(_buf), end(_buf), 0);\n    for (auto& [i, _] : loop) dfs3(i);\n\
    \n    _uf.data.clear();\n    _buf.clear();\n    _is_loop.clear();\n\n    aux.resize(loop.size());\n\
    \    for (int i = 0; i < (int)loop.size(); i++) {\n      int k = loop[i].first,\
    \ j = 0;\n      dfs4(k, i, j);\n      aux[i].resize(j);\n\n      dfs5(k);\n  \
    \    hld.emplace_back(aux[i]);\n    }\n\n    _h.clear();\n    _built = true;\n\
    \  }\n\n  pair<int, int> idx(int i) const { return mp[i]; }\n\n  int root(int\
    \ i) const { return loop[mp[i].first].first; }\n\n private:\n  // \u521D\u671F\
    \u5316\u7528\u306E\u72B6\u614B\u5909\u6570\n  UnionFind _uf;\n  vector<int> _buf;\n\
    \  vector<bool> _is_loop;\n  int _root = -1, _adj = -1, _es = 0;\n  bool _built\
    \ = false;\n  T _w = 0;\n  G _h;\n\n  // par\u3092\u30E1\u30E2\u3059\u308B\n \
    \ void dfs1(int c, int p) {\n    for (auto& d : g[c]) {\n      if (d != p) {\n\
    \        _buf[d] = c;\n        dfs1(d, c);\n      }\n    }\n  }\n\n  // _h \u3067\
    \u6709\u5411\u6728\u3092\u4F5C\u308B\n  void dfs2(int c, int p) {\n    for (auto&\
    \ d : g[c]) {\n      if (d == p or _is_loop[d]) continue;\n      _h[c].emplace_back(c,\
    \ d, d.cost);\n      dfs2(d, c);\n    }\n  }\n\n  // HLD\u7528\u306B\u9806\u756A\
    \u66FF\u3048\n  void dfs3(int c) {\n    _buf[c] = 1;\n    for (auto& d : _h[c])\
    \ {\n      dfs3(d);\n      _buf[c] += _buf[d];\n      if (_buf[d] > _buf[_h[c][0]])\
    \ {\n        swap(_h[c][0], d);\n      }\n    }\n  }\n\n  // \u9806\u756A\u3092\
    \u3064\u3051\u308B\n  void dfs4(int c, int i, int& j) {\n    mp[c] = make_pair(i,\
    \ j++);\n    for (auto& d : _h[c]) {\n      dfs4(d, i, j);\n    }\n  }\n\n  //\
    \ \u90E8\u5206\u30B0\u30E9\u30D5\u3092\u4F5C\u308B\n  void dfs5(int c) {\n   \
    \ for (auto& d : _h[c]) {\n      dfs5(d);\n      auto [i, j] = mp[c];\n      auto\
    \ [_, k] = mp[d];\n      aux[i][j].emplace_back(j, k, d.cost);\n      // \u9006\
    \u8FBA\u3082\u5165\u308C\u305F\u3044\u3068\u304D\u306F\u3053\u3053\u3092\u30AA\
    \u30F3\u306B\u3059\u308B(\u52D5\u304F\u304B\u4E0D\u660E)\n      // aux[i][k].emplace_back(k,\
    \ j, d.cost);\n    }\n  }\n};\n\n/**\n * @brief Functional Graph(\u306A\u3082\u308A\
    \u30B0\u30E9\u30D5)\u306E\u5206\u89E3\n * @docs docs/graph/functional-graph.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../data-structure/union-find.hpp\"\
    \n#include \"../tree/heavy-light-decomposition.hpp\"\n#include \"graph-template.hpp\"\
    \n\nusing namespace std;\n\ntemplate <typename T>\nstruct Namori {\n  using G\
    \ = WeightedGraph<T>;\n\n  int n;\n  G g;\n\n  // \u90E8\u5206\u30B0\u30E9\u30D5\
    \n  vector<G> aux;\n\n  // \u30EB\u30FC\u30D7\u90E8\u5206\u306E(\u9802\u70B9,\u8FBA\
    \u306E\u91CD\u307F)\n  // loop[i].se \u306F loop[i] \u3068 loop[i+1] \u306E\u9593\
    \u306E\u8FBA\n  vector<pair<int, T>> loop;\n\n  // \u9802\u70B9\u306E\u5BFE\u5FDC\
    \u95A2\u4FC2\n  vector<pair<int, int>> mp;\n\n  // HL\u5206\u89E3\n  vector<HeavyLightDecomposition<G>>\
    \ hld;\n\n  Namori(int _n = 0) : _uf(_n) { init(_n); }\n\n  void init(int _n)\
    \ {\n    n = _n;\n    g.resize(n);\n    _uf.data.resize(n);\n    fill(begin(_uf.data),\
    \ end(_uf.data), -1);\n    _is_loop.resize(n, false);\n    mp.resize(n, make_pair(-1,\
    \ -1));\n  }\n\n  void add_edge(int u, int v, T w = 1) {\n    assert(_built ==\
    \ false);\n    if (_uf.same(u, v)) {\n      _root = u, _adj = v, _w = w;\n   \
    \ } else {\n      _uf.unite(u, v);\n      g[u].emplace_back(u, v, w);\n      g[v].emplace_back(v,\
    \ u, w);\n    }\n    if (++_es == n) build();\n  }\n\n  void build() {\n    if\
    \ (_built) return;\n\n    _buf.resize(n, -1);\n    dfs1(_root, -1);\n\n    for\
    \ (int c = _adj; c >= 0; c = _buf[c]) {\n      loop.emplace_back(c, -1);\n   \
    \   _is_loop[c] = true;\n      for (auto& e : g[c]) {\n        if (e == _buf[c])\
    \ loop.back().second = e.cost;\n      }\n    }\n    assert(loop.back().first ==\
    \ _root);\n    loop.back().second = _w;\n\n    _h.resize(n);\n    for (auto& [i,\
    \ _] : loop) dfs2(i, -1);\n\n    fill(begin(_buf), end(_buf), 0);\n    for (auto&\
    \ [i, _] : loop) dfs3(i);\n\n    _uf.data.clear();\n    _buf.clear();\n    _is_loop.clear();\n\
    \n    aux.resize(loop.size());\n    for (int i = 0; i < (int)loop.size(); i++)\
    \ {\n      int k = loop[i].first, j = 0;\n      dfs4(k, i, j);\n      aux[i].resize(j);\n\
    \n      dfs5(k);\n      hld.emplace_back(aux[i]);\n    }\n\n    _h.clear();\n\
    \    _built = true;\n  }\n\n  pair<int, int> idx(int i) const { return mp[i];\
    \ }\n\n  int root(int i) const { return loop[mp[i].first].first; }\n\n private:\n\
    \  // \u521D\u671F\u5316\u7528\u306E\u72B6\u614B\u5909\u6570\n  UnionFind _uf;\n\
    \  vector<int> _buf;\n  vector<bool> _is_loop;\n  int _root = -1, _adj = -1, _es\
    \ = 0;\n  bool _built = false;\n  T _w = 0;\n  G _h;\n\n  // par\u3092\u30E1\u30E2\
    \u3059\u308B\n  void dfs1(int c, int p) {\n    for (auto& d : g[c]) {\n      if\
    \ (d != p) {\n        _buf[d] = c;\n        dfs1(d, c);\n      }\n    }\n  }\n\
    \n  // _h \u3067\u6709\u5411\u6728\u3092\u4F5C\u308B\n  void dfs2(int c, int p)\
    \ {\n    for (auto& d : g[c]) {\n      if (d == p or _is_loop[d]) continue;\n\
    \      _h[c].emplace_back(c, d, d.cost);\n      dfs2(d, c);\n    }\n  }\n\n  //\
    \ HLD\u7528\u306B\u9806\u756A\u66FF\u3048\n  void dfs3(int c) {\n    _buf[c] =\
    \ 1;\n    for (auto& d : _h[c]) {\n      dfs3(d);\n      _buf[c] += _buf[d];\n\
    \      if (_buf[d] > _buf[_h[c][0]]) {\n        swap(_h[c][0], d);\n      }\n\
    \    }\n  }\n\n  // \u9806\u756A\u3092\u3064\u3051\u308B\n  void dfs4(int c, int\
    \ i, int& j) {\n    mp[c] = make_pair(i, j++);\n    for (auto& d : _h[c]) {\n\
    \      dfs4(d, i, j);\n    }\n  }\n\n  // \u90E8\u5206\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u308B\n  void dfs5(int c) {\n    for (auto& d : _h[c]) {\n      dfs5(d);\n\
    \      auto [i, j] = mp[c];\n      auto [_, k] = mp[d];\n      aux[i][j].emplace_back(j,\
    \ k, d.cost);\n      // \u9006\u8FBA\u3082\u5165\u308C\u305F\u3044\u3068\u304D\
    \u306F\u3053\u3053\u3092\u30AA\u30F3\u306B\u3059\u308B(\u52D5\u304F\u304B\u4E0D\
    \u660E)\n      // aux[i][k].emplace_back(k, j, d.cost);\n    }\n  }\n};\n\n/**\n\
    \ * @brief Functional Graph(\u306A\u3082\u308A\u30B0\u30E9\u30D5)\u306E\u5206\u89E3\
    \n * @docs docs/graph/functional-graph.md\n */\n"
  dependsOn:
  - data-structure/union-find.hpp
  - tree/heavy-light-decomposition.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/namori.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2891.test.cpp
  - verify/verify-yuki/yuki-1254.test.cpp
documentation_of: graph/namori.hpp
layout: document
redirect_from:
- /library/graph/namori.hpp
- /library/graph/namori.hpp.html
title: "Functional Graph(\u306A\u3082\u308A\u30B0\u30E9\u30D5)\u306E\u5206\u89E3"
---
## Functional Graph(なもりグラフ)

頂点数$n$のなもりグラフを$\mathrm{O}(n\alpha (n))$で分解するライブラリ。

#### 使い方

##### メンバ関数

- `Namori<T>(int n)`: $n$頂点のなもりグラフのコンストラクタ。(`T`は辺の重みの型)
- `add_edge(int u, int v, T w)`: 重み`w`の`(u, v)`パスを追加する。
- `idx(int i)`: 頂点$i$の新しいインデックス$(r,x)$を返す。($r$番目の部分木の$x$番目の頂点を意味する)
- `root(int i)`: $i$番目の頂点の根$j$(古いインデックス)を返す。

##### メンバ変数

- `vector<pair<int, T>> loop`: なもりグラフのループ部分のグラフ。
  - `loop[i].second` は `loop[i]` と `loop[i+1]` の間の辺の重みを意味する。
- `vector<WeightedGraph<T>> aux`: ループ部分に付随する部分木のグラフ。
  - `aux[i]` は `loop[i]` を根とするグラフ。
- `vector<HeavyLightDecomposition<G>> hld`: `aux`をHL分解したもの。
  - `hld[i].idx(i).first`と`Namori::idx(i).first`が一致するようにしている(はず)
  - TODO: ここ自信がないのでverifyを書く
