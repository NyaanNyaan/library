---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/persistent-union-find.hpp
    title: "\u5B8C\u5168\u6C38\u7D9AUnion-Find"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
    title: verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"data-structure/persistent-array.hpp\"\n\ntemplate <typename\
    \ T, int shift = 4>\nstruct PersistentArray {\n  struct Node {\n    Node *ns[1\
    \ << shift];\n    Node() { memset(ns, 0, sizeof(ns)); }\n    Node(const Node &other)\
    \ { memcpy(ns, other.ns, sizeof(ns)); }\n    Node(const Node *other) { memcpy(ns,\
    \ other->ns, sizeof(ns)); }\n  };\n  inline Node *my_new() { return new Node();\
    \ }\n  inline Node *my_new(const Node &other) { return new Node(other); }\n  inline\
    \ Node *my_new(const Node *other) { return new Node(other); }\n  inline T *my_new_leaf(const\
    \ T &val) { return new T{val}; }\n\n  using i64 = long long;\n  static constexpr\
    \ int mask = (1 << shift) - 1;\n  Node *root;\n  int depth;\n  T ID;\n\n  PersistentArray()\
    \ {}\n\n  PersistentArray(i64 MAX, T ID_ = T(0)) : root(my_new()), depth(0), ID(ID_)\
    \ {\n    while (MAX) ++depth, MAX >>= shift;\n  }\n\n  PersistentArray(const vector<T>\
    \ &v, T ID_ = T(0))\n      : root(my_new()), depth(0), ID(ID_) {\n    i64 MAX\
    \ = v.size();\n    while (MAX) ++depth, MAX >>= shift;\n    for (int i = 0; i\
    \ < (int)v.size(); i++) {\n      Node *n = root;\n      for (int k = i, d = depth;\
    \ d; d--) {\n        if (!(n->ns[k & mask])) {\n          if (d == 1)\n      \
    \      n->ns[k & mask] = reinterpret_cast<Node *>(my_new_leaf(v[i]));\n      \
    \    else\n            n->ns[k & mask] = my_new();\n        }\n        n = n->ns[k\
    \ & mask];\n        k >>= shift;\n      }\n    }\n  }\n\n  T get(Node *n, i64\
    \ k) const {\n    for (int i = depth; i; --i) {\n      n = n ? n->ns[k & mask]\
    \ : nullptr;\n      k >>= shift;\n    }\n    return n ? *reinterpret_cast<T *>(n)\
    \ : ID;\n  }\n  T get(i64 k) const { return get(root, k); }\n\n  Node *update(Node\
    \ *n, i64 k, const T &val) {\n    stack<pair<Node *, int>> st;\n    for (int i\
    \ = depth; i; --i) {\n      st.emplace(n, k & mask);\n      n = n ? n->ns[k &\
    \ mask] : nullptr;\n      k >>= shift;\n    }\n    Node *chd = reinterpret_cast<Node\
    \ *>(my_new_leaf(val));\n    while (!st.empty()) {\n      Node *par;\n      int\
    \ k;\n      tie(par, k) = st.top();\n      st.pop();\n      Node *nxt = par ?\
    \ my_new(par) : my_new();\n      nxt->ns[k] = chd;\n      chd = nxt;\n    }\n\
    \    return root = chd;\n  }\n  Node *update(i64 k, const T &val) { return update(root,\
    \ k, val); }\n};\n\n/**\n * @brief \u6C38\u7D9A\u914D\u5217\n */\n"
  code: "#pragma once\n\ntemplate <typename T, int shift = 4>\nstruct PersistentArray\
    \ {\n  struct Node {\n    Node *ns[1 << shift];\n    Node() { memset(ns, 0, sizeof(ns));\
    \ }\n    Node(const Node &other) { memcpy(ns, other.ns, sizeof(ns)); }\n    Node(const\
    \ Node *other) { memcpy(ns, other->ns, sizeof(ns)); }\n  };\n  inline Node *my_new()\
    \ { return new Node(); }\n  inline Node *my_new(const Node &other) { return new\
    \ Node(other); }\n  inline Node *my_new(const Node *other) { return new Node(other);\
    \ }\n  inline T *my_new_leaf(const T &val) { return new T{val}; }\n\n  using i64\
    \ = long long;\n  static constexpr int mask = (1 << shift) - 1;\n  Node *root;\n\
    \  int depth;\n  T ID;\n\n  PersistentArray() {}\n\n  PersistentArray(i64 MAX,\
    \ T ID_ = T(0)) : root(my_new()), depth(0), ID(ID_) {\n    while (MAX) ++depth,\
    \ MAX >>= shift;\n  }\n\n  PersistentArray(const vector<T> &v, T ID_ = T(0))\n\
    \      : root(my_new()), depth(0), ID(ID_) {\n    i64 MAX = v.size();\n    while\
    \ (MAX) ++depth, MAX >>= shift;\n    for (int i = 0; i < (int)v.size(); i++) {\n\
    \      Node *n = root;\n      for (int k = i, d = depth; d; d--) {\n        if\
    \ (!(n->ns[k & mask])) {\n          if (d == 1)\n            n->ns[k & mask] =\
    \ reinterpret_cast<Node *>(my_new_leaf(v[i]));\n          else\n            n->ns[k\
    \ & mask] = my_new();\n        }\n        n = n->ns[k & mask];\n        k >>=\
    \ shift;\n      }\n    }\n  }\n\n  T get(Node *n, i64 k) const {\n    for (int\
    \ i = depth; i; --i) {\n      n = n ? n->ns[k & mask] : nullptr;\n      k >>=\
    \ shift;\n    }\n    return n ? *reinterpret_cast<T *>(n) : ID;\n  }\n  T get(i64\
    \ k) const { return get(root, k); }\n\n  Node *update(Node *n, i64 k, const T\
    \ &val) {\n    stack<pair<Node *, int>> st;\n    for (int i = depth; i; --i) {\n\
    \      st.emplace(n, k & mask);\n      n = n ? n->ns[k & mask] : nullptr;\n  \
    \    k >>= shift;\n    }\n    Node *chd = reinterpret_cast<Node *>(my_new_leaf(val));\n\
    \    while (!st.empty()) {\n      Node *par;\n      int k;\n      tie(par, k)\
    \ = st.top();\n      st.pop();\n      Node *nxt = par ? my_new(par) : my_new();\n\
    \      nxt->ns[k] = chd;\n      chd = nxt;\n    }\n    return root = chd;\n  }\n\
    \  Node *update(i64 k, const T &val) { return update(root, k, val); }\n};\n\n\
    /**\n * @brief \u6C38\u7D9A\u914D\u5217\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent-array.hpp
  requiredBy:
  - data-structure/persistent-union-find.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp
documentation_of: data-structure/persistent-array.hpp
layout: document
redirect_from:
- /library/data-structure/persistent-array.hpp
- /library/data-structure/persistent-array.hpp.html
title: "\u6C38\u7D9A\u914D\u5217"
---
