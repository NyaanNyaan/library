#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Val, uint32_t N = 1 << 20>
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

  Node* my_new(const Key& key, const Val& val) {
    pool[pid].key = key;
    pool[pid].val = val;
    pool[pid].nxt = nullptr;
    return &(pool[pid++]);
  }

  u32 hash(u64 x) {
    static const u64 m =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    x ^= x >> 23;
    x ^= m;
    x ^= x >> 47;
    return (x - (x >> 32)) & mask;
  }

 public:
  HashMap() : mask(N - 1), table(new Node*[N]()), pool(new Node[N]), pid(0) {}

  Val& operator[](const Key& key) {
    u32 h = hash(key);
    Node** pp = &(table[h]);
    while (*pp != nullptr && (*pp)->key != key) pp = &((*pp)->nxt);
    if (*pp == nullptr) *pp = my_new(key, Val(0));
    return (*pp)->val;
  }
};

/**
 * @brief Hash Map
 * @docs docs/data-structure/hash-map.md
 */
