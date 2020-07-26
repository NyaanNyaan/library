#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../competitive-template.cpp"
#include "../tree/rerooting.cpp"

void solve() {
  ini(N);
  auto g = wgraph<int>(N, N - 1, false, false);
  map<pair<int, int>, int> es;
  rep(i, N) each(e, g[i]) es[{e.src, e.to}] = e.cost;

  using T = pair<int, int>;
  // identify element of f1, and answer of leaf
  T I = {0, 0};
  // merge value of child node
  auto f1 = [&](T x, T y) -> T {
    T ret;
    ret.first = max(x.first, y.first);
    ret.second = max(x.first + y.first - ret.first, max(x.second, y.second));
    return ret;
  };
  // return value from child node to parent node
  auto f2 = [&](T x, int chd, int par) -> T {
    return T{x.first + es[{chd, par}], 0};
  };
  Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);
  int ans = 0;
  each(p, dp.dp) amax(ans, p.first + p.second);
  out(ans);
}