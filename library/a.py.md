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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: a.py

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/a.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import atexit
import os


class Fastio:
    def __init__(self):
        self.ibuf = bytes()
        self.obuf = bytearray()
        self.pil = 0
        self.pir = 0
        self.buf = bytearray(21)
        self.buf[20] = 10

    def load(self):
        self.ibuf = self.ibuf[self.pil:]
        self.ibuf += os.read(0, 131072)
        self.pil = 0
        self.pir = len(self.ibuf)

    def flush(self):
        os.write(1, self.obuf)
        self.obuf = bytearray()

    def fastin(self):
        if self.pir - self.pil < 32:
            self.load()
        minus = 0
        x = 0
        while self.ibuf[self.pil] < 45:
            self.pil += 1
        if self.ibuf[self.pil] == 45:
            minus = 1
            self.pil += 1
        while self.ibuf[self.pil] >= 48:
            x = x * 10 + (self.ibuf[self.pil] & 15)
            self.pil += 1
        if minus:
            x = -x
        return x

    def fastoutln(self, x):
        i = 19
        if x == 0:
            self.buf[i] = 48
            i -= 1
        else:
            if x < 0:
                self.obuf.append(45)
                x = -x
            while x != 0:
                x, r = divmod(x, 10)
                self.buf[i] = 48 + r
                i -= 1
        self.obuf.extend(self.buf[i+1:21])
        if len(self.obuf) > 262144:
            self.flush()


fastio = Fastio()
rd = fastio.fastin
wtn = fastio.fastoutln
atexit.register(fastio.flush)


T = rd()
for i in range(T):
    A, B = rd(), rd()
    wtn(A + B)

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

<a href="../index.html">Back to top page</a>

