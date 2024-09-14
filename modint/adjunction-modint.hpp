#pragma once

// a + b sqrt(B)
template <typename mint, long long B>
struct Adjunction {
  using A = Adjunction;
  mint a, b;
  Adjunction(mint _a = 0, mint _b = 0) : a(_a), b(_b) {}
  Adjunction(long long x) : a(x), b(0) {}
  friend A operator+(const A& l, const A& r) { return {l.a + r.a, l.b + r.b}; }
  friend A operator-(const A& l, const A& r) { return {l.a - r.a, l.b - r.b}; }
  friend A operator*(const A& l, const A& r) {
    return {l.a * r.a + l.b * r.b * B, l.a * r.b + l.b * r.a};
  }
  friend A operator/(const A& l, const A& r) { return l * r.inverse(); }

  A& operator+=(const A& r) { return (*this) = (*this) + r; }
  A& operator-=(const A& r) { return (*this) = (*this) - r; }
  A& operator*=(const A& r) { return (*this) = (*this) * r; }
  A& operator/=(const A& r) { return (*this) = (*this) / r; }
  A operator-() const { return {-a, -b}; }
  A operator+() const { return *this; }

  A inverse() const {
    mint c = (a * a - b * b * B).inverse();
    return {a * c, -b * c};
  }
  A pow(__int128_t e) const {
    A res{1}, c{*this};
    while (e) {
      if (e & 1) res = res * c;
      c *= c;
      e >>= 1;
    }
    return res;
  }

  bool operator==(const A& r) const { return a == r.a && b == r.b; }
  bool operator!=(const A& r) const { return a != r.a || b != r.b; }
  friend ostream& operator<<(ostream& os, const A& rhs) {
    return os << rhs.a << " " << rhs.b;
  }
};
