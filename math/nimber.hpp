#pragma once

#include "garner.hpp"

namespace NimberImpl {
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

struct calc8 {
  u16 dp[1 << 8][1 << 8];
  constexpr calc8() : dp() {
    dp[0][0] = dp[0][1] = dp[1][0] = 0;
    dp[1][1] = 1;
    for (int e = 1; e <= 3; e++) {
      int p = 1 << e, q = p >> 1;
      u16 ep = 1u << p, eq = 1u << q;
      for (u16 i = 0; i < ep; i++) {
        for (u16 j = i; j < ep; j++) {
          if (i < eq && j < eq) continue;
          if (min(i, j) <= 1u) {
            dp[i][j] = dp[j][i] = i * j;
            continue;
          }
          u16 iu = i >> q, il = i & (eq - 1);
          u16 ju = j >> q, jl = j & (eq - 1);
          u16 u = dp[iu][ju], l = dp[il][jl];
          u16 ul = dp[iu ^ il][ju ^ jl];
          u16 uq = dp[u][eq >> 1];
          dp[i][j] = ((ul ^ l) << q) ^ uq ^ l;
          dp[j][i] = dp[i][j];
        }
      }
    }
  }
} constexpr c8;

struct calc16 {
  static constexpr u16 proot = 10279;
  static constexpr u32 ppoly = 92191;
  static constexpr int order = 65535;

  u16 base[16], exp[(1 << 18) + 100];
  int log[1 << 16];

 private:
  constexpr u16 d(u32 x) { return (x << 1) ^ (x < 32768u ? 0 : ppoly); }

  constexpr u16 naive(u16 i, u16 j) {
    if (min(i, j) <= 1u) return i * j;
    u16 q = 8, eq = 1u << 8;
    u16 iu = i >> q, il = i & (eq - 1);
    u16 ju = j >> q, jl = j & (eq - 1);
    u16 u = c8.dp[iu][ju];
    u16 l = c8.dp[il][jl];
    u16 ul = c8.dp[iu ^ il][ju ^ jl];
    u16 uq = c8.dp[u][eq >> 1];
    return ((ul ^ l) << q) ^ uq ^ l;
  }

 public:
  constexpr calc16() : base(), exp(), log() {
    base[0] = 1;
    for (int i = 1; i < 16; i++) base[i] = naive(base[i - 1], proot);
    exp[0] = 1;
    for (int i = 1; i < order; i++) exp[i] = d(exp[i - 1]);
    u16* pre = exp + order + 1;
    pre[0] = 0;
    for (int b = 0; b < 16; b++) {
      int is = 1 << b, ie = is << 1;
      for (int i = is; i < ie; i++) pre[i] = pre[i - is] ^ base[b];
    }
    for (int i = 0; i < order; i++) exp[i] = pre[exp[i]], log[exp[i]] = i;

    int ie = 2 * order + 30;
    for (int i = order; i < ie; i++) exp[i] = exp[i - order];
    for (unsigned int i = ie; i < sizeof(exp) / sizeof(u16); i++) exp[i] = 0;
    log[0] = ie + 1;
  }

  constexpr u16 prod(u16 i, u16 j) const { return exp[log[i] + log[j]]; }

