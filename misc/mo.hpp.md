---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modulo/multipoint-binomial-sum.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306Eprefix sum\u306E\u591A\u70B9\u8A55\u4FA1"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/misc/mo.md
    document_title: Mo's algorithm
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\nstruct Mo {\n  int width;\n  vector<int>\
    \ left, right, order;\n\n  Mo(int N, int Q) : order(Q) {\n    width = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n    iota(begin(order), end(order),\
    \ 0);\n  }\n\n  void insert(int l, int r) { /* [l, r) */\n    left.emplace_back(l);\n\
    \    right.emplace_back(r);\n  }\n\n  template <typename AL, typename AR, typename\
    \ DL, typename DR, typename REM>\n  void run(const AL &add_left, const AR &add_right,\
    \ const DL &delete_left,\n           const DR &delete_right, const REM &rem) {\n\
    \    assert(left.size() == order.size());\n    sort(begin(order), end(order),\
    \ [&](int a, int b) {\n      int ablock = left[a] / width, bblock = left[b] /\
    \ width;\n      if (ablock != bblock) return ablock < bblock;\n      if (ablock\
    \ & 1) return right[a] < right[b];\n      return right[a] > right[b];\n    });\n\
    \    int nl = 0, nr = 0;\n    for (auto idx : order) {\n      while (nl > left[idx])\
    \ add_left(--nl);\n      while (nr < right[idx]) add_right(nr++);\n      while\
    \ (nl < left[idx]) delete_left(nl++);\n      while (nr > right[idx]) delete_right(--nr);\n\
    \      rem(idx);\n    }\n  }\n};\n\n/**\n * @brief Mo's algorithm\n * @docs docs/misc/mo.md\n\
    \ */\n"
  code: "#pragma once\n\nstruct Mo {\n  int width;\n  vector<int> left, right, order;\n\
    \n  Mo(int N, int Q) : order(Q) {\n    width = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(Q * 2.0 / 3.0)));\n    iota(begin(order), end(order), 0);\n  }\n\n  void\
    \ insert(int l, int r) { /* [l, r) */\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
    \  }\n\n  template <typename AL, typename AR, typename DL, typename DR, typename\
    \ REM>\n  void run(const AL &add_left, const AR &add_right, const DL &delete_left,\n\
    \           const DR &delete_right, const REM &rem) {\n    assert(left.size()\
    \ == order.size());\n    sort(begin(order), end(order), [&](int a, int b) {\n\
    \      int ablock = left[a] / width, bblock = left[b] / width;\n      if (ablock\
    \ != bblock) return ablock < bblock;\n      if (ablock & 1) return right[a] <\
    \ right[b];\n      return right[a] > right[b];\n    });\n    int nl = 0, nr =\
    \ 0;\n    for (auto idx : order) {\n      while (nl > left[idx]) add_left(--nl);\n\
    \      while (nr < right[idx]) add_right(nr++);\n      while (nl < left[idx])\
    \ delete_left(nl++);\n      while (nr > right[idx]) delete_right(--nr);\n    \
    \  rem(idx);\n    }\n  }\n};\n\n/**\n * @brief Mo's algorithm\n * @docs docs/misc/mo.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy:
  - modulo/multipoint-binomial-sum.hpp
  timestamp: '2021-03-26 19:14:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
documentation_of: misc/mo.hpp
layout: document
redirect_from:
- /library/misc/mo.hpp
- /library/misc/mo.hpp.html
title: Mo's algorithm
---
## Mo's algorithm

$[0,N)$上の区間に対する$Q$個のクエリを$\mathrm{O}(\alpha N \sqrt{Q})$で計算するライブラリ。(ただし区間の幅を$1$変化させる伸縮が$\mathrm{O}(\alpha)$で行えるとする。)

#### 概要

アルゴリズムは[snukeさんのブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)が詳しい。

考察ミスしていて定数倍を大きく悪くしていたので、反省を込めて定数倍について考察したものを簡単に記しておく。

区間の伸縮の計算量が(定数倍込みで)等しい時、アルゴリズムの実行時間は伸縮の回数に依存するので、伸縮の回数を最小化すれば実行時間が高速になると考えられる。そこで、ランダムなクエリに対して区間の伸縮回数を最小化する区間の分割幅$W$の値を考察する。左端と右端が動く回数は、

- 左端：1回あたり区間$[0,W]$上のランダムな$2$点の距離と等しいので$\frac{W}{3} \times Q$回
- 右端：$i$番目の区間を処理するとき$N - Wi$個動くので$\sum_{i \leq \frac{N}{W}} N-Wi = \frac{N^2}{2W}+\mathrm{O}(\frac{N}{W})$

であるので、$\frac{N^2}{2W} + \frac{WQ}{3}$が最小になる$W$を選べばよく、AM-BMより$W=\frac{\sqrt{3}N}{\sqrt{2Q}}$を得る。

(修正前のライブラリはうっかり$W=\frac{\sqrt{3}N}{\sqrt{Q}}$にしていたがこれだと定数倍が$3$倍ほど悪いようだ。これはひどい…)