#define PROBLEM "https://yukicoder.me/problems/no/1283"
//
#include "../../template/template.hpp"
//
#include "../../graph/dimension-expanded-graph.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  ini(n, m);
  DimensionExpandedGraph<3> g(n, n, 2);

  vvi fee(n, vi(n));
  rep(i, m) {
    ini(h, w, c);
    --h, --w;
    fee[h][w] = c;
  }

  auto d = g.dijkstra(
      [&](auto a, auto f) {
        each(nx, a.near()) {
          if (nx[2] != a[2]) continue;
          f(nx, 1 + fee[nx[0]][nx[1]]);
          if (a[2] == 0) {
            auto nx2 = nx;
            nx2[2]++;
            f(nx2, 1);
          }
        }
      },
      {0, 0, 0});

  out(min(d[g.id(n - 1, n - 1, 0)], d[g.id(n - 1, n - 1, 1)]));
}
