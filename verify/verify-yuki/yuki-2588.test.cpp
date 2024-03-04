#define PROBLEM "https://yukicoder.me/problems/no/2588"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/union-find.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/auxiliary-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"
#include "../../tree/tree-query.hpp"
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
  inl(N, M);
  auto G = graph(N, M);

  vvi g(N);
  {
    vi mx = mkiota(N);
    UnionFind uf(N);
    rep(i, N) each(j, G[i]) {
      if (j < i and !uf.same(i, j)) {
        int k = mx[uf.find(j)];
        g[i].push_back(k);
        g[k].push_back(i);
        uf.unite(i, k);
        mx[uf.find(i)] = i;
      }
    }
  }

  HeavyLightDecomposition hld(g, N - 1);
  Tree tree(g, N - 1);
  SegmentTree dp(
      N, [](mint a, mint b) { return a + b; }, mint{});

  AuxiliaryTree auxgen(g, N - 1);
  rep(i, N) {
    mint cur = 1;
    vi chds;
    chds.push_back(i);
    each(j, G[i]) {
      if (j < i) chds.push_back(j);
    }
    auto [aux, mp] = auxgen.get(chds);
    rep(ii, sz(aux)) each(j, aux[ii]) {
      int l = mp[ii], c = mp[j];
      int nxt = tree.nxt(l, c);
      hld.path_query(nxt, c, true,
                     [&](int u, int v) { cur += dp.query(u, v); });
    }
    dp.update(hld.idx(i).fi, cur);
  }
  out(dp.query(0, N));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
