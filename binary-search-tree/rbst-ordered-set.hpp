#pragma once
#include "./randomized-binary-search-tree.hpp"

template <typename T, int S = 2000000, bool MULTI = false>
struct OrderedSet {
  using RBST = RandomizedBinarySearchTree<T>;
  using Node = typename RBST::Node;

  static RBST* rbst;
  Node* t;

  OrderedSet() {
    if (!rbst) rbst = new RBST([](T x, T y) { return x; }, T(), S);
    t = rbst->make();
  }

  T kth_element(int k) {
    Node* p = t;
    int l;
    while (k != (l = rbst->count(p->l))) {
      if (k < l) {
        p = p->l;
      } else {
        p = p->r;
        k -= l + 1;
      }
    }
    return p->key;
  }

  void insert(const T& x) {
    int l = lower_bound(x);
    int r = upper_bound(x);
    if (!MULTI and l != r) return;
    rbst->insert(t, l, x);
  }

  void erase(const T& x) {
    int l = lower_bound(x);
    int r = upper_bound(x);
    if (l == r) return;
    rbst->erase(t, l);
  }

  int count(const T& x) { return upper_bound(t, x) - lower_bound(t, x); }

  int lower_bound(const T& x) {
    Node* p = t;
    int ret = 0;
    while (p) {
      if (x <= p->key) {
        p = p->l;
      } else {
        ret += p->count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int upper_bound(const T& x) {
    Node* p = t;
    int ret = 0;
    while (p) {
      if (x < p->key) {
        p = p->l;
      } else {
        ret += p->count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }
};
template <typename T, int S, bool MULTI>
typename OrderedSet<T, S, MULTI>::RBST* rbst = nullptr;