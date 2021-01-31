#pragma once

#include "hashmap-base.hpp"

template <typename Key>
struct HashSet : HashMapImpl::HashMapBase<Key, Key> {
  using HashMapImpl::HashMapBase<Key, Key>::HashMapBase;
};

/* 
 * @brief ハッシュセット(集合)
 * @docs docs/hashmap/hashset.md
**/
