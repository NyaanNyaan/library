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


# :heavy_check_mark: data-structure/rectangle-sum.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/rectangle-sum.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 12:40:30+09:00




## Depends on

* :heavy_check_mark: <a href="../segment-tree/persistent-segment-tree.hpp.html">永続セグメント木 <small>(segment-tree/persistent-segment-tree.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

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
#line 2 "data-structure/rectangle-sum.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "segment-tree/persistent-segment-tree.hpp"
using namespace std;

template <typename T, typename F, int NODES = 20000000>
struct PersistentSegmentTree {
  using ll = long long;
  struct Node {
    T data;
    Node *l, *r;
    Node() {}
    Node(const T &_data) : data(_data), l(nullptr), r(nullptr) {}
  };

  Node *pool;
  int pid;
  ll N;
  const F f;
  const T ID;
  Node *nil;
  vector<Node *> roots;

  PersistentSegmentTree(const vector<T> &v, const F &f_, const T &ID_)
      : pid(0), f(f_), ID(ID_), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new(ID);
    nil->l = nil->r = nil;
    roots.reserve(262144);
    roots.push_back(build(v));
  }

  PersistentSegmentTree(const ll &N_, const F &f_, const T &ID_)
      : pid(0), N(N_), f(f_), ID(ID_), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new(ID);
    nil->l = nil->r = nil;
    roots.reserve(262144);
    roots.push_back(nil);
  }

  Node *my_new(const T &data) {
    pool[pid].data = data;
    pool[pid].l = pool[pid].r = nil;
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].data = f(l->data, r->data);
    pool[pid].l = l;
    pool[pid].r = r;
    return &(pool[pid++]);
  }

  Node *build(const vector<T> &v) {
    N = (ll)v.size();
    return build(0, (ll)v.size(), v);
  }

  Node *build(ll l, ll r, const vector<T> &v) {
    if (l + 1 == r) return my_new(v[l]);
    ll m = (l + r) >> 1;
    return merge(build(l, m, v), build(m, r, v));
  }

 private:
  Node *update_(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(x);
    ll m = (l + r) >> 1;
    if (a < m) return merge(update_(a, x, n->l, l, m), n->r);
    return merge(n->l, update_(a, x, n->r, m, r));
  }
  Node *add_(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(f(x, n->data));
    ll m = (l + r) >> 1;
    if (a < m) return merge(add_(a, x, n->l, l, m), n->r);
    return merge(n->l, add_(a, x, n->r, m, r));
  }
  T query_(ll a, ll b, Node *n, ll l, ll r) {
    if (n == nil) return ID;
    if (r <= a or b <= l) return ID;
    if (a <= l and r <= b) return n->data;
    ll m = (l + r) >> 1;
    return f(query_(a, b, n->l, l, m), query_(a, b, n->r, m, r));
  }

 public:
  Node *update(Node *n, ll k, const T &x) {
    Node *root = update_(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(int t, ll k, const T &x) {
    Node *root = update_(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(ll k, const T &x) {
    Node *root = update_(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  Node *add(Node *n, ll k, const T &x) {
    Node *root = add_(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(int t, ll k, const T &x) {
    Node *root = add_(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(ll k, const T &x) {
    Node *root = add_(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  T query(Node *n, ll a, ll b) { return query_(a, b, n, 0, N); }
  T query(int t, ll a, ll b) { return query_(a, b, roots[t], 0, N); }
  T query(ll a, ll b) { return query_(a, b, roots.back(), 0, N); }

  Node *new_tree() { return nil; }
};

/**
 * @brief 永続セグメント木
 * @docs docs/segment-tree/persistent-segtree.md
 */
#line 6 "data-structure/rectangle-sum.hpp"

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

<a href="../../index.html">Back to top page</a>
