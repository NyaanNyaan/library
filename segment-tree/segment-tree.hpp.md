---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/segment-tree-on-range-tree.hpp
    title: "\u9818\u57DF\u6728(Segment Tree)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
    title: verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T, typename F>\nstruct SegmentTree\
    \ {\n  int size;\n  vector<T> seg;\n  const F f;\n  const T I;\n\n  SegmentTree(F\
    \ f_, const T &I_) : size(0), f(f_), I(I_) {}\n\n  SegmentTree(int N, F f_, const\
    \ T &I_) : f(f_), I(I_) { init(N); }\n\n  SegmentTree(const vector<T> &v, F f,\
    \ T I) : f(f), I(I) {\n    init(v.size());\n    for (int i = 0; i < (int)v.size();\
    \ i++) {\n      seg[i + size] = v[i];\n    }\n    build();\n  }\n\n  void init(int\
    \ N) {\n    size = 1;\n    while (size < N) size <<= 1;\n    seg.assign(2 * size,\
    \ I);\n  }\n\n  void set(int k, T x) { seg[k + size] = x; }\n\n  void build()\
    \ {\n    for (int k = size - 1; k > 0; k--) {\n      seg[k] = f(seg[2 * k], seg[2\
    \ * k + 1]);\n    }\n  }\n\n  void update(int k, T x) {\n    k += size;\n    seg[k]\
    \ = x;\n    while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n\
    \    }\n  }\n\n  void add(int k, T x) {\n    k += size;\n    seg[k] += x;\n  \
    \  while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n \
    \ }\n\n  // query to [a, b)\n  T query(int a, int b) {\n    T L = I, R = I;\n\
    \    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L\
    \ = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b], R);\n    }\n    return f(L,\
    \ R);\n  }\n\n  T &operator[](const int &k) { return seg[k + size]; }\n\n  template\
    \ <typename C>\n  int find_subtree(int a, const C &check, T &M, bool type) {\n\
    \    while (a < size) {\n      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n      if (check(nxt))\n        a = 2 * a + type;\n      else\n\
    \        M = nxt, a = 2 * a + 1 - type;\n    }\n    return a - size;\n  }\n\n\
    \  template <typename C>\n  int find_first(int a, const C &check) {\n    T L =\
    \ I;\n    if (a <= 0) {\n      if (check(f(L, seg[1]))) return find_subtree(1,\
    \ check, L, false);\n      return -1;\n    }\n    int b = size;\n    for (a +=\
    \ size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) {\n        T nxt\
    \ = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a, check, L, false);\n\
    \        L = nxt;\n        ++a;\n      }\n    }\n    return -1;\n  }\n\n  template\
    \ <typename C>\n  int find_last(int b, const C &check) {\n    T R = I;\n    if\
    \ (b >= size) {\n      if (check(f(seg[1], R))) return find_subtree(1, check,\
    \ R, true);\n      return -1;\n    }\n    int a = size;\n    for (b += size; a\
    \ < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T nxt = f(seg[--b], R);\n\
    \        if (check(nxt)) return find_subtree(b, check, R, true);\n        R =\
    \ nxt;\n      }\n    }\n    return -1;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename F>\nstruct SegmentTree {\n  int size;\n  vector<T> seg;\n\
    \  const F f;\n  const T I;\n\n  SegmentTree(F f_, const T &I_) : size(0), f(f_),\
    \ I(I_) {}\n\n  SegmentTree(int N, F f_, const T &I_) : f(f_), I(I_) { init(N);\
    \ }\n\n  SegmentTree(const vector<T> &v, F f, T I) : f(f), I(I) {\n    init(v.size());\n\
    \    for (int i = 0; i < (int)v.size(); i++) {\n      seg[i + size] = v[i];\n\
    \    }\n    build();\n  }\n\n  void init(int N) {\n    size = 1;\n    while (size\
    \ < N) size <<= 1;\n    seg.assign(2 * size, I);\n  }\n\n  void set(int k, T x)\
    \ { seg[k + size] = x; }\n\n  void build() {\n    for (int k = size - 1; k > 0;\
    \ k--) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void\
    \ update(int k, T x) {\n    k += size;\n    seg[k] = x;\n    while (k >>= 1) {\n\
    \      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void add(int k,\
    \ T x) {\n    k += size;\n    seg[k] += x;\n    while (k >>= 1) {\n      seg[k]\
    \ = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  // query to [a, b)\n  T query(int\
    \ a, int b) {\n    T L = I, R = I;\n    for (a += size, b += size; a < b; a >>=\
    \ 1, b >>= 1) {\n      if (a & 1) L = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b],\
    \ R);\n    }\n    return f(L, R);\n  }\n\n  T &operator[](const int &k) { return\
    \ seg[k + size]; }\n\n  template <typename C>\n  int find_subtree(int a, const\
    \ C &check, T &M, bool type) {\n    while (a < size) {\n      T nxt = type ? f(seg[2\
    \ * a + type], M) : f(M, seg[2 * a + type]);\n      if (check(nxt))\n        a\
    \ = 2 * a + type;\n      else\n        M = nxt, a = 2 * a + 1 - type;\n    }\n\
    \    return a - size;\n  }\n\n  template <typename C>\n  int find_first(int a,\
    \ const C &check) {\n    T L = I;\n    if (a <= 0) {\n      if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n      return -1;\n    }\n    int b\
    \ = size;\n    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if\
    \ (a & 1) {\n        T nxt = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n        L = nxt;\n        ++a;\n      }\n    }\n    return\
    \ -1;\n  }\n\n  template <typename C>\n  int find_last(int b, const C &check)\
    \ {\n    T R = I;\n    if (b >= size) {\n      if (check(f(seg[1], R))) return\
    \ find_subtree(1, check, R, true);\n      return -1;\n    }\n    int a = size;\n\
    \    for (b += size; a < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T\
    \ nxt = f(seg[--b], R);\n        if (check(nxt)) return find_subtree(b, check,\
    \ R, true);\n        R = nxt;\n      }\n    }\n    return -1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy:
  - data-structure-2d/segment-tree-on-range-tree.hpp
  timestamp: '2020-09-27 16:45:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: segment-tree/segment-tree.hpp
---
