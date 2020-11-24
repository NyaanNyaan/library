---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: orderedmap/rbst-ordered-set.hpp
    title: "OrderedSet(\u9806\u5E8F\u4ED8\u304D\u96C6\u5408)"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"orderedmap/randomized-binary-search-tree.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T, typename F>\n\
    struct RandomizedBinarySearchTree {\n  uint64_t rng() {\n    static uint64_t x_\
    \ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n\
    \    return x_ & 0xFFFFFFFFull;\n  }\n\n  struct Node {\n    Node *l, *r;\n  \
    \  T key, sum;\n    int cnt;\n\n    Node() {}\n\n    Node(const T &k) : l(nullptr),\
    \ r(nullptr), key(k), sum(k), cnt(1) {}\n  };\n\n  vector<Node> pool;\n  int ptr;\n\
    \  const F f;\n  const T I;\n\n  RandomizedBinarySearchTree(const F &f_, const\
    \ T &I_, int pool_size = 2000000)\n      : pool(pool_size), ptr(0), f(f_), I(I_)\
    \ {}\n\n  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k)); }\n\n  inline\
    \ int count(const Node *t){ return t ? t->cnt : 0; }\n\n  inline T sum(const Node\
    \ *t) { return t ? t->sum : I; }\n\n  Node *update(Node *t) {\n    t->cnt = count(t->l)\
    \ + count(t->r) + 1;\n    t->sum = f(f(sum(t->l), t->key), sum(t->r));\n    return\
    \ t;\n  }\n\n  Node *merge(Node *l, Node *r) {\n    if (!l || !r) return l ? l\
    \ : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      l->r\
    \ = merge(l->r, r);\n      return update(l);\n    } else {\n      r->l = merge(l,\
    \ r->l);\n      return update(r);\n    }\n  }\n\n  pair<Node *, Node *> split(Node\
    \ *t, int k) {\n    if (!t) return {nullptr, nullptr};\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\n  Node\
    \ *build(int l, int r, const vector<T> &v) {\n    if (l + 1 >= r) return my_new(v[l]);\n\
    \    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n\
    \n  Node *build(const vector<T> &v) {\n    ptr = 0;\n    return build(0, (int)v.size(),\
    \ v);\n  }\n\n  void insert(Node *&t, int k, const T &v) {\n    auto x = split(t,\
    \ k);\n    t = merge(merge(x.first, my_new(v)), x.second);\n  }\n\n  void erase(Node\
    \ *&t, int k) {\n    auto x = split(t, k);\n    t = merge(x.first, split(x.second,\
    \ 1).second);\n  }\n\n  T query(Node *&t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    auto ret = sum(y.first);\n  \
    \  t = merge(x.first, merge(y.first, y.second));\n    return ret;\n  }\n\n  int\
    \ size(Node *t) { return count(t); }\n\n  Node *make() { return nullptr; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename F>\nstruct RandomizedBinarySearchTree {\n  uint64_t rng()\
    \ {\n    static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n\
    \    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  struct Node\
    \ {\n    Node *l, *r;\n    T key, sum;\n    int cnt;\n\n    Node() {}\n\n    Node(const\
    \ T &k) : l(nullptr), r(nullptr), key(k), sum(k), cnt(1) {}\n  };\n\n  vector<Node>\
    \ pool;\n  int ptr;\n  const F f;\n  const T I;\n\n  RandomizedBinarySearchTree(const\
    \ F &f_, const T &I_, int pool_size = 2000000)\n      : pool(pool_size), ptr(0),\
    \ f(f_), I(I_) {}\n\n  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k));\
    \ }\n\n  inline int count(const Node *t){ return t ? t->cnt : 0; }\n\n  inline\
    \ T sum(const Node *t) { return t ? t->sum : I; }\n\n  Node *update(Node *t) {\n\
    \    t->cnt = count(t->l) + count(t->r) + 1;\n    t->sum = f(f(sum(t->l), t->key),\
    \ sum(t->r));\n    return t;\n  }\n\n  Node *merge(Node *l, Node *r) {\n    if\
    \ (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32)\
    \ < l->cnt) {\n      l->r = merge(l->r, r);\n      return update(l);\n    } else\
    \ {\n      r->l = merge(l, r->l);\n      return update(r);\n    }\n  }\n\n  pair<Node\
    \ *, Node *> split(Node *t, int k) {\n    if (!t) return {nullptr, nullptr};\n\
    \    if (k <= count(t->l)) {\n      auto s = split(t->l, k);\n      t->l = s.second;\n\
    \      return {s.first, update(t)};\n    } else {\n      auto s = split(t->r,\
    \ k - count(t->l) - 1);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  Node *build(int l, int r, const vector<T> &v) {\n    if (l +\
    \ 1 >= r) return my_new(v[l]);\n    return merge(build(l, (l + r) >> 1, v), build((l\
    \ + r) >> 1, r, v));\n  }\n\n  Node *build(const vector<T> &v) {\n    ptr = 0;\n\
    \    return build(0, (int)v.size(), v);\n  }\n\n  void insert(Node *&t, int k,\
    \ const T &v) {\n    auto x = split(t, k);\n    t = merge(merge(x.first, my_new(v)),\
    \ x.second);\n  }\n\n  void erase(Node *&t, int k) {\n    auto x = split(t, k);\n\
    \    t = merge(x.first, split(x.second, 1).second);\n  }\n\n  T query(Node *&t,\
    \ int a, int b) {\n    auto x = split(t, a);\n    auto y = split(x.second, b -\
    \ a);\n    auto ret = sum(y.first);\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return ret;\n  }\n\n  int size(Node *t) { return count(t); }\n\n  Node *make()\
    \ { return nullptr; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: orderedmap/randomized-binary-search-tree.hpp
  requiredBy:
  - orderedmap/rbst-ordered-set.hpp
  timestamp: '2020-11-24 21:53:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: orderedmap/randomized-binary-search-tree.hpp
layout: document
redirect_from:
- /library/orderedmap/randomized-binary-search-tree.hpp
- /library/orderedmap/randomized-binary-search-tree.hpp.html
title: orderedmap/randomized-binary-search-tree.hpp
---
