#define PROBLEM "https://yukicoder.me/problems/no/705"
//
#include "../../template/template.hpp"
//
#include "../../dp/monge-shortest-path.hpp"
//
using namespace Nyaan;

void q() {
  inl(N);
  vl a(N), x(N), y(N);
  in(a, x, y);
  auto cubic = [](ll z) { return abs(z * z * z); };
  // 人 i, ゴミ j
  auto dist = [&](int i, int j) { return cubic(x[j] - a[i]) + cubic(y[j]); };
  auto f = [&](int i, int j) { return dist(j - 1, i); };
  auto ans = monge_shortest_path<ll>(N, f);
  out(ans[N]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
