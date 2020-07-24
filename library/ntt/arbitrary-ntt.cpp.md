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


# :warning: ntt/arbitrary-ntt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ccb3669c87b2d028539237c4554e3c0f">ntt</a>
* <a href="{{ site.github.repository_url }}/blob/master/ntt/arbitrary-ntt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>
* :warning: <a href="../modint/arbitrary-modint.cpp.html">modint/arbitrary-modint.cpp</a>
* :warning: <a href="../modint/montgomery-modint.cpp.html">modint/montgomery-modint.cpp</a>
* :warning: <a href="../modint/simd-montgomery.cpp.html">modint/simd-montgomery.cpp</a>
* :warning: <a href="ntt-sse42.cpp.html">ntt/ntt-sse42.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "../modint/montgomery-modint.cpp"
#include "../modint/simd-montgomery.cpp"
#include "../modint/arbitrary-modint.cpp"
#include "./ntt-sse42.cpp"

namespace ArbitraryNTT {
constexpr int32_t m0 = 167772161;
constexpr int32_t m1 = 469762049;
constexpr int32_t m2 = 754974721;
using mint0 = LazyMontgomeryModInt<m0>;
using mint1 = LazyMontgomeryModInt<m1>;
using mint2 = LazyMontgomeryModInt<m2>;

template <int mod>
vector<LazyMontgomeryModInt<mod>> mul(const vector<int> &a,
                                      const vector<int> &b) {
  using submint = LazyMontgomeryModInt<mod>;
  NTT<submint> ntt;
  vector<submint> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
  return std::move(ntt.multiply(s, t));
}

template <int mod>
vector<int> multiply(const vector<int> &s, const vector<int> &t) {
  auto d0 = mul<m0>(s, t);
  auto d1 = mul<m1>(s, t);
  auto d2 = mul<m2>(s, t);
  int n = d0.size();
  vector<int> res(n);
  using i64 = int64_t;
  static const int r01 = mint1(m0).inverse().get();
  static const int r02 = mint2(m0).inverse().get();
  static const int r12 = mint2(m1).inverse().get();
  static const int r02r12 = i64(r02) * r12 % m2;
  static const int w1 = m0 % mod;
  static const int w2 = i64(w1) * m1 % mod;
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    res[i] = (a + b * w1 + c * w2) % mod;
  }
  return std::move(res);
}

vector<int> multiply(const vector<int> &s, const vector<int> &t, int mod) {
  auto d0 = mul<m0>(s, t);
  auto d1 = mul<m1>(s, t);
  auto d2 = mul<m2>(s, t);
  int n = d0.size();
  vector<int> res(n);
  using i64 = int64_t;
  static const int r01 = mint1(m0).inverse().get();
  static const int r02 = mint2(m0).inverse().get();
  static const int r12 = mint2(m1).inverse().get();
  static const int r02r12 = i64(r02) * r12 % m2;
  static const int w1 = m0 % mod;
  static const int w2 = i64(w1) * m1 % mod;
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    res[i] = (a + b * w1 + c * w2) % mod;
  }
  return std::move(res);
}

template <int mod>
vector<LazyMontgomeryModInt<mod>> multiply(
    const vector<LazyMontgomeryModInt<mod>> &a,
    const vector<LazyMontgomeryModInt<mod>> &b) {
  using mint = LazyMontgomeryModInt<mod>;
  vector<int> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();
  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();
  vector<int> u = multiply<mod>(s, t);
  vector<mint> ret(u.size());
  for (int i = 0; i < (int)u.size(); ++i)
    ret[i].a = mint::reduce(uint64_t(u[i]) * mint::n2);
  return std::move(ret);
}

vector<ArbitraryModInt> multiply(const vector<ArbitraryModInt> &a,
                                 const vector<ArbitraryModInt> &b) {
  using mint = ArbitraryModInt;
  vector<int> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].x;
  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].x;
  vector<int> u = multiply(s, t, ArbitraryModInt::get_mod());
  vector<mint> ret(u.size());
  for (int i = 0; i < (int)u.size(); ++i) ret[i].x = u[i];
  return std::move(ret);
}
}  // namespace ArbitraryNTT
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ntt/arbitrary-ntt.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

