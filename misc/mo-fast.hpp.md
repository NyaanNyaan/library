---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo-fast.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \nstruct Fast_Mo {\n  int N, Q, width;\n  vector<int> L, R, order;\n  bool is_build;\n\
    \n  Fast_Mo(int _n, int _q) : N(_n), Q(_q), order(Q), is_build(false) {\n    width\
    \ = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q / 2.0)));\n    iota(begin(order),\
    \ end(order), 0);\n  }\n  // [l, r)\n  void insert(int l, int r) {\n    assert(0\
    \ <= l and l <= r and r <= N);\n    L.push_back(l), R.push_back(r);\n  }\n\n \
    \ void build() { sort(), climb(), is_build = true; }\n\n  template <typename AL,\
    \ typename AR, typename DL, typename DR, typename REM>\n  void run(const AL &add_left,\
    \ const AR &add_right, const DL &delete_left,\n           const DR &delete_right,\
    \ const REM &rem) {\n    if (!is_build) build();\n    int nl = 0, nr = 0;\n  \
    \  for (auto idx : order) {\n      while (nl > L[idx]) add_left(--nl);\n     \
    \ while (nr < R[idx]) add_right(nr++);\n      while (nl < L[idx]) delete_left(nl++);\n\
    \      while (nr > R[idx]) delete_right(--nr);\n      rem(idx);\n    }\n  }\n\n\
    \ private:\n  void sort() {\n    assert((int)order.size() == Q);\n    vector<int>\
    \ cnt(N + 1), buf(Q);\n    for (int i = 0; i < Q; i++) cnt[R[i]]++;\n    for (int\
    \ i = 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];\n    for (int i = 0;\
    \ i < Q; i++) buf[--cnt[R[i]]] = i;\n    vector<int> b(Q);\n    for (int i = 0;\
    \ i < Q; i++) b[i] = L[i] / width;\n    cnt.resize(N / width + 1);\n    fill(begin(cnt),\
    \ end(cnt), 0);\n    for (int i = 0; i < Q; i++) cnt[b[i]]++;\n    for (int i\
    \ = 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];\n    for (int i = 0; i\
    \ < Q; i++) order[--cnt[b[buf[i]]]] = buf[i];\n    for (int i = 0, j = 0; i <\
    \ Q; i = j) {\n      int bi = b[order[i]];\n      j = i + 1;\n      while (j !=\
    \ Q and bi == b[order[j]]) j++;\n      if (!(bi & 1)) reverse(begin(order) + i,\
    \ begin(order) + j);\n    }\n  }\n\n  int dist(int i, int j) { return abs(L[i]\
    \ - L[j]) + abs(R[i] - R[j]); }\n  \n  void climb(int iter = 3, int interval =\
    \ 5) {\n    vector<int> d(Q - 1);\n    for (int i = 0; i < Q - 1; i++) d[i] =\
    \ dist(order[i], order[i + 1]);\n    while (iter--) {\n      for (int i = 1; i\
    \ < Q; i++) {\n        int pre1 = d[i - 1];\n        int js = i + 1, je = min<int>(i\
    \ + interval, Q - 1);\n        for (int j = je - 1; j >= js; j--) {\n        \
    \  int pre2 = d[j];\n          int now1 = dist(order[i - 1], order[j]);\n    \
    \      int now2 = dist(order[i], order[j + 1]);\n          if (now1 + now2 < pre1\
    \ + pre2) {\n            reverse(begin(order) + i, begin(order) + j + 1);\n  \
    \          reverse(begin(d) + i, begin(d) + j);\n            d[i - 1] = pre1 =\
    \ now1;\n            d[j] = now2;\n          }\n        }\n      }\n    }\n  }\n\
    };\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\nusing namespace std;\n\nstruct Fast_Mo\
    \ {\n  int N, Q, width;\n  vector<int> L, R, order;\n  bool is_build;\n\n  Fast_Mo(int\
    \ _n, int _q) : N(_n), Q(_q), order(Q), is_build(false) {\n    width = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(Q / 2.0)));\n    iota(begin(order), end(order),\
    \ 0);\n  }\n  // [l, r)\n  void insert(int l, int r) {\n    assert(0 <= l and\
    \ l <= r and r <= N);\n    L.push_back(l), R.push_back(r);\n  }\n\n  void build()\
    \ { sort(), climb(), is_build = true; }\n\n  template <typename AL, typename AR,\
    \ typename DL, typename DR, typename REM>\n  void run(const AL &add_left, const\
    \ AR &add_right, const DL &delete_left,\n           const DR &delete_right, const\
    \ REM &rem) {\n    if (!is_build) build();\n    int nl = 0, nr = 0;\n    for (auto\
    \ idx : order) {\n      while (nl > L[idx]) add_left(--nl);\n      while (nr <\
    \ R[idx]) add_right(nr++);\n      while (nl < L[idx]) delete_left(nl++);\n   \
    \   while (nr > R[idx]) delete_right(--nr);\n      rem(idx);\n    }\n  }\n\n private:\n\
    \  void sort() {\n    assert((int)order.size() == Q);\n    vector<int> cnt(N +\
    \ 1), buf(Q);\n    for (int i = 0; i < Q; i++) cnt[R[i]]++;\n    for (int i =\
    \ 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];\n    for (int i = 0; i <\
    \ Q; i++) buf[--cnt[R[i]]] = i;\n    vector<int> b(Q);\n    for (int i = 0; i\
    \ < Q; i++) b[i] = L[i] / width;\n    cnt.resize(N / width + 1);\n    fill(begin(cnt),\
    \ end(cnt), 0);\n    for (int i = 0; i < Q; i++) cnt[b[i]]++;\n    for (int i\
    \ = 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];\n    for (int i = 0; i\
    \ < Q; i++) order[--cnt[b[buf[i]]]] = buf[i];\n    for (int i = 0, j = 0; i <\
    \ Q; i = j) {\n      int bi = b[order[i]];\n      j = i + 1;\n      while (j !=\
    \ Q and bi == b[order[j]]) j++;\n      if (!(bi & 1)) reverse(begin(order) + i,\
    \ begin(order) + j);\n    }\n  }\n\n  int dist(int i, int j) { return abs(L[i]\
    \ - L[j]) + abs(R[i] - R[j]); }\n  \n  void climb(int iter = 3, int interval =\
    \ 5) {\n    vector<int> d(Q - 1);\n    for (int i = 0; i < Q - 1; i++) d[i] =\
    \ dist(order[i], order[i + 1]);\n    while (iter--) {\n      for (int i = 1; i\
    \ < Q; i++) {\n        int pre1 = d[i - 1];\n        int js = i + 1, je = min<int>(i\
    \ + interval, Q - 1);\n        for (int j = je - 1; j >= js; j--) {\n        \
    \  int pre2 = d[j];\n          int now1 = dist(order[i - 1], order[j]);\n    \
    \      int now2 = dist(order[i], order[j + 1]);\n          if (now1 + now2 < pre1\
    \ + pre2) {\n            reverse(begin(order) + i, begin(order) + j + 1);\n  \
    \          reverse(begin(d) + i, begin(d) + j);\n            d[i - 1] = pre1 =\
    \ now1;\n            d[j] = now2;\n          }\n        }\n      }\n    }\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo-fast.hpp
  requiredBy: []
  timestamp: '2023-03-24 20:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
documentation_of: misc/mo-fast.hpp
layout: document
redirect_from:
- /library/misc/mo-fast.hpp
- /library/misc/mo-fast.hpp.html
title: misc/mo-fast.hpp
---
