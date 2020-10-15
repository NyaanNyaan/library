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
    \ = 0;\n    pool[0].key = Key();\n    pool[0].val = pool[0].sum = Val();\n   \
    \ return pool;\n  }\n\n  using F = function<Val(Val, Val)>;\n\n  static void set_monoid(const\
    \ F &_f, const Val &I_) {\n    f = _f;\n    I = I_;\n    pool[0].val = pool[0].sum\
    \ = I_;\n  }\n\n  static VectorPool<Node> pool;\n  static F f;\n  static Val I;\n\
    \  NodePtr root;\n\n  OrderedMap() : root(0) {}\n\n  NodePtr my_new(const Key\
    \ &k, const Val &v) {\n    NodePtr ret = pool.my_new(k, v);\n    assert(ret !=\
    \ 0);\n    return ret;\n  }\n\n  void my_delete(NodePtr t) {\n    assert(t !=\
    \ 0);\n    pool.free(t);\n  }\n\n  // update (*t)\n  inline NodePtr update(NodePtr\
    \ t) {\n    pool[t].cnt = pool[pool[t].l].cnt + pool[pool[t].r].cnt + 1;\n   \
    \ pool[t].sum = f(f(pool[pool[t].l].sum, pool[t].val), pool[pool[t].r].sum);\n\
    \    return t;\n  }\n\n  // assign (*this)[x] = y, and update parent nodes\n \
    \ void thrust(NodePtr p, const Key &x, const Val &y) {\n    if (!p) return;\n\
    \    if (pool[p].key == x) {\n      pool[p].val = y;\n      update(p);\n     \
    \ return;\n    }\n    NodePtr nxt = pool[p].key < x ? pool[p].r : pool[p].l;\n\
    \    thrust(nxt, x, y);\n    update(p);\n  }\n\n  // merge (*l, *r)\n  NodePtr\
    \ merge(NodePtr l, NodePtr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng()\
    \ * (pool[l].cnt + pool[r].cnt)) >> 32) < pool[l].cnt) {\n      pool[l].r = merge(pool[l].r,\
    \ r);\n      return update(l);\n    } else {\n      pool[r].l = merge(l, pool[r].l);\n\
    \      return update(r);\n    }\n  }\n\n  // split (*t) to [-inf, x), [x, inf)\n\
    \  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {\n    if (!t) return\
    \ {0, 0};\n    if (x <= pool[t].key) {\n      auto s = split(pool[t].l, x);\n\
    \      pool[t].l = s.second;\n      return {s.first, update(t)};\n    } else {\n\
    \      auto s = split(pool[t].r, x);\n      pool[t].r = s.first;\n      return\
    \ {update(t), s.second};\n    }\n  }\n\n  // split (*t) to [-inf, x], (x, inf)\n\
    \  pair<NodePtr, NodePtr> split_upper(NodePtr t, const Key &x) {\n    if (!t)\
    \ return {0, 0};\n    if (x < pool[t].key) {\n      auto s = split(pool[t].l,\
    \ x);\n      pool[t].l = s.second;\n      return {s.first, update(t)};\n    }\
    \ else {\n      auto s = split(pool[t].r, x);\n      pool[t].r = s.first;\n  \
    \    return {update(t), s.second};\n    }\n  }\n\n  // find t : t->key == x\n\
    \  NodePtr find_ptr(const Key &x) const {\n    NodePtr p = root;\n    while (p)\
    \ {\n      if (x == pool[p].key) return p;\n      p = x < pool[p].key ? pool[p].l\
    \ : pool[p].r;\n    }\n    return 0;\n  }\n\n  // find t : t->key is minimum among\
    \ (ptr n: n->key >= x)\n  NodePtr lower_ptr(NodePtr p, const Key &x) const {\n\
    \    if (!p) return 0;\n    if (pool[p].val == x) return p;\n    if (pool[p].val\
    \ < x) return lower_ptr(pool[p].r, x);\n    NodePtr q = lower_ptr(pool[p].l, x);\n\
    \    return q ? q : p;\n  }\n\n  // find t : t->key is minimum among (ptr n: n->key\
    \ > x)\n  NodePtr upper_ptr(NodePtr p, const Key &x) const {\n    if (!p) return\
    \ 0;\n    if (pool[p].val <= x) return upper_ptr(pool[p].r, x);\n    NodePtr q\
    \ = upper_ptr(pool[p].l, x);\n    return q ? q : p;\n  }\n\n  // access (*this)[x]\n\
    \  Val &operator[](const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (p) return\
    \ pool[p].val;\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n    NodePtr\
    \ n = my_new(x, Val());\n    root = merge(merge(l, n), r);\n    return pool[n].val;\n\
    \  }\n\n  // get (*this)[x]\n  Val get(const Key &x) const {\n    NodePtr p =\
    \ root;\n    while (p) {\n      if (x == pool[p].key) return pool[p].val;\n  \
    \    p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return Val();\n\
    \  }\n\n  // get\u306E\u8A2D\u8A08\u3092NodePtr\u3092\u8FD4\u3059\u4ED5\u69D8\u306B\
    \u3059\u3079\u304D\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306B\
    nullptr\u3092\u8FD4\u305B\u306A\u3044\u3068\u8272\u3005\u90FD\u5408\u304C\u60AA\
    \u3044)\n\n  // get node, of which key is minimum\n  pair<const Key &, Val &>\
    \ get_first() const {\n    assert((*this).size() > 0);\n    NodePtr p = root;\n\
    \    while (!pool[p].l) p = pool[p].l;\n    return make_pair(pool[p].key, pool[p].val);\n\
    \  }\n\n  // get node, of which key is maximum\n  pair<const Key &, Val &> get_last()\
    \ const {\n    assert((*this).size() > 0);\n    NodePtr p = root;\n    while (!pool[p].r)\
    \ p = pool[p].r;\n    return make_pair(pool[p].key, pool[p].val);\n  }\n\n  //\
    \ get pair(key, val) (lower_bound x)\n  pair<const Key &, Val &> get_lower_bound(const\
    \ Key &x) const {\n    NodePtr p = lower_ptr(root, x);\n    assert(p != 0);\n\
    \    return make_pair(pool[p].key, pool[p].val);\n  }\n\n  // get pair(key, val)\
    \ (upper_bound x)\n  pair<const Key &, Val &> get_upper_bound(const Key &x) const\
    \ {\n    NodePtr p = upper_ptr(root, x);\n    assert(p != 0);\n    return make_pair(pool[p].key,\
    \ pool[p].val);\n  }\n\n  // enumerate all key in order of increasing\n  vector<pair<const\
    \ Key &, Val &>> enumerate() const {\n    vector<pair<const Key &, Val &>> ret;\n\
    \    auto dfs = [&](auto rec, NodePtr p) -> void {\n      if (pool[p].l) rec(rec,\
    \ pool[p].l);\n      if (p) ret.emplace_back(pool[p].key, pool[p].val);\n    \
    \  if (pool[p].r) rec(rec, pool[p].r);\n      return;\n    };\n    dfs(dfs, root);\n\
    \    return ret;\n  }\n\n  // (*this)[x] = y\n  void insert(const Key &x, const\
    \ Val &y) {\n    NodePtr p = find_ptr(x);\n    if (p) {\n      thrust(root, x,\
    \ y);\n      return;\n    }\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n\
    \    root = merge(merge(l, my_new(x, y)), r);\n  }\n\n  // erase (*this)[x]\n\
    \  void erase(const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (!p) return;\n\
    \    NodePtr l, r;\n    tie(l, r) = split(root, x);\n    root = merge(l, split_upper(r,\
    \ x).second);\n    my_delete(p);\n  }\n\n  // count the number of node: n.key\
    \ < x\n  int lower_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x <= pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // count the number of node: n.key\
    \ <= x\n  int upper_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x < pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // calculate f([n : l <= n.key < r])\n\
    \  Val fold(const Key &l, const Key &r) {\n    auto x = split(root, l);\n    auto\
    \ y = split(x.second, r);\n    Val ret = y.first.sum;\n    root = merge(x.first,\
    \ merge(y.first, y.second));\n    return ret;\n  }\n\n  // count containing nodes\n\
    \  int size() const { return pool[root].cnt; }\n};\n\ntemplate <typename Key,\
    \ typename Val>\nVectorPool<typename OrderedMap<Key, Val>::Node> OrderedMap<Key,\
    \ Val>::pool =\n    OrderedMap<Key, Val>::init_pool();\ntemplate <typename Key,\
    \ typename Val>\nfunction<Val(Val, Val)> OrderedMap<Key, Val>::f = +[](Val, Val)\
    \ {\n  return Val();\n};\ntemplate <typename Key, typename Val>\nVal OrderedMap<Key,\
    \ Val>::I = Val();\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../misc/vector-pool.hpp\"\n\ntemplate <typename Key, typename Val>\nstruct\
    \ OrderedMap {\n  uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n\
    \    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n\
    \  }\n\n  using NodePtr = uint32_t;\n  struct Node {\n    NodePtr l, r;\n    Key\
    \ key;\n    Val val, sum;\n    int cnt;\n    Node() {}\n    Node(const Key &k,\
    \ const Val &v)\n        : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}\n  };\n\
    \n  static VectorPool<Node> init_pool() {\n    VectorPool<Node> pool;\n    pool[0].l\
    \ = pool[0].r = pool[0].cnt = 0;\n    pool[0].key = Key();\n    pool[0].val =\
    \ pool[0].sum = Val();\n    return pool;\n  }\n\n  using F = function<Val(Val,\
    \ Val)>;\n\n  static void set_monoid(const F &_f, const Val &I_) {\n    f = _f;\n\
    \    I = I_;\n    pool[0].val = pool[0].sum = I_;\n  }\n\n  static VectorPool<Node>\
    \ pool;\n  static F f;\n  static Val I;\n  NodePtr root;\n\n  OrderedMap() : root(0)\
    \ {}\n\n  NodePtr my_new(const Key &k, const Val &v) {\n    NodePtr ret = pool.my_new(k,\
    \ v);\n    assert(ret != 0);\n    return ret;\n  }\n\n  void my_delete(NodePtr\
    \ t) {\n    assert(t != 0);\n    pool.free(t);\n  }\n\n  // update (*t)\n  inline\
    \ NodePtr update(NodePtr t) {\n    pool[t].cnt = pool[pool[t].l].cnt + pool[pool[t].r].cnt\
    \ + 1;\n    pool[t].sum = f(f(pool[pool[t].l].sum, pool[t].val), pool[pool[t].r].sum);\n\
    \    return t;\n  }\n\n  // assign (*this)[x] = y, and update parent nodes\n \
    \ void thrust(NodePtr p, const Key &x, const Val &y) {\n    if (!p) return;\n\
    \    if (pool[p].key == x) {\n      pool[p].val = y;\n      update(p);\n     \
    \ return;\n    }\n    NodePtr nxt = pool[p].key < x ? pool[p].r : pool[p].l;\n\
    \    thrust(nxt, x, y);\n    update(p);\n  }\n\n  // merge (*l, *r)\n  NodePtr\
    \ merge(NodePtr l, NodePtr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng()\
    \ * (pool[l].cnt + pool[r].cnt)) >> 32) < pool[l].cnt) {\n      pool[l].r = merge(pool[l].r,\
    \ r);\n      return update(l);\n    } else {\n      pool[r].l = merge(l, pool[r].l);\n\
    \      return update(r);\n    }\n  }\n\n  // split (*t) to [-inf, x), [x, inf)\n\
    \  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {\n    if (!t) return\
    \ {0, 0};\n    if (x <= pool[t].key) {\n      auto s = split(pool[t].l, x);\n\
    \      pool[t].l = s.second;\n      return {s.first, update(t)};\n    } else {\n\
    \      auto s = split(pool[t].r, x);\n      pool[t].r = s.first;\n      return\
    \ {update(t), s.second};\n    }\n  }\n\n  // split (*t) to [-inf, x], (x, inf)\n\
    \  pair<NodePtr, NodePtr> split_upper(NodePtr t, const Key &x) {\n    if (!t)\
    \ return {0, 0};\n    if (x < pool[t].key) {\n      auto s = split(pool[t].l,\
    \ x);\n      pool[t].l = s.second;\n      return {s.first, update(t)};\n    }\
    \ else {\n      auto s = split(pool[t].r, x);\n      pool[t].r = s.first;\n  \
    \    return {update(t), s.second};\n    }\n  }\n\n  // find t : t->key == x\n\
    \  NodePtr find_ptr(const Key &x) const {\n    NodePtr p = root;\n    while (p)\
    \ {\n      if (x == pool[p].key) return p;\n      p = x < pool[p].key ? pool[p].l\
    \ : pool[p].r;\n    }\n    return 0;\n  }\n\n  // find t : t->key is minimum among\
    \ (ptr n: n->key >= x)\n  NodePtr lower_ptr(NodePtr p, const Key &x) const {\n\
    \    if (!p) return 0;\n    if (pool[p].val == x) return p;\n    if (pool[p].val\
    \ < x) return lower_ptr(pool[p].r, x);\n    NodePtr q = lower_ptr(pool[p].l, x);\n\
    \    return q ? q : p;\n  }\n\n  // find t : t->key is minimum among (ptr n: n->key\
    \ > x)\n  NodePtr upper_ptr(NodePtr p, const Key &x) const {\n    if (!p) return\
    \ 0;\n    if (pool[p].val <= x) return upper_ptr(pool[p].r, x);\n    NodePtr q\
    \ = upper_ptr(pool[p].l, x);\n    return q ? q : p;\n  }\n\n  // access (*this)[x]\n\
    \  Val &operator[](const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (p) return\
    \ pool[p].val;\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n    NodePtr\
    \ n = my_new(x, Val());\n    root = merge(merge(l, n), r);\n    return pool[n].val;\n\
    \  }\n\n  // get (*this)[x]\n  Val get(const Key &x) const {\n    NodePtr p =\
    \ root;\n    while (p) {\n      if (x == pool[p].key) return pool[p].val;\n  \
    \    p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return Val();\n\
    \  }\n\n  // get\u306E\u8A2D\u8A08\u3092NodePtr\u3092\u8FD4\u3059\u4ED5\u69D8\u306B\
    \u3059\u3079\u304D\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306B\
    nullptr\u3092\u8FD4\u305B\u306A\u3044\u3068\u8272\u3005\u90FD\u5408\u304C\u60AA\
    \u3044)\n\n  // get node, of which key is minimum\n  pair<const Key &, Val &>\
    \ get_first() const {\n    assert((*this).size() > 0);\n    NodePtr p = root;\n\
    \    while (!pool[p].l) p = pool[p].l;\n    return make_pair(pool[p].key, pool[p].val);\n\
    \  }\n\n  // get node, of which key is maximum\n  pair<const Key &, Val &> get_last()\
    \ const {\n    assert((*this).size() > 0);\n    NodePtr p = root;\n    while (!pool[p].r)\
    \ p = pool[p].r;\n    return make_pair(pool[p].key, pool[p].val);\n  }\n\n  //\
    \ get pair(key, val) (lower_bound x)\n  pair<const Key &, Val &> get_lower_bound(const\
    \ Key &x) const {\n    NodePtr p = lower_ptr(root, x);\n    assert(p != 0);\n\
    \    return make_pair(pool[p].key, pool[p].val);\n  }\n\n  // get pair(key, val)\
    \ (upper_bound x)\n  pair<const Key &, Val &> get_upper_bound(const Key &x) const\
    \ {\n    NodePtr p = upper_ptr(root, x);\n    assert(p != 0);\n    return make_pair(pool[p].key,\
    \ pool[p].val);\n  }\n\n  // enumerate all key in order of increasing\n  vector<pair<const\
    \ Key &, Val &>> enumerate() const {\n    vector<pair<const Key &, Val &>> ret;\n\
    \    auto dfs = [&](auto rec, NodePtr p) -> void {\n      if (pool[p].l) rec(rec,\
    \ pool[p].l);\n      if (p) ret.emplace_back(pool[p].key, pool[p].val);\n    \
    \  if (pool[p].r) rec(rec, pool[p].r);\n      return;\n    };\n    dfs(dfs, root);\n\
    \    return ret;\n  }\n\n  // (*this)[x] = y\n  void insert(const Key &x, const\
    \ Val &y) {\n    NodePtr p = find_ptr(x);\n    if (p) {\n      thrust(root, x,\
    \ y);\n      return;\n    }\n    NodePtr l, r;\n    tie(l, r) = split(root, x);\n\
    \    root = merge(merge(l, my_new(x, y)), r);\n  }\n\n  // erase (*this)[x]\n\
    \  void erase(const Key &x) {\n    NodePtr p = find_ptr(x);\n    if (!p) return;\n\
    \    NodePtr l, r;\n    tie(l, r) = split(root, x);\n    root = merge(l, split_upper(r,\
    \ x).second);\n    my_delete(p);\n  }\n\n  // count the number of node: n.key\
    \ < x\n  int lower_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x <= pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // count the number of node: n.key\
    \ <= x\n  int upper_bound(const Key &x) const {\n    NodePtr p = root;\n    int\
    \ ret = 0;\n    while (p) {\n      if (x < pool[p].val) {\n        p = pool[p].l;\n\
    \      } else {\n        ret += pool[pool[p].l].cnt + 1;\n        p = pool[p].r;\n\
    \      }\n    }\n    return ret;\n  }\n\n  // calculate f([n : l <= n.key < r])\n\
    \  Val fold(const Key &l, const Key &r) {\n    auto x = split(root, l);\n    auto\
    \ y = split(x.second, r);\n    Val ret = y.first.sum;\n    root = merge(x.first,\
    \ merge(y.first, y.second));\n    return ret;\n  }\n\n  // count containing nodes\n\
    \  int size() const { return pool[root].cnt; }\n};\n\ntemplate <typename Key,\
    \ typename Val>\nVectorPool<typename OrderedMap<Key, Val>::Node> OrderedMap<Key,\
    \ Val>::pool =\n    OrderedMap<Key, Val>::init_pool();\ntemplate <typename Key,\
    \ typename Val>\nfunction<Val(Val, Val)> OrderedMap<Key, Val>::f = +[](Val, Val)\
    \ {\n  return Val();\n};\ntemplate <typename Key, typename Val>\nVal OrderedMap<Key,\
    \ Val>::I = Val();\n"
  dependsOn:
  - misc/vector-pool.hpp
  isVerificationFile: false
  path: balanced-binary-search-tree/rbst-ordered-map.hpp
  requiredBy: []
  timestamp: '2020-10-16 00:17:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: balanced-binary-search-tree/rbst-ordered-map.hpp
layout: document
redirect_from:
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp.html
title: balanced-binary-search-tree/rbst-ordered-map.hpp
---
