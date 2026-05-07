#pragma once

#include "orderedmap-base.hpp"

template <typename Key, bool is_multiset>
struct OrderedSetNode {
  using Ptr = typename RBSTBase<OrderedSetNode>::Ptr;
  Ptr l, r;
  Key key;
  int cnt;

  OrderedSetNode(const Key& k = Key()) : l(), r(), key(k), cnt(1) {}
};

template <typename Key>
struct OrderedSet : OrderedMapBase<OrderedSetNode<Key, false>, false> {
  using base = OrderedMapBase<OrderedSetNode<Key, false>, false>;

  OrderedSet() : base() {}

  void insert(const Key& k) { base::insert_key(k); }
};

/**
 * @brief Ordered Map(順序付き連想配列)
 */
