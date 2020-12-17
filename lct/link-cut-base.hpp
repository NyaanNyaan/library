#pragma once

template <typename Splay>
struct LinkCutTree : Splay {
  using Node = typename Splay::Node;
  using Ptr = Node*;

  Ptr expose(Ptr t) {
    Ptr rp = nullptr;
    for (Ptr cur = t; cur; cur = cur->p) {
      this->splay(cur);
      cur->r = rp;
      this->update(cur);
      rp = cur;
    }
    this->splay(t);
    return rp;
  }

  void link(Ptr u, Ptr v) {
    evert(u);
    expose(v);
    u->p = v;
  }

  void cut(Ptr u, Ptr v) {
    evert(u);
    expose(v);
    assert(v->l == u);
    v->l = u->p = nullptr;
    this->update(v);
  }

  void evert(Ptr t) {
    expose(t);
    this->toggle(t);
    this->push(t);
  }

  Ptr lca(Ptr u, Ptr v) {
    if (get_root(u) != get_root(v)) return nullptr;
    expose(u);
    return expose(v);
  }

  Ptr get_kth(Ptr x, int k) {
    expose(x);
    while (x) {
      this->push(x);
      if (x->r && x->r->sz > k) {
        x = x->r;
      } else {
        if (x->r) k -= x->r->sz;
        if (k == 0) return x;
        k -= 1;
        x = x->l;
      }
    }
    return nullptr;
  }

  Ptr get_root(Ptr x) {
    expose(x);
    while (x->l) this->push(x), x = x->l;
    return x;
  }

  void vertex_set(Ptr t, const decltype(Node::key)& key) {
    this->splay(t);
    t->key = key;
    this->update(t);
  }

  decltype(Node::key) fold(Ptr u, Ptr v) {
    evert(u);
    expose(v);
    return v->sum;
  }
};

/**
 * @brief Link Cut Tree
 */
