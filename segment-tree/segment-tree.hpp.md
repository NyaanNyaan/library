---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
    title: verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T, typename F>\nstruct SegmentTree\
    \ {\n  int size;\n  vector<T> seg;\n  const F func;\n  const T UNIT;\n\n  SegmentTree(int\
    \ N, F func, T UNIT) : func(func), UNIT(UNIT) {\n    size = 1;\n    while (size\
    \ < N) size <<= 1;\n    seg.assign(2 * size, UNIT);\n  }\n\n  SegmentTree(const\
    \ vector<T> &v, F func, T UNIT) : func(func), UNIT(UNIT) {\n    int N = (int)v.size();\n\
    \    size = 1;\n    while (size < N) size <<= 1;\n    seg.assign(2 * size, UNIT);\n\
    \    for (int i = 0; i < N; i++) {\n      seg[i + size] = v[i];\n    }\n    build();\n\
    \  }\n\n  void set(int k, T x) { seg[k + size] = x; }\n\n  void build() {\n  \
    \  for (int k = size - 1; k > 0; k--) {\n      seg[k] = func(seg[2 * k], seg[2\
    \ * k + 1]);\n    }\n  }\n\n  void update(int k, T x) {\n    k += size;\n    seg[k]\
    \ = x;\n    while (k >>= 1) {\n      seg[k] = func(seg[2 * k], seg[2 * k + 1]);\n\
    \    }\n  }\n\n  void add(int k, T x) {\n    k += size;\n    seg[k] += x;\n  \
    \  while (k >>= 1) {\n      seg[k] = func(seg[2 * k], seg[2 * k + 1]);\n    }\n\
    \  }\n\n  // query to [a, b)\n  T query(int a, int b) {\n    T L = UNIT, R = UNIT;\n\
    \    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L\
    \ = func(L, seg[a++]);\n      if (b & 1) R = func(seg[--b], R);\n    }\n    return\
    \ func(L, R);\n  }\n\n  T &operator[](const int &k) { return seg[k + size]; }\n\
    \n  template <typename C>\n  int find_subtree(int a, const C &check, T &M, bool\
    \ type) {\n    while (a < size) {\n      T nxt = type ? func(seg[2 * a + type],\
    \ M) : func(M, seg[2 * a + type]);\n      if (check(nxt))\n        a = 2 * a +\
    \ type;\n      else\n        M = nxt, a = 2 * a + 1 - type;\n    }\n    return\
    \ a - size;\n  }\n\n  template <typename C>\n  int find_first(int a, const C &check)\
    \ {\n    T L = UNIT;\n    if (a <= 0) {\n      if (check(func(L, seg[1]))) return\
    \ find_subtree(1, check, L, false);\n      return -1;\n    }\n    int b = size;\n\
    \    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) {\n\
    \        T nxt = func(L, seg[a]);\n        if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n        L = nxt;\n        ++a;\n      }\n    }\n    return\
    \ -1;\n  }\n\n  template <typename C>\n  int find_last(int b, const C &check)\
    \ {\n    T R = UNIT;\n    if (b >= size) {\n      if (check(func(seg[1], R)))\
    \ return find_subtree(1, check, R, true);\n      return -1;\n    }\n    int a\
    \ = size;\n    for (b += size; a < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n\
    \        T nxt = func(seg[--b], R);\n        if (check(nxt)) return find_subtree(b,\
    \ check, R, true);\n        R = nxt;\n      }\n    }\n    return -1;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename F>\nstruct SegmentTree {\n  int size;\n  vector<T> seg;\n\
    \  const F func;\n  const T UNIT;\n\n  SegmentTree(int N, F func, T UNIT) : func(func),\
    \ UNIT(UNIT) {\n    size = 1;\n    while (size < N) size <<= 1;\n    seg.assign(2\
    \ * size, UNIT);\n  }\n\n  SegmentTree(const vector<T> &v, F func, T UNIT) : func(func),\
    \ UNIT(UNIT) {\n    int N = (int)v.size();\n    size = 1;\n    while (size < N)\
    \ size <<= 1;\n    seg.assign(2 * size, UNIT);\n    for (int i = 0; i < N; i++)\
    \ {\n      seg[i + size] = v[i];\n    }\n    build();\n  }\n\n  void set(int k,\
    \ T x) { seg[k + size] = x; }\n\n  void build() {\n    for (int k = size - 1;\
    \ k > 0; k--) {\n      seg[k] = func(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\
    \n  void update(int k, T x) {\n    k += size;\n    seg[k] = x;\n    while (k >>=\
    \ 1) {\n      seg[k] = func(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void\
    \ add(int k, T x) {\n    k += size;\n    seg[k] += x;\n    while (k >>= 1) {\n\
    \      seg[k] = func(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  // query to\
    \ [a, b)\n  T query(int a, int b) {\n    T L = UNIT, R = UNIT;\n    for (a +=\
    \ size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = func(L, seg[a++]);\n\
    \      if (b & 1) R = func(seg[--b], R);\n    }\n    return func(L, R);\n  }\n\
    \n  T &operator[](const int &k) { return seg[k + size]; }\n\n  template <typename\
    \ C>\n  int find_subtree(int a, const C &check, T &M, bool type) {\n    while\
    \ (a < size) {\n      T nxt = type ? func(seg[2 * a + type], M) : func(M, seg[2\
    \ * a + type]);\n      if (check(nxt))\n        a = 2 * a + type;\n      else\n\
    \        M = nxt, a = 2 * a + 1 - type;\n    }\n    return a - size;\n  }\n\n\
    \  template <typename C>\n  int find_first(int a, const C &check) {\n    T L =\
    \ UNIT;\n    if (a <= 0) {\n      if (check(func(L, seg[1]))) return find_subtree(1,\
    \ check, L, false);\n      return -1;\n    }\n    int b = size;\n    for (a +=\
    \ size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) {\n        T nxt\
    \ = func(L, seg[a]);\n        if (check(nxt)) return find_subtree(a, check, L,\
    \ false);\n        L = nxt;\n        ++a;\n      }\n    }\n    return -1;\n  }\n\
    \n  template <typename C>\n  int find_last(int b, const C &check) {\n    T R =\
    \ UNIT;\n    if (b >= size) {\n      if (check(func(seg[1], R))) return find_subtree(1,\
    \ check, R, true);\n      return -1;\n    }\n    int a = size;\n    for (b +=\
    \ size; a < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T nxt = func(seg[--b],\
    \ R);\n        if (check(nxt)) return find_subtree(b, check, R, true);\n     \
    \   R = nxt;\n      }\n    }\n    return -1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/segment-tree.hpp
  requiredBy: []
  timestamp: '2020-08-03 00:31:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-b-segtree.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-a-segtree.test.cpp
  - verify/verify-yuki/yuki-0875-binary-search-on-segtree.test.cpp
documentation_of: segment-tree/segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree.hpp
- /library/segment-tree/segment-tree.hpp.html
title: segment-tree/segment-tree.hpp
---
