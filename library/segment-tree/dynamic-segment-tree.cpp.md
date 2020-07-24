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


# :warning: segment-tree/dynamic-segment-tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/dynamic-segment-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




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

template <typename T, typename F, int NODES = 4194304>
struct DynamicSegmentTree {
  using ll = long long;

  struct Node {
    T data;
    Node *l, *r;
    Node() {}
    Node(const T &_data) : data(_data), l(nullptr), r(nullptr) {}
  };

  Node *pool;
  int pid;
  ll L, R;
  const F &f;
  const T ID;
  Node *root;

  DynamicSegmentTree(const vector<T> &v, const F &_f, const T &_ID)
      : pid(0), L(0), R((ll)v.size()), f(_f), ID(_ID) {
    pool = new Node[NODES];
    root = build(v);
  }

  DynamicSegmentTree(const ll &_L, const ll &_R, const F &_f, const T &_ID)
      : pid(0), L(_L), R(_R), f(_f), ID(_ID) {
    pool = new Node[NODES];
    root = my_new(ID);
  }

  Node *my_new(const T &data) {
    pool[pid].data = data;
    pool[pid].l = pool[pid].r = nullptr;
    return &(pool[pid++]);
  }

  Node *my_new(Node *l, Node *r) {
    pool[pid].data = f(l->data, r->data);
    pool[pid].l = l;
    pool[pid].r = r;
    return &(pool[pid++]);
  }

  Node *build(const vector<T> &v) { return build(L, R, v); }

  Node *build(ll l, ll r, const vector<T> &v) {
    if (l + 1 == r) return my_new(v[l]);
    ll m = (l + r) >> 1;
    return my_new(build(l, m, v), build(m, r, v));
  }

  void _update(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) {
      n->data = x;
      return;
    }
    ll m = (l + r) >> 1;
    if (a < m) {
      if (!n->l) n->l = my_new(ID);
      _update(a, x, n->l, l, m);
    } else {
      if (!n->r) n->r = my_new(ID);
      _update(a, x, n->r, m, r);
    }
    n->data = f(n->l ? (n->l)->data : ID, n->r ? (n->r)->data : ID);
  }

  void update(ll k, const T &x) { _update(k, x, root, L, R); }

  void add(ll k, const T &x) {
    Node *n = root;
    ll l = L, r = R;
    n->data = f(n->data, x);
    while (r - l > 1) {
      ll m = (l + r) >> 1;
      if (k < m) {
        if (!n->l) n->l = my_new(ID);
        n = n->l;
        r = m;
      } else {
        if (!n->r) n->r = my_new(ID);
        n = n->r;
        l = m;
      }
      n->data = f(n->data, x);
    }
  }

  T _query(ll a, ll b, Node *n, ll l, ll r) {
    if (r <= a or b <= l) return ID;
    if (a <= l and r <= b) return n->data;
    ll m = (l + r) >> 1;
    return f(n->l ? _query(a, b, n->l, l, m) : ID,
             n->r ? _query(a, b, n->r, m, r) : ID);
  }

  T query(ll a, ll b) { return _query(a, b, root, L, R); }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segment-tree/dynamic-segment-tree.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

