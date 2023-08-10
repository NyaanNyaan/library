#pragma once

#include <cassert>
using namespace std;

// 引数が [0, mod) の範囲内, かつ逆元が存在するときに正しく動く
template <int MOD>
struct fast_modinv {
  using u32 = unsigned int;
  using u64 = unsigned long long;

  static constexpr int mod = MOD;
  static_assert(mod % 2 == 1 && mod < (1LL << 30));
  static constexpr int B = 2048;
  static constexpr bool prime = []() -> bool {
    if (MOD == 1) return false;
    for (int p = 3; p * p <= MOD; p += 2) {
      if (MOD % p == 0) return false;
    }
    return true;
  }();

  u32 ipow2[64], pre[B / 2];
  constexpr fast_modinv() : ipow2(), pre() {
    ipow2[0] = 1 % mod;
    for (int i = 1; i < 64; i++) {
      ipow2[i] = u64(ipow2[i - 1]) * ((mod + 1) / 2) % mod;
    }
    pre[0] = 1 % mod;
    for (int i = 3; i < B; i += 2) {
      pre[i >> 1] = [i]() -> int {
        int x = i, y = mod, u = 1, v = 0, t = 0, tmp = 0;
        while (y > 0) {
          t = x / y;
          x -= t * y, u -= t * v;
          tmp = x, x = y, y = tmp;
          tmp = u, u = v, v = tmp;
        }
        return u < 0 ? u + mod : u;
      }();
    }
  }

  constexpr u32 inv(u32 a) const {
    if constexpr (mod == 1) {
      return 0;
    }
    u32 b = mod, s = 1, t = 0;
    int n = __builtin_ctz(a);
    a >>= n;
    while (a - b != 0) {
      if constexpr (prime) {
        if (a < B) break;
      }
      int m = __builtin_ctz(a - b);
      bool f = a > b;
      n += m;
      a = f ? (a - b) >> m : a;
      b = f ? b : -(a - b) >> m;
      u32 u = f ? s - t : s << m;
      t = f ? t << m : -(s - t);
      s = u;
    }
    return u64(s) * pre[a >> 1] % mod * ipow2[n] % mod;
  }
  constexpr u32 operator()(u32 a) const { return inv(a); }
};
