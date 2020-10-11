---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"balanced-binary-search-tree/rbst-ordered-map.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename Key, typename Val,\
    \ int S = 2000000>\nstruct OrderedMap {\n  uint64_t rng() {\n    static uint64_t\
    \ x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n\
    \    return x_ & 0xFFFFFFFFull;\n  }\n\n  using NodePtr = uint32_t;\n  struct\
    \ Node {\n    NodePtr l, r;\n    Key key;\n    Val val;\n    uint32_t cnt;\n \
    \ };\n\n  NodePtr t;\n  static Node *pool;\n  static int ptr;\n  static NodePtr\
    \ buf[128];\n\n  OrderedMap() : t(0) {\n    if (!pool) {\n      pool = new Node[S\
    \ + 10];\n      pool[0].l = pool[0].r = pool[0].cnt = 0;\n    }\n  }\n\n  NodePtr\
    \ my_new(const Key &k, const Val &v) {\n    pool[ptr].l = pool[ptr].r = 0;\n \
    \   pool[ptr].key = k;\n    pool[ptr].val = v;\n    pool[ptr].cnt = 1;\n    return\
    \ ptr++;\n  }\n\n  NodePtr merge(NodePtr l, NodePtr r) {\n    if (!l || !r) return\
    \ l ? l : r;\n    NodePtr res;\n    NodePtr *pre = &res;\n    while (true) {\n\
    \      if (!l || !r) {\n        *pre = l ? l : r;\n        break;\n      }\n \
    \     uint32_t s = pool[l].cnt + pool[r].cnt;\n      if (uint32_t((rng() * s)\
    \ >> 32) < pool[l].cnt) {\n        *pre = l;\n        pool[l].cnt = s + 1;\n \
    \       pre = &(pool[l].r);\n        l = pool[l].r;\n      } else {\n        *pre\
    \ = r;\n        pool[r].cnt = s + 1;\n        pre = &(pool[r].l);\n        r =\
    \ pool[r].l;\n      }\n    }\n    return res;\n  }\n\n  pair<NodePtr, NodePtr>\
    \ split(NodePtr t, const Key &x, int i = -1) {\n    if (i == -1) {\n      i =\
    \ 0;\n      while (t) {\n        buf[i++] = t;\n        t = x <= pool[t].key ?\
    \ pool[t].l : pool[t].r;\n      }\n    }\n    NodePtr l = 0, r = 0;\n    uint32_t\
    \ pre = 0;\n    while (i--) {\n      NodePtr t = buf[i];\n      if (x <= pool[t].key)\
    \ {\n        pool[t].l = r;\n        pool[t].cnt = (pre += pool[pool[t].r].cnt\
    \ + 1);\n        r = t;\n      } else {\n        pool[t].r = l;\n        pool[t].cnt\
    \ = (pre += pool[pool[t].l].cnt + 1);\n        l = t;\n      }\n    }\n    return\
    \ {l, r};\n  }\n\n  NodePtr _find(const Key &x) const {\n    NodePtr p = t;\n\
    \    while (p) {\n      if (x == pool[p].key) return p;\n      p = x < pool[p].key\
    \ ? pool[p].l : pool[p].r;\n    }\n    return 0;\n  }\n\n  Val &operator[](const\
    \ Key &x) {\n    NodePtr p = _find(x);\n    if (p) return pool[p].val;\n    NodePtr\
    \ l, r;\n    tie(l, r) = split(t, x);\n    NodePtr n = my_new(x, Val());\n   \
    \ t = merge(merge(l, n), r);\n    return pool[n].val;\n  }\n\n  void insert(const\
    \ Key &x, const Val &y) {\n    NodePtr p = t;\n    int i = 0;\n    while (p) {\n\
    \      if (pool[p].key == x) {\n        pool[p].val = y;\n        return;\n  \
    \    }\n      buf[i++] = p;\n      p = x < pool[p].key ? pool[p].l : pool[p].r;\n\
    \    }\n    NodePtr l, r;\n    tie(l, r) = split(t, x, i);\n    t = merge(merge(l,\
    \ my_new(x, y)), r);\n  }\n\n  Val get(const Key &x) const {\n    NodePtr p =\
    \ t;\n    while (p) {\n      if (x == pool[p].key) return pool[p].val;\n     \
    \ p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return Val();\n  }\n\
    \n  int size() { return pool[t].cnt; }\n};\ntemplate <typename Key, typename Val,\
    \ int S>\ntypename OrderedMap<Key, Val, S>::Node *OrderedMap<Key, Val, S>::pool\
    \ = nullptr;\ntemplate <typename Key, typename Val, int S>\nint OrderedMap<Key,\
    \ Val, S>::ptr = 1;\ntemplate <typename Key, typename Val, int S>\ntypename OrderedMap<Key,\
    \ Val, S>::NodePtr OrderedMap<Key, Val, S>::buf[128] =\n    {};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Key, typename Val, int S = 2000000>\nstruct OrderedMap {\n  uint64_t\
    \ rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ <<\
    \ 7);\n    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  using\
    \ NodePtr = uint32_t;\n  struct Node {\n    NodePtr l, r;\n    Key key;\n    Val\
    \ val;\n    uint32_t cnt;\n  };\n\n  NodePtr t;\n  static Node *pool;\n  static\
    \ int ptr;\n  static NodePtr buf[128];\n\n  OrderedMap() : t(0) {\n    if (!pool)\
    \ {\n      pool = new Node[S + 10];\n      pool[0].l = pool[0].r = pool[0].cnt\
    \ = 0;\n    }\n  }\n\n  NodePtr my_new(const Key &k, const Val &v) {\n    pool[ptr].l\
    \ = pool[ptr].r = 0;\n    pool[ptr].key = k;\n    pool[ptr].val = v;\n    pool[ptr].cnt\
    \ = 1;\n    return ptr++;\n  }\n\n  NodePtr merge(NodePtr l, NodePtr r) {\n  \
    \  if (!l || !r) return l ? l : r;\n    NodePtr res;\n    NodePtr *pre = &res;\n\
    \    while (true) {\n      if (!l || !r) {\n        *pre = l ? l : r;\n      \
    \  break;\n      }\n      uint32_t s = pool[l].cnt + pool[r].cnt;\n      if (uint32_t((rng()\
    \ * s) >> 32) < pool[l].cnt) {\n        *pre = l;\n        pool[l].cnt = s + 1;\n\
    \        pre = &(pool[l].r);\n        l = pool[l].r;\n      } else {\n       \
    \ *pre = r;\n        pool[r].cnt = s + 1;\n        pre = &(pool[r].l);\n     \
    \   r = pool[r].l;\n      }\n    }\n    return res;\n  }\n\n  pair<NodePtr, NodePtr>\
    \ split(NodePtr t, const Key &x, int i = -1) {\n    if (i == -1) {\n      i =\
    \ 0;\n      while (t) {\n        buf[i++] = t;\n        t = x <= pool[t].key ?\
    \ pool[t].l : pool[t].r;\n      }\n    }\n    NodePtr l = 0, r = 0;\n    uint32_t\
    \ pre = 0;\n    while (i--) {\n      NodePtr t = buf[i];\n      if (x <= pool[t].key)\
    \ {\n        pool[t].l = r;\n        pool[t].cnt = (pre += pool[pool[t].r].cnt\
    \ + 1);\n        r = t;\n      } else {\n        pool[t].r = l;\n        pool[t].cnt\
    \ = (pre += pool[pool[t].l].cnt + 1);\n        l = t;\n      }\n    }\n    return\
    \ {l, r};\n  }\n\n  NodePtr _find(const Key &x) const {\n    NodePtr p = t;\n\
    \    while (p) {\n      if (x == pool[p].key) return p;\n      p = x < pool[p].key\
    \ ? pool[p].l : pool[p].r;\n    }\n    return 0;\n  }\n\n  Val &operator[](const\
    \ Key &x) {\n    NodePtr p = _find(x);\n    if (p) return pool[p].val;\n    NodePtr\
    \ l, r;\n    tie(l, r) = split(t, x);\n    NodePtr n = my_new(x, Val());\n   \
    \ t = merge(merge(l, n), r);\n    return pool[n].val;\n  }\n\n  void insert(const\
    \ Key &x, const Val &y) {\n    NodePtr p = t;\n    int i = 0;\n    while (p) {\n\
    \      if (pool[p].key == x) {\n        pool[p].val = y;\n        return;\n  \
    \    }\n      buf[i++] = p;\n      p = x < pool[p].key ? pool[p].l : pool[p].r;\n\
    \    }\n    NodePtr l, r;\n    tie(l, r) = split(t, x, i);\n    t = merge(merge(l,\
    \ my_new(x, y)), r);\n  }\n\n  Val get(const Key &x) const {\n    NodePtr p =\
    \ t;\n    while (p) {\n      if (x == pool[p].key) return pool[p].val;\n     \
    \ p = x < pool[p].key ? pool[p].l : pool[p].r;\n    }\n    return Val();\n  }\n\
    \n  int size() { return pool[t].cnt; }\n};\ntemplate <typename Key, typename Val,\
    \ int S>\ntypename OrderedMap<Key, Val, S>::Node *OrderedMap<Key, Val, S>::pool\
    \ = nullptr;\ntemplate <typename Key, typename Val, int S>\nint OrderedMap<Key,\
    \ Val, S>::ptr = 1;\ntemplate <typename Key, typename Val, int S>\ntypename OrderedMap<Key,\
    \ Val, S>::NodePtr OrderedMap<Key, Val, S>::buf[128] =\n    {};\n"
  dependsOn: []
  isVerificationFile: false
  path: balanced-binary-search-tree/rbst-ordered-map.hpp
  requiredBy: []
  timestamp: '2020-10-11 13:18:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: balanced-binary-search-tree/rbst-ordered-map.hpp
layout: document
redirect_from:
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp
- /library/balanced-binary-search-tree/rbst-ordered-map.hpp.html
title: balanced-binary-search-tree/rbst-ordered-map.hpp
---
