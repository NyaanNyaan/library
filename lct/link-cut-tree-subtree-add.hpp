#pragma once

template <typename T, T (*add)(T, T), T (*sub)(T, T), T (*mul)(T, long long)>
struct LinkCutForSubtreeNode {
  using Node = LinkCutForSubtreeNode;
  using Ptr = LinkCutForSubtreeNode*;
  Ptr l, r, p;
  T key, sum, lazy, cancel, subsum;
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
        subsum(T()),
        cnt(1),
        subcnt(0),
        rev(false) {}
  void make_normal(Ptr other) {
    subsum = add(subsum, other->sum);
    subcnt += other->cnt;
  }
  void make_prefer(Ptr other) {
    subsum = sub(subsum, other->sum);
    subcnt -= other->cnt;
  }
  void merge(Ptr n1, Ptr n2) {
    sum = add(add(n1 ? n1->sum : T(), key), add(subsum, n2 ? n2->sum : T()));
    cnt = 1 + (n1 ? n1->cnt : 0) + (n2 ? n2->cnt : 0) + subcnt;
    if (n1) n1->cancel = lazy;
    if (n2) n2->cancel = lazy;
  }
  void apply(const T& add_val) {
    key = add(key, add_val);
    sum = add(sum, mul(add_val, cnt));
    lazy = add(lazy, add_val);
    subsum = add(subsum, mul(add_val, subcnt));
  }
  void fetch() {
    if (!p) return;
    apply(p->lazy - cancel);
    cancel = p->lazy;
  }
};

template <typename T, T (*add)(T, T), T (*sub)(T, T), T (*mul)(T, long long)>
struct LinkCutTreeSubtreeQuery {
  using Node = LinkCutForSubtreeNode<T, add, sub, mul>;
  using Ptr = Node*;

  void push_rev(Ptr t) {
    if (!t) return;
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
  }

  void push(Ptr t) {
    if (!t) return;
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
    if (t->l) t->l->fetch();
    if (t->r) t->r->fetch();
  }

  Ptr update(Ptr t) {
    if (!t) return t;
    t->merge(t->l, t->r);
    return t;
  }

  void splay(Ptr t) {
    push(t);
    while (!is_root(t)) {
      Ptr q = t->p;
      if (is_root(q)) {
        push_rev(q), push_rev(t);
        rot(t);
      } else {
        Ptr r = q->p;
        push_rev(r), push_rev(q), push_rev(t);
        if (pos(q) == pos(t))
          rot(q), rot(t);
        else
          rot(t), rot(t);
      }
    }
  }

  Ptr expose(Ptr t) {
    Ptr rp = nullptr;
    for (Ptr cur = t; cur; cur = cur->p) {
      splay(cur), push(cur);
      if (cur->r) cur->make_normal(cur->r);
      if (rp) rp->fetch(), cur->make_prefer(rp);
      cur->r = rp;
      rp = cur;
    }
    splay(t);
    return rp;
  }

  void evert(Ptr t) {
    expose(t);
    toggle(t);
    push(t);
  }

  void link(Ptr u, Ptr v) {
    evert(u);
    expose(v);
    u->p = v, v->r = u;
    update(v);
  }

  void cut(Ptr u, Ptr v) {
    evert(u);
    expose(v);
    v->l = u->p = nullptr;
    update(v);
  }

  void toggle(Ptr t) {
    if(!t) return;
    swap(t->l, t->r);
    t->rev ^= true;
  }

  T get_key(Ptr t) {
    expose(t);
    return t->key;
  }

  void set_key(Ptr t, const T& key) {
    expose(t);
    t->key = key;
    update(t);
  }

  void subtree_add(Ptr t, const T& add_val) {
    expose(t);
    Ptr l = t->l;
    if (l) t->l = nullptr, update(t);
    t->apply(add_val);
    if (l) t->l = l, update(t);
  }

  T subtree_sum(Ptr t) {
    expose(t);
    return add(t->key, t->subsum);
  }

  Ptr get_root(Ptr x) {
    expose(x);
    while (x->l) this->push(x), x = x->l;
    return x;
  }

 protected:
  bool is_root(Ptr t) { return !(t->p) || (t->p->l != t && t->p->r != t); }

  inline int pos(Ptr t) {
    if (t->p) {
      if (t->p->l == t) return -1;
      if (t->p->r == t) return 1;
    }
    return 0;
  }

  void rot(Ptr t) {
    Ptr x = t->p, y = x->p;
    push(x), push(t);
    if (pos(t) == -1) {
      if ((x->l = t->r)) t->r->p = x;
      t->r = x, x->p = t;
    } else {
      if ((x->r = t->l)) t->l->p = x;
      t->l = x, x->p = t;
    }
    T xc = x->cancel;
    update(x), update(t);
    t->cancel = xc;
    if ((t->p = y)) {
      if (y->l == x) y->l = t;
      if (y->r == x) y->r = t;
    }
  }
};

/**
 * @brief 部分木加算クエリLink/Cut Tree
 */
