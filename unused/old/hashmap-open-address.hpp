#pragma once

template <typename Key, typename Val, uint32_t N = 1 << 20,
          Val DefaultValue = Val()>
struct HashMap {
  using u32 = uint32_t;
  using u64 = uint64_t;

 private:
  Key* keys;
  Val* vals;
  bitset<N> flag;
  static constexpr u32 shift = 64 - __lg(N);

  static u64 rng() {
    u64 m = chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }

 public:
  HashMap() : keys(new Key[N]), vals(new Val[N]) {
    static_assert((N & (N - 1)) == 0 && N > 0);
  }

  Val& operator[](const Key& i) {
    static u64 r = rng();
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) {
        keys[hash] = i;
        flag[hash] = 1;
        return vals[hash] = DefaultValue;
      }
      if (keys[hash] == i) return vals[hash];
      hash = (hash + 1) & (N - 1);
    }
  }
};

/**
 * @brief Hash Map(開番地法)
 * @docs docs/hashmap/hashmap_all.md
 */
