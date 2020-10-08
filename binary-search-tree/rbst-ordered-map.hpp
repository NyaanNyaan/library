#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Val, int S = 2000000, bool MULTI = false>
struct OrderedMap {
  struct RandomizedBinarySearchTree {
    uint64_t rng() {
      static uint64_t x_ = 88172645463325252ULL;
      x_ = x_ ^ (x_ << 7);
      x_ = x_ ^ (x_ >> 9);
      return x_ & 0xFFFFFFFFull;
    }

    struct Node {
      Node *l, *r;
      Key key;
      Val val;
      int cnt;

      Node() {}

      Node(const Key &k, const Val &v)
          : l(nullptr), r(nullptr), key(k), val(v), cnt(1) {}
    };

    vector<Node> pool;
    int ptr;

    RandomizedBinarySearchTree(int pool_size = 2000000)
        : pool(pool_size), ptr(0) {}

    Node *my_new(const Key &k, const Val &v) {
      return &(pool[ptr++] = Node(k, v));
    }

    inline int count(const Node *t) { return t ? t->cnt : 0; }

    inline Node *update(Node *t) {
      t->cnt = count(t->l) + count(t->r) + 1;
      return t;
    }

    Node *merge(Node *l, Node *r) {
      if (!l || !r) return l ? l : r;

      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
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

    void insert(Node *&t, int k, const Key &key, const Val &val) {
      auto x = split(t, k);
      t = merge(merge(x.first, my_new(key, val)), x.second);
    }

    void erase(Node *&t, int k) {
      auto x = split(t, k);
      t = merge(x.first, split(x.second, 1).second);
    }

    int size(Node *t) { return count(t); }

    Node *make() { return nullptr; }
  };

  using T = pair<Key, Val>;
  using F = function<T(T, T)>;
  using RBST = RandomizedBinarySearchTree;
  using Node = typename RBST::Node;

  static RBST *rbst;
  Node *t;

  OrderedMap() {
    if (!rbst) rbst = new RBST(S);
    t = rbst->make();
  }

  pair<Node *, Node *> split(Node *t, const Key &x) {
    if (!t) return {nullptr, nullptr};
    if (x <= t->key) {
      auto s = split(t->l, x);
      t->l = s.second;
      return {s.first, rbst->update(t)};
    } else {
      auto s = split(t->r, x);
      t->r = s.first;
      return {rbst->update(t), s.second};
    }
  }

  Node *_find(const Key &x) {
    Node *p = t;
    while (p) {
      if (x == p->key) return p;
      p = x < p->key ? p->l : p->r;
    }
    return nullptr;
  }

  Val &operator[](const Key &x) {
    Node *p = _find(x);
    if (p) return p->val;
    insert(x, Val());
    return _find(x)->val;
  }

  void insert(const Key &x, const Val &y) {
    Node *p = _find(x);
    if (p) {
      p->val = y;
      return;
    }
    Node *l, *r;
    tie(l, r) = split(t, x);
    t = rbst->merge(rbst->merge(l, rbst->my_new(x, y)), r);
  }

  Val get(const Key &x) const {
    Node *p = t;
    while (p) {
      if (x == p->key) return p->val;
      p = x < p->key ? p->l : p->r;
    }
    return Val();
  }

  int size() { return rbst->count(t); }
};
template <typename Key, typename Val, int S, bool MULTI>
typename OrderedMap<Key, Val, S, MULTI>::RBST
    *OrderedMap<Key, Val, S, MULTI>::rbst = nullptr;