  // exp[3] = 2^{15} = 32768
  constexpr u16 Hprod(u16 i, u16 j) const { return exp[log[i] + log[j] + 3]; }
  constexpr u16 H(u16 i) const { return exp[log[i] + 3]; }
  constexpr u16 H2(u16 i) const { return exp[log[i] + 6]; }
} constexpr c16;

u16 product16(u16 i, u16 j) { return c16.prod(i, j); }

constexpr u32 product32(u32 i, u32 j) {
  u16 iu = i >> 16, il = i & 65535;
  u16 ju = j >> 16, jl = j & 65535;
  u16 l = c16.prod(il, jl);
  u16 ul = c16.prod(iu ^ il, ju ^ jl);
  u16 uq = c16.Hprod(iu, ju);
  return (u32(ul ^ l) << 16) ^ uq ^ l;
}

// (+ : xor, x : nim product, * : integer product)
// i x j
// = (iu x ju + il x ju + iu x ji) * 2^{16}
// + (iu x ju x 2^{15}) + il x jl
// (assign ju = 2^{15}, jl = 0)
// = ((iu + il) x 2^{15}) * 2^{16} + (iu x 2^{15} x 2^{15})
constexpr u32 H(u32 i) {
  u16 iu = i >> 16;
  u16 il = i & 65535;
  return (u32(c16.H(iu ^ il)) << 16) ^ c16.H2(iu);
}

constexpr u64 product64(u64 i, u64 j) {
  u32 iu = i >> 32, il = i & u32(-1);
  u32 ju = j >> 32, jl = j & u32(-1);
  u32 l = product32(il, jl);
  u32 ul = product32(iu ^ il, ju ^ jl);
  u32 uq = H(product32(iu, ju));
  return (u64(ul ^ l) << 32) ^ uq ^ l;
}
}  // namespace NimberImpl

template <typename uint, uint (*prod)(uint, uint)>
struct NimberBase {
  using N = NimberBase;
  uint x;
  NimberBase() : x(0) {}
  NimberBase(uint _x) : x(_x) {}
  static N id0() { return {}; }
  static N id1() { return {1}; }

  N& operator+=(const N& p) {
    x ^= p.x;
    return *this;
  }
  N& operator-=(const N& p) {
    x ^= p.x;
    return *this;
  }
  N& operator*=(const N& p) {
    x = prod(x, p.x);
    return *this;
  }
  N operator+(const N& p) const { return x ^ p.x; }
  N operator-(const N& p) const { return x ^ p.x; }
  N operator*(const N& p) const { return prod(x, p.x); }
  bool operator==(const N& p) const { return x == p.x; }
  bool operator!=(const N& p) const { return x != p.x; }
  N pow(uint64_t n) const {
    N a = *this, r = 1;
    for (; n; a *= a, n >>= 1)
      if (n & 1) r *= a;
    return r;
  }
  friend ostream& operator<<(ostream& os, const N& p) { return os << p.x; }

  // calculate log_a (b)
  uint discrete_logarithm(N y) const {
    assert(x != 0 && y != 0);
    vector<uint> rem, mod;
    for (uint p : {3, 5, 17, 257, 641, 65537, 6700417}) {
      if (uint(-1) % p) continue;
      uint q = uint(-1) / p;
      uint STEP = 1;
      while (4 * STEP * STEP < p) STEP *= 2;
      // a^m = z を満たす 1 以上の整数 m を返す
      auto inside = [&](N a, N z) -> uint {
        unordered_map<uint, int> mp;
        N big = 1, now = 1;  // x^m
        for (int i = 0; i < int(STEP); i++) {
          mp[z.x] = i, z *= a, big *= a;
        }
        for (int step = 0; step < int(p + 10); step += STEP) {
          now *= big;
          if (mp.find(now.x) != mp.end()) return (step + STEP) - mp[now.x];
        }
        return uint(-1);
      };
      N xq = (*this).pow(q), yq = y.pow(q);
      if (xq == 1 and yq == 1) continue;
      if (xq == 1 and yq != 1) return uint(-1);
      uint res = inside(xq, yq);
      if (res == uint(-1)) return uint(-1);
      rem.push_back(res % p);
      mod.push_back(p);
    }
    return garner(rem, mod).first;
  }

  uint is_primitive_root() const {
    if (x == 0) return false;
    for (uint p : {3, 5, 17, 257, 641, 65537, 6700417}) {
      if (uint(-1) % p != 0) continue;
      if ((*this).pow(uint(-1) / p) == 1) return false;
    }
    return true;
  }
};

using Nimber16 = NimberBase<uint16_t, NimberImpl::product16>;
using Nimber32 = NimberBase<uint32_t, NimberImpl::product32>;
using Nimber64 = NimberBase<uint64_t, NimberImpl::product64>;
using Nimber = Nimber64;

/**
 * @brief Nim Product
 * @docs docs/math/nimber.md
 */
