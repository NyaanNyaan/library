#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../misc/vector-pool.hpp"

template <typename Key, typename Val>
struct OrderedMap {
  uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    x_ = x_ ^ (x_ >> 9);
    return x_ & 0xFFFFFFFFull;
  }

  using NodePtr = uint32_t;
  struct Node {
    NodePtr l, r;
    Key key;
    Val val, sum;
    int cnt;
    Node() {}
    Node(const Key &k, const Val &v)
        : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}
  };

  static VectorPool<Node> init_pool() {
    VectorPool<Node> pool;
    pool[0].l = pool[0].r = pool[0].cnt = 0;
    pool[0].key = Key();
    pool[0].val = Val();
    return pool;
  }

  static VectorPool<Node> pool;
  using F = function<Val(Val, Val)>;
  const F f;
  NodePtr t;

  OrderedMap() : f([](Val, Val) { return Val(); }), t(0) {}
  OrderedMap(const F _f) : f(_f), t(0) {}

  NodePtr my_new(const Key &k, const Val &v) { return pool.my_new(k, v); }

  void my_delete(NodePtr t) { pool.free(t); }

  inline NodePtr update(NodePtr t) {
    pool[t].cnt = pool[pool[t].l].cnt + pool[pool[t].r].cnt + 1;
    pool[t].sum = f(f(pool[pool[t].l].sum, pool[t].val), pool[pool[t].r].sum);
    return t;
  }

  NodePtr merge(NodePtr l, NodePtr r) {
    if (!l || !r) return l ? l : r;
    if (int((rng() * (pool[l].cnt + pool[r].cnt)) >> 32) < pool[l].cnt) {
      pool[l].r = merge(pool[l].r, r);
      return update(l);
    } else {
      pool[r].l = merge(l, pool[r].l);
      return update(r);
    }
  }

  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {
    if (!t) return {0, 0};
    if (x <= pool[t].key) {
      auto s = split(pool[t].l, x);
      pool[t].l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(pool[t].r, x);
      pool[t].r = s.first;
      return {update(t), s.second};
    }
  }

  NodePtr find_ptr(const Key &x) const {
    NodePtr p = t;
    while (p) {
      if (x == pool[p].key) return p;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    return 0;
  }

  Val &operator[](const Key &x) {
    NodePtr p = find_ptr(x);
    if (p) return pool[p].val;
    NodePtr l, r;
    tie(l, r) = split(t, x);
    NodePtr n = my_new(x, Val());
    t = merge(merge(l, n), r);
    return pool[n].val;
  }

  void insert(const Key &x, const Val &y) {
    NodePtr p = find_ptr(x);
    if (p) {
      pool[p].val = y;
      return;
    }
    NodePtr l, r;
    tie(l, r) = split(t, x);
    t = merge(merge(l, my_new(x, y)), r);
  }

  Val get(const Key &x) const {
    NodePtr p = t;
    while (p) {
      if (x == pool[p].key) return pool[p].val;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    return Val();
  }
};

template <typename Key, typename Val>
VectorPool<typename OrderedMap<Key, Val>::Node> OrderedMap<Key, Val>::pool =
    OrderedMap<Key, Val>::init_pool();