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


# :heavy_check_mark: Nim Product <small>(math/nim-product.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/nim-product.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:36:21+09:00




## Nim Product

$$a \oplus b =\mathrm{mex}(\lbrace a' \oplus b \mid a'<a \rbrace\cup\lbrace a \oplus b' \mid b'<b \rbrace)$$

$$a \otimes b =\mathrm{mex}(\lbrace a' \otimes b \oplus a \otimes b' \oplus a' \otimes b' \mid a'<a,b'<b \rbrace)$$

と置いたとき、$a\otimes b\ (a,b<2^{64})$を高速に計算するライブラリ。

[Wikipedia](https://en.wikipedia.org/wiki/Nimber)　[kyopro_friendsさんによる資料](https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit)

#### 使い方

- `nim_product(a, b)` ： $a\otimes b$を返す関数。


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-nim-product.test.cpp.html">verify/verify-yosupo-math/yosupo-nim-product.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace nimber {
using u64 = uint64_t;

u64 calc(u64, u64, int p, int pre);

struct Precalc {
  u64 dp[256][256];
  Precalc() {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[j][i] = calc(i, j, 8, true);
      }
  }

} precalc;

u64 calc(u64 a, u64 b, int p = 64, int pre = false) {
  if (min(a, b) <= 1) return a * b;
  while (max(a, b) < 1ull << (p >> 1)) p >>= 1;
  if (!pre && p <= 8) return precalc.dp[a][b];
  p >>= 1;
  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);
  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);
  u64 c = calc(a1, b1, p, pre);
  u64 d = calc(a2, b2, p, pre);
  u64 e = calc(a1 ^ a2, b1 ^ b2, p, pre);
  return calc(c, 1ull << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);
}

u64 nim_product(u64 a, u64 b) { return calc(a, b); }

}  // namespace nimber
using nimber::nim_product;

/**
 * @brief Nim Product
 * @docs docs/math/nim-product.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/nim-product.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace nimber {
using u64 = uint64_t;

u64 calc(u64, u64, int p, int pre);

struct Precalc {
  u64 dp[256][256];
  Precalc() {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[j][i] = calc(i, j, 8, true);
      }
  }

} precalc;

u64 calc(u64 a, u64 b, int p = 64, int pre = false) {
  if (min(a, b) <= 1) return a * b;
  while (max(a, b) < 1ull << (p >> 1)) p >>= 1;
  if (!pre && p <= 8) return precalc.dp[a][b];
  p >>= 1;
  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);
  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);
  u64 c = calc(a1, b1, p, pre);
  u64 d = calc(a2, b2, p, pre);
  u64 e = calc(a1 ^ a2, b1 ^ b2, p, pre);
  return calc(c, 1ull << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);
}

u64 nim_product(u64 a, u64 b) { return calc(a, b); }

}  // namespace nimber
using nimber::nim_product;

/**
 * @brief Nim Product
 * @docs docs/math/nim-product.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

