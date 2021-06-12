#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/schoenhage-strassen-radix2.hpp"

using mint = LazyMontgomeryModInt<1000000007>;
using vm = V<mint>;
Schoenhage_Strassen_radix2<mint> ss;

/*
#include "misc/timer.hpp"

void calc() {
  int N = TEN(5) * 5;
  vm a(N), b(N);
  int e = 1;
  each(x, a) x = e, ++e;
  each(x, b) x = e, ++e;

  Timer timer;
  auto c = ss.multiply(a, b);
  cerr << c.first.size() << " " << timer.elapsed() << endl;
}

void test() {
  for (int n = 1, m = 1; n < 100; n += 2, m += 2) {
    vm a(n), b(m);
    int e = 1;
    each(x, a) x = e, e += 1;
    // each(x, b) x = e, e += 1;
    b = a;

    auto [c, d] = ss.multiply(a, b);
    mint inv = mint(1 << d).inverse();
    each(x, c) x *= inv;

    vm C(n + m - 1);
    rep(i, n) rep(j, m) C[i + j] += a[i] * b[j];
    assert(C == c);
  }
}
*/

void Nyaan::solve() {
  // test();
  // calc();

  ini(N, M);
  vm a(N), b(M);
  in(a, b);

  auto [c, d] = ss.multiply(a, b);
  mint inv = mint(1 << d).inverse();
  each(x, c) x *= inv;

  out(c);
}
