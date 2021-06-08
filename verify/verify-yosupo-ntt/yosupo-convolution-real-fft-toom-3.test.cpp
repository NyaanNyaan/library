#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../ntt/complex-fft.hpp"

namespace ArbitraryModConvolution {

// naive Toom-3
template <unsigned int MOD>
vector<int> toom_3(const vector<int>& a, const vector<int>& b) {
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
  auto c0 = CooleyTukey::multiply(a0, b0);
  auto c1 = CooleyTukey::multiply(a1, b1);
  auto cm1 = CooleyTukey::multiply(am1, bm1);
  auto cm2 = CooleyTukey::multiply(am2, bm2);
  auto cinf = CooleyTukey::multiply(ainf, binf);

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

void Nyaan::solve() {
  using namespace ArbitraryModConvolution;
  int N, M;
  rd(N, M);
  vector<int> a(N), b(M);
  for (auto& x : a) rd(x);
  for (auto& x : b) rd(x);

  auto c = toom_3<1000000007>(a, b);
  // auto c = CooleyTukey::karatsuba<1000000007>(a, b);
  for (int i = 0; i < N + M - 1; i++) {
    wt(c[i], " \n"[i == N + M - 2]);
  }
}