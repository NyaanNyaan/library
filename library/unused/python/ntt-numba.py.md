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


# :warning: unused/python/ntt-numba.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1fff5e1f009a90e6e1bc2cb52b88bfd3">unused/python</a>
* <a href="{{ site.github.repository_url }}/blob/master/unused/python/ntt-numba.py">View this file on GitHub</a>
    - Last commit date: 2020-08-01 13:45:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from numba import jit, njit, i8
import numpy as np


@njit(i8(i8, i8, i8), cache=True)
def modpow(a, p, m):
  r = 1
  while p:
    if p & 1: r = r * a % m
    a = a * a % m
    p >>= 1
  return r


@njit(i8[:](i8[:], i8[:]), cache=True)
def ntt(s, t):
  mod = 998244353
  pr = 5
  sl, tl = len(s), len(t)
  k = 1
  M = 2
  while M < sl + tl - 1:
    k += 1
    M *= 2
  w = np.zeros(M // 2, np.int64)
  y = np.zeros(M // 2, np.int64)

  def init():
    nonlocal w, y, M, mod, pr
    z = modpow(pr, (mod - 1) // M, mod)
    x = modpow(z, mod - 2, mod)
    j = M // 4
    while j:
      w[j] = z
      z = z * z % mod
      y[j] = x
      x = x * x % mod
      j //= 2
    y[0] = 1
    w[0] = 1
    j = M // 2
    js = 2
    while js < j:
      z = w[js]
      x = y[js]
      for k2 in range(js):
        w[k2 + js] = w[k2] * z % mod
        y[k2 + js] = y[k2] * x % mod
      js *= 2

  def fft(a, k):
    nonlocal w, y, mod
    m = 2 ** k
    u = 1
    v = m // 2
    i = k
    while i:
      jh = 0
      while jh < u:
        wj = w[jh]
        j = jh * v * 2
        je = j + v
        while j < je:
          ajv = wj * a[j + v] % mod
          a[j + v] = a[j] + mod - ajv
          if a[j + v] >= mod:
            a[j + v] -= mod
          a[j] = a[j] + ajv
          if a[j] >= mod:
            a[j] -= mod
          j += 1
        jh += 1
      u *= 2
      v //= 2
      i -= 1

  def ifft(a, k):
    nonlocal w, y, mod
    m = 2 ** k
    u = m // 2
    v = 1
    i = 1
    while i <= k:
      jh = 0
      while jh < u:
        wj = y[jh]
        j = jh * v * 2
        je = j + v
        while j < je:
          ajv = a[j] + mod - a[j + v]
          if ajv >= mod:
            ajv -= mod
          a[j] = a[j] + a[j + v]
          if a[j] >= mod:
            a[j] -= mod
          a[j + v] = wj * ajv % mod
          j += 1
        jh += 1
      u //= 2
      v *= 2
      i += 1

  init()
  u = np.zeros(M, np.int64); u[:sl] = s; fft(u, k)
  v = np.zeros(M, np.int64); v[:tl] = t; fft(v, k)
  u *= v; u %= mod; ifft(u, k)
  u *= modpow(2 ** k, mod - 2, mod); u %= mod
  return u[:sl + tl - 1]

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

