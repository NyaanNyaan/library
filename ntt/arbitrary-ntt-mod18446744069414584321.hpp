#pragma once

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

struct ModInt18446744069414584321 {
  using M = ModInt18446744069414584321;
  using U = unsigned long long;
  using U128 = __uint128_t;

  static constexpr U mod = 18446744069414584321uLL;
  U x;

  static constexpr U modulo(U128 y) {
    U l = y & U(-1);
    U m = (y >> 64) & unsigned(-1);
    U h = y >> 96;
    U u = h + m + (m ? mod - (m << 32) : 0);
    U v = mod <= l ? l - mod : l;
    return v - u + (v < u ? mod : 0);
  }

  ModInt18446744069414584321() : x(0) {}
  ModInt18446744069414584321(U _x) : x(_x) {}
  U get() const { return x; }
  static U get_mod() { return mod; }

  friend M operator+(const M& l, const M& r) {
    U y = l.x - (mod - r.x);
    if (l.x < mod - r.x) y += mod;
    return M{y};
  }
  friend M operator-(const M& l, const M& r) {
    U y = l.x - r.x;
    if (l.x < r.x) y += mod;
    return M{y};
  }
  friend M operator*(const M& l, const M& r) {
    return M{modulo(U128(l.x) * r.x)};
  }
  friend M operator/(const M& l, const M& r) {
    return M{modulo(U128(l.x) * r.inverse().x)};
  }

  M& operator+=(const M& r) { return *this = *this + r; }
  M& operator-=(const M& r) { return *this = *this - r; }
  M& operator*=(const M& r) { return *this = *this * r; }
  M& operator/=(const M& r) { return *this = *this / r; }
  M operator-() const { return M{x ? mod - x : 0uLL}; }
  M operator+() const { return *this; }

  M pow(U e) const {
    M res{1}, a{*this};
    while (e) {
      if (e & 1) res = res * a;
      a = a * a;
      e >>= 1;
    }
    return res;
  }
  M inverse() const {
    assert(x != 0);
    return this->pow(mod - 2);
  }

  friend bool operator==(const M& l, const M& r) { return l.x == r.x; }
  friend bool operator!=(const M& l, const M& r) { return l.x != r.x; }
  friend ostream& operator<<(ostream& os, const M& r) { return os << r.x; }
};

struct NTT18446744069414584321 {
  using mint = ModInt18446744069414584321;
  using U = typename mint::U;

  static constexpr U mod = mint::mod;
  static constexpr U pr = 7;
  static constexpr int level = 32;
  mint dw[level], dy[level];

  void setwy(int k) {
    mint w[level], y[level];
    w[k - 1] = mint(pr).pow((mod - 1) / (1LL << k));
    y[k - 1] = w[k - 1].inverse();
    for (int i = k - 2; i > 0; --i)
      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
    for (int i = 3; i < k; ++i) {
      dw[i] = dw[i - 1] * y[i - 2] * w[i];
      dy[i] = dy[i - 1] * w[i - 2] * y[i];
    }
  }

  NTT18446744069414584321() { setwy(level); }

