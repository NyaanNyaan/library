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


# :warning: math/divisor-multiple-transform.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/divisor-multiple-transform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

struct divisor_transform{
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a){
    int N = a.size() - 1; 
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = 1; k * p <= N; ++k)
          sieve[k * p] = false , a[k * p] += a[k];    
  }

  template<typename T>
  static constexpr void mobius_transform(T &a){
    int N = a.size() - 1; 
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , a[k * p] -= a[k];    
  }
  
  // verify 
  // https://atcoder.jp/contests/arc064/submissions/7707249
  template<typename T>
  static constexpr void zeta_transform(map<long long, T> &a){
    for(auto &x : a) for(auto &y : a){
      if(x == y) break;
      if(x.first % y.first == 0) x.second += y.second;
    }
  }
  template<typename T>
  static constexpr void mobius_transform(map<long long, T> &a){
    for(auto &x : a) for(auto &y : a){
      if(x == y) break;
      if(x.first % y.first == 0) x.second -= y.second;
    }
  }

};

// verify
// https://atcoder.jp/contests/agc038/submissions/7683063
// https://www.codechef.com/viewsolution/26767783
struct multiple_transform{
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a){
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; ++p)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , a[k] += a[k * p];
  }
  template <typename T>
  static constexpr void mobius_transform(vector<T> &a){
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for(int p = 2; p <= N; ++p)
      if(sieve[p])
        for(int k = 1; k * p <= N; ++k)
          sieve[k * p] = false , a[k] -= a[k * p];
  }

  template<typename T>
  static constexpr void zeta_transform(map<long long, T> &a){
    for(auto it=a.rbegin(); it!=a.rend(); it++)
      for(auto it2=a.rbegin(); it2!=it; it2++)
        if(it2->first % it->first == 0)
          it->second += it2->second;
  }
  template<typename T>
  static constexpr void mobius_transform(map<long long, T> &a){
    for(auto it=a.rbegin(); it!=a.rend(); it++)
      for(auto it2=a.rbegin(); it2!=it; it2++)
        if(it2->first % it->first == 0)
          it->second -= it2->second;
  }

};

template<typename T>
static constexpr vector<T> mobius_function(int N){
  vector<T> a(N + 1 , 0);
  a[1] = 1;
  divisor_transform::mobius_transform(a);
  return a;
}

template<int N>
struct constexpr_mobius_function{
  int mobius[N + 1] , sieve[N + 1];
  constexpr constexpr_mobius_function(): mobius() , sieve(){
    for(int i=1; i<=N; i++) sieve[i] = 1, mobius[i] = 0;
    mobius[1] = 1;
    for(int p = 2; p <= N; p++)
      if(sieve[p])
        for(int k = N / p; k > 0; --k)
          sieve[k * p] = false , mobius[k * p] -= mobius[k];    
  }
  const int& operator[](int i)const{return mobius[i];}
};

// N = 1000000 , pnum = 78498
template<int N,int pnum> struct constexpr_prime{
  int prime[pnum];
  int sieve[N + 1];
  constexpr_prime() : prime() , sieve() {
    for(int i=2;i<=N;i++) sieve[i]=1;
    int idx = 0;
    for(long long p = 2; p <= N; p++){
      if(sieve[p]){
        prime[idx++] = p;
        for(long long j = p * p; j <= N; j += p) sieve[j] = 0;
      }
    }
  }
  const long long& operator[](long long i) const{return prime[i];}
};

// verify
template<typename T,typename F>
static constexpr unordered_map<long long,T> divisor_zeta_transform(long long N, F f){
  // factorization
  unordered_map<long long,long long> factors;
  {
    long long M = N;
    for(long long i = 2; i * i <= M; i++)
      while(M % i == 0) factors[i]++ , M /= i;
    if(M != 1) factors[M]++;
  }
  unordered_map<long long,T> ret;
  ret.emplace(1 , 1);
  for(auto &d : factors){
    auto ret2 = ret;
    T prev = 1;
    for(long long i = 1 , cur = d.first; 
      i <= d.second;
      i++ , cur *= d.first){
      T val = ( prev += f(cur) );
      for(auto &x : ret) 
        ret2.emplace(x.first*cur , x.second*val);
    }
    swap(ret , ret2);
  }
  return ret;
}

// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/NTL_1_D/judge/3892694/C++14
// https://atcoder.jp/contests/abc020/submissions/7695313
template<typename T,typename F>
static constexpr unordered_map<long long,T> divisor_mobius_transform(long long N, F f){
  // factorization
  unordered_map<long long,long long> factors;
  {
    long long M = N;
    for(long long i = 2; i * i <= M; i++)
      while(M % i == 0) factors[i]++ , M /= i;
    if(M != 1) factors[M]++;
  }
  unordered_map<long long,T> ret;
  ret.emplace(1 , 1);
  for(auto &d : factors){
    auto ret2 = ret;
    for(long long i = 1,cur = d.first , prev = 1; 
      i <= d.second; 
      i++ , cur *= d.first , prev *= d.first){
      T val = f(cur) - f(prev);
      for(auto &x : ret) 
        ret2.emplace(x.first*cur , x.second*val);
    }
    swap(ret , ret2);
  }
  return ret;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/divisor-multiple-transform.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

