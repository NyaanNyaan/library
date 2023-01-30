---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-associative-array-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-associative-array-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-range-sum-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-range-sum-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0789.test.cpp
    title: verify/verify-yuki/yuki-0789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dynamic Segment Tree
    links: []
  bundledCode: "#line 2 \"segment-tree/dynamic-segment-tree.hpp\"\n\ntemplate <typename\
    \ T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n          T (*ti)(),\
    \ E (*ei)()>\nstruct DynamicLazySegmentTree {\n  using ll = long long;\n  struct\
    \ Node;\n  using Ptr = Node *;\n\n  struct Node {\n    Ptr l, r;\n    T sum;\n\
    \    E laz;\n    Node() : l(nullptr), r(nullptr), sum(ti()), laz(ei()) {}\n  };\n\
    \n  Ptr root;\n  ll Rmax;\n  DynamicLazySegmentTree(ll n = 0) {\n    Rmax = 2;\n\
    \    while (Rmax <= n) Rmax *= 2;\n    root = my_new();\n  }\n\n  // get a[x]\n\
    \  T get_val(ll x) {\n    ll L = 0, R = Rmax;\n    Ptr t = root;\n    while (L\
    \ + 1 < R) {\n      push(t);\n      ll M = (L + R) / 2;\n      if (x < M) {\n\
    \        if (!t->l) return ti();\n        t = t->l, R = M;\n      } else {\n \
    \       if (!t->r) return ti();\n        t = t->r, L = M;\n      }\n    }\n  \
    \  return t->sum;\n  }\n  // a[i] <- x\n  void set_val(ll i, const T &x) { _set_val(root,\
    \ 0, Rmax, i, x); }\n  // apply x to a[l], a[l+1], ..., a[r-1]\n  void apply(ll\
    \ l, ll r, const E &x) { _apply(root, 0, Rmax, l, r, x); }\n  // get sum(a[l],\
    \ a[l+1], ..., a[r-1])\n  T fold(ll l, ll r) { return _fold(root, 0, Rmax, l,\
    \ r); }\n  // \u7834\u58CA\u7684\u3002\u307E\u305F\u3001key \u304C\u7B49\u3057\
    \u3044\u8981\u7D20\u304C\u3042\u308B\u5834\u5408\u306F\u672A\u5B9A\u7FA9\n  void\
    \ merge(DynamicLazySegmentTree &rhs) { root = _merge(root, rhs.root); }\n\n private:\n\
    \  DynamicLazySegmentTree(Ptr _root, ll _Rmax) : root(_root), Rmax(_Rmax) {}\n\
    \n  Ptr my_new() { return new Node{}; }\n  void my_del(Ptr p) { delete p; }\n\n\
    \  void propagate(Ptr t, const E &x) {\n    assert(t != nullptr && x != ei());\n\
    \    t->laz = h(t->laz, x);\n    t->sum = g(t->sum, x);\n  }\n  void push(Ptr\
    \ t) {\n    assert(t != nullptr);\n    if (t->laz == ei()) return;\n    if (!t->l)\
    \ t->l = my_new();\n    if (!t->r) t->r = my_new();\n    propagate(t->l, t->laz);\n\
    \    propagate(t->r, t->laz);\n    t->laz = ei();\n  }\n  void update(Ptr t) {\n\
    \    assert(t->laz == ei());\n    t->sum = f(t->l ? t->l->sum : ti(), t->r ? t->r->sum\
    \ : ti());\n  }\n\n  void _set_val(Ptr t, ll L, ll R, ll i, const T &x) {\n  \
    \  assert(L <= i && i < R && t);\n    if (L + 1 == R) {\n      t->sum = x;\n \
    \     return;\n    }\n    ll M = (L + R) / 2;\n    push(t);\n    if (i < M) {\n\
    \      if (!t->l) t->l = my_new();\n      _set_val(t->l, L, M, i, x);\n    } else\
    \ {\n      if (!t->r) t->r = my_new();\n      _set_val(t->r, M, R, i, x);\n  \
    \  }\n    update(t);\n  }\n\n  void _apply(Ptr t, ll L, ll R, ll a, ll b, const\
    \ E &x) {\n    assert(a <= b && a < R && L < b && t);\n    if (L == a and R ==\
    \ b) {\n      propagate(t, x);\n      if (L + 1 == R) t->laz = ei();\n      return;\n\
    \    }\n    ll M = (L + R) / 2;\n    push(t);\n    if (a < M) {\n      if (!t->l)\
    \ t->l = my_new();\n      _apply(t->l, L, M, a, min(b, M), x);\n    }\n    if\
    \ (M < b) {\n      if (!t->r) t->r = my_new();\n      _apply(t->r, M, R, max(a,\
    \ M), b, x);\n    }\n    update(t);\n    return;\n  }\n\n  T _fold(Ptr t, ll L,\
    \ ll R, ll a, ll b) {\n    assert(a <= b && a < R && L < b && t);\n    if (L ==\
    \ a and R == b) return t->sum;\n    ll M = (L + R) / 2;\n    push(t);\n    T v\
    \ = ti();\n    if (a < M && t->l) v = f(_fold(t->l, L, M, a, min(b, M)), v);\n\
    \    if (M < b && t->r) v = f(v, _fold(t->r, M, R, max(a, M), b));\n    return\
    \ v;\n  }\n\n  Ptr _merge(Ptr t1, Ptr t2) {\n    if (!t1 or !t2) return t1 ? t1\
    \ : t2;\n    assert(t1->laz == ei() && t2->laz == ei());\n    t1->l = merge(t1->l,\
    \ t2->l);\n    t1->r = merge(t1->r, t2->r);\n    update(t1), my_del(t2);\n   \
    \ return t1;\n  }\n\n  /*\n  // [L, x), [x, R) \u3067 split\n  pair<Ptr, Ptr>\
    \ _split(Ptr t1, ll L, ll R, ll x) {\n    if (!t1) return {nullptr, nullptr};\n\
    \    assert(t1->laz == ei());\n    Ptr t2 = my_new();\n    ll M = (L + R) / 2;\n\
    \  }\n  */\n};\n\nnamespace DynamicSegmentTreeImpl {\ntemplate <typename T>\n\
    T g(T l, bool) {\n  return l;\n}\nbool h(bool, bool) { return false; }\nbool ei()\
    \ { return false; }\n\ntemplate <typename T, T (*f)(T, T), T (*ti)()>\nusing DynamicSegmentTree\
    \ = DynamicLazySegmentTree<T, bool, f, g, h, ti, ei>;\n}  // namespace DynamicSegmentTreeImpl\n\
    \nusing DynamicSegmentTreeImpl::DynamicSegmentTree;\n\n/**\n * @brief Dynamic\
    \ Segment Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T,\
    \ E), E (*h)(E, E),\n          T (*ti)(), E (*ei)()>\nstruct DynamicLazySegmentTree\
    \ {\n  using ll = long long;\n  struct Node;\n  using Ptr = Node *;\n\n  struct\
    \ Node {\n    Ptr l, r;\n    T sum;\n    E laz;\n    Node() : l(nullptr), r(nullptr),\
    \ sum(ti()), laz(ei()) {}\n  };\n\n  Ptr root;\n  ll Rmax;\n  DynamicLazySegmentTree(ll\
    \ n = 0) {\n    Rmax = 2;\n    while (Rmax <= n) Rmax *= 2;\n    root = my_new();\n\
    \  }\n\n  // get a[x]\n  T get_val(ll x) {\n    ll L = 0, R = Rmax;\n    Ptr t\
    \ = root;\n    while (L + 1 < R) {\n      push(t);\n      ll M = (L + R) / 2;\n\
    \      if (x < M) {\n        if (!t->l) return ti();\n        t = t->l, R = M;\n\
    \      } else {\n        if (!t->r) return ti();\n        t = t->r, L = M;\n \
    \     }\n    }\n    return t->sum;\n  }\n  // a[i] <- x\n  void set_val(ll i,\
    \ const T &x) { _set_val(root, 0, Rmax, i, x); }\n  // apply x to a[l], a[l+1],\
    \ ..., a[r-1]\n  void apply(ll l, ll r, const E &x) { _apply(root, 0, Rmax, l,\
    \ r, x); }\n  // get sum(a[l], a[l+1], ..., a[r-1])\n  T fold(ll l, ll r) { return\
    \ _fold(root, 0, Rmax, l, r); }\n  // \u7834\u58CA\u7684\u3002\u307E\u305F\u3001\
    key \u304C\u7B49\u3057\u3044\u8981\u7D20\u304C\u3042\u308B\u5834\u5408\u306F\u672A\
    \u5B9A\u7FA9\n  void merge(DynamicLazySegmentTree &rhs) { root = _merge(root,\
    \ rhs.root); }\n\n private:\n  DynamicLazySegmentTree(Ptr _root, ll _Rmax) : root(_root),\
    \ Rmax(_Rmax) {}\n\n  Ptr my_new() { return new Node{}; }\n  void my_del(Ptr p)\
    \ { delete p; }\n\n  void propagate(Ptr t, const E &x) {\n    assert(t != nullptr\
    \ && x != ei());\n    t->laz = h(t->laz, x);\n    t->sum = g(t->sum, x);\n  }\n\
    \  void push(Ptr t) {\n    assert(t != nullptr);\n    if (t->laz == ei()) return;\n\
    \    if (!t->l) t->l = my_new();\n    if (!t->r) t->r = my_new();\n    propagate(t->l,\
    \ t->laz);\n    propagate(t->r, t->laz);\n    t->laz = ei();\n  }\n  void update(Ptr\
    \ t) {\n    assert(t->laz == ei());\n    t->sum = f(t->l ? t->l->sum : ti(), t->r\
    \ ? t->r->sum : ti());\n  }\n\n  void _set_val(Ptr t, ll L, ll R, ll i, const\
    \ T &x) {\n    assert(L <= i && i < R && t);\n    if (L + 1 == R) {\n      t->sum\
    \ = x;\n      return;\n    }\n    ll M = (L + R) / 2;\n    push(t);\n    if (i\
    \ < M) {\n      if (!t->l) t->l = my_new();\n      _set_val(t->l, L, M, i, x);\n\
    \    } else {\n      if (!t->r) t->r = my_new();\n      _set_val(t->r, M, R, i,\
    \ x);\n    }\n    update(t);\n  }\n\n  void _apply(Ptr t, ll L, ll R, ll a, ll\
    \ b, const E &x) {\n    assert(a <= b && a < R && L < b && t);\n    if (L == a\
    \ and R == b) {\n      propagate(t, x);\n      if (L + 1 == R) t->laz = ei();\n\
    \      return;\n    }\n    ll M = (L + R) / 2;\n    push(t);\n    if (a < M) {\n\
    \      if (!t->l) t->l = my_new();\n      _apply(t->l, L, M, a, min(b, M), x);\n\
    \    }\n    if (M < b) {\n      if (!t->r) t->r = my_new();\n      _apply(t->r,\
    \ M, R, max(a, M), b, x);\n    }\n    update(t);\n    return;\n  }\n\n  T _fold(Ptr\
    \ t, ll L, ll R, ll a, ll b) {\n    assert(a <= b && a < R && L < b && t);\n \
    \   if (L == a and R == b) return t->sum;\n    ll M = (L + R) / 2;\n    push(t);\n\
    \    T v = ti();\n    if (a < M && t->l) v = f(_fold(t->l, L, M, a, min(b, M)),\
    \ v);\n    if (M < b && t->r) v = f(v, _fold(t->r, M, R, max(a, M), b));\n   \
    \ return v;\n  }\n\n  Ptr _merge(Ptr t1, Ptr t2) {\n    if (!t1 or !t2) return\
    \ t1 ? t1 : t2;\n    assert(t1->laz == ei() && t2->laz == ei());\n    t1->l =\
    \ merge(t1->l, t2->l);\n    t1->r = merge(t1->r, t2->r);\n    update(t1), my_del(t2);\n\
    \    return t1;\n  }\n\n  /*\n  // [L, x), [x, R) \u3067 split\n  pair<Ptr, Ptr>\
    \ _split(Ptr t1, ll L, ll R, ll x) {\n    if (!t1) return {nullptr, nullptr};\n\
    \    assert(t1->laz == ei());\n    Ptr t2 = my_new();\n    ll M = (L + R) / 2;\n\
    \  }\n  */\n};\n\nnamespace DynamicSegmentTreeImpl {\ntemplate <typename T>\n\
    T g(T l, bool) {\n  return l;\n}\nbool h(bool, bool) { return false; }\nbool ei()\
    \ { return false; }\n\ntemplate <typename T, T (*f)(T, T), T (*ti)()>\nusing DynamicSegmentTree\
    \ = DynamicLazySegmentTree<T, bool, f, g, h, ti, ei>;\n}  // namespace DynamicSegmentTreeImpl\n\
    \nusing DynamicSegmentTreeImpl::DynamicSegmentTree;\n\n/**\n * @brief Dynamic\
    \ Segment Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-08-23 00:32:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-associative-array-dynamic-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-range-sum-dynamic-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
  - verify/verify-yuki/yuki-0789.test.cpp
documentation_of: segment-tree/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/dynamic-segment-tree.hpp
- /library/segment-tree/dynamic-segment-tree.hpp.html
title: Dynamic Segment Tree
---
