#pragma once

// x + yi
template <typename T>
struct Gaussian_Integer {
  T x, y;
  using G = Gaussian_Integer;

  Gaussian_Integer(T _x = 0, T _y = 0) : x(_x), y(_y) {}
  Gaussian_Integer(const pair<T, T>& p) : x(p.fi), y(p.se) {}

  T norm() const { return x * x + y * y; }
  G conj() const { return G{x, -y}; }

  G operator+(const G& r) const { return G{x + r.x, y + r.y}; }
  G operator-(const G& r) const { return G{x - r.x, y - r.y}; }
  G operator*(const G& r) const {
    return G{x * r.x - y * r.y, x * r.y + y * r.x};
  }
  G operator/(const G& r) const {
    G g = G{*this} * r.conj();
    T n = r.norm();
    g.x += n / 2, g.y += n / 2;
    return G{g.x / n - (g.x % n < 0), g.y / n - (g.y % n < 0)};
  }
  G operator%(const G& r) const { return G{*this} - G{*this} / r * r; }

  G& operator+=(const G& r) { return *this = G{*this} + r; }
  G& operator-=(const G& r) { return *this = G{*this} - r; }
  G& operator*=(const G& r) { return *this = G{*this} * r; }
  G& operator/=(const G& r) { return *this = G{*this} / r; }
  G& operator%=(const G& r) { return *this = G{*this} % r; }
  G operator-() const { return G{-x, -y}; }
  G operator+() const { return G{*this}; }
  bool operator==(const G& g) const { return x == g.x && y == g.y; }
  bool operator!=(const G& g) const { return x != g.x || y != g.y; }

  G pow(__int128_t e) const {
    G res{1}, a{*this};
    while (e) {
      if (e & 1) res *= a;
      a *= a, e >>= 1;
    }
    return res;
  }

  friend G gcd(G a, G b) {
    while (b != G{0, 0}) {
      trc(a, b, a / b, a % b);
      swap(a %= b, b);
    }
    return a;
  }
  friend ostream& operator<<(ostream& os, const G& rhs) {
    return os << rhs.x << " " << rhs.y;
  }
};
