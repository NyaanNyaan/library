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


# :heavy_check_mark: segment-tree/segment-tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/segment-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj-dsl-2-a-segtree.test.cpp.html">verify/aoj-dsl-2-a-segtree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/aoj-dsl-2-b-segtree.test.cpp.html">verify/aoj-dsl-2-b-segtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template<typename T,typename F>
struct SegmentTree{

  int size;
  vector<T> seg;
  const F func;
  const T UNIT;
  
  SegmentTree(int N,F func , T UNIT): func(func) , UNIT(UNIT) {
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
  }

  SegmentTree(const vector<T> &v,F func , T UNIT) : func(func) , UNIT(UNIT){
    int N = (int)v.size();
    size = 1;
    while(size < N) size <<= 1;
    seg.assign(2 * size , UNIT);
    for(int i = 0; i < N; i++){
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k, T x){
    seg[k + size] = x;
  }

  void build(){
    for(int k = size-1; k > 0; k--){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  void update(int k, T x){
    k += size; seg[k] = x;
    while(k >>= 1){
      seg[k] = func( seg[2 * k] , seg[2 * k + 1] );
    }
  }

  void add(int k , T x){
    k += size; seg[k] += x;
    while(k >>= 1){
      seg[k] = func(seg[2 * k] , seg[2 * k + 1] );
    }
  }
  
  // query to [a, b) 
  T query(int a, int b){
    T L = UNIT, R = UNIT;
    for(a+=size,b+=size; a<b; a>>=1,b>>=1){
      if(a & 1) L = func(L,seg[a++]);
      if(b & 1) R = func(seg[--b],R);
    }
    return func(L, R);
  }

  T& operator[](const int &k){
    return seg[k + size];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/segment-tree.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

