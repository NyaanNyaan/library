#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1130"
//
#include "../../template/template.hpp"
//
#include "../../graph/dimension-expanded-graph.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  while (1) {
    int H, W;
    in(W, H);
    if (H * W == 0) break;
    DimensionExpandedGraph<2> g(H, W);
    in(g);
    auto st = g.find('@');
    auto d = g.bfs(
        [&](auto a, auto f) { each(x, a.near()) if (g(x) != '#') f(x); }, st);
    ll ans = 0;
    each(x, d) if (~x) ans++;
    out(ans);
  }
}
