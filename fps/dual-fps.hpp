#pragma once

#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

#include "../math/constexpr-primitive-root.hpp"

/**
 * (1) deg(f) <= 1 (定数関数) ... topに値を保持
 * (2) deg(f) >= 2
 *   (a) deg == 2^b + 1
 *     len(F) = 2^b, top = [x^{2^b}] f として保持
 *   (b) otherwise
 *     F = ntt(f)として普通に保持
 */

template <typename mint>
struct Zeta {
  static constexpr int pr = constexpr_primitive_root(mint::get_mod());
  static constexpr int S = __builtin_ctz(mint::get_mod() - 1);
  static constexpr mint one{1};
  mint zeta[S + 1];
  constexpr Zeta() : zeta() {
    zeta[S] = mint(constexpr_primitive_root(mint::get_mod()));
    zeta[S] = zeta[S].pow((mint::get_mod() - 1) >> S);
    for (int i = S - 1; i >= 0; i--) {
      zeta[i] = zeta[i + 1] * zeta[i + 1];
    }
  }
  inline mint operator[](int i) const { return zeta[i]; }
};

template <typename fps>
struct DualFPS {
  using mint = typename fps::value_type;
  fps f;
  int deg;
  mint top;
  static constexpr Zeta<mint> zeta{};
  static vector<int> btr;

  explicit DualFPS() : deg(0), top() {}
  explicit DualFPS(const fps& g) : f(g), deg(g.size()), top() {
    if (g.empty()) return;
    if (g.size() == 1) {
      f.clear();
      top = g[0];
      if (top == mint()) deg = 0;
      return;
    }
    top = g.back();
    int cap = get_cap(deg);
    if (deg == cap + 1) {
      f.pop_back();
      f[0] += top;
    } else {
      f.resize(cap);
    }
    f.ntt();
  }

  DualFPS& operator+=(const mint& r) {
    if (r == mint()) return *this;
    if (f.empty()) {
      top += r;
      (*this).deg = 1;
    } else {
      for (auto& x : f) x += r;
    }
    return *this;
  }

  DualFPS& operator*=(const mint& r) {
    if (r == mint()) {
      f.clear();
      deg = 0, top = mint();
    } else {
      for (auto& x : f) x *= r;
      top *= r;
    }
    return *this;
  }

  DualFPS& operator+=(DualFPS& r) {
    DualFPS& l{*this};
    if (r.deg <= 1) return l += r.top;
    if (l.deg <= 1) {
      mint lt = l.top;
      return l = r + lt;
    }

    int d = max(l.deg, r.deg);
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    for (int i = 0; i < cap; i++) l.f[i] += r.f[i];
    if (l.deg == r.deg) {
      l.top += r.top;
    } else if (r.deg > l.deg) {
      l.top = r.top;
    }
    l.deg = d;
    return l;
  }

  DualFPS& operator-=(DualFPS& r) {
    DualFPS& l{*this};
    if (r.deg <= 1) return l -= r.top;
    if (l.deg <= 1) {
      mint lt = l.top;
      return l = (-r) + lt;
    }

    int d = max(l.deg, r.deg);
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    for (int i = 0; i < cap; i++) l.f[i] -= r.f[i];
    if (l.deg == r.deg) {
      l.top -= r.top;
    } else if (r.deg > l.deg) {
      l.top = -r.top;
    }
    l.deg = d;
    return l;
  }

  DualFPS& operator*=(DualFPS& r) {
    DualFPS& l{*this};
    if (r.deg <= 1) return l *= r.top;
    if (l.deg <= 1) {
      mint lt = l.top;
      return l = r * lt;
    }

    int d = l.deg + r.deg - 1;
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    for (int i = 0; i < cap; i++) l.f[i] *= r.f[i];
    l.deg = d;
    l.top *= r.top;
    return l;
  }

  friend DualFPS operator+(DualFPS& l, DualFPS& r) {
    if (r.deg <= 1) return l + r.top;
    if (l.deg <= 1) return r + l.top;

    int d = max(l.deg, r.deg);
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    DualFPS res{l};
    for (int i = 0; i < cap; i++) res.f[i] += r.f[i];
    if (l.deg == r.deg) {
      res.top += r.top;
    } else if (r.deg > l.deg) {
      res.top = r.top;
    }
    res.deg = d;
    return res;
  }

