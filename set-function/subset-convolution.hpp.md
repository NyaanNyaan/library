---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/set-function/subset-convolution.md
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"set-function/subset-convolution.hpp\"\n\ntemplate <typename\
    \ mint, int _s>\nstruct SubsetConvolution {\n  using fps = array<mint, _s + 1>;\n\
    \  static constexpr int s = _s;\n  vector<int> pc;\n\n  SubsetConvolution() :\
    \ pc(1 << s) {\n    for (int i = 1; i < (1 << s); i++) pc[i] = pc[i - (i & -i)]\
    \ + 1;\n  }\n\n  void add(fps& l, const fps& r, int d) {\n    for (int i = 0;\
    \ i < d; ++i) l[i] += r[i];\n  }\n\n  void sub(fps& l, const fps& r, int d) {\n\
    \    for (int i = d; i <= s; ++i) l[i] -= r[i];\n  }\n\n  void zeta(vector<fps>&\
    \ a) {\n    int n = a.size();\n    for (int w = 1; w < n; w *= 2) {\n      for\
    \ (int k = 0; k < n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n  \
    \        add(a[k + w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n   \
    \ }\n  }\n\n  void mobius(vector<fps>& a) {\n    int n = a.size();\n    for (int\
    \ w = n >> 1; w; w >>= 1) {\n      for (int k = 0; k < n; k += w * 2) {\n    \
    \    for (int i = 0; i < w; ++i) {\n          sub(a[k + w + i], a[k + i], pc[k\
    \ + w + i]);\n        }\n      }\n    }\n  }\n\n  vector<fps> lift(const vector<mint>&\
    \ a) {\n    vector<fps> A(a.size());\n    for (int i = 0; i < (int)a.size(); i++)\
    \ {\n      fill(begin(A[i]), end(A[i]), mint());\n      A[i][pc[i]] = a[i];\n\
    \    }\n    return A;\n  }\n\n  vector<mint> unlift(const vector<fps>& A) {\n\
    \    vector<mint> a(A.size());\n    for (int i = 0; i < (int)A.size(); i++) a[i]\
    \ = A[i][pc[i]];\n    return a;\n  }\n\n  void prod(vector<fps>& A, const vector<fps>&\
    \ B) {\n    int n = A.size(), d = __builtin_ctz(n);\n    for (int i = 0; i < n;\
    \ i++) {\n      fps c{};\n      for (int j = 0; j <= d; j++) {\n        for (int\
    \ k = 0; k <= d - j; k++) {\n          c[j + k] += A[i][j] * B[i][k];\n      \
    \  }\n      }\n      A[i].swap(c);\n    }\n  }\n\n  vector<mint> multiply(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    vector<fps> A = lift(a), B =\
    \ lift(b);\n    zeta(A), zeta(B);\n    prod(A, B);\n    mobius(A);\n    return\
    \ unlift(A);\n  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs docs/set-function/subset-convolution.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename mint, int _s>\nstruct SubsetConvolution\
    \ {\n  using fps = array<mint, _s + 1>;\n  static constexpr int s = _s;\n  vector<int>\
    \ pc;\n\n  SubsetConvolution() : pc(1 << s) {\n    for (int i = 1; i < (1 << s);\
    \ i++) pc[i] = pc[i - (i & -i)] + 1;\n  }\n\n  void add(fps& l, const fps& r,\
    \ int d) {\n    for (int i = 0; i < d; ++i) l[i] += r[i];\n  }\n\n  void sub(fps&\
    \ l, const fps& r, int d) {\n    for (int i = d; i <= s; ++i) l[i] -= r[i];\n\
    \  }\n\n  void zeta(vector<fps>& a) {\n    int n = a.size();\n    for (int w =\
    \ 1; w < n; w *= 2) {\n      for (int k = 0; k < n; k += w * 2) {\n        for\
    \ (int i = 0; i < w; ++i) {\n          add(a[k + w + i], a[k + i], pc[k + w +\
    \ i]);\n        }\n      }\n    }\n  }\n\n  void mobius(vector<fps>& a) {\n  \
    \  int n = a.size();\n    for (int w = n >> 1; w; w >>= 1) {\n      for (int k\
    \ = 0; k < n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n         \
    \ sub(a[k + w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n    }\n  }\n\
    \n  vector<fps> lift(const vector<mint>& a) {\n    vector<fps> A(a.size());\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n      fill(begin(A[i]), end(A[i]),\
    \ mint());\n      A[i][pc[i]] = a[i];\n    }\n    return A;\n  }\n\n  vector<mint>\
    \ unlift(const vector<fps>& A) {\n    vector<mint> a(A.size());\n    for (int\
    \ i = 0; i < (int)A.size(); i++) a[i] = A[i][pc[i]];\n    return a;\n  }\n\n \
    \ void prod(vector<fps>& A, const vector<fps>& B) {\n    int n = A.size(), d =\
    \ __builtin_ctz(n);\n    for (int i = 0; i < n; i++) {\n      fps c{};\n     \
    \ for (int j = 0; j <= d; j++) {\n        for (int k = 0; k <= d - j; k++) {\n\
    \          c[j + k] += A[i][j] * B[i][k];\n        }\n      }\n      A[i].swap(c);\n\
    \    }\n  }\n\n  vector<mint> multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n    vector<fps> A = lift(a), B = lift(b);\n    zeta(A), zeta(B);\n   \
    \ prod(A, B);\n    mobius(A);\n    return unlift(A);\n  }\n};\n\n/**\n * @brief\
    \ Subset Convolution\n * @docs docs/set-function/subset-convolution.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/subset-convolution.hpp
  requiredBy: []
  timestamp: '2021-03-06 19:10:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
