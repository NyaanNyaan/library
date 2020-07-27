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


# :heavy_check_mark: graph/topological-sort.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topological-sort.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :question: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>
* :question: <a href="graph-template.hpp.html">graph/graph-template.hpp</a>


## Required by

* :warning: <a href="../math/grundy-number.hpp.html">math/grundy-number.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-4-a.test.cpp.html">verify-aoj-grl/aoj-grl-4-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-4-b.test.cpp.html">verify-aoj-grl/aoj-grl-4-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

#include "./graph-template.hpp"

// if the graph is not DAG, return empty vector
template <typename T>
vector<int> TopologicalSort(T &g) {
  int N = g.size();
  vector<int> marked(N, 0), temp(N, 0), v;
  auto visit = [&](auto f, int i) -> bool {
    if (temp[i] == 1) return false;
    if (marked[i] == 0) {
      temp[i] = 1;
      for (auto &e : g[i]) {
        if (f(f, e) == false) return false;
      }
      marked[i] = 1;
      v.push_back(i);
      temp[i] = 0;
    }
    return true;
  };

  for (int i = 0; i < N; i++) {
    if (marked[i] == 0) {
      if (visit(visit, i) == false) return vector<int>();
    }
  }
  reverse(v.begin(), v.end());
  return v;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/topological-sort.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

