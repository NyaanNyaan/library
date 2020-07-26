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


# :x: verify-aoj-grl/aoj-grl-5-d.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f6d05e39b39a7a0b0203ea25054f4234">verify-aoj-grl</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify-aoj-grl/aoj-grl-5-d.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 01:36:08+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D</a>


## Depends on

* :question: <a href="../../library/competitive-template.cpp.html">competitive-template.cpp</a>
* :question: <a href="../../library/graph/graph-template.cpp.html">graph/graph-template.cpp</a>
* :question: <a href="../../library/segment-tree/segment-tree.cpp.html">segment-tree/segment-tree.cpp</a>
* :question: <a href="../../library/tree/heavy-light-decomposition.cpp.html">tree/heavy-light-decomposition.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include "../competitive-template.cpp"
#include "../segment-tree/segment-tree.cpp"
#include "../tree/heavy-light-decomposition.cpp"
void solve() {
  ini(N);
  vvi g(N);
  rep(i, N) {
    ini(n);
    g[i].resize(n);
    in(g[i]);
  }

  HeavyLightDecomposition<vvi> hld(g);
  auto f = [](int a, int b) { return a + b; };
  SegmentTree<int, decltype(f)> seg(N, f, 0);
  int ans = 0;
  auto q = [&](int u, int v) { ans += seg.query(u, v); };

  ini(Q);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(v, w);
      seg.add(hld.in[v], w);
    } else {
      ini(v);
      ans = 0;
      hld.edge_query(0, v, q);
      out(ans);
    }
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

