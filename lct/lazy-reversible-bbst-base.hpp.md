---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lct/link-cut-tree-lazy.hpp
    title: "\u9045\u5EF6\u4F1D\u642CLink/Cut Tree"
  - icon: ':heavy_check_mark:'
    path: lct/splay-lazy-reversible.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\
      \u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)"
    links: []
  bundledCode: "#line 2 \"lct/lazy-reversible-bbst-base.hpp\"\n\ntemplate <typename\
    \ Tree, typename Node, typename T, typename E, T (*f)(T, T),\n          T (*g)(T,\
    \ E), E (*h)(E, E), T (*ts)(T)>\nstruct LazyReversibleBBST : Tree {\n  using Tree::merge;\n\
    \  using Tree::split;\n  using typename Tree::Ptr;\n\n  LazyReversibleBBST() =\
    \ default;\n\n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n\
    \    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  void apply(Ptr &t, int a, int b, const E &e) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    propagate(y.first, e);\n    t\
    \ = merge(x.first, merge(y.first, y.second));\n  }\n\n protected:\n  inline T\
    \ sum(const Ptr t) { return t ? t->sum : T(); }\n\n  Ptr update(Ptr t) override\
    \ {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void push(Ptr\
    \ t) override {\n    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n\
    \      if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n    if (t->lazy\
    \ != E()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if (t->r) propagate(t->r,\
    \ t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void propagate(Ptr t, const\
    \ E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key, x);\n    t->sum\
    \ = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
    \u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  code: "#pragma once\n\ntemplate <typename Tree, typename Node, typename T, typename\
    \ E, T (*f)(T, T),\n          T (*g)(T, E), E (*h)(E, E), T (*ts)(T)>\nstruct\
    \ LazyReversibleBBST : Tree {\n  using Tree::merge;\n  using Tree::split;\n  using\
    \ typename Tree::Ptr;\n\n  LazyReversibleBBST() = default;\n\n  void toggle(Ptr\
    \ t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n    t->rev ^= true;\n\
    \  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto\
    \ y = split(x.second, b - a);\n    auto ret = sum(y.first);\n    t = merge(x.first,\
    \ merge(y.first, y.second));\n    return ret;\n  }\n\n  void reverse(Ptr &t, int\
    \ a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b - a);\n\
    \    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n  }\n\
    \n  void apply(Ptr &t, int a, int b, const E &e) {\n    auto x = split(t, a);\n\
    \    auto y = split(x.second, b - a);\n    propagate(y.first, e);\n    t = merge(x.first,\
    \ merge(y.first, y.second));\n  }\n\n protected:\n  inline T sum(const Ptr t)\
    \ { return t ? t->sum : T(); }\n\n  Ptr update(Ptr t) override {\n    if (!t)\
    \ return t;\n    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l) t->cnt += t->l->cnt,\
    \ t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt += t->r->cnt, t->sum =\
    \ f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void push(Ptr t) override {\n\
    \    if (!t) return;\n    if (t->rev) {\n      if (t->l) toggle(t->l);\n     \
    \ if (t->r) toggle(t->r);\n      t->rev = false;\n    }\n    if (t->lazy != E())\
    \ {\n      if (t->l) propagate(t->l, t->lazy);\n      if (t->r) propagate(t->r,\
    \ t->lazy);\n      t->lazy = E();\n    }\n  }\n\n  void propagate(Ptr t, const\
    \ E &x) {\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key, x);\n    t->sum\
    \ = g(t->sum, x);\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
    \u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/lazy-reversible-bbst-base.hpp
  requiredBy:
  - lct/splay-lazy-reversible.hpp
  - lct/link-cut-tree-lazy.hpp
  timestamp: '2020-12-17 12:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
documentation_of: lct/lazy-reversible-bbst-base.hpp
layout: document
redirect_from:
- /library/lct/lazy-reversible-bbst-base.hpp
- /library/lct/lazy-reversible-bbst-base.hpp.html
title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
  (\u57FA\u5E95\u30AF\u30E9\u30B9)"
---
