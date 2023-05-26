#pragma once

#include "nimber.hpp"
#include "sweep-restore.hpp"

template <typename N>
struct NimberToField {
  using uint = decltype(N::x);
  static constexpr int S = sizeof(uint) * 8;
  vector<uint> ftn, ntf;
  NimberToField(N proot) {
    ftn.resize(S);
    N cur = 1;
    for (int i = 0; i < S; i++) {
      ftn[i] = cur.x;
      cur *= proot;
    }
    Sweep sweep{ftn};
    ntf.resize(S);
    for (int i = 0; i < S; i++) {
      auto ans = sweep.restore(1 << i);
      uint bit{};
      for (auto& x : ans.second) bit ^= uint{1} << x;
      ntf[i] = bit;
    }
  }
  uint nimber2field(N n) {
    uint res = 0, x = n.x;
    for (; x; x &= x - 1) res ^= ntf[__builtin_ctzll(x)];
    return res;
  }
  N field2nimber(uint x) {
    uint res = 0;
    for (; x; x &= x - 1) res ^= ftn[__builtin_ctzll(x)];
    return res;
  }
};

/**
 * @brief Nimber <-> 多項式環
 */
