---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure-2d/dynamic-wavelet-matrix.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n// \u66F8\u304D\u639B\u3051 \n\ntemplate\
    \ <typename S, typename T, T (*f)(T, T), T (*I)(), int LOG = 20>\nstruct DynamicWaveletMatrix\
    \ {\n  static uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n\
    \    x_ = x_ ^ (x_ << 7);\n    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n\
    \  }\n\n  using P = pair<S, T>;\n  struct MultiSet {\n    struct MSNode {\n  \
    \    MSNode *l, *r;\n      P key;\n      int cnt;\n      MSNode(const P &p) :\
    \ l(nullptr), r(nullptr), key(p), cnt(1) {}\n    };\n\n    MultiSet() {}\n\n \
    \   static inline int count(const MSNode *t) { return t ? t->cnt : 0; }\n    static\
    \ MSNode *update(MSNode *t) {\n      t->cnt = count(t->l) + count(t->r) + 1;\n\
    \      return t;\n    }\n\n    static MSNode *merge(MSNode *l, MSNode *r) {\n\
    \      if (!l || !r) return l ? l : r;\n      if (int((rng() * (l->cnt + r->cnt))\
    \ >> 32) < l->cnt) {\n        l->r = merge(l->r, r);\n        return update(l);\n\
    \      } else {\n        r->l = merge(l, r->l);\n        return update(r);\n \
    \     }\n    }\n\n    static pair<MSNode *, MSNode *> split(MSNode *t, int k)\
    \ {\n      if (!t) return {nullptr, nullptr};\n      if (k <= count(t->l)) {\n\
    \        auto s = split(t->l, k);\n        t->l = s.second;\n        return {s.first,\
    \ update(t)};\n      } else {\n        auto s = split(t->r, k - count(t->l) -\
    \ 1);\n        t->r = s.first;\n        return {update(t), s.second};\n      }\n\
    \    }\n\n    static void insert(MSNode *&t, int k, const S &key, const T &val)\
    \ {\n      auto x = split(t, k);\n      t = merge(merge(x.first, new MSNode(make_pair(key,\
    \ val))), x.second);\n    }\n\n    static pair<int, bool> lower_bound(MSNode *t,\
    \ const S &x, const T &y) {\n      MSNode *p = t;\n      int ret = 0;\n      P\
    \ k = make_pair(x, y);\n      int exist = false;\n      while (p) {\n        if\
    \ (k == p->key) exist = true;\n        if (k <= p->key) {\n          p = p->l;\n\
    \        } else {\n          ret += count(p->l) + 1;\n          p = p->r;\n  \
    \      }\n      }\n      return make_pair(ret, exist);\n    }\n  };\n\n  struct\
    \ BBST {\n    struct BNode {\n      BNode *l, *r;\n      T key, sum;\n      int\
    \ cnt;\n      int cnt1;\n\n      BNode() {}\n\n      BNode(const T &k, bool b)\n\
    \          : l(nullptr), r(nullptr), key(k), sum(k), cnt(1), cnt1(b) {}\n    };\n\
    \n    BBST() {}\n\n    static inline int count(const BNode *t) { return t ? t->cnt\
    \ : 0; }\n\n    static inline int count1(const BNode *t) { return t ? t->cnt1\
    \ : 0; }\n\n    static inline T sum(const BNode *t) { return t ? t->sum : I();\
    \ }\n\n    static BNode *update(BNode *t) {\n      t->cnt = count(t->l) + count(t->r)\
    \ + 1;\n      t->cnt1 = count1(t->l) + count1(t->r) + t->cnt1;\n      t->sum =\
    \ f(f(sum(t->l), t->key), sum(t->r));\n      return t;\n    }\n\n    static BNode\
    \ *merge(BNode *l, BNode *r) {\n      if (!l || !r) return l ? l : r;\n      if\
    \ (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n        l->r = merge(l->r,\
    \ r);\n        return update(l);\n      } else {\n        r->l = merge(l, r->l);\n\
    \        return update(r);\n      }\n    }\n\n    static pair<BNode *, BNode *>\
    \ split(BNode *t, int k) {\n      if (!t) return {nullptr, nullptr};\n      if\
    \ (k <= count(t->l)) {\n        auto s = split(t->l, k);\n        t->l = s.second;\n\
    \        return {s.first, update(t)};\n      } else {\n        auto s = split(t->r,\
    \ k - count(t->l) - 1);\n        t->r = s.first;\n        return {update(t), s.second};\n\
    \      }\n    }\n\n    static void insert(BNode *&t, int k, const T &key, bool\
    \ b) {\n      auto x = split(t, k);\n      t = merge(merge(x.first, my_new(key,\
    \ b)), x.second);\n    }\n\n    static BNode *kth_element(BNode *t, int k) {\n\
    \      assert(k < count(t));\n      while (t) {\n        int l = count(t->l);\n\
    \        if (k == l) return t;\n        if (k < l) {\n          t = t->l;\n  \
    \      } else {\n          t = t->r;\n          k -= l + 1;\n        }\n     \
    \ }\n      exit(1);\n    }\n\n    static BNode *add(BNode *t, int k, const T &y)\
    \ {\n      assert(k < count(t));\n      int l = count(t->l);\n      BNode *ret\
    \ = nullptr;\n      if (k == l) {\n        t->key += y;\n        ret = t;\n  \
    \    } else if (k < l) {\n        ret = add(t->l, k, y);\n      } else {\n   \
    \     ret = add(t->r, k - l - 1, y);\n      }\n      t->sum = f(f(sum(t->l), t->key),\
    \ sum(t->r));\n      return ret;\n    }\n\n    static int size(BNode *t) { return\
    \ count(t); }\n\n    static T fold(BNode *t) { return sum(t); }\n  };\n\n  struct\
    \ Node {\n    typename BBST::BNode *bv;\n    Node *p[2];\n    Node() : bv(nullptr)\
    \ { p[0] = p[1] = nullptr; }\n  };\n\n  typename MultiSet::MSNode *xs;\n  Node\
    \ *root;\n\n  DynamicWaveletMatrix() : xs(nullptr), root(new Node) {}\n\n  void\
    \ add(const S &x, const T &y) {\n    int k;\n    bool exist;\n    tie(k, exist)\
    \ = MultiSet::lower_bound(xs, x, y);\n    Node *n = root;\n    if (exist) {\n\
    \      for (int h = LOG - 1; h >= 0; h--) {\n        int b = (y >> h) & 1;\n \
    \       auto bv_node = BBST::add(n->bv, k, y);\n        if (b) {\n          k\
    \ = BBST::count1(bv_node) - 1;\n        } else {\n          k = k - BBST::count1(bv_node);\n\
    \        }\n        assert(k >= 0);\n        assert(b->p[b] != nullptr);\n   \
    \     n = n->p[b];\n      }\n    } else {\n      MultiSet::insert(xs, k, x, y);\n\
    \      for (int h = LOG - 1; h >= 0; h--) {\n        int b = (y >> h) & 1;\n \
    \     }\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u66F8\
    \u304D\u639B\u3051 \n\ntemplate <typename S, typename T, T (*f)(T, T), T (*I)(),\
    \ int LOG = 20>\nstruct DynamicWaveletMatrix {\n  static uint64_t rng() {\n  \
    \  static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n    x_\
    \ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  using P = pair<S,\
    \ T>;\n  struct MultiSet {\n    struct MSNode {\n      MSNode *l, *r;\n      P\
    \ key;\n      int cnt;\n      MSNode(const P &p) : l(nullptr), r(nullptr), key(p),\
    \ cnt(1) {}\n    };\n\n    MultiSet() {}\n\n    static inline int count(const\
    \ MSNode *t) { return t ? t->cnt : 0; }\n    static MSNode *update(MSNode *t)\
    \ {\n      t->cnt = count(t->l) + count(t->r) + 1;\n      return t;\n    }\n\n\
    \    static MSNode *merge(MSNode *l, MSNode *r) {\n      if (!l || !r) return\
    \ l ? l : r;\n      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n \
    \       l->r = merge(l->r, r);\n        return update(l);\n      } else {\n  \
    \      r->l = merge(l, r->l);\n        return update(r);\n      }\n    }\n\n \
    \   static pair<MSNode *, MSNode *> split(MSNode *t, int k) {\n      if (!t) return\
    \ {nullptr, nullptr};\n      if (k <= count(t->l)) {\n        auto s = split(t->l,\
    \ k);\n        t->l = s.second;\n        return {s.first, update(t)};\n      }\
    \ else {\n        auto s = split(t->r, k - count(t->l) - 1);\n        t->r = s.first;\n\
    \        return {update(t), s.second};\n      }\n    }\n\n    static void insert(MSNode\
    \ *&t, int k, const S &key, const T &val) {\n      auto x = split(t, k);\n   \
    \   t = merge(merge(x.first, new MSNode(make_pair(key, val))), x.second);\n  \
    \  }\n\n    static pair<int, bool> lower_bound(MSNode *t, const S &x, const T\
    \ &y) {\n      MSNode *p = t;\n      int ret = 0;\n      P k = make_pair(x, y);\n\
    \      int exist = false;\n      while (p) {\n        if (k == p->key) exist =\
    \ true;\n        if (k <= p->key) {\n          p = p->l;\n        } else {\n \
    \         ret += count(p->l) + 1;\n          p = p->r;\n        }\n      }\n \
    \     return make_pair(ret, exist);\n    }\n  };\n\n  struct BBST {\n    struct\
    \ BNode {\n      BNode *l, *r;\n      T key, sum;\n      int cnt;\n      int cnt1;\n\
    \n      BNode() {}\n\n      BNode(const T &k, bool b)\n          : l(nullptr),\
    \ r(nullptr), key(k), sum(k), cnt(1), cnt1(b) {}\n    };\n\n    BBST() {}\n\n\
    \    static inline int count(const BNode *t) { return t ? t->cnt : 0; }\n\n  \
    \  static inline int count1(const BNode *t) { return t ? t->cnt1 : 0; }\n\n  \
    \  static inline T sum(const BNode *t) { return t ? t->sum : I(); }\n\n    static\
    \ BNode *update(BNode *t) {\n      t->cnt = count(t->l) + count(t->r) + 1;\n \
    \     t->cnt1 = count1(t->l) + count1(t->r) + t->cnt1;\n      t->sum = f(f(sum(t->l),\
    \ t->key), sum(t->r));\n      return t;\n    }\n\n    static BNode *merge(BNode\
    \ *l, BNode *r) {\n      if (!l || !r) return l ? l : r;\n      if (int((rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n        l->r = merge(l->r, r);\n  \
    \      return update(l);\n      } else {\n        r->l = merge(l, r->l);\n   \
    \     return update(r);\n      }\n    }\n\n    static pair<BNode *, BNode *> split(BNode\
    \ *t, int k) {\n      if (!t) return {nullptr, nullptr};\n      if (k <= count(t->l))\
    \ {\n        auto s = split(t->l, k);\n        t->l = s.second;\n        return\
    \ {s.first, update(t)};\n      } else {\n        auto s = split(t->r, k - count(t->l)\
    \ - 1);\n        t->r = s.first;\n        return {update(t), s.second};\n    \
    \  }\n    }\n\n    static void insert(BNode *&t, int k, const T &key, bool b)\
    \ {\n      auto x = split(t, k);\n      t = merge(merge(x.first, my_new(key, b)),\
    \ x.second);\n    }\n\n    static BNode *kth_element(BNode *t, int k) {\n    \
    \  assert(k < count(t));\n      while (t) {\n        int l = count(t->l);\n  \
    \      if (k == l) return t;\n        if (k < l) {\n          t = t->l;\n    \
    \    } else {\n          t = t->r;\n          k -= l + 1;\n        }\n      }\n\
    \      exit(1);\n    }\n\n    static BNode *add(BNode *t, int k, const T &y) {\n\
    \      assert(k < count(t));\n      int l = count(t->l);\n      BNode *ret = nullptr;\n\
    \      if (k == l) {\n        t->key += y;\n        ret = t;\n      } else if\
    \ (k < l) {\n        ret = add(t->l, k, y);\n      } else {\n        ret = add(t->r,\
    \ k - l - 1, y);\n      }\n      t->sum = f(f(sum(t->l), t->key), sum(t->r));\n\
    \      return ret;\n    }\n\n    static int size(BNode *t) { return count(t);\
    \ }\n\n    static T fold(BNode *t) { return sum(t); }\n  };\n\n  struct Node {\n\
    \    typename BBST::BNode *bv;\n    Node *p[2];\n    Node() : bv(nullptr) { p[0]\
    \ = p[1] = nullptr; }\n  };\n\n  typename MultiSet::MSNode *xs;\n  Node *root;\n\
    \n  DynamicWaveletMatrix() : xs(nullptr), root(new Node) {}\n\n  void add(const\
    \ S &x, const T &y) {\n    int k;\n    bool exist;\n    tie(k, exist) = MultiSet::lower_bound(xs,\
    \ x, y);\n    Node *n = root;\n    if (exist) {\n      for (int h = LOG - 1; h\
    \ >= 0; h--) {\n        int b = (y >> h) & 1;\n        auto bv_node = BBST::add(n->bv,\
    \ k, y);\n        if (b) {\n          k = BBST::count1(bv_node) - 1;\n       \
    \ } else {\n          k = k - BBST::count1(bv_node);\n        }\n        assert(k\
    \ >= 0);\n        assert(b->p[b] != nullptr);\n        n = n->p[b];\n      }\n\
    \    } else {\n      MultiSet::insert(xs, k, x, y);\n      for (int h = LOG -\
    \ 1; h >= 0; h--) {\n        int b = (y >> h) & 1;\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/dynamic-wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2020-11-12 23:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure-2d/dynamic-wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure-2d/dynamic-wavelet-matrix.hpp
- /library/data-structure-2d/dynamic-wavelet-matrix.hpp.html
title: data-structure-2d/dynamic-wavelet-matrix.hpp
---
