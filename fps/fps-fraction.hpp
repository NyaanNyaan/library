#pragma once

template <typename fps>
struct fps_fraction {
  using frac = fps_fraction;
  using mint = typename fps::value_type;

  fps p, q;
  fps_fraction(const fps& numerator = fps{0}, const fps& denominator = fps{1})
      : p(numerator), q(denominator) {}

  friend frac operator+(const frac& l, const frac& r) {
    return frac{l.p * r.q + r.p * l.q, l.q * r.q};
  }
  friend frac operator-(const frac& l, const frac& r) {
    return frac{l.p * r.q - r.p * l.q, l.q * r.q};
  }
  friend frac operator*(const frac& l, const frac& r) {
    return frac{l.p * r.p, l.q * r.q};
  }
  friend frac operator/(const frac& l, const frac& r) {
    return frac{l.p * r.q, l.q * r.p};
  }

  frac& operator+=(const mint& r) {
    (*this).p += (*this).q * r;
    return *this;
  }
  frac& operator-=(const mint& r) {
    (*this).p -= (*this).q * r;
    return *this;
  }
  frac& operator*=(const mint& r) {
    (*this).p *= r;
    return *this;
  }

  frac operator+(const mint& r) { return frac{*this} += r; }
  frac operator-(const mint& r) { return frac{*this} -= r; }
  frac operator*(const mint& r) { return frac{*this} *= r; }
  frac operator/(const mint& r) { return frac{*this} /= r; }
  frac& operator+=(const frac& r) { return *this = (*this) + r; }
  frac& operator-=(const frac& r) { return *this = (*this) - r; }
  frac& operator*=(const frac& r) { return *this = (*this) * r; }
  frac operator-() const { return frac{-p, q}; }
  frac inverse() const { return frac{q, p}; };

  void shrink() { p.shrink(), q.shrink(); }
  friend bool operator==(const frac& l, const frac& r) {
    return l.p == r.p && l.q == r.q;
  }
  friend bool operator!=(const frac& l, const frac& r) {
    return l.p != r.p || l.q != r.q;
  }
  friend ostream& operator<<(ostream& os, const frac& r) {
    os << "[ ";
    for (auto& x : r.p) os << x << ", ";
    os << "], ";
    os << "[ ";
    for (auto& x : r.q) os << x << ", ";
    os << " ]";
    return os;
  }
};
