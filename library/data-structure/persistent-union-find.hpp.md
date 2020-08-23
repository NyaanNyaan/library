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


# :heavy_check_mark: 完全永続Union-Find <small>(data-structure/persistent-union-find.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/persistent-union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 22:52:35+09:00




## Depends on

* :heavy_check_mark: <a href="persistent-array.hpp.html">永続配列 <small>(data-structure/persistent-array.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp.html">verify/verify-yosupo-ds/yosupo-persistent-unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./persistent-array.hpp"

struct PersistentUnionFind {
  PersistentArray<int> arr;
  using Node = decltype(arr)::Node;
  static Node *root;

  PersistentUnionFind(int N) : arr(vector<int>(N, -1)) { root = arr.root; }

  pair<int, int> find_with_size(int i, Node *r = root) {
    int n = arr.get(r, i);
    return n < 0 ? pair<int, int>{i, n} : find_with_size(n, r);
  }
  inline int find(int i, Node *r = root) { return find_with_size(i, r).first; }
  inline int size(int i, Node *r = root) { return -(find_with_size(i, r).second); }
  inline int same(int i, int j, Node *r = root) { return find(i, r) == find(j, r); }

  int unite(int i, int j, Node *r = root) {
    int is, js;
    tie(i, is) = find_with_size(i, r);
    tie(j, js) = find_with_size(j, r);
    if (i == j) return false;
    if (is > js) swap(i, j), swap(is, js);
    r = arr.update(r, i, is + js);
    r = arr.update(r, j, i);
    root = r;
    return true;
  }

  Node *get_root() const { return root; }
};
typename PersistentUnionFind::Node *PersistentUnionFind::root = nullptr;

/**
 * @brief 完全永続Union-Find
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/persistent-union-find.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "data-structure/persistent-array.hpp"
using namespace std;

template <typename T, int shift = 4>
struct PersistentArray {
  struct Node {
    Node *ns[1 << shift];
    Node() { memset(ns, 0, sizeof(ns)); }
    Node(const Node &other) { memcpy(ns, other.ns, sizeof(ns)); }
    Node(const Node *other) { memcpy(ns, other->ns, sizeof(ns)); }
  };
  inline Node *my_new() { return new Node(); }
  inline Node *my_new(const Node &other) { return new Node(other); }
  inline Node *my_new(const Node *other) { return new Node(other); }
  inline T *my_new_leaf(const T &val) { return new T{val}; }

  using i64 = long long;
  static constexpr int mask = (1 << shift) - 1;
  Node *root;
  int depth;
  T ID;

  PersistentArray() {}

  PersistentArray(i64 MAX, T ID_ = T(0)) : root(my_new()), depth(0), ID(ID_) {
    while (MAX) ++depth, MAX >>= shift;
  }

  PersistentArray(const vector<T> &v, T ID_ = T(0))
      : root(my_new()), depth(0), ID(ID_) {
    i64 MAX = v.size();
    while (MAX) ++depth, MAX >>= shift;
    for (int i = 0; i < (int)v.size(); i++) {
      Node *n = root;
      for (int k = i, d = depth; d; d--) {
        if (!(n->ns[k & mask])) {
          if (d == 1)
            n->ns[k & mask] = reinterpret_cast<Node *>(my_new_leaf(v[i]));
          else
            n->ns[k & mask] = my_new();
        }
        n = n->ns[k & mask];
        k >>= shift;
      }
    }
  }

  T get(Node *n, i64 k) const {
    for (int i = depth; i; --i) {
      n = n ? n->ns[k & mask] : nullptr;
      k >>= shift;
    }
    return n ? *reinterpret_cast<T *>(n) : ID;
  }
  T get(i64 k) const { return get(root, k); }

  Node *update(Node *n, i64 k, const T &val) {
    stack<pair<Node *, int>> st;
    for (int i = depth; i; --i) {
      st.emplace(n, k & mask);
      n = n ? n->ns[k & mask] : nullptr;
      k >>= shift;
    }
    Node *chd = reinterpret_cast<Node *>(my_new_leaf(val));
    while (!st.empty()) {
      Node *par;
      int k;
      tie(par, k) = st.top();
      st.pop();
      Node *nxt = par ? my_new(par) : my_new();
      nxt->ns[k] = chd;
      chd = nxt;
    }
    return root = chd;
  }
  Node *update(i64 k, const T &val) { return update(root, k, val); }
};

/**
 * @brief 永続配列
 */
#line 6 "data-structure/persistent-union-find.hpp"

struct PersistentUnionFind {
  PersistentArray<int> arr;
  using Node = decltype(arr)::Node;
  static Node *root;

  PersistentUnionFind(int N) : arr(vector<int>(N, -1)) { root = arr.root; }

  pair<int, int> find_with_size(int i, Node *r = root) {
    int n = arr.get(r, i);
    return n < 0 ? pair<int, int>{i, n} : find_with_size(n, r);
  }
  inline int find(int i, Node *r = root) { return find_with_size(i, r).first; }
  inline int size(int i, Node *r = root) { return -(find_with_size(i, r).second); }
  inline int same(int i, int j, Node *r = root) { return find(i, r) == find(j, r); }

  int unite(int i, int j, Node *r = root) {
    int is, js;
    tie(i, is) = find_with_size(i, r);
    tie(j, js) = find_with_size(j, r);
    if (i == j) return false;
    if (is > js) swap(i, j), swap(is, js);
    r = arr.update(r, i, is + js);
    r = arr.update(r, j, i);
    root = r;
    return true;
  }

  Node *get_root() const { return root; }
};
typename PersistentUnionFind::Node *PersistentUnionFind::root = nullptr;

/**
 * @brief 完全永続Union-Find
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

