#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Val, int S = 2000000>
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
    Val val;
    uint32_t cnt;
  };

  NodePtr t;
  static Node *pool;
  static int ptr;
  static NodePtr buf[128];

  OrderedMap() : t(0) {
    if (!pool) {
      pool = new Node[S + 10];
      pool[0].l = pool[0].r = pool[0].cnt = 0;
    }
  }

  NodePtr my_new(const Key &k, const Val &v) {
    pool[ptr].l = pool[ptr].r = 0;
    pool[ptr].key = k;
    pool[ptr].val = v;
    pool[ptr].cnt = 1;
    return ptr++;
  }

  NodePtr merge(NodePtr l, NodePtr r) {
    if (!l || !r) return l ? l : r;
    NodePtr res;
    NodePtr *pre = &res;
    while (true) {
      if (!l || !r) {
        *pre = l ? l : r;
        break;
      }
      uint32_t s = pool[l].cnt + pool[r].cnt;
      if (uint32_t((rng() * s) >> 32) < pool[l].cnt) {
        *pre = l;
        pool[l].cnt = s + 1;
        pre = &(pool[l].r);
        l = pool[l].r;
      } else {
        *pre = r;
        pool[r].cnt = s + 1;
        pre = &(pool[r].l);
        r = pool[r].l;
      }
    }
    return res;
  }

  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x, int i = -1) {
    if (i == -1) {
      i = 0;
      while (t) {
        buf[i++] = t;
        t = x <= pool[t].key ? pool[t].l : pool[t].r;
      }
    }
    NodePtr l = 0, r = 0;
    uint32_t pre = 0;
    while (i--) {
      NodePtr t = buf[i];
      if (x <= pool[t].key) {
        pool[t].l = r;
        pool[t].cnt = (pre += pool[pool[t].r].cnt + 1);
        r = t;
      } else {
        pool[t].r = l;
        pool[t].cnt = (pre += pool[pool[t].l].cnt + 1);
        l = t;
      }
    }
    return {l, r};
  }

  NodePtr _find(const Key &x) const {
    NodePtr p = t;
    while (p) {
      if (x == pool[p].key) return p;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    return 0;
  }

  Val &operator[](const Key &x) {
    NodePtr p = _find(x);
    if (p) return pool[p].val;
    NodePtr l, r;
    tie(l, r) = split(t, x);
    NodePtr n = my_new(x, Val());
    t = merge(merge(l, n), r);
    return pool[n].val;
  }

  void insert(const Key &x, const Val &y) {
    NodePtr p = t;
    int i = 0;
    while (p) {
      if (pool[p].key == x) {
        pool[p].val = y;
        return;
      }
      buf[i++] = p;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    NodePtr l, r;
    tie(l, r) = split(t, x, i);
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

  int size() { return pool[t].cnt; }
};
template <typename Key, typename Val, int S>
typename OrderedMap<Key, Val, S>::Node *OrderedMap<Key, Val, S>::pool = nullptr;
template <typename Key, typename Val, int S>
int OrderedMap<Key, Val, S>::ptr = 1;
template <typename Key, typename Val, int S>
typename OrderedMap<Key, Val, S>::NodePtr OrderedMap<Key, Val, S>::buf[128] =
    {};
