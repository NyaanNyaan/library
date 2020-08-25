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


# :heavy_check_mark: data-structure/persistent-queue.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/persistent-queue.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 12:15:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp.html">verify/verify-yosupo-ds/yosupo-persistent-queue.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct PersistentQueue {
  struct Node {
    int d;
    T val;
    vector<Node*> par;
    Node(int d_) : d(d_) {}
    Node(int d_, const T& val_, Node* n) : d(d_), val(val_), par({n}) {}
  };

  using P = pair<Node*, Node*>;
  vector<P> roots;

  PersistentQueue() {
    Node* root = new Node(0);
    roots.emplace_back(root, root);
  }

  int push(const T& val, int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ne = new Node(e->d + 1, val, e);
    roots.emplace_back(s, ne);
    for (int i = 0;; i++) {
      if ((int)e->par.size() <= i) break;
      Node* nxt = e->par[i];
      ne->par.push_back(e = nxt);
    }
    return (int)roots.size() - 1;
  }

  pair<T, int> pop(int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ns = e;
    for (int x = e->d - s->d - 1; x;) {
      int d = __builtin_ctz(x);
      ns = ns->par[d];
      x -= 1 << d;
    }
    roots.emplace_back(ns, e);
    return make_pair(ns->val, (int)roots.size() - 1);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/persistent-queue.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct PersistentQueue {
  struct Node {
    int d;
    T val;
    vector<Node*> par;
    Node(int d_) : d(d_) {}
    Node(int d_, const T& val_, Node* n) : d(d_), val(val_), par({n}) {}
  };

  using P = pair<Node*, Node*>;
  vector<P> roots;

  PersistentQueue() {
    Node* root = new Node(0);
    roots.emplace_back(root, root);
  }

  int push(const T& val, int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ne = new Node(e->d + 1, val, e);
    roots.emplace_back(s, ne);
    for (int i = 0;; i++) {
      if ((int)e->par.size() <= i) break;
      Node* nxt = e->par[i];
      ne->par.push_back(e = nxt);
    }
    return (int)roots.size() - 1;
  }

  pair<T, int> pop(int id = -1) {
    Node *s, *e;
    tie(s, e) = id == -1 ? roots.back() : roots[id];
    Node* ns = e;
    for (int x = e->d - s->d - 1; x;) {
      int d = __builtin_ctz(x);
      ns = ns->par[d];
      x -= 1 << d;
    }
    roots.emplace_back(ns, e);
    return make_pair(ns->val, (int)roots.size() - 1);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

