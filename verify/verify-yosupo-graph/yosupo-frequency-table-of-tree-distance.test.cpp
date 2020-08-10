#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../competitive-template.hpp"

#include "../../graph/graph-template.hpp"

#include "../../misc/fastio.hpp"

#include "../../tree/frequency-table-of-tree-distance.hpp"

void solve() {
  int N;
  rd(N);
  vvi g(N);
  rep(_, N - 1) {
    int u, v;
    rd(u, v);
    g[u].pb(v);
    g[v].pb(u);
  }
  FrequencyTableOfTreeDistance<vvi> ft(g);
  auto d = ft.get();
  d.resize(N);
  rep1(i, N - 1) {
    if (i != 1) wt(' ');
    wt(d[i]);
  }
  wt('\n');
}
