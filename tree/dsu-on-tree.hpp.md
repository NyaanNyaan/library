---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
    title: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2995.test.cpp
    title: verify/verify-aoj-other/aoj-2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/dsu-on-tree.md
    document_title: DSU on Tree(Guni)
    links: []
  bundledCode: "#line 2 \"tree/dsu-on-tree.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ <typename T>\nEdges<T> esgraph([[maybe_unused]] int N, int M, int is_weighted\
    \ = true,\n                 bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 6 \"tree/dsu-on-tree.hpp\"\n\ntemplate <typename G>\nstruct DSUonTree\
    \ {\n private:\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, down, up;\n  int\
    \ idx_;\n  int root;\n\n  int dfs1(int cur, int par = -1) {\n    sub_sz[cur] =\
    \ 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur, int par = -1) {\n    euler[idx_] = cur;\n    down[cur] = idx_++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    up[cur] = idx_;\n  }\n\n public:\n  DSUonTree(G &_g,int _root = 0)\n\
    \      : g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        down(_g.size()),\n        up(_g.size()),\n        idx_(0),\n        root(_root)\
    \ {\n    dfs1(root);\n    dfs2(root);\n  }\n\n  int idx(int u) const { return\
    \ down[u]; }\n\n  template <typename UPDATE, typename QUERY, typename CLEAR, typename\
    \ RESET>\n  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset)\
    \ {\n    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = false) ->\
    \ void {\n      for (int i = 1; i < (int)g[cur].size(); i++)\n        if (g[cur][i]\
    \ != par) rc(rc, g[cur][i], cur, false);\n      if (sub_sz[cur] != 1) rc(rc, g[cur][0],\
    \ cur, true);\n      if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]];\
    \ i < up[cur]; i++) update(euler[i]);\n      update(cur);\n      query(cur);\n\
    \      if (!keep) {\n        for (int i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n\
    \        reset();\n      }\n      return;\n    };\n    dsu(dsu, root);\n  }\n\
    };\n\n/**\n * @brief DSU on Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\ntemplate\
    \ <typename G>\nstruct DSUonTree {\n private:\n  G &g;\n  int N;\n  vector<int>\
    \ sub_sz, euler, down, up;\n  int idx_;\n  int root;\n\n  int dfs1(int cur, int\
    \ par = -1) {\n    sub_sz[cur] = 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0]\
    \ == par) {\n      swap(g[cur][0], g[cur][1]);\n    }\n    for (auto &dst : g[cur])\
    \ {\n      if (dst == par) continue;\n      sub_sz[cur] += dfs1(dst, cur);\n \
    \     if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);\n    }\n    return\
    \ sub_sz[cur];\n  }\n\n  void dfs2(int cur, int par = -1) {\n    euler[idx_] =\
    \ cur;\n    down[cur] = idx_++;\n    for (auto &dst : g[cur]) {\n      if (dst\
    \ == par) continue;\n      dfs2(dst, cur);\n    }\n    up[cur] = idx_;\n  }\n\n\
    \ public:\n  DSUonTree(G &_g,int _root = 0)\n      : g(_g),\n        N(_g.size()),\n\
    \        sub_sz(_g.size()),\n        euler(_g.size()),\n        down(_g.size()),\n\
    \        up(_g.size()),\n        idx_(0),\n        root(_root) {\n    dfs1(root);\n\
    \    dfs2(root);\n  }\n\n  int idx(int u) const { return down[u]; }\n\n  template\
    \ <typename UPDATE, typename QUERY, typename CLEAR, typename RESET>\n  void run(UPDATE\
    \ &update, QUERY &query, CLEAR &clear, RESET &reset) {\n    auto dsu = [&](auto\
    \ rc, int cur, int par = -1, bool keep = false) -> void {\n      for (int i =\
    \ 1; i < (int)g[cur].size(); i++)\n        if (g[cur][i] != par) rc(rc, g[cur][i],\
    \ cur, false);\n      if (sub_sz[cur] != 1) rc(rc, g[cur][0], cur, true);\n  \
    \    if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]]; i < up[cur]; i++)\
    \ update(euler[i]);\n      update(cur);\n      query(cur);\n      if (!keep) {\n\
    \        for (int i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n        reset();\n\
    \      }\n      return;\n    };\n    dsu(dsu, root);\n  }\n};\n\n/**\n * @brief\
    \ DSU on Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/dsu-on-tree.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - verify/verify-aoj-other/aoj-2995.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
documentation_of: tree/dsu-on-tree.hpp
layout: document
redirect_from:
- /library/tree/dsu-on-tree.hpp
- /library/tree/dsu-on-tree.hpp.html
title: DSU on Tree(Guni)
---
## DSU on Tree

DSU on Treeとは、全ての部分木に対するクエリを高速に処理するアルゴリズムである。

#### 使い方&テンプレート

ライブラリと一緒に下のテンプレートを貼って使用する。

```
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g)> dsu(g, 0);
  dsu.run(update, query, clear, reset);
```

#### 概要

前に手元のメモに書いた落書きを貼る。


