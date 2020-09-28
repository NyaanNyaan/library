---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/range-weighted-add-range-sum-lazyseg.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T, typename\
    \ E>\nstruct Range_Weighted_Add_Range_Sum_SegTree {\n  int n, height;\n  T ti\
    \ = {0, 0};\n  E ei = 0;\n  vector<T> dat;\n  vector<E> laz;\n  Range_Weighted_Add_Range_Sum_SegTree(const\
    \ vector<T> &v) {\n    init((int)v.size());\n    build(v);\n  }\n\n  void init(int\
    \ n_) {\n    n = 1;\n    height = 0;\n    while (n < n_) n <<= 1, height++;\n\
    \    dat.assign(2 * n, ti);\n    laz.assign(2 * n, ei);\n  }\n  void build(const\
    \ vector<T> &v) {\n    int n_ = v.size();\n    init(n_);\n    for (int i = 0;\
    \ i < n_; i++) dat[n + i] = v[i];\n    for (int i = n - 1; i; i--) {\n      dat[i].first\
    \ = dat[(i << 1) | 0].first + dat[(i << 1) | 1].first;\n      dat[i].second =\
    \ dat[(i << 1) | 0].second + dat[(i << 1) | 1].second;\n    }\n  }\n  inline T\
    \ reflect(int k) {\n    return laz[k] == ei\n               ? dat[k]\n       \
    \        : T{dat[k].first + laz[k] * dat[k].second, dat[k].second};\n  }\n  inline\
    \ void eval(int k) {\n    if (laz[k] == ei) return;\n    laz[(k << 1) | 0] +=\
    \ laz[k];\n    laz[(k << 1) | 1] += laz[k];\n    dat[k] = reflect(k);\n    laz[k]\
    \ = ei;\n  }\n  inline void thrust(int k) {\n    for (int i = height; i; i--)\
    \ eval(k >> i);\n  }\n  inline void recalc(int k) {\n    while (k >>= 1)\n   \
    \   dat[k].first = reflect((k << 1) | 0).first + reflect((k << 1) | 1).first;\n\
    \  }\n  void update(int a, int b, E x) {\n    thrust(a += n);\n    thrust(b +=\
    \ n - 1);\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) laz[l] += x, l++;\n      if (r & 1) --r, laz[r] += x;\n    }\n    recalc(a);\n\
    \    recalc(b);\n  }\n  void update(int a, E x) {\n    thrust(a += n);\n    laz[a]\
    \ += x;\n    recalc(a);\n  }\n\n  void set_val(int a, T x) {\n    thrust(a +=\
    \ n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n  }\n\n  E query(int\
    \ a, int b) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    E ret = ei;\n\
    \    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) ret\
    \ += reflect(l++).first;\n      if (r & 1) ret += reflect(--r).first;\n    }\n\
    \    return ret;\n  }\n\n  E query(int a) {\n    thrust(a += n);\n    return reflect(a).first;\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename E>\nstruct Range_Weighted_Add_Range_Sum_SegTree {\n  int\
    \ n, height;\n  T ti = {0, 0};\n  E ei = 0;\n  vector<T> dat;\n  vector<E> laz;\n\
    \  Range_Weighted_Add_Range_Sum_SegTree(const vector<T> &v) {\n    init((int)v.size());\n\
    \    build(v);\n  }\n\n  void init(int n_) {\n    n = 1;\n    height = 0;\n  \
    \  while (n < n_) n <<= 1, height++;\n    dat.assign(2 * n, ti);\n    laz.assign(2\
    \ * n, ei);\n  }\n  void build(const vector<T> &v) {\n    int n_ = v.size();\n\
    \    init(n_);\n    for (int i = 0; i < n_; i++) dat[n + i] = v[i];\n    for (int\
    \ i = n - 1; i; i--) {\n      dat[i].first = dat[(i << 1) | 0].first + dat[(i\
    \ << 1) | 1].first;\n      dat[i].second = dat[(i << 1) | 0].second + dat[(i <<\
    \ 1) | 1].second;\n    }\n  }\n  inline T reflect(int k) {\n    return laz[k]\
    \ == ei\n               ? dat[k]\n               : T{dat[k].first + laz[k] * dat[k].second,\
    \ dat[k].second};\n  }\n  inline void eval(int k) {\n    if (laz[k] == ei) return;\n\
    \    laz[(k << 1) | 0] += laz[k];\n    laz[(k << 1) | 1] += laz[k];\n    dat[k]\
    \ = reflect(k);\n    laz[k] = ei;\n  }\n  inline void thrust(int k) {\n    for\
    \ (int i = height; i; i--) eval(k >> i);\n  }\n  inline void recalc(int k) {\n\
    \    while (k >>= 1)\n      dat[k].first = reflect((k << 1) | 0).first + reflect((k\
    \ << 1) | 1).first;\n  }\n  void update(int a, int b, E x) {\n    thrust(a +=\
    \ n);\n    thrust(b += n - 1);\n    for (int l = a, r = b + 1; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) laz[l] += x, l++;\n      if (r & 1) --r, laz[r]\
    \ += x;\n    }\n    recalc(a);\n    recalc(b);\n  }\n  void update(int a, E x)\
    \ {\n    thrust(a += n);\n    laz[a] += x;\n    recalc(a);\n  }\n\n  void set_val(int\
    \ a, T x) {\n    thrust(a += n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n\
    \  }\n\n  E query(int a, int b) {\n    thrust(a += n);\n    thrust(b += n - 1);\n\
    \    E ret = ei;\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n\
    \      if (l & 1) ret += reflect(l++).first;\n      if (r & 1) ret += reflect(--r).first;\n\
    \    }\n    return ret;\n  }\n\n  E query(int a) {\n    thrust(a += n);\n    return\
    \ reflect(a).first;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/range-weighted-add-range-sum-lazyseg.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/range-weighted-add-range-sum-lazyseg.hpp
layout: document
redirect_from:
- /library/segment-tree/range-weighted-add-range-sum-lazyseg.hpp
- /library/segment-tree/range-weighted-add-range-sum-lazyseg.hpp.html
title: segment-tree/range-weighted-add-range-sum-lazyseg.hpp
---
