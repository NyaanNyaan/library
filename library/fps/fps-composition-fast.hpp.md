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


# :warning: 関数の合成( $\mathrm{O}(N^2)$ ) <small>(fps/fps-composition-fast.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/fps-composition-fast.hpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../fps/formal-power-series.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../modulo/strassen.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) fps Composition(
    fps P, fps Q, int deg = -1) {
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  int K = max<int>(ceil(sqrt(N)), 2);
  assert(N <= K * K);

  vector<fps> PS(K + 1);
  {
    // step 1
    PS[0].resize(N, mint());
    PS[0][0] = 1;
    PS[1] = P;
    fps::set_fft();
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i <= K; i++) PS[i] = (PS[i - 1] * P).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Pomega = P;
      Pomega.resize(len);
      Pomega.ntt();
      for (int i = 2; i <= K; i++) {
        PS[i].resize(len);
        for (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];
        PS[i].ntt();
        for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];
        PS[i].intt();
        PS[i].resize(N);
        PS[i].shrink_to_fit();
      }
    }
  }

  vector<fps> TS(K);
  {
    // step 2
    TS[0].resize(N, mint());
    TS[0][0] = 1;
    TS[1] = PS[K];
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Tomega = TS[1];
      Tomega.resize(len);
      Tomega.ntt();
      for (int i = 2; i < K; i++) {
        TS[i].resize(len);
        for (int j = 0; j < N; j++) TS[i][j] = TS[i - 1][j];
        TS[i].ntt();
        for (int j = 0; j < len; j++) TS[i][j] *= Tomega[j];
        TS[i].intt();
        TS[i].resize(N);
        TS[i].shrink_to_fit();
      }
    }
  }

  // step 3
  vector<fps> QP;
  {
    PS.pop_back();
    vector<fps> QS(K, fps(K, mint()));
    for (int i = 0; i < K; i++)
      for (int j = 0; j < K; j++) {
        QS[i][j] = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();
      }
    
    QP = FastMatProd::fast_mul_2(QS, PS);
    // QP = FastMatProd::naive_mul(QS, PS);
  }

  fps ans(N, mint());
  {
    // step 4,5
    for (int i = 0; i < K; i++) ans += (QP[i] * TS[i]).pre(N);
  }
  return ans;
}

/**
 * @brief 関数の合成( $\mathrm{O}(N^2)$ )
 */

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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 258, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modulo/strassen.hpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

