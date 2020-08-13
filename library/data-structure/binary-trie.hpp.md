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


# :heavy_check_mark: Binary Trie <small>(data-structure/binary-trie.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/binary-trie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 00:07:06+09:00




## Binary Trie

トライ木の辺に対応する文字を0/1に限定することで非負整数を管理できるようにしたデータ構造。

挿入される値の最大値のビット長さを$w$としたとき、値の挿入・削除・検索などを$\mathrm{O}(w)$で行える。また、全体にXORを掛ける操作が$\mathrm{O}(1)$で出来るのが大きな特徴である。

永続化しやすいようにポインタ木で実装してある(が、永続化はしていない。)

#### 使い方
整数のインデックスが必要な場合は引数`id`にインデックスを入れるとよい。
- `add(x, id)`: xを追加する
- `del(x, id)`: xを削除する
- `find(x)` : xが存在するか調べる。返り値はpair(個数,インデックスの集合)
- `max_element()/min_element()` : 最大値/最小値を返す。返り値はpair(最大値/最小値,インデックスの集合)
- `get_kth()` : k番目の値を返す。返り値はpair(値,インデックスの集合)
- `operate_xor(x)` : 集合全体にxorを作用させる。


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp.html">verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, int MAX_LOG, int NODES = 16777216>
struct BinaryTrie {
  using Container = vector<int>;
  struct Node {
    Node *nxt[2];
    int exist;
    Container accept;
    Node() {}
  };

  Node *pool;
  int pid;
  T lazy;
  Node *nil;
  Node *root;

  BinaryTrie() : pid(0), lazy(T(0)), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new();
    nil->nxt[0] = nil->nxt[1] = root = nil;
  }

  Node *my_new(int exist_ = 0, int id = -1) {
    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;
    pool[pid].exist = exist_;
    if (id != -1) pool[pid].accept.push_back(id);
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].nxt[0] = l;
    pool[pid].nxt[1] = r;
    pool[pid].exist = l->exist + r->exist;
    return &(pool[pid++]);
  }

 private:
  Node *add_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      if (n == nil) return my_new(1, id);
      n->exist++;
      n->accept.push_back(id);
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); }

 private:
  Node *del_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      n->exist--;
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void del(const T &x, int id = -1) { root = del_(x, id, root, MAX_LOG); }

 private:
  pair<int, Container &> find_(const T &x, Node *n, int bit_idx) {
    if (bit_idx == -1)
      return pair<int, Container &>(n->exist, n->accept);
    else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return find_(x, n->nxt[0], bit_idx - 1);
      else
        return find_(x, n->nxt[1], bit_idx - 1);
    }
  }

 public:
  pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG); }

 private:
  pair<T, Container &> max_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {
      auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> max_element() { return max_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> min_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {
      return min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    } else {
      auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    }
  }

 public:
  pair<T, Container &> min_element() { return min_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> get_kth_(Node *n, int64_t k, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;
    if (ex0 < k) {
      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0, bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }

  void operate_xor(T x) { lazy ^= x; }
};

/**
 * @brief Binary Trie
 * @docs docs/binary-trie.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/binary-trie.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T, int MAX_LOG, int NODES = 16777216>
struct BinaryTrie {
  using Container = vector<int>;
  struct Node {
    Node *nxt[2];
    int exist;
    Container accept;
    Node() {}
  };

  Node *pool;
  int pid;
  T lazy;
  Node *nil;
  Node *root;

  BinaryTrie() : pid(0), lazy(T(0)), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new();
    nil->nxt[0] = nil->nxt[1] = root = nil;
  }

  Node *my_new(int exist_ = 0, int id = -1) {
    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;
    pool[pid].exist = exist_;
    if (id != -1) pool[pid].accept.push_back(id);
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].nxt[0] = l;
    pool[pid].nxt[1] = r;
    pool[pid].exist = l->exist + r->exist;
    return &(pool[pid++]);
  }

 private:
  Node *add_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      if (n == nil) return my_new(1, id);
      n->exist++;
      n->accept.push_back(id);
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); }

 private:
  Node *del_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      n->exist--;
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void del(const T &x, int id = -1) { root = del_(x, id, root, MAX_LOG); }

 private:
  pair<int, Container &> find_(const T &x, Node *n, int bit_idx) {
    if (bit_idx == -1)
      return pair<int, Container &>(n->exist, n->accept);
    else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return find_(x, n->nxt[0], bit_idx - 1);
      else
        return find_(x, n->nxt[1], bit_idx - 1);
    }
  }

 public:
  pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG); }

 private:
  pair<T, Container &> max_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {
      auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> max_element() { return max_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> min_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {
      return min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    } else {
      auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    }
  }

 public:
  pair<T, Container &> min_element() { return min_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> get_kth_(Node *n, int64_t k, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;
    if (ex0 < k) {
      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0, bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }

  void operate_xor(T x) { lazy ^= x; }
};

/**
 * @brief Binary Trie
 * @docs docs/binary-trie.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

