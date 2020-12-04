#pragma once

template <typename Key, typename Val>
struct HashMap {
  using u32 = uint32_t;
  using u64 = uint64_t;

  u32 cap, s;
  vector<Key> keys;
  vector<Val> vals;
  vector<bool> flag;
  u64 r;
  u32 shift;
  Val DefaultValue;

  static u64 rng() {
    u64 m = chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }

  void reallocate() {
    cap <<= 1;
    vector<Key> k(cap);
    vector<Val> v(cap);
    vector<bool> f(cap);
    u32 sh = shift - 1;
    for (int i = 0; i < (int)flag.size(); i++) {
      if (flag[i]) {
        u32 hash = (u64(keys[i]) * r) >> sh;
        while (f[hash]) hash = (hash + 1) & (cap - 1);
        k[hash] = keys[i];
        v[hash] = vals[i];
        f[hash] = 1;
      }
    }
    keys.swap(k);
    vals.swap(v);
    flag.swap(f);
    --shift;
  }

  explicit HashMap()
      : cap(8),
        s(0),
        keys(cap),
        vals(cap),
        flag(cap),
        r(rng()),
        shift(64 - __lg(cap)),
        DefaultValue(Val()) {}

  Val& operator[](const Key& i) {
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) {
        if (s + s / 4 >= cap) {
          reallocate();
          return (*this)[i];
        }
        keys[hash] = i;
        flag[hash] = 1;
        ++s;
        return vals[hash] = DefaultValue;
      }
      if (keys[hash] == i) return vals[hash];
      hash = (hash + 1) & (cap - 1);
    }
  }

  // exist -> return pointer of Val
  // not exist -> return nullptr
  const Val* find(const Key& i) const {
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) return nullptr;
      if (keys[hash] == i) return &(vals[hash]);
      hash = (hash + 1) & (cap - 1);
    }
  }

  // return vector< pair<const Key&, val& > >
  vector<pair<Key, Val>> enumerate() const {
    vector<pair<Key, Val>> ret;
    for (u32 i = 0; i < cap; ++i)
      if (flag[i]) ret.emplace_back(keys[i], vals[i]);
    return ret;
  }

  int size() const { return s; }

  // set default_value
  void set_default(const Val& val) { DefaultValue = val; }
};

/**
 * @brief Hash Map(可変長版)
 * @docs docs/data-structure/hash-map.md
 */
