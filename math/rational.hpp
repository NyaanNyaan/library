#pragma once

struct Rational {
  using R = Rational;
  using i128 = __int128_t;
  using i64 = long long;
  using u64 = unsigned long long;
  long long x, y;
  Rational() : x(0), y(1) {}
  Rational(long long _x, long long _y = 1) : x(_x), y(_y) {
    assert(y != 0);
    if (_y != 1) {
      long long g = gcd(x, y);
      if (g != 0) x /= g, y /= g;
      if (y < 0) x = -x, y = -y;
    }
  }

  u64 gcd(i64 A, i64 B) {
    u64 a = A >= 0 ? A : -A;
    u64 b = B >= 0 ? B : -B;
    if (a == 0 || b == 0) return a + b;
    int n = __builtin_ctzll(a);
    int m = __builtin_ctzll(b);
    a >>= n;
    b >>= m;
    while (a != b) {
      int d = __builtin_ctzll(a - b);
      bool f = a > b;
      u64 c = f ? a : b;
      b = f ? b : a;
      a = (c - b) >> d;
    }
    return a << min(n, m);
  }

  friend R operator+(const R& l, const R& r) {
    return R(l.x * r.y + l.y * r.x, l.y * r.y);
  }
  friend R operator-(const R& l, const R& r) {
    return R(l.x * r.y - l.y * r.x, l.y * r.y);
  }
  friend R operator*(const R& l, const R& r) { return R(l.x * r.x, l.y * r.y); }
  friend R operator/(const R& l, const R& r) {
    assert(r.x != 0);
    return R(l.x * r.y, l.y * r.x);
  }
  R& operator+=(const R& r) { return (*this) = (*this) + r; }
  R& operator-=(const R& r) { return (*this) = (*this) - r; }
  R& operator*=(const R& r) { return (*this) = (*this) * r; }
  R& operator/=(const R& r) { return (*this) = (*this) / r; }
  R operator-() const {
    R r;
    r.x = -x, r.y = y;
    return r;
  }
  R inverse() const {
    assert(x != 0);
    R r;
    r.x = y, r.y = x;
    if (x < 0) r.x = -r.x, r.y = -r.y;
    return r;
  }
  R pow(long long p) const {
    R res(1), base(*this);
    while (p) {
      if (p & 1) res *= base;
      base *= base;
      p >>= 1;
    }
    return res;
  }

  friend bool operator==(const R& l, const R& r) {
    return l.x == r.x && l.y == r.y;
  };
  friend bool operator!=(const R& l, const R& r) {
    return l.x != r.x || l.y != r.y;
  };
  friend bool operator<(const R& l, const R& r) {
    return i128(l.x) * r.y < i128(l.y) * r.x;
  };
  friend bool operator<=(const R& l, const R& r) { return l < r || l == r; }
  friend bool operator>(const R& l, const R& r) {
    return i128(l.x) * r.y > i128(l.y) * r.x;
  };
  friend bool operator>=(const R& l, const R& r) { return l > r || l == r; }
  friend ostream& operator<<(ostream& os, const R& r) {
    os << r.x;
    if (r.x != 0 && r.y != 1) os << "/" << r.y;
    return os;
  }

  long long toMint(long long mod) {
    assert(mod != 0);
    i64 a = y, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return i128((u % mod + mod) % mod) * x % mod;
  }
};

template <typename R = Rational>
struct Binomial {
  vector<R> fc;
  Binomial(int = 0) { fc.emplace_back(1); }
  void extend() {
    int n = fc.size();
    R nxt = fc.back() * n;
    fc.push_back(nxt);
  }
  R fac(int n) {
    while ((int)fc.size() <= n) extend();
    return fc[n];
  }
  R finv(int n) { return fac(n).inverse(); }
  R inv(int n) { return R{1, max(n, 1)}; }
  R C(int n, int r) {
    if (n < 0 or r < 0 or n < r) return R{0};
    return fac(n) * finv(n - r) * finv(r);
  }
  R operator()(int n, int r) { return C(n, r); }
  template <typename I>
  R multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if (x < 0) return R{0};
      n += x;
    }
    R res = fac(n);
    for (auto& x : r) res *= finv(x);
    return res;
  }

  template <typename I>
  R operator()(const vector<I>& r) {
    return multinomial(r);
  }
};
