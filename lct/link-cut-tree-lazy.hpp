#pragma once

#include "splay-lazy-reversible.hpp"

//
#include "link-cut-base.hpp"

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ts)(T)>
struct LazyLinkCutTree
    : LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts>> {
  using base = LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts>>;
  using Ptr = typename base::Ptr;

  void set_key(Ptr t, const T& key) override {
    this->evert(t);
    t->key = key;
    this->update(t);
  }

  T get_key(Ptr t) override {
    this->evert(t);
    return t->key;
  }

  void apply(Ptr u, Ptr v, const E& e) {
    this->evert(u);
    this->expose(v);
    this->propagate(v, e);
  }
};

/**
 * @brief 遅延伝搬Link/Cut Tree
 */
