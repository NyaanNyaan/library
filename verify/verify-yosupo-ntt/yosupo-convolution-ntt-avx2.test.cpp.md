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


# :x: verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c2de173895230134e20c27dd4ec4cad4">verify-yosupo-ntt</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :question: <a href="../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :x: <a href="../../library/modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>
* :x: <a href="../../library/modint/simd-montgomery.hpp.html">modint/simd-montgomery.hpp</a>
* :x: <a href="../../library/ntt/ntt-avx2.hpp.html">ntt/ntt-avx2.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../competitive-template.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../ntt/ntt-avx2.hpp"

constexpr int MOD = 998244353;
using mint = LazyMontgomeryModInt<MOD>;
using vm = vector<mint>;

__attribute__((target("avx2"))) void solve() {
  NTT<mint> ntt;
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: competitive-template.hpp: line 108: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

