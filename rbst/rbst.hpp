#pragma once

#include "rbst-base.hpp"

template <typename T>
struct RBSTNode {
  typename RBSTBase<RBSTNode>::Ptr l, r;
  T key, sum;
  int cnt;

  RBSTNode(const T &t = T()) : l(), r(), key(t), sum(t), cnt(1) {}
};

template <typename T, T (*f)(T, T)>
struct RBST : RBSTBase<RBSTNode<T>> {
  using Node = RBSTNode<T>;
  using base = RBSTBase<RBSTNode<T>>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  RBST() = default;

  T fold(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  inline T sum(const Ptr t) const { return t ? t->sum : T(); }

 protected:
  Ptr update(Ptr t) override {
    push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void push(Ptr) override {}
};

/**
 * @brief 乱択平衡二分木
 */
