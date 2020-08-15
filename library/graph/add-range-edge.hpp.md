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


# :warning: graph/add-range-edge.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/add-range-edge.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 17:28:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// do not forget setting graph_size !!
struct RangeEdges {
  int N, idx;

 private:
  int graph_size_;

 public:
  RangeEdges(int n, int q) {
    N = 1;
    while (N < n) N *= 2;
    graph_size_ = N * 3 + q * __builtin_ctz(N) + 10;
    idx = 3 * N;
  };

  int graph_size() const { return graph_size_; }

  template <typename F>
  void build(const F& add_edge) {
    for (int i = 0; i < N; i++) {
      if (i) {
        add_edge(N + i, N + (i >> 1) + 0);
        add_edge(N + i, N + (i >> 1) + 1);
        add_edge((N << 1) + (i >> 1) + 0, (N << 1) + i);
        add_edge((N << 1) + (i >> 1) + 1, (N << 1) + i);
      }
      add_edge(i + N, i);
      add_edge(i, i + (N << 1));
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename F>
  void range_add(const F& add_edge, int fl, int fr, int tl, int tr) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++));
      if (fr & 1) add_edge(fn, N + (--fr));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn);
      if (tr & 1) add_edge((--tr) + (N << 1), tn);
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename C, typename F>
  void weighted_range_add(const F& add_edge, int fl, int fr, int tl, int tr,
                          C cost) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn, cost);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++), C(0));
      if (fr & 1) add_edge(fn, N + (--fr), C(0));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn, C(0));
      if (tr & 1) add_edge((--tr) + (N << 1), tn, C(0));
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/add-range-edge.hpp"
#include <bits/stdc++.h>
using namespace std;

// do not forget setting graph_size !!
struct RangeEdges {
  int N, idx;

 private:
  int graph_size_;

 public:
  RangeEdges(int n, int q) {
    N = 1;
    while (N < n) N *= 2;
    graph_size_ = N * 3 + q * __builtin_ctz(N) + 10;
    idx = 3 * N;
  };

  int graph_size() const { return graph_size_; }

  template <typename F>
  void build(const F& add_edge) {
    for (int i = 0; i < N; i++) {
      if (i) {
        add_edge(N + i, N + (i >> 1) + 0);
        add_edge(N + i, N + (i >> 1) + 1);
        add_edge((N << 1) + (i >> 1) + 0, (N << 1) + i);
        add_edge((N << 1) + (i >> 1) + 1, (N << 1) + i);
      }
      add_edge(i + N, i);
      add_edge(i, i + (N << 1));
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename F>
  void range_add(const F& add_edge, int fl, int fr, int tl, int tr) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++));
      if (fr & 1) add_edge(fn, N + (--fr));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn);
      if (tr & 1) add_edge((--tr) + (N << 1), tn);
    }
  }

  // from [fl, fr) to [to, tr)
  template <typename C, typename F>
  void weighted_range_add(const F& add_edge, int fl, int fr, int tl, int tr,
                          C cost) {
    int fn = idx++;
    int tn = idx++;
    add_edge(tn, fn, cost);
    for (fl += N, fr += N; fl < fr; fl >>= 1, fr >>= 1) {
      if (fl & 1) add_edge(fn, N + (fl++), C(0));
      if (fr & 1) add_edge(fn, N + (--fr), C(0));
    }
    for (tl += N, tr += N; tl < tr; tl >>= 1, tr >>= 1) {
      if (tl & 1) add_edge((tl++) + (N << 1), tn, C(0));
      if (tr & 1) add_edge((--tr) + (N << 1), tn, C(0));
    }
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

