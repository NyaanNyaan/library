#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

#include "../../misc/rng.hpp"

using namespace Nyaan;

void test_div(int n, int m) {
  trc("test div");
  assert(n > 0 and m > 0);
  fps f(n), g(m);
  each(x, f) x = rng();
  each(x, g) x = rng();
  do {
    f.back() = rng();
    g.back() = rng();
  } while (f.back() == 0 or g.back() == 0);

  auto q = f / g;
  auto r = f % g;
  assert(g * q + r == f);
  assert(r.size() < g.size());
}

void test_pow(int n, int deg) {
  trc("test pow", n, deg);
  assert(n > 0 && deg > 0);
  fps f(n);
  each(x, f) x = rng();
  int r = randint(0, 100);
  fps g = f.pow(r, deg);
  fps h(deg), base(f);
  h[0] = 1;
  for (int e = r; e; e >>= 1) {
    if (e & 1) h = (base * h).pre(deg);
    base = (base * base).pre(deg);
  }
  if (g != h) {
    trc(f, r, deg);
    trc(g);
    trc(h);
  }
  assert(g == h);
}

void test_exp(int n, int deg) {
  trc("test exp", n, deg);
  assert(n > 0 and deg > 0);
  fps f(n);
  each(x, f) x = rng();
  f[0] = 1;

  fps g = f.log(deg);
  fps h = g.exp(deg);
  f.resize(deg);
  assert(f == h);
}

void test_inv(int n, int deg) {
  trc("test inv");
  assert(n > 0 and deg > 0);
  fps f(n);
  each(x, f) x = rng();
  while (f[0] == 0) f[0] = rng();

  fps g = f.inv(deg);
  fps h = g.inv(deg);
  f.resize(deg);
  assert(f == h);
}

void Nyaan::solve() {
  rep1(i, 100) rep1(j, 100) {
    test_div(i, j);
    test_pow(i, j);
    test_exp(i, j);
    test_inv(i, j);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
