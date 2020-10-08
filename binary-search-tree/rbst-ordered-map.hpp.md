---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"binary-search-tree/rbst-ordered-map.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Key, typename Val, int S = 2000000,\
    \ bool MULTI = false>\nstruct OrderedMap {\n  struct RandomizedBinarySearchTree\
    \ {\n    uint64_t rng() {\n      static uint64_t x_ = 88172645463325252ULL;\n\
    \      x_ = x_ ^ (x_ << 7);\n      x_ = x_ ^ (x_ >> 9);\n      return x_ & 0xFFFFFFFFull;\n\
    \    }\n\n    struct Node {\n      Node *l, *r;\n      Key key;\n      Val val;\n\
    \      int cnt;\n\n      Node() {}\n\n      Node(const Key &k, const Val &v)\n\
    \          : l(nullptr), r(nullptr), key(k), val(v), cnt(1) {}\n    };\n\n   \
    \ vector<Node> pool;\n    int ptr;\n\n    RandomizedBinarySearchTree(int pool_size\
    \ = 2000000)\n        : pool(pool_size), ptr(0) {}\n\n    Node *my_new(const Key\
    \ &k, const Val &v) {\n      return &(pool[ptr++] = Node(k, v));\n    }\n\n  \
    \  inline int count(const Node *t) { return t ? t->cnt : 0; }\n\n    inline Node\
    \ *update(Node *t) {\n      t->cnt = count(t->l) + count(t->r) + 1;\n      return\
    \ t;\n    }\n\n    Node *merge(Node *l, Node *r) {\n      if (!l || !r) return\
    \ l ? l : r;\n\n      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n\
    \        l->r = merge(l->r, r);\n        return update(l);\n      } else {\n \
    \       r->l = merge(l, r->l);\n        return update(r);\n      }\n    }\n\n\
    \    pair<Node *, Node *> split(Node *t, int k) {\n      if (!t) return {nullptr,\
    \ nullptr};\n      if (k <= count(t->l)) {\n        auto s = split(t->l, k);\n\
    \        t->l = s.second;\n        return {s.first, update(t)};\n      } else\
    \ {\n        auto s = split(t->r, k - count(t->l) - 1);\n        t->r = s.first;\n\
    \        return {update(t), s.second};\n      }\n    }\n\n    void insert(Node\
    \ *&t, int k, const Key &key, const Val &val) {\n      auto x = split(t, k);\n\
    \      t = merge(merge(x.first, my_new(key, val)), x.second);\n    }\n\n    void\
    \ erase(Node *&t, int k) {\n      auto x = split(t, k);\n      t = merge(x.first,\
    \ split(x.second, 1).second);\n    }\n\n    int size(Node *t) { return count(t);\
    \ }\n\n    Node *make() { return nullptr; }\n  };\n\n  using T = pair<Key, Val>;\n\
    \  using F = function<T(T, T)>;\n  using RBST = RandomizedBinarySearchTree;\n\
    \  using Node = typename RBST::Node;\n\n  static RBST *rbst;\n  Node *t;\n\n \
    \ OrderedMap() {\n    if (!rbst) rbst = new RBST(S);\n    t = rbst->make();\n\
    \  }\n\n  pair<Node *, Node *> split(Node *t, const Key &x) {\n    if (!t) return\
    \ {nullptr, nullptr};\n    if (x <= t->key) {\n      auto s = split(t->l, x);\n\
    \      t->l = s.second;\n      return {s.first, rbst->update(t)};\n    } else\
    \ {\n      auto s = split(t->r, x);\n      t->r = s.first;\n      return {rbst->update(t),\
    \ s.second};\n    }\n  }\n\n  Node *_find(const Key &x) {\n    Node *p = t;\n\
    \    while (p) {\n      if (x == p->key) return p;\n      p = x < p->key ? p->l\
    \ : p->r;\n    }\n    return nullptr;\n  }\n\n  Val &operator[](const Key &x)\
    \ {\n    Node *p = _find(x);\n    if (p) return p->val;\n    insert(x, Val());\n\
    \    return _find(x)->val;\n  }\n\n  void insert(const Key &x, const Val &y) {\n\
    \    Node *p = _find(x);\n    if (p) {\n      p->val = y;\n      return;\n   \
    \ }\n    Node *l, *r;\n    tie(l, r) = split(t, x);\n    t = rbst->merge(rbst->merge(l,\
    \ rbst->my_new(x, y)), r);\n  }\n\n  Val get(const Key &x) const {\n    Node *p\
    \ = t;\n    while (p) {\n      if (x == p->key) return p->val;\n      p = x <\
    \ p->key ? p->l : p->r;\n    }\n    return Val();\n  }\n\n  int size() { return\
    \ rbst->count(t); }\n};\ntemplate <typename Key, typename Val, int S, bool MULTI>\n\
    typename OrderedMap<Key, Val, S, MULTI>::RBST\n    *OrderedMap<Key, Val, S, MULTI>::rbst\
    \ = nullptr;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val, int S = 2000000, bool MULTI = false>\nstruct OrderedMap\
    \ {\n  struct RandomizedBinarySearchTree {\n    uint64_t rng() {\n      static\
    \ uint64_t x_ = 88172645463325252ULL;\n      x_ = x_ ^ (x_ << 7);\n      x_ =\
    \ x_ ^ (x_ >> 9);\n      return x_ & 0xFFFFFFFFull;\n    }\n\n    struct Node\
    \ {\n      Node *l, *r;\n      Key key;\n      Val val;\n      int cnt;\n\n  \
    \    Node() {}\n\n      Node(const Key &k, const Val &v)\n          : l(nullptr),\
    \ r(nullptr), key(k), val(v), cnt(1) {}\n    };\n\n    vector<Node> pool;\n  \
    \  int ptr;\n\n    RandomizedBinarySearchTree(int pool_size = 2000000)\n     \
    \   : pool(pool_size), ptr(0) {}\n\n    Node *my_new(const Key &k, const Val &v)\
    \ {\n      return &(pool[ptr++] = Node(k, v));\n    }\n\n    inline int count(const\
    \ Node *t) { return t ? t->cnt : 0; }\n\n    inline Node *update(Node *t) {\n\
    \      t->cnt = count(t->l) + count(t->r) + 1;\n      return t;\n    }\n\n   \
    \ Node *merge(Node *l, Node *r) {\n      if (!l || !r) return l ? l : r;\n\n \
    \     if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n        l->r = merge(l->r,\
    \ r);\n        return update(l);\n      } else {\n        r->l = merge(l, r->l);\n\
    \        return update(r);\n      }\n    }\n\n    pair<Node *, Node *> split(Node\
    \ *t, int k) {\n      if (!t) return {nullptr, nullptr};\n      if (k <= count(t->l))\
    \ {\n        auto s = split(t->l, k);\n        t->l = s.second;\n        return\
    \ {s.first, update(t)};\n      } else {\n        auto s = split(t->r, k - count(t->l)\
    \ - 1);\n        t->r = s.first;\n        return {update(t), s.second};\n    \
    \  }\n    }\n\n    void insert(Node *&t, int k, const Key &key, const Val &val)\
    \ {\n      auto x = split(t, k);\n      t = merge(merge(x.first, my_new(key, val)),\
    \ x.second);\n    }\n\n    void erase(Node *&t, int k) {\n      auto x = split(t,\
    \ k);\n      t = merge(x.first, split(x.second, 1).second);\n    }\n\n    int\
    \ size(Node *t) { return count(t); }\n\n    Node *make() { return nullptr; }\n\
    \  };\n\n  using T = pair<Key, Val>;\n  using F = function<T(T, T)>;\n  using\
    \ RBST = RandomizedBinarySearchTree;\n  using Node = typename RBST::Node;\n\n\
    \  static RBST *rbst;\n  Node *t;\n\n  OrderedMap() {\n    if (!rbst) rbst = new\
    \ RBST(S);\n    t = rbst->make();\n  }\n\n  pair<Node *, Node *> split(Node *t,\
    \ const Key &x) {\n    if (!t) return {nullptr, nullptr};\n    if (x <= t->key)\
    \ {\n      auto s = split(t->l, x);\n      t->l = s.second;\n      return {s.first,\
    \ rbst->update(t)};\n    } else {\n      auto s = split(t->r, x);\n      t->r\
    \ = s.first;\n      return {rbst->update(t), s.second};\n    }\n  }\n\n  Node\
    \ *_find(const Key &x) {\n    Node *p = t;\n    while (p) {\n      if (x == p->key)\
    \ return p;\n      p = x < p->key ? p->l : p->r;\n    }\n    return nullptr;\n\
    \  }\n\n  Val &operator[](const Key &x) {\n    Node *p = _find(x);\n    if (p)\
    \ return p->val;\n    insert(x, Val());\n    return _find(x)->val;\n  }\n\n  void\
    \ insert(const Key &x, const Val &y) {\n    Node *p = _find(x);\n    if (p) {\n\
    \      p->val = y;\n      return;\n    }\n    Node *l, *r;\n    tie(l, r) = split(t,\
    \ x);\n    t = rbst->merge(rbst->merge(l, rbst->my_new(x, y)), r);\n  }\n\n  Val\
    \ get(const Key &x) const {\n    Node *p = t;\n    while (p) {\n      if (x ==\
    \ p->key) return p->val;\n      p = x < p->key ? p->l : p->r;\n    }\n    return\
    \ Val();\n  }\n\n  int size() { return rbst->count(t); }\n};\ntemplate <typename\
    \ Key, typename Val, int S, bool MULTI>\ntypename OrderedMap<Key, Val, S, MULTI>::RBST\n\
    \    *OrderedMap<Key, Val, S, MULTI>::rbst = nullptr;\n"
  dependsOn: []
  isVerificationFile: false
  path: binary-search-tree/rbst-ordered-map.hpp
  requiredBy: []
  timestamp: '2020-10-09 02:28:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: binary-search-tree/rbst-ordered-map.hpp
layout: document
redirect_from:
- /library/binary-search-tree/rbst-ordered-map.hpp
- /library/binary-search-tree/rbst-ordered-map.hpp.html
title: binary-search-tree/rbst-ordered-map.hpp
---
