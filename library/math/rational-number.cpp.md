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


# :warning: math/rational-number.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/rational-number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 15:02:17+09:00




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

struct RationalNumber {
  pair<long long, long long> a;

  RationalNumber(pair<long long, long long> p) { a = init(p.first, p.second); }
  RationalNumber(long long x, long long y) { a = init(x, y); }

  pair<long long, long long> init(long long x, long long y) {
    if (x == 0 && y == 0) return pair<long long, long long>(0, 0);
    long long g = this->gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) x = -x, y = -y;
    if (x == 0 && y < 0) y = -y;
    return pair<long long, long long>(x, y);
  }

  long long gcd(long long x, long long y) {
    long long z;
    if (x > y) swap(x, y);
    while (x) {
      x = y % (z = x);
      y = z;
    }
    return y;
  }
  bool zero() const { return a.first == 0 && a.second == 0; }
  RationalNumber orth() const { return RationalNumber{-a.second, a.first}; }
};
namespace std {
bool operator<(const RationalNumber &x, const RationalNumber &y) {
  return x.a < y.a;
}
bool operator==(const RationalNumber &x, const RationalNumber &y) {
  return x.a == y.a;
}
bool operator!=(const RationalNumber &x, const RationalNumber &y) {
  return x.a != y.a;
}
}  // namespace std
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/rational-number.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

