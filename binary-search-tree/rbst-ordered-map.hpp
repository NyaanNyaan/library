#pragma once
#include "./randomized-binary-search-tree.hpp"

template <typename Key, typename Val, int S = 2000000, bool MULTI = false>
struct OrderedMap {
  using T = pair<Key, Val>;
  using F = function<T(T, T)>;
  using RBST = RandomizedBinarySearchTree<T, F>;
  using Node = typename RBST::Node;

  static RBST* rbst;
  Node* t;

  OrderedMap() {
    if (!rbst) rbst = new RBST([](T, T) { return T(); }, T(), S);
    t = rbst->make();
  }

  Val& operator[](const Key& x) {
    Node* p = t;
    int k = 0;

    while (p) {
      if (x == p->key.first) {
        return p->key.second;
      }
      if (x < p->key.first) {
        p = p->l;
      } else {
        k += rbst->count(p->l) + 1;
        p = p->r;
      }
    }

    rbst->insert(t, k, make_pair(x, Val()));
    return (*this)[x];
  }

  void insert(const Key& x, const Val& y) {
    Node* p = t;
    int k = 0;

    while (p) {
      if (x == p->key.first) {
        p->key.second = y;
        return;
      }
      if (x < p->key.first) {
        p = p->l;
      } else {
        k += rbst->count(p->l) + 1;
        p = p->r;
      }
    }

    rbst->insert(t, k, make_pair(x, y));
  }

  Val get(const Key& x) const {
    Node* p = t;
    while (p) {
      if (x == p->key.first) return p->key.second;
      p = x < p->key.first ? p->l : p->r;
    }
    return Val();
  }

  int size() { return rbst->count(t); }
};
template <typename Key, typename Val, int S, bool MULTI>
typename OrderedMap<Key, Val, S, MULTI>::RBST*
    OrderedMap<Key, Val, S, MULTI>::rbst = nullptr;
