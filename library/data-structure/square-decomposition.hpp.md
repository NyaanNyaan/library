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


# :heavy_check_mark: 平方分割 <small>(data-structure/square-decomposition.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/square-decomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 01:46:09+09:00




## 平方分割

要素数$N$の列を$\mathrm{O}(\sqrt(N))$個のバケットに分割して管理することで列上のクエリを高速に答えるアルゴリズムを平方分割と呼ぶ。

セグメント木にない特長として、バケット上に重たいデータ構造を乗せることが出来るという点がある。例えば次の二つのクエリに答える問題を考える。

- `add(l,r,x)` : $[a_l,a_r)$に$x$を足す
- `count[l,r,x)` : $[a_l,a_r)$内にある$x$の個数を数える
- $1 \leq l < r \leq N=10^5,$クエリ数$Q=10^5,a_i \leq 10^9, x \leq 10^9$

この問題にセグメント木を適用するとノード上に大量のhashmapを乗せることになり計算量が悪化するが、平方分割ならばhashmapの空間計算量が$\mathrm{O}(N)$で抑えられるため$\mathrm{O}((N+Q)\sqrt{N})$で解くことが出来る。(range addは適切に遅延評価すればよい。)

#### 使い方

次のようなblockを作成して本体に乗せると上手く動く。

```cpp=
struct block {
  // S 作用素の型 T 要素の型
  using S = ;
  using T = ;

  int i;

  block() {}

  // i ... 何個目のブロックか
  // i * B + j ... (jをブロック内のidxとして)全体でのidx
  int idx(int j) const { return i * B + j; }
  
  // 変数とブロックの初期化を忘れない！
  void init(int _) { 
    i = _; 
  }

  void build() {

  }

  void update_all(S x) {

  }

  void update_part(int l, int r, S x) { 
    
    build(); 
  }

  T query_all() {

  }

  T query_part(int l, int r) {

  }
};
```

## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp.html">verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename MERGE, typename block, int B>
struct SquareDecomposition {
  int N;
  vector<block> sq;
  MERGE merge;
  typename block::T UNIT;
  SquareDecomposition(int N_, MERGE merge_, typename block::T UNIT_)
      : N(N_), sq(N / B + 1), merge(merge_), UNIT(UNIT_) {
    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);
  }

  void update(int l, int r, typename block::S x) {
    if (l / B == r / B) {
      sq[l / B].update_part(l % B, r % B, x);
    } else {
      sq[l / B].update_part(l % B, B, x);
      for (int i = l / B + 1; i < r / B; i++) sq[i].update_all(x);
      sq[r / B].update_part(0, r % B, x);
    }
  }

  typename block::T query(int l, int r) {
    if (l / B == r / B) return sq[l / B].query_part(l % B, r % B);
    typename block::T ret = UNIT;
    ret = merge(ret, sq[l / B].query_part(l % B, B));
    for (int i = l / B + 1; i < r / B; i++) ret = merge(ret, sq[i].query_all());
    ret = merge(ret, sq[r / B].query_part(0, r % B));
    return ret;
  }
};

/**
 * @brief 平方分割
 * @docs docs/sqrt-dec.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/square-decomposition.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename MERGE, typename block, int B>
struct SquareDecomposition {
  int N;
  vector<block> sq;
  MERGE merge;
  typename block::T UNIT;
  SquareDecomposition(int N_, MERGE merge_, typename block::T UNIT_)
      : N(N_), sq(N / B + 1), merge(merge_), UNIT(UNIT_) {
    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);
  }

  void update(int l, int r, typename block::S x) {
    if (l / B == r / B) {
      sq[l / B].update_part(l % B, r % B, x);
    } else {
      sq[l / B].update_part(l % B, B, x);
      for (int i = l / B + 1; i < r / B; i++) sq[i].update_all(x);
      sq[r / B].update_part(0, r % B, x);
    }
  }

  typename block::T query(int l, int r) {
    if (l / B == r / B) return sq[l / B].query_part(l % B, r % B);
    typename block::T ret = UNIT;
    ret = merge(ret, sq[l / B].query_part(l % B, B));
    for (int i = l / B + 1; i < r / B; i++) ret = merge(ret, sq[i].query_all());
    ret = merge(ret, sq[r / B].query_part(0, r % B));
    return ret;
  }
};

/**
 * @brief 平方分割
 * @docs docs/sqrt-dec.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

