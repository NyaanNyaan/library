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


# :warning: data-structure/randomized-binary-search-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/randomized-binary-search-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 00:26:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
struct RandomizedBinarySearchTree {
  unsigned long long rng() {
    static unsigned long long x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    return x_ = x_ ^ (x_ >> 9);
  }

  struct Node {
    Node *l, *r;
    int cnt;
    T key, sum;

    Node() {}

    Node(const T &k) : l(nullptr), r(nullptr), cnt(1), key(k), sum(k) {}
  };

  vector<Node> pool;
  int ptr;
  const F f;
  const T I;

  RandomizedBinarySearchTree(const F &f_, const T &I_, int pool_size = 2000000)
      : pool(pool_size), ptr(0), f(f_), I(I_) {}

  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k, I)); }

  inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline T sum(const Node *t) { return t ? t->sum : I; }

  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
  }

  Node *merge(Node *l, Node *r) {
    if (!l || !r) return l ? l : r;
    if (rng() % (l->cnt + r->cnt) < l->cnt) {
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Node *, Node *> split(Node *t, int k) {
    if (!t) return {nullptr, nullptr};
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Node *build(int l, int r, const vector<T> &v) {
    if (l + 1 >= r) return my_new(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *build(const vector<T> &v) {
    ptr = 0;
    return build(0, (int)v.size(), v);
  }

  void insert(Node *&t, int k, const T &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(v)), x.second);
  }

  void erase(Node *&t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

  T query(Node *&t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  int size(Node *t) { return count(t); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/randomized-binary-search-tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
struct RandomizedBinarySearchTree {
  unsigned long long rng() {
    static unsigned long long x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    return x_ = x_ ^ (x_ >> 9);
  }

  struct Node {
    Node *l, *r;
    int cnt;
    T key, sum;

    Node() {}

    Node(const T &k) : l(nullptr), r(nullptr), cnt(1), key(k), sum(k) {}
  };

  vector<Node> pool;
  int ptr;
  const F f;
  const T I;

  RandomizedBinarySearchTree(const F &f_, const T &I_, int pool_size = 2000000)
      : pool(pool_size), ptr(0), f(f_), I(I_) {}

  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k, I)); }

  inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline T sum(const Node *t) { return t ? t->sum : I; }

  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
  }

  Node *merge(Node *l, Node *r) {
    if (!l || !r) return l ? l : r;
    if (rng() % (l->cnt + r->cnt) < l->cnt) {
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Node *, Node *> split(Node *t, int k) {
    if (!t) return {nullptr, nullptr};
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Node *build(int l, int r, const vector<T> &v) {
    if (l + 1 >= r) return my_new(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *build(const vector<T> &v) {
    ptr = 0;
    return build(0, (int)v.size(), v);
  }

  void insert(Node *&t, int k, const T &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(v)), x.second);
  }

  void erase(Node *&t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

  T query(Node *&t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  int size(Node *t) { return count(t); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

