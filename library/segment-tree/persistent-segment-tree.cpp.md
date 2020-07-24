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


# :warning: segment-tree/persistent-segment-tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/persistent-segment-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 15:38:36+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

// if you want to reserve memory at once,
// activate below line, and change type of pool properly.
// #define reserve_pool_at_once
template <typename T>
struct _Node {
  T data;
  _Node *l, *r;
  _Node() {}
  _Node(const T &_data) : data(_data), l(nullptr), r(nullptr) {}
};

#ifdef reserve_pool_at_once
_Node<int> pool[40000000];
#endif

template <typename T, typename F, int NODES = 8388608>
struct PersistentSegmentTree {
  using ll = long long;
  using Node = _Node<T>;

#ifndef reserve_pool_at_once
  Node *pool;
#endif
  int pid;
  ll N;
  const F &f;
  const T ID;
  Node *nil;
  vector<Node *> roots;

  PersistentSegmentTree(const vector<T> &v, const F &_f, const T &_ID)
      : pid(0), f(_f), ID(_ID), nil(nullptr) {
#ifndef reserve_pool_at_once
    pool = new Node[NODES];
#endif
    nil = my_new(ID);
    nil->l = nil->r = nil;
    roots.reserve(262144);
    roots.push_back(build(v));
  }

  PersistentSegmentTree(const ll &_N, const F &_f, const T &_ID)
      : pid(0), N(_N), f(_f), ID(_ID), nil(nullptr) {
#ifndef reserve_pool_at_once
    pool = new Node[NODES];
#endif
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

  Node *_update(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(x);
    ll m = (l + r) >> 1;
    if (a < m) return merge(_update(a, x, n->l, l, m), n->r);
    return merge(n->l, _update(a, x, n->r, m, r));
  }

  Node *update(Node *n, ll k, const T &x) {
    Node *root = _update(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(int t, ll k, const T &x) {
    Node *root = _update(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(ll k, const T &x) {
    Node *root = _update(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  Node *_add(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(f(x, n->data));
    ll m = (l + r) >> 1;
    if (a < m) return merge(_add(a, x, n->l, l, m), n->r);
    return merge(n->l, _add(a, x, n->r, m, r));
  }

  Node *add(Node *n, ll k, const T &x) {
    Node *root = _add(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(int t, ll k, const T &x) {
    Node *root = _add(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(ll k, const T &x) {
    Node *root = _add(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  T _query(ll a, ll b, Node *n, ll l, ll r) {
    if (n == nil) return ID;
    if (r <= a or b <= l) return ID;
    if (a <= l and r <= b) return n->data;
    ll m = (l + r) >> 1;
    return f(_query(a, b, n->l, l, m), _query(a, b, n->r, m, r));
  }

  T query(Node *n, ll a, ll b) { return _query(a, b, n, 0, N); }
  T query(int t, ll a, ll b) { return _query(a, b, roots[t], 0, N); }
  T query(ll a, ll b) { return _query(a, b, roots.back(), 0, N); }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/persistent-segment-tree.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

