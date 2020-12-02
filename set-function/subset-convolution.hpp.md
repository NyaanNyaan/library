---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/set-function/subset-convolution.md
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"set-function/subset-convolution.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename mint>\nvector<mint> subset_convolution(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int N = a.size();\n  assert(a.size()\
    \ == b.size() && (N & (N - 1)) == 0);\n  int l = __builtin_ctz(N);\n\n  auto conv\
    \ = [&](vector<mint>& a, vector<mint>& b) -> void {\n    for (int k = l; k >=\
    \ 0; --k) {\n      mint n = mint(0);\n      for (int i = 0; i <= k; ++i) n +=\
    \ a[i] * b[k - i];\n      a[k] = n;\n    }\n  };\n\n  vector<vector<mint>> A(N,\
    \ vector<mint>(l + 1)), B(N, vector<mint>(l + 1));\n  for (int i = 0; i < N; i++)\
    \ A[i][0] = a[i], B[i][0] = b[i];\n  vector<mint> buf(l + 1);\n\n  for (int n\
    \ = N / 2, d = 1; n; n >>= 1, ++d) {\n    for (int i = 0; i < N; i += 2 * n) {\n\
    \      for (int j = i; j < i + n; j++) {\n        // A[j + n] = A[j] + A[j + n]\
    \ * x\n        buf[0] = A[j][0];\n        for (int k = 1; k <= d; k++) buf[k]\
    \ = A[j][k] + A[j + n][k - 1];\n        copy(begin(buf), end(buf), begin(A[j +\
    \ n]));\n        buf[0] = B[j][0];\n        for (int k = 1; k <= d; k++) buf[k]\
    \ = B[j][k] + B[j + n][k - 1];\n        copy(begin(buf), end(buf), begin(B[j +\
    \ n]));\n      }\n    }\n  }\n\n  for (int i = 0; i < N; i++) conv(A[i], B[i]);\n\
    \  \n  for (int n = 1, d = 0; n < N; n <<= 1, ++d) {\n    for (int i = 0; i <\
    \ N; i += 2 * n) {\n      for (int j = i; j < i + n; j++) {\n        // A[j +\
    \ n] -= A[j]\n        for (int k = d; k <= l; k++) A[j + n][k] -= A[j][k];\n \
    \       // A[j] *= x\n        for (int k = l; k > d; --k) A[j][k] = A[j][k - 1];\n\
    \        A[j][0] = mint(0);\n      }\n    }\n  }\n\n  vector<mint> C(N);\n  for\
    \ (int i = 0; i < N; i++) C[i] = A[i][l];\n  return C;\n}\n\n/**\n * @brief Subset\
    \ Convolution\n * @docs docs/set-function/subset-convolution.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename mint>\nvector<mint> subset_convolution(const vector<mint>& a, const\
    \ vector<mint>& b) {\n  int N = a.size();\n  assert(a.size() == b.size() && (N\
    \ & (N - 1)) == 0);\n  int l = __builtin_ctz(N);\n\n  auto conv = [&](vector<mint>&\
    \ a, vector<mint>& b) -> void {\n    for (int k = l; k >= 0; --k) {\n      mint\
    \ n = mint(0);\n      for (int i = 0; i <= k; ++i) n += a[i] * b[k - i];\n   \
    \   a[k] = n;\n    }\n  };\n\n  vector<vector<mint>> A(N, vector<mint>(l + 1)),\
    \ B(N, vector<mint>(l + 1));\n  for (int i = 0; i < N; i++) A[i][0] = a[i], B[i][0]\
    \ = b[i];\n  vector<mint> buf(l + 1);\n\n  for (int n = N / 2, d = 1; n; n >>=\
    \ 1, ++d) {\n    for (int i = 0; i < N; i += 2 * n) {\n      for (int j = i; j\
    \ < i + n; j++) {\n        // A[j + n] = A[j] + A[j + n] * x\n        buf[0] =\
    \ A[j][0];\n        for (int k = 1; k <= d; k++) buf[k] = A[j][k] + A[j + n][k\
    \ - 1];\n        copy(begin(buf), end(buf), begin(A[j + n]));\n        buf[0]\
    \ = B[j][0];\n        for (int k = 1; k <= d; k++) buf[k] = B[j][k] + B[j + n][k\
    \ - 1];\n        copy(begin(buf), end(buf), begin(B[j + n]));\n      }\n    }\n\
    \  }\n\n  for (int i = 0; i < N; i++) conv(A[i], B[i]);\n  \n  for (int n = 1,\
    \ d = 0; n < N; n <<= 1, ++d) {\n    for (int i = 0; i < N; i += 2 * n) {\n  \
    \    for (int j = i; j < i + n; j++) {\n        // A[j + n] -= A[j]\n        for\
    \ (int k = d; k <= l; k++) A[j + n][k] -= A[j][k];\n        // A[j] *= x\n   \
    \     for (int k = l; k > d; --k) A[j][k] = A[j][k - 1];\n        A[j][0] = mint(0);\n\
    \      }\n    }\n  }\n\n  vector<mint> C(N);\n  for (int i = 0; i < N; i++) C[i]\
    \ = A[i][l];\n  return C;\n}\n\n/**\n * @brief Subset Convolution\n * @docs docs/set-function/subset-convolution.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/subset-convolution.hpp
  requiredBy: []
  timestamp: '2020-12-02 11:16:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
