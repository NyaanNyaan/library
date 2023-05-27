---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set-function/subset-convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
    title: verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E exp"
    links: []
  bundledCode: "#line 2 \"set-function/exp-of-set-power-series.hpp\"\n\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"set-function/subset-convolution.hpp\"\
    \n\n#include <array>\n#line 5 \"set-function/subset-convolution.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename mint, int _s>\nstruct SubsetConvolution {\n  using\
    \ fps = array<mint, _s + 1>;\n  static constexpr int s = _s;\n  vector<int> pc;\n\
    \n  SubsetConvolution() : pc(1 << s) {\n    for (int i = 1; i < (1 << s); i++)\
    \ pc[i] = pc[i - (i & -i)] + 1;\n  }\n\n  void add(fps& l, const fps& r, int d)\
    \ {\n    for (int i = 0; i < d; ++i) l[i] += r[i];\n  }\n\n  void sub(fps& l,\
    \ const fps& r, int d) {\n    for (int i = d; i <= s; ++i) l[i] -= r[i];\n  }\n\
    \n  void zeta(vector<fps>& a) {\n    int n = a.size();\n    for (int w = 1; w\
    \ < n; w *= 2) {\n      for (int k = 0; k < n; k += w * 2) {\n        for (int\
    \ i = 0; i < w; ++i) {\n          add(a[k + w + i], a[k + i], pc[k + w + i]);\n\
    \        }\n      }\n    }\n  }\n\n  void mobius(vector<fps>& a) {\n    int n\
    \ = a.size();\n    for (int w = n >> 1; w; w >>= 1) {\n      for (int k = 0; k\
    \ < n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n          sub(a[k\
    \ + w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n    }\n  }\n\n  vector<fps>\
    \ lift(const vector<mint>& a) {\n    vector<fps> A(a.size());\n    for (int i\
    \ = 0; i < (int)a.size(); i++) {\n      fill(begin(A[i]), end(A[i]), mint());\n\
    \      A[i][pc[i]] = a[i];\n    }\n    return A;\n  }\n\n  vector<mint> unlift(const\
    \ vector<fps>& A) {\n    vector<mint> a(A.size());\n    for (int i = 0; i < (int)A.size();\
    \ i++) a[i] = A[i][pc[i]];\n    return a;\n  }\n\n  void prod(vector<fps>& A,\
    \ const vector<fps>& B) {\n    int n = A.size(), d = __builtin_ctz(n);\n    for\
    \ (int i = 0; i < n; i++) {\n      fps c{};\n      for (int j = 0; j <= d; j++)\
    \ {\n        for (int k = 0; k <= d - j; k++) {\n          c[j + k] += A[i][j]\
    \ * B[i][k];\n        }\n      }\n      A[i].swap(c);\n    }\n  }\n\n  vector<mint>\
    \ multiply(const vector<mint>& a, const vector<mint>& b) {\n    vector<fps> A\
    \ = lift(a), B = lift(b);\n    zeta(A), zeta(B);\n    prod(A, B);\n    mobius(A);\n\
    \    return unlift(A);\n  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs\
    \ docs/set-function/subset-convolution.md\n */\n#line 8 \"set-function/exp-of-set-power-series.hpp\"\
    \n\ntemplate <typename mint, int MAX = 21>\nvector<mint> exp_of_set_power_series(int\
    \ n, vector<mint> g) {\n  assert(0 <= n && n <= MAX);\n  static SubsetConvolution<mint,\
    \ MAX> ss;\n  g.resize(1 << n);\n  assert(g[0] == 0);\n\n  vector<mint> h{1};\n\
    \  for (int k = 1; k <= n; k++) {\n    auto a = ss.multiply(h, {begin(g) + (1\
    \ << (k - 1)), begin(g) + (1 << k)});\n    copy(begin(a), end(a), back_inserter(h));\n\
    \  }\n  return h;\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E exp\n\
    \ */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \n#include \"subset-convolution.hpp\"\n\ntemplate <typename mint, int MAX = 21>\n\
    vector<mint> exp_of_set_power_series(int n, vector<mint> g) {\n  assert(0 <= n\
    \ && n <= MAX);\n  static SubsetConvolution<mint, MAX> ss;\n  g.resize(1 << n);\n\
    \  assert(g[0] == 0);\n\n  vector<mint> h{1};\n  for (int k = 1; k <= n; k++)\
    \ {\n    auto a = ss.multiply(h, {begin(g) + (1 << (k - 1)), begin(g) + (1 <<\
    \ k)});\n    copy(begin(a), end(a), back_inserter(h));\n  }\n  return h;\n}\n\n\
    /**\n * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E exp\n */\n"
  dependsOn:
  - set-function/subset-convolution.hpp
  isVerificationFile: false
  path: set-function/exp-of-set-power-series.hpp
  requiredBy: []
  timestamp: '2023-05-27 23:17:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
documentation_of: set-function/exp-of-set-power-series.hpp
layout: document
redirect_from:
- /library/set-function/exp-of-set-power-series.hpp
- /library/set-function/exp-of-set-power-series.hpp.html
title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E exp"
---
