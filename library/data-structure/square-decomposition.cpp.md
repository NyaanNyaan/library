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


# :warning: data-structure/square-decomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/square-decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :question: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

constexpr int B = 300;

struct block{

  // S 更新用 T 取得用
  using S = long long;
  using T = long long;

  // 各種変数の初期化を忘れない！！！
  block(){

  }

  void build(){

  }

  void update_all(S x){

  }
  
  void update_part(int l,int r, S x){

    build();
  }

  T query_all(){

  }
  
  T query_part(int l,int r){
  
  }

};

// 取得クエリのマージ関数をf、単位元をUNITとする
template <typename F> struct Sqd{
  int N;
  V<block> sq;
  F f;
  block::T UNIT;
  Sqd(int N , F f, block::T UNIT) : N(N) , sq(N / B + 1) , f(f) , UNIT(UNIT) {
    init();
    for(auto &x : sq) x.build();
  }

  void init(){

  }

  // 半開区間[ l , r )に対する更新クエリ
  void update(int l , int r , block::S x){
    if(l / B == r / B) {
      sq[l / B].update_part(l % B , r % B , x);
    }
    else {
      sq[l / B].update_part(l % B , B , x);
      for(int i = l / B + 1 ; i < r / B ; i++) sq[i].update_all(x);
      sq[r / B].update_part(0 , r % B , x);
    }
  }

  // 半開区間[ l , r )に対する取得クエリ
  block::T query(int l,int r){
    if(l / B == r / B)
      return sq[l / B].query_part(l % B , r % B);
    block::T ret = UNIT;
    ret = f( ret , sq[l / B].query_part(l % B , B) );
    for(int i = l / B + 1 ; i < r / B ; i++) 
      ret = f(ret , sq[i].query_all() );
    ret = f( ret , sq[r / B].query_part(0 , r % B) );
    return ret;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/square-decomposition.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

