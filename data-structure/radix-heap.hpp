#pragma once

template <typename Key, typename Val>
struct RadixHeap {
  using uint = typename make_unsigned<Key>::type;
  static constexpr int bit = sizeof(Key) * 8;
  array<vector<pair<uint, Val> >, bit + 1> vs;
  array<uint, bit + 1> ms;

  int s;
  uint last;

  RadixHeap() : s(0), last(0) { fill(begin(ms), end(ms), uint(-1)); }

  bool empty() const { return s == 0; }

  int size() const { return s; }

  __attribute__((target("lzcnt"))) inline uint64_t getbit(uint a) const {
    return 64 - _lzcnt_u64(a);
  }

  void push(const uint &key, const Val &val) {
    s++;
    uint64_t b = getbit(key ^ last);
    vs[b].emplace_back(key, val);
    ms[b] = min(key, ms[b]);
  }

  pair<uint, Val> pop() {
    if (ms[0] == uint(-1)) {
      int idx = 1;
      while (ms[idx] == uint(-1)) idx++;
      last = ms[idx];
      for (auto &p : vs[idx]) {
        uint64_t b = getbit(p.first ^ last);
        vs[b].emplace_back(p);
        ms[b] = min(p.first, ms[b]);
      }
      vs[idx].clear();
      ms[idx] = uint(-1);
    }
    --s;
    auto res = vs[0].back();
    vs[0].pop_back();
    if (vs[0].empty()) ms[0] = uint(-1);
    return res;
  }
};

/**
 * @brief Radix Heap
 * @docs docs/data-structure/radix-heap.md
 */
