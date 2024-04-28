#define PROBLEM "https://yukicoder.me/problems/no/768"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
using namespace Nyaan;

struct Path {
  int v, u0, u1;
};
using Point = int;
using Info = int;
Path vertex(const Info &) { return {0, 0, 1}; }
Path compress(const Path &p, const Path &c) {
  Path r;
  r.v = c.v;
  int w0 = p.v | (c.u0 ^ 1);
  r.u0 = w0 ? p.u1 : p.u0;
  int w1 = p.v | (c.u1 ^ 1);
  r.u1 = w1 ? p.u1 : p.u0;
  return r;
}
Point rake(const Point &a, const Point &b) { return a | b; }
Point add_edge(const Path &a) { return (a.v ? a.u1 : a.u0) ^ 1; }
Path add_vertex(const Point &a, const Info &) { return {a, 0, 1}; }

using DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,
                            add_vertex>;

void q() {
  ini(N);
  DR dr(N, vi(N));
  rep(i, N - 1) {
    ini(a, b);
    --a, --b;
    dr.add_edge(a, b);
  }
  vi ans;
  rep(i, N) {
    auto q = dr.query(i);
    int u = q.v ? q.u1 : q.u0;
    if (u == 0) ans.push_back(i + 1);
  }
  out(sz(ans));
  each(x, ans) out(x);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
