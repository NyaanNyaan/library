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


# :warning: unused/python/ntt.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1fff5e1f009a90e6e1bc2cb52b88bfd3">unused/python</a>
* <a href="{{ site.github.repository_url }}/blob/master/unused/python/ntt.py">View this file on GitHub</a>
    - Last commit date: 2020-08-01 13:45:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class NumberTheroemTransform:
  def __init__(self, mod, pr):
    self.mod = mod
    self.pr = pr
    self.M = 2
    self.w = [1]
    self.y = [1]

  def setwy(self, M):
    if M <= self.M: return
    self.w += [0] * ((M - self.M) // 2)
    self.y += [0] * ((M - self.M) // 2)
    self.M = M
    z = pow(self.pr, (self.mod - 1) // self.M, self.mod)
    x = pow(z, self.mod - 2, self.mod)
    j = M // 4
    while j:
      self.w[j] = z
      z = z * z % self.mod
      self.y[j] = x
      x = x * x % self.mod
      j //= 2
    self.y[0] = 1
    self.w[0] = 1
    j = self.M // 2
    js = 2
    while js < j:
      z = self.w[js]
      x = self.y[js]
      for k2 in range(js):
        self.w[k2 + js] = self.w[k2] * z % self.mod
        self.y[k2 + js] = self.y[k2] * x % self.mod
      js *= 2

  def fft(self, a):
    mod = self.mod
    self.setwy(len(a))
    u = 1
    v = len(a) >> 1
    while v:
      for j in range(v):
        a[j], a[j + v] = a[j] + a[j + v], a[j] - a[j + v]
        if a[j] >= mod:
          a[j] -= mod
        if a[j + v] < 0:
          a[j + v] += mod
      for jh in range(1, u):
        wj = self.w[jh]
        js = jh * v * 2
        je = js + v
        for j in range(js, je):
          ajv = wj * a[j + v] % mod
          a[j + v] = a[j] - ajv
          if a[j + v] < 0:
            a[j + v] += mod
          a[j] = a[j] + ajv
          if a[j] >= mod:
            a[j] -= mod
      u *= 2
      v >>= 1

  def ifft(self, a):
    mod = self.mod
    self.setwy(len(a))
    u = len(a) >> 1
    v = 1
    while u:
      for j in range(v):
        a[j], a[j + v] = a[j] + a[j + v], a[j] - a[j + v]
        if a[j] >= mod:
          a[j] -= mod
        if a[j + v] < 0:
          a[j + v] += mod
      for jh in range(1, u):
        wj = self.y[jh]
        js = jh * v * 2
        je = js + v
        for j in range(js, je):
          ajv = a[j] - a[j + v]
          if ajv < 0:
            ajv += mod
          a[j] = a[j] + a[j + v]
          if a[j] >= mod:
            a[j] -= mod
          a[j + v] = wj * ajv % mod
      u >>= 1
      v *= 2

  def multiply(self, s, t):
    sl, tl = len(s), len(t)
    L = sl + tl - 1
    M = 2 ** (L - 1).bit_length()
    s += [0] * (M - sl)
    t += [0] * (M - tl)
    self.fft(s)
    self.fft(t)
    for i in range(M):
      s[i] = s[i] * t[i] % self.mod
    self.ifft(s)
    invk = pow(M, self.mod - 2, self.mod)
    for i in range(L):
      s[i] = s[i] * invk % self.mod
    del s[L:]
    return s
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

