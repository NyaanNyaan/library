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


# :heavy_check_mark: fps/polynomial-interpolation.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/polynomial-interpolation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-13 14:48:13+09:00




## Depends on

* :question: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp.html">verify/verify-yosupo-fps/yosupo-interpolation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./formal-power-series.hpp"

template <class mint>
FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint> &xs,
                                                const vector<mint> &ys) {
  using fps = FormalPowerSeries<mint>;
  assert(xs.size() == ys.size());
  ProductTree<mint> ptree(xs);
  fps w = ptree.buf[1].diff();
  vector<mint> vs = InnerMultipointEvaluation<mint>(w, xs, ptree);
  auto rec = [&](auto self, int idx) -> fps {
    if (idx >= ptree.N) {
      if (idx - ptree.N < (int)xs.size())
        return {ys[idx - ptree.N] / vs[idx - ptree.N]};
      else
        return {mint(1)};
    }
    if (ptree.buf[idx << 1 | 0].empty())
      return {};
    else if (ptree.buf[idx << 1 | 1].empty())
      return self(self, idx << 1 | 0);
    return self(self, idx << 1 | 0) * ptree.buf[idx << 1 | 1] +
           self(self, idx << 1 | 1) * ptree.buf[idx << 1 | 0];
  };
  return rec(rec, 1);
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 239, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: fps/polynomial-interpolation.hpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

