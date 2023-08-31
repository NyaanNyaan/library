#pragma once

#include "rader-ntt.hpp"

template <typename mint>
struct ArbitraryLengthNTT {
  using i64 = long long;

  int factor(int n) {
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) return i;
    return n;
  }

  vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ret.push_back(i);
        ret.push_back(n / i);
      }
    }
    ret.push_back(n);
    sort(begin(ret), end(ret));
    ret.erase(unique(begin(ret), end(ret)), end(ret));
    return ret;
  }

  int len;
  vector<mint> w;
  vector<int> divisors;
  map<int, RaderNTT<mint> *> rader;

  ArbitraryLengthNTT(int len_ = -1) { set_len(len_); }

  void set_len(int len_ = -1) {
    int mod = mint::get_mod();
    if ((len = len_) == -1) len = mod - 1;
    if (mod >= 3 && len <= 1) len = 2;
    while ((mod - 1) % len != 0) ++len;
    mint pr = mint(constexpr_primitive_root(mod)).pow((mod - 1) / len);
    w.resize(len + 1);
    for (int i = 0; i <= len; i++) w[i] = i ? w[i - 1] * pr : mint(1);
    divisors = divisor(len);
  }

  void dft(vector<mint> &a) {
    int N = a.size();
    if (N == 2) {
      mint a01 = a[0] + a[1];
      a[1] = a[0] - a[1];
      a[0] = a01;
      return;
    }
    int d = len / N;
    vector<mint> b(N);
    for (int i = 0, dk = 0; i < N; i++, dk += d) {
      for (int j = 0, k = 0; j < N; j++) {
        b[j] += a[i] * w[k];
        if ((k += dk) >= len) k -= len;
      }
    }
    swap(a, b);
  }

  void ntt_base2(vector<mint> &a) {
    static vector<int> btr;
    int N = a.size();
    assert(N % 2 == 0);
    if (btr.size() != a.size()) {
      btr.resize(N);
      int b = __builtin_ctz(N);
      assert(N == (1 << b));
      for (int i = 0; i < N; i++) {
        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));
      }
    }
    static vector<mint> basis;
    if (basis.size() < a.size()) {
      basis.resize(N);
      mint b = w[len / N];
      for (int i = N >> 1; i > 0; i >>= 1) {
        mint c = 1;
        for (int j = 0; j < i; ++j) {
          basis[i + j] = c;
          c *= b;
        }
        b *= b;
      }
    }
    for (int i = 0; i < N; i++)
      if (i < btr[i]) swap(a[i], a[btr[i]]);
    for (int k = 1; k < N; k <<= 1) {
      for (int i = 0; i < N; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          mint z = a[i + j + k] * basis[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  void pntt(vector<mint> &a) {
    int P = a.size();
    if (P <= 64) {
      dft(a);
      return;
    }
    if (rader.find(P) == end(rader)) rader[P] = new RaderNTT<mint>(P, len, w);
    rader[P]->ntt(a);
  }

  void ntt(vector<mint> &a) {
    assert(len % a.size() == 0);
    int N = (int)a.size();
    if (N <= 1) return;
    if (N <= 64) {
      dft(a);
      return;
    }

    int P = factor(N);
    if (P == N) {
      pntt(a);
      return;
    }
    if (P == 2) {
      P = 1 << __builtin_ctz(N);
      if (N == P) {
        ntt_base2(a);
        return;
      }
    }

    int Q = N / P;
    vector<mint> t(N), u(P);
    {
      vector<mint> s(Q);
      for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {
        for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];
        ntt(s);
        for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {
          t[pQ + r] = w[n] * s[r];
        }
      }
    }
    for (int r = 0; r < Q; r++) {
      for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];
      if (P <= 64)
        dft(u);
      else if (P & 1)
        pntt(u);
      else
        ntt_base2(u);
      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ + r] = u[s];
    }
  }

  void intt(vector<mint> &a) {
    reverse(begin(a) + 1, end(a));
    ntt(a);
    mint invn = mint(a.size()).inverse();
    for (auto &x : a) x *= invn;
  }

  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    int N = (int)a.size() + (int)b.size() - 1;
    assert(N <= len);
    vector<mint> s(a), t(b);
    int l = *lower_bound(begin(divisors), end(divisors), N);
    s.resize(l, mint(0));
    t.resize(l, mint(0));
    ntt(s);
    ntt(t);
    for (int i = 0; i < l; i++) s[i] *= t[i];
    intt(s);
    s.resize(N);
    return s;
  }
};

/**
 * @brief Cooley-Tukey FFT Algorithm
 */
