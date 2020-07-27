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


# :heavy_check_mark: shortest-path/bellman-ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d53d0f39583bbf03056486512d3e44bc">shortest-path</a>
* <a href="{{ site.github.repository_url }}/blob/master/shortest-path/bellman-ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 23:51:38+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :heavy_check_mark: <a href="../graph/graph-template.cpp.html">graph/graph-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-1-b.test.cpp.html">verify-aoj-grl/aoj-grl-1-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../graph/graph-template.cpp"

// bellman-ford法
// goalが存在しないとき-> 負閉路が存在するときは空列を返す
// goalが存在するとき  -> startとgoalの間に負閉路が存在する時に負閉路を返す
template<typename T>
vector<T> bellman_ford(int N, Edges<T>& es , int start = 0 , int goal = -1){
  T INF = numeric_limits< T >::max() / 2;
  vector<T> d(N , INF);
  d[start] = 0;
  for(int i = 0 ; i < N ; i++){
    bool update = false;
    for(auto &e : es){
      if(d[e.src] == INF) continue;
      if(d[e.to] > d[e.src] + e.cost){
        update = true , d[e.to] = d[e.src] + e.cost;
      }
    }
    if(!update) return d;
  }

  if(goal == -1) return vector<T>();
  vector<bool> negative(N , false);
  for(int i = 0 ; i < N ; i++){
    for(auto &e : es){
      if(d[e.src] == INF) continue;
      if(d[e.to] > d[e.src] + e.cost)
        negative[e.to] = true , d[e.to] = d[e.src] + e.cost;
      if(negative[e.src] == true)
        negative[e.to] = true;
    }
  }

  if(negative[goal] == true) return vector<T>();
  else return d;  
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: shortest-path/bellman-ford.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

