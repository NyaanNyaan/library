#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../dp/concave-min-plus-convolution.hpp"
using namespace Nyaan;

void test() {
  rep(_, 10000) {
    int N = rng(1, 30);
    int M = rng(1, 30);

    vi a(N), b(M);
    a[0] = -30;
    for (int i = 1, d = -10; i < N; i++, d += rng(1, 10)) {
      a[i] = a[i - 1] + d;
    }
    each(x, b) x = rng(-30, 30);
    auto c = concave_min_plus_convolution(a, b);
    vi d(N + M - 1, inf);
    rep(i, N) rep(j, M) amin(d[i + j], a[i] + b[j]);
    if (c != d) {
      trc(a, b);
      trc(c);
      trc(d);
      exit(1);
    }
  }
  trc2("OK");
}

void q() {
  test();
  ini(N, M);
  vi a(N), b(M);
  in(a, b);
  out(concave_min_plus_convolution(a, b));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
