---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570\u306Eprefix sum\u306E\u591A\u70B9\u8A55\
      \u4FA1"
    links: []
  bundledCode: "#line 2 \"modulo/multipoint-binomial-sum.hpp\"\n\n#line 2 \"misc/mo.hpp\"\
    \n\nstruct Mo {\n  int width;\n  vector<int> left, right, order;\n\n  Mo(int N,\
    \ int Q) : order(Q) {\n    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q\
    \ * 2.0 / 3.0)));\n    iota(begin(order), end(order), 0);\n  }\n\n  void insert(int\
    \ l, int r) { /* [l, r) */\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
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
    \ */\n#line 2 \"modulo/binomial.hpp\"\n\ntemplate <typename T>\nstruct Binomial\
    \ {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int MAX = 0) : fac_(MAX + 10),\
    \ finv_(MAX + 10), inv_(MAX + 10) {\n    assert(T::get_mod() != 0);\n    MAX +=\
    \ 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX; i++)\
    \ fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n    for (int\
    \ i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for (int i\
    \ = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  void extend()\
    \ {\n    int n = fac_.size();\n    T fac = fac_.back() * n;\n    T inv = (-inv_[T::get_mod()\
    \ % n]) * (T::get_mod() / n);\n    T finv = finv_.back() * inv;\n    fac_.push_back(fac);\n\
    \    finv_.push_back(finv);\n    inv_.push_back(inv);\n  }\n\n  T fac(int i) {\n\
    \    if(i < 0) return T(0);\n    while (i >= (int)fac_.size()) extend();\n   \
    \ return fac_[i];\n  }\n\n  T finv(int i) {\n    if(i < 0) return T(0);\n    while\
    \ (i >= (int)finv_.size()) extend();\n    return finv_[i];\n  }\n\n  T inv(int\
    \ i) {\n    if(i < 0) return T(0);\n    while (i >= (int)inv_.size()) extend();\n\
    \    return inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 || n < r ||\
    \ r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n  T\
    \ C_naive(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n   \
    \ T ret = T(1);\n    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret\
    \ *= inv(i) * (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n\
    \ < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\
    \n  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 5 \"modulo/multipoint-binomial-sum.hpp\"\
    \n\ntemplate <typename mint>\nvector<mint> multipoint_binomial_sum(const vector<pair<int,\
    \ int>>& qs) {\n  int N = 2;\n  for (auto& p : qs) N = max(N, p.first);\n  Binomial<mint>\
    \ b(N + 1);\n  int Q = qs.size();\n  Mo mo(N, Q);\n  for (auto& p : qs) {\n  \
    \  assert(p.second <= p.first);\n    assert(p.first <= N);\n    mo.insert(p.second,\
    \ p.first);\n  }\n  vector<mint> ans(Q);\n  mint cur = 1;\n  int n = 0, m = 0;\n\
    \  auto al = [&](int) { cur -= b.C(n, m--); };\n  auto ar = [&](int) { cur +=\
    \ cur - b.C(n++, m); };\n  auto el = [&](int) { cur += b.C(n, ++m); };\n  auto\
    \ er = [&](int) { cur = (cur + b.C(--n, m)) * b.inv(2); };\n  auto q = [&](int\
    \ i) { ans[i] = cur; };\n  mo.run(al, ar, el, er, q);\n  return ans;\n}\n\n/**\n\
    \ * @brief \u4E8C\u9805\u4FC2\u6570\u306Eprefix sum\u306E\u591A\u70B9\u8A55\u4FA1\
    \n */\n"
  code: "#pragma once\n\n#include \"../misc/mo.hpp\"\n#include \"binomial.hpp\"\n\n\
    template <typename mint>\nvector<mint> multipoint_binomial_sum(const vector<pair<int,\
    \ int>>& qs) {\n  int N = 2;\n  for (auto& p : qs) N = max(N, p.first);\n  Binomial<mint>\
    \ b(N + 1);\n  int Q = qs.size();\n  Mo mo(N, Q);\n  for (auto& p : qs) {\n  \
    \  assert(p.second <= p.first);\n    assert(p.first <= N);\n    mo.insert(p.second,\
    \ p.first);\n  }\n  vector<mint> ans(Q);\n  mint cur = 1;\n  int n = 0, m = 0;\n\
    \  auto al = [&](int) { cur -= b.C(n, m--); };\n  auto ar = [&](int) { cur +=\
    \ cur - b.C(n++, m); };\n  auto el = [&](int) { cur += b.C(n, ++m); };\n  auto\
    \ er = [&](int) { cur = (cur + b.C(--n, m)) * b.inv(2); };\n  auto q = [&](int\
    \ i) { ans[i] = cur; };\n  mo.run(al, ar, el, er, q);\n  return ans;\n}\n\n/**\n\
    \ * @brief \u4E8C\u9805\u4FC2\u6570\u306Eprefix sum\u306E\u591A\u70B9\u8A55\u4FA1\
    \n */\n"
  dependsOn:
  - misc/mo.hpp
  - modulo/binomial.hpp
  isVerificationFile: false
  path: modulo/multipoint-binomial-sum.hpp
  requiredBy: []
  timestamp: '2021-03-26 19:14:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
documentation_of: modulo/multipoint-binomial-sum.hpp
layout: document
redirect_from:
- /library/modulo/multipoint-binomial-sum.hpp
- /library/modulo/multipoint-binomial-sum.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570\u306Eprefix sum\u306E\u591A\u70B9\u8A55\u4FA1"
---
