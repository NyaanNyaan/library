---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/persistent-segment-tree.hpp
    title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/rectangle-sum.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"segment-tree/persistent-segment-tree.hpp\"\n\
    using namespace std;\n\ntemplate <typename T, typename F, int NODES = 20000000>\n\
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
    \ docs/segment-tree/persistent-segtree.md\n */\n#line 6 \"data-structure/rectangle-sum.hpp\"\
    \n\ntemplate <typename T, typename U, typename F>\nstruct RectangleSum {\n  PersistentSegmentTree<U,\
    \ F> seg;\n  vector<T> xs, ys;\n  vector<U> ws;\n  vector<int> ord;\n\n  RectangleSum(const\
    \ vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,\n              \
    \ const F &f)\n      : seg({(int)xs_.size() + 1, f, U(0)}) {\n    int N = xs_.size();\n\
    \    xs.reserve(N);\n    ys.reserve(N);\n    ws.reserve(N);\n    ord.resize(N);\n\
    \    iota(begin(ord), end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i,\
    \ int j) { return xs_[i] < xs_[j]; });\n    for (auto &i : ord) {\n      xs.push_back(xs_[i]);\n\
    \      ys.push_back(ys_[i]);\n      ws.push_back(ws_[i]);\n    }\n    iota(begin(ord),\
    \ end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i]\
    \ < ys[j]; });\n    vector<T> ys2;\n    ys2.reserve(N);\n    for (auto &i : ord)\
    \ {\n      seg.add(i, ws[i]);\n      ys2.push_back(ys[i]);\n    }\n    ys.swap(ys2);\n\
    \  }\n\n  // [ [x1, 0], [x2, y] )\n  U rect_sum(T x1, T x2, T y) {\n    int l\
    \ = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int r = lower_bound(begin(xs),\
    \ end(xs), x2) - begin(xs);\n    int u = lower_bound(begin(ys), end(ys), y) -\
    \ begin(ys);\n    return seg.query(u, l, r);\n  }\n\n  // [ [x1, y1], [x2, y2]\
    \ )\n  U rect_sum(T x1, T y1, T x2, T y2) {\n    if (x1 >= x2 || y1 >= y2) return\
    \ U(0);\n    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int\
    \ r = lower_bound(begin(xs), end(xs), x2) - begin(xs);\n    int d = lower_bound(begin(ys),\
    \ end(ys), y1) - begin(ys);\n    int u = lower_bound(begin(ys), end(ys), y2) -\
    \ begin(ys);\n    return seg.query(u, l, r) - seg.query(d, l, r);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../segment-tree/persistent-segment-tree.hpp\"\n\ntemplate <typename T, typename\
    \ U, typename F>\nstruct RectangleSum {\n  PersistentSegmentTree<U, F> seg;\n\
    \  vector<T> xs, ys;\n  vector<U> ws;\n  vector<int> ord;\n\n  RectangleSum(const\
    \ vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,\n              \
    \ const F &f)\n      : seg({(int)xs_.size() + 1, f, U(0)}) {\n    int N = xs_.size();\n\
    \    xs.reserve(N);\n    ys.reserve(N);\n    ws.reserve(N);\n    ord.resize(N);\n\
    \    iota(begin(ord), end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i,\
    \ int j) { return xs_[i] < xs_[j]; });\n    for (auto &i : ord) {\n      xs.push_back(xs_[i]);\n\
    \      ys.push_back(ys_[i]);\n      ws.push_back(ws_[i]);\n    }\n    iota(begin(ord),\
    \ end(ord), 0);\n    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i]\
    \ < ys[j]; });\n    vector<T> ys2;\n    ys2.reserve(N);\n    for (auto &i : ord)\
    \ {\n      seg.add(i, ws[i]);\n      ys2.push_back(ys[i]);\n    }\n    ys.swap(ys2);\n\
    \  }\n\n  // [ [x1, 0], [x2, y] )\n  U rect_sum(T x1, T x2, T y) {\n    int l\
    \ = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int r = lower_bound(begin(xs),\
    \ end(xs), x2) - begin(xs);\n    int u = lower_bound(begin(ys), end(ys), y) -\
    \ begin(ys);\n    return seg.query(u, l, r);\n  }\n\n  // [ [x1, y1], [x2, y2]\
    \ )\n  U rect_sum(T x1, T y1, T x2, T y2) {\n    if (x1 >= x2 || y1 >= y2) return\
    \ U(0);\n    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);\n    int\
    \ r = lower_bound(begin(xs), end(xs), x2) - begin(xs);\n    int d = lower_bound(begin(ys),\
    \ end(ys), y1) - begin(ys);\n    int u = lower_bound(begin(ys), end(ys), y2) -\
    \ begin(ys);\n    return seg.query(u, l, r) - seg.query(d, l, r);\n  }\n};"
  dependsOn:
  - segment-tree/persistent-segment-tree.hpp
  isVerificationFile: false
  path: data-structure/rectangle-sum.hpp
  requiredBy: []
  timestamp: '2020-08-20 12:40:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp
documentation_of: data-structure/rectangle-sum.hpp
layout: document
redirect_from:
- /library/data-structure/rectangle-sum.hpp
- /library/data-structure/rectangle-sum.hpp.html
title: data-structure/rectangle-sum.hpp
---
