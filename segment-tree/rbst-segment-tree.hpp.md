---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/rbst-segment-tree.test.cpp
    title: verify/verify-unit-test/rbst-segment-tree.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: RBST-based Dynamic Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"segment-tree/rbst-segment-tree.hpp\"\n\ntemplate <typename\
    \ I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E,\
    \ E), T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree {\n  struct Node {\n \
    \   Node *l, *r;\n    I key;\n    T val, sum;\n    E lazy;\n    int cnt;\n   \
    \ Node(const I &i, const T &t = ti())\n        : l(), r(), key(i), val(t), sum(t),\
    \ lazy(ei()), cnt(1) {}\n  };\n\n protected:\n  using Ptr = Node *;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return new Node(args...);\n\
    \  }\n  inline void my_del(Ptr t) { delete t; }\n\n  inline int count(const Ptr\
    \ t) const { return t ? t->cnt : 0; }\n\n  static uint64_t rng() {\n    static\
    \ uint64_t x_ = 88172645463325252ULL;\n    return x_ ^= x_ << 7, x_ ^= x_ >> 9,\
    \ x_ & 0xFFFFFFFFull;\n  }\n\n  Ptr merge(Ptr l, Ptr r) {\n    if (!l || !r) return\
    \ l ? l : r;\n    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n   \
    \   push(l);\n      l->r = merge(l->r, r);\n      return update(l);\n    } else\
    \ {\n      push(r);\n      r->l = merge(l, r->l);\n      return update(r);\n \
    \   }\n  }\n\n  Ptr build(int l, int r, const vector<pair<I, T>> &dat) {\n   \
    \ if (l == r) return nullptr;\n    if (l + 1 == r) return my_new(dat[l].first,\
    \ dat[l].second);\n    int m = (l + r) / 2;\n    return merge(build(l, m, dat),\
    \ build(m, r, dat));\n  };\n\n  void push([[maybe_unused]] Ptr t) {\n#pragma GCC\
    \ diagnostic ignored \"-Waddress\"\n    if constexpr (g != nullptr) {\n#pragma\
    \ GCC diagnostic warning \"-Waddress\"\n      if (!t) return;\n      if (t->lazy\
    \ != ei()) {\n        if (t->l) propagate(t->l, t->lazy);\n        if (t->r) propagate(t->r,\
    \ t->lazy);\n        t->lazy = ei();\n      }\n    }\n  }\n\n  Ptr update(Ptr\
    \ t) {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->val;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  void propagate([[maybe_unused]]\
    \ Ptr t, [[maybe_unused]] const E &x) {\n#pragma GCC diagnostic ignored \"-Waddress\"\
    \n    if constexpr (g != nullptr) {\n#pragma GCC diagnostic warning \"-Waddress\"\
    \n      if (!t) return;\n      t->lazy = h(t->lazy, x);\n      t->val = g(t->val,\
    \ x);\n      t->sum = g(t->sum, x);\n    }\n  }\n\n  // key \u304C k \u3067\u3042\
    \u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\u3070 nullptr\n\
    \  Ptr find(Ptr t, I k) {\n    while (t) {\n      push(t);\n      if (k == t->key)\
    \ return t;\n      t = k < t->key ? t->l : t->r;\n    }\n    return nullptr;\n\
    \  }\n\n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr\
    \ t, I k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k ==\
    \ t->key) {\n      Ptr tl = t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n\
    \    } else if (k < t->key) {\n      auto s = split_left(t->l, k);\n      t->l\
    \ = s.second;\n      return {s.first, update(t)};\n    } else {\n      auto s\
    \ = split_left(t->r, k);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_key(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->key) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r =\
    \ nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->key) {\n\
    \      auto s = split_by_key(t->l, k);\n      t->l = s[2];\n      return {{s[0],\
    \ s[1], update(t)}};\n    } else {\n      auto s = split_by_key(t->r, k);\n  \
    \    t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\n  //\
    \ x \u4EE5\u4E0A\u306E key \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F infty\n  I _lower_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n\
    \    while (!t) {\n      if (i == t->key) return i;\n      if (i < t->key) {\n\
    \        res = min(res, t->key);\n        t = t->l;\n      } else {\n        t\
    \ = t->l;\n      }\n    }\n    return res;\n  }\n\n  // x \u8D85\u904E\u306E key\
    \ \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F infty\n \
    \ I _upper_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n    while (!t)\
    \ {\n      if (i == t->key) return i;\n      if (i < t->key) {\n        res =\
    \ min(res, t->key);\n        t = t->l;\n      } else {\n        t = t->l;\n  \
    \    }\n    }\n    return res;\n  }\n\n  // [l, inf) \u3067\u3042\u308B\u5730\u70B9\
    \u306B apply\n  void _apply_left(Ptr t, I l, const E &e) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->key < l) {\n      _apply_left(t->r, l, e);\n    } else\
    \ if (t->key == l) {\n      t->val = g(t->val, e);\n      propagate(t->r, e);\n\
    \    } else {\n      _apply_left(t->l, l, e);\n      t->val = g(t->val, e);\n\
    \      propagate(t->r, e);\n    }\n    update(t);\n  }\n\n  // [-inf, r) \u3067\
    \u3042\u308B\u5730\u70B9\u306B apply\n  void _apply_right(Ptr t, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < r) {\n      propagate(t->l,\
    \ e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    } else\
    \ if (t->key == r) {\n      propagate(t->l, e);\n    } else {\n      _apply_right(t->l,\
    \ r, e);\n    }\n    update(t);\n  }\n\n  void _apply(Ptr t, I l, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < l) {\n      _apply(t->r,\
    \ l, r, e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n   \
    \   _apply_right(t->r, r, e);\n    } else if (t->key < r) {\n      _apply_left(t->l,\
    \ l, e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    }\
    \ else if (t->key == r) {\n      _apply_left(t->l, l, e);\n    } else {\n    \
    \  _apply(t->l, l, r, e);\n    }\n    update(t);\n  }\n\n  T _sum(const Ptr &t)\
    \ { return t ? t->sum : ti(); }\n\n  // l \u4EE5\u4E0A\n  T _fold_left(Ptr t,\
    \ I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n    \
    \  return _fold_left(t->r, l);\n    } else if (t->key == l) {\n      return f(t->val,\
    \ _fold_left(t->r, l));\n    } else {\n      T tl = _fold_left(t->l, l);\n   \
    \   return f(f(tl, t->val), _sum(t->r));\n    }\n  }\n\n  // r \u672A\u6E80\n\
    \  T _fold_right(Ptr t, I r) {\n    if (!t) return ti();\n    push(t);\n    if\
    \ (t->key < r) {\n      T tr = _fold_right(t->r, r);\n      return f(f(_sum(t->l),\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _sum(t->l);\n   \
    \ } else {\n      return _fold_right(t->l, r);\n    }\n  }\n\n  T _fold(Ptr t,\
    \ I l, I r) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n\
    \      return _fold(t->r, l, r);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_right(t->r, r));\n    } else if (t->key < r) {\n      T tl =\
    \ _fold_left(t->l, l);\n      T tr = _fold_right(t->r, r);\n      return f(f(tl,\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _fold_left(t->l,\
    \ l);\n    } else {\n      return _fold(t->l, l, r);\n    }\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _get_min_key(Ptr t, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l) t = t->l;\n\
    \    return t->key;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\
    \u3067\u6700\u5927\u306E key \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F\
    \ failed)\n  I _get_max_key(Ptr t, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    while (t->r) t = t->r;\n    return t->key;\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_min_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->l) push(t), t = t->l;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_max_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->r) push(t), t = t->r;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0, i \u306E\u533A\u9593\
    \ fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\
    \n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,\u53F3]\u304C\u771F\
    \u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n  // inclusive \u304B\
    \u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\u5834\u5408) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool exclusive>\n  I _max_right(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->l != nullptr) {\n        push(now->l);\n \
    \       auto pl = f(prod_now, now->l->sum);\n        if (check(pl)) {\n      \
    \    prod_now = pl;\n        } else {\n          now = now->l;\n          continue;\n\
    \        }\n      }\n      auto pl = f(prod_now, now->val);\n      if (!check(pl))\
    \ {\n        if constexpr (exclusive) {\n          return now->key;\n        }\
    \ else {\n          return now->l ? _get_max_key(now->l, failed) : prev;\n   \
    \     }\n      }\n      prod_now = pl;\n      if (now->r == nullptr) {\n     \
    \   if constexpr (exclusive) {\n          return failed;\n        } else {\n \
    \         return now->key;\n        }\n      }\n      push(now->r);\n      if\
    \ constexpr (!exclusive) prev = now->key;\n      now = now->r;\n    }\n  }\n\n\
    \  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001i, inf) \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F \u5B58\u5728\
    \u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve \u304B\u3064 (\u7A7A\
    \ \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\u5408\u306F failed\n\
    \  template <typename C, bool inclusive>\n  I _min_left(Ptr t, C check, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n    Ptr now\
    \ = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n    while\
    \ (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n        auto\
    \ pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n          prod_now\
    \ = pr;\n        } else {\n          now = now->r;\n          continue;\n    \
    \    }\n      }\n      auto pr = f(now->val, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _get_min_key(now->r,\
    \ failed) : prev;\n        } else {\n          return now->key;\n        }\n \
    \     }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->key;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->key;\n      now = now->l;\n    }\n  }\n\n  void _clear(Ptr t) {\n\
    \    if (!t) return;\n    if (t->l) _clear(t->l);\n    if (t->r) _clear(t->r);\n\
    \    my_del(t);\n  }\n\n  void inner_dump(Ptr t) {\n    push(t);\n    if (t->l)\
    \ inner_dump(t->l);\n    cerr << \"## i = \" << t->key << \", \";\n    cerr <<\
    \ \"\\tkey = \" << t->val << \", \";\n    cerr << \"\\tsum = \" << t->sum << \"\
    , \";\n    cerr << \"\\tchild = \";\n    cerr << \"( \" << (t->l ? to_string(t->l->key)\
    \ : \"nil\");\n    cerr << \", \";\n    cerr << (t->r ? to_string(t->r->key) :\
    \ \"nil\");\n    cerr << \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\
    \n  void inner_make_array(Ptr t, vector<pair<I, T>> &v) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->l) inner_make_array(t->l, v);\n    v.emplace_back(t->key,\
    \ t->val);\n    if (t->r) inner_make_array(t->r, v);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_key(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->val = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->key)\
    \ break;\n      if (i < t->key) {\n        t = t->l;\n      } else {\n       \
    \ t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->val = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->val : ti();\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\
    \u63DB\u3048\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\
    \u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val(I\
    \ i, const function<void(T &)> &func) {\n    auto s = split_by_key(root, i);\n\
    \    if (s[1] == nullptr) s[1] = my_new(i);\n    func(s[1]->val);\n    root =\
    \ merge(merge(s[0], update(s[1])), s[2]);\n  }\n  // 1 \u70B9 \u5024\u306E\u66F8\
    \u304D\u63DB\u3048 \u5024\u304C\u65E2\u306B\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306B\u65E9\u3044\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\
    \u7167\u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void\
    \ apply_val_fast(I i, const function<void(T &)> &func) {\n    static vector<Ptr>\
    \ ps;\n    ps.clear();\n    Ptr t = root;\n    while (t) {\n      push(t);\n \
    \     ps.push_back(t);\n      if (i == t->key) break;\n      if (i < t->key) {\n\
    \        t = t->l;\n      } else {\n        t = t->r;\n      }\n    }\n    if\
    \ (!t) {\n      apply_val(i, func);\n      return;\n    }\n    func(t->val);\n\
    \    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n  }\n\n  // \u9802\
    \u70B9\u306E\u524A\u9664\n  void erase(I i) {\n    auto s = split_by_key(root,\
    \ i);\n    if (s[1]) my_del(s[1]);\n    root = merge(s[0], s[2]);\n  }\n\n  //\
    \ \u7BC4\u56F2\u4F5C\u7528\n  void apply(I l, I r, const E &e) {\n    if (l >=\
    \ r) return;\n    _apply(root, l, r, e);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\
    \n  T fold(I l, I r) {\n    if (l >= r) return ti();\n    return _fold(root, l,\
    \ r);\n  }\n\n  // key \u6700\u5C0F\u3092\u53D6\u5F97\n  I get_min_key(I failed\
    \ = -1) { return _get_min_key(root, failed); }\n  // key \u6700\u5927\u3092\u53D6\
    \u5F97\n  I get_max_key(I failed = -1) { return _get_max_key(root, failed); }\n\
    \  // (key, val) \u6700\u5C0F\u3092\u53D6\u5F97\n  pair<I, T> get_min_keyval(I\
    \ failed = -1) {\n    return _get_min_keyval(root, failed);\n  }\n  // (key, val)\
    \ \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> get_max_keyval(I failed = -1) {\n\
    \    return _get_max_keyval(root, failed);\n  }\n  // (key, val) \u6700\u5C0F\u3092\
    \ pop\n  pair<I, T> pop_min_keyval(I failed = -1) {\n    assert(root != nullptr);\n\
    \    auto kv = _get_min_keyval(root, failed);\n    erase(kv.first);\n    return\
    \ kv;\n  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> pop_max_keyval(I\
    \ failed = -1) {\n    assert(root != nullptr);\n    auto kv = _get_max_keyval(root,\
    \ failed);\n    erase(kv.first);\n    return kv;\n  }\n\n  // n \u672A\u6E80\u306E\
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
    \ y);\n    return res;\n  }\n\n  void clear() { _clear(root), root = nullptr;\
    \ }\n  int size() { return count(root); }\n  bool empty() { return !root; }\n\
    \  void dump() { inner_dump(root); }\n\n  // \u5217\u3092\u914D\u5217\u306B\u5909\
    \u63DB\u3057\u3066\u8FD4\u3059\n  vector<pair<I, T>> make_array() {\n    vector<pair<I,\
    \ T>> res;\n    inner_make_array(root, res);\n    return res;\n  }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\nbool ei() { return false; }\ntemplate <typename I, typename\
    \ T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree =\n    RBSTLazySegmentTree<I,\
    \ T, bool, f, nullptr, nullptr, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\
    using RBSTSegmentTreeImpl::RBSTSegmentTree;\n\n/**\n * @brief RBST-based Dynamic\
    \ Lazy Segment Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename I, typename T, typename E, T (*f)(T, T),\
    \ T (*g)(T, E),\n          E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct RBSTLazySegmentTree\
    \ {\n  struct Node {\n    Node *l, *r;\n    I key;\n    T val, sum;\n    E lazy;\n\
    \    int cnt;\n    Node(const I &i, const T &t = ti())\n        : l(), r(), key(i),\
    \ val(t), sum(t), lazy(ei()), cnt(1) {}\n  };\n\n protected:\n  using Ptr = Node\
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
    \   return merge(build(l, m, dat), build(m, r, dat));\n  };\n\n  void push([[maybe_unused]]\
    \ Ptr t) {\n#pragma GCC diagnostic ignored \"-Waddress\"\n    if constexpr (g\
    \ != nullptr) {\n#pragma GCC diagnostic warning \"-Waddress\"\n      if (!t) return;\n\
    \      if (t->lazy != ei()) {\n        if (t->l) propagate(t->l, t->lazy);\n \
    \       if (t->r) propagate(t->r, t->lazy);\n        t->lazy = ei();\n      }\n\
    \    }\n  }\n\n  Ptr update(Ptr t) {\n    if (!t) return t;\n    t->cnt = 1;\n\
    \    t->sum = t->val;\n    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum,\
    \ t->sum);\n    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);\n\
    \    return t;\n  }\n\n  void propagate([[maybe_unused]] Ptr t, [[maybe_unused]]\
    \ const E &x) {\n#pragma GCC diagnostic ignored \"-Waddress\"\n    if constexpr\
    \ (g != nullptr) {\n#pragma GCC diagnostic warning \"-Waddress\"\n      if (!t)\
    \ return;\n      t->lazy = h(t->lazy, x);\n      t->val = g(t->val, x);\n    \
    \  t->sum = g(t->sum, x);\n    }\n  }\n\n  // key \u304C k \u3067\u3042\u308B\u30CE\
    \u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\u3070 nullptr\n  Ptr find(Ptr\
    \ t, I k) {\n    while (t) {\n      push(t);\n      if (k == t->key) return t;\n\
    \      t = k < t->key ? t->l : t->r;\n    }\n    return nullptr;\n  }\n\n  //\
    \ [k \u672A\u6E80, k \u4EE5\u4E0A]\n  pair<Ptr, Ptr> split_left(Ptr t, I k) {\n\
    \    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k == t->key) {\n\
    \      Ptr tl = t->l;\n      t->l = nullptr;\n      return {tl, update(t)};\n\
    \    } else if (k < t->key) {\n      auto s = split_left(t->l, k);\n      t->l\
    \ = s.second;\n      return {s.first, update(t)};\n    } else {\n      auto s\
    \ = split_left(t->r, k);\n      t->r = s.first;\n      return {update(t), s.second};\n\
    \    }\n  }\n\n  // [k \u672A\u6E80, k, k \u8D85\u904E]\n  array<Ptr, 3> split_by_key(Ptr\
    \ t, I k) {\n    if (!t) return {{nullptr, nullptr, nullptr}};\n    push(t);\n\
    \    if (k == t->key) {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r =\
    \ nullptr;\n      return {{tl, update(t), tr}};\n    } else if (k < t->key) {\n\
    \      auto s = split_by_key(t->l, k);\n      t->l = s[2];\n      return {{s[0],\
    \ s[1], update(t)}};\n    } else {\n      auto s = split_by_key(t->r, k);\n  \
    \    t->r = s[0];\n      return {{update(t), s[1], s[2]}};\n    }\n  }\n\n  //\
    \ x \u4EE5\u4E0A\u306E key \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F infty\n  I _lower_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n\
    \    while (!t) {\n      if (i == t->key) return i;\n      if (i < t->key) {\n\
    \        res = min(res, t->key);\n        t = t->l;\n      } else {\n        t\
    \ = t->l;\n      }\n    }\n    return res;\n  }\n\n  // x \u8D85\u904E\u306E key\
    \ \u6700\u5C0F\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F infty\n \
    \ I _upper_bound_key(Ptr t, I i, I infty) {\n    I res = infty;\n    while (!t)\
    \ {\n      if (i == t->key) return i;\n      if (i < t->key) {\n        res =\
    \ min(res, t->key);\n        t = t->l;\n      } else {\n        t = t->l;\n  \
    \    }\n    }\n    return res;\n  }\n\n  // [l, inf) \u3067\u3042\u308B\u5730\u70B9\
    \u306B apply\n  void _apply_left(Ptr t, I l, const E &e) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->key < l) {\n      _apply_left(t->r, l, e);\n    } else\
    \ if (t->key == l) {\n      t->val = g(t->val, e);\n      propagate(t->r, e);\n\
    \    } else {\n      _apply_left(t->l, l, e);\n      t->val = g(t->val, e);\n\
    \      propagate(t->r, e);\n    }\n    update(t);\n  }\n\n  // [-inf, r) \u3067\
    \u3042\u308B\u5730\u70B9\u306B apply\n  void _apply_right(Ptr t, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < r) {\n      propagate(t->l,\
    \ e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    } else\
    \ if (t->key == r) {\n      propagate(t->l, e);\n    } else {\n      _apply_right(t->l,\
    \ r, e);\n    }\n    update(t);\n  }\n\n  void _apply(Ptr t, I l, I r, const E\
    \ &e) {\n    if (!t) return;\n    push(t);\n    if (t->key < l) {\n      _apply(t->r,\
    \ l, r, e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n   \
    \   _apply_right(t->r, r, e);\n    } else if (t->key < r) {\n      _apply_left(t->l,\
    \ l, e);\n      t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    }\
    \ else if (t->key == r) {\n      _apply_left(t->l, l, e);\n    } else {\n    \
    \  _apply(t->l, l, r, e);\n    }\n    update(t);\n  }\n\n  T _sum(const Ptr &t)\
    \ { return t ? t->sum : ti(); }\n\n  // l \u4EE5\u4E0A\n  T _fold_left(Ptr t,\
    \ I l) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n    \
    \  return _fold_left(t->r, l);\n    } else if (t->key == l) {\n      return f(t->val,\
    \ _fold_left(t->r, l));\n    } else {\n      T tl = _fold_left(t->l, l);\n   \
    \   return f(f(tl, t->val), _sum(t->r));\n    }\n  }\n\n  // r \u672A\u6E80\n\
    \  T _fold_right(Ptr t, I r) {\n    if (!t) return ti();\n    push(t);\n    if\
    \ (t->key < r) {\n      T tr = _fold_right(t->r, r);\n      return f(f(_sum(t->l),\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _sum(t->l);\n   \
    \ } else {\n      return _fold_right(t->l, r);\n    }\n  }\n\n  T _fold(Ptr t,\
    \ I l, I r) {\n    if (!t) return ti();\n    push(t);\n    if (t->key < l) {\n\
    \      return _fold(t->r, l, r);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_right(t->r, r));\n    } else if (t->key < r) {\n      T tl =\
    \ _fold_left(t->l, l);\n      T tr = _fold_right(t->r, r);\n      return f(f(tl,\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _fold_left(t->l,\
    \ l);\n    } else {\n      return _fold(t->l, l, r);\n    }\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  I _get_min_key(Ptr t, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    while (t->l) t = t->l;\n\
    \    return t->key;\n  }\n\n  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\
    \u3067\u6700\u5927\u306E key \u306F\uFF1F (t \u304C\u7A7A\u306E\u5834\u5408\u306F\
    \ failed)\n  I _get_max_key(Ptr t, const I &failed) {\n    if (t == nullptr) return\
    \ failed;\n    while (t->r) t = t->r;\n    return t->key;\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_min_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->l) push(t), t = t->l;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  pair<I, T> _get_max_keyval(Ptr\
    \ t, const I &failed) {\n    if (t == nullptr) return {failed, ti()};\n    while\
    \ (t->r) push(t), t = t->r;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0, i \u306E\u533A\u9593\
    \ fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\
    \n  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,\u53F3]\u304C\u771F\
    \u306E\u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n  // inclusive \u304B\
    \u3064 (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\u5834\u5408) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool exclusive>\n  I _max_right(Ptr\
    \ t, C check, const I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->l != nullptr) {\n        push(now->l);\n \
    \       auto pl = f(prod_now, now->l->sum);\n        if (check(pl)) {\n      \
    \    prod_now = pl;\n        } else {\n          now = now->l;\n          continue;\n\
    \        }\n      }\n      auto pl = f(prod_now, now->val);\n      if (!check(pl))\
    \ {\n        if constexpr (exclusive) {\n          return now->key;\n        }\
    \ else {\n          return now->l ? _get_max_key(now->l, failed) : prev;\n   \
    \     }\n      }\n      prod_now = pl;\n      if (now->r == nullptr) {\n     \
    \   if constexpr (exclusive) {\n          return failed;\n        } else {\n \
    \         return now->key;\n        }\n      }\n      push(now->r);\n      if\
    \ constexpr (!exclusive) prev = now->key;\n      now = now->r;\n    }\n  }\n\n\
    \  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001i, inf) \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F \u5B58\u5728\
    \u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve \u304B\u3064 (\u7A7A\
    \ \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\u5408\u306F failed\n\
    \  template <typename C, bool inclusive>\n  I _min_left(Ptr t, C check, const\
    \ I &failed) {\n    if (t == nullptr) return failed;\n    push(t);\n    Ptr now\
    \ = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n    while\
    \ (true) {\n      if (now->r != nullptr) {\n        push(now->r);\n        auto\
    \ pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n          prod_now\
    \ = pr;\n        } else {\n          now = now->r;\n          continue;\n    \
    \    }\n      }\n      auto pr = f(now->val, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _get_min_key(now->r,\
    \ failed) : prev;\n        } else {\n          return now->key;\n        }\n \
    \     }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if constexpr\
    \ (inclusive) {\n          return now->key;\n        } else {\n          return\
    \ failed;\n        }\n      }\n      push(now->l);\n      if constexpr (inclusive)\
    \ prev = now->key;\n      now = now->l;\n    }\n  }\n\n  void _clear(Ptr t) {\n\
    \    if (!t) return;\n    if (t->l) _clear(t->l);\n    if (t->r) _clear(t->r);\n\
    \    my_del(t);\n  }\n\n  void inner_dump(Ptr t) {\n    push(t);\n    if (t->l)\
    \ inner_dump(t->l);\n    cerr << \"## i = \" << t->key << \", \";\n    cerr <<\
    \ \"\\tkey = \" << t->val << \", \";\n    cerr << \"\\tsum = \" << t->sum << \"\
    , \";\n    cerr << \"\\tchild = \";\n    cerr << \"( \" << (t->l ? to_string(t->l->key)\
    \ : \"nil\");\n    cerr << \", \";\n    cerr << (t->r ? to_string(t->r->key) :\
    \ \"nil\");\n    cerr << \" )\" << endl;\n    if (t->r) inner_dump(t->r);\n  }\n\
    \n  void inner_make_array(Ptr t, vector<pair<I, T>> &v) {\n    if (!t) return;\n\
    \    push(t);\n    if (t->l) inner_make_array(t->l, v);\n    v.emplace_back(t->key,\
    \ t->val);\n    if (t->r) inner_make_array(t->r, v);\n  }\n\n public:\n  Ptr root;\n\
    \n  RBSTLazySegmentTree() : root(nullptr) {}\n  RBSTLazySegmentTree(const vector<T>\
    \ xs, const vector<I> &is = {}) {\n    if (!is.empty()) assert(xs.size() == is.size());\n\
    \    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n    for (int i = 0; i\
    \ < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};\n    root = build(0, n,\
    \ dat);\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void set_val(I\
    \ i, T x) {\n    auto s = split_by_key(root, i);\n    if (s[1] == nullptr) {\n\
    \      s[1] = my_new(i, x);\n    } else {\n      s[1]->val = x;\n    }\n    root\
    \ = merge(merge(s[0], update(s[1])), s[2]);\n  }\n\n  // \u3059\u3067\u306B\u8981\
    \u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\u3092 set \u3059\u308B\
    \u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n  void set_val_fast(I\
    \ i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\n    Ptr t = root;\n\
    \    while (t) {\n      push(t);\n      ps.push_back(t);\n      if (i == t->key)\
    \ break;\n      if (i < t->key) {\n        t = t->l;\n      } else {\n       \
    \ t = t->r;\n      }\n    }\n    if (!t) {\n      set_val(i, x);\n      return;\n\
    \    }\n    t->val = x;\n    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n\
    \  }\n\n  // 1 \u70B9\u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = find(root,\
    \ i);\n    return p ? p->val : ti();\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\
    \u63DB\u3048\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\
    \u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val(I\
    \ i, const function<void(T &)> &func) {\n    auto s = split_by_key(root, i);\n\
    \    if (s[1] == nullptr) s[1] = my_new(i);\n    func(s[1]->val);\n    root =\
    \ merge(merge(s[0], update(s[1])), s[2]);\n  }\n  // 1 \u70B9 \u5024\u306E\u66F8\
    \u304D\u63DB\u3048 \u5024\u304C\u65E2\u306B\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306B\u65E9\u3044\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\
    \u7167\u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void\
    \ apply_val_fast(I i, const function<void(T &)> &func) {\n    static vector<Ptr>\
    \ ps;\n    ps.clear();\n    Ptr t = root;\n    while (t) {\n      push(t);\n \
    \     ps.push_back(t);\n      if (i == t->key) break;\n      if (i < t->key) {\n\
    \        t = t->l;\n      } else {\n        t = t->r;\n      }\n    }\n    if\
    \ (!t) {\n      apply_val(i, func);\n      return;\n    }\n    func(t->val);\n\
    \    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);\n  }\n\n  // \u9802\
    \u70B9\u306E\u524A\u9664\n  void erase(I i) {\n    auto s = split_by_key(root,\
    \ i);\n    if (s[1]) my_del(s[1]);\n    root = merge(s[0], s[2]);\n  }\n\n  //\
    \ \u7BC4\u56F2\u4F5C\u7528\n  void apply(I l, I r, const E &e) {\n    if (l >=\
    \ r) return;\n    _apply(root, l, r, e);\n  }\n\n  // \u7BC4\u56F2\u53D6\u5F97\
    \n  T fold(I l, I r) {\n    if (l >= r) return ti();\n    return _fold(root, l,\
    \ r);\n  }\n\n  // key \u6700\u5C0F\u3092\u53D6\u5F97\n  I get_min_key(I failed\
    \ = -1) { return _get_min_key(root, failed); }\n  // key \u6700\u5927\u3092\u53D6\
    \u5F97\n  I get_max_key(I failed = -1) { return _get_max_key(root, failed); }\n\
    \  // (key, val) \u6700\u5C0F\u3092\u53D6\u5F97\n  pair<I, T> get_min_keyval(I\
    \ failed = -1) {\n    return _get_min_keyval(root, failed);\n  }\n  // (key, val)\
    \ \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> get_max_keyval(I failed = -1) {\n\
    \    return _get_max_keyval(root, failed);\n  }\n  // (key, val) \u6700\u5C0F\u3092\
    \ pop\n  pair<I, T> pop_min_keyval(I failed = -1) {\n    assert(root != nullptr);\n\
    \    auto kv = _get_min_keyval(root, failed);\n    erase(kv.first);\n    return\
    \ kv;\n  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> pop_max_keyval(I\
    \ failed = -1) {\n    assert(root != nullptr);\n    auto kv = _get_max_keyval(root,\
    \ failed);\n    erase(kv.first);\n    return kv;\n  }\n\n  // n \u672A\u6E80\u306E\
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
    \ y);\n    return res;\n  }\n\n  void clear() { _clear(root), root = nullptr;\
    \ }\n  int size() { return count(root); }\n  bool empty() { return !root; }\n\
    \  void dump() { inner_dump(root); }\n\n  // \u5217\u3092\u914D\u5217\u306B\u5909\
    \u63DB\u3057\u3066\u8FD4\u3059\n  vector<pair<I, T>> make_array() {\n    vector<pair<I,\
    \ T>> res;\n    inner_make_array(root, res);\n    return res;\n  }\n};\n\nnamespace\
    \ RBSTSegmentTreeImpl {\nbool ei() { return false; }\ntemplate <typename I, typename\
    \ T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree =\n    RBSTLazySegmentTree<I,\
    \ T, bool, f, nullptr, nullptr, ti, ei>;\n}  // namespace RBSTSegmentTreeImpl\n\
    using RBSTSegmentTreeImpl::RBSTSegmentTree;\n\n/**\n * @brief RBST-based Dynamic\
    \ Lazy Segment Tree\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/rbst-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-11-01 22:31:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1786.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-procedessor-problem-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-associative-array-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
  - verify/verify-unit-test/rbst-segment-tree.test.cpp
documentation_of: segment-tree/rbst-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/rbst-segment-tree.hpp
- /library/segment-tree/rbst-segment-tree.hpp.html
title: RBST-based Dynamic Lazy Segment Tree
---
