#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../fps/partial-fraction-decomposition.hpp"
#include "../../fps/fps-utility.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
// #include "fps/arbitrary-fps.hpp"
// using mint = LazyMontgomeryModInt<1000000007>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

void verify() {
  vector<pair<mint, int>> denom;
  vector<fps> fs;

  int size1 = 100;
  int size2 = 10;

  vector<int> xs(size1);
  for (int i = 0; i < size1; i++) {
    do {
      xs[i] = rng() % 998244353;
      int c = true;
      for (int j = 0; j < i; j++) {
        if (!c) break;
        if (xs[j] == xs[i]) c = false;
      }
      if (!c) continue;
    } while (0);
  }

  for (int i = 0; i < size1; i++) {
    mint m = xs[i];
    int d = randint(1, size2);
    denom.emplace_back(m, d);
    fps f(d + 1);
    f[0] = m, f[1] = 1;
    fs.emplace_back(f.pow(d));
  }
  auto pi = Pi(fs);

  fps numer;
  vector<pair<mint, vm>> part1;
  rep(i, size1) {
    auto [m, d] = denom[i];
    vm coeff(d);
    each(x, coeff) x = rng();
    fps f, buf{1};
    for (int j = d - 1; j >= 0; j--) {
      f += buf * coeff[j];
      buf *= fps{m, 1};
    }
    numer += f * (pi / buf);
    part1.emplace_back(m, coeff);
  }

  auto part2 = PartialFractionDecomposition<mint>(numer, denom);

  sort(all(part1),
       [](auto a, auto b) { return a.first.get() < b.first.get(); });
  sort(all(part2),
       [](auto a, auto b) { return a.first.get() < b.first.get(); });

  assert(part1 == part2);
}

void Nyaan::solve() {
  rep(loop, 100) verify();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}