#pragma once



struct montgomery64 {
  using mint = montgomery64;
  using i64 = int64_t;
  using u64 = uint64_t;
  using u128 = __uint128_t;

  static u64 mod;
  static u64 r;
  static u64 n2;

  static u64 get_r() {
    u64 ret = mod;
    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static void set_mod(u64 m) {
    assert(m < (1LL << 62));
    assert((m & 1) == 1);
    mod = m;
    n2 = -u128(m) % m;
    r = get_r();
    assert(r * mod == 1);
  }

  u64 a;

  montgomery64() : a(0) {}
  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};

  static u64 reduce(const u128 &b) {
    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
  }

  mint &operator+=(const mint &b) {
    if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i64(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u128(a) * b.a);
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

  mint pow(u128 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = montgomery64(t);
    return (is);
  }

  mint inverse() const { return pow(mod - 2); }

  u64 get() const {
    u64 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;
