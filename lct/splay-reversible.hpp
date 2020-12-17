#pragma once

#include "reversible-bbst-base.hpp"
#include "splay-base.hpp"

template <typename T>
struct ReversibleSplayTreeNode {
  using Ptr = ReversibleSplayTreeNode *;
  Ptr l, r, p;
  T key, sum;
  int cnt;
  bool rev;

  ReversibleSplayTreeNode(const T &t = T())
      : l(), r(), p(), key(t), sum(t), cnt(1), rev(false) {}
};

template <typename T, T (*f)(T, T), T (*ts)(T)>
struct ReversibleSplayTree
    : ReversibleBBST<SplayTreeBase<ReversibleSplayTreeNode<T>>,
                     ReversibleSplayTreeNode<T>, T, f, ts> {
  using Node = ReversibleSplayTreeNode<T>;
};

/**
 * @brief 反転可能Splay Tree
 */
