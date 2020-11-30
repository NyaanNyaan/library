#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945"
//
#include "../../template/template.hpp"
//
#include "../../shortest-path/bfs01.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  WeightedGraph<int> g(10000);
  auto ok = [](int i) { return 0 <= i and i < 100; };
  auto id = [](int i, int j) { return i * 100 + j; };
  while (1) {
    int n;
    in(n);
    if (!n) break;
    int a, b, c, d;
    in(a, b, c, d);
    --a, --b, --c, --d;
    g.clear();
    g.resize(10000);
    rep(i, 100) rep(j, 100) {
      int e;
      if (a <= i and i <= c and b <= j and j <= d) {
        e = 0;
      } else {
        e = 1;
      }
      int x = 1, y = 0;
      rep(_, 4) {
        int nx = i + x;
        int ny = j + y;
        if (ok(nx) and ok(ny)) {
          g[id(nx, ny)].emplace_back(id(i, j), e);
        }
        swap(x, y = -y);
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
      auto d = bfs01(g, id(sx, sy));
      trc(d[id(tx,ty)]);
      ans += d[id(tx, ty)];
      swap(sx, tx), swap(sy, ty);
    }
    out(ans);
  }
}
