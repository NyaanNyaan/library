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
    \ <bits/stdc++.h>\nusing namespace std;\n\n// \u5B9F\u88C5\u7834\u7DBB\u3057\u305F\
    \u3000\u304A\u308F\u308A\n\ntemplate <typename S, typename T, T (*f)(T, T), T\
    \ (*I)(), int LOG = 20>\nstruct DynamicWaveletMatrix {\n  static uint64_t rng()\
    \ {\n    static uint64_t x_ = 88172645463325252ULL;\n    x_ = x_ ^ (x_ << 7);\n\
    \    x_ = x_ ^ (x_ >> 9);\n    return x_ & 0xFFFFFFFFull;\n  }\n\n  using P =\
    \ pair<S, T>;\n  struct MultiSet {\n    struct MSNode {\n      MSNode *l, *r;\n\
    \      P key;\n      int cnt;\n      MSNode(const P &p) : l(nullptr), r(nullptr),\
    \ key(p), cnt(1) {}\n    };\n\n    MultiSet() {}\n\n    static inline int count(const\
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
    \ BNode {\n      BNode *l, *r;\n      T key, sum;\n      int b, cnt, cnt1;\n\n\
    \      BNode() {}\n\n      BNode(const T &k, bool _b)\n          : l(nullptr),\
    \ r(nullptr), key(k), sum(k), b(_b), cnt(1), cnt1(_b) {}\n    };\n\n    BBST()\
    \ {}\n\n    static inline int count(const BNode *t) { return t ? t->cnt : 0; }\n\
    \n    static inline int count1(const BNode *t) { return t ? t->cnt1 : 0; }\n\n\
    \    static inline T sum(const BNode *t) { return t ? t->sum : I(); }\n\n    static\
    \ BNode *update(BNode *t) {\n      t->cnt = count(t->l) + count(t->r) + 1;\n \
    \     t->cnt1 = count1(t->l) + count1(t->r) + t->b;\n      t->sum = f(f(sum(t->l),\
    \ t->key), sum(t->r));\n      return t;\n    }\n\n    static BNode *merge(BNode\
    \ *l, BNode *r) {\n      if (!l || !r) return l ? l : r;\n      if (int((rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n        l->r = merge(l->r, r);\n  \
    \      return update(l);\n      } else {\n        r->l = merge(l, r->l);\n   \
    \     return update(r);\n      }\n    }\n\n    static pair<BNode *, BNode *> split(BNode\
    \ *t, int k) {\n      if (!t) return {nullptr, nullptr};\n      if (k <= count(t->l))\
    \ {\n        auto s = split(t->l, k);\n        t->l = s.second;\n        return\
    \ {s.first, update(t)};\n      } else {\n        auto s = split(t->r, k - count(t->l)\
    \ - 1);\n        t->r = s.first;\n        return {update(t), s.second};\n    \
    \  }\n    }\n\n    static int insert(BNode *&t, int k, const T &key, bool b) {\n\
    \      auto x = split(t, k);\n      int c1 = count1(x.first);\n      t = merge(merge(x.first,\
    \ new BNode(key, b)), x.second);\n      return c1;\n    }\n\n    static BNode\
    \ *kth_element(BNode *t, int k) {\n      assert(k < count(t));\n      while (t)\
    \ {\n        int l = count(t->l);\n        if (k == l) return t;\n        if (k\
    \ < l) {\n          t = t->l;\n        } else {\n          t = t->r;\n       \
    \   k -= l + 1;\n        }\n      }\n      exit(1);\n    }\n\n    static pair<BNode\
    \ *, int> add(BNode *t, int k, const T &y) {\n      assert(k < count(t));\n  \
    \    int l = count(t->l);\n      int c1;\n      BNode *ret;\n      if (k == l)\
    \ {\n        t->key += y;\n        ret = t;\n        c1 = count1(t->l);\n    \
    \  } else if (k < l) {\n        tie(ret, c1) = add(t->l, k, y);\n      } else\
    \ {\n        tie(ret, c1) = add(t->r, k - l - 1, y);\n        c1 += count(t->l);\n\
    \      }\n      t->sum = f(f(sum(t->l), t->key), sum(t->r));\n      return make_pair(ret,\
    \ c1);\n    }\n\n    //  fold [0, k)\n    static pair<T, int> presum(BNode *t,\
    \ int k) {\n      assert(k <= count(t));\n      T s = I();\n      int c1 = 0;\n\
    \      while (t != nullptr and k != 0) {\n        int l = count(t->l);\n     \
    \   if (k == l) {\n          s = f(s, t->l->sum);\n          c1 += t->l->cnt1;\n\
    \          break;\n        } else if (k < l) {\n          t = t->l;\n        }\
    \ else {\n          s = f(s, f(sum(t->l), t->key));\n          c1 += count1(t->l)\
    \ + t->b;\n          k -= l + 1;\n          t = t->r;\n        }\n      }\n  \
    \    return make_pair(s, c1);\n    }\n\n    static int size(BNode*t){return count(t);}\n\
    \  };\n\n  struct Node {\n    typename BBST::BNode *bv;\n    Node *p[2];\n   \
    \ Node() : bv(nullptr) { p[0] = p[1] = nullptr; }\n  };\n\n  typename MultiSet::MSNode\
    \ *xs;\n  Node *root;\n\n  DynamicWaveletMatrix() : xs(nullptr), root(new Node)\
    \ {}\n\n  void add(const S &x, const T &y) {\n    int k;\n    bool exist;\n  \
    \  tie(k, exist) = MultiSet::lower_bound(xs, x, y);\n    Node *n = root;\n   \
    \ if (exist) {\n      for (int h = LOG - 1; h >= 0; h--) {\n        int b = (y\
    \ >> h) & 1;\n        typename BBST::BNode *bv_node;\n        int c1;\n      \
    \  tie(bv_node, c1) = BBST::add(n->bv, k, y);\n        if (b) {\n          k =\
    \ c1;\n        } else {\n          k -= c1;\n        }\n        assert(k >= 0);\n\
    \        assert(h == 0 or n->p[b] != nullptr);\n        n = n->p[b];\n      }\n\
    \    } else {\n      MultiSet::insert(xs, k, x, y);\n      for (int h = LOG -\
    \ 1; h >= 0; h--) {\n        int b = (y >> h) & 1;\n        int c1 = BBST::insert(n->bv,\
    \ k, x, y);\n        if (b) {\n          k = c1;\n        } else {\n         \
    \ k -= c1;\n        }\n        if (h != 0 and n->p[b] == nullptr) n->p[b] = new\
    \ Node;\n        n = n->p[b];\n      }\n    }\n  }\n\n  T sum(int l, int r, T\
    \ upper) {\n    assert(upper < (1LL << LOG));\n    T res = 0;\n    auto n = root;\n\
    \    for (int h = LOG - 1; h >= 0; --h) {\n      if(n == nullptr) break;\n   \
    \   auto L = BBST::presum(n->bv, l);\n      auto R = BBST::presum(n->bv, r);\n\
    \      int s = size(n->bv);\n      if((upper >> h) & 1) {\n        \n      }\n\
    \    }\n  }\n};\n\nint f(int a, int b) { return a + b; }\n\nint e() { return 0;\
    \ }\n\nvoid solve() {\n  DynamicWaveletMatrix<int,int,f,e> wm;\n  wm.add(1,2);\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u5B9F\
    \u88C5\u7834\u7DBB\u3057\u305F\u3000\u304A\u308F\u308A\n\ntemplate <typename S,\
    \ typename T, T (*f)(T, T), T (*I)(), int LOG = 20>\nstruct DynamicWaveletMatrix\
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
    \ b, cnt, cnt1;\n\n      BNode() {}\n\n      BNode(const T &k, bool _b)\n    \
    \      : l(nullptr), r(nullptr), key(k), sum(k), b(_b), cnt(1), cnt1(_b) {}\n\
    \    };\n\n    BBST() {}\n\n    static inline int count(const BNode *t) { return\
    \ t ? t->cnt : 0; }\n\n    static inline int count1(const BNode *t) { return t\
    \ ? t->cnt1 : 0; }\n\n    static inline T sum(const BNode *t) { return t ? t->sum\
    \ : I(); }\n\n    static BNode *update(BNode *t) {\n      t->cnt = count(t->l)\
    \ + count(t->r) + 1;\n      t->cnt1 = count1(t->l) + count1(t->r) + t->b;\n  \
    \    t->sum = f(f(sum(t->l), t->key), sum(t->r));\n      return t;\n    }\n\n\
    \    static BNode *merge(BNode *l, BNode *r) {\n      if (!l || !r) return l ?\
    \ l : r;\n      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n     \
    \   l->r = merge(l->r, r);\n        return update(l);\n      } else {\n      \
    \  r->l = merge(l, r->l);\n        return update(r);\n      }\n    }\n\n    static\
    \ pair<BNode *, BNode *> split(BNode *t, int k) {\n      if (!t) return {nullptr,\
    \ nullptr};\n      if (k <= count(t->l)) {\n        auto s = split(t->l, k);\n\
    \        t->l = s.second;\n        return {s.first, update(t)};\n      } else\
    \ {\n        auto s = split(t->r, k - count(t->l) - 1);\n        t->r = s.first;\n\
    \        return {update(t), s.second};\n      }\n    }\n\n    static int insert(BNode\
    \ *&t, int k, const T &key, bool b) {\n      auto x = split(t, k);\n      int\
    \ c1 = count1(x.first);\n      t = merge(merge(x.first, new BNode(key, b)), x.second);\n\
    \      return c1;\n    }\n\n    static BNode *kth_element(BNode *t, int k) {\n\
    \      assert(k < count(t));\n      while (t) {\n        int l = count(t->l);\n\
    \        if (k == l) return t;\n        if (k < l) {\n          t = t->l;\n  \
    \      } else {\n          t = t->r;\n          k -= l + 1;\n        }\n     \
    \ }\n      exit(1);\n    }\n\n    static pair<BNode *, int> add(BNode *t, int\
    \ k, const T &y) {\n      assert(k < count(t));\n      int l = count(t->l);\n\
    \      int c1;\n      BNode *ret;\n      if (k == l) {\n        t->key += y;\n\
    \        ret = t;\n        c1 = count1(t->l);\n      } else if (k < l) {\n   \
    \     tie(ret, c1) = add(t->l, k, y);\n      } else {\n        tie(ret, c1) =\
    \ add(t->r, k - l - 1, y);\n        c1 += count(t->l);\n      }\n      t->sum\
    \ = f(f(sum(t->l), t->key), sum(t->r));\n      return make_pair(ret, c1);\n  \
    \  }\n\n    //  fold [0, k)\n    static pair<T, int> presum(BNode *t, int k) {\n\
    \      assert(k <= count(t));\n      T s = I();\n      int c1 = 0;\n      while\
    \ (t != nullptr and k != 0) {\n        int l = count(t->l);\n        if (k ==\
    \ l) {\n          s = f(s, t->l->sum);\n          c1 += t->l->cnt1;\n        \
    \  break;\n        } else if (k < l) {\n          t = t->l;\n        } else {\n\
    \          s = f(s, f(sum(t->l), t->key));\n          c1 += count1(t->l) + t->b;\n\
    \          k -= l + 1;\n          t = t->r;\n        }\n      }\n      return\
    \ make_pair(s, c1);\n    }\n\n    static int size(BNode*t){return count(t);}\n\
    \  };\n\n  struct Node {\n    typename BBST::BNode *bv;\n    Node *p[2];\n   \
    \ Node() : bv(nullptr) { p[0] = p[1] = nullptr; }\n  };\n\n  typename MultiSet::MSNode\
    \ *xs;\n  Node *root;\n\n  DynamicWaveletMatrix() : xs(nullptr), root(new Node)\
    \ {}\n\n  void add(const S &x, const T &y) {\n    int k;\n    bool exist;\n  \
    \  tie(k, exist) = MultiSet::lower_bound(xs, x, y);\n    Node *n = root;\n   \
    \ if (exist) {\n      for (int h = LOG - 1; h >= 0; h--) {\n        int b = (y\
    \ >> h) & 1;\n        typename BBST::BNode *bv_node;\n        int c1;\n      \
    \  tie(bv_node, c1) = BBST::add(n->bv, k, y);\n        if (b) {\n          k =\
    \ c1;\n        } else {\n          k -= c1;\n        }\n        assert(k >= 0);\n\
    \        assert(h == 0 or n->p[b] != nullptr);\n        n = n->p[b];\n      }\n\
    \    } else {\n      MultiSet::insert(xs, k, x, y);\n      for (int h = LOG -\
    \ 1; h >= 0; h--) {\n        int b = (y >> h) & 1;\n        int c1 = BBST::insert(n->bv,\
    \ k, x, y);\n        if (b) {\n          k = c1;\n        } else {\n         \
    \ k -= c1;\n        }\n        if (h != 0 and n->p[b] == nullptr) n->p[b] = new\
    \ Node;\n        n = n->p[b];\n      }\n    }\n  }\n\n  T sum(int l, int r, T\
    \ upper) {\n    assert(upper < (1LL << LOG));\n    T res = 0;\n    auto n = root;\n\
    \    for (int h = LOG - 1; h >= 0; --h) {\n      if(n == nullptr) break;\n   \
    \   auto L = BBST::presum(n->bv, l);\n      auto R = BBST::presum(n->bv, r);\n\
    \      int s = size(n->bv);\n      if((upper >> h) & 1) {\n        \n      }\n\
    \    }\n  }\n};\n\nint f(int a, int b) { return a + b; }\n\nint e() { return 0;\
    \ }\n\nvoid solve() {\n  DynamicWaveletMatrix<int,int,f,e> wm;\n  wm.add(1,2);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/dynamic-wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2020-11-19 22:42:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure-2d/dynamic-wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure-2d/dynamic-wavelet-matrix.hpp
- /library/data-structure-2d/dynamic-wavelet-matrix.hpp.html
title: data-structure-2d/dynamic-wavelet-matrix.hpp
---
