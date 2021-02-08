---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
  - icon: ':x:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
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
    \ = log; i >= 1; i--) {\n      if (((k >> i) << i) != k) _push(k >> i);\n    }\n\
    \    val[k] = x;\n    for (int i = 1; i <= log; i++) {\n      if (((k >> i) <<\
    \ i) != k) _update(k >> i);\n    }\n  }\n\n  void update_val(int k, const E& x)\
    \ {\n    k += n;\n    for (int i = log; i >= 1; i--) {\n      if (((k >> i) <<\
    \ i) != k) _push(k >> i);\n    }\n    val[k] = g(val[k], x);\n    for (int i =\
    \ 1; i <= log; i++) {\n      if (((k >> i) << i) != k) _update(k >> i);\n    }\n\
    \  }\n\n  T get_val(int k) {\n    k += n;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((k >> i) << i) != k) _push(k >> i);\n    }\n    return val[k];\n\
    \  }\n\n private:\n  void _push(int i) {\n    if (laz[i] != ei()) {\n      val[2\
    \ * i + 0] = g(val[2 * i + 0], laz[i]);\n      val[2 * i + 1] = g(val[2 * i +\
    \ 1], laz[i]);\n      if (2 * i < n) {\n        laz[2 * i + 0] = h(laz[i], laz[2\
    \ * i + 0]);\n        laz[2 * i + 1] = h(laz[i], laz[2 * i + 1]);\n      }\n \
    \     laz[i] = ei();\n    }\n  }\n  void _update(int i) { val[i] = f(val[2 * i\
    \ + 0], val[2 * i + 1]); }\n  void _apply(int i, const E& x) {\n    if (x != ei())\
    \ {\n      val[i] = g(val[i], x);\n      if (i < n) laz[i] = h(laz[i], x);\n \
    \   }\n  }\n};\n\nnamespace SegmentTreeUtil {\n\ntemplate <typename T>\nstruct\
    \ Pair {\n  T first, second;\n  Pair() = default;\n  Pair(const T& f, const T&\
    \ s) : first(f), second(s) {}\n  operator T() const { return first; }\n};\n\n\
    template <typename T>\nT Max(T a, T b) {\n  return max(a, b);\n}\ntemplate <typename\
    \ T>\nT Min(T a, T b) {\n  return min(a, b);\n}\ntemplate <typename T>\nT Update(T,\
    \ T b) {\n  return b;\n}\ntemplate <typename T>\nT Add(T a, T b) {\n  return a\
    \ + b;\n}\ntemplate <typename T>\nPair<T> Psum(Pair<T> a, Pair<T> b) {\n  return\
    \ Pair<T>(a.first + b.first, a.second + b.second);\n}\ntemplate <typename T>\n\
    Pair<T> Padd(Pair<T> a, T b) {\n  return Pair<T>(a.first + a.second * b, a.second);\n\
    }\ntemplate <typename T>\nPair<T> Pid() {\n  return Pair<T>(0, 0);\n}\ntemplate\
    \ <typename T>\nT Zero() {\n  return T(0);\n}\ntemplate <typename T, T val>\n\
    T Const() {\n  return val;\n}\n\ntemplate <typename T, T MINF>\nstruct AddMax_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Max<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>\
    \ {\n  using base =\n      LazySegmentTree<T, T, Max<T>, Add<T>, Add<T>, Const<T,\
    \ MINF>, Zero<T>>;\n  AddMax_LazySegmentTree(const vector<T>& v) : base(v) {}\n\
    };\n\ntemplate <typename T, T INF>\nstruct AddMin_LazySegmentTree\n    : LazySegmentTree<T,\
    \ T, Min<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n  using base =\n     \
    \ LazySegmentTree<T, T, Min<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>>;\n  AddMin_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T>\nstruct AddSum_LazySegmentTree\n\
    \    : LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>\
    \ {\n  using base =\n      LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Add<T>,\
    \ Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename T, T MINF>\nstruct UpdateMax_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Max<T>, Update<T>, Update<T>, Const<T, MINF>,\n \
    \                     Const<T, MINF>> {\n  using base = LazySegmentTree<T, T,\
    \ Max<T>, Update<T>, Update<T>,\n                               Const<T, MINF>,\
    \ Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const vector<T>& v) : base(v)\
    \ {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n \
    \   : LazySegmentTree<T, T, Min<T>, Update<T>, Update<T>, Const<T, INF>,\n   \
    \                   Const<T, INF>> {\n  using base = LazySegmentTree<T, T, Min<T>,\
    \ Update<T>, Update<T>,\n                               Const<T, INF>, Const<T,\
    \ INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n    :\
    \ LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Update<T>, Pid<T>,\n         \
    \             Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Update<T>, Pid<T>,\n                               Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n"
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
    \ >> i) << i) != k) _push(k >> i);\n    }\n    val[k] = x;\n    for (int i = 1;\
    \ i <= log; i++) {\n      if (((k >> i) << i) != k) _update(k >> i);\n    }\n\
    \  }\n\n  void update_val(int k, const E& x) {\n    k += n;\n    for (int i =\
    \ log; i >= 1; i--) {\n      if (((k >> i) << i) != k) _push(k >> i);\n    }\n\
    \    val[k] = g(val[k], x);\n    for (int i = 1; i <= log; i++) {\n      if (((k\
    \ >> i) << i) != k) _update(k >> i);\n    }\n  }\n\n  T get_val(int k) {\n   \
    \ k += n;\n    for (int i = log; i >= 1; i--) {\n      if (((k >> i) << i) !=\
    \ k) _push(k >> i);\n    }\n    return val[k];\n  }\n\n private:\n  void _push(int\
    \ i) {\n    if (laz[i] != ei()) {\n      val[2 * i + 0] = g(val[2 * i + 0], laz[i]);\n\
    \      val[2 * i + 1] = g(val[2 * i + 1], laz[i]);\n      if (2 * i < n) {\n \
    \       laz[2 * i + 0] = h(laz[i], laz[2 * i + 0]);\n        laz[2 * i + 1] =\
    \ h(laz[i], laz[2 * i + 1]);\n      }\n      laz[i] = ei();\n    }\n  }\n  void\
    \ _update(int i) { val[i] = f(val[2 * i + 0], val[2 * i + 1]); }\n  void _apply(int\
    \ i, const E& x) {\n    if (x != ei()) {\n      val[i] = g(val[i], x);\n     \
    \ if (i < n) laz[i] = h(laz[i], x);\n    }\n  }\n};\n\nnamespace SegmentTreeUtil\
    \ {\n\ntemplate <typename T>\nstruct Pair {\n  T first, second;\n  Pair() = default;\n\
    \  Pair(const T& f, const T& s) : first(f), second(s) {}\n  operator T() const\
    \ { return first; }\n};\n\ntemplate <typename T>\nT Max(T a, T b) {\n  return\
    \ max(a, b);\n}\ntemplate <typename T>\nT Min(T a, T b) {\n  return min(a, b);\n\
    }\ntemplate <typename T>\nT Update(T, T b) {\n  return b;\n}\ntemplate <typename\
    \ T>\nT Add(T a, T b) {\n  return a + b;\n}\ntemplate <typename T>\nPair<T> Psum(Pair<T>\
    \ a, Pair<T> b) {\n  return Pair<T>(a.first + b.first, a.second + b.second);\n\
    }\ntemplate <typename T>\nPair<T> Padd(Pair<T> a, T b) {\n  return Pair<T>(a.first\
    \ + a.second * b, a.second);\n}\ntemplate <typename T>\nPair<T> Pid() {\n  return\
    \ Pair<T>(0, 0);\n}\ntemplate <typename T>\nT Zero() {\n  return T(0);\n}\ntemplate\
    \ <typename T, T val>\nT Const() {\n  return val;\n}\n\ntemplate <typename T,\
    \ T MINF>\nstruct AddMax_LazySegmentTree\n    : LazySegmentTree<T, T, Max<T>,\
    \ Add<T>, Add<T>, Const<T, MINF>, Zero<T>> {\n  using base =\n      LazySegmentTree<T,\
    \ T, Max<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;\n  AddMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct AddMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Min<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {\n\
    \  using base =\n      LazySegmentTree<T, T, Min<T>, Add<T>, Add<T>, Const<T,\
    \ INF>, Zero<T>>;\n  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n\
    };\n\ntemplate <typename T>\nstruct AddSum_LazySegmentTree\n    : LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>> {\n  using base =\n      LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Add<T>, Pid<T>, Zero<T>>;\n  AddSum_LazySegmentTree(const\
    \ vector<T>& v) {\n    vector<Pair<T>> w(v.size());\n    for (int i = 0; i < (int)v.size();\
    \ i++) w[i] = Pair<T>(v[i], 1);\n    base::init(w);\n  }\n};\n\ntemplate <typename\
    \ T, T MINF>\nstruct UpdateMax_LazySegmentTree\n    : LazySegmentTree<T, T, Max<T>,\
    \ Update<T>, Update<T>, Const<T, MINF>,\n                      Const<T, MINF>>\
    \ {\n  using base = LazySegmentTree<T, T, Max<T>, Update<T>, Update<T>,\n    \
    \                           Const<T, MINF>, Const<T, MINF>>;\n  UpdateMax_LazySegmentTree(const\
    \ vector<T>& v) : base(v) {}\n};\n\ntemplate <typename T, T INF>\nstruct UpdateMin_LazySegmentTree\n\
    \    : LazySegmentTree<T, T, Min<T>, Update<T>, Update<T>, Const<T, INF>,\n  \
    \                    Const<T, INF>> {\n  using base = LazySegmentTree<T, T, Min<T>,\
    \ Update<T>, Update<T>,\n                               Const<T, INF>, Const<T,\
    \ INF>>;\n  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}\n};\n\n\
    template <typename T, T UNUSED_VALUE>\nstruct UpdateSum_LazySegmentTree\n    :\
    \ LazySegmentTree<Pair<T>, T, Psum<T>, Padd<T>, Update<T>, Pid<T>,\n         \
    \             Const<T, UNUSED_VALUE>> {\n  using base = LazySegmentTree<Pair<T>,\
    \ T, Psum<T>, Padd<T>, Update<T>, Pid<T>,\n                               Const<T,\
    \ UNUSED_VALUE>>;\n  UpdateSum_LazySegmentTree(const vector<T>& v) {\n    vector<Pair<T>>\
    \ w(v.size());\n    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i],\
    \ 1);\n    base::init(w);\n  }\n};\n\n}  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::AddMax_LazySegmentTree;\n\
    using SegmentTreeUtil::AddMin_LazySegmentTree;\nusing SegmentTreeUtil::AddSum_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateMax_LazySegmentTree;\nusing SegmentTreeUtil::UpdateMin_LazySegmentTree;\n\
    using SegmentTreeUtil::UpdateSum_LazySegmentTree;\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree-utility.hpp
  requiredBy: []
  timestamp: '2021-02-08 19:11:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-2-g.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-f-max.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-h.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-i.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-d.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-f.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-e.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
documentation_of: segment-tree/lazy-segment-tree-utility.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree-utility.hpp
- /library/segment-tree/lazy-segment-tree-utility.hpp.html
title: segment-tree/lazy-segment-tree-utility.hpp
---
