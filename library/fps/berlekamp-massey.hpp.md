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


# :heavy_check_mark: fps/berlekamp-massey.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/berlekamp-massey.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-12 21:35:55+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp.html">verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
vector<mint> BerlekampMassey(const vector<mint> &s) {
  const int N = (int)s.size();
  vector<mint> b, c;
  b.reserve(N + 1);
  c.reserve(N + 1);
  b.push_back(mint(1));
  c.push_back(mint(1));
  mint y = mint(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size());
    mint x = 0;
    for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
    b.emplace_back(mint(0));
    m++;
    if (x == mint(0)) continue;
    mint freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, mint(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  reverse(begin(c), end(c));
  return c;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/berlekamp-massey.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
vector<mint> BerlekampMassey(const vector<mint> &s) {
  const int N = (int)s.size();
  vector<mint> b, c;
  b.reserve(N + 1);
  c.reserve(N + 1);
  b.push_back(mint(1));
  c.push_back(mint(1));
  mint y = mint(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size());
    mint x = 0;
    for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
    b.emplace_back(mint(0));
    m++;
    if (x == mint(0)) continue;
    mint freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, mint(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  reverse(begin(c), end(c));
  return c;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

