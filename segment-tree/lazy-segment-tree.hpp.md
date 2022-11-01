---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/lazyseg-setval-2.test.cpp
    title: verify/verify-unit-test/lazyseg-setval-2.test.cpp
  - icon: ':x:'
    path: verify/verify-unit-test/rbst-segment-tree.test.cpp
    title: verify/verify-unit-test/rbst-segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-lazysegtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-lazysegtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/lazy-segment-tree.hpp\"\n\n// LazySegmentTree\n\
    template <typename T, typename E, typename F, typename G, typename H>\nstruct\
    \ LazySegmentTree {\n  int n, height;\n  F f;\n  G g;\n  H h;\n  T ti;\n  E ei;\n\
    \  vector<T> dat;\n  vector<E> laz;\n  LazySegmentTree(int _n, F _f, G _g, H _h,\
    \ T _ti, E _ei)\n      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n    init(_n);\n\
    \  }\n  LazySegmentTree(const vector<T> &v, F _f, G _g, H _h, T _ti, E _ei)\n\
    \      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n    init((int)v.size());\n \
    \   build(v);\n  }\n  void init(int _n) {\n    n = 1;\n    height = 0;\n    while\
    \ (n < _n) n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2 *\
    \ n, ei);\n  }\n  void build(const vector<T> &v) {\n    int _n = v.size();\n \
    \   init(_n);\n    for (int i = 0; i < _n; i++) dat[n + i] = v[i];\n    for (int\
    \ i = n - 1; i; i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n\
    \  }\n  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);\
    \ }\n  inline void eval(int k) {\n    if (laz[k] == ei) return;\n    laz[(k <<\
    \ 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k <<\
    \ 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = ei;\n  }\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) eval(k >> i);\n  }\n\
    \  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = f(reflect((k << 1)\
    \ | 0), reflect((k << 1) | 1));\n  }\n  void update(int a, int b, E x) {\n   \
    \ if (a >= b) return;\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int\
    \ l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n\
    \    recalc(b);\n  }\n  void set_val(int a, T x) {\n    thrust(a += n);\n    dat[a]\
    \ = x;\n    laz[a] = ei;\n    recalc(a);\n  }\n  T get_val(int a) {\n    thrust(a\
    \ += n);\n    return reflect(a);\n  }\n  T query(int a, int b) {\n    if (a >=\
    \ b) return ti;\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = ti,\
    \ vr = ti;\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) vl = f(vl, reflect(l++));\n      if (r & 1) vr = f(reflect(--r), vr);\n\
    \    }\n    return f(vl, vr);\n  }\n};\n"
  code: "#pragma once\n\n// LazySegmentTree\ntemplate <typename T, typename E, typename\
    \ F, typename G, typename H>\nstruct LazySegmentTree {\n  int n, height;\n  F\
    \ f;\n  G g;\n  H h;\n  T ti;\n  E ei;\n  vector<T> dat;\n  vector<E> laz;\n \
    \ LazySegmentTree(int _n, F _f, G _g, H _h, T _ti, E _ei)\n      : f(_f), g(_g),\
    \ h(_h), ti(_ti), ei(_ei) {\n    init(_n);\n  }\n  LazySegmentTree(const vector<T>\
    \ &v, F _f, G _g, H _h, T _ti, E _ei)\n      : f(_f), g(_g), h(_h), ti(_ti), ei(_ei)\
    \ {\n    init((int)v.size());\n    build(v);\n  }\n  void init(int _n) {\n   \
    \ n = 1;\n    height = 0;\n    while (n < _n) n <<= 1, height++;\n    dat.assign(2\
    \ * n, ti);\n    laz.assign(2 * n, ei);\n  }\n  void build(const vector<T> &v)\
    \ {\n    int _n = v.size();\n    init(_n);\n    for (int i = 0; i < _n; i++) dat[n\
    \ + i] = v[i];\n    for (int i = n - 1; i; i--)\n      dat[i] = f(dat[(i << 1)\
    \ | 0], dat[(i << 1) | 1]);\n  }\n  inline T reflect(int k) { return laz[k] ==\
    \ ei ? dat[k] : g(dat[k], laz[k]); }\n  inline void eval(int k) {\n    if (laz[k]\
    \ == ei) return;\n    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k\
    \ << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k]\
    \ = ei;\n  }\n  inline void thrust(int k) {\n    for (int i = height; i; i--)\
    \ eval(k >> i);\n  }\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k]\
    \ = f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n  }\n  void update(int a,\
    \ int b, E x) {\n    if (a >= b) return;\n    thrust(a += n);\n    thrust(b +=\
    \ n - 1);\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) laz[l] = h(laz[l], x), l++;\n      if (r & 1) --r, laz[r] = h(laz[r],\
    \ x);\n    }\n    recalc(a);\n    recalc(b);\n  }\n  void set_val(int a, T x)\
    \ {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n\
    \  }\n  T get_val(int a) {\n    thrust(a += n);\n    return reflect(a);\n  }\n\
    \  T query(int a, int b) {\n    if (a >= b) return ti;\n    thrust(a += n);\n\
    \    thrust(b += n - 1);\n    T vl = ti, vr = ti;\n    for (int l = a, r = b +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl = f(vl, reflect(l++));\n\
    \      if (r & 1) vr = f(reflect(--r), vr);\n    }\n    return f(vl, vr);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-11 08:39:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-lazysegtree.test.cpp
  - verify/verify-unit-test/rbst-segment-tree.test.cpp
  - verify/verify-unit-test/lazyseg-setval-2.test.cpp
documentation_of: segment-tree/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree.hpp
- /library/segment-tree/lazy-segment-tree.hpp.html
title: segment-tree/lazy-segment-tree.hpp
---