##### 参考にしたサイト
- [kimiyukiさんの解説。非常にわかりやすい](https://wiki.kimiyuki.net/DSU%20on%20tree)
- [CodeForcesの記事](https://codeforces.com/blog/entry/44351)
- [謎の記事](http://codingwithrajarshi.blogspot.com/2018/06/small-to-large.html)


##### 説明

Python風コードによるアルゴリズムの動作の説明を以下に示す。

```python=
# c ... current node
# p ... parent node
# keep ... condition variable of reserving data

def dsu(c, p, keep):
    # light edge -> run dfs and clear data
    for d in 'light edge of c':
        dsu(d, c, false)
    
    # heavy edge -> run dfs and reserve data
    dsu('heavy edge of c', c, true)
    
    # light edge -> reserve data
    for d in 'light edge of c':
        for n in 'subtree of d':
            add(n)
     
    # current node -> reserve data
    add(c)

    # answer queries related to subtree of current node
    query(c)

    # if keep is false, clear all data
    if keep = false:
          reset()
    return
```

##### 計算量
- add()を呼び出す回数を考える
- 各ノードがaddされる回数を考えるとそれぞれ$\rm O(\log N)$回
    - 全てのノードがdsu関数を1回ずつ実行
    - 関数内ではlight edgeでつながる子孫 + 自分をaddしている
    - よってノードがaddされる回数は$($根とのパスに存在するlight edgeの本数 + $1)$回
    - 重軽木の深さは$\rm O(\log N)$なので回数も同じ
- eraseされる回数はaddされる回数と同じ
- 以上より、全体の計算量はadd,eraseを$\rm O(1)$として$\rm O(N \log N)$

##### DSU on TreeとWeighted Union Heuristic(マージテク)の違い

- Weighted Union Heuristic…競プロで広く一般に使われるテクニック
- 大きい部分木を小さい部分木にマージすることで$\rm{O}(N \log N)$
- 例えば下のような問題

> 頂点$1$を根とする$N$頂点の根付き木がある。
> 木の頂点には数字$(1 \leq c \leq N)$が書かれている。
> 次のオフラインクエリを$Q$個処理せよ。
> $n\ x \ldots$ 頂点$n$を根とする部分木の全ての頂点のうち$x$の書かれた頂点の個数を出力。

- これはマージテクだと$\rm{O}(N \log N)$で解ける(実装も簡単だが、hash tableが必要)
    - DSU on Treeだと配列のみで$\rm O(N \log N)$が達成できる
    - [類題](https://codeforces.com/contest/600/problem/E)

```cpp=
int a[N]; // number of nodes
using M = unordered_map<int, int>;
M dp[N];

void merge(M &a, M &b) {
    if (a.size() < b.size()) swap(a, b);
    for (auto &x : b) a[x.first] += x.second;
}

void dfs(int c, int p) {
    dp[c][a[c]] += 1;
    for (auto &d : g[c]){
        if (d == p) continue;
        dfs(d, c);
        merge(dp[c], dp[d]);
    }
    // answer queries of subtree c
}
```

- ではこの問題は？

> 頂点$1$を根とする$N$頂点の根付き木がある。
> 木の頂点には数字$(1 \leq c \leq N)$が書かれている。
> 次のクエリを$Q$個処理せよ。
> $n\ x\ \ldots$ 頂点$n$を根とする部分木の全ての頂点のうち$x$<strong>以下</strong>の書かれた頂点個数を出力。
> 制約：$1 \leq N = Q \leq 200000$
- これをマージテクで解こうとすると...?
    1. hash mapをマージ
        + クエリが$\rm{O}($要素数$)$になり壊れる
    2. vectorをマージ(クエリを二分探索で処理)
        + マージが$\rm{O}($小さい方$)$にならない
    3. Segment Treeをノードごとに構築、一方hash mapでも頂点を管理
        hash mapをマージする時に小さい方のデータを大きい方のセグ木に反映
        + 一見うまくいきそうだが… 
        + セグ木の構築にノードごとに$\rm{O}(N)$かかるので最悪$\rm O(N^2)$
    4. 動的Segment Treeや平衡二分木をマージ
        + 構築 ノードごとに$\rm{O}(1)$か$\rm{O}(\log N)$
        + マージ 全体で$\rm{O}(N \log ^ 2 N)$
        + クエリ クエリごとに$\rm{O}(\log N)$
        + よって高速に動作する
        + ただし、最悪ケースで$\rm{O}(N)$個のセグ木が同時に構築される
    5. Heavy Light Decomposition + 4.の解法
        + heavyな部分木から動的セグ木を参照渡しでもらう
        + 同時に構築される動的セグ木の数は$\rm{O}(\log N)$個となり空間計算量が改善された

- 一方、DSU on Treeだとセグメント木1本で解ける(計算量は$\rm O(N \log ^2 N)$)
    - なおこの問題はEuler Tour + 領域木で$\rm{O}(N \log N)$と高速かつオンラインで解ける
    - 動的木のマージも実は工夫すると全体で$\rm O(N \log N)$らしい [(参考)](https://codeforces.com/blog/entry/49446)のでマージテク+永続セグ木でも$\rm O(N \log N)$か

- DSU on Treeのメリット
    + データ構造が一つでいい
        + メモリ確保の回数や空間計算量少ない分、高速なことが多いらしい(要出典)
    + ライブラリ化できる
        + 実装の手間が省けてありがたい

- DSU on Treeのデメリット
    + 値の追加だけでなく削除ができる必要がある
    + 削除が面倒な例: priority_queue
        + 初期状態に戻せば問題ないので、例えば
            `auto clear=[&](){};`
            `auto reset=[&](){Q.swap(priority_queue<int>());};`
            のようにすればよいが、1個のデータ構造で出来るというメリットが失われている
- 疑問：DSU on Treeで解けてマージテクで解けない問題(あるいはその逆)は存在するのか？
    - 存在しない気がする
    - それはそれとしてDSU on Treeの方が(ライブラリがあれば)簡単に書けそう
    - 親に返す時に操作が必要な場合は上記のライブラリでは対応できない？