  void fft(vector<mint>& a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        mint ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] += ajv;
      }
    }
    int u = 1 << (2 + (k & 1));
    int v = 1 << (k - 2 - (k & 1));
    mint one = mint(1);
    mint imag = dw[1];
    while (v) {
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      mint ww = one, xx = one * dw[2], wx = one;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, wx = ww * xx;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,
               t3 = a[j2 + v] * wx;
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
        }
        xx *= dw[__builtin_ctzll((jh += 4))];
      }
      u <<= 2;
      v >>= 2;
    }
  }

  void ifft(vector<mint>& a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    mint one = mint(1);
    mint imag = dy[1];
    while (u) {
      {
        int j0 = 0;
        int j1 = v;
        int j2 = v + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      mint ww = one, xx = one * dy[2], yy = one;
      u <<= 2;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, yy = xx * imag;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;
        }
        xx *= dy[__builtin_ctzll(jh += 4)];
      }
      u >>= 4;
      v <<= 2;
    }
    if (k & 1) {
      u = 1 << (k - 1);
      for (int j = 0; j < u; ++j) {
        mint ajv = a[j] - a[j + u];
        a[j] += a[j + u];
        a[j + u] = ajv;
      }
    }
  }

  void ntt(vector<mint>& a) {
    if ((int)a.size() <= 1) return;
    fft(a, __builtin_ctz(a.size()));
  }

  void intt(vector<mint>& a) {
    if ((int)a.size() <= 1) return;
    ifft(a, __builtin_ctz(a.size()));
    mint iv = mint(a.size()).inverse();
    for (auto& x : a) x *= iv;
  }

  vector<mint> multiply(const vector<mint>& a, const vector<mint>& b) {
    int l = a.size() + b.size() - 1;
    if (min<int>(a.size(), b.size()) <= 40) {
      vector<mint> s(l);
      for (int i = 0; i < (int)a.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];
      return s;
    }
    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    setwy(k);
    vector<mint> s(M);
    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
    if (a == b) {
      fft(s, k);
      for (int i = 0; i < M; i++) s[i] *= s[i];
    } else {
      vector<mint> t(M);
      for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
      fft(s, k), fft(t, k);
      for (int i = 0; i < M; ++i) s[i] *= t[i];
    }
    ifft(s, k);
    s.resize(l);
    mint invm = mint(M).inverse();
    for (int i = 0; i < l; ++i) s[i] *= invm;
    return s;
  }

  // すべての要素が正, かつ答えの各成分が mod 以下である必要がある
  template <typename I, enable_if_t<is_integral_v<I>>* = nullptr>
  vector<unsigned long long> multiply(const vector<I>& a, const vector<I>& b) {
    if (min<int>(a.size(), b.size()) <= 40) {
      vector<U> c(a.size() + b.size() - 1);
      for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 0; j < (int)b.size(); ++j) c[i + j] += U(a[i]) * U(b[j]);
      }
      return c;
    }
    vector<mint> s(a.size()), t(b.size());
    for (int i = 0; i < (int)a.size(); i++) s[i] = a[i];
    for (int i = 0; i < (int)b.size(); i++) t[i] = b[i];
    auto u = multiply(s, t);
    vector<U> c(u.size());
    for (int i = 0; i < (int)c.size(); i++) c[i] = u[i].x;
    return c;
  }

  vector<int> bigint_mul_base_10_9(const vector<int>& a, const vector<int>& b) {
    constexpr int D = 1000000000;
    constexpr int B = 1000000;
    constexpr int C = 1000;
    auto convert = [&](const vector<int>& v) -> vector<mint> {
      vector<mint> c((v.size() * 3 + 1) / 2);
      int i = 0;
      for (; i * 2 + 1 < (int)v.size(); i++) {
        c[i * 3 + 0].x = v[i * 2 + 0] % B;
        c[i * 3 + 1].x = v[i * 2 + 0] / B + v[i * 2 + 1] % C * C;
        c[i * 3 + 2].x = v[i * 2 + 1] / C;
      }
      if (i * 2 + 1 == (int)v.size()) {
        c[i * 3 + 0].x = v[i * 2 + 0] % B;
        c[i * 3 + 1].x = v[i * 2 + 0] / B;
      }
      return c;
    };
    auto revert = [&](const vector<mint>& v) -> vector<int> {
      vector<int> c(v.size() + 4);
      int i = 0;
      U s = 0;
      for (; i < (int)v.size(); i++) s += v[i].x, c[i] = s % B, s /= B;
      while (s) c[i] = s % B, s /= B, i++;
      while (!c.empty() && c.back() == 0) c.pop_back();
      i = 0;
      for (; i * 3 + 0 < (int)c.size(); i++) {
        long long x = c[i * 3 + 0];
        c[i * 3 + 0] = 0;
        if (i * 3 + 1 < (int)c.size()) {
          x += 1LL * c[i * 3 + 1] * B;
          c[i * 3 + 1] = 0;
        }
        if (i * 3 + 2 < (int)c.size()) {
          x += 1LL * c[i * 3 + 2] * (1LL * B * B);
          c[i * 3 + 2] = 0;
        }
        c[i * 2 + 0] = x % D;
        if (i * 2 + 1 < (int)c.size()) c[i * 2 + 1] = x / D;
      }
      while (!c.empty() && c.back() == 0) c.pop_back();
      return c;
    };
    return revert(multiply(convert(a), convert(b)));
  }
};

NTT18446744069414584321 ntt18446744069414584321;

/**
 *  mod 18446744069414584321 (= 2^64 - 2^32 + 1) 上の数論変換
 */
