#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"

using namespace Nyaan;

#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../set-function/and-convolution.hpp"
#include "../../set-function/or-convolution.hpp"
#include "../../set-function/xor-convolution.hpp"
using mint = LazyMontgomeryModInt<998244353>;

template <typename T>
void test(int n) {
  assert((n & (n - 1)) == 0);
  vector<T> a(n), b(n), c(n);

  rep(i, n) {
    a[i] = rng() & 0xFFFF;
    b[i] = rng() & 0xFFFF;
  }

  {
    auto d = a;
    subset_zeta_transform(d);
    subset_mobius_transform(d);
    assert(a == d && "subset");
  }

  {
    auto d = a;
    superset_zeta_transform(d);
    superset_mobius_transform(d);
    assert(a == d && "superset");
  }

  {
    auto d = a;
    walsh_hadamard_transform(d);
    walsh_hadamard_transform(d, true);
    assert(a == d && "hadamard");
  }

  // and convolution
  {
    auto d = and_convolution(a, b);
    fill(all(c), 0);
    rep(i, n) rep(j, n) c[i & j] += a[i] * b[j];
    assert(c == d && "and");
  }

  // or convolution
  {
    auto d = or_convolution(a, b);
    fill(all(c), 0);
    rep(i, n) rep(j, n) c[i | j] += a[i] * b[j];
    assert(c == d && "or");
  }

  // xor convolution
  {
    auto d = xor_convolution(a, b);
    fill(all(c), 0);
    rep(i, n) rep(j, n) c[i ^ j] += a[i] * b[j];
    assert(c == d && "xor");
  }
}

void Nyaan::solve() {
  for (int i = 1; i <= 1024; i *= 2) {
    test<ll>(i);
    test<mint>(i);
  }
  cerr << "ok" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
