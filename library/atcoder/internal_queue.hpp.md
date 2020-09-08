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


# :heavy_check_mark: atcoder/internal_queue.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#554e0d24f25abaa0e2922c944fbc560c">atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/atcoder/internal_queue.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 18:51:36+09:00




## Required by

* :heavy_check_mark: <a href="maxflow.hpp.html">atcoder/maxflow.hpp</a>
* :heavy_check_mark: <a href="../flow/flow-on-bipartite-graph.hpp.html">flow/flow-on-bipartite-graph.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp.html">verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

namespace atcoder {

namespace internal {

template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T& t) { payload.push_back(t); }
  T& front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "atcoder/internal_queue.hpp"
#include <vector>

namespace atcoder {

namespace internal {

template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T& t) { payload.push_back(t); }
  T& front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

