#pragma once

#include "orderedmap-base.hpp"

template <typename Key, typename Val, bool multi>
struct OrderedMapNode {
  using Ptr = typename RBSTBase<OrderedMapNode>::Ptr;
  Ptr l, r;
  Key key;
  Val val;
  int cnt;

  OrderedMapNode(const Key& k = Key(), const Val& v = Val())
      : l(), r(), key(k), val(v), cnt(1) {}
};

template <typename Key, typename Val>
struct OrderedMap : OrderedMapBase<OrderedMapNode<Key, Val, false>, false> {
  using base = OrderedMapBase<OrderedMapNode<Key, Val, false>, false>;

  OrderedMap() : base() {}

  Val& operator[](const Key& key) { return base::insert_key(key)->val; };

};

/**
 * @brief Ordered Map(順序付き連想配列)
 */
