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


# :heavy_check_mark: data-structure/2d-binary-indexed-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/2d-binary-indexed-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp.html">verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree2D {
  int H, W;
  vector<vector<T>> bit;
  BinaryIndexedTree2D(int H, int W) : H(H + 1), W(W + 1) {
    bit.resize(H + 3, vector<T>(W + 3, 0));
  }
  // 関数の入力のindexは0-originを想定

  // (x,y)にwを足す
  // 範囲外の時は足さない
  void add(int x, int y, T w) {
    if (x < 0 || x >= H || y < 0 || y >= W) return;
    for (int a = (++y, ++x); a <= H; a += a & -a) {
      for (int b = y; b <= W; b += b & -b) {
        bit[a][b] += w;
      }
    }
  }

  // imos法で[(x1,y1) , (x2,y2)]にwを足す
  void imos(int x1, int y1, int x2, int y2, T w) {
    add(x1, y1, w);
    add(x1, y2 + 1, -w);
    add(x2 + 1, y1, -w);
    add(x2 + 1, y2 + 1, w);
  }

  //  [(0,0) , (x,y)]の和　閉区間に注意！
  // x,y<0の時は0 x>=H y>=Wのときはx=H-1,y=W-1とみなす
  // ( imos法の時は (x,y)の値を返す )
  T sum(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (x >= H) x = H - 1;
    if (y >= W) y = W - 1;
    T ret = 0;
    for (int a = (++y, ++x); a > 0; a -= a & -a) {
      for (int b = y; b > 0; b -= b & -b) {
        ret += bit[a][b];
      }
    }
    return ret;
  }

  // [(x1,y1) , (x2,y2)] の和
  // x1 > x2, y1 > y2の時はswap
  T sum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return T(0);
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +
           sum(x1 - 1, y1 - 1);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/2d-binary-indexed-tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree2D {
  int H, W;
  vector<vector<T>> bit;
  BinaryIndexedTree2D(int H, int W) : H(H + 1), W(W + 1) {
    bit.resize(H + 3, vector<T>(W + 3, 0));
  }
  // 関数の入力のindexは0-originを想定

  // (x,y)にwを足す
  // 範囲外の時は足さない
  void add(int x, int y, T w) {
    if (x < 0 || x >= H || y < 0 || y >= W) return;
    for (int a = (++y, ++x); a <= H; a += a & -a) {
      for (int b = y; b <= W; b += b & -b) {
        bit[a][b] += w;
      }
    }
  }

  // imos法で[(x1,y1) , (x2,y2)]にwを足す
  void imos(int x1, int y1, int x2, int y2, T w) {
    add(x1, y1, w);
    add(x1, y2 + 1, -w);
    add(x2 + 1, y1, -w);
    add(x2 + 1, y2 + 1, w);
  }

  //  [(0,0) , (x,y)]の和　閉区間に注意！
  // x,y<0の時は0 x>=H y>=Wのときはx=H-1,y=W-1とみなす
  // ( imos法の時は (x,y)の値を返す )
  T sum(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (x >= H) x = H - 1;
    if (y >= W) y = W - 1;
    T ret = 0;
    for (int a = (++y, ++x); a > 0; a -= a & -a) {
      for (int b = y; b > 0; b -= b & -b) {
        ret += bit[a][b];
      }
    }
    return ret;
  }

  // [(x1,y1) , (x2,y2)] の和
  // x1 > x2, y1 > y2の時はswap
  T sum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return T(0);
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +
           sum(x1 - 1, y1 - 1);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

