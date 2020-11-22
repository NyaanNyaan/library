#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Val, uint32_t N = 1 << 20,
          Val DefaultValue = Val()>
struct HashMap {
  using u32 = uint32_t;
  using u64 = uint64_t;

 private:
  struct Node {
    Key key;
    Val val;
    Node* nxt;
    Node() = default;
  };

  u32 mask;
  Node** table;
  Node* pool;
  int pid;
  static constexpr u32 shift = 64 - __lg(N);

  Node* my_new(const Key& key, const Val& val) {
    pool[pid].key = key;
    pool[pid].val = val;
    pool[pid].nxt = nullptr;
    return &(pool[pid++]);
  }

  static u64 rng() {
    u64 m = chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }

 public:
  HashMap() : mask(N - 1), table(new Node*[N]()), pool(new Node[N]), pid(0) {}

  Val& operator[](const Key& key) {
    static u64 r = rng();
    u32 h = (u64(key) * r) >> shift;
    Node** pp = &(table[h]);
    while (*pp != nullptr && (*pp)->key != key) pp = &((*pp)->nxt);
    if (*pp == nullptr) *pp = my_new(key, DefaultValue);
    return (*pp)->val;
  }
};

/**
 * @brief Hash Map(連鎖法)
 * @docs docs/data-structure/hashmap_all.md
 */
