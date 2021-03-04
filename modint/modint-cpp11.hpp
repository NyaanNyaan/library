#pragma once

namespace modint998244353 {
using i32 = int32_t;
using u32 = uint32_t;
using u64 = uint64_t;
constexpr u32 mod = 998244353;
constexpr u32 r = 3296722945u;
constexpr u32 n2 = 932051910;
static_assert(r * mod == 1, "invalid, r * mod != 1");
static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

struct MontgomeryModInt998244353 {
  using mint = MontgomeryModInt998244353;

  u32 a;

  MontgomeryModInt998244353() : a(0) {}
  MontgomeryModInt998244353(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint() - mint(*this); }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  mint inverse() const { return pow(mod - 2); }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = mint(t);
    return (is);
  }

  u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};

}  // namespace modint998244353
using modint998244353::MontgomeryModInt998244353;