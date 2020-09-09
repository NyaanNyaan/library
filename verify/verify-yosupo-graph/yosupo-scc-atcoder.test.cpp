#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../competitive-template.hpp"
#include "../../atcoder/scc.hpp"

void solve() {
  ini(N, M);
  scc_graph scc(N);
  rep(_,M) {
    ini(u,v);
    scc.add_edge(u,v);
  }
  auto res = scc.scc();
  out(res.size());
  each(x, res) {
    cout << x.size() << " " << x << endl;
  }
}
