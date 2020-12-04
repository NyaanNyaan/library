#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../../template/template.hpp"
#include "../../misc/fastio.hpp"
#include "../../graph/max-independent-set.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, M;
  rd(N, M);
  vector<vector<int>> g(N);
  rep(i, M) {
    int u, v;
    rd(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto ans = max_independent_set<40>(g);
  wtn(ans.size());
  rep(i, ans.size()) wt(ans[i], (i == (int)ans.size() - 1 ? '\n' : ' '));
}