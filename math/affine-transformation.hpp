#pragma once

template <typename mint>
struct Affine {
  mint a, b;
  constexpr Affine() : a(1), b(0) {}
  constexpr Affine(mint _a, mint _b) : a(_a), b(_b) {}
  // R(L(x))
  friend Affine operator*(const Affine& l, const Affine& r) {
    return Affine(l.a * r.a, l.b * r.a + r.b);
  }
  mint operator()(mint x) const { return a * x + b; }
  Affine operator()(const Affine& r) const { return r * (*this); }
  bool operator==(const Affine& r) const { return a == r.a && b == r.b; }
  bool operator!=(const Affine& r) const { return a != r.a || b != r.b; }
  friend ostream& operator<<(ostream& os, const Affine& r) {
    os << "( " << r.a << ", " << r.b << " )";
    return os;
  }
};

/**
 * @brief アフィン変換
 */
