---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: orderedmap/orderedmap-base.hpp
    title: "Ordered Set(base)\u3000(\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: rbst/rbst-base.hpp
    title: "\u4E71\u629E\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/orderedmap.test.cpp
    title: verify/verify-unit-test/orderedmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Ordered Map(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
    links: []
  bundledCode: "#line 2 \"orderedmap/orderedmap.hpp\"\n\n#line 2 \"orderedmap/orderedmap-base.hpp\"\
    \n\n#line 2 \"rbst/rbst-base.hpp\"\n\ntemplate <typename Node>\nstruct RBSTBase\
    \ {\n  using Ptr = Node *;\n  template <typename... Args>\n  inline Ptr my_new(Args...\
    \ args) {\n    return new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete\
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
    \u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"orderedmap/orderedmap-base.hpp\"\
    \n\ntemplate <typename Node, bool multi>\nstruct OrderedMapBase : RBSTBase<Node>\
    \ {\n  using base = RBSTBase<Node>;\n  using Ptr = typename base::Ptr;\n  using\
    \ Key = decltype(Node::key);\n\n  Ptr root;\n  OrderedMapBase() : root(base::make_tree())\
    \ {}\n\n  Ptr find(const Key& k) const {\n    Ptr p = root;\n    while (p) {\n\
    \      if (k == p->key) return p;\n      p = k < p->key ? p->l : p->r;\n    }\n\
    \    return base::make_tree();\n  }\n\n  int lower_bound(const Key& k) const {\n\
    \    Ptr p = root;\n    int ret = 0;\n    while (p) {\n      if (k <= p->key)\
    \ {\n        p = p->l;\n      } else {\n        ret += base::count(p->l) + 1;\n\
    \        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int upper_bound(const\
    \ Key& k) const {\n    Ptr p = root;\n    int ret = 0;\n    while (p) {\n    \
    \  if (k < p->key) {\n        p = p->l;\n      } else {\n        ret += base::count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    return ret;\n  }\n\n  int count(const\
    \ Key& k) const {\n    if constexpr (multi) {\n      return upper_bound(k) - lower_bound(k);\n\
    \    } else {\n      return !!find(k);\n    }\n  }\n\n  Ptr kth_element(int k)\
    \ const {\n    Ptr p = root;\n    while (p) {\n      int lc = base::count(p->l);\n\
    \      if (lc == k) return p;\n      if (k < lc) {\n        p = p->l;\n      }\
    \ else {\n        k -= lc + 1;\n        p = p->r;\n      }\n    }\n    return\
    \ p;\n  }\n\n  void erase(const Key& k) {\n    Ptr p = root;\n    int ret = 0;\n\
    \    bool flg = false;\n    while (p) {\n      if (k == p->key) flg = true;\n\
    \      if (k <= p->key) {\n        p = p->l;\n      } else {\n        ret += base::count(p->l)\
    \ + 1;\n        p = p->r;\n      }\n    }\n    if (flg) base::erase(root, ret);\n\
    \  }\n\n  void erase(Ptr p) { erase(p->key); }\n\n  int size() const { return\
    \ base::size(root); }\n\n protected:\n\n  void push(Ptr) override {}\n  \n  Ptr\
    \ update(Ptr n) override {\n    n->cnt = 1 + base::count(n->l) + base::count(n->r);\n\
    \    return n;\n  }\n\n  Ptr insert_key(const Key& k) {\n    Ptr p = root;\n \
    \   int ret = 0;\n    while (p) {\n      if constexpr (multi == false) {\n   \
    \     if (k == p->key) return p;\n      }\n      if (k < p->key) {\n        p\
    \ = p->l;\n      } else {\n        ret += base::count(p->l) + 1;\n        p =\
    \ p->r;\n      }\n    }\n    Ptr n = base::my_new(k);\n    auto x = base::split(root,\
    \ ret);\n    root = base::merge(base::merge(x.first, n), x.second);\n    return\
    \ n;\n  }\n};\n\n/**\n * @brief Ordered Set(base)\u3000(\u9806\u5E8F\u4ED8\u304D\
    \u96C6\u5408\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9)\n */\n#line 4 \"orderedmap/orderedmap.hpp\"\
    \n\ntemplate <typename Key, typename Val, bool multi>\nstruct OrderedMapNode {\n\
    \  using Ptr = typename RBSTBase<OrderedMapNode>::Ptr;\n  Ptr l, r;\n  Key key;\n\
    \  Val val;\n  int cnt;\n\n  OrderedMapNode(const Key& k = Key(), const Val& v\
    \ = Val())\n      : l(), r(), key(k), val(v), cnt(1) {}\n};\n\ntemplate <typename\
    \ Key, typename Val>\nstruct OrderedMap : OrderedMapBase<OrderedMapNode<Key, Val,\
    \ false>, false> {\n  using base = OrderedMapBase<OrderedMapNode<Key, Val, false>,\
    \ false>;\n\n  OrderedMap() : base() {}\n\n  Val& operator[](const Key& key) {\
    \ return base::insert_key(key)->val; };\n\n};\n\n/**\n * @brief Ordered Map(\u9806\
    \u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)\n */\n"
  code: "#pragma once\n\n#include \"orderedmap-base.hpp\"\n\ntemplate <typename Key,\
    \ typename Val, bool multi>\nstruct OrderedMapNode {\n  using Ptr = typename RBSTBase<OrderedMapNode>::Ptr;\n\
    \  Ptr l, r;\n  Key key;\n  Val val;\n  int cnt;\n\n  OrderedMapNode(const Key&\
    \ k = Key(), const Val& v = Val())\n      : l(), r(), key(k), val(v), cnt(1) {}\n\
    };\n\ntemplate <typename Key, typename Val>\nstruct OrderedMap : OrderedMapBase<OrderedMapNode<Key,\
    \ Val, false>, false> {\n  using base = OrderedMapBase<OrderedMapNode<Key, Val,\
    \ false>, false>;\n\n  OrderedMap() : base() {}\n\n  Val& operator[](const Key&\
    \ key) { return base::insert_key(key)->val; };\n\n};\n\n/**\n * @brief Ordered\
    \ Map(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)\n */\n"
  dependsOn:
  - orderedmap/orderedmap-base.hpp
  - rbst/rbst-base.hpp
  isVerificationFile: false
  path: orderedmap/orderedmap.hpp
  requiredBy: []
  timestamp: '2020-12-17 02:52:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/orderedmap.test.cpp
  - verify/verify-yosupo-ds/yosupo-orderedmap.test.cpp
documentation_of: orderedmap/orderedmap.hpp
layout: document
redirect_from:
- /library/orderedmap/orderedmap.hpp
- /library/orderedmap/orderedmap.hpp.html
title: "Ordered Map(\u9806\u5E8F\u4ED8\u304D\u9023\u60F3\u914D\u5217)"
---
