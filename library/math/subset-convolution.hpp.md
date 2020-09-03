---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Subset Convolution <small>(math/subset-convolution.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/subset-convolution.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 01:02:15+09:00





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


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp.html">verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
vector<mint> subset_convolution(const vector<mint>& a, const vector<mint>& b) {
  int N = a.size();
  assert(a.size() == b.size() && (N & (N - 1)) == 0);
  int l = __builtin_ctz(N);

  auto conv = [&](vector<mint>& a, vector<mint>& b) -> void {
    for (int k = l; k >= 0; --k) {
      mint n = mint(0);
      for (int i = 0; i <= k; ++i) n += a[i] * b[k - i];
      a[k] = n;
    }
  };

  vector<vector<mint>> A(N, vector<mint>(l + 1)), B(N, vector<mint>(l + 1));
  for (int i = 0; i < N; i++) A[i][0] = a[i], B[i][0] = b[i];
  vector<mint> buf(l + 1);

  for (int n = N / 2, d = 1; n; n >>= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] = A[j] + A[j + n] * x
        buf[0] = A[j][0];
        for (int k = 1; k <= d; k++) buf[k] = A[j][k] + A[j + n][k - 1];
        copy(begin(buf), end(buf), begin(A[j + n]));
        buf[0] = B[j][0];
        for (int k = 1; k <= d; k++) buf[k] = B[j][k] + B[j + n][k - 1];
        copy(begin(buf), end(buf), begin(B[j + n]));
      }
    }
  }

  for (int i = 0; i < N; i++) conv(A[i], B[i]);
  
  for (int n = 1, d = 0; n < N; n <<= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] -= A[j]
        for (int k = d; k <= l; k++) A[j + n][k] -= A[j][k];
        // A[j] *= x
        for (int k = l; k > d; --k) A[j][k] = A[j][k - 1];
        A[j][0] = mint(0);
      }
    }
  }

  vector<mint> C(N);
  for (int i = 0; i < N; i++) C[i] = A[i][l];
  return C;
}

/**
 * @brief Subset Convolution
 * @docs docs/math/subset-convolution.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/subset-convolution.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
vector<mint> subset_convolution(const vector<mint>& a, const vector<mint>& b) {
  int N = a.size();
  assert(a.size() == b.size() && (N & (N - 1)) == 0);
  int l = __builtin_ctz(N);

  auto conv = [&](vector<mint>& a, vector<mint>& b) -> void {
    for (int k = l; k >= 0; --k) {
      mint n = mint(0);
      for (int i = 0; i <= k; ++i) n += a[i] * b[k - i];
      a[k] = n;
    }
  };

  vector<vector<mint>> A(N, vector<mint>(l + 1)), B(N, vector<mint>(l + 1));
  for (int i = 0; i < N; i++) A[i][0] = a[i], B[i][0] = b[i];
  vector<mint> buf(l + 1);

  for (int n = N / 2, d = 1; n; n >>= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] = A[j] + A[j + n] * x
        buf[0] = A[j][0];
        for (int k = 1; k <= d; k++) buf[k] = A[j][k] + A[j + n][k - 1];
        copy(begin(buf), end(buf), begin(A[j + n]));
        buf[0] = B[j][0];
        for (int k = 1; k <= d; k++) buf[k] = B[j][k] + B[j + n][k - 1];
        copy(begin(buf), end(buf), begin(B[j + n]));
      }
    }
  }

  for (int i = 0; i < N; i++) conv(A[i], B[i]);
  
  for (int n = 1, d = 0; n < N; n <<= 1, ++d) {
    for (int i = 0; i < N; i += 2 * n) {
      for (int j = i; j < i + n; j++) {
        // A[j + n] -= A[j]
        for (int k = d; k <= l; k++) A[j + n][k] -= A[j][k];
        // A[j] *= x
        for (int k = l; k > d; --k) A[j][k] = A[j][k - 1];
        A[j][0] = mint(0);
      }
    }
  }

  vector<mint> C(N);
  for (int i = 0; i < N; i++) C[i] = A[i][l];
  return C;
}

/**
 * @brief Subset Convolution
 * @docs docs/math/subset-convolution.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

