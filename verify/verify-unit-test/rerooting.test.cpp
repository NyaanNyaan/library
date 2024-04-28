#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../graph/graph-template.hpp"
//
#include "../../tree/rerooting.hpp"
//
#include "../../misc/rng.hpp"
#include "../../tree/pruefer-code.hpp"
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

vm naive(int N, vvi g, vm A) {
  auto dfs = [&](auto rc, int c, int p) -> mint {
    vm chds;
    each(d, g[c]) {
      if (d == p) continue;
      chds.push_back(rc(rc, d, c));
    }
    if (chds.empty()) return A[c];
    mint prod = 1;
    each(x, chds) prod *= x;
    return prod + A[c];
  };
  vm ans(N);
  rep(i, N) ans[i] = dfs(dfs, i, -1);
  return ans;
}

vm calc(int N, vvi g, vm A) {
  mint I = 0;
  auto f1 = [&](mint x, mint y) { return x * y; };
  auto f2 = [&](mint x, int c, int) { return x + A[c]; };
  Rerooting rt{g, f1, f2, I};
  auto ans = rt.dp;
  rep(i, N) ans[i] += A[i];
  return ans;
}

void test() {
  rep(t, 10000) {
    int N = rng(1, 10);
    vvi g = random_tree(N);
    vm A(N);
    each(x, A) x = rng();
    auto an = naive(N, g, A);
    auto ac = calc(N, g, A);
    assert(an == ac);
  }
  trc2("OK");
}

void q() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
