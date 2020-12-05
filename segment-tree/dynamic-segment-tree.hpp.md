---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0789.test.cpp
    title: verify/verify-yuki/yuki-0789.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/dynamic-segment-tree.hpp\"\n\n\n\ntemplate\
    \ <typename T, typename F, int NODES = 4194304>\nstruct DynamicSegmentTree {\n\
    \  using ll = long long;\n\n  struct Node {\n    T data;\n    Node *l, *r;\n \
    \   Node() {}\n    Node(const T &_data) : data(_data), l(nullptr), r(nullptr)\
    \ {}\n  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n  const F &f;\n  const T\
    \ ID;\n  Node *root;\n\n  DynamicSegmentTree(const vector<T> &v, const F &_f,\
    \ const T &_ID)\n      : pid(0), L(0), R((ll)v.size()), f(_f), ID(_ID) {\n   \
    \ pool = new Node[NODES];\n    root = build(v);\n  }\n\n  DynamicSegmentTree(const\
    \ ll &_L, const ll &_R, const F &_f, const T &_ID)\n      : pid(0), L(_L), R(_R),\
    \ f(_f), ID(_ID) {\n    pool = new Node[NODES];\n    root = my_new(ID);\n  }\n\
    \n  Node *my_new(const T &data) {\n    pool[pid].data = data;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n  Node *my_new(Node\
    \ *l, Node *r) {\n    pool[pid].data = f(l->data, r->data);\n    pool[pid].l =\
    \ l;\n    pool[pid].r = r;\n    return &(pool[pid++]);\n  }\n\n  Node *build(const\
    \ vector<T> &v) { return build(L, R, v); }\n\n  Node *build(ll l, ll r, const\
    \ vector<T> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n    ll m = (l + r)\
    \ >> 1;\n    return my_new(build(l, m, v), build(m, r, v));\n  }\n\n  void _update(ll\
    \ a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 == r) {\n      n->data\
    \ = x;\n      return;\n    }\n    ll m = (l + r) >> 1;\n    if (a < m) {\n   \
    \   if (!n->l) n->l = my_new(ID);\n      _update(a, x, n->l, l, m);\n    } else\
    \ {\n      if (!n->r) n->r = my_new(ID);\n      _update(a, x, n->r, m, r);\n \
    \   }\n    n->data = f(n->l ? (n->l)->data : ID, n->r ? (n->r)->data : ID);\n\
    \  }\n\n  void update(ll k, const T &x) { _update(k, x, root, L, R); }\n\n  void\
    \ add(ll k, const T &x) {\n    Node *n = root;\n    ll l = L, r = R;\n    n->data\
    \ = f(n->data, x);\n    while (r - l > 1) {\n      ll m = (l + r) >> 1;\n    \
    \  if (k < m) {\n        if (!n->l) n->l = my_new(ID);\n        n = n->l;\n  \
    \      r = m;\n      } else {\n        if (!n->r) n->r = my_new(ID);\n       \
    \ n = n->r;\n        l = m;\n      }\n      n->data = f(n->data, x);\n    }\n\
    \  }\n\n  T _query(ll a, ll b, Node *n, ll l, ll r) {\n    if (r <= a or b <=\
    \ l) return ID;\n    if (a <= l and r <= b) return n->data;\n    ll m = (l + r)\
    \ >> 1;\n    return f(n->l ? _query(a, b, n->l, l, m) : ID,\n             n->r\
    \ ? _query(a, b, n->r, m, r) : ID);\n  }\n\n  T query(ll a, ll b) { return _query(a,\
    \ b, root, L, R); }\n};\n"
  code: "#pragma once\n\n\n\ntemplate <typename T, typename F, int NODES = 4194304>\n\
    struct DynamicSegmentTree {\n  using ll = long long;\n\n  struct Node {\n    T\
    \ data;\n    Node *l, *r;\n    Node() {}\n    Node(const T &_data) : data(_data),\
    \ l(nullptr), r(nullptr) {}\n  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n \
    \ const F &f;\n  const T ID;\n  Node *root;\n\n  DynamicSegmentTree(const vector<T>\
    \ &v, const F &_f, const T &_ID)\n      : pid(0), L(0), R((ll)v.size()), f(_f),\
    \ ID(_ID) {\n    pool = new Node[NODES];\n    root = build(v);\n  }\n\n  DynamicSegmentTree(const\
    \ ll &_L, const ll &_R, const F &_f, const T &_ID)\n      : pid(0), L(_L), R(_R),\
    \ f(_f), ID(_ID) {\n    pool = new Node[NODES];\n    root = my_new(ID);\n  }\n\
    \n  Node *my_new(const T &data) {\n    pool[pid].data = data;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n  Node *my_new(Node\
    \ *l, Node *r) {\n    pool[pid].data = f(l->data, r->data);\n    pool[pid].l =\
    \ l;\n    pool[pid].r = r;\n    return &(pool[pid++]);\n  }\n\n  Node *build(const\
    \ vector<T> &v) { return build(L, R, v); }\n\n  Node *build(ll l, ll r, const\
    \ vector<T> &v) {\n    if (l + 1 == r) return my_new(v[l]);\n    ll m = (l + r)\
    \ >> 1;\n    return my_new(build(l, m, v), build(m, r, v));\n  }\n\n  void _update(ll\
    \ a, const T &x, Node *n, ll l, ll r) {\n    if (l + 1 == r) {\n      n->data\
    \ = x;\n      return;\n    }\n    ll m = (l + r) >> 1;\n    if (a < m) {\n   \
    \   if (!n->l) n->l = my_new(ID);\n      _update(a, x, n->l, l, m);\n    } else\
    \ {\n      if (!n->r) n->r = my_new(ID);\n      _update(a, x, n->r, m, r);\n \
    \   }\n    n->data = f(n->l ? (n->l)->data : ID, n->r ? (n->r)->data : ID);\n\
    \  }\n\n  void update(ll k, const T &x) { _update(k, x, root, L, R); }\n\n  void\
    \ add(ll k, const T &x) {\n    Node *n = root;\n    ll l = L, r = R;\n    n->data\
    \ = f(n->data, x);\n    while (r - l > 1) {\n      ll m = (l + r) >> 1;\n    \
    \  if (k < m) {\n        if (!n->l) n->l = my_new(ID);\n        n = n->l;\n  \
    \      r = m;\n      } else {\n        if (!n->r) n->r = my_new(ID);\n       \
    \ n = n->r;\n        l = m;\n      }\n      n->data = f(n->data, x);\n    }\n\
    \  }\n\n  T _query(ll a, ll b, Node *n, ll l, ll r) {\n    if (r <= a or b <=\
    \ l) return ID;\n    if (a <= l and r <= b) return n->data;\n    ll m = (l + r)\
    \ >> 1;\n    return f(n->l ? _query(a, b, n->l, l, m) : ID,\n             n->r\
    \ ? _query(a, b, n->r, m, r) : ID);\n  }\n\n  T query(ll a, ll b) { return _query(a,\
    \ b, root, L, R); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0789.test.cpp
documentation_of: segment-tree/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/dynamic-segment-tree.hpp
- /library/segment-tree/dynamic-segment-tree.hpp.html
title: segment-tree/dynamic-segment-tree.hpp
---
