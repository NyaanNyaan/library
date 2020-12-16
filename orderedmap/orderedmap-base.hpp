#pragma once

#include "../rbst/rbst-base.hpp"

template <typename Node, bool multi>
struct OrderedMapBase : RBSTBase<Node> {
  using base = RBSTBase<Node>;
  using Ptr = typename base::Ptr;
  using Key = decltype(Node::key);

  Ptr root;
  OrderedMapBase() : root(base::make_tree()) {}

  Ptr find(const Key& k) const {
    Ptr p = root;
    while (p) {
      if (k == p->key) return p;
      p = k < p->key ? p->l : p->r;
    }
    return base::make_tree();
  }

  int lower_bound(const Key& k) const {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if (k <= p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int upper_bound(const Key& k) const {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if (k < p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int count(const Key& k) const {
    if constexpr (multi) {
      return upper_bound(k) - lower_bound(k);
    } else {
      return !!find(k);
    }
  }

  Ptr kth_element(int k) const {
    Ptr p = root;
    while (p) {
      int lc = base::count(p->l);
      if (lc == k) return p;
      if (k < lc) {
        p = p->l;
      } else {
        k -= lc + 1;
        p = p->r;
      }
    }
    return p;
  }

  void erase(const Key& k) {
    Ptr p = root;
    int ret = 0;
    bool flg = false;
    while (p) {
      if (k == p->key) flg = true;
      if (k <= p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    if (flg) base::erase(root, ret);
  }

  void erase(Ptr p) { erase(p->key); }

  int size() const { return base::size(root); }

 protected:

  void push(Ptr) override {}
  
  Ptr update(Ptr n) override {
    n->cnt = 1 + base::count(n->l) + base::count(n->r);
    return n;
  }

  Ptr insert_key(const Key& k) {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if constexpr (multi == false) {
        if (k == p->key) return p;
      }
      if (k < p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    Ptr n = base::my_new(k);
    auto x = base::split(root, ret);
    root = base::merge(base::merge(x.first, n), x.second);
    return n;
  }
};

/**
 * @brief Ordered Set(base)　(順序付き集合・基底クラス)
 */
