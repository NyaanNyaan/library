#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace FastFourierTransform {
using real = double;

struct C {
  real x, y;

  C() : x(0), y(0) {}

  C(real x, real y) : x(x), y(y) {}

  inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

  inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

  inline C operator*(const C &c) const {
    return C(x * c.x - y * c.y, x * c.y + y * c.x);
  }

  inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  rts.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  while (base < nbase) {
    real angle = PI * 2.0 / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      real angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void fft(vector<C> &a, int n) {
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = a[i + j + k] * rts[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

template <typename mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  vector<C> fa(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i].get() : 0);
    int y = (i < (int)b.size() ? b[i].get() : 0);
    fa[i] = C(x, y);
  }
  fft(fa, sz);
  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
    fa[i] = A0 + A1 * s;
  }
  fft(fa, sz >> 1);
  vector<mint> ret(need);
  for (int i = 0; i < need; i++) {
    ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
  }
  return ret;
}
};  // namespace FastFourierTransform

template <typename T>
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  static vector<T> multiply(const vector<T> &a, const vector<T> &b,
                            int need = -1) {
    if (need == -1) need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    FastFourierTransform::ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for (int i = 0; i < (int)a.size(); i++) {
      fa[i] = C(a[i].get() & ((1 << 15) - 1), a[i].get() >> 15);
    }
    fft(fa, sz);
    vector<C> fb(sz);
    if (a == b) {
      fb = fa;
    } else {
      for (int i = 0; i < (int)b.size(); i++) {
        fb[i] = C(b[i].get() & ((1 << 15) - 1), b[i].get() >> 15);
      }
      fft(fb, sz);
    }
    real ratio = 0.25 / sz;
    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C a1 = (fa[i] + fa[j].conj());
      C a2 = (fa[i] - fa[j].conj()) * r2;
      C b1 = (fb[i] + fb[j].conj()) * r3;
      C b2 = (fb[i] - fb[j].conj()) * r4;
      if (i != j) {
        C c1 = (fa[j] + fa[i].conj());
        C c2 = (fa[j] - fa[i].conj()) * r2;
        C d1 = (fb[j] + fb[i].conj()) * r3;
        C d2 = (fb[j] - fb[i].conj()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<T> ret(need);
    for (int i = 0; i < need; i++) {
      int64_t aa = llround(fa[i].x);
      int64_t bb = llround(fb[i].x);
      int64_t cc = llround(fa[i].y);
      aa = T(aa).get(), bb = T(bb).get(), cc = T(cc).get();
      ret[i] = aa + (bb << 15) + (cc << 30);
    }
    return ret;
  }
};

template <typename mint>
struct ArbitraryLengthNTT {
  using i64 = long long;

  static int modpow(i64 a, i64 p, int m) {
    i64 r = 1 % m;
    for (a %= m; p; a = a * a % m, p >>= 1)
      if (p & 1) r = r * a % m;
    return r;
  }

  static int factor(int n) {
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) return i;
    return n;
  }

  static vector<int> divisor(int n) {
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

  static int get_pr(int m) {
    vector<int> st;
    for (int i = m - 1; i != 1; i /= st.back()) st.push_back(factor(i));
    st.erase(unique(begin(st), end(st)), end(st));
    for (int pr = 1, flg = 1; pr < m; ++pr, flg = 1) {
      for (auto &x : st)
        if (modpow(pr, (m - 1) / x, m) == 1) flg = 0;
      if (flg) return pr;
    }
    exit(1);
  }

  struct LaderNTT {
    int p, pr;
    vector<int> prs, iprs;
    LaderNTT() {}
    LaderNTT(int p_) : p(p_), pr(get_pr(p_)), prs(p_ - 1), iprs(p_, -1) {
      for (int i = 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;
      for (int i = 0; i < p - 1; i++) iprs[prs[i]] = i;
    }

    void ntt(vector<mint> &a) {
      vector<mint> s(p - 1), t(p - 1);
      for (int i = 0; i < p - 1; i++) s[i] = a[prs[i]];
      for (int i = 0, ldp = len / p; i < p - 1; i++)
        t[i] = w[ldp * prs[i ? p - 1 - i : 0]];
      vector<mint> u = ArbitraryModConvolution<mint>::multiply(s, t);
      s.resize(p);
      fill(begin(s), end(s), a[0]);
      for (int i = 1; i < p; i++) s[0] += a[i];
      for (int i = 0, y = 0; i < (int)u.size(); i++) {
        s[prs[y]] += u[i];
        if (--y < 0) y += p - 1;
      }
      swap(a, s);
    }
  };

  static int len;
  static vector<mint> w;
  static vector<int> divisors;
  static map<int, LaderNTT *> lader;

  ArbitraryLengthNTT(int len_ = -1) {
    int mod = mint::get_mod();
    if ((len = len_) == -1) len = mod - 1;
    if (mod >= 3 && len <= 1) len = 2;
    while ((mod - 1) % len != 0) ++len;
    w.resize(len + 1);
    mint pr = mint(get_pr(mod)).pow((mod - 1) / len);
    for (int i = 0; i <= len; i++) w[i] = i ? w[i - 1] * pr : mint(1);
    divisors = divisor(len);
  }

  static void dft(vector<mint> &a) {
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

  static void ntt_base2(vector<mint> &a) {
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

  static void pntt(vector<mint> &a) {
    int P = a.size();
    if (P <= 64) {
      dft(a);
      return;
    }
    if (lader.find(P) == end(lader)) lader[P] = new LaderNTT(P);
    lader[P]->ntt(a);
  }

  static void ntt(vector<mint> &a) {
    assert(len % a.size() == 0);
    int N = (int)a.size();
    if(N <= 1) return;
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
    vector<mint> s(Q), t(N), u(P);
    for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {
      for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];
      ntt(s);
      for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {
        t[pQ + r] = w[n] * s[r];
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

  static void intt(vector<mint> &a) {
    reverse(begin(a) + 1, end(a));
    ntt(a);
    mint invn = mint(a.size()).inverse();
    for (auto &x : a) x *= invn;
  }

  static vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
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
template <typename mint>
int ArbitraryLengthNTT<mint>::len;
template <typename mint>
vector<mint> ArbitraryLengthNTT<mint>::w;
template <typename mint>
vector<int> ArbitraryLengthNTT<mint>::divisors;
template <typename mint>
map<int, typename ArbitraryLengthNTT<mint>::LaderNTT *>
    ArbitraryLengthNTT<mint>::lader;
