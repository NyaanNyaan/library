#include "hashmap-base.hpp"

template <typename Key, typename Val>
struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {
  using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;
  using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;
  using Data = pair<Key, Val>;

  Val& operator[](const Key& k) {
    typename base::u32 h = base::inner_hash(k);
    while (true) {
      if (base::flag[h] == false) {
        if (base::extend_rate(base::s + 1)) {
          base::extend();
          h = base::hash(k);
          continue;
        }
        base::data[h].first = k;
        base::data[h].second = Val();
        base::flag[h] = true;
        ++base::s;
        return base::data[h].second;
      }
      if (base::data[h].first == k) {
        if (base::dflag[h] == true) base::data[h].second = Val();
        return base::data[h].second;
      }
      h = (h + 1) & (base::cap - 1);
    }
  }

  typename base::itr emplace(const Key& key, const Val& val) {
    return base::insert(Data(key, val));
  }
};

/* 
 * @brief ハッシュマップ(連想配列)
 * @docs docs/hashmap/hashmap.md
**/
