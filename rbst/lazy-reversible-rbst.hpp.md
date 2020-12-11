---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: rbst/rbst-base.hpp
    title: "\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/rbst/lazy-reversible-rbst.md
    document_title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\
      \u8861\u4E8C\u5206\u6728"
    links: []
  bundledCode: "#line 2 \"rbst/lazy-reversible-rbst.hpp\"\n\n#line 2 \"rbst/rbst-base.hpp\"\
    \n\ntemplate <typename Node>\nstruct RBSTBase {\n  using Ptr = Node *;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return new Node(args...);\n\
    \  }\n  inline Ptr make_tree() const { return nullptr; }\n\n  // for avoiding\
    \ memory leak, activate below\n  /*\n  using Ptr = shared_ptr<Node>;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return make_shared<Node>(args...);\n\
    \  }\n  Ptr make_tree() {return Ptr();}\n  */\n\n  int size(Ptr t) const { return\
    \ count(t); }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l :\
    \ r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      push(l);\n\
    \      l->r = merge(l->r, r);\n      return update(l);\n    } else {\n      push(r);\n\
    \      r->l = merge(l, r->l);\n      return update(r);\n    }\n  }\n\n  pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n\
    \    if (k <= count(t->l)) {\n      auto s = split(t->l, k);\n      t->l = s.second;\n\
    \      return {s.first, update(t)};\n    } else {\n      auto s = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  Ptr build(int l, int r, const vector<decltype(Node::key)> &v)\
    \ {\n    if (l + 1 == r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n   \
    \ Ptr pm = my_new(v[m]);\n    if (l < m) pm->l = build(l, m, v);\n    if (m +\
    \ 1 < r) pm->r = build(m + 1, r, v);\n    return update(pm);\n  }\n\n  Ptr build(const\
    \ vector<decltype(Node::key)> &v) {\n    return build(0, (int)v.size(), v);\n\
    \  }\n\n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args\
    \ &... args) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    auto x = split(t, k);\n\
    \    t = merge(x.first, split(x.second, 1).second);\n  }\n\n protected:\n  static\
    \ uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n    return\
    \ x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9), x_ & 0xFFFFFFFFull;\n  }\n\n  inline\
    \ int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr)\
    \ {}\n\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief \u4E71\u629E\u5E73\
    \u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"rbst/lazy-reversible-rbst.hpp\"\
    \n\ntemplate <typename T, typename E>\nstruct LazyReversibleRBSTNode {\n  typename\
    \ RBSTBase<LazyReversibleRBSTNode>::Ptr l, r;\n  T key, sum;\n  E lazy;\n  int\
    \ cnt;\n  bool rev;\n\n  LazyReversibleRBSTNode(const T &t = T(), const E &e =\
    \ E())\n      : l(), r(), key(t), sum(t), lazy(e), cnt(1), rev(false) {}\n};\n\
    \ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \          T (*ts)(T)>\nstruct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>> {\n  using Node = LazyReversibleRBSTNode<T, E>;\n  using base = RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>>;\n  using base::merge;\n  using base::split;\n  using typename base::Ptr;\n\
    \n  LazyReversibleRBST() = default;\n\n  void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  void apply(Ptr &t,\
    \ int a, int b, const E &e) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    propagate(y.first, e);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n protected:\n  inline T sum(const Ptr t) const { return t ? t->sum : T();\
    \ }\n\n  Ptr update(Ptr t) override {\n    push(t);\n    t->cnt = 1;\n    t->sum\
    \ = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return\
    \ t;\n  }\n\n  void push(Ptr t) override {\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \    if (t->lazy != E()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if\
    \ (t->r) propagate(t->r, t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void\
    \ propagate(Ptr t, const E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key,\
    \ x);\n    t->sum = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\
    \u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728\n * @docs\
    \ docs/rbst/lazy-reversible-rbst.md\n */\n"
  code: "#pragma once\n\n#include \"rbst-base.hpp\"\n\ntemplate <typename T, typename\
    \ E>\nstruct LazyReversibleRBSTNode {\n  typename RBSTBase<LazyReversibleRBSTNode>::Ptr\
    \ l, r;\n  T key, sum;\n  E lazy;\n  int cnt;\n  bool rev;\n\n  LazyReversibleRBSTNode(const\
    \ T &t = T(), const E &e = E())\n      : l(), r(), key(t), sum(t), lazy(e), cnt(1),\
    \ rev(false) {}\n};\n\ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T,\
    \ E), E (*h)(E, E),\n          T (*ts)(T)>\nstruct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>> {\n  using Node = LazyReversibleRBSTNode<T, E>;\n  using base = RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>>;\n  using base::merge;\n  using base::split;\n  using typename base::Ptr;\n\
    \n  LazyReversibleRBST() = default;\n\n  void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  void apply(Ptr &t,\
    \ int a, int b, const E &e) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    propagate(y.first, e);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n protected:\n  inline T sum(const Ptr t) const { return t ? t->sum : T();\
    \ }\n\n  Ptr update(Ptr t) override {\n    push(t);\n    t->cnt = 1;\n    t->sum\
    \ = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return\
    \ t;\n  }\n\n  void push(Ptr t) override {\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \    if (t->lazy != E()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if\
    \ (t->r) propagate(t->r, t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void\
    \ propagate(Ptr t, const E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key,\
    \ x);\n    t->sum = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\
    \u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728\n * @docs\
    \ docs/rbst/lazy-reversible-rbst.md\n */\n"
  dependsOn:
  - rbst/rbst-base.hpp
  isVerificationFile: false
  path: rbst/lazy-reversible-rbst.hpp
  requiredBy: []
  timestamp: '2020-12-11 17:45:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
documentation_of: rbst/lazy-reversible-rbst.hpp
layout: document
redirect_from:
- /library/rbst/lazy-reversible-rbst.hpp
- /library/rbst/lazy-reversible-rbst.hpp.html
title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\u4E8C\
  \u5206\u6728"
---
## 遅延伝搬反転可能乱択平衡二分木

強すぎてAtCoderRated出禁になった最強データ構造・平衡二分木のRBSTによる実装。

#### 使い方

計算量は木の大きさを$N$として表記している。

- `build(v)`: 列vを初期値とした新たな木を作る。$\mathrm{O}(N)$
- `merge(l, r)`: lとrをマージして新たに出来た木のポインタを返す。$\mathrm{O}(\log N)$
- `split(t, k)`: tを$[0,k)$と$[k, \lvert t\lvert)$の二つの木に分割する。$\mathrm{O}(\log N)$
- `insert(t, k, args...)`: tのk番目に`Node(args...)`を挿入する。$\mathrm{O}(\log N)$
- `erase(t, k)`: tのk番目のノードを削除する。$\mathrm{O}(\log N)$
- `fold(t, a, b)`: $[a,b)$の和を返す。$\mathrm{O}(\log N)$
- `apply(t, a, b, e)`: $[a, b)$に作用素eを作用させる。$\mathrm{O}(\log N)$
- `reverse(t, a, b)`:$[a, b)$を反転する。$\mathrm{O}(\log N)$
- `toggle(t)`: tを反転する。$\mathrm{O}(1)$
- `size(t)`: tの大きさを返す。$\mathrm{O}(1)$
- `make_tree()`: 空の木を返す。$\mathrm{O}(1)$
