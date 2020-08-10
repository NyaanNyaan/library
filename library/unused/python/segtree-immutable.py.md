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


# :warning: unused/python/segtree-immutable.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1fff5e1f009a90e6e1bc2cb52b88bfd3">unused/python</a>
* <a href="{{ site.github.repository_url }}/blob/master/unused/python/segtree-immutable.py">View this file on GitHub</a>
    - Last commit date: 2020-08-01 13:45:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class SegmentTree:
    def __init__(self, N, func, I):
        self.sz = 2**(N-1).bit_length()
        self.func = func
        self.I = I
        self.seg = [I] * (self.sz * 2)
 
    def assign(self, k, x):
        self.seg[k + self.sz] = x
 
    def build(self):
        for i in range(self.sz - 1, 0, -1):
            self.seg[i] = self.func(self.seg[2 * i], self.seg[2 * i + 1])
 
    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k > 1:
            k >>= 1
            self.seg[k] = self.func(self.seg[2 * k], self.seg[2 * k + 1])
 
    def query(self, a, b):
        L = self.I
        R = self.I
        a += self.sz
        b += self.sz
        while a < b:
            if a & 1:
                L = self.func(L, self.seg[a])
                a += 1
            if b & 1:
                b -= 1
                R = self.func(self.seg[b], R)
            a >>= 1
            b >>= 1
        return self.func(L, R)
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

