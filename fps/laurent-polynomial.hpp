#pragma once

// f * x^{-n}
template <typename fps>
struct Laurent {
  fps f;
  int n;
  Laurent(const fps& _f = fps{}, int _n = 0) : f(_f), n(_n) {}

  using L = Laurent;
  using mint = typename fps::value_type;

  // [x^k] 取得
  mint get(int k) const {
    int i = k + n;
    if (0 <= i and i < (int)f.size()) return f[i];
    return 0;
  }

  // 最低次を x^{-deg} にする
  void shrink_l(int deg) {
    if (n > deg) {
      f = fps{begin(f) + min<int>(n - deg, f.size()), end(f)};
      n = deg;
    }
    if (n < deg) {
      f.insert(begin(f), deg - n, {});
      n = deg;
    }
  }
  // x^{-deg} 次以降を切り捨て (=最高次を x^{-deg-1} にする)
  void shrink_r(int deg) {
    if (n - deg < (int)f.size()) f.resize(max<int>(0, n - deg));
  }

  friend L operator+(const L& l, const L& r) {
    if (l.n > r.n) {
      L x = r;
      x.shrink_l(l.n);
      return {l.f + x.f, x.n};
    } else {
      L x = l;
      x.shrink_l(r.n);
      return {x.f + r.f, x.n};
    }
  }
  friend L operator-(const L& l, const L& r) {
    if (l.n > r.n) {
      L x = r;
      x.shrink_l(l.n);
      return {l.f - x.f, x.n};
    } else {
      L x = l;
      x.shrink_l(r.n);
      return {x.f - r.f, x.n};
    }
  }
  friend L operator*(const L& l, const L& r) { return {l.f * r.f, l.n + r.n}; }
  friend ostream& operator<<(ostream& os, const L& x) {
    os << "( { ";
    for (auto& v : x.f) os << v << ", ";
    os << "}, " << x.n << ")";
    return os;
  }
};
