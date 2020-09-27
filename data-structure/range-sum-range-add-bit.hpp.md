---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: data-structure/binary-indexed-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/range-sum-range-add-bit.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\nusing\
    \ namespace std;\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  int N;\n\
    \  vector<T> data;\n\n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int\
    \ size) { init(size); }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N\
    \ + 1, 0);\n  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k <\
    \ 0) return 0;  // return 0 if k < 0\n    T ret = 0;\n    for (++k; k > 0; k -=\
    \ k & -k) ret += data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline\
    \ T sum(int l, int r) const { return sum(r) - sum(l - 1); }\n\n  // get value\
    \ of k\n  inline T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n\
    \  // data[k] += x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k)\
    \ data[k] += x;\n  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T\
    \ x) {\n    add(l, x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i)\
    \ >= w\n  int lower_bound(T w) {\n    if (w <= 0) return 0;\n    int x = 0;\n\
    \    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N - 1 && data[x\
    \ + k] < w) {\n        w -= data[x + k];\n        x += k;\n      }\n    }\n  \
    \  return x;\n  }\n\n  // minimize i s.t. sum(i) > w\n  int upper_bound(T w) {\n\
    \    if (w < 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k; k\
    \ >>= 1) {\n      if (x + k <= N - 1 && data[x + k] <= w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n};\n#line 6 \"data-structure/range-sum-range-add-bit.hpp\"\
    \n\ntemplate <typename T>\nstruct RangeAddRangeSumBIT {\n  BinaryIndexedTree<T>\
    \ a, b;\n  RangeAddRangeSumBIT(int N) : a(N + 1), b(N + 1) {}\n\n  // add x to\
    \ [l, r)\n  void add(int l, int r, T x) {\n    a.add(l, x);\n    a.add(r, -x);\n\
    \    b.add(l, x * (1 - l));\n    b.add(r, x * (r - 1));\n  }\n\n  // return sum\
    \ of [l, r)\n  T sum(T l, T r) {\n    --r, --l;\n    return a.sum(r) * r + b.sum(r)\
    \ - a.sum(l) * l - b.sum(l);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"binary-indexed-tree.hpp\"\n\ntemplate <typename T>\nstruct RangeAddRangeSumBIT\
    \ {\n  BinaryIndexedTree<T> a, b;\n  RangeAddRangeSumBIT(int N) : a(N + 1), b(N\
    \ + 1) {}\n\n  // add x to [l, r)\n  void add(int l, int r, T x) {\n    a.add(l,\
    \ x);\n    a.add(r, -x);\n    b.add(l, x * (1 - l));\n    b.add(r, x * (r - 1));\n\
    \  }\n\n  // return sum of [l, r)\n  T sum(T l, T r) {\n    --r, --l;\n    return\
    \ a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);\n  }\n};"
  dependsOn:
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: false
  path: data-structure/range-sum-range-add-bit.hpp
  requiredBy: []
  timestamp: '2020-09-27 19:18:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
documentation_of: data-structure/range-sum-range-add-bit.hpp
layout: document
redirect_from:
- /library/data-structure/range-sum-range-add-bit.hpp
- /library/data-structure/range-sum-range-add-bit.hpp.html
title: data-structure/range-sum-range-add-bit.hpp
---
