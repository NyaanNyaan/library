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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#17f17e0bbb64138c9a2bbb0627c5fef6">verify/verify-yosupo-fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 00:13:26+09:00


* see: <a href="https://judge.yosupo.jp/problem/polynomial_interpolation">https://judge.yosupo.jp/problem/polynomial_interpolation</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :question: <a href="../../../library/fps/formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/fps/multipoint-evaluation.hpp.html">fps/multipoint-evaluation.hpp</a>
* :heavy_check_mark: <a href="../../../library/fps/ntt-friendly-fps.hpp.html">fps/ntt-friendly-fps.hpp</a>
* :heavy_check_mark: <a href="../../../library/fps/polynomial-interpolation.hpp.html">fps/polynomial-interpolation.hpp</a>
* :question: <a href="../../../library/modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>
* :question: <a href="../../../library/modint/simd-montgomery.hpp.html">modint/simd-montgomery.hpp</a>
* :question: <a href="../../../library/ntt/ntt-avx2.hpp.html">ntt/ntt-avx2.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../competitive-template.hpp"
#include "../../fps/multipoint-evaluation.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/polynomial-interpolation.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  int N;
  cin >> N;
  fps xs(N), ys(N);
  cin >> xs >> ys;
  cout << PolynomialInterpolation<mint>(xs, ys) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 239, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: fps/polynomial-interpolation.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