  friend DualFPS operator-(DualFPS& l, DualFPS& r) {
    if (r.deg <= 1) return l - r.top;
    if (l.deg <= 1) return (-r) += l.top;

    int d = max(l.deg, r.deg);
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    DualFPS res{l};
    for (int i = 0; i < cap; i++) res.f[i] -= r.f[i];
    if (l.deg == r.deg) {
      res.top -= r.top;
    } else if (r.deg > l.deg) {
      res.top = -r.top;
    }
    res.deg = d;
    return res;
  }

  friend DualFPS operator*(DualFPS& l, DualFPS& r) {
    if (r.deg <= 1) return l * r.top;
    if (l.deg <= 1) return r * l.top;

    int d = l.deg + r.deg - 1;
    int cap = max<int>(get_cap(d), max(l.f.size(), r.f.size()));
    l.change_factor(cap);
    r.change_factor(cap);

    DualFPS res{l};
    for (int i = 0; i < cap; i++) res.f[i] *= r.f[i];
    res.deg = d;
    res.top = l.top * r.top;
    return res;
  }

  DualFPS operator-() const {
    DualFPS buf{*this};
    buf.top = -buf.top;
    for (auto& x : buf.f) x = -x;
    return buf;
  }

  DualFPS& operator-=(const mint& r) { return (*this) += -r; }
  DualFPS operator+(const mint& r) const { return DualFPS{*this} += r; }
  DualFPS operator-(const mint& r) const { return DualFPS{*this} += -r; }
  DualFPS operator*(const mint& r) const { return DualFPS{*this} *= r; }

  DualFPS operator<<(int s) {
    if (s == 0) return *this;
    if (deg <= 1 and top == mint()) return DualFPS{};

    // deg >= 1, s >= 1 => d >= 2, cap >= 1
    int d = deg + s;
    int cap = max<int>(get_cap(d), f.size());
    (*this).change_factor(cap);

    if ((int)btr.size() < cap) {
      btr.resize(cap);
      for (int i = 0, lg = __builtin_ctz(cap); i < (1 << lg); i++) {
        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg - 1));
      }
    }

    int lg1 = __builtin_ctz(cap);
    int lg2 = __builtin_ctz(btr.size());

    DualFPS res{*this};
    mint w = zeta[lg1].pow(s), buf{1};
    for (int i = 0; i < cap; i++) {
      res.f[btr[i] >> (lg2 - lg1)] *= buf;
      buf *= w;
    }
    res.deg = d;
    return res;
  }

  fps get() const {
    if (deg < 2) return fps{top};
    fps res = f;
    res.intt();
    if ((int)f.size() + 1 == deg) {
      res.push_back(top);
      res[0] -= top;
    }
    return res;
  }

  friend ostream& operator<<(ostream& os, const DualFPS& r) {
    os << "deg = " << r.deg;
    os << ", cap = " << r.f.size();
    os << ", top = " << r.top;
    os << ", ele = [ ";
    for (auto& x : r.get()) os << x << ", ";
    os << "]";
    return os;
  }

 private:
  static inline int get_cap(int d) {
    if (d <= 1) return 0;
    if (d == 2) return 1;
    return 1 << (32 - __builtin_clz(d - 2));
  }

  void doubling() {
    fps g = f;
    g.intt();
    if ((int)f.size() + 1 == deg) g[0] -= top + top;
    int M = g.size();
    mint r = 1, z = zeta[__builtin_ctz(M) + 1];
    for (int i = 0; i < M; i++) g[i] *= r, r *= z;
    g.ntt();
    copy(begin(g), end(g), back_inserter(f));
  }

  void change_factor(unsigned int cap) {
    assert(this->f.size() <= cap);
    if (this->f.size() == cap) return;
    if (this->f.size() * 2 == cap) {
      doubling();
      return;
    }
    if (f.empty()) {
      f.resize(cap, top);
    } else {
      int s = this->f.size();
      f.intt();
      f.resize(cap);
      if (s + 1 == deg) f[0] -= top, f[s] += top;
      f.ntt();
    }
  }
};

template <typename fps>
vector<int> DualFPS<fps>::btr;

/**
 * @brief 周波数領域での値を保持するFPS
 */
