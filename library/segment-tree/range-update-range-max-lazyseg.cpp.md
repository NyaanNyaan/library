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


# :heavy_check_mark: segment-tree/range-update-range-max-lazyseg.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/range-update-range-max-lazyseg.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj-dsl-2-f-max.test.cpp.html">verify/aoj-dsl-2-f-max.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <typename E, E MINF>
struct UpdateMax_LazySegmentTree {
  int n, height;
  using T = E;
  T f(T a, T b) { return max(a, b); };
  T g(T a, E b) { return b; };
  E h(E a, E b) { return b; };
  T ti = MINF;
  E ei = MINF;
  vector<T> dat;
  vector<E> laz;

  UpdateMax_LazySegmentTree(const vector<E> &v) { build(v); }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }

  void build(const vector<E> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }

  inline void propagate(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }

  inline void thrust(int k) {
    for (int i = height; i; i--) propagate(k >> i);
  }

  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }

  void update(int a, int b, E x) {
    if (a >= b) return;
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }

  T query(int a, int b) {
    if (a >= b) return ti;
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/range-update-range-max-lazyseg.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

