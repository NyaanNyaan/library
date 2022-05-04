---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-procedessor-problem-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-procedessor-problem-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1786.test.cpp
    title: verify/verify-yuki/yuki-1786.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: RBST-based Dynamic Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"segment-tree/rbst-segment-tree.hpp\"\n\ntemplate <typename\
    \ I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E,\
    \ E), T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree {\n  struct Node {\n \
    \   Node *l, *r;\n    I index;\n    T key, sum;\n    E lazy;\n    int cnt;\n \
    \   Node(const I &i, const T &t = ti())\n        : l(), r(), index(i), key(t),\
    \ sum(t), lazy(ei()), cnt(1) {}\n  };\n\n protected:\n  using Ptr = Node *;\n\
    \  template <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return\
    \ new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete t; }\n\n  inline\
    \ int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  static uint64_t\
    \ rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n    return x_ ^= x_\
    \ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  Ptr merge(Ptr l, Ptr r) {\n\
    \    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt))\
    \ >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n      return\
    \ update(l);\n    } else {\n      push(r);\n      r->l = merge(l, r->l);\n   \
    \   return update(r);\n    }\n  }\n\n  Ptr build(int l, int r, const vector<pair<I,\
    \ T>> &dat) {\n    if (l == r) return nullptr;\n    if (l + 1 == r) return my_new(dat[l].first,\
    \ dat[l].second);\n    int m = (l + r) / 2;\n    return merge(build(l, m, dat),\
    \ build(m, r, dat));\n  };\n\n  void push(Ptr t) {\n    if (!t) return;\n    if\
    \ (t->lazy != ei()) {\n      if (t->l) propagate(t->l, t->lazy);\n      if (t->r)\
    \ propagate(t->r, t->lazy);\n      t->lazy = ei();\n    }\n  }\n\n  Ptr update(Ptr\
    \ t) {\n    if (!t) return t;\n    //push(t);\n    t->cnt = 1;\n    t->sum = t->key;\n\
    \    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r)\
    \ t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n\
    \  void propagate(Ptr t, const E &x) {\n    if (!t) return;\n    t->lazy = h(t->lazy,\
    \ x);\n    t->key = g(t->key, x);\n    t->sum = g(t->sum, x);\n  }\n\n  // index\
    \ \u304C k \u3067\u3042\u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\
    \u308C\u3070 nullptr\n  Ptr find(Ptr t, I k) {\n    while (t) {\n      push(t);\n\
    \      if (k == t->index) return t;\n      if (k < t->index) {\n        t = t->l;\n\
    \      } else {\n        t = t->r;\n      }\n    }\n    return nullptr;\n  }\n\
    \n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr t, I\
    \ k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k == t->index)\
    \ {\n      Ptr tl = t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n\
    \    } else if (k < t->index) {\n      auto s = split_left(t->l, k);\n      t->l\
    \ = s.second;\n      return {s.first, update(t)};\n    } else {\n      auto s\
    \ = split_left(t->r, k);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_index(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->index) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r\
    \ = nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->index)\
    \ {\n      auto s = split_by_index(t->l, k);\n      t->l = s[2];\n      return\
    \ {{s[0], s[1], update(t)}};\n    } else {\n      auto s = split_by_index(t->r,\
    \ k);\n      t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\
    \n  // r \u672A\u6E80\n  T _fold_left(Ptr t, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index == r) {\n      return t->l ? t->l->sum : ti();\n\
    \    } else if (t->index > r) {\n      return _fold_left(t->l, r);\n    } else\
    \ {\n      T l = t->l ? t->l->sum : ti();\n      l = f(l, t->key);\n      return\
    \ f(l, _fold_left(t->r, r));\n    }\n  }\n\n  // l \u4EE5\u4E0A\n  T _fold_right(Ptr\
    \ t, I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->index == l) {\n\
    \      T r = t->r ? t->r->sum : ti();\n      return f(t->key, r);\n    } else\
    \ if (t->index < l) {\n      return _fold_right(t->r, l);\n    } else {\n    \
    \  T r = t->r ? t->r->sum : ti();\n      r = f(t->key, r);\n      return f(_fold_right(t->l,\
    \ l), r);\n    }\n  }\n\n  T _fold(Ptr t, I l, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index < l) return _fold(t->r, l, r);\n    if (t->index\
    \ >= r) return _fold(t->l, l, r);\n    // l <= t->index < r\n    T tl = _fold_right(t->l,\
    \ l);\n    T tr = _fold_left(t->r, r);\n    return f(f(tl, t->key), tr);\n  }\n\
    \n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E\
    \ index \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _min_index(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l)\
    \ t = t->l;\n    return t->index;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\
    \u6728\u306E\u4E0A\u3067\u6700\u5927\u306E index \u306F\uFF1F (t \u304C\u7A7A\u306E\
    \u5834\u5408\u306F failed)\n  I _max_index(Ptr t, const I &failed) {\n    if (t\
    \ == nullptr) return failed;\n    while (t->r) t = t->r;\n    return t->index;\n\
    \  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0,\
    \ i \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i\
    \ \u306F\u4F55\u304B\uFF1F\n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F\
    [0,\u53F3]\u304C\u771F\u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n\
    \  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\
    \u5834\u5408) \u306E\u5834\u5408\u306F failed\n  template <typename C, bool exclusive>\n\
    \  I _max_right(Ptr t, C check, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    push(t);\n    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]]\
    \ I prev = failed;\n    while (true) {\n      if (now->l != nullptr) {\n     \
    \   push(now->l);\n        auto pl = f(prod_now, now->l->sum);\n        if (check(pl))\
    \ {\n          prod_now = pl;\n        } else {\n          now = now->l;\n   \
    \       continue;\n        }\n      }\n      auto pl = f(prod_now, now->key);\n\
    \      if (!check(pl)) {\n        if constexpr (exclusive) {\n          return\
    \ now->index;\n        } else {\n          return now->l ? _max_index(now->l,\
    \ failed) : prev;\n        }\n      }\n      prod_now = pl;\n      if (now->r\
    \ == nullptr) {\n        if constexpr (exclusive) {\n          return failed;\n\
    \        } else {\n          return now->index;\n        }\n      }\n      push(now->r);\n\
    \      if constexpr (!exclusive) prev = now->index;\n      now = now->r;\n   \
    \ }\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001\
    i, inf) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E\
    \ i \u306F\u4F55\u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\
    \u306F \u5B58\u5728\u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve\
    \ \u304B\u3064 (\u7A7A \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool inclusive>\n  I _min_left(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n \
    \       auto pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n      \
    \    prod_now = pr;\n        } else {\n          now = now->r;\n          continue;\n\
    \        }\n      }\n      auto pr = f(now->key, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _min_index(now->r,\
    \ failed) : prev;\n        } else {\n          return now->index;\n        }\n\
    \      }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->index;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->index;\n      now = now->l;\n    }\n  }\n\n  void inner_dump(Ptr\
    \ t) {\n    push(t);\n    if (t->l) inner_dump(t->l);\n    cerr << \"## i = \"\
    \ << t->index << \", \";\n    cerr << \"\\tkey = \" << t->key << \", \";\n   \
    \ cerr << \"\\tsum = \" << t->sum << \", \";\n    cerr << \"\\tchild = \";\n \
    \   cerr << \"( \" << (t->l ? to_string(t->l->index) : \"nil\");\n    cerr <<\
    \ \", \";\n    cerr << (t->r ? to_string(t->r->index) : \"nil\");\n    cerr <<\
    \ \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_index(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->key = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->index)\
    \ break;\n      if (i < t->index) {\n        t = t->l;\n      } else {\n     \
    \   t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->key = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->key : ti();\n  }\n\n  // \u9802\u70B9\u306E\u524A\u9664\
    \n  void erase(I i) {\n    auto s = split_by_index(root, i);\n    if (s[1]) my_del(s[1]);\n\
    \    root = merge(s[0], s[2]);\n  }\n\n  // \u7BC4\u56F2\u4F5C\u7528\n  void apply(I\
    \ l, I r, const E &e) {\n    auto [x, aux] = split_left(root, l);\n    auto [y,\
    \ z] = split_left(aux, r);\n    propagate(y, e);\n    root = merge(merge(x, y),\
    \ z);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\n  T fold(I l, I r) {\n    return\
    \ _fold(root, l, r);\n    // auto [x, aux] = split_left(root, l);\n    // auto\
    \ [y, z] = split_left(aux, r);\n    // T res = y ? y->sum : ti();\n    // root\
    \ = merge(merge(x, y), z);\n    // return res;\n  }\n\n  // n \u672A\u6E80\u306E\
    \ i \u306E\u3046\u3061\u3001[i, n) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n\
    \  I min_left(I n, C check, I failed) {\n    assert(check(ti()) == true);\n  \
    \  auto [x, y] = split_left(root, n);\n    I res = _min_left<C, true>(x, check,\
    \ failed);\n    root = merge(x, y);\n    return res;\n  }\n\n  // n \u672A\u6E80\
    \u306E i \u306E\u3046\u3061\u3001(i, n) \u306E\u533A\u9593 fold \u304C true \u306B\
    \u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\
    \u305F\u308A (\u5DE6\u7AEF, n) \u304C \u771F\u306E\u5834\u5408\u306F minus_infty\
    \ \u3092\u8FD4\u3059)\n  template <typename C>\n  I min_left_exclusive(I n, C\
    \ check, I minus_infty) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ split_left(root, n);\n    I res = _min_left<C, false>(x, check, minus_infty);\n\
    \    root = merge(x, y);\n    return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i\
    \ \u306E\u3046\u3061\u3001[n, i) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\u305F\
    \u308A [n, \u53F3\u7AEF] \u304C true \u306E\u5834\u5408\u306F infty \u3092\u8FD4\
    \u3059)\n  template <typename C>\n  I max_right(I n, C check, I infty) {\n   \
    \ assert(check(ti()) == true);\n    auto [x, y] = split_left(root, n);\n    I\
    \ res = _max_right<C, true>(y, check, infty);\n    root = merge(x, y);\n    return\
    \ res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i \u306E\u3046\u3061\u3001[n, i] \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F failed \u3092\
    \u8FD4\u3059)\n  template <typename C>\n  I max_right_inclusive(I n, C check,\
    \ I failed) {\n    assert(check(ti()) == true);\n    auto [x, y] = split_left(root,\
    \ n);\n    I res = _max_right<C, false>(y, check, failed);\n    root = merge(x,\
    \ y);\n    return res;\n  }\n\n  void dump() { inner_dump(root); }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\n\ntemplate <typename T>\nT g(T l, bool) {\n  return l;\n\
    }\nbool h(bool, bool) { return false; }\nbool ei() { return false; }\n\ntemplate\
    \ <typename I, typename T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree = RBSTLazySegmentTree<I,\
    \ T, bool, f, g, h, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\nusing RBSTSegmentTreeImpl::RBSTSegmentTree;\n\
    \n/**\n * @brief RBST-based Dynamic Lazy Segment Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename I, typename T, typename E, T (*f)(T, T),\
    \ T (*g)(T, E),\n          E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree\
    \ {\n  struct Node {\n    Node *l, *r;\n    I index;\n    T key, sum;\n    E lazy;\n\
    \    int cnt;\n    Node(const I &i, const T &t = ti())\n        : l(), r(), index(i),\
    \ key(t), sum(t), lazy(ei()), cnt(1) {}\n  };\n\n protected:\n  using Ptr = Node\
    \ *;\n  template <typename... Args>\n  inline Ptr my_new(Args... args) {\n   \
    \ return new Node(args...);\n  }\n  inline void my_del(Ptr t) { delete t; }\n\n\
    \  inline int count(const Ptr t) const { return t ? t->cnt : 0; }\n\n  static\
    \ uint64_t rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n    return\
    \ x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  Ptr merge(Ptr l,\
    \ Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt\
    \ + r->cnt)) >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n\
    \      return update(l);\n    } else {\n      push(r);\n      r->l = merge(l,\
    \ r->l);\n      return update(r);\n    }\n  }\n\n  Ptr build(int l, int r, const\
    \ vector<pair<I, T>> &dat) {\n    if (l == r) return nullptr;\n    if (l + 1 ==\
    \ r) return my_new(dat[l].first, dat[l].second);\n    int m = (l + r) / 2;\n \
    \   return merge(build(l, m, dat), build(m, r, dat));\n  };\n\n  void push(Ptr\
    \ t) {\n    if (!t) return;\n    if (t->lazy != ei()) {\n      if (t->l) propagate(t->l,\
    \ t->lazy);\n      if (t->r) propagate(t->r, t->lazy);\n      t->lazy = ei();\n\
    \    }\n  }\n\n  Ptr update(Ptr t) {\n    if (!t) return t;\n    //push(t);\n\
    \    t->cnt = 1;\n    t->sum = t->key;\n    if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n    return t;\n  }\n\n  void propagate(Ptr t, const E &x) {\n \
    \   if (!t) return;\n    t->lazy = h(t->lazy, x);\n    t->key = g(t->key, x);\n\
    \    t->sum = g(t->sum, x);\n  }\n\n  // index \u304C k \u3067\u3042\u308B\u30CE\
    \u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\u3070 nullptr\n  Ptr find(Ptr\
    \ t, I k) {\n    while (t) {\n      push(t);\n      if (k == t->index) return\
    \ t;\n      if (k < t->index) {\n        t = t->l;\n      } else {\n        t\
    \ = t->r;\n      }\n    }\n    return nullptr;\n  }\n\n  // [k \u672A\u6E80, k\
    \ \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr t, I k) {\n    if (!t) return\
    \ {nullptr, nullptr};\n    push(t);\n    if (k == t->index) {\n      Ptr tl =\
    \ t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n    } else if (k\
    \ < t->index) {\n      auto s = split_left(t->l, k);\n      t->l = s.second;\n\
    \      return {s.first, update(t)};\n    } else {\n      auto s = split_left(t->r,\
    \ k);\n      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n\
    \n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_index(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->index) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r\
    \ = nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->index)\
    \ {\n      auto s = split_by_index(t->l, k);\n      t->l = s[2];\n      return\
    \ {{s[0], s[1], update(t)}};\n    } else {\n      auto s = split_by_index(t->r,\
    \ k);\n      t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\
    \n  // r \u672A\u6E80\n  T _fold_left(Ptr t, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index == r) {\n      return t->l ? t->l->sum : ti();\n\
    \    } else if (t->index > r) {\n      return _fold_left(t->l, r);\n    } else\
    \ {\n      T l = t->l ? t->l->sum : ti();\n      l = f(l, t->key);\n      return\
    \ f(l, _fold_left(t->r, r));\n    }\n  }\n\n  // l \u4EE5\u4E0A\n  T _fold_right(Ptr\
    \ t, I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->index == l) {\n\
    \      T r = t->r ? t->r->sum : ti();\n      return f(t->key, r);\n    } else\
    \ if (t->index < l) {\n      return _fold_right(t->r, l);\n    } else {\n    \
    \  T r = t->r ? t->r->sum : ti();\n      r = f(t->key, r);\n      return f(_fold_right(t->l,\
    \ l), r);\n    }\n  }\n\n  T _fold(Ptr t, I l, I r) {\n    if (!t) return ti();\n\
    \    push(t);\n    if (t->index < l) return _fold(t->r, l, r);\n    if (t->index\
    \ >= r) return _fold(t->l, l, r);\n    // l <= t->index < r\n    T tl = _fold_right(t->l,\
    \ l);\n    T tr = _fold_left(t->r, r);\n    return f(f(tl, t->key), tr);\n  }\n\
    \n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E\
    \ index \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _min_index(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l)\
    \ t = t->l;\n    return t->index;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\
    \u6728\u306E\u4E0A\u3067\u6700\u5927\u306E index \u306F\uFF1F (t \u304C\u7A7A\u306E\
    \u5834\u5408\u306F failed)\n  I _max_index(Ptr t, const I &failed) {\n    if (t\
    \ == nullptr) return failed;\n    while (t->r) t = t->r;\n    return t->index;\n\
    \  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0,\
    \ i \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i\
    \ \u306F\u4F55\u304B\uFF1F\n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F\
    [0,\u53F3]\u304C\u771F\u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n\
    \  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\
    \u5834\u5408) \u306E\u5834\u5408\u306F failed\n  template <typename C, bool exclusive>\n\
    \  I _max_right(Ptr t, C check, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    push(t);\n    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]]\
    \ I prev = failed;\n    while (true) {\n      if (now->l != nullptr) {\n     \
    \   push(now->l);\n        auto pl = f(prod_now, now->l->sum);\n        if (check(pl))\
    \ {\n          prod_now = pl;\n        } else {\n          now = now->l;\n   \
    \       continue;\n        }\n      }\n      auto pl = f(prod_now, now->key);\n\
    \      if (!check(pl)) {\n        if constexpr (exclusive) {\n          return\
    \ now->index;\n        } else {\n          return now->l ? _max_index(now->l,\
    \ failed) : prev;\n        }\n      }\n      prod_now = pl;\n      if (now->r\
    \ == nullptr) {\n        if constexpr (exclusive) {\n          return failed;\n\
    \        } else {\n          return now->index;\n        }\n      }\n      push(now->r);\n\
    \      if constexpr (!exclusive) prev = now->index;\n      now = now->r;\n   \
    \ }\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001\
    i, inf) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E\
    \ i \u306F\u4F55\u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\
    \u306F \u5B58\u5728\u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve\
    \ \u304B\u3064 (\u7A7A \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool inclusive>\n  I _min_left(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n \
    \       auto pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n      \
    \    prod_now = pr;\n        } else {\n          now = now->r;\n          continue;\n\
    \        }\n      }\n      auto pr = f(now->key, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _min_index(now->r,\
    \ failed) : prev;\n        } else {\n          return now->index;\n        }\n\
    \      }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->index;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->index;\n      now = now->l;\n    }\n  }\n\n  void inner_dump(Ptr\
    \ t) {\n    push(t);\n    if (t->l) inner_dump(t->l);\n    cerr << \"## i = \"\
    \ << t->index << \", \";\n    cerr << \"\\tkey = \" << t->key << \", \";\n   \
    \ cerr << \"\\tsum = \" << t->sum << \", \";\n    cerr << \"\\tchild = \";\n \
    \   cerr << \"( \" << (t->l ? to_string(t->l->index) : \"nil\");\n    cerr <<\
    \ \", \";\n    cerr << (t->r ? to_string(t->r->index) : \"nil\");\n    cerr <<\
    \ \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_index(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->key = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->index)\
    \ break;\n      if (i < t->index) {\n        t = t->l;\n      } else {\n     \
    \   t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->key = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->key : ti();\n  }\n\n  // \u9802\u70B9\u306E\u524A\u9664\
    \n  void erase(I i) {\n    auto s = split_by_index(root, i);\n    if (s[1]) my_del(s[1]);\n\
    \    root = merge(s[0], s[2]);\n  }\n\n  // \u7BC4\u56F2\u4F5C\u7528\n  void apply(I\
    \ l, I r, const E &e) {\n    auto [x, aux] = split_left(root, l);\n    auto [y,\
    \ z] = split_left(aux, r);\n    propagate(y, e);\n    root = merge(merge(x, y),\
    \ z);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\n  T fold(I l, I r) {\n    return\
    \ _fold(root, l, r);\n    // auto [x, aux] = split_left(root, l);\n    // auto\
    \ [y, z] = split_left(aux, r);\n    // T res = y ? y->sum : ti();\n    // root\
    \ = merge(merge(x, y), z);\n    // return res;\n  }\n\n  // n \u672A\u6E80\u306E\
    \ i \u306E\u3046\u3061\u3001[i, n) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n\
    \  I min_left(I n, C check, I failed) {\n    assert(check(ti()) == true);\n  \
    \  auto [x, y] = split_left(root, n);\n    I res = _min_left<C, true>(x, check,\
    \ failed);\n    root = merge(x, y);\n    return res;\n  }\n\n  // n \u672A\u6E80\
    \u306E i \u306E\u3046\u3061\u3001(i, n) \u306E\u533A\u9593 fold \u304C true \u306B\
    \u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\
    \u305F\u308A (\u5DE6\u7AEF, n) \u304C \u771F\u306E\u5834\u5408\u306F minus_infty\
    \ \u3092\u8FD4\u3059)\n  template <typename C>\n  I min_left_exclusive(I n, C\
    \ check, I minus_infty) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ split_left(root, n);\n    I res = _min_left<C, false>(x, check, minus_infty);\n\
    \    root = merge(x, y);\n    return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i\
    \ \u306E\u3046\u3061\u3001[n, i) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\u305F\
    \u308A [n, \u53F3\u7AEF] \u304C true \u306E\u5834\u5408\u306F infty \u3092\u8FD4\
    \u3059)\n  template <typename C>\n  I max_right(I n, C check, I infty) {\n   \
    \ assert(check(ti()) == true);\n    auto [x, y] = split_left(root, n);\n    I\
    \ res = _max_right<C, true>(y, check, infty);\n    root = merge(x, y);\n    return\
    \ res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i \u306E\u3046\u3061\u3001[n, i] \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F failed \u3092\
    \u8FD4\u3059)\n  template <typename C>\n  I max_right_inclusive(I n, C check,\
    \ I failed) {\n    assert(check(ti()) == true);\n    auto [x, y] = split_left(root,\
    \ n);\n    I res = _max_right<C, false>(y, check, failed);\n    root = merge(x,\
    \ y);\n    return res;\n  }\n\n  void dump() { inner_dump(root); }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\n\ntemplate <typename T>\nT g(T l, bool) {\n  return l;\n\
    }\nbool h(bool, bool) { return false; }\nbool ei() { return false; }\n\ntemplate\
    \ <typename I, typename T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree = RBSTLazySegmentTree<I,\
    \ T, bool, f, g, h, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\nusing RBSTSegmentTreeImpl::RBSTSegmentTree;\n\
    \n/**\n * @brief RBST-based Dynamic Lazy Segment Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/rbst-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-13 15:07:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1786.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
  - verify/verify-yosupo-ds/yosupo-procedessor-problem-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
documentation_of: segment-tree/rbst-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/rbst-segment-tree.hpp
- /library/segment-tree/rbst-segment-tree.hpp.html
title: RBST-based Dynamic Lazy Segment Tree
---
