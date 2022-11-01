---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/lazyseg-setval.test.cpp
    title: verify/verify-unit-test/lazyseg-setval.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/lazy-segment-tree-utility.md
    document_title: "\u4F7F\u7528\u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"segment-tree/lazy-segment-tree-utility.hpp\"\n\ntemplate\
    \ <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n       \
    \   T (*ti)(), E (*ei)()>\nstruct LazySegmentTree {\n  int n, log;\n  vector<T>\
    \ val;\n  vector<E> laz;\n\n  explicit LazySegmentTree() {}\n  explicit LazySegmentTree(const\
    \ vector<T>& vc) { init(vc); }\n\n  void init(const vector<T>& vc) {\n    n =\
    \ 1, log = 0;\n    while (n < (int)vc.size()) n <<= 1, log++;\n    val.resize(2\
    \ * n, ti());\n    laz.resize(n, ei());\n    for (int i = 0; i < (int)vc.size();\
    \ ++i) val[i + n] = vc[i];\n    for (int i = n - 1; i; --i) _update(i);\n  }\n\
    \n  void update(int l, int r, const E& x) {\n    if (l == r) return;\n    l +=\
    \ n, r += n;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) _push(l >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n\
    \    }\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l\
    \ & 1) _apply(l++, x);\n        if (r & 1) _apply(--r, x);\n        l >>= 1;\n\
    \        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n    for (int\
    \ i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) _update(l >> i);\n\
    \      if (((r >> i) << i) != r) _update((r - 1) >> i);\n    }\n  }\n\n  T query(int\
    \ l, int r) {\n    if (l == r) return ti();\n    l += n, r += n;\n    T L = ti(),\
    \ R = ti();\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) !=\
    \ l) _push(l >> i);\n      if (((r >> i) << i) != r) _push((r - 1) >> i);\n  \
    \  }\n    while (l < r) {\n      if (l & 1) L = f(L, val[l++]);\n      if (r &\
    \ 1) R = f(val[--r], R);\n      l >>= 1;\n      r >>= 1;\n    }\n    return f(L,\
    \ R);\n  }\n\n  void set_val(int k, const T& x) {\n    k += n;\n    for (int i\
    \ = log; i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) <<\
    \ i) != (k + 1))\n        _push(k >> i);\n    }\n    val[k] = x;\n    for (int\
    \ i = 1; i <= log; i++) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) <<\
    \ i) != (k + 1))\n        _update(k >> i);\n    }\n  }\n\n  void update_val(int\
    \ k, const E& x) {\n    k += n;\n    for (int i = log; i >= 1; i--) {\n      if\
    \ (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _push(k\
    \ >> i);\n    }\n    val[k] = g(val[k], x);\n    for (int i = 1; i <= log; i++)\
    \ {\n      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n   \
    \     _update(k >> i);\n    }\n  }\n\n  T get_val(int k) {\n    k += n;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >>\
    \ i) << i) != (k + 1))\n        _push(k >> i);\n    }\n    return val[k];\n  }\n\
    \n private:\n  void _push(int i) {\n    if (laz[i] != ei()) {\n      val[2 * i\
    \ + 0] = g(val[2 * i + 0], laz[i]);\n      val[2 * i + 1] = g(val[2 * i + 1],\
    \ laz[i]);\n      if (2 * i < n) {\n        compose(laz[2 * i + 0], laz[i]);\n\
    \        compose(laz[2 * i + 1], laz[i]);\n      }\n      laz[i] = ei();\n   \
    \ }\n  }\n  inline void _update(int i) { val[i] = f(val[2 * i + 0], val[2 * i\
    \ + 1]); }\n  inline void _apply(int i, const E& x) {\n    if (x != ei()) {\n\
    \      val[i] = g(val[i], x);\n      if (i < n) compose(laz[i], x);\n    }\n \
    \ }\n  inline void compose(E& a, const E& b) { a = a == ei() ? b : h(a, b); }\n\
    };\n\nnamespace SegmentTreeUtil {\n\ntemplate <typename T>\nstruct Pair {\n  T\
    \ first, second;\n  Pair() = default;\n  Pair(const T& f, const T& s) : first(f),\
    \ second(s) {}\n  operator T() const { return first; }\n  friend ostream& operator<<(ostream&\
    \ os, const Pair<T>& p) {\n    os << T(p.first);\n    return os;\n  }\n};\n\n\
    template <typename T>\nT Mx(T a, T b) {\n  return max(a, b);\n}\ntemplate <typename\
    \ T>\nT Mn(T a, T b) {\n  return min(a, b);\n}\ntemplate <typename T>\nT Update(T,\
    \ T b) {\n  return b;\n}\ntemplate <typename T>\nT Add(T a, T b) {\n  return a\
    \ + b;\n}\ntemplate <typename T>\nPair<T> Psum(Pair<T> a, Pair<T> b) {\n  return\
    \ Pair<T>(a.first + b.first, a.second + b.second);\n}\ntemplate <typename T>\n\
    Pair<T> Padd(Pair<T> a, T b) {\n  return Pair<T>(a.first + a.second * b, a.second);\n\
    }\ntemplate <typename T>\nPair<T> PUpdate(Pair<T> a, T b) {\n  return Pair<T>(a.second\
    \ * b, a.second);\n}\ntemplate <typename T>\nPair<T> Pid() {\n  return Pair<T>(0,\
    \ 0);\n}\ntemplate <typename T>\nT Zero() {\n  return T(0);\n}\ntemplate <typename\
    \ T, T val>\nT Const() {\n  return val;\n}\n\ntemplate <typename T, T MINF>\n\
    struct AddMax_LazySegmentTree\n    : LazySegmentTree<T, T, Mx<T>, Add<T>, Add<T>,\
    \ Const<T, MINF>, Zero<T>> {\n  using base =\n      LazySegmentTree<T, T, Mx<T>,\
    \ Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;\n  AddMax_LazySegmentTree(const vector<T>&\
    \ v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct AddMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n\
    \  using base =\n      LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>,\
    \ Zero<T>>;\n  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T>\nstruct AddSum_LazySegmentTree\n    : LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>> {\n  using base =\n      LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const\
    \ vector<T>& v) {\n    vector<Pair<T>> w(v.size());\n    for (int i = 0; i < (int)v.size();\
    \ i++) w[i] = Pair<T>(v[i], 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename\
    \ T, T MINF>\nstruct UpdateMax_LazySegmentTree\n    : LazySegmentTree<T, T, Mx<T>,\
    \ Update<T>, Update<T>, Const<T, MINF>,\n                      Const<T, MINF>>\
    \ {\n  using base = LazySegmentTree<T, T, Mx<T>, Update<T>, Update<T>,\n     \
    \                          Const<T, MINF>, Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,\n   \
    \                   Const<T, INF>> {\n  using base = LazySegmentTree<T, T, Mn<T>,\
    \ Update<T>, Update<T>,\n                               Const<T, INF>, Const<T,\
    \ INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n    :\
    \ LazySegmentTree<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,\n      \
    \                Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, PUpdate<T>, Update<T>,\n                               Pid<T>, Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n\n/**\n * @brief \u4F7F\u7528\
    \u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @docs docs/segment-tree/lazy-segment-tree-utility.md\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename E, T (*f)(T, T), T (*g)(T,\
    \ E), E (*h)(E, E),\n          T (*ti)(), E (*ei)()>\nstruct LazySegmentTree {\n\
    \  int n, log;\n  vector<T> val;\n  vector<E> laz;\n\n  explicit LazySegmentTree()\
    \ {}\n  explicit LazySegmentTree(const vector<T>& vc) { init(vc); }\n\n  void\
    \ init(const vector<T>& vc) {\n    n = 1, log = 0;\n    while (n < (int)vc.size())\
    \ n <<= 1, log++;\n    val.resize(2 * n, ti());\n    laz.resize(n, ei());\n  \
    \  for (int i = 0; i < (int)vc.size(); ++i) val[i + n] = vc[i];\n    for (int\
    \ i = n - 1; i; --i) _update(i);\n  }\n\n  void update(int l, int r, const E&\
    \ x) {\n    if (l == r) return;\n    l += n, r += n;\n    for (int i = log; i\
    \ >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l >> i);\n      if (((r\
    \ >> i) << i) != r) _push((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 =\
    \ r;\n      while (l < r) {\n        if (l & 1) _apply(l++, x);\n        if (r\
    \ & 1) _apply(--r, x);\n        l >>= 1;\n        r >>= 1;\n      }\n      l =\
    \ l2;\n      r = r2;\n    }\n    for (int i = 1; i <= log; i++) {\n      if (((l\
    \ >> i) << i) != l) _update(l >> i);\n      if (((r >> i) << i) != r) _update((r\
    \ - 1) >> i);\n    }\n  }\n\n  T query(int l, int r) {\n    if (l == r) return\
    \ ti();\n    l += n, r += n;\n    T L = ti(), R = ti();\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) _push(l >> i);\n      if (((r\
    \ >> i) << i) != r) _push((r - 1) >> i);\n    }\n    while (l < r) {\n      if\
    \ (l & 1) L = f(L, val[l++]);\n      if (r & 1) R = f(val[--r], R);\n      l >>=\
    \ 1;\n      r >>= 1;\n    }\n    return f(L, R);\n  }\n\n  void set_val(int k,\
    \ const T& x) {\n    k += n;\n    for (int i = log; i >= 1; i--) {\n      if (((k\
    \ >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _push(k >> i);\n\
    \    }\n    val[k] = x;\n    for (int i = 1; i <= log; i++) {\n      if (((k >>\
    \ i) << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _update(k >> i);\n\
    \    }\n  }\n\n  void update_val(int k, const E& x) {\n    k += n;\n    for (int\
    \ i = log; i >= 1; i--) {\n      if (((k >> i) << i) != k || (((k + 1) >> i) <<\
    \ i) != (k + 1))\n        _push(k >> i);\n    }\n    val[k] = g(val[k], x);\n\
    \    for (int i = 1; i <= log; i++) {\n      if (((k >> i) << i) != k || (((k\
    \ + 1) >> i) << i) != (k + 1))\n        _update(k >> i);\n    }\n  }\n\n  T get_val(int\
    \ k) {\n    k += n;\n    for (int i = log; i >= 1; i--) {\n      if (((k >> i)\
    \ << i) != k || (((k + 1) >> i) << i) != (k + 1))\n        _push(k >> i);\n  \
    \  }\n    return val[k];\n  }\n\n private:\n  void _push(int i) {\n    if (laz[i]\
    \ != ei()) {\n      val[2 * i + 0] = g(val[2 * i + 0], laz[i]);\n      val[2 *\
    \ i + 1] = g(val[2 * i + 1], laz[i]);\n      if (2 * i < n) {\n        compose(laz[2\
    \ * i + 0], laz[i]);\n        compose(laz[2 * i + 1], laz[i]);\n      }\n    \
    \  laz[i] = ei();\n    }\n  }\n  inline void _update(int i) { val[i] = f(val[2\
    \ * i + 0], val[2 * i + 1]); }\n  inline void _apply(int i, const E& x) {\n  \
    \  if (x != ei()) {\n      val[i] = g(val[i], x);\n      if (i < n) compose(laz[i],\
    \ x);\n    }\n  }\n  inline void compose(E& a, const E& b) { a = a == ei() ? b\
    \ : h(a, b); }\n};\n\nnamespace SegmentTreeUtil {\n\ntemplate <typename T>\nstruct\
    \ Pair {\n  T first, second;\n  Pair() = default;\n  Pair(const T& f, const T&\
    \ s) : first(f), second(s) {}\n  operator T() const { return first; }\n  friend\
    \ ostream& operator<<(ostream& os, const Pair<T>& p) {\n    os << T(p.first);\n\
    \    return os;\n  }\n};\n\ntemplate <typename T>\nT Mx(T a, T b) {\n  return\
    \ max(a, b);\n}\ntemplate <typename T>\nT Mn(T a, T b) {\n  return min(a, b);\n\
    }\ntemplate <typename T>\nT Update(T, T b) {\n  return b;\n}\ntemplate <typename\
    \ T>\nT Add(T a, T b) {\n  return a + b;\n}\ntemplate <typename T>\nPair<T> Psum(Pair<T>\
    \ a, Pair<T> b) {\n  return Pair<T>(a.first + b.first, a.second + b.second);\n\
    }\ntemplate <typename T>\nPair<T> Padd(Pair<T> a, T b) {\n  return Pair<T>(a.first\
    \ + a.second * b, a.second);\n}\ntemplate <typename T>\nPair<T> PUpdate(Pair<T>\
    \ a, T b) {\n  return Pair<T>(a.second * b, a.second);\n}\ntemplate <typename\
    \ T>\nPair<T> Pid() {\n  return Pair<T>(0, 0);\n}\ntemplate <typename T>\nT Zero()\
    \ {\n  return T(0);\n}\ntemplate <typename T, T val>\nT Const() {\n  return val;\n\
    }\n\ntemplate <typename T, T MINF>\nstruct AddMax_LazySegmentTree\n    : LazySegmentTree<T,\
    \ T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>> {\n  using base =\n     \
    \ LazySegmentTree<T, T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;\n  AddMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct AddMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n\
    \  using base =\n      LazySegmentTree<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>,\
    \ Zero<T>>;\n  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T>\nstruct AddSum_LazySegmentTree\n    : LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>> {\n  using base =\n      LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const\
    \ vector<T>& v) {\n    vector<Pair<T>> w(v.size());\n    for (int i = 0; i < (int)v.size();\
    \ i++) w[i] = Pair<T>(v[i], 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename\
    \ T, T MINF>\nstruct UpdateMax_LazySegmentTree\n    : LazySegmentTree<T, T, Mx<T>,\
    \ Update<T>, Update<T>, Const<T, MINF>,\n                      Const<T, MINF>>\
    \ {\n  using base = LazySegmentTree<T, T, Mx<T>, Update<T>, Update<T>,\n     \
    \                          Const<T, MINF>, Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,\n   \
    \                   Const<T, INF>> {\n  using base = LazySegmentTree<T, T, Mn<T>,\
    \ Update<T>, Update<T>,\n                               Const<T, INF>, Const<T,\
    \ INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n    :\
    \ LazySegmentTree<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,\n      \
    \                Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, PUpdate<T>, Update<T>,\n                               Pid<T>, Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n\n/**\n * @brief \u4F7F\u7528\
    \u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @docs docs/segment-tree/lazy-segment-tree-utility.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree-utility.hpp
  requiredBy: []
  timestamp: '2021-04-26 16:30:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
  - verify/verify-yosupo-ds/yosupo-lazysegtree-2.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - verify/verify-unit-test/lazyseg-setval.test.cpp
documentation_of: segment-tree/lazy-segment-tree-utility.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree-utility.hpp
- /library/segment-tree/lazy-segment-tree-utility.hpp.html
title: "\u4F7F\u7528\u983B\u5EA6\u306E\u9AD8\u3044\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---
## 使用頻度の高い遅延セグメント木

使用頻度の高い遅延セグメント木を特殊化してライブラリ化したもの。

#### 使い方

以下の6種類の遅延セグメント木を特殊化している。いずれも`クラス名(初期値の入ったvector)`で初期化、`update(l, r, x)`で`[l, r)`に`x`を作用、`query(l, r)`で`[l, r)`の積を取得できる。

- `AddMax_LazySegmentTree` : Range Add Query & Range Max Query
- `AddMin_LazySegmentTree` : Range Min Query & Range Min Query
- `AddSum_LazySegmentTree` : Range Sum Query & Range Sum Query
- `UpdateMax_LazySegmentTree` : Range Update Query & Range Max Query
- `UpdateMin_LazySegmentTree` : Range Update Query & Range Min Query
- `UpdateSum_LazySegmentTree` : Range Update Query & Range Sum Query
