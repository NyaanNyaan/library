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


# :heavy_check_mark: misc/fastio.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/fastio.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 17:31:00+09:00




## Required by

* :warning: <a href="../arbitrary-length-test.cpp.html">arbitrary-length-test.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp.html">verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-swag.test.cpp.html">verify/verify-yosupo-ds/yosupo-swag.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-composition.test.cpp.html">verify/verify-yosupo-fps/yosupo-composition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp.html">verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp.html">verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp.html">verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp.html">verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-factrization.test.cpp.html">verify/verify-yosupo-math/yosupo-factrization.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp.html">verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-mod-log.test.cpp.html">verify/verify-yosupo-math/yosupo-mod-log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-prime-table.test.cpp.html">verify/verify-yosupo-math/yosupo-prime-table.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp.html">verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp.html">verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp.html">verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ntt/yosupo-inliner-multiply.test.cpp.html">verify/verify-yosupo-ntt/yosupo-inliner-multiply.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp.html">verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
}
inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

inline void rd(char& c) { c = ibuf[pil++]; }
template <typename T>
inline void rd(T& x) {
  if (pil + 32 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if (c == '-') {
    minus = 1;
    c = ibuf[pil++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = ibuf[pil++];
  }
  if (minus) x = -x;
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head& head, Tail&... tail) {
  rd(head);
  rd(tail...);
}

inline void wt(char c) { obuf[por++] = c; }
template <typename T>
inline void wt(T x) {
  if (por > SZ - 32) flush();
  if (!x) {
    obuf[por++] = '0';
    return;
  }
  if (x < 0) {
    obuf[por++] = '-';
    x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  int d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);
  memcpy(obuf + por, pre.num + x * 4 + 4 - d, d);
  por += d;
  memcpy(obuf + por, buf + i + 4, 12 - i);
  por += 12 - i;
}

inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head head, Tail... tail) {
  wt(head);
  wt(tail...);
}
template<typename T>
inline void wtn(T x){
  wt(x, '\n');
}

struct Dummy {
  Dummy() { atexit(flush); }
} dummy;

}  // namespace fastio
using fastio::rd;
using fastio::wt;
using fastio::wtn;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "misc/fastio.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
}
inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

inline void rd(char& c) { c = ibuf[pil++]; }
template <typename T>
inline void rd(T& x) {
  if (pil + 32 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if (c == '-') {
    minus = 1;
    c = ibuf[pil++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = ibuf[pil++];
  }
  if (minus) x = -x;
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head& head, Tail&... tail) {
  rd(head);
  rd(tail...);
}

inline void wt(char c) { obuf[por++] = c; }
template <typename T>
inline void wt(T x) {
  if (por > SZ - 32) flush();
  if (!x) {
    obuf[por++] = '0';
    return;
  }
  if (x < 0) {
    obuf[por++] = '-';
    x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  int d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);
  memcpy(obuf + por, pre.num + x * 4 + 4 - d, d);
  por += d;
  memcpy(obuf + por, buf + i + 4, 12 - i);
  por += 12 - i;
}

inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head head, Tail... tail) {
  wt(head);
  wt(tail...);
}
template<typename T>
inline void wtn(T x){
  wt(x, '\n');
}

struct Dummy {
  Dummy() { atexit(flush); }
} dummy;

}  // namespace fastio
using fastio::rd;
using fastio::wt;
using fastio::wtn;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

