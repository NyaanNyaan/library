---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/vector-pool.hpp
    title: misc/vector-pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"balanced-binary-search-tree/rbst-ordered-map.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"misc/vector-pool.hpp\"\n\
    using namespace std;\n\ntemplate <typename T>\nstruct VectorPool {\n  using ptr_t\
    \ = int;\n  vector<T> pool;\n  vector<ptr_t> st;\n  int idx;\n  int cap;\n\n \
    \ // pool[0] is missing number (assuming nil)\n  VectorPool(int s = 4) : pool(s),\
    \ st(), idx(1), cap(s) { assert(s > 0); }\n\n  inline T& operator[](ptr_t i) {\
    \ return pool[i]; }\n\n  void reallocate() {\n    assert(idx == cap && st.size()\
    \ == 0);\n    cap *= 2;\n    pool.resize(cap, T());\n  }\n\n  ptr_t alloc() {\n\
    \    if (idx != cap) return idx++;\n    if (st.empty()) {\n      reallocate();\n\
    \      return idx++;\n    }\n    ptr_t ret = st.back();\n    st.pop_back();\n\
    \    return ret;\n  }\n\n  template <typename... Args>\n  ptr_t my_new(Args...\
    \ args) {\n    ptr_t ret = alloc();\n    pool[ret] = T(args...);\n    return ret;\n\
    \  }\n\n  void free(ptr_t i) { st.push_back(i); }\n\n  void clear() {\n    idx\
    \ = 1;\n    st.clear();\n  }\n};\n#line 6 \"balanced-binary-search-tree/rbst-ordered-map.hpp\"\
    \n\ntemplate <typename Key, typename Val>\nstruct OrderedMap {\n  uint64_t rng()\
    \ {\n    static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n\
    \    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  using NodePtr\
    \ = uint32_t;\n  struct Node {\n    NodePtr l, r;\n    Key key;\n    Val val,\
    \ sum;\n    int cnt;\n    Node() {}\n    Node(const Key &k, const Val &v)\n  \
    \      : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}\n  };\n\n  static VectorPool<Node>\
    \ init_pool() {\n    VectorPool<Node> pool;\n    pool[0].l = pool[0].r = pool[0].cnt\
    \ = 0;\n    pool[0].key = Key();\n    pool[0].val = Val();\n    return pool;\n\
    \  }\n\n  static VectorPool<Node> pool;\n  using F = function<Val(Val, Val)>;\n\
    \  const F f;\n  NodePtr t;\n\n  OrderedMap() : f([](Val, Val) { return Val();\
    \ }), t(0) {}\n  OrderedMap(const F _f) : f(_f), t(0) {}\n\n  NodePtr my_new(const\
    \ Key &k, const Val &v) { return pool.my_new(k, v); }\n\n  void my_delete(NodePtr\
    \ t) { pool.free(t); }\n\n  inline NodePtr update(NodePtr t) {\n    pool[t].cnt\
    \ = pool[pool[t].l].cnt + pool[pool[t].r].cnt + 1;\n    pool[t].sum = f(f(pool[pool[t].l].sum,\
    \ pool[t].val), pool[pool[t].r].sum);\n    return t;\n  }\n\n  NodePtr merge(NodePtr\
    \ l, NodePtr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng() * (pool[l].cnt\
    \ + pool[r].cnt)) >> 32) < pool[l].cnt) {\n      pool[l].r = merge(pool[l].r,\
    \ r);\n      return update(l);\n    } else {\n      pool[r].l = merge(l, pool[r].l);\n\
    \      return update(r);\n    }\n  }\n\n  pair<NodePtr, NodePtr> split(NodePtr\
    \ t, const Key &x) {\n    if (!t) return {0, 0};\n    if (x <= pool[t].key) {\n\
    \      auto s = split(pool[t].l, x);\n      pool[t].l = s.second;\n      return\
    \ {s.first, update(t)};\n    } else {\n      auto s = split(pool[t].r, x);\n \
    \     pool[t].r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\n\
    \  NodePtr find_ptr(const Key &x) const {\n    NodePtr p = t;\n    while (p) {\n\
    \      if (x == pool[p].key) return p;\n      p = x < pool[p].key ? pool[p].l\
    \ : pool[p].r;\n    }\n    return 0;\n  }\n\n  Val &operator[](const Key &x) {\n\
    \    NodePtr p = find_ptr(x);\n    if (p) return pool[p].val;\n    NodePtr l,\
    \ r;\n    tie(l, r) = split(t, x);\n    NodePtr n = my_new(x, Val());\n    t =\
    \ merge(merge(l, n), r);\n    return pool[n].val;\n  }\n\n  void insert(const\
    \ Key &x, const Val &y) {\n    NodePtr p = find_ptr(x);\n    if (p) {\n      pool[p].val\
    \ = y;\n      return;\n    }\n    NodePtr l, r;\n    tie(l, r) = split(t, x);\n\
    \    t = merge(merge(l, my_new(x, y)), r);\n  }\n\n  Val get(const Key &x) const\
    \ {\n    NodePtr p = t;\n    while (p) {\n      if (x == pool[p].key) return pool[p].val;\n\
    \      p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return Val();\n\
    \  }\n};\n\ntemplate <typename Key, typename Val>\nVectorPool<typename OrderedMap<Key,\
    \ Val>::Node> OrderedMap<Key, Val>::pool =\n    OrderedMap<Key, Val>::init_pool();\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../misc/vector-pool.hpp\"\n\ntemplate <typename Key, typename Val>\nstruct\
    \ OrderedMap {\n  uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n\
    \    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n\
    \  }\n\n  using NodePtr = uint32_t;\n  struct Node {\n    NodePtr l, r;\n    Key\
    \ key;\n    Val val, sum;\n    int cnt;\n    Node() {}\n    Node(const Key &k,\
    \ const Val &v)\n        : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}\n  };\n\
    \n  static VectorPool<Node> init_pool() {\n    VectorPool<Node> pool;\n    pool[0].l\
    \ = pool[0].r = pool[0].cnt = 0;\n    pool[0].key = Key();\n    pool[0].val =\
    \ Val();\n    return pool;\n  }\n\n  static VectorPool<Node> pool;\n  using F\
    \ = function<Val(Val, Val)>;\n  const F f;\n  NodePtr t;\n\n  OrderedMap() : f([](Val,\
    \ Val) { return Val(); }), t(0) {}\n  OrderedMap(const F _f) : f(_f), t(0) {}\n\
    \n  NodePtr my_new(const Key &k, const Val &v) { return pool.my_new(k, v); }\n\
    \n  void my_delete(NodePtr t) { pool.free(t); }\n\n  inline NodePtr update(NodePtr\
    \ t) {\n    pool[t].cnt = pool[pool[t].l].cnt + pool[pool[t].r].cnt + 1;\n   \
    \ pool[t].sum = f(f(pool[pool[t].l].sum, pool[t].val), pool[pool[t].r].sum);\n\
    \    return t;\n  }\n\n  NodePtr merge(NodePtr l, NodePtr r) {\n    if (!l ||\
    \ !r) return l ? l : r;\n    if (int((rng() * (pool[l].cnt + pool[r].cnt)) >>\
    \ 32) < pool[l].cnt) {\n      pool[l].r = merge(pool[l].r, r);\n      return update(l);\n\
    \    } else {\n      pool[r].l = merge(l, pool[r].l);\n      return update(r);\n\
    \    }\n  }\n\n  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {\n   \
    \ if (!t) return {0, 0};\n    if (x <= pool[t].key) {\n      auto s = split(pool[t].l,\
    \ x);\n      pool[t].l = s.second;\n      return {s.first, update(t)};\n    }\
    \ else {\n      auto s = split(pool[t].r, x);\n      pool[t].r = s.first;\n  \
    \    return {update(t), s.second};\n    }\n  }\n\n  NodePtr find_ptr(const Key\
    \ &x) const {\n    NodePtr p = t;\n    while (p) {\n      if (x == pool[p].key)\
    \ return p;\n      p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return\
    \ 0;\n  }\n\n  Val &operator[](const Key &x) {\n    NodePtr p = find_ptr(x);\n\
    \    if (p) return pool[p].val;\n    NodePtr l, r;\n    tie(l, r) = split(t, x);\n\
    \    NodePtr n = my_new(x, Val());\n    t = merge(merge(l, n), r);\n    return\
    \ pool[n].val;\n  }\n\n  void insert(const Key &x, const Val &y) {\n    NodePtr\
    \ p = find_ptr(x);\n    if (p) {\n      pool[p].val = y;\n      return;\n    }\n\
    \    NodePtr l, r;\n    tie(l, r) = split(t, x);\n    t = merge(merge(l, my_new(x,\
    \ y)), r);\n  }\n\n  Val get(const Key &x) const {\n    NodePtr p = t;\n    while\
    \ (p) {\n      if (x == pool[p].key) return pool[p].val;\n      p = x < pool[p].key\
    \ ? pool[p].l : pool[p].r;\n    }\n    return Val();\n  }\n};\n\ntemplate <typename\
    \ Key, typename Val>\nVectorPool<typename OrderedMap<Key, Val>::Node> OrderedMap<Key,\
    \ Val>::pool =\n    OrderedMap<Key, Val>::init_pool();"
  dependsOn:
  - misc/vector-pool.hpp
  isVerificationFile: false
  path: balanced-binary-search-tree/rbst-ordered-map.hpp
  requiredBy: []
  timestamp: '2020-10-15 01:08:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: balanced-binary-search-tree/rbst-ordered-map.hpp
layout: document
redirect_from:
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp.html
title: balanced-binary-search-tree/rbst-ordered-map.hpp
---
