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


# :heavy_check_mark: verify-yosupo-ds/yosupo-rectangle-sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bd0671126b1c769555a4a09b2a39dde2">verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 19:38:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/competitive-template.cpp.html">competitive-template.cpp</a>
* :heavy_check_mark: <a href="../../library/data-structure/rectangle-sum.cpp.html">data-structure/rectangle-sum.cpp</a>
* :heavy_check_mark: <a href="../../library/segment-tree/persistent-segment-tree.cpp.html">segment-tree/persistent-segment-tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../competitive-template.cpp"
#include "../data-structure/rectangle-sum.cpp"

void solve() {
  ini(N, Q);
  vl xs(N), ys(N), ws(N);
  in3(xs, ys, ws);
  auto f = [](ll u, ll v) { return u + v; };
  RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);
  rep(_, Q) {
    inl(l, d, r, u);
    out(rect.rect_sum(l, d, r, u));
  }
}
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
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: competitive-template.cpp: line 108: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

