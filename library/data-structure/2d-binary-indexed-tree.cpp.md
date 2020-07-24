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


# :warning: data-structure/2d-binary-indexed-tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/2d-binary-indexed-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <typename T>
struct BIT2D {
  int H, W;
  vector<vector<T>> bit;
  BIT2D(int H, int W) : H(H), W(W) { bit.resize(H + 1, vector<T>(W + 1, 0)); }
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
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/2d-binary-indexed-tree.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

