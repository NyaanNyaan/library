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


# :heavy_check_mark: data-structure/slide-window-aggregation.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/slide-window-aggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 17:31:00+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-swag.test.cpp.html">verify/verify-yosupo-ds/yosupo-swag.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
struct SlideWindowAggregation {
  stack<T> a0, a1;
  stack<T> r0, r1;
  F f;
  T I, f0, f1;

  SlideWindowAggregation(F f_, T I_) : f(f_), I(I_), f0(I_), f1(I_) {}

 private:
  void push_s0(const T &x) {
    a0.push(x);
    r0.push(f0 = f(x, f0));
  }
  void push_s1(const T &x) {
    a1.push(x);
    r1.push(f1 = f(f1, x));
  }
  void transfer() {
    while (!a1.empty()) {
      push_s0(a1.top());
      a1.pop();
    }
    while (!r1.empty()) r1.pop();
    f1 = I;
  }

 public:
  void push(const T &x) {
    if (a0.empty()) {
      push_s0(x);
      transfer();
    } else {
      push_s1(x);
    }
  }
  void pop() {
    if (a0.empty()) transfer();
    a0.pop();
    r0.pop();
    f0 = r0.empty() ? I : r0.top();
  }
  T query() { return f(f0, f1); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/slide-window-aggregation.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
struct SlideWindowAggregation {
  stack<T> a0, a1;
  stack<T> r0, r1;
  F f;
  T I, f0, f1;

  SlideWindowAggregation(F f_, T I_) : f(f_), I(I_), f0(I_), f1(I_) {}

 private:
  void push_s0(const T &x) {
    a0.push(x);
    r0.push(f0 = f(x, f0));
  }
  void push_s1(const T &x) {
    a1.push(x);
    r1.push(f1 = f(f1, x));
  }
  void transfer() {
    while (!a1.empty()) {
      push_s0(a1.top());
      a1.pop();
    }
    while (!r1.empty()) r1.pop();
    f1 = I;
  }

 public:
  void push(const T &x) {
    if (a0.empty()) {
      push_s0(x);
      transfer();
    } else {
      push_s1(x);
    }
  }
  void pop() {
    if (a0.empty()) transfer();
    a0.pop();
    r0.pop();
    f0 = r0.empty() ? I : r0.top();
  }
  T query() { return f(f0, f1); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