documentation_of: set-function/subset-convolution.hpp
layout: document
redirect_from:
- /library/set-function/subset-convolution.hpp
- /library/set-function/subset-convolution.hpp.html
title: Subset Convolution
---

## Subset Convolution

$n$要素の集合の部分集合$S$に対する関数$f(S),g(S)$に対して、

$$(f \circ g)(S) = \sum_{T \subseteq S}f(T)g(S\setminus T)$$

を$\mathrm{O}(2^N N^2)$で計算するライブラリ。

#### 概要

[指数時間アルゴリズム](https://www.slideshare.net/wata_orz/ss-12131479)の包除定理の項目を参考にした。

関数$f$に対して、要素$n$が入っていない集合を定義域とする関数を$f_1$、
入っている集合を定義域とする関数を$f_2$とおく。(厳密に書くと、

$$f_1(S) = f(S),\ f_2(S) = f(S \cap \lbrace n\rbrace) \ \ \ (S\subset\lbrace1,2,\ldots n-1\rbrace)$$

となる。)この時、

$$ (f\circ g)_1 = f_1 \circ g_1$$

$$ (f\circ g)_2 = f_1 \circ g_2 + f_2 \circ g_1$$

となり、これを愚直に計算すると、$2^n$要素の畳み込みが$2^{n-1}$要素の畳み込み$3$回で計算できるので$\mathrm{O}(3^N)$となる。

高速化のために多項式を導入する。関数の加法やスカラー倍を$(f+g)(S)=f(S)+g(S),(f\cdot x)(S)=f(S)x$のように定義すると、

$$(f\circ g)_2\cdot x\equiv (f_1+f_2\cdot x)\circ(g_1+g_2\cdot x)-f_1\circ g_1 \mod x^2$$

となり、$f\circ g$が$2^{n-1}$サイズの畳み込み$2$回を用いて再帰的に計算できるようになる。再帰の末尾で次数$n$の多項式乗算$2^n$回が必要になるため計算量は$T(n)=2T(n-1)+\mathrm{O}(n^2 2^n)$を解いて$\mathrm{O}(2^N N^2)$となる。
