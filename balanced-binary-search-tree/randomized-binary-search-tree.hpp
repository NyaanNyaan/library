#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F>
struct RandomizedBinarySearchTree {
  uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    x_ = x_ ^ (x_ >> 9);
    return x_ & 0xFFFFFFFFull;
  }

  struct Node {
    Node *l, *r;
    T key, sum;
    int cnt;

    Node() {}

    Node(const T &k) : l(nullptr), r(nullptr), key(k), sum(k), cnt(1) {}
  };

  vector<Node> pool;
  int ptr;
  const F f;
  const T I;

  RandomizedBinarySearchTree(const F &f_, const T &I_, int pool_size = 2000000)
      : pool(pool_size), ptr(0), f(f_), I(I_) {}

  Node *my_new(const T &k) { return &(pool[ptr++] = Node(k)); }

  inline int count(const Node *t){ return t ? t->cnt : 0; }

  inline T sum(const Node *t) { return t ? t->sum : I; }

  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
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

  Node *build(int l, int r, const vector<T> &v) {
    if (l + 1 >= r) return my_new(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *build(const vector<T> &v) {
    ptr = 0;
    return build(0, (int)v.size(), v);
  }

  void insert(Node *&t, int k, const T &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(v)), x.second);
  }

  void erase(Node *&t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

  T query(Node *&t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  int size(Node *t) { return count(t); }

  Node *make() { return nullptr; }
};
