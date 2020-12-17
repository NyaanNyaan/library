#pragma once

#include "lazy-reversible-bbst-base.hpp"
#include "splay-base.hpp"

template <typename T, typename E>
struct LazyReversibleSplayTreeNode {
  using Ptr = LazyReversibleSplayTreeNode *;
  Ptr l, r, p;
  T key, sum;
  E lazy;
  int cnt;
  bool rev;

  LazyReversibleSplayTreeNode(const T &t = T(), const E &e = E())
      : l(), r(), p(), key(t), sum(t), lazy(e), cnt(1), rev(false) {}
};

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ts)(T)>
struct LazyReversibleSplayTree
    : LazyReversibleBBST<SplayTreeBase<LazyReversibleSplayTreeNode<T, E>>,
                         LazyReversibleSplayTreeNode<T, E>, T, E, f, g, h, ts> {
  using Node = LazyReversibleSplayTreeNode<T, E>;
};

/**
 * @brief 遅延伝搬反転可能Splay Tree
 */
