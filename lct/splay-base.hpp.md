---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-lazy.hpp
    title: "\u9045\u5EF6\u4F1D\u642CLink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-subtree.hpp
    title: "\u90E8\u5206\u6728\u30AF\u30A8\u30EALink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree.hpp
    title: Link/Cut Tree
  - icon: ':heavy_check_mark:'
    path: lct/splay-lazy-reversible.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  - icon: ':heavy_check_mark:'
    path: lct/splay-reversible.hpp
    title: "\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Splay Tree(base)
    links: []
  bundledCode: "#line 2 \"lct/splay-base.hpp\"\n\ntemplate <typename Node>\nstruct\
    \ SplayTreeBase {\n  using Ptr = Node *;\n  template <typename... Args>\n  Ptr\
    \ my_new(const Args &... args) {\n    return new Node(args...);\n  }\n  void my_del(Ptr\
    \ p) { delete p; }\n\n  bool is_root(Ptr t) { return !(t->p) || (t->p->l != t\
    \ && t->p->r != t); }\n\n  int size(Ptr t) const { return count(t); }\n\n  void\
    \ splay(Ptr t) {\n    push(t);\n    while (!is_root(t)) {\n      Ptr q = t->p;\n\
    \      if (is_root(q)) {\n        push(q), push(t);\n        rot(t);\n      }\
    \ else {\n        Ptr r = q->p;\n        push(r), push(q), push(t);\n        if\
    \ (pos(q) == pos(t))\n          rot(q), rot(t);\n        else\n          rot(t),\
    \ rot(t);\n      }\n    }\n  }\n\n  Ptr get_left(Ptr t) {\n    while (t->l) push(t),\
    \ t = t->l;\n    return t;\n  }\n\n  Ptr get_right(Ptr t) {\n    while (t->r)\
    \ push(t), t = t->r;\n    return t;\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int\
    \ k) {\n    if (!t) return {nullptr, nullptr};\n    if (k == 0) return {nullptr,\
    \ t};\n    if (k == count(t)) return {t, nullptr};\n    push(t);\n    if (k <=\
    \ count(t->l)) {\n      auto x = split(t->l, k);\n      t->l = x.second;\n   \
    \   t->p = nullptr;\n      if (x.second) x.second->p = t;\n      return {x.first,\
    \ update(t)};\n    } else {\n      auto x = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = x.first;\n      t->p = nullptr;\n      if (x.first) x.first->p =\
    \ t;\n      return {update(t), x.second};\n    }\n  }\n\n  Ptr merge(Ptr l, Ptr\
    \ r) {\n    if (!l && !r) return nullptr;\n    if (!l) return splay(r), r;\n \
    \   if (!r) return splay(l), l;\n    splay(l), splay(r);\n    l = get_right(l);\n\
    \    splay(l);\n    l->r = r;\n    r->p = l;\n    update(l);\n    return l;\n\
    \  }\n\n  using Key = decltype(Node::key);\n  Ptr build(const vector<Key> &v)\
    \ { return build(0, v.size(), v); }\n  Ptr build(int l, int r, const vector<Key>\
    \ &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n    return merge(build(l, (l\
    \ + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\n  template <typename... Args>\n\
    \  void insert(Ptr &t, int k, const Args &... args) {\n    splay(t);\n    auto\
    \ x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)), x.second);\n\
    \  }\n\n  void erase(Ptr &t, int k) {\n    splay(t);\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    my_del(y.first);\n    t = merge(x.first,\
    \ y.second);\n  }\n\n  virtual Ptr update(Ptr t) = 0;\n\n protected:\n  inline\
    \ int count(Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr\
    \ t) = 0;\n\n  Ptr build(const vector<Ptr> &v) { return build(0, v.size(), v);\
    \ }\n\n  Ptr build(int l, int r, const vector<Ptr> &v) {\n    if (l + 1 >= r)\
    \ return v[l];\n    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1,\
    \ r, v));\n  }\n\n private:\n  inline int pos(Ptr t) {\n    if (t->p) {\n    \
    \  if (t->p->l == t) return -1;\n      if (t->p->r == t) return 1;\n    }\n  \
    \  return 0;\n  }\n\n  void rot(Ptr t) {\n    Ptr x = t->p, y = x->p;\n    if\
    \ (pos(t) == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n      t->r = x, x->p\
    \ = t;\n    } else {\n      if ((x->r = t->l)) t->l->p = x;\n      t->l = x, x->p\
    \ = t;\n    }\n    update(x), update(t);\n    if ((t->p = y)) {\n      if (y->l\
    \ == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n  }\n};\n\n/**\n * @brief\
    \ Splay Tree(base)\n */\n"
  code: "#pragma once\n\ntemplate <typename Node>\nstruct SplayTreeBase {\n  using\
    \ Ptr = Node *;\n  template <typename... Args>\n  Ptr my_new(const Args &... args)\
    \ {\n    return new Node(args...);\n  }\n  void my_del(Ptr p) { delete p; }\n\n\
    \  bool is_root(Ptr t) { return !(t->p) || (t->p->l != t && t->p->r != t); }\n\
    \n  int size(Ptr t) const { return count(t); }\n\n  void splay(Ptr t) {\n    push(t);\n\
    \    while (!is_root(t)) {\n      Ptr q = t->p;\n      if (is_root(q)) {\n   \
    \     push(q), push(t);\n        rot(t);\n      } else {\n        Ptr r = q->p;\n\
    \        push(r), push(q), push(t);\n        if (pos(q) == pos(t))\n         \
    \ rot(q), rot(t);\n        else\n          rot(t), rot(t);\n      }\n    }\n \
    \ }\n\n  Ptr get_left(Ptr t) {\n    while (t->l) push(t), t = t->l;\n    return\
    \ t;\n  }\n\n  Ptr get_right(Ptr t) {\n    while (t->r) push(t), t = t->r;\n \
    \   return t;\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n    if (!t) return\
    \ {nullptr, nullptr};\n    if (k == 0) return {nullptr, t};\n    if (k == count(t))\
    \ return {t, nullptr};\n    push(t);\n    if (k <= count(t->l)) {\n      auto\
    \ x = split(t->l, k);\n      t->l = x.second;\n      t->p = nullptr;\n      if\
    \ (x.second) x.second->p = t;\n      return {x.first, update(t)};\n    } else\
    \ {\n      auto x = split(t->r, k - count(t->l) - 1);\n      t->r = x.first;\n\
    \      t->p = nullptr;\n      if (x.first) x.first->p = t;\n      return {update(t),\
    \ x.second};\n    }\n  }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l && !r) return\
    \ nullptr;\n    if (!l) return splay(r), r;\n    if (!r) return splay(l), l;\n\
    \    splay(l), splay(r);\n    l = get_right(l);\n    splay(l);\n    l->r = r;\n\
    \    r->p = l;\n    update(l);\n    return l;\n  }\n\n  using Key = decltype(Node::key);\n\
    \  Ptr build(const vector<Key> &v) { return build(0, v.size(), v); }\n  Ptr build(int\
    \ l, int r, const vector<Key> &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args &...\
    \ args) {\n    splay(t);\n    auto x = split(t, k);\n    t = merge(merge(x.first,\
    \ my_new(args...)), x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    splay(t);\n\
    \    auto x = split(t, k);\n    auto y = split(x.second, 1);\n    my_del(y.first);\n\
    \    t = merge(x.first, y.second);\n  }\n\n  virtual Ptr update(Ptr t) = 0;\n\n\
    \ protected:\n  inline int count(Ptr t) const { return t ? t->cnt : 0; }\n\n \
    \ virtual void push(Ptr t) = 0;\n\n  Ptr build(const vector<Ptr> &v) { return\
    \ build(0, v.size(), v); }\n\n  Ptr build(int l, int r, const vector<Ptr> &v)\
    \ {\n    if (l + 1 >= r) return v[l];\n    return merge(build(l, (l + r) >> 1,\
    \ v), build((l + r) >> 1, r, v));\n  }\n\n private:\n  inline int pos(Ptr t) {\n\
    \    if (t->p) {\n      if (t->p->l == t) return -1;\n      if (t->p->r == t)\
    \ return 1;\n    }\n    return 0;\n  }\n\n  void rot(Ptr t) {\n    Ptr x = t->p,\
    \ y = x->p;\n    if (pos(t) == -1) {\n      if ((x->l = t->r)) t->r->p = x;\n\
    \      t->r = x, x->p = t;\n    } else {\n      if ((x->r = t->l)) t->l->p = x;\n\
    \      t->l = x, x->p = t;\n    }\n    update(x), update(t);\n    if ((t->p =\
    \ y)) {\n      if (y->l == x) y->l = t;\n      if (y->r == x) y->r = t;\n    }\n\
    \  }\n};\n\n/**\n * @brief Splay Tree(base)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/splay-base.hpp
  requiredBy:
  - lct/splay-lazy-reversible.hpp
  - lct/splay-reversible.hpp
  - lct/link-cut-tree.hpp
  - lct/link-cut-tree-subtree.hpp
  - lct/link-cut-tree-lazy.hpp
  timestamp: '2020-12-17 12:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
documentation_of: lct/splay-base.hpp
layout: document
redirect_from:
- /library/lct/splay-base.hpp
- /library/lct/splay-base.hpp.html
title: Splay Tree(base)
---
