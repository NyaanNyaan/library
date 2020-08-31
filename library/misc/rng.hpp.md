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


# :heavy_check_mark: misc/rng.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/rng.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :heavy_check_mark: <a href="../math/prime-factor.hpp.html">高速素因数分解(Miller Rabin/Pollard's Rho) <small>(math/prime-factor.hpp)</small></a>
* :warning: <a href="simulated-annealing.hpp.html">misc/simulated-annealing.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-factrization.test.cpp.html">verify/verify-yosupo-math/yosupo-factrization.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

unsigned long long rng() {
  static unsigned long long x_ = 88172645463325252ULL;
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "misc/rng.hpp"
#include <bits/stdc++.h>
using namespace std;

unsigned long long rng() {
  static unsigned long long x_ = 88172645463325252ULL;
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

