#define PROBLEM "https://yukicoder.me/problems/no/2677"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
using namespace Nyaan;

using Path = array<array<int, 2>, 2>;
struct Point {
  int c0, c01;
};
using Info = int;
Path vertex(const Info &i) {
  Path p;
  rep(j, 2) rep(k, 2) p[j][k] = -inf;
  if (i != 1) p[0][0] = 0;
  if (i != 0) p[1][1] = 1;
  return p;
}
Path compress(const Path &p, const Path &c) {
  Path r;
  rep(i, 2) rep(j, 2) r[i][j] = -inf;
#define f(i, j, k, l) amax(r[i][l], p[i][j] + c[k][l])
  f(0, 0, 0, 0);
  f(0, 0, 0, 1);
  f(0, 0, 1, 0);
  f(0, 0, 1, 1);
  f(0, 1, 0, 0);
  f(0, 1, 0, 1);
  f(1, 0, 0, 0);
  f(1, 0, 0, 1);
  f(1, 0, 1, 0);
  f(1, 0, 1, 1);
  f(1, 1, 0, 0);
  f(1, 1, 0, 1);
#undef f
  return r;
}
Point rake(const Point &a, const Point &b) {
  return {a.c0 + b.c0, a.c01 + b.c01};
}
Point add_edge(const Path &a) {
  int c0 = max(a[0][0], a[0][1]);
  int c01 = max({a[0][0], a[0][1], a[1][0], a[1][1]});
  return {c0, c01};
}
Path add_vertex(const Point &a, const Info &i) {
  Path p;
  rep(j, 2) rep(k, 2) p[j][k] = -inf;
  if (i != 1) p[0][0] = a.c01;
  if (i != 0) p[1][1] = a.c0 + 1;
  return p;
}

using DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,
                            add_vertex>;

void q() {
  ini(N);
  DR dr(N, V<Info>(N, -1));
  rep(i, N - 1) {
    ini(u, v);
    --u, --v;
    dr.add_edge(u, v);
  }
  int ans = inf;
  rep(i, N) {
    auto q = dr.query(i);
    amin(ans, max(q[1][0], q[1][1]));
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
