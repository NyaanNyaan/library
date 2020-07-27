#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include "../competitive-template.hpp"
#include "../tree/rerooting.hpp"

void solve() {
  ini(N);
  auto g = wgraph<int>(N, N - 1, false, false);
  map<pair<int, int>, int> es;
  rep(i, N) each(e, g[i]) es[{e.src, e.to}] = e.cost;

  using T = int;
  // identify element of f1, and answer of leaf
  T I = 0;
  // merge value of child node
  auto f1 = [&](T x, T y) -> T { return max(x, y); };
  // return value from child node to parent node
  auto f2 = [&](T x, int chd, int par) -> T { return x + es[{chd, par}]; };
  Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

  rep(i,N) out(dp.dp[i]);
}