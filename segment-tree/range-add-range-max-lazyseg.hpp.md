---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/range-add-range-max-lazyseg.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename E, E MINF>\nstruct\
    \ AddMax_LazySegmentTree {\n  int n, height;\n  using T = E;\n  T f(T a, T b)\
    \ { return max(a, b); };\n  T g(T a, E b) { return a + b; };\n  E h(E a, E b)\
    \ { return a + b; };\n  T ti = MINF;\n  E ei = 0;\n  vector<T> dat;\n  vector<E>\
    \ laz;\n\n  AddMax_LazySegmentTree(const vector<E> &v) { build(v); }\n\n  void\
    \ init(int n_) {\n    n = 1;\n    height = 0;\n    while (n < n_) n <<= 1, height++;\n\
    \    dat.assign(2 * n, ti);\n    laz.assign(2 * n, ei);\n  }\n\n  void build(const\
    \ vector<E> &v) {\n    int n_ = v.size();\n    init(n_);\n    for (int i = 0;\
    \ i < n_; i++) dat[n + i] = v[i];\n    for (int i = n - 1; i; i--)\n      dat[i]\
    \ = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n  }\n\n  inline T reflect(int k)\
    \ { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }\n\n  inline void propagate(int\
    \ k) {\n    if (laz[k] == ei) return;\n    laz[(k << 1) | 0] = h(laz[(k << 1)\
    \ | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);\n    dat[k]\
    \ = reflect(k);\n    laz[k] = ei;\n  }\n\n  inline void thrust(int k) {\n    for\
    \ (int i = height; i; i--) propagate(k >> i);\n  }\n\n  inline void recalc(int\
    \ k) {\n    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1)\
    \ | 1));\n  }\n\n  void update(int a, int b, E x) {\n    if (a >= b) return;\n\
    \    thrust(a += n);\n    thrust(b += n - 1);\n    for (int l = a, r = b + 1;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = h(laz[l], x), l++;\n \
    \     if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  void set_val(int a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n \
    \   laz[a] = ei;\n    recalc(a);\n  }\n\n  T query(int a, int b) {\n    if (a\
    \ >= b) return ti;\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = ti,\
    \ vr = ti;\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) vl = f(vl, reflect(l++));\n      if (r & 1) vr = f(reflect(--r), vr);\n\
    \    }\n    return f(vl, vr);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename E, E MINF>\nstruct AddMax_LazySegmentTree {\n  int n, height;\n  using\
    \ T = E;\n  T f(T a, T b) { return max(a, b); };\n  T g(T a, E b) { return a +\
    \ b; };\n  E h(E a, E b) { return a + b; };\n  T ti = MINF;\n  E ei = 0;\n  vector<T>\
    \ dat;\n  vector<E> laz;\n\n  AddMax_LazySegmentTree(const vector<E> &v) { build(v);\
    \ }\n\n  void init(int n_) {\n    n = 1;\n    height = 0;\n    while (n < n_)\
    \ n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2 * n, ei);\n\
    \  }\n\n  void build(const vector<E> &v) {\n    int n_ = v.size();\n    init(n_);\n\
    \    for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n    for (int i = n - 1;\
    \ i; i--)\n      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n  }\n\n  inline\
    \ T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }\n\n \
    \ inline void propagate(int k) {\n    if (laz[k] == ei) return;\n    laz[(k <<\
    \ 1) | 0] = h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = h(laz[(k <<\
    \ 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k] = ei;\n  }\n\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) propagate(k >> i);\n\
    \  }\n\n  inline void recalc(int k) {\n    while (k >>= 1) dat[k] = f(reflect((k\
    \ << 1) | 0), reflect((k << 1) | 1));\n  }\n\n  void update(int a, int b, E x)\
    \ {\n    if (a >= b) return;\n    thrust(a += n);\n    thrust(b += n - 1);\n \
    \   for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l]\
    \ = h(laz[l], x), l++;\n      if (r & 1) --r, laz[r] = h(laz[r], x);\n    }\n\
    \    recalc(a);\n    recalc(b);\n  }\n\n  void set_val(int a, T x) {\n    thrust(a\
    \ += n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n  }\n\n  T query(int\
    \ a, int b) {\n    if (a >= b) return ti;\n    thrust(a += n);\n    thrust(b +=\
    \ n - 1);\n    T vl = ti, vr = ti;\n    for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) vl = f(vl, reflect(l++));\n      if (r & 1)\
    \ vr = f(reflect(--r), vr);\n    }\n    return f(vl, vr);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/range-add-range-max-lazyseg.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-2-h-max.test.cpp
documentation_of: segment-tree/range-add-range-max-lazyseg.hpp
layout: document
redirect_from:
- /library/segment-tree/range-add-range-max-lazyseg.hpp
- /library/segment-tree/range-add-range-max-lazyseg.hpp.html
title: segment-tree/range-add-range-max-lazyseg.hpp
---
