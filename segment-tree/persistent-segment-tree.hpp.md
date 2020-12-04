---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure-2d/rectangle-sum.hpp
    title: "\u77E9\u5F62\u548C(\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/persistent-segtree.md
    document_title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"segment-tree/persistent-segment-tree.hpp\"\n\n\n\ntemplate\
    \ <typename T, typename F, int NODES = 20000000>\nstruct PersistentSegmentTree\
    \ {\n  using ll = long long;\n  struct Node {\n    T data;\n    Node *l, *r;\n\
    \    Node() {}\n    Node(const T &_data) : data(_data), l(nullptr), r(nullptr)\
    \ {}\n  };\n\n  Node *pool;\n  int pid;\n  ll N;\n  const F f;\n  const T ID;\n\
    \  Node *nil;\n  vector<Node *> roots;\n\n  PersistentSegmentTree(const vector<T>\
    \ &v, const F &f_, const T &ID_)\n      : pid(0), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(build(v));\n  }\n\n  PersistentSegmentTree(const\
    \ ll &N_, const F &f_, const T &ID_)\n      : pid(0), N(N_), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(nil);\n  }\n\n  Node *my_new(const\
    \ T &data) {\n    pool[pid].data = data;\n    pool[pid].l = pool[pid].r = nil;\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *merge(Node *l, Node *r) {\n    pool[pid].data\
    \ = f(l->data, r->data);\n    pool[pid].l = l;\n    pool[pid].r = r;\n    return\
    \ &(pool[pid++]);\n  }\n\n  Node *build(const vector<T> &v) {\n    N = (ll)v.size();\n\
    \    return build(0, (ll)v.size(), v);\n  }\n\n  Node *build(ll l, ll r, const\
    \ vector<T> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n    ll m = (l + r)\
    \ >> 1;\n    return merge(build(l, m, v), build(m, r, v));\n  }\n\n private:\n\
    \  Node *update_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 == r)\
    \ return my_new(x);\n    ll m = (l + r) >> 1;\n    if (a < m) return merge(update_(a,\
    \ x, n->l, l, m), n->r);\n    return merge(n->l, update_(a, x, n->r, m, r));\n\
    \  }\n  Node *add_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 ==\
    \ r) return my_new(f(x, n->data));\n    ll m = (l + r) >> 1;\n    if (a < m) return\
    \ merge(add_(a, x, n->l, l, m), n->r);\n    return merge(n->l, add_(a, x, n->r,\
    \ m, r));\n  }\n  T query_(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil)\
    \ return ID;\n    if (r <= a or b <= l) return ID;\n    if (a <= l and r <= b)\
    \ return n->data;\n    ll m = (l + r) >> 1;\n    return f(query_(a, b, n->l, l,\
    \ m), query_(a, b, n->r, m, r));\n  }\n\n public:\n  Node *update(Node *n, ll\
    \ k, const T &x) {\n    Node *root = update_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *update(int t, ll k, const T &x) {\n    Node *root\
    \ = update_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *update(ll k, const T &x) {\n    Node *root = update_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  Node *add(Node\
    \ *n, ll k, const T &x) {\n    Node *root = add_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *add(int t, ll k, const T &x) {\n    Node *root\
    \ = add_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *add(ll k, const T &x) {\n    Node *root = add_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  T query(Node\
    \ *n, ll a, ll b) { return query_(a, b, n, 0, N); }\n  T query(int t, ll a, ll\
    \ b) { return query_(a, b, roots[t], 0, N); }\n  T query(ll a, ll b) { return\
    \ query_(a, b, roots.back(), 0, N); }\n\n  Node *new_tree() { return nil; }\n\
    };\n\n/**\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs\
    \ docs/segment-tree/persistent-segtree.md\n */\n"
  code: "#pragma once\n\n\n\ntemplate <typename T, typename F, int NODES = 20000000>\n\
    struct PersistentSegmentTree {\n  using ll = long long;\n  struct Node {\n   \
    \ T data;\n    Node *l, *r;\n    Node() {}\n    Node(const T &_data) : data(_data),\
    \ l(nullptr), r(nullptr) {}\n  };\n\n  Node *pool;\n  int pid;\n  ll N;\n  const\
    \ F f;\n  const T ID;\n  Node *nil;\n  vector<Node *> roots;\n\n  PersistentSegmentTree(const\
    \ vector<T> &v, const F &f_, const T &ID_)\n      : pid(0), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(build(v));\n  }\n\n  PersistentSegmentTree(const\
    \ ll &N_, const F &f_, const T &ID_)\n      : pid(0), N(N_), f(f_), ID(ID_), nil(nullptr)\
    \ {\n    pool = new Node[NODES];\n    nil = my_new(ID);\n    nil->l = nil->r =\
    \ nil;\n    roots.reserve(262144);\n    roots.push_back(nil);\n  }\n\n  Node *my_new(const\
    \ T &data) {\n    pool[pid].data = data;\n    pool[pid].l = pool[pid].r = nil;\n\
    \    return &(pool[pid++]);\n  }\n\n  Node *merge(Node *l, Node *r) {\n    pool[pid].data\
    \ = f(l->data, r->data);\n    pool[pid].l = l;\n    pool[pid].r = r;\n    return\
    \ &(pool[pid++]);\n  }\n\n  Node *build(const vector<T> &v) {\n    N = (ll)v.size();\n\
    \    return build(0, (ll)v.size(), v);\n  }\n\n  Node *build(ll l, ll r, const\
    \ vector<T> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n    ll m = (l + r)\
    \ >> 1;\n    return merge(build(l, m, v), build(m, r, v));\n  }\n\n private:\n\
    \  Node *update_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 == r)\
    \ return my_new(x);\n    ll m = (l + r) >> 1;\n    if (a < m) return merge(update_(a,\
    \ x, n->l, l, m), n->r);\n    return merge(n->l, update_(a, x, n->r, m, r));\n\
    \  }\n  Node *add_(ll a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 ==\
    \ r) return my_new(f(x, n->data));\n    ll m = (l + r) >> 1;\n    if (a < m) return\
    \ merge(add_(a, x, n->l, l, m), n->r);\n    return merge(n->l, add_(a, x, n->r,\
    \ m, r));\n  }\n  T query_(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil)\
    \ return ID;\n    if (r <= a or b <= l) return ID;\n    if (a <= l and r <= b)\
    \ return n->data;\n    ll m = (l + r) >> 1;\n    return f(query_(a, b, n->l, l,\
    \ m), query_(a, b, n->r, m, r));\n  }\n\n public:\n  Node *update(Node *n, ll\
    \ k, const T &x) {\n    Node *root = update_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *update(int t, ll k, const T &x) {\n    Node *root\
    \ = update_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *update(ll k, const T &x) {\n    Node *root = update_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  Node *add(Node\
    \ *n, ll k, const T &x) {\n    Node *root = add_(k, x, n, 0, N);\n    roots.push_back(root);\n\
    \    return root;\n  }\n  Node *add(int t, ll k, const T &x) {\n    Node *root\
    \ = add_(k, x, roots[t], 0, N);\n    roots.push_back(root);\n    return root;\n\
    \  }\n  Node *add(ll k, const T &x) {\n    Node *root = add_(k, x, roots.back(),\
    \ 0, N);\n    roots.push_back(root);\n    return root;\n  }\n\n  T query(Node\
    \ *n, ll a, ll b) { return query_(a, b, n, 0, N); }\n  T query(int t, ll a, ll\
    \ b) { return query_(a, b, roots[t], 0, N); }\n  T query(ll a, ll b) { return\
    \ query_(a, b, roots.back(), 0, N); }\n\n  Node *new_tree() { return nil; }\n\
    };\n\n/**\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs\
    \ docs/segment-tree/persistent-segtree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/persistent-segment-tree.hpp
  requiredBy:
  - data-structure-2d/rectangle-sum.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
documentation_of: segment-tree/persistent-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/persistent-segment-tree.hpp
- /library/segment-tree/persistent-segment-tree.hpp.html
title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 永続セグメント木(Persistent Segment Tree)

永続セグメント木とはセグメント木を完全永続化したデータ構造である。完全永続化とは、更新をする時に更新前のデータを残したり、最新でないデータを元として更新したりできるようにすることである。

複雑な割にほとんど使わないので忘れないうちに使い方を簡単にメモ。

#### 使い方
- `PersistentSegmentTree(v, f, ID)`:= 要素を$v$、マージ関数を$f$とする木を作成する。(fはモノイドである必要がある。)
- `update,add,query`は通常のセグ木と同様だが、使用方法に応じてそれぞれ3種類の関数が存在する。
  - `update(Node *n, k, x)` := nを根とする木を更新元とする。
  - `update(int t, k, x)`:= t回目の更新の後の木を更新元とする。
  - `update(k, x)` := 最新の木を更新元とする。
- `new_tree()` := 空の木を返す