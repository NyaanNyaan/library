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


# :heavy_check_mark: shortest-path/warshall-floyd.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d53d0f39583bbf03056486512d3e44bc">shortest-path</a>
* <a href="{{ site.github.repository_url }}/blob/master/shortest-path/warshall-floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:43:08+09:00




## Depends on

* :question: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :question: <a href="../graph/graph-template.cpp.html">graph/graph-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-1-c.test.cpp.html">verify-aoj-grl/aoj-grl-1-c.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../graph/graph-template.cpp"

// i : d[i][i] < 0 exists -> negative cycle
template <typename T>
void warshall_floyd(T& d) {
  int N = sz(d[0]);
  for (int i = 0; i < N; i++) d[i][i] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
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
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: shortest-path/warshall-floyd.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

