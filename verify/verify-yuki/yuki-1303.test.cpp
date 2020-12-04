#define PROBLEM "https://yukicoder.me/problems/no/1303"

#include "../../template/template.hpp"
#include "../../data-structure/union-find.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../matrix/matrix-tree.hpp"
#include "../../matrix/polynomial-matrix-determinant.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
Binomial<mint> C;

int a[111][111];

using namespace Nyaan; void Nyaan::solve() {
  ini(N, M);
  UnionFind uf(N);
  rep(i, M) {
    ini(u, v);
    --u, --v;
    a[u][v] = a[v][u] = 1;
    uf.unite(u, v);
  }

  using P = pair<mint, int>;
  vvi memo(N);
  rep(i, N) memo[uf.find(i)].push_back(i);
  V<P> v;
  rep(i, N) {
    if (uf.find(i) == i) {
      if (sz(memo[i]) == 1) {
        v.emplace_back(1, 1);
        continue;
      }
      MatrixTree<mint> m(sz(memo[i]) - 1);
      rep(j, sz(memo[i])) rep(k, j) {
        if (a[memo[i][j]][memo[i][k]]) m.add(j, k, 1);
      }
      v.emplace_back(m.calc(), sz(memo[i]));
    }
  }

  if (sz(v) == 1) {
    MatrixTree<fps> m(N - 1);
    rep(i, N) rep(j, i) {
      if (a[i][j])
        m.add(i, j, fps{0, 1});
      else
        m.add(i, j, fps{1});
    }
    auto f = m.calc();
    out(0);
    out(f[N - 1] + f[N - 2]);
    return;
  }

  sort(all(v), [](P a, P b) { return a.second > b.second; });
  int n1 = v[0].second, n2 = v[1].second;

  ll h = -n1 * n2 * 2;
  mint ans = 1;
  each(p, v) ans *= p.first;

  mint sm = 0;
  rep(j, sz(v)) rep(i, j) {
    h += v[i].second * v[j].second * 2;
    if (v[i].second == n1 and v[j].second == n2) {
      sm += v[i].second * v[j].second;
    }
  }

  out(h);
  out(ans * sm);
}
