
namespace ArbitraryModConvolution {

// naive convolution
template <typename T>
static vector<long long> multiply(const vector<T>& s, const vector<T>& t) {
  int l = s.size() + t.size() - 1;
  int k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  CooleyTukey::Setw(k);

  vector<C> a(M);
  for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];
  for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];
  CooleyTukey::fft(a, k);

  a[0].y = 4.0 * a[0].x * a[0].y;
  a[1].y = 4.0 * a[1].x * a[1].y;
  a[0].x = a[1].x = 0.0;
  for (int i = 2; i < M; i += 2) {
    int c = 1 << (31 - __builtin_clz(i));
    int j = i ^ (c - 1);
    a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());
    a[j] = -a[i].conj();
  }

  vector<C> b(M / 2);
  for (int j = 0; j < M / 2; j++) {
    C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];
    C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * CooleyTukey::w[j].conj();
    b[j] = tmp1 + tmp2.rotl();
  }
  CooleyTukey::ifft(b, k - 1);

  vector<long long> u(l);
  for (int i = 0; i < l; i++) {
    if (i & 1) {
      u[i] = llround(-b[i >> 1].x / (4.0 * M));
    } else {
      u[i] = llround(b[i >> 1].y / (4.0 * M));
    }
  }
  return u;
}

// naive toom-3
template <unsigned int MOD>
vector<int> toom_3_naive(const vector<int>& a, const vector<int>& b) {
  auto precalc = [](const vector<int>& _a) -> array<vector<int>, 5> {
    int n = _a.size();
    vector<int> p0(n), p1(n), pm1(n), pm2(n), pinf(n);
    for (int i = 0; i < n; i++) {
      int m0 = _a[i] & 1023;
      int m1 = (_a[i] >> 10) & 1023;
      int m2 = (_a[i] >> 20) & 1023;
      p0[i] = m0;
      p1[i] = m0 + m1 + m2;
      pm1[i] = m0 - m1 + m2;
      pm2[i] = m0 - 2 * m1 + 4 * m2;
      pinf[i] = m2;
    }
    return {{p0, p1, pm1, pm2, pinf}};
  };
  auto [a0, a1, am1, am2, ainf] = precalc(a);
  auto [b0, b1, bm1, bm2, binf] = precalc(b);
  auto c0 = multiply(a0, b0);
  auto c1 = multiply(a1, b1);
  auto cm1 = multiply(am1, bm1);
  auto cm2 = multiply(am2, bm2);
  auto cinf = multiply(ainf, binf);

  vector<int> c(c0.size());
  for (int i = 0; i < (int)c.size(); i++) {
    long long r0 = c0[i];
    long long r4 = cinf[i];
    long long r3 = (cm2[i] - c1[i]) / 3;
    long long r1 = (c1[i] - cm1[i]) / 2;
    long long r2 = cm1[i] - c0[i];
    r3 = (r2 - r3) / 2 + r4 * 2;
    r2 += r1 - r4;
    r1 -= r3;

    long long ret = r4 % MOD * 1048576;
    ret += r3 % MOD * 1024 + r2;
    ret = ret % MOD * 1048576;
    ret += r1 % MOD * 1024 + r0;
    ret %= MOD;
    if (ret < 0) ret += MOD;

    c[i] = ret;
  }
  return c;
}
}  // namespace ArbitraryModConvolution

#include "misc/fastio.hpp"
#include "misc/timer.hpp"

using namespace Nyaan;

void verify() {
  using namespace ArbitraryModConvolution;
  auto naive = [](vi a, vi b) {
    vi c(a.size() + b.size() - 1);
    rep(i, sz(a)) rep(j, sz(b)) {
      c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % (TEN(9) + 7);
    }
    return c;
  };
  constexpr unsigned MOD = TEN(9) + 7;

  auto is_same = [&naive](vi a, vi b) {
    vi c = naive(a, b);
    vi d = toom_3_naive<MOD>(a, b);
    vi e = CooleyTukey::karatsuba<MOD>(a, b);
    if (d != c or e != c) {
      out(a), out(b), out(c), out(d), out(e), exit(1);
    }
  };
  is_same({1, 2, 3, 4}, {5, 6, 7, 8, 9});
  is_same({10000000}, {10000000});

  vi a(20);
  iota(all(a), 1);
  is_same(a, a);
  iota(all(a), int(1e8));
  is_same(a, a);
  cerr << "verify ok" << endl;
}

void calc_time() {
  Timer timer;
  int M = 524288;

  auto rnd = []() {
    static long long x = 1333;
    return x = x * 5 % 1000000007;
  };
  timer.reset();
  using namespace ArbitraryModConvolution;
  rep(_, 5) {
    vi a(M), b(M);
    each(x, a) x = rnd();
    each(x, b) x = rnd();
    vi c = toom_3_naive<1000000007>(a, b);
    cerr << "toom-3 : " << timer.elapsed() << ", ";
    timer.reset();
    vi d = CooleyTukey::karatsuba<1000000007>(a, b);
    cerr << "karatsuba : " << timer.elapsed() << endl;
    timer.reset();
    assert(c == d);
  }
}
