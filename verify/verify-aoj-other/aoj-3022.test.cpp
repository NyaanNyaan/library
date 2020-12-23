#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3022"

#include "../../template/template.hpp"
//
#include "../../graph/graph-template.hpp"
#include "../../tree/block-cut-tree.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(n, m);
  vl w(n);
  in(w);
  auto g = graph(n, m);

  BlockCutTree<vvi> bct(g);
  vl W(sz(bct.aux));

  rep(i, n) W[bct.id(i)] += w[i];

  vl ans(n), nwans(bct.size());
  ll sm = accumulate(all(w), 0LL);

  auto dfs = [&](auto rc, int cur, int par) -> ll {
    vl chd;
    each(dst, bct[cur]) {
      if (dst == par) continue;
      chd.push_back(rc(rc, dst, cur));
    }
    ll csm = accumulate(all(chd), 0LL) + W[cur];
    ll cmx = sz(chd) ? *max_element(all(chd)) : 0;
    if (cur < bct.arti()) nwans[cur] = max(sm - csm, cmx);
    return csm;
  };
  dfs(dfs, 0, -1);

  rep(i, n) {
    if (!bct.is_arti(i))
      ans[i] = sm - w[i];
    else
      ans[i] = nwans[bct.id(i)];
  }

  each(x, ans) out(x);
}
