#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Val, Val DefaultValue = Val()>
struct HashMap {
  using u32 = uint32_t;
  using u64 = uint64_t;

 private:
  u32 cap, s;
  Key* keys;
  Val* vals;
  vector<bool> flag;
  const u64 r;
  u32 shift;

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
    Key* k = new Key[cap];
    Val* v = new Val[cap];
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
    delete (keys);
    delete (vals);
    keys = k;
    vals = v;
    flag.swap(f);
    --shift;
  }

 public:
  HashMap()
      : cap(8),
        s(0),
        keys(new Key[cap]),
        vals(new Val[cap]),
        flag(cap),
        r(rng()),
        shift(64 - __lg(cap)) {}

  ~HashMap() {
    delete(keys);
    delete(vals);
  }

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

  // exist -> return pointer 
  // not exist -> return nullptr 
  Val* find(const Key& i) {
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) return nullptr;
      if (keys[hash] == i) return &(vals[hash]);
      hash = (hash + 1) & (cap - 1);
    }
  }
};

/**
 * @brief Hash Map(可変長版)
 * @docs docs/data-structure/hash-map.md
 */
