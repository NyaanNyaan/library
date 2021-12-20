#define PROBLEM "https://yukicoder.me/problems/no/1789"
//
#include "../../template/template.hpp"
//
#include "../../atcoder/mincostflow.hpp"
#include "../../graph/graph-template.hpp"
#include "../../tree/convert-tree.hpp"
#include "../../tree/tree-hash.hpp"

using namespace Nyaan;

using Hash = typename TreeHash<vvi>::Hash;

vi sub(vvi g, int r) {
  int N = sz(g);
  vi res(N, -1);
  auto dfs = [&](auto rc, int c, int p = -1,
                 [[maybe_unused]] ll dat = 0) -> void {
    res[c] = 1;
    for (auto& d : g[c]) {
      if (d == p) continue;
      rc(rc, d, c);
      res[c] += res[d];
    }
  };
  dfs(dfs, r);
  return res;
}
map<pair<Hash, Hash>, int> memo;

int sol(int, vvi g, int, vvi h, int hr) {
  g = rooted_tree(g, 0);
  h = rooted_tree(h, hr);
  TreeHash hag(g, 0);
  TreeHash hah(h, hr);
  vi subg = sub(g, 0);
  vi subh = sub(h, hr);

  auto calc = [&](auto rc, int cg, int ch, bool ke = false) -> ll {
    pair<Hash, Hash> pa;
    if (!ke) {
      if (subg[cg] > subh[ch]) return inf;
      if (sz(g[cg]) > sz(h[ch])) return inf;
      pa = make_pair(hag.hash[cg], hah.hash[ch]);
    } else {
      if (subg[cg] + 1 > subh[ch]) return inf;
      auto h2 = hag.hash[cg] + hag.xs()[hag.depth[cg] + 1];
      pa = make_pair(h2, hah.hash[ch]);
    }
    if (memo.find(pa) != end(memo)) return memo[pa];

    using HS = pair<Hash, int>;
    map<HS, pl> mpg, mph;
    int kog = 0, koh = 0;
    if (ke) {
      mpg[{hag.hash[cg], subg[cg]}] = {1, cg};
      kog = 1;
    } else {
      each(d, g[cg]) {
        auto& p = mpg[{hag.hash[d], subg[d]}];
        p.first++;
        p.second = d;
        kog++;
      }
    }
    each(d, h[ch]) {
      auto& p = mph[{hah.hash[d], subh[d]}];
      p.first++;
      p.second = d;
      koh++;
    }

    V<pair<HS, pl>> mpg2, mph2;
    each(p, mpg) mpg2.push_back(p);
    each(p, mph) mph2.push_back(p);

    atcoder::mcf_graph<ll, ll> mcf(sz(mpg) + 1 + sz(mph) + 2);
    int sg = sz(mpg2) + 1;
    int sh = sz(mph2);
    int S = sg + sh + 0;
    int T = sg + sh + 1;

    rep(i, sg - 1) mcf.add_edge(S, i + 0u, mpg2[i].second.first, 0);
    rep(i, sh + 0) mcf.add_edge(i + sg, T, mph2[i].second.first, 0);
    mcf.add_edge(S, sg - 1, koh - kog, 0);

    rep(i, sg) rep(j, sh) {
      int cost = inf;
      if (i == sz(mpg2)) {
        cost = mph2[j].first.second;
      } else {
        int daig = mpg2[i].second.second;
        int daih = mph2[j].second.second;
        cost = rc(rc, daig, daih);
        amin(cost, rc(rc, daig, daih, true));
      }
      mcf.add_edge(i, sg + j, inf, cost);
    }

    auto [fl, ans] = mcf.flow(S, T);
    if (ans > inf) ans = inf;
    return memo[pa] = ans;
  };
  return calc(calc, 0, hr);
}

void Nyaan::solve() {
  inl(K);
  auto g = graph(K);
  inl(N);
  auto h = graph(N);

  ll ans = inf;
  rep(i, N) {
    int cur = sol(K, g, N, h, i);
    amin(ans, cur);
  }
  if (ans == inf)
    ans = -1;
  else
    ans = N - 1 - ans;
  out(ans);
}