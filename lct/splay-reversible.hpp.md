---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lct/reversible-bbst-base.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\
      \u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: lct/splay-base.hpp
    title: Splay Tree(base)
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree.hpp
    title: Link/Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-reverse-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-reverse-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53CD\u8EE2\u53EF\u80FDSplay Tree"
    links: []
  bundledCode: "#line 2 \"lct/splay-reversible.hpp\"\n\n#line 2 \"lct/reversible-bbst-base.hpp\"\
    \n\ntemplate <typename Tree, typename Node, typename T, T (*f)(T, T), T (*ts)(T)>\n\
    struct ReversibleBBST : Tree {\n  using Tree::merge;\n  using Tree::split;\n \
    \ using typename Tree::Ptr;\n\n  ReversibleBBST() = default;\n\n  virtual void\
    \ toggle(Ptr t) {\n    if(!t) return;\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
    \    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  Ptr update(Ptr t) override {\n    if (!t) return t;\n    t->cnt = 1;\n\
    \    t->sum = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum,\
    \ t->sum);\n    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n\
    \    return t;\n  }\n\n protected:\n  inline T sum(const Ptr t) { return t ? t->sum\
    \ : T(); }\n\n  void push(Ptr t) override {\n    if (!t) return;\n    if (t->rev)\
    \ {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev\
    \ = false;\n    }\n  }\n};\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\
    \u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 2 \"lct/splay-base.hpp\"\
    \n\ntemplate <typename Node>\nstruct SplayTreeBase {\n  using Ptr = Node *;\n\
    \  template <typename... Args>\n  Ptr my_new(const Args &...args) {\n    return\
    \ new Node(args...);\n  }\n  void my_del(Ptr p) { delete p; }\n\n  bool is_root(Ptr\
    \ t) { return !(t->p) || (t->p->l != t && t->p->r != t); }\n\n  int size(Ptr t)\
    \ const { return count(t); }\n\n  virtual void splay(Ptr t) {\n    if (!t) return;\n\
    \    push(t);\n    while (!is_root(t)) {\n      Ptr q = t->p;\n      if (is_root(q))\
    \ {\n        push(q), push(t);\n        rot(t);\n      } else {\n        Ptr r\
    \ = q->p;\n        push(r), push(q), push(t);\n        if (pos(q) == pos(t))\n\
    \          rot(q), rot(t);\n        else\n          rot(t), rot(t);\n      }\n\
    \    }\n  }\n\n  Ptr get_left(Ptr t) {\n    while (t->l) push(t), t = t->l;\n\
    \    return t;\n  }\n\n  Ptr get_right(Ptr t) {\n    while (t->r) push(t), t =\
    \ t->r;\n    return t;\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n    if\
    \ (!t) return {nullptr, nullptr};\n    if (k == 0) return {nullptr, t};\n    if\
    \ (k == count(t)) return {t, nullptr};\n    push(t);\n    if (k <= count(t->l))\
    \ {\n      auto x = split(t->l, k);\n      t->l = x.second;\n      t->p = nullptr;\n\
    \      if (x.second) x.second->p = t;\n      return {x.first, update(t)};\n  \
    \  } else {\n      auto x = split(t->r, k - count(t->l) - 1);\n      t->r = x.first;\n\
    \      t->p = nullptr;\n      if (x.first) x.first->p = t;\n      return {update(t),\
    \ x.second};\n    }\n  }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l && !r) return\
    \ nullptr;\n    if (!l) return splay(r), r;\n    if (!r) return splay(l), l;\n\
    \    splay(l), splay(r);\n    l = get_right(l);\n    splay(l);\n    l->r = r;\n\
    \    r->p = l;\n    update(l);\n    return l;\n  }\n\n  using Key = decltype(Node::key);\n\
    \  Ptr build(const vector<Key> &v) { return build(0, v.size(), v); }\n  Ptr build(int\
    \ l, int r, const vector<Key> &v) {\n    if (l == r) return nullptr;\n    if (l\
    \ + 1 == r) return my_new(v[l]);\n    return merge(build(l, (l + r) >> 1, v),\
    \ build((l + r) >> 1, r, v));\n  }\n\n  template <typename... Args>\n  void insert(Ptr\
    \ &t, int k, const Args &...args) {\n    splay(t);\n    auto x = split(t, k);\n\
    \    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n\n  void erase(Ptr\
    \ &t, int k) {\n    splay(t);\n    auto x = split(t, k);\n    auto y = split(x.second,\
    \ 1);\n    my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n  virtual\
    \ Ptr update(Ptr t) = 0;\n\n protected:\n  inline int count(Ptr t) const { return\
    \ t ? t->cnt : 0; }\n\n  virtual void push(Ptr t) = 0;\n\n  Ptr build(const vector<Ptr>\
    \ &v) { return build(0, v.size(), v); }\n\n  Ptr build(int l, int r, const vector<Ptr>\
    \ &v) {\n    if (l + 1 >= r) return v[l];\n    return merge(build(l, (l + r) >>\
    \ 1, v), build((l + r) >> 1, r, v));\n  }\n\n  inline int pos(Ptr t) {\n    if\
    \ (t->p) {\n      if (t->p->l == t) return -1;\n      if (t->p->r == t) return\
    \ 1;\n    }\n    return 0;\n  }\n\n  virtual void rot(Ptr t) {\n    Ptr x = t->p,\
    \ y = x->p;\n    if (pos(t) == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n\
    \      t->r = x, x->p = t;\n    } else {\n      if ((x->r = t->l)) t->l->p = x;\n\
    \      t->l = x, x->p = t;\n    }\n    update(x), update(t);\n    if ((t->p =\
    \ y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n\
    \  }\n};\n\n/**\n * @brief Splay Tree(base)\n */\n#line 5 \"lct/splay-reversible.hpp\"\
    \n\ntemplate <typename T>\nstruct ReversibleSplayTreeNode {\n  using Ptr = ReversibleSplayTreeNode\
    \ *;\n  Ptr l, r, p;\n  T key, sum;\n  int cnt;\n  bool rev;\n\n  ReversibleSplayTreeNode(const\
    \ T &t = T())\n      : l(), r(), p(), key(t), sum(t), cnt(1), rev(false) {}\n\
    };\n\ntemplate <typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleSplayTree\n\
    \    : ReversibleBBST<SplayTreeBase<ReversibleSplayTreeNode<T>>,\n           \
    \          ReversibleSplayTreeNode<T>, T, f, ts> {\n  using Node = ReversibleSplayTreeNode<T>;\n\
    };\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FDSplay Tree\n */\n"
  code: "#pragma once\n\n#include \"reversible-bbst-base.hpp\"\n#include \"splay-base.hpp\"\
    \n\ntemplate <typename T>\nstruct ReversibleSplayTreeNode {\n  using Ptr = ReversibleSplayTreeNode\
    \ *;\n  Ptr l, r, p;\n  T key, sum;\n  int cnt;\n  bool rev;\n\n  ReversibleSplayTreeNode(const\
    \ T &t = T())\n      : l(), r(), p(), key(t), sum(t), cnt(1), rev(false) {}\n\
    };\n\ntemplate <typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleSplayTree\n\
    \    : ReversibleBBST<SplayTreeBase<ReversibleSplayTreeNode<T>>,\n           \
    \          ReversibleSplayTreeNode<T>, T, f, ts> {\n  using Node = ReversibleSplayTreeNode<T>;\n\
    };\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FDSplay Tree\n */\n"
  dependsOn:
  - lct/reversible-bbst-base.hpp
  - lct/splay-base.hpp
  isVerificationFile: false
  path: lct/splay-reversible.hpp
  requiredBy:
  - lct/link-cut-tree.hpp
  timestamp: '2023-08-10 18:41:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-reverse-range-sum.test.cpp
documentation_of: lct/splay-reversible.hpp
layout: document
redirect_from:
- /library/lct/splay-reversible.hpp
- /library/lct/splay-reversible.hpp.html
title: "\u53CD\u8EE2\u53EF\u80FDSplay Tree"
---
