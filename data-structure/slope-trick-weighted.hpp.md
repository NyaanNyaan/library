---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/rbst-segment-tree.hpp
    title: RBST-based Dynamic Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1467-weighted.test.cpp
    title: verify/verify-yuki/yuki-1467-weighted.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Weighted Slope Trick
    links: []
  bundledCode: "#line 2 \"data-structure/slope-trick-weighted.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n#include <type_traits>\nusing namespace std;\n\n#line 2 \"\
    segment-tree/rbst-segment-tree.hpp\"\n\n#define ENABLE_HAS_VAR(var)          \
    \                        \\\n  template <typename T>                         \
    \             \\\n  class has_##var {                                        \
    \  \\\n    template <typename U, int = (&U::var, 0)>                \\\n    static\
    \ true_type check(U *);                             \\\n    static false_type\
    \ check(...);                            \\\n    static T *t;                \
    \                             \\\n                                           \
    \                  \\\n   public:                                            \
    \       \\\n    static constexpr bool value = decltype(check(t))::value; \\\n\
    \  };                                                         \\\n  template <typename\
    \ T>                                      \\\n  inline constexpr bool has_##var##_v\
    \ = has_##var<T>::value;\n\nENABLE_HAS_VAR(lazy);\nENABLE_HAS_VAR(shift);\n\n\
    template <typename Node, typename I, typename T, typename E, T (*f)(T, T),\n \
    \         T (*g)(T, E), E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct RBSTSegmentTreeBase\
    \ {\n protected:\n  using Ptr = Node *;\n  template <typename... Args>\n  static\
    \ Ptr _my_new(Args... args) {\n    return new Node(args...);\n  }\n  static void\
    \ _my_del(Ptr t) { delete t; }\n\n  static int _count(const Ptr t) { return t\
    \ ? t->cnt : 0; }\n\n  static T _sum(const Ptr &t) { return t ? t->sum : ti();\
    \ }\n\n  static uint64_t _rng() {\n    static uint64_t x_ = 88172645463325252ULL;\n\
    \    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n\n  static\
    \ Ptr _merge(Ptr l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((_rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n      _push(l);\n      l->r = _merge(l->r,\
    \ r);\n      return _update(l);\n    } else {\n      _push(r);\n      r->l = _merge(l,\
    \ r->l);\n      return _update(r);\n    }\n  }\n\n  static Ptr _build(int l, int\
    \ r, const vector<pair<I, T>> &dat) {\n    if (l == r) return nullptr;\n    if\
    \ (l + 1 == r) return _my_new(dat[l].first, dat[l].second);\n    int m = (l +\
    \ r) / 2;\n    return _merge(_build(l, m, dat), _build(m, r, dat));\n  };\n\n\
    \  static void _push([[maybe_unused]] Ptr t) {\n    if constexpr (has_lazy_v<Node>)\
    \ {\n      if (!t) return;\n      if (t->lazy != ei()) {\n        if (t->l) _propagate(t->l,\
    \ t->lazy);\n        if (t->r) _propagate(t->r, t->lazy);\n        t->lazy = ei();\n\
    \      }\n    }\n    if constexpr (has_shift_v<Node>) {\n      if (!t) return;\n\
    \      if (t->shift != I{}) {\n        if (t->l) _shift(t->l, t->shift);\n   \
    \     if (t->r) _shift(t->r, t->shift);\n        t->shift = I{};\n      }\n  \
    \  }\n  }\n  static void _propagate([[maybe_unused]] Ptr t, [[maybe_unused]] const\
    \ E &x) {\n    if constexpr (has_lazy_v<Node>) {\n      if (!t) return;\n    \
    \  t->lazy = h(t->lazy, x);\n      t->val = g(t->val, x);\n      t->sum = g(t->sum,\
    \ x);\n    }\n  }\n  static void _shift([[maybe_unused]] Ptr t, [[maybe_unused]]\
    \ const I &sh) {\n    if constexpr (has_shift_v<Node>) {\n      if (!t) return;\n\
    \      t->key += sh, t->shift += sh;\n    }\n  }\n\n  static Ptr _update(Ptr t)\
    \ {\n    if (!t) return t;\n    t->cnt = 1;\n    t->sum = t->val;\n    if (t->l)\
    \ t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);\n    if (t->r) t->cnt +=\
    \ t->r->cnt, t->sum = f(t->sum, t->r->sum);\n    return t;\n  }\n\n  // key \u304C\
    \ k \u3067\u3042\u308B\u30CE\u30FC\u30C9\u3092\u63A2\u3059, \u306A\u3051\u308C\
    \u3070 nullptr\n  static Ptr _find(Ptr t, I k) {\n    while (t) {\n      _push(t);\n\
    \      if (k == t->key) return t;\n      t = k < t->key ? t->l : t->r;\n    }\n\
    \    return nullptr;\n  }\n\n  static void _erase(Ptr &t, I k) {\n    if (!t)\
    \ return;\n    _push(t);\n    if (k == t->key) {\n      Ptr tl = t->l, tr = t->r;\n\
    \      _my_del(t);\n      t = _merge(tl, tr);\n    } else if (k < t->key) {\n\
    \      _erase(t->l, k);\n      _update(t);\n    } else {\n      _erase(t->r, k);\n\
    \      _update(t);\n    }\n  }\n\n  // [k \u672A\u6E80, k \u4EE5\u4E0A]\n  static\
    \ pair<Ptr, Ptr> _split_by_key(Ptr t, I k) {\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    if (k == t->key) {\n      Ptr tl = t->l;\n      t->l = nullptr;\n\
    \      return {tl, _update(t)};\n    } else if (k < t->key) {\n      auto s =\
    \ _split_by_key(t->l, k);\n      t->l = s.second;\n      return {s.first, _update(t)};\n\
    \    } else {\n      auto s = _split_by_key(t->r, k);\n      t->r = s.first;\n\
    \      return {_update(t), s.second};\n    }\n  }\n\n  // [k \u672A\u6E80, k,\
    \ k \u8D85\u904E]\n  static array<Ptr, 3> _split_by_key3(Ptr t, I k) {\n    if\
    \ (!t) return {{nullptr, nullptr, nullptr}};\n    _push(t);\n    if (k == t->key)\
    \ {\n      Ptr tl = t->l, tr = t->r;\n      t->l = t->r = nullptr;\n      return\
    \ {{tl, _update(t), tr}};\n    } else if (k < t->key) {\n      auto s = _split_by_key3(t->l,\
    \ k);\n      t->l = s[2];\n      return {{s[0], s[1], _update(t)}};\n    } else\
    \ {\n      auto s = _split_by_key3(t->r, k);\n      t->r = s[0];\n      return\
    \ {{_update(t), s[1], s[2]}};\n    }\n  }\n\n  // (-inf, i] \u306E prod \u306B\
    \u3064\u3044\u3066 check(prod) \u306E (true / false) \u3067\u5207\u308B\n  template\
    \ <typename C>\n  static pair<Ptr, Ptr> _split_max_right(Ptr t, const C &check,\
    \ T prod = ti()) {\n    assert(check(prod));\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    T p1 = f(prod, _sum(t->l));\n    if (check(p1)) {\n      prod\
    \ = p1;\n    } else {\n      auto s = _split_max_right(t->l, check, prod);\n \
    \     t->l = s.second;\n      return {s.first, _update(t)};\n    }\n    prod =\
    \ f(prod, t->val);\n    if (!check(prod)) {\n      Ptr tl = t->l;\n      t->l\
    \ = nullptr;\n      return {tl, _update(t)};\n    }\n    p1 = f(prod, _sum(t->r));\n\
    \    if (check(p1)) {\n      return {t, nullptr};\n    } else {\n      auto s\
    \ = _split_max_right(t->r, check, prod);\n      t->r = s.first;\n      return\
    \ {_update(t), s.second};\n    }\n  }\n\n  // [i, inf) \u306E prod \u306B\u3064\
    \u3044\u3066 check(prod) \u306E (false / true) \u3067\u5207\u308B\n  template\
    \ <typename C>\n  static pair<Ptr, Ptr> _split_min_left(Ptr t, const C &check,\
    \ T prod = ti()) {\n    assert(check(prod));\n    if (!t) return {nullptr, nullptr};\n\
    \    _push(t);\n    T p1 = f(_sum(t->r), prod);\n    if (check(p1)) {\n      prod\
    \ = p1;\n    } else {\n      auto s = _split_min_left(t->r, check, prod);\n  \
    \    t->r = s.first;\n      return {_update(t), s.second};\n    }\n    prod =\
    \ f(t->val, prod);\n    if (!check(prod)) {\n      Ptr tr = t->r;\n      t->r\
    \ = nullptr;\n      return {_update(t), tr};\n    }\n    p1 = f(_sum(t->l), prod);\n\
    \    if (check(p1)) {\n      return {nullptr, t};\n    } else {\n      auto s\
    \ = _split_min_left(t->l, check, prod);\n      t->l = s.second;\n      return\
    \ {s.first, _update(t)};\n    }\n  }\n\n  // [l, inf) \u3067\u3042\u308B\u5730\
    \u70B9\u306B apply\n  static void _apply_left(Ptr t, I l, const E &e) {\n    if\
    \ (!t) return;\n    _push(t);\n    if (t->key < l) {\n      _apply_left(t->r,\
    \ l, e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n      _propagate(t->r,\
    \ e);\n    } else {\n      _apply_left(t->l, l, e);\n      t->val = g(t->val,\
    \ e);\n      _propagate(t->r, e);\n    }\n    _update(t);\n  }\n\n  // [-inf,\
    \ r) \u3067\u3042\u308B\u5730\u70B9\u306B apply\n  static void _apply_right(Ptr\
    \ t, I r, const E &e) {\n    if (!t) return;\n    _push(t);\n    if (t->key <\
    \ r) {\n      _propagate(t->l, e);\n      t->val = g(t->val, e);\n      _apply_right(t->r,\
    \ r, e);\n    } else if (t->key == r) {\n      _propagate(t->l, e);\n    } else\
    \ {\n      _apply_right(t->l, r, e);\n    }\n    _update(t);\n  }\n\n  // [l,\
    \ r) \u306B apply\n  static void _apply(Ptr t, I l, I r, const E &e) {\n    if\
    \ (!t) return;\n    _push(t);\n    if (t->key < l) {\n      _apply(t->r, l, r,\
    \ e);\n    } else if (t->key == l) {\n      t->val = g(t->val, e);\n      _apply_right(t->r,\
    \ r, e);\n    } else if (t->key < r) {\n      _apply_left(t->l, l, e);\n     \
    \ t->val = g(t->val, e);\n      _apply_right(t->r, r, e);\n    } else if (t->key\
    \ == r) {\n      _apply_left(t->l, l, e);\n    } else {\n      _apply(t->l, l,\
    \ r, e);\n    }\n    _update(t);\n  }\n\n  // l \u4EE5\u4E0A\n  static T _fold_left(Ptr\
    \ t, I l) {\n    if (!t) return ti();\n    _push(t);\n    if (t->key < l) {\n\
    \      return _fold_left(t->r, l);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_left(t->r, l));\n    } else {\n      T tl = _fold_left(t->l,\
    \ l);\n      return f(f(tl, t->val), _sum(t->r));\n    }\n  }\n\n  // r \u672A\
    \u6E80\n  static T _fold_right(Ptr t, I r) {\n    if (!t) return ti();\n    _push(t);\n\
    \    if (t->key < r) {\n      T tr = _fold_right(t->r, r);\n      return f(f(_sum(t->l),\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _sum(t->l);\n   \
    \ } else {\n      return _fold_right(t->l, r);\n    }\n  }\n\n  static T _fold(Ptr\
    \ t, I l, I r) {\n    if (!t) return ti();\n    _push(t);\n    if (t->key < l)\
    \ {\n      return _fold(t->r, l, r);\n    } else if (t->key == l) {\n      return\
    \ f(t->val, _fold_right(t->r, r));\n    } else if (t->key < r) {\n      T tl =\
    \ _fold_left(t->l, l);\n      T tr = _fold_right(t->r, r);\n      return f(f(tl,\
    \ t->val), tr);\n    } else if (t->key == r) {\n      return _fold_left(t->l,\
    \ l);\n    } else {\n      return _fold(t->l, l, r);\n    }\n  }\n\n  // t \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  static pair<I, T> _get_min_keyval(Ptr\
    \ t, const I &failed) {\n    if (!t) return {failed, ti()};\n    while (t->l)\
    \ _push(t), t = t->l;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\u6839\
    \u3068\u3059\u308B\u6728\u306E\u4E0A\u3067\u6700\u5C0F\u306E key \u306F\uFF1F\
    \ (t \u304C\u7A7A\u306E\u5834\u5408\u306F failed)\n  static pair<I, T> _get_max_keyval(Ptr\
    \ t, const I &failed) {\n    if (!t) return {failed, ti()};\n    while (t->r)\
    \ _push(t), t = t->r;\n    return {t->key, t->val};\n  }\n\n  // t \u3092\u6839\
    \u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001[0, i \u306E\u533A\u9593 fold\
    \ \u304C true \u306B\u306A\u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n\
    \  // exclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F[0,\u53F3]\u304C\u771F\u306E\
    \u5834\u5408) \u306E\u5834\u5408\u306F failed(inf)\n  // inclusive \u304B\u3064\
    \ (\u7A7A \u307E\u305F\u306F[0,0] \u304C\u507D\u306E\u5834\u5408) \u306E\u5834\
    \u5408\u306F failed\n  template <typename C, bool exclusive>\n  static I _max_right(Ptr\
    \ t, C check, const I &failed) {\n    if (!t) return failed;\n    _push(t);\n\
    \    Ptr now = t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n\
    \    while (true) {\n      if (now->l != nullptr) {\n        _push(now->l);\n\
    \        auto pl = f(prod_now, now->l->sum);\n        if (check(pl)) {\n     \
    \     prod_now = pl;\n        } else {\n          now = now->l;\n          continue;\n\
    \        }\n      }\n      auto pl = f(prod_now, now->val);\n      if (!check(pl))\
    \ {\n        if constexpr (exclusive) {\n          return now->key;\n        }\
    \ else {\n          return now->l ? _get_max_keyval(now->l, failed).first : prev;\n\
    \        }\n      }\n      prod_now = pl;\n      if (now->r == nullptr) {\n  \
    \      if constexpr (exclusive) {\n          return failed;\n        } else {\n\
    \          return now->key;\n        }\n      }\n      _push(now->r);\n      if\
    \ constexpr (!exclusive) prev = now->key;\n      now = now->r;\n    }\n  }\n\n\
    \  // t \u3092\u6839\u3068\u3059\u308B\u6728\u306E\u3046\u3061\u3001i, inf) \u306E\
    \u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\
    \u304B\uFF1F\n  // inclusive \u304B\u3064 (\u7A7A \u307E\u305F\u306F \u5B58\u5728\
    \u3057\u306A\u3044) \u5834\u5408\u306F failed\n  // exlucisve \u304B\u3064 (\u7A7A\
    \ \u307E\u305F\u306F [\u5DE6, inf) \u304C\u771F) \u306E\u5834\u5408\u306F failed\n\
    \  template <typename C, bool inclusive>\n  static I _min_left(Ptr t, C check,\
    \ const I &failed) {\n    if (!t) return failed;\n    _push(t);\n    Ptr now =\
    \ t;\n    T prod_now = ti();\n    [[maybe_unused]] I prev = failed;\n    while\
    \ (true) {\n      if (now->r != nullptr) {\n        _push(now->r);\n        auto\
    \ pr = f(now->r->sum, prod_now);\n        if (check(pr)) {\n          prod_now\
    \ = pr;\n        } else {\n          now = now->r;\n          continue;\n    \
    \    }\n      }\n      auto pr = f(now->val, prod_now);\n      if (!check(pr))\
    \ {\n        if constexpr (inclusive) {\n          return now->r ? _get_min_keyval(now->r,\
    \ failed).first : prev;\n        } else {\n          return now->key;\n      \
    \  }\n      }\n      prod_now = pr;\n      if (now->l == nullptr) {\n        if\
    \ constexpr (inclusive) {\n          return now->key;\n        } else {\n    \
    \      return failed;\n        }\n      }\n      _push(now->l);\n      if constexpr\
    \ (inclusive) prev = now->key;\n      now = now->l;\n    }\n  }\n\n  static void\
    \ _clear(Ptr t) {\n    if (!t) return;\n    if (t->l) _clear(t->l);\n    if (t->r)\
    \ _clear(t->r);\n    _my_del(t);\n  }\n\n  static Ptr _deepcopy(Ptr t) {\n   \
    \ if (!t) return nullptr;\n    Ptr u = _my_new(*t);\n    if (u->l) u->l = _deepcopy(u->l);\n\
    \    if (u->r) u->r = _deepcopy(u->r);\n    return u;\n  }\n\n  static void _dump(Ptr\
    \ t) {\n    if (!t) return;\n    _push(t);\n    _dump(t->l);\n    cerr << \"##\
    \ key = \" << t->key << \",\";\n    cerr << \"\\tval = \" << t->val << \", \"\
    ;\n    cerr << \"\\tsum = \" << t->sum << \", \";\n    cerr << \"\\tchild = \"\
    ;\n    cerr << \"( \";\n    if (t->l) cerr << t->l->key;\n    if (!t->l) cerr\
    \ << \"nil\";\n    cerr << \", \";\n    if (t->r) cerr << t->r->key;\n    if (!t->r)\
    \ cerr << \"nil\";\n    cerr << \" )\" << endl;\n    _dump(t->r);\n  }\n\n  static\
    \ void _make_array(Ptr t, vector<pair<I, T>> &v) {\n    if (!t) return;\n    _push(t);\n\
    \    if (t->l) _make_array(t->l, v);\n    v.emplace_back(t->key, t->val);\n  \
    \  if (t->r) _make_array(t->r, v);\n  }\n\n public:\n  Ptr root;\n\n  RBSTSegmentTreeBase()\
    \ : root(nullptr) {}\n  RBSTSegmentTreeBase(Ptr t) : root(t) {}\n  RBSTSegmentTreeBase(const\
    \ vector<T> xs, const vector<I> &vals = {}) {\n    if (!vals.empty()) assert(xs.size()\
    \ == vals.size());\n    int n = xs.size();\n    vector<pair<I, T>> dat(n);\n \
    \   for (int i = 0; i < n; i++) dat[i] = {vals.empty() ? i : vals[i], xs[i]};\n\
    \    root = _build(0, n, dat);\n  }\n  RBSTSegmentTreeBase(RBSTSegmentTreeBase\
    \ &&rhs) noexcept { root = rhs.root; }\n  RBSTSegmentTreeBase(const RBSTSegmentTreeBase\
    \ &rhs) { root = rhs.root; }\n  ~RBSTSegmentTreeBase() = default;\n\n  using RBST\
    \ = RBSTSegmentTreeBase;\n  RBST &operator=(RBST &&rhs) noexcept {\n    root =\
    \ rhs.root;\n    return *this;\n  }\n  RBST &operator=(const RBST &rhs) {\n  \
    \  root = rhs.root;\n    return *this;\n  }\n  RBST deepcopy() { return _deepcopy(root);\
    \ }\n\n  friend void swap(RBST &lhs, RBST &rhs) { swap(lhs.root, rhs.root); }\n\
    \  void swap(RBST &rhs) { swap(root, rhs.root); }\n\n  // destructive ordered\
    \ _merge (max(lhs) < min(rhs))\n  friend RBST ordered_merge(RBST &lhs, RBST &rhs)\
    \ {\n    assert(lhs.get_max_key() < rhs.get_min_key());\n    return RBST{_merge(lhs.root,\
    \ rhs.root)};\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n  void\
    \ set_val(I i, T x) {\n    auto s = _split_by_key3(root, i);\n    if (s[1] ==\
    \ nullptr) {\n      s[1] = _my_new(i, x);\n    } else {\n      s[1]->val = x;\n\
    \    }\n    root = _merge(_merge(s[0], _update(s[1])), s[2]);\n  }\n\n  // \u3059\
    \u3067\u306B\u8981\u7D20\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306B\u5024\
    \u3092 set \u3059\u308B\u3002\u304A\u305D\u3089\u304F\u5C11\u3057\u65E9\u3044\n\
    \  void set_val_fast(I i, T x) {\n    static vector<Ptr> ps;\n    ps.clear();\n\
    \    Ptr t = root;\n    while (t) {\n      _push(t);\n      ps.push_back(t);\n\
    \      if (i == t->key) break;\n      t = i < t->key ? t->l : t->r;\n    }\n \
    \   if (!t) {\n      set_val(i, x);\n      return;\n    }\n    t->val = x;\n \
    \   for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);\n  }\n\n  // 1 \u70B9\
    \u53D6\u5F97\n  T get_val(I i) {\n    Ptr p = _find(root, i);\n    return p ?\
    \ p->val : ti();\n  }\n\n  // 1 \u70B9 \u5024\u306E\u66F8\u304D\u63DB\u3048\n\
    \  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\u7167\u3055\u308C\
    \u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void apply_val(I i,\
    \ const function<void(T &)> &func) {\n    auto s = _split_by_key3(root, i);\n\
    \    if (s[1] == nullptr) s[1] = _my_new(i);\n    func(s[1]->val);\n    root =\
    \ _merge(_merge(s[0], _update(s[1])), s[2]);\n  }\n  // 1 \u70B9 \u5024\u306E\u66F8\
    \u304D\u63DB\u3048 \u5024\u304C\u65E2\u306B\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306B\u65E9\u3044\n  // func \u306E\u8FD4\u308A\u5024\u306F void !!!!!!(\u53C2\
    \u7167\u3055\u308C\u305F\u5024\u3092\u76F4\u63A5\u66F4\u65B0\u3059\u308B)\n  void\
    \ apply_val_fast(I i, const function<void(T &)> &func) {\n    static vector<Ptr>\
    \ ps;\n    ps.clear();\n    Ptr t = root;\n    while (t) {\n      _push(t);\n\
    \      ps.push_back(t);\n      if (i == t->key) break;\n      t = i < t->key ?\
    \ t->l : t->r;\n    }\n    if (!t) {\n      apply_val(i, func);\n      return;\n\
    \    }\n    func(t->val);\n    for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);\n\
    \  }\n\n  // \u9802\u70B9\u306E\u524A\u9664\n  virtual void erase(I i) { _erase(root,\
    \ i); }\n\n  // \u7BC4\u56F2\u4F5C\u7528\n  void apply(I l, I r, const E &e) {\n\
    \    if (l >= r) return;\n    _apply(root, l, r, e);\n  }\n  void apply_all(const\
    \ E &e) { _propagate(root, e); }\n\n  // \u7BC4\u56F2\u53D6\u5F97\n  T fold(I\
    \ l, I r) {\n    if (l >= r) return ti();\n    return _fold(root, l, r);\n  }\n\
    \  T fold_all() { return _sum(root); }\n\n  void shift(const I &sh) { _shift(root,\
    \ sh); }\n\n  // key \u6700\u5C0F\u3092\u53D6\u5F97\n  I get_min_key(I failed\
    \ = -1) { return _get_min_keyval(root, failed).first; }\n  // key \u6700\u5927\
    \u3092\u53D6\u5F97\n  I get_max_key(I failed = -1) { return _get_max_keyval(root,\
    \ failed).first; }\n  // (key, val) \u6700\u5C0F\u3092\u53D6\u5F97\n  pair<I,\
    \ T> get_min_keyval(I failed = -1) {\n    return _get_min_keyval(root, failed);\n\
    \  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I, T> get_max_keyval(I\
    \ failed = -1) {\n    return _get_max_keyval(root, failed);\n  }\n  // (key, val)\
    \ \u6700\u5C0F\u3092 pop\n  pair<I, T> pop_min_keyval(I failed = -1) {\n    assert(root\
    \ != nullptr);\n    auto kv = _get_min_keyval(root, failed);\n    erase(kv.first);\n\
    \    return kv;\n  }\n  // (key, val) \u6700\u5927\u3092\u53D6\u5F97\n  pair<I,\
    \ T> pop_max_keyval(I failed = -1) {\n    assert(root != nullptr);\n    auto kv\
    \ = _get_max_keyval(root, failed);\n    erase(kv.first);\n    return kv;\n  }\n\
    \n  // n \u672A\u6E80\u306E i \u306E\u3046\u3061\u3001[i, n) \u306E\u533A\u9593\
    \ fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\
    \n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F failed \u3092\u8FD4\u3059\
    )\n  template <typename C>\n  I min_left(I n, C check, I failed) {\n    assert(check(ti())\
    \ == true);\n    auto [x, y] = _split_by_key(root, n);\n    I res = _min_left<C,\
    \ true>(x, check, failed);\n    root = _merge(x, y);\n    return res;\n  }\n\n\
    \  // n \u672A\u6E80\u306E i \u306E\u3046\u3061\u3001(i, n) \u306E\u533A\u9593\
    \ fold \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E i \u306F\u4F55\u304B\uFF1F\
    \n  // (\u7A7A\u3060\u3063\u305F\u308A (\u5DE6\u7AEF, n) \u304C \u771F\u306E\u5834\
    \u5408\u306F minus_infty \u3092\u8FD4\u3059)\n  template <typename C>\n  I min_left_exclusive(I\
    \ n, C check, I minus_infty) {\n    assert(check(ti()) == true);\n    auto [x,\
    \ y] = _split_by_key(root, n);\n    I res = _min_left<C, false>(x, check, minus_infty);\n\
    \    root = _merge(x, y);\n    return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i\
    \ \u306E\u3046\u3061\u3001[n, i) \u306E\u533A\u9593 fold \u304C true \u306B\u306A\
    \u308B\u6700\u5927\u306E i \u306F\u4F55\u304B\uFF1F\n  // (\u7A7A\u3060\u3063\u305F\
    \u308A [n, \u53F3\u7AEF] \u304C true \u306E\u5834\u5408\u306F infty \u3092\u8FD4\
    \u3059)\n  template <typename C>\n  I max_right(I n, C check, I infty) {\n   \
    \ assert(check(ti()) == true);\n    auto [x, y] = _split_by_key(root, n);\n  \
    \  I res = _max_right<C, true>(y, check, infty);\n    root = _merge(x, y);\n \
    \   return res;\n  }\n\n  // n \u4EE5\u4E0A\u306E i \u306E\u3046\u3061\u3001[n,\
    \ i] \u306E\u533A\u9593 fold \u304C true \u306B\u306A\u308B\u6700\u5927\u306E\
    \ i \u306F\u4F55\u304B\uFF1F\n  // (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F failed \u3092\u8FD4\u3059)\n  template <typename C>\n  I max_right_inclusive(I\
    \ n, C check, I failed) {\n    assert(check(ti()) == true);\n    auto [x, y] =\
    \ _split_by_key(root, n);\n    I res = _max_right<C, false>(y, check, failed);\n\
    \    root = _merge(x, y);\n    return res;\n  }\n\n  // (key \u672A\u6E80, key\
    \ \u4EE5\u4E0A) \u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\
    \u308B\n  pair<RBST, RBST> split_by_key(const I &key) {\n    auto [x, y] = _split_by_key(root,\
    \ key);\n    root = nullptr;\n    return make_pair(RBST{x}, RBST{y});\n  }\n \
    \ // [i, inf) \u306E\u533A\u9593\u7A4D\u304C (false, true) \u306B\u306A\u308B\u5883\
    \u754C\u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\u308B\
    \n  template <typename C>\n  pair<RBST, RBST> split_min_left(const C &check) {\n\
    \    assert(check(ti()) == true);\n    auto [x, y] = _split_min_left(root, check);\n\
    \    root = nullptr;\n    return make_pair(RBST{x}, RBST{y});\n  }\n  // (-inf,\
    \ i] \u306E\u533A\u9593\u7A4D\u304C (true, false) \u306B\u306A\u308B\u5883\u754C\
    \u3067\u5206\u5272\n  // \u547C\u3073\u51FA\u3057\u5F8C\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306F\u7A7A\u306E\u30BB\u30B0\u6728\u306B\u306A\u308B\n  template\
    \ <typename C>\n  pair<RBST, RBST> split_max_right(const C &check) {\n    assert(check(ti())\
    \ == true);\n    auto [x, y] = _split_max_right(root, check);\n    root = nullptr;\n\
    \    return make_pair(RBST{x}, RBST{y});\n  }\n\n  void clear() { _clear(root),\
    \ root = nullptr; }\n  int size() { return _count(root); }\n  bool empty() { return\
    \ !root; }\n  void dump() {\n    cerr << \"***** dump start *****\" << endl;\n\
    \    _dump(root);\n    cerr << \"****** dump end ******\" << endl;\n  }\n\n  //\
    \ \u5217\u3092\u914D\u5217\u306B\u5909\u63DB\u3057\u3066\u8FD4\u3059\n  vector<pair<I,\
    \ T>> make_array() {\n    vector<pair<I, T>> res;\n    _make_array(root, res);\n\
    \    return res;\n  }\n};\n\nnamespace RBSTSegmentTreeImpl {\nbool _ei() { return\
    \ false; }\n\ntemplate <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T,\
    \ E),\n          E (*h)(E, E), T (*ti)(), E (*ei)()>\nstruct ShiftableLazySegNode\
    \ {\n  ShiftableLazySegNode *l, *r;\n  I key, shift;\n  T val, sum;\n  E lazy;\n\
    \  int cnt;\n  ShiftableLazySegNode(const I &i, const T &t = ti())\n      : l(),\
    \ r(), key(i), shift(I{}), val(t), sum(t), lazy(ei()), cnt(1) {}\n};\ntemplate\
    \ <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n         \
    \ E (*h)(E, E), T (*ti)(), E (*ei)()>\nusing RBSTShiftableLazySegmentTree =\n\
    \    RBSTSegmentTreeBase<ShiftableLazySegNode<I, T, E, f, g, h, ti, ei>, I, T,\
    \ E,\n                        f, g, h, ti, ei>;\n\ntemplate <typename I, typename\
    \ T, typename E, T (*f)(T, T), T (*g)(T, E),\n          E (*h)(E, E), T (*ti)(),\
    \ E (*ei)()>\nstruct LazySegNode {\n  LazySegNode *l, *r;\n  I key;\n  T val,\
    \ sum;\n  E lazy;\n  int cnt;\n  LazySegNode(const I &i, const T &t = ti())\n\
    \      : l(), r(), key(i), val(t), sum(t), lazy(ei()), cnt(1) {}\n};\ntemplate\
    \ <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),\n         \
    \ E (*h)(E, E), T (*ti)(), E (*ei)()>\nusing RBSTLazySegmentTree =\n    RBSTSegmentTreeBase<LazySegNode<I,\
    \ T, E, f, g, h, ti, ei>, I, T, E, f, g, h,\n                        ti, ei>;\n\
    \ntemplate <typename I, typename T, T (*f)(T, T), T (*ti)()>\nstruct SegNode {\n\
    \  SegNode *l, *r;\n  I key;\n  T val, sum;\n  int cnt;\n  SegNode(const I &i,\
    \ const T &t = ti())\n      : l(), r(), key(i), val(t), sum(t), cnt(1) {}\n};\n\
    template <typename I, typename T, T (*f)(T, T), T (*ti)()>\nusing RBSTSegmentTree\
    \ = RBSTSegmentTreeBase<SegNode<I, T, f, ti>, I, T, bool, f,\n               \
    \                             nullptr, nullptr, ti, _ei>;\n\n}  // namespace RBSTSegmentTreeImpl\n\
    \nusing RBSTSegmentTreeImpl::RBSTLazySegmentTree;\nusing RBSTSegmentTreeImpl::RBSTSegmentTree;\n\
    using RBSTSegmentTreeImpl::RBSTShiftableLazySegmentTree;\n\n/**\n * @brief RBST-based\
    \ Dynamic Lazy Segment Tree\n */\n#line 9 \"data-structure/slope-trick-weighted.hpp\"\
    \n\nnamespace SlopeTrickImpl {\n\ntemplate <typename Int>\nusing T = pair<Int,\
    \ Int>;\ntemplate <typename Int>\nusing E = Int;\ntemplate <typename Int>\nT<Int>\
    \ f(T<Int> a, T<Int> b) {\n  return {a.first + b.first, a.second + b.second};\n\
    }\ntemplate <typename Int>\nT<Int> g(T<Int> a, E<Int> b) {\n  return {a.first,\
    \ a.second + a.first * b};\n}\ntemplate <typename Int>\nE<Int> h(E<Int> a, E<Int>\
    \ b) {\n  return a + b;\n}\ntemplate <typename Int>\nT<Int> ti() {\n  return {};\n\
    }\ntemplate <typename Int>\nE<Int> ei() {\n  return {};\n}\ntemplate <typename\
    \ Int>\nusing SegTree = RBSTShiftableLazySegmentTree<Int, T<Int>, E<Int>, f<Int>,\n\
    \                                             g<Int>, h<Int>, ti<Int>, ei<Int>>;\n\
    }  // namespace SlopeTrickImpl\n\ntemplate <typename I>\nstruct WeightedSlopeTrick\
    \ {\n  static constexpr I inf = (I{1} << (sizeof(I) * 8 - 2)) - 1;\n  using Seg\
    \ = typename SlopeTrickImpl::SegTree<I>;\n  using T = SlopeTrickImpl::T<I>;\n\
    \  using E = SlopeTrickImpl::E<I>;\n\n  // x : \u5EA7\u6A19, c : \u50BE\u304D\u306E\
    \u5909\u5316\u91CF\n  struct P {\n    I x, c;\n    P(I _x, I _c) : x(_x), c(_c)\
    \ {}\n  };\n\n private:\n  Seg L, R;\n  I min_y;\n\n  // seg[x] += c\n  void _apply(Seg&\
    \ seg, I x, I c) {\n    if (c == 0) return;\n    seg.apply_val_fast(x, [&](T&\
    \ t) {\n      t.first += c;\n      t.second += x * c;\n    });\n  }\n  void _push_L(I\
    \ x, I c = 1) { _apply(L, x, c); }\n  void _push_R(I x, I c = 1) { _apply(R, x,\
    \ c); }\n  P _get_L() {\n    assert(!L.empty());\n    auto kv = L.get_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _get_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.get_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  P _getpop_L() {\n    assert(!L.empty());\n    auto kv = L.pop_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _getpop_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.pop_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  pair<Seg, Seg> _split_L(I c) {\n    assert(L.fold_all().first >= c);\n\
    \    pair<Seg, Seg> res =\n        L.split_min_left([&](const T& t) { return t.first\
    \ <= c; });\n    c -= res.second.fold_all().first;\n    if (c != 0) {\n      I\
    \ k = res.first.get_max_key();\n      _apply(res.first, k, -c);\n      _apply(res.second,\
    \ k, c);\n    }\n    return res;\n  }\n  pair<Seg, Seg> _split_R(I c) {\n    assert(R.fold_all().first\
    \ >= c);\n    pair<Seg, Seg> res =\n        R.split_max_right([&](const T& t)\
    \ { return t.first <= c; });\n    c -= res.first.fold_all().first;\n    if (c\
    \ != 0) {\n      I k = res.second.get_min_key();\n      _apply(res.first, k, c);\n\
    \      _apply(res.second, k, -c);\n    }\n    return res;\n  }\n  // destructive\
    \ merge\n  Seg _unite(Seg& lhs, Seg& rhs) {\n    if (lhs.empty()) return rhs;\n\
    \    if (rhs.empty()) return lhs;\n    assert(lhs.get_max_key() <= rhs.get_min_key()\
    \ && \"WeightSlopTrick::_unite\");\n    if (lhs.get_max_key() == rhs.get_min_key())\
    \ {\n      auto [x, p] = lhs.pop_max_keyval();\n      _apply(rhs, x, p.first);\n\
    \    }\n    if (lhs.empty()) return rhs;\n    if (rhs.empty()) return lhs;\n \
    \   return ordered_merge(lhs, rhs);\n  }\n\n public:\n  WeightedSlopeTrick() :\
    \ min_y(0) {}\n\n  void debug() {\n    auto LL = L.make_array(), RR = R.make_array();\n\
    \    cerr << \"L : \";\n    for (auto& [k, v] : LL) cerr << \"( \" << k << \"\
    , \" << v.first << \" ), \";\n    cerr << endl << \"R : \";\n    for (auto& [k,\
    \ v] : RR) cerr << \"( \" << k << \", \" << v.first << \" ), \";\n    cerr <<\
    \ endl << \"min : ( \";\n    cerr << get_min().first << \", \" << get_min().second\
    \ << \" )\" << endl;\n  }\n\n  // return {x, y} s.t. {argmin, min}\n  pair<I,\
    \ I> get_min() {\n    I x = L.empty() ? R.empty() ? 0 : _get_R().x : _get_L().x;\n\
    \    return {x, min_y};\n  }\n\n  void shift_L(I a) { L.shift(a), L.apply_all(a);\
    \ }\n  void shift_R(I a) { R.shift(a), R.apply_all(a); }\n  // f(x) <- f(x - a)\n\
    \  void shift_x(I a) { shift_L(a), shift_R(a); }\n  // f(x) <- f(x) + a\n  void\
    \ shift_y(I a) { min_y += a; }\n\n  // add (x-a)_+   _____/\n  void add_xma(I\
    \ a, I c = 1) {\n    _apply(L, a, c);\n    auto [L1, L2] = _split_L(c);\n    auto\
    \ [c_sum, ac_sum] = L2.fold(a, inf);\n    min_y += ac_sum - c_sum * a;\n    auto\
    \ c2 = L2.get_val(a);\n    L2.erase(a);\n    R = _unite(L2, R);\n    _apply(R,\
    \ a, c2.first);\n    L = L1;\n  }\n\n  // add (a-x)_+   \\_____\n  void add_amx(I\
    \ a, I c = 1) {\n    _apply(R, a, c);\n    auto [R1, R2] = _split_R(c);\n    auto\
    \ [c_sum, ac_sum] = R1.fold(-inf, a);\n    min_y += c_sum * a - ac_sum;\n    auto\
    \ c2 = R1.get_val(a);\n    R1.erase(a);\n    L = _unite(L, R1);\n    _apply(L,\
    \ a, c2.first);\n    R = R2;\n  }\n\n  // add |x-a|     \\____/\n  void add_abs_xma(I\
    \ a, I c = 1) {\n    add_xma(a, c);\n    add_amx(a, c);\n  }\n\n  //  chmin right\
    \ side \\_/ -> \\__\n  void chmin_right() { R.clear(); }\n  //  chmin left side\
    \  \\_/ -> __/\n  void chmin_left() { L.clear(); }\n\n  // destructive merge\n\
    \  void merge(WeightedSlopeTrick& r) {\n    if (L.size() + R.size() < r.L.size()\
    \ + r.R.size()) swap(*this, r);\n    for (auto& [x, t] : r.L.make_array()) add_amx(x,\
    \ t.first);\n    for (auto& [x, t] : r.R.make_array()) add_xma(x, t.first);\n\
    \    shift_y(r.min_y);\n  }\n\n  I eval(I x) {\n    I res = min_y;\n    if (!L.empty()\
    \ && _get_L().x > x) {\n      auto [L1, L2] = L.split_by_key(x);\n      auto [c_sum,\
    \ xc_sum] = L2.fold_all();\n      res += xc_sum - c_sum * x;\n      L = _unite(L1,\
    \ L2);\n    }\n    if (!R.empty() && _get_R().x < x) {\n      auto [R1, R2] =\
    \ R.split_by_key(x);\n      auto [c_sum, xc_sum] = R1.fold_all();\n      res +=\
    \ c_sum * x - xc_sum;\n      R = _unite(R1, R2);\n    }\n    return res;\n  }\n\
    \n  void clear() { L.clear(), R.clear(), min_y = 0; }\n};\n\nusing SlopeTrick\
    \ = WeightedSlopeTrick<__int128_t>;\n\n/**\n * @brief Weighted Slope Trick\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <type_traits>\n\
    using namespace std;\n\n#include \"../segment-tree/rbst-segment-tree.hpp\"\n\n\
    namespace SlopeTrickImpl {\n\ntemplate <typename Int>\nusing T = pair<Int, Int>;\n\
    template <typename Int>\nusing E = Int;\ntemplate <typename Int>\nT<Int> f(T<Int>\
    \ a, T<Int> b) {\n  return {a.first + b.first, a.second + b.second};\n}\ntemplate\
    \ <typename Int>\nT<Int> g(T<Int> a, E<Int> b) {\n  return {a.first, a.second\
    \ + a.first * b};\n}\ntemplate <typename Int>\nE<Int> h(E<Int> a, E<Int> b) {\n\
    \  return a + b;\n}\ntemplate <typename Int>\nT<Int> ti() {\n  return {};\n}\n\
    template <typename Int>\nE<Int> ei() {\n  return {};\n}\ntemplate <typename Int>\n\
    using SegTree = RBSTShiftableLazySegmentTree<Int, T<Int>, E<Int>, f<Int>,\n  \
    \                                           g<Int>, h<Int>, ti<Int>, ei<Int>>;\n\
    }  // namespace SlopeTrickImpl\n\ntemplate <typename I>\nstruct WeightedSlopeTrick\
    \ {\n  static constexpr I inf = (I{1} << (sizeof(I) * 8 - 2)) - 1;\n  using Seg\
    \ = typename SlopeTrickImpl::SegTree<I>;\n  using T = SlopeTrickImpl::T<I>;\n\
    \  using E = SlopeTrickImpl::E<I>;\n\n  // x : \u5EA7\u6A19, c : \u50BE\u304D\u306E\
    \u5909\u5316\u91CF\n  struct P {\n    I x, c;\n    P(I _x, I _c) : x(_x), c(_c)\
    \ {}\n  };\n\n private:\n  Seg L, R;\n  I min_y;\n\n  // seg[x] += c\n  void _apply(Seg&\
    \ seg, I x, I c) {\n    if (c == 0) return;\n    seg.apply_val_fast(x, [&](T&\
    \ t) {\n      t.first += c;\n      t.second += x * c;\n    });\n  }\n  void _push_L(I\
    \ x, I c = 1) { _apply(L, x, c); }\n  void _push_R(I x, I c = 1) { _apply(R, x,\
    \ c); }\n  P _get_L() {\n    assert(!L.empty());\n    auto kv = L.get_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _get_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.get_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  P _getpop_L() {\n    assert(!L.empty());\n    auto kv = L.pop_max_keyval();\n\
    \    return P{kv.first, kv.second.first};\n  }\n  P _getpop_R() {\n    assert(!R.empty());\n\
    \    auto kv = R.pop_min_keyval();\n    return P{kv.first, kv.second.first};\n\
    \  }\n  pair<Seg, Seg> _split_L(I c) {\n    assert(L.fold_all().first >= c);\n\
    \    pair<Seg, Seg> res =\n        L.split_min_left([&](const T& t) { return t.first\
    \ <= c; });\n    c -= res.second.fold_all().first;\n    if (c != 0) {\n      I\
    \ k = res.first.get_max_key();\n      _apply(res.first, k, -c);\n      _apply(res.second,\
    \ k, c);\n    }\n    return res;\n  }\n  pair<Seg, Seg> _split_R(I c) {\n    assert(R.fold_all().first\
    \ >= c);\n    pair<Seg, Seg> res =\n        R.split_max_right([&](const T& t)\
    \ { return t.first <= c; });\n    c -= res.first.fold_all().first;\n    if (c\
    \ != 0) {\n      I k = res.second.get_min_key();\n      _apply(res.first, k, c);\n\
    \      _apply(res.second, k, -c);\n    }\n    return res;\n  }\n  // destructive\
    \ merge\n  Seg _unite(Seg& lhs, Seg& rhs) {\n    if (lhs.empty()) return rhs;\n\
    \    if (rhs.empty()) return lhs;\n    assert(lhs.get_max_key() <= rhs.get_min_key()\
    \ && \"WeightSlopTrick::_unite\");\n    if (lhs.get_max_key() == rhs.get_min_key())\
    \ {\n      auto [x, p] = lhs.pop_max_keyval();\n      _apply(rhs, x, p.first);\n\
    \    }\n    if (lhs.empty()) return rhs;\n    if (rhs.empty()) return lhs;\n \
    \   return ordered_merge(lhs, rhs);\n  }\n\n public:\n  WeightedSlopeTrick() :\
    \ min_y(0) {}\n\n  void debug() {\n    auto LL = L.make_array(), RR = R.make_array();\n\
    \    cerr << \"L : \";\n    for (auto& [k, v] : LL) cerr << \"( \" << k << \"\
    , \" << v.first << \" ), \";\n    cerr << endl << \"R : \";\n    for (auto& [k,\
    \ v] : RR) cerr << \"( \" << k << \", \" << v.first << \" ), \";\n    cerr <<\
    \ endl << \"min : ( \";\n    cerr << get_min().first << \", \" << get_min().second\
    \ << \" )\" << endl;\n  }\n\n  // return {x, y} s.t. {argmin, min}\n  pair<I,\
    \ I> get_min() {\n    I x = L.empty() ? R.empty() ? 0 : _get_R().x : _get_L().x;\n\
    \    return {x, min_y};\n  }\n\n  void shift_L(I a) { L.shift(a), L.apply_all(a);\
    \ }\n  void shift_R(I a) { R.shift(a), R.apply_all(a); }\n  // f(x) <- f(x - a)\n\
    \  void shift_x(I a) { shift_L(a), shift_R(a); }\n  // f(x) <- f(x) + a\n  void\
    \ shift_y(I a) { min_y += a; }\n\n  // add (x-a)_+   _____/\n  void add_xma(I\
    \ a, I c = 1) {\n    _apply(L, a, c);\n    auto [L1, L2] = _split_L(c);\n    auto\
    \ [c_sum, ac_sum] = L2.fold(a, inf);\n    min_y += ac_sum - c_sum * a;\n    auto\
    \ c2 = L2.get_val(a);\n    L2.erase(a);\n    R = _unite(L2, R);\n    _apply(R,\
    \ a, c2.first);\n    L = L1;\n  }\n\n  // add (a-x)_+   \\_____\n  void add_amx(I\
    \ a, I c = 1) {\n    _apply(R, a, c);\n    auto [R1, R2] = _split_R(c);\n    auto\
    \ [c_sum, ac_sum] = R1.fold(-inf, a);\n    min_y += c_sum * a - ac_sum;\n    auto\
    \ c2 = R1.get_val(a);\n    R1.erase(a);\n    L = _unite(L, R1);\n    _apply(L,\
    \ a, c2.first);\n    R = R2;\n  }\n\n  // add |x-a|     \\____/\n  void add_abs_xma(I\
    \ a, I c = 1) {\n    add_xma(a, c);\n    add_amx(a, c);\n  }\n\n  //  chmin right\
    \ side \\_/ -> \\__\n  void chmin_right() { R.clear(); }\n  //  chmin left side\
    \  \\_/ -> __/\n  void chmin_left() { L.clear(); }\n\n  // destructive merge\n\
    \  void merge(WeightedSlopeTrick& r) {\n    if (L.size() + R.size() < r.L.size()\
    \ + r.R.size()) swap(*this, r);\n    for (auto& [x, t] : r.L.make_array()) add_amx(x,\
    \ t.first);\n    for (auto& [x, t] : r.R.make_array()) add_xma(x, t.first);\n\
    \    shift_y(r.min_y);\n  }\n\n  I eval(I x) {\n    I res = min_y;\n    if (!L.empty()\
    \ && _get_L().x > x) {\n      auto [L1, L2] = L.split_by_key(x);\n      auto [c_sum,\
    \ xc_sum] = L2.fold_all();\n      res += xc_sum - c_sum * x;\n      L = _unite(L1,\
    \ L2);\n    }\n    if (!R.empty() && _get_R().x < x) {\n      auto [R1, R2] =\
    \ R.split_by_key(x);\n      auto [c_sum, xc_sum] = R1.fold_all();\n      res +=\
    \ c_sum * x - xc_sum;\n      R = _unite(R1, R2);\n    }\n    return res;\n  }\n\
    \n  void clear() { L.clear(), R.clear(), min_y = 0; }\n};\n\nusing SlopeTrick\
    \ = WeightedSlopeTrick<__int128_t>;\n\n/**\n * @brief Weighted Slope Trick\n */\n"
  dependsOn:
  - segment-tree/rbst-segment-tree.hpp
  isVerificationFile: false
  path: data-structure/slope-trick-weighted.hpp
  requiredBy: []
  timestamp: '2023-03-24 20:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1467-weighted.test.cpp
documentation_of: data-structure/slope-trick-weighted.hpp
layout: document
redirect_from:
- /library/data-structure/slope-trick-weighted.hpp
- /library/data-structure/slope-trick-weighted.hpp.html
title: Weighted Slope Trick
---
