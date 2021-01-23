---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-subtree.hpp
    title: "\u90E8\u5206\u6728\u30AF\u30A8\u30EALink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree.hpp
    title: Link/Cut Tree
  - icon: ':heavy_check_mark:'
    path: lct/splay-reversible.hpp
    title: "\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
    links: []
  bundledCode: "#line 2 \"lct/reversible-bbst-base.hpp\"\n\ntemplate <typename Tree,\
    \ typename Node, typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleBBST\
    \ : Tree {\n  using Tree::merge;\n  using Tree::split;\n  using typename Tree::Ptr;\n\
    \n  ReversibleBBST() = default;\n\n  virtual void toggle(Ptr t) {\n    swap(t->l,\
    \ t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  Ptr update(Ptr t)\
    \ override {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->key;\n \
    \   if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r)\
    \ t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n\
    \ protected:\n  inline T sum(const Ptr t) { return t ? t->sum : T(); }\n\n  void\
    \ push(Ptr t) override {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l)\
    \ toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n\
    \  }\n};\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
    (\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  code: "#pragma once\n\ntemplate <typename Tree, typename Node, typename T, T (*f)(T,\
    \ T), T (*ts)(T)>\nstruct ReversibleBBST : Tree {\n  using Tree::merge;\n  using\
    \ Tree::split;\n  using typename Tree::Ptr;\n\n  ReversibleBBST() = default;\n\
    \n  virtual void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
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
    \u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/reversible-bbst-base.hpp
  requiredBy:
  - lct/splay-reversible.hpp
  - lct/link-cut-tree.hpp
  - lct/link-cut-tree-subtree.hpp
  timestamp: '2020-12-17 20:54:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-subtree-sum.test.cpp
documentation_of: lct/reversible-bbst-base.hpp
layout: document
redirect_from:
- /library/lct/reversible-bbst-base.hpp
- /library/lct/reversible-bbst-base.hpp.html
title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\
  \u30B9)"
---
