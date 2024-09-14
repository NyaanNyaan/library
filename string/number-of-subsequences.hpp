#pragma once

#include "../hashmap/hashmap-unerasable.hpp"

template <typename Container, typename mint>
mint number_of_subsequences(const Container& S) {
  using Key = typename Container::value_type;
  UnerasableHashMap<Key, mint> mp;
  mint al = 1;
  for (auto& c : S) {
    mint& mpc = mp[c];
    mint x = mpc;
    mpc = al;
    al += al - x;
  }
  return al - 1;
}
