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
    \ */\n#line 2 \"modulo/binomial.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306E MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\
    \u6295\u3052\u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\
    \u500D\u901F\u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\
    \u524D\u8A08\u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\
    \u5BFE\u7B56\u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T>\
    \ f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
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
  timestamp: '2023-05-22 22:29:25+09:00'
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
