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


# :heavy_check_mark: segment-tree/persistent-segment-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/persistent-segment-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :heavy_check_mark: <a href="../data-structure/rectangle-sum.hpp.html">data-structure/rectangle-sum.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp.html">verify-yosupo-ds/yosupo-rectangle-sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "segment-tree/persistent-segment-tree.hpp"
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

