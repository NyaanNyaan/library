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


# :warning: math/grundy-number.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/grundy-number.cpp">View this file on GitHub</a>
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

vector<int> GrundyNumber(vector<vector<int>> &g) {
  vector<int> topo = TopologicalSort(g);
  if ((int)topo.size() == 0) return vector<int>();
  vector<int> grundy(g.size(), 0);
  vector<int> memo(g.size() + 1, 0);
  for (int _ = (int)g.size() - 1; _ >= 0; _--) {
    int i = topo[_];
    if (g[i].size() == 0) continue;
    for (auto &x : g[i]) {
      memo[grundy[x]]++;
    }
    while (memo[grundy[i]] > 0) grundy[i]++;
    for (auto &x : g[i]) {
      memo[grundy[x]]--;
    }
  }
  return grundy;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/grundy-number.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

