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


# :x: data-structure/rectangle-sum.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/rectangle-sum.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 03:32:31+09:00




## Depends on

* :question: <a href="../competitive-template.hpp.html">competitive-template.hpp</a>
* :x: <a href="../segment-tree/persistent-segment-tree.hpp.html">segment-tree/persistent-segment-tree.hpp</a>


## Verified with

* :x: <a href="../../verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html">verify-yosupo-ds/yosupo-rectangle-sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

#include "../segment-tree/persistent-segment-tree.hpp"

template <typename T, typename U, typename F>
struct RectangleSum {
  PersistentSegmentTree<U, F> seg;
  vector<T> xs, ys;
  vector<U> ws;
  vector<int> ord;

  RectangleSum(const vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,
               const F &f)
      : seg({(int)xs_.size() + 1, f, U(0)}) {
    int N = xs_.size();
    xs.reserve(N);
    ys.reserve(N);
    ws.reserve(N);
    ord.resize(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return xs_[i] < xs_[j]; });
    for (auto &i : ord) {
      xs.push_back(xs_[i]);
      ys.push_back(ys_[i]);
      ws.push_back(ws_[i]);
    }
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i] < ys[j]; });
    vector<T> ys2;
    ys2.reserve(N);
    for (auto &i : ord) {
      seg.add(i, ws[i]);
      ys2.push_back(ys[i]);
    }
    ys.swap(ys2);
  }

  // [ [x1, 0], [x2, y] )
  U rect_sum(T x1, T x2, T y) {
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int u = lower_bound(begin(ys), end(ys), y) - begin(ys);
    return seg.query(u, l, r);
  }

  // [ [x1, y1], [x2, y2] )
  U rect_sum(T x1, T y1, T x2, T y2) {
    if (x1 >= x2 || y1 >= y2) return U(0);
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int d = lower_bound(begin(ys), end(ys), y1) - begin(ys);
    int u = lower_bound(begin(ys), end(ys), y2) - begin(ys);
    return seg.query(u, l, r) - seg.query(d, l, r);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/rectangle-sum.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

