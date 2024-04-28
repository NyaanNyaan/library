#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
//
#include "../../template/template.hpp"
//
#include "../../graph/graph-template.hpp"
//
#include "../../tree/rerooting.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

using namespace Nyaan;

void q() {
  inl(N);
  vm A(N);
  in(A);

  using pm = pair<mint, mint>;
  vvi g(N);
  map<pi, pm> mp;
  rep(_, N - 1) {
    ini(u, v, b, c);
    g[u].push_back(v);
    g[v].push_back(u);
    mp[minmax(u, v)] = {b, c};
  }

  // 「T : 根が virtual である根付き木」に対応する情報を管理する
  using T = pair<mint, int>;
  // 空の状態に対応する情報
  T leaf = {0, 0};
  // T 同士をマージ
  auto f1 = [&](T x, T y) -> T { return {x.fi + y.fi, x.se + y.se}; };
  // T の根に頂点 c および辺 c-p を追加する (p は virtual)
  auto f2 = [&](T xn, int c, int p) -> T {
    auto [x, n] = xn;
    auto [a, b] = mp[minmax(c, p)];
    return make_pair((x + A[c]) * a + b * (n + 1), n + 1);
  };
  Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, leaf);
  auto ans = dp.dp;
  rep(i, N) cout << (ans[i].fi + A[i]) << " \n"[i + 1 == N];
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
