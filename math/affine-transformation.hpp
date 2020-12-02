#pragma once

template <typename mint>
struct Affine {
  mint a, b;
  Affine(mint _a = 1, mint _b = 0) : a(_a), b(_b) {}
  mint operator()(mint x) { return a * x + b; }
  friend Affine operator*(const Affine& l, const Affine& r) {
    return Affine(l.a * r.a, l.b * r.a + r.b);
  }
  bool operator==(const Affine& r) const { return a == r.a && b == r.b; }
  bool operator!=(const Affine& r) const { return a != r.a || b != r.b; }
  friend ostream& operator<<( ostream&os,const Affine&r){
    os << "( " << r.a << ", " << r.b << " )";
    return os;
  }
};

/**
 * @brief アフィン変換
 */
