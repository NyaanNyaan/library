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


# :heavy_check_mark: data-structure/union-find-with-potential.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/union-find-with-potential.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj-dsl-1-b.test.cpp.html">verify/aoj-dsl-1-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

// PotentialつきUnion-Find
template <class T>
struct UnionFindWithPotential {
  vector<int> par, rank;
  // pot...根に対するポテンシャル
  vector<T> pot;
  T UNIT;

  UnionFindWithPotential(int N, T UNIT_ = 0)
      : par(N), rank(N), pot(N), UNIT(UNIT_) {
    for (int i = 0; i < N; i++) par[i] = i, rank[i] = 0, pot[i] = UNIT;
  }

  // xの根を返す関数
  int root(int x) {
    if (par[x] == x) return x;
    int r = root(par[x]);
    pot[x] += pot[par[x]];
    return par[x] = r;
  }

  // 根に対するポテンシャルを返す関数
  T potential(int x) {
    root(x);
    return pot[x];
  }

  // 根が同じかを判定する関数
  bool same(int x, int y) { return root(x) == root(y); }

  // xのyに対するpotentialを返す関数
  T diff(int x, int y) { return potential(x) - potential(y); }

  // xのyに対するpotentialがpである (xはyよりもp大きい)
  // falseの時、既存の情報と矛盾
  bool merge(int x, int y, T p) {
    p += potential(y) - potential(x);
    x = root(x), y = root(y);
    if (x == y) {
      return p == UNIT;
    }
    if (rank[x] > rank[y]) swap(x, y), p = -p;
    if (rank[x] == rank[y]) ++rank[x];
    par[x] = y, pot[x] = p;
    return true;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/union-find-with-potential.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

