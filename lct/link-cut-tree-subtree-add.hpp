#pragma once

// バグ　見つからん　終わり

#include "reversible-bbst-base.hpp"
#include "splay-base.hpp"

template <typename T, T (*f)(T, T), T (*finv)(T, T), T (*mul)(T, long long)>
struct LinkCutForSubtreeNode {
  using Node = LinkCutForSubtreeNode;
  using Ptr = LinkCutForSubtreeNode*;
  Ptr l, r, p;
  T key, sum, lazy, cancel, sub;
  int cnt, subcnt;
  bool rev;

  LinkCutForSubtreeNode(const T& t = T())
      : l(),
        r(),
        p(),
        key(t),
        sum(t),
        lazy(T()),
        cancel(T()),
        sub(T()),
        cnt(1),
        subcnt(0),
        rev(false) {}
  void add(Ptr other) {
    sub = f(sub, other->sum);
    subcnt += other->cnt;
  }
  void erase(Ptr other) {
    sub = finv(sub, other->sum);
    subcnt -= other->cnt;
  }
  void merge(Ptr n1, Ptr n2) {
    sum = f(f(n1 ? n1->sum : T(), key), f(sub, n2 ? n2->sum : T()));
    cnt = 1 + (n1 ? n1->cnt : 0) + (n2 ? n2->cnt : 0) + subcnt;
    if (n1) n1->cancel = lazy;
    if (n2) n2->cancel = lazy;
  }
  void apply(const T& add_val) {
    key = f(key, add_val);
    sum = f(sum, mul(add_val, cnt));
    lazy = f(lazy, add_val);
    sub = f(sub, mul(add_val, subcnt));
  }
  void fetch() {
    if (!p) return;
    apply(p->lazy - cancel);
    cancel = p->lazy;
  }
};

template <typename T, T (*f)(T, T), T (*finv)(T, T), T (*mul)(T, long long)>
struct SplayTreeForLCSubtree
    : ReversibleBBST<SplayTreeBase<LinkCutForSubtreeNode<T, f, finv, mul>>,
                     LinkCutForSubtreeNode<T, f, finv, mul>, T, nullptr,
                     nullptr> {
  using Node = LinkCutForSubtreeNode<T, f, finv, mul>;
};
//
#include "link-cut-base.hpp"

template <typename T, T (*f)(T, T), T (*finv)(T, T), T (*mul)(T, long long)>
struct LinkCutTreeSubtreeQuery
    : LinkCutBase<SplayTreeForLCSubtree<T, f, finv, mul>> {
  using base = LinkCutBase<SplayTreeForLCSubtree<T, f, finv, mul>>;
  using Node = typename base::Node;
  using Ptr = typename base::Ptr;

  void push(Ptr t) override {
    if (!t) return;
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
    if (t->l) t->l->fetch();
    if (t->r) t->r->fetch();
  }

  Ptr update(Ptr t) override {
    if (!t) return t;
    t->merge(t->l, t->r);
    return t;
  }

  Ptr expose(Ptr t) override {
    Ptr rp = nullptr;
    for (Ptr cur = t; cur; cur = cur->p) {
      this->splay(cur), push(cur);
      if (cur->r) cur->add(cur->r);
      if (rp) rp->fetch(), cur->erase(rp);
      cur->r = rp, update(cur), rp = cur;
    }
    this->splay(t), push(t);
    return rp;
  }

  void link(Ptr u, Ptr v) override {
    this->evert(u);
    this->expose(v);
    u->p = v;
    v->add(u), u->cancel = v->lazy;
  }

  void toggle(Ptr t) override {
    swap(t->l, t->r);
    t->rev ^= true;
  }

  void set_key(Ptr t, const T& key) override {
    this->expose(t);
    t->key = key;
    this->update(t);
  }

  void subtree_add(Ptr t, const T& add_val) {
    expose(t);
    Ptr l = t->l;
    if (l) l->fetch(), t->l = nullptr, this->update(t);
    t->apply(add_val);
    if (l) t->l = l, this->update(t);
    push(t);
  }

  T subtree_sum(Ptr t) {
    this->expose(t);
    return f(t->key, t->sub);
  }

  void rot(Ptr t) override {
    Ptr x = t->p, y = x->p;
    x->fetch(), t->fetch();
    if (this->pos(t) == -1) {
      if ((x->l = t->r)) t->r->fetch(), t->r->p = x;
      t->r = x, x->p = t;
    } else {
      if ((x->r = t->l)) t->l->fetch(), t->l->p = x;
      t->l = x, x->p = t;
    }
    update(x), update(t);
    if ((t->p = y)) {
      if (y->l == x) y->l = t, t->cancel = y->lazy;
      if (y->r == x) y->r = t, t->cancel = y->lazy;
    }
  }
};

/**
 * @brief 部分木クエリLink/Cut Tree
 */
