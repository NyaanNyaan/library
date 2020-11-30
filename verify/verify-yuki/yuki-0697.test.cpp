#define PROBLEM "https://yukicoder.me/problems/no/697"
//
#include "../../template/template.hpp"
//
#include "../../graph/dimension-expanded-graph.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  ini(n, m);
  DimensionExpandedGraph<2> g(n, m);

  g.get_grid().resize(n * m);
  rep(i, n) rep(j, m) in(g.get_grid()[g.id(i, j)]);

  g.uf([&](auto a, auto f) {
    each(b, a.near()) {
      if (g(a) == '1' and g(b) == '1') f(a, b);
    }
  });

  int ans = 0;
  rep(i, n) rep(j, m) {
    if(g(i,j) == '0') continue;
    auto c = g.cast(i, j);
    if (g.find(c) == c) ans++;
  }
  out(ans);
}
