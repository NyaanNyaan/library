#include "template/template.hpp"
//

#include "fft_ver2.cpp"

/**
#include "fft_verify.cpp"
//*/

#include "misc/timer.hpp"

using namespace Nyaan;

void test() {
  Timer timer;
  int M = 524288;
  auto rnd = []() {
    static long long x = 1333;
    return x = x * 5 % 1000000007;
  };
  double sm = 0.0;
  rep(_, 50) {
    vi a(M), b(M);
    each(x, a) x = rnd();
    each(x, b) x = rnd();

    timer.reset();
    vi e = ArbitraryModConvolution2::karatsuba<1000000007>(a, b);
    cerr << "karatsuba2 : " << timer.elapsed() << endl;
    sm += chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - timer.st).count();
  }
  cerr << "average : " << (sm / TEN(6) / 50) << endl; 
}

#include "misc/fastio.hpp"

namespace ArbitraryModConvolution2 {

template <unsigned int MOD>
void solve() {
  using u64 = unsigned long long;
  constexpr unsigned int B = 32000;
  static_assert(1uLL * B * B < 1uLL << 32);
  auto round = [](double x) -> u64 { return u64(x + 0.5); };

  int n, m;
  rd(n, m);
  int l = n + m - 1, k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  Setw(k);

  for (int i = 0; i < n; i++) {
    unsigned int x;
    rd(x);
    alr[i] = double(x % B), ali[i] = double(x / B);
  }
  for (int i = 0; i < m; i++) {
    unsigned int x;
    rd(x);
    blr[i] = double(x % B), bli[i] = double(x / B);
  }

  fft_real(alr, ali, ahr, ahi, k);
  fft_real(blr, bli, bhr, bhi, k);

  for (int i = 0; i < M; i++) {
    double tmp1r = alr[i], tmp1i = ali[i];
    double tmp2r = -ahi[i], tmp2i = ahr[i];
    double tmp3r = tmp1r, tmp3i = tmp1i;
    double tmp4r = tmp2r, tmp4i = tmp2i;
    mul(tmp1r, tmp1i, blr[i], bli[i]);
    mul(tmp2r, tmp2i, bhr[i], bhi[i]);
    mul(tmp3r, tmp3i, bhr[i], bhi[i]);
    mul(tmp4r, tmp4i, blr[i], bli[i]);
    blr[i] = tmp1r + tmp2r, bli[i] = tmp1i + tmp2i;
    bhr[i] = tmp3r + tmp4r, bhi[i] = tmp3i + tmp4i;
  }

  ifft(blr, bli, k);
  ifft(bhr, bhi, k);

  double im = 1.0 / (4.0 * M);
  for (int i = 0; i < l; i++) {
    blr[i] *= im, bli[i] *= im;
    bhr[i] *= im, bhi[i] *= im;
    int x1 = round(blr[i]) % MOD;
    int x2 = (round(bhr[i]) + round(bhi[i])) % MOD * B % MOD;
    int x3 = round(bli[i]) % MOD * (B * B % MOD) % MOD;
    if ((x1 += x2) >= (int)MOD) x1 -= MOD;
    if ((x1 += x3) >= (int)MOD) x1 -= MOD;
    wt(x1);
    wt(" \n"[i == l - 1]);
  }
}

}  // namespace ArbitraryModConvolution2

void Nyaan::solve() {

#ifdef PROFILER
  // verify();
  test();
  return;
  //*/
#endif

#ifdef NyaanLocal
  test();
  return;
#endif

  ArbitraryModConvolution2::solve<1000000007>();
}
