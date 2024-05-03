#define PROBLEM "https://yukicoder.me/problems/no/1254"
//
#include "../../template/template.hpp"
//
#include "../../graph/functional-graph.hpp"
#include "../../graph/graph-template.hpp"

using namespace Nyaan;

void q() {
  ini(N);
  WeightedGraph<int> g(N);
  map<pair<int, int>, int> es;

  rep1(i, N) {
    ini(u, v);
    --u, --v;
    es[minmax(u, v)] = i;
    g[u].emplace_back(u, v, i);
    g[v].emplace_back(v, u, i);
  }

  FunctionalGraph fg{N, g};
  auto loops = fg.get_loops_with_weight();
  assert(sz(loops) == 1);

  auto loop = loops[0];
  trc(loop);
  vi ans;
  rep(i, sz(loop)) {
    int u = loop[i].fi;
    int v = loop[(i + 1) % sz(loop)].fi;

    if (es[minmax(u, v)] != loop[i].se) exit(1);
    ans.push_back(loop[i].se);
  }
  sort(all(ans));
  out(sz(ans));
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
