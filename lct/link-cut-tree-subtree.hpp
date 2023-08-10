#pragma once

#include "reversible-bbst-base.hpp"
#include "splay-base.hpp"

template <typename T, T (*f)(T, T), T (*finv)(T, T)>
struct LinkCutForSubtreeNode {
  using Node = LinkCutForSubtreeNode;
  using Ptr = LinkCutForSubtreeNode*;
  Ptr l, r, p;
  T key, sum, sub;
  int cnt;
  bool rev;

  LinkCutForSubtreeNode(const T& t = T())
      : l(), r(), p(), key(t), sum(t), sub(T()), cnt(1), rev(false) {}
  void add(Node* other) { sub = f(sub, other->sum); }
  void erase(Node* other) { sub = finv(sub, other->sum); }
  void merge(Node* n1, Node* n2) {
    sum = f(f(n1 ? n1->sum : T(), key), f(sub, n2 ? n2->sum : T()));
  }
};

template <typename T, T (*f)(T, T), T (*finv)(T, T)>
struct SplayTreeForLCSubtree
    : ReversibleBBST<SplayTreeBase<LinkCutForSubtreeNode<T, f, finv>>,
                     LinkCutForSubtreeNode<T, f, finv>, T, nullptr, nullptr> {
  using Node = LinkCutForSubtreeNode<T, f, finv>;
};
//
#include "link-cut-base.hpp"

template <typename T, T (*f)(T, T), T (*finv)(T, T)>
struct LinkCutTreeSubtreeQuery
    : LinkCutBase<SplayTreeForLCSubtree<T, f, finv>> {
  using base = LinkCutBase<SplayTreeForLCSubtree<T, f, finv>>;
  using Node = typename base::Node;
  using Ptr = typename base::Ptr;

  Ptr expose(Ptr t) override {
    Ptr rp = nullptr;
    for (Ptr cur = t; cur; cur = cur->p) {
      this->splay(cur);
      if (cur->r) cur->add(cur->r);
      cur->r = rp;
      if (cur->r) cur->erase(cur->r);
      this->update(cur);
      rp = cur;
    }
    this->splay(t);
    return rp;
  }

  void link(Ptr u, Ptr v) override {
    this->evert(u);
    this->expose(v);
    u->p = v;
    v->add(u);
  }

  void toggle(Ptr t) override {
    if(!t) return;
    swap(t->l, t->r);
    t->rev ^= true;
  }

  Ptr update(Ptr t) override {
    if (!t) return t;
    t->cnt = 1 + this->count(t->l) + this->count(t->r);
    t->merge(t->l, t->r);
    return t;
  }

  void set_key(Ptr t, const T& key) override {
    this->expose(t);
    t->key = key;
    this->update(t);
  }

  T subtree(Ptr t) {
    this->expose(t);
    return f(t->key, t->sub);
  }
};

/**
 * @brief 部分木クエリLink/Cut Tree
 */
