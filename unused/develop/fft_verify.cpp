
#pragma once

#include "fft_ver1.hpp"
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
    vi f = ArbitraryModConvolution2::karatsuba<MOD>(a, b);
    if (d != c or e != c or f != c) {
      out(a), out(b), out(c), out(d), out(e), out(f), exit(1);
    }
  };
  is_same({1, 2, 3, 4}, {5, 6, 7, 8, 9});
  is_same({10000000}, {10000000});

  vi a(20);
  iota(all(a), 1);
  is_same(a, a);
  iota(all(a), int(1e8));
  is_same(a, a);

  auto is_same2 = [&](vi _a, vi b) {
    auto d = multiply(_a, b);
    auto e = ArbitraryModConvolution2::multiply(_a, b);
    if (d != e) {
      out(_a), out(b), out(d), out(e), exit(1);
    }
  };
  is_same2({1, 2, 3, 4}, {5, 6, 7, 8, 9});
  is_same2({10000000}, {10000000});

  cerr << "verify ok" << endl;
}

void calc_time() {
  Timer timer;
  int M = 524288;

  auto rnd = []() {
    static long long x = 1333;
    return x = x * 5 % 1000000007;
  };
  using namespace ArbitraryModConvolution;

  rep(_, 5) {
    vi a(M), b(M);
    each(x, a) x = rnd();
    each(x, b) x = rnd();

      /*
      timer.reset();
      vi c = toom_3_naive<1000000007>(a, b);
      cerr << "toom-3 : " << timer.elapsed() << ", ";

      timer.reset();
      vi d = CooleyTukey::karatsuba<1000000007>(a, b);
      cerr << "karatsuba : " << timer.elapsed() << ", ";
      */

    timer.reset();
    vi e = ArbitraryModConvolution2::karatsuba<1000000007>(a, b);
    cerr << "karatsuba2 : " << timer.elapsed() << endl;

    // assert(c == d and d == e);
  }
}
