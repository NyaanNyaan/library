#pragma once

struct FastSet {
  using u64 = uint64_t;
  static constexpr u64 B = 64;
  int n, lg;
  vector<vector<u64>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vector<u64>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }

  inline int lsb(u64 x) { return __builtin_ctzll(x); }
  inline int msb(u64 x) { return 63 - __builtin_clzll(x); }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void set(int i) {
    for (int h = 0; h < lg; h++) {
      bool b = seg[h][i / B] != 0;
      seg[h][i / B] |= 1ULL << (i % B);
      if (b) break;
      i /= B;
    }
  }
  void reset(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B]) break;
      i /= B;
    }
  }

  int find_next(int i) {
    i++;
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size()) break;
      u64 d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      i += lsb(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += lsb(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }

  int find_prev(int i) {
    i--;
    for (int h = 0; h < lg; h++) {
      if (i == -1) break;
      u64 d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      i += msb(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += msb(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }
};
