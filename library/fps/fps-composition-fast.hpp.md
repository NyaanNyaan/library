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





## 関数の合成

形式的冪級数$P(x),Q(x)$(ただし$P_0 = 0$)に対して$Q(P) \mod x^{n}$を$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$で求めるライブラリ。

[出典の論文](http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf)

#### 概要

まず、$P$を$P = P_m + P_r,\ \ P_r \equiv 0 \mod x^m$を満たす$P_m,P_r$に分けて考える。($m$は後で値を決める。)この時、テイラー展開の式

$$Q(P)=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P-P_m)^i=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P_r)^i$$

の前$\lfloor\frac{n}{m}\rfloor$次の項を計算できればよいので($P_r \equiv 0 \mod x$に留意する)、$Q^{(i)}(P),0 \leq i \leq \lfloor\frac{n}{m}\rfloor$を高速に列挙できればよい。

まず、$Q(P(x))\mod x^n$は$\deg(Q) = j$($j$は2冪)とした時

$$Q(P) = Q_1(P) + P^{\frac{j}{2}}\cdot Q_2(P)$$

を利用して再帰的に求めることで$\mathrm{O}(jm\log^2 n)$で計算できる。また、$Q^{(i)}(P_m)$は連鎖律$\frac{d}{dx}Q(P) = \frac{dP} {dx} \cdot \frac{dQ}{dP}$を利用して

$$Q^{(i)}{(P_m)} \equiv \frac{\left(Q^{(i-1)}{(P_m)}\right)'}{P_m'} \mod x^{n-i}$$

より$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で列挙できる。(実装においては、$m \geq 2$かつ$P$の$2$次の係数が$0$の時に$\frac{1}{P_m'}$が定義されないコーナーケースを意識して適切に逆元を取る必要がある。)

最後にテイラー展開の式に基づいて足し合わせる部分も愚直に計算すると$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で計算できる。

以上より$j = n$とすると$\mathrm{O}(nm\log^2 n + \lfloor\frac{n}{m}\rfloor n \log n)$で$Q(P(x))$を計算することが出来た。ここで$m = \sqrt{\frac{n} {\log n}}$とおくと$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$となる。

###### 余談

実装してから思ったが、元の論文には行列積を使用した$O(\sqrt{N}\cdot T(\sqrt{N}))$($T(n)$は行列積のオーダー)のアルゴリズムも載っており、オーダーは実質2乗だがSIMDの利用などにより定数倍高速化が見込める。

$N \leq 8192$とすると、感覚的には解説したアルゴリズムよりも大きさ$100$の行列積$100回$の方が高速に動作する気がする… 

$\rightarrow$実装したら3倍速かった [実装](https://nyaannyaan.github.io/library/library/fps/fps-composition-fast.hpp.html)


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
 * @docs docs/fps/fps-composition.md
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

