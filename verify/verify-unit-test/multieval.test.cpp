#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
#include "../../fps/fast-multieval.hpp"
#include "../../fps/multipoint-evaluation.hpp"
//
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using fps = FormalPowerSeries<mint>;

#include "../../misc/rng.hpp"

void test(int n, int s) {
  // cerr<<n<<" "<<s<<endl;
  fps f(s);
  vm xs(n);
  each(x, f) x = rng();
  each(x, xs) x = rng();
  auto ys1 = FastMultiEval(f, xs);
  auto ys2 = MultipointEvaluation(f, xs);
  vm ys3(n);
  rep(i, n) ys3[i] = f.eval(xs[i]);
  assert(ys1 == ys2);
  assert(ys2 == ys3);
}

using namespace Nyaan;
void Nyaan::solve() {
  rep(i, 66) rep(j, 66) rep(k, 5) test(i, j);

  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
