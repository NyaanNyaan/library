---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lct/splay-reversible.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay\u6728"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\
      \u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)"
    links: []
  bundledCode: "#line 2 \"lct/reversible-bbst-base.hpp\"\n\ntemplate <typename Tree,\
    \ typename Node, typename T, T (*f)(T, T), T (*ts)(T)>\nstruct ReversibleBBST\
    \ : Tree {\n  using Tree::merge;\n  using Tree::split;\n  using typename Tree::Ptr;\n\
    \n  ReversibleBBST() = default;\n\n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n\
    \    t->sum = ts(t->sum);\n    t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a,\
    \ int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b - a);\n\
    \    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  void reverse(Ptr &t, int a, int b) {\n    auto x =\
    \ split(t, a);\n    auto y = split(x.second, b - a);\n    toggle(y.first);\n \
    \   t = merge(x.first, merge(y.first, y.second));\n  }\n\n  Ptr update(Ptr t)\
    \ override {\n    if (!t) return t;\n    push(t);\n    t->cnt = 1;\n    t->sum\
    \ = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n\
    \    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return\
    \ t;\n  }\n\n protected:\n  inline T sum(const Ptr t) { return t ? t->sum : T();\
    \ }\n\n  void push(Ptr t) override {\n    if (!t) return;\n    if (t->rev) {\n\
    \      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n      t->rev =\
    \ false;\n    }\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\
    \u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  code: "#pragma once\n\ntemplate <typename Tree, typename Node, typename T, T (*f)(T,\
    \ T), T (*ts)(T)>\nstruct ReversibleBBST : Tree {\n  using Tree::merge;\n  using\
    \ Tree::split;\n  using typename Tree::Ptr;\n\n  ReversibleBBST() = default;\n\
    \n  void toggle(Ptr t) {\n    swap(t->l, t->r);\n    t->sum = ts(t->sum);\n  \
    \  t->rev ^= true;\n  }\n\n  T fold(Ptr &t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  void\
    \ reverse(Ptr &t, int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second,\
    \ b - a);\n    toggle(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \  }\n\n  Ptr update(Ptr t) override {\n    if (!t) return t;\n    push(t);\n\
    \    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n    return t;\n  }\n\n protected:\n  inline T sum(const Ptr t)\
    \ { return t ? t->sum : T(); }\n\n  void push(Ptr t) override {\n    if (!t) return;\n\
    \    if (t->rev) {\n      if (t->l) toggle(t->l);\n      if (t->r) toggle(t->r);\n\
    \      t->rev = false;\n    }\n  }\n};\n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\
    \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\
    \u30B9)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: lct/reversible-bbst-base.hpp
  requiredBy:
  - lct/splay-reversible.hpp
  timestamp: '2020-12-16 23:51:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lct/reversible-bbst-base.hpp
layout: document
redirect_from:
- /library/lct/reversible-bbst-base.hpp
- /library/lct/reversible-bbst-base.hpp.html
title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
  (\u57FA\u5E95\u30AF\u30E9\u30B9)"
---
