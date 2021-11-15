---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: orderedmap/orderedmap-base.hpp
    title: "Ordered Set(base)\u3000(\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: orderedmap/orderedmap.hpp
    title: "Ordered Map(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: rbst/lazy-reversible-rbst.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\
      \u4E8C\u5206\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/orderedmap.test.cpp
    title: verify/verify-unit-test/orderedmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\
      \u30E9\u30B9)"
    links: []
  bundledCode: "#line 2 \"rbst/rbst-base.hpp\"\n\ntemplate <typename Node>\nstruct\
    \ RBSTBase {\n  using Ptr = Node *;\n  template <typename... Args>\n  inline Ptr\
    \ my_new(Args... args) {\n    return new Node(args...);\n  }\n  inline void my_del(Ptr\
    \ t) { delete t; }\n  inline Ptr make_tree() const { return nullptr; }\n\n  //\
    \ for avoiding memory leak, activate below\n  /*\n  using Ptr = shared_ptr<Node>;\n\
    \  template <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return\
    \ make_shared<Node>(args...);\n  }\n  inline void my_del(Ptr t) {}\n  Ptr make_tree()\
    \ {return Ptr();}\n  */\n\n  int size(Ptr t) const { return count(t); }\n\n  Ptr\
    \ merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r,\
    \ r);\n      return update(l);\n    } else {\n      push(r);\n      r->l = merge(l,\
    \ r->l);\n      return update(r);\n    }\n  }\n\n  pair<Ptr, Ptr> split(Ptr t,\
    \ int k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k <=\
    \ count(t->l)) {\n      auto s = split(t->l, k);\n      t->l = s.second;\n   \
    \   return {s.first, update(t)};\n    } else {\n      auto s = split(t->r, k -\
    \ count(t->l) - 1);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  Ptr build(int l, int r, const vector<decltype(Node::key)> &v)\
    \ {\n    if (l + 1 == r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n   \
    \ Ptr pm = my_new(v[m]);\n    if (l < m) pm->l = build(l, m, v);\n    if (m +\
    \ 1 < r) pm->r = build(m + 1, r, v);\n    return update(pm);\n  }\n\n  Ptr build(const\
    \ vector<decltype(Node::key)> &v) {\n    return build(0, (int)v.size(), v);\n\
    \  }\n\n  template <typename... Args>\n  void insert(Ptr &t, int k, const Args\
    \ &... args) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(args...)),\
    \ x.second);\n  }\n\n  void erase(Ptr &t, int k) {\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    my_del(y.first);\n    t = merge(x.first,\
    \ y.second);\n  }\n\n protected:\n  static uint64_t rng() {\n    static uint64_t\
    \ x_ = 88172645463325252ULL;\n    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n\
    \  }\n\n  inline int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n \
    \ virtual void push(Ptr) = 0;\n\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n *\
    \ @brief \u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n"
  code: "#pragma once\n\ntemplate <typename Node>\nstruct RBSTBase {\n  using Ptr\
    \ = Node *;\n  template <typename... Args>\n  inline Ptr my_new(Args... args)\
    \ {\n    return new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete\
    \ t; }\n  inline Ptr make_tree() const { return nullptr; }\n\n  // for avoiding\
    \ memory leak, activate below\n  /*\n  using Ptr = shared_ptr<Node>;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return make_shared<Node>(args...);\n\
    \  }\n  inline void my_del(Ptr t) {}\n  Ptr make_tree() {return Ptr();}\n  */\n\
    \n  int size(Ptr t) const { return count(t); }\n\n  Ptr merge(Ptr l, Ptr r) {\n\
    \    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt))\
    \ >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n      return\
    \ update(l);\n    } else {\n      push(r);\n      r->l = merge(l, r->l);\n   \
    \   return update(r);\n    }\n  }\n\n  pair<Ptr, Ptr> split(Ptr t, int k) {\n\
    \    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\n  Ptr\
    \ build(int l, int r, const vector<decltype(Node::key)> &v) {\n    if (l + 1 ==\
    \ r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n    Ptr pm = my_new(v[m]);\n\
    \    if (l < m) pm->l = build(l, m, v);\n    if (m + 1 < r) pm->r = build(m +\
    \ 1, r, v);\n    return update(pm);\n  }\n\n  Ptr build(const vector<decltype(Node::key)>\
    \ &v) {\n    return build(0, (int)v.size(), v);\n  }\n\n  template <typename...\
    \ Args>\n  void insert(Ptr &t, int k, const Args &... args) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n\n  void\
    \ erase(Ptr &t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second,\
    \ 1);\n    my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n protected:\n\
    \  static uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n \
    \   return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  inline\
    \ int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  virtual void push(Ptr)\
    \ = 0;\n\n  virtual Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief \u4E71\u629E\u5E73\
    \u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: rbst/rbst-base.hpp
  requiredBy:
  - orderedmap/orderedmap-base.hpp
  - orderedmap/orderedmap.hpp
  - rbst/lazy-reversible-rbst.hpp
  timestamp: '2020-12-17 01:20:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
  - verify/verify-unit-test/orderedmap.test.cpp
documentation_of: rbst/rbst-base.hpp
layout: document
redirect_from:
- /library/rbst/rbst-base.hpp
- /library/rbst/rbst-base.hpp.html
title: "\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)"
---
