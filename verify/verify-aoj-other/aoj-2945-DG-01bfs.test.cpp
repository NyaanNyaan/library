#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945"
// 
#include "../../template/template.hpp"
//
#include "../../graph/dimension-expanded-graph.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  DimensionExpandedGraph<2> g(100, 100);
  g.get_grid().resize(10000);
  while (1) {
    int n;
    in(n);
    if (!n) break;
    int a, b, c, d;
    in(a, b, c, d);
    --a, --b, --c, --d;
    fill(all(g.get_grid()), '#');
    rep(i, 100) rep(j, 100) {
      if (a <= i and i <= c and b <= j and j <= d) {
        g(i, j) = '.';
      }
    }
    int sx, sy;
    in(sx, sy);
    --sx, --sy;
    ll ans = 0;
    rep(i, n) {
      int tx, ty;
      in(tx, ty);
      --tx, --ty;
      auto d = g.bfs01(
          [&](auto a, auto f) {
            each(nx, a.near()) {
              if (g(nx) == '.')
                f(nx, 0);
              else
                f(nx, 1);
            }
          },
          {sx, sy});
      ans += d[g.id(tx, ty)];
      swap(sx, tx), swap(sy, ty);
    }
    out(ans);
  }
}
