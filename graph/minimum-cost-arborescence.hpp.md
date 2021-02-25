---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/skew-heap.hpp
    title: Skew Heap
  - icon: ':question:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
    title: verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/minimum-cost-arborescence.hpp\"\n\n#line 2 \"data-structure/skew-heap.hpp\"\
    \n\ntemplate <typename T, bool isMin = true>\nstruct SkewHeap {\n  struct Node\
    \ {\n    T key, laz;\n    Node *l, *r;\n    int idx;\n    Node() = default;\n\
    \    Node(const T &k, int i = -1)\n        : key(k), laz(0), l(nullptr), r(nullptr),\
    \ idx(i) {}\n  };\n  using Ptr = Node *;\n\n  static void propagate(Ptr x) {\n\
    \    if (x->laz == 0) return;\n    if (x->l) x->l->laz += x->laz;\n    if (x->r)\
    \ x->r->laz += x->laz;\n    x->key += x->laz;\n    x->laz = 0;\n  }\n\n  static\
    \ Ptr meld(Ptr x, Ptr y) {\n    if (!x || !y) return x ? x : y;\n    if (!comp(x,\
    \ y)) swap(x, y);\n    propagate(x);\n    x->r = meld(x->r, y);\n    swap(x->l,\
    \ x->r);\n    return x;\n  }\n\n  static Ptr alloc(const T &key, int idx = -1)\
    \ { return new Node(key, idx); }\n\n  static Ptr pop(Ptr x) {\n    propagate(x);\n\
    \    return meld(x->l, x->r);\n  }\n\n  static Ptr push(Ptr x, const T &key, int\
    \ idx = -1) {\n    return meld(x, alloc(key, idx));\n  }\n\n  static void apply(Ptr\
    \ x, const T &laz) {\n    x->laz += laz;\n    propagate(x);\n  }\n\n private:\n\
    \  static inline bool comp(Ptr x, Ptr y) {\n    if constexpr (isMin) {\n     \
    \ return x->key + x->laz < y->key + y->laz;\n    } else {\n      return x->key\
    \ + x->laz > y->key + y->laz;\n    }\n  }\n};\n\n/**\n * @brief Skew Heap\n *\
    \ @docs docs/data-structure/skew-heap.md\n */\n#line 2 \"data-structure/union-find.hpp\"\
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
    \ */\n#line 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge\
    \ {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to),\
    \ cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost)\
    \ {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\
    \n  operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
    \ = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph = vector<Edges<T>>;\n\
    using UnweightedGraph = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\n\
    UnweightedGraph graph(int N, int M = -1, bool is_directed = false,\n         \
    \             bool is_1origin = true) {\n  UnweightedGraph g(N);\n  if (M == -1)\
    \ M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >>\
    \ y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n    if (!is_directed)\
    \ g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of Weighted Graph\ntemplate\
    \ <typename T>\nWeightedGraph<T> wgraph(int N, int M = -1, bool is_directed =\
    \ false,\n                        bool is_1origin = true) {\n  WeightedGraph<T>\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n\
    \    g[x].emplace_back(x, y, c);\n    if (!is_directed) g[y].emplace_back(y, x,\
    \ c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {\n  Edges<T>\
    \ es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n  \
    \  T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if\
    \ (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return es;\n}\n\
    \n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>> adjgraph(int\
    \ N, int M, T INF, int is_weighted = true,\n                           bool is_directed\
    \ = false, bool is_1origin = true) {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n\
    \  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n\
    \    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if (is_1origin)\
    \ x--, y--;\n    d[x][y] = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return\
    \ d;\n}\n#line 6 \"graph/minimum-cost-arborescence.hpp\"\n\ntemplate <typename\
    \ T>\nEdges<T> MinimumCostArborescence(int N, int root, const Edges<T> &es) {\n\
    \  using Heap = SkewHeap<T>;\n  using Ptr = typename Heap::Ptr;\n  UnionFind uf(N);\n\
    \  vector<int> used(N, -1), from(N);\n  vector<T> from_cost(N);\n  vector<Ptr>\
    \ come(N, nullptr);\n\n  used[root] = root;\n  vector<int> par_e(es.size(), -1),\
    \ stem(N, -1), idxs;\n\n  for (int i = 0; i < (int)es.size(); i++) {\n    auto\
    \ &e = es[i];\n    come[e] = Heap::push(come[e], e.cost, i);\n  }\n\n  T costs\
    \ = 0;\n\n  for (int start = 0; start < N; start++) {\n    if (used[start] !=\
    \ -1) continue;\n    int cur = start;\n    vector<int> chi_e;\n    int cycle =\
    \ 0;\n    while (used[cur] == -1 || used[cur] == start) {\n      used[cur] = start;\n\
    \      if (come[cur] == nullptr) return {};\n      int src = uf.find(es[come[cur]->idx].src);\n\
    \      T cost = come[cur]->key + come[cur]->laz;\n      int idx = come[cur]->idx;\n\
    \      come[cur] = Heap::pop(come[cur]);\n      if (src == cur) continue;\n\n\
    \      from[cur] = src;\n      from_cost[cur] = cost;\n      if (stem[cur] ==\
    \ -1) stem[cur] = idx;\n      costs += cost;\n      idxs.push_back(idx);\n   \
    \   while (cycle) {\n        par_e[chi_e.back()] = idx;\n        chi_e.pop_back();\n\
    \        --cycle;\n      }\n      chi_e.push_back(idx);\n\n      if (used[src]\
    \ == start) {\n        int p = cur;\n        do {\n          if (come[p]) Heap::apply(come[p],\
    \ -from_cost[p]);\n          if (p != cur) {\n            uf.unite(p, cur);\n\
    \            Ptr newheap = Heap::meld(come[cur], come[p]);\n            come[cur\
    \ = uf.find(cur)] = newheap;\n          }\n          p = uf.find(from[p]);\n \
    \         ++cycle;\n        } while (p != cur);\n      } else {\n        cur =\
    \ src;\n      }\n    }\n  }\n\n  vector<int> used_e(es.size());\n  Edges<T> res;\n\
    \  for (int _ = (int)idxs.size(); _--;) {\n    int idx = idxs[_];\n    if (used_e[idx])\
    \ continue;\n    auto &e = es[idx];\n    res.push_back(e);\n    int x = stem[e.to];\n\
    \    while (x != idx) {\n      used_e[x] = true;\n      x = par_e[x];\n    }\n\
    \  }\n  return res;\n}\n"
  code: "#pragma once\n\n#include \"../data-structure/skew-heap.hpp\"\n#include \"\
    ../data-structure/union-find.hpp\"\n#include \"graph-template.hpp\"\n\ntemplate\
    \ <typename T>\nEdges<T> MinimumCostArborescence(int N, int root, const Edges<T>\
    \ &es) {\n  using Heap = SkewHeap<T>;\n  using Ptr = typename Heap::Ptr;\n  UnionFind\
    \ uf(N);\n  vector<int> used(N, -1), from(N);\n  vector<T> from_cost(N);\n  vector<Ptr>\
    \ come(N, nullptr);\n\n  used[root] = root;\n  vector<int> par_e(es.size(), -1),\
    \ stem(N, -1), idxs;\n\n  for (int i = 0; i < (int)es.size(); i++) {\n    auto\
    \ &e = es[i];\n    come[e] = Heap::push(come[e], e.cost, i);\n  }\n\n  T costs\
    \ = 0;\n\n  for (int start = 0; start < N; start++) {\n    if (used[start] !=\
    \ -1) continue;\n    int cur = start;\n    vector<int> chi_e;\n    int cycle =\
    \ 0;\n    while (used[cur] == -1 || used[cur] == start) {\n      used[cur] = start;\n\
    \      if (come[cur] == nullptr) return {};\n      int src = uf.find(es[come[cur]->idx].src);\n\
    \      T cost = come[cur]->key + come[cur]->laz;\n      int idx = come[cur]->idx;\n\
    \      come[cur] = Heap::pop(come[cur]);\n      if (src == cur) continue;\n\n\
    \      from[cur] = src;\n      from_cost[cur] = cost;\n      if (stem[cur] ==\
    \ -1) stem[cur] = idx;\n      costs += cost;\n      idxs.push_back(idx);\n   \
    \   while (cycle) {\n        par_e[chi_e.back()] = idx;\n        chi_e.pop_back();\n\
    \        --cycle;\n      }\n      chi_e.push_back(idx);\n\n      if (used[src]\
    \ == start) {\n        int p = cur;\n        do {\n          if (come[p]) Heap::apply(come[p],\
    \ -from_cost[p]);\n          if (p != cur) {\n            uf.unite(p, cur);\n\
    \            Ptr newheap = Heap::meld(come[cur], come[p]);\n            come[cur\
    \ = uf.find(cur)] = newheap;\n          }\n          p = uf.find(from[p]);\n \
    \         ++cycle;\n        } while (p != cur);\n      } else {\n        cur =\
    \ src;\n      }\n    }\n  }\n\n  vector<int> used_e(es.size());\n  Edges<T> res;\n\
    \  for (int _ = (int)idxs.size(); _--;) {\n    int idx = idxs[_];\n    if (used_e[idx])\
    \ continue;\n    auto &e = es[idx];\n    res.push_back(e);\n    int x = stem[e.to];\n\
    \    while (x != idx) {\n      used_e[x] = true;\n      x = par_e[x];\n    }\n\
    \  }\n  return res;\n}\n"
  dependsOn:
  - data-structure/skew-heap.hpp
  - data-structure/union-find.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/minimum-cost-arborescence.hpp
  requiredBy: []
  timestamp: '2021-02-04 22:39:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
documentation_of: graph/minimum-cost-arborescence.hpp
layout: document
redirect_from:
- /library/graph/minimum-cost-arborescence.hpp
- /library/graph/minimum-cost-arborescence.hpp.html
title: graph/minimum-cost-arborescence.hpp
---
