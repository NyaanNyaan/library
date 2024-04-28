#define PROBLEM "https://yukicoder.me/problems/no/1976"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
//
using namespace Nyaan;

template <typename T>
struct HalfPathData {
  T d;
  int u;
  friend HalfPathData max(const HalfPathData& lhs, const HalfPathData& rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    return lhs.u > rhs.u ? lhs : rhs;
  }
};
template <typename T>
struct PathData {
  T d;
  int u, v;
  friend PathData max(const PathData& lhs, const PathData& rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    if (lhs.u != rhs.u) return lhs.u > rhs.u ? lhs : rhs;
    return lhs.v > rhs.v ? lhs : rhs;
  }
};
template <typename T>
struct Point {
  PathData<T> dia;
  HalfPathData<T> d1, d2;
};
template <typename T>
struct Path {
  PathData<T> dia;
  HalfPathData<T> pd, cd;
  T p_to_c;
  int p, c;
};
template <typename T>
struct Info {
  T x;
  int i;
};
template <typename T>
Path<T> vertex(const Info<T>& info) {
  auto [x, i] = info;
  Path<T> r;
  r.dia = {x, i, i};
  r.pd = r.cd = {x, i};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}
template <typename T>
Path<T> compress(const Path<T>& p, const Path<T>& c) {
  Path<T> r;
  r.dia = max(max(p.dia, c.dia), {p.cd.d + c.pd.d, p.cd.u, c.pd.u});
  r.pd = max(p.pd, {p.p_to_c + c.pd.d, c.pd.u});
  r.cd = max(c.cd, {c.p_to_c + p.cd.d, p.cd.u});
  r.p_to_c = p.p_to_c + c.p_to_c;
  r.p = p.p, r.c = c.c;
  return r;
}
template <typename T>
Point<T> rake(const Point<T>& a, const Point<T>& b) {
  Point<T> r;
  r.dia = max(a.dia, b.dia);
  if (a.d1.d > b.d1.d) {
    r.d1 = a.d1;
    r.d2 = max(a.d2, b.d1);
  } else {
    r.d1 = b.d1;
    r.d2 = max(b.d2, a.d1);
  }
  return r;
}
template <typename T>
Point<T> add_edge(const Path<T>& a) {
  Point<T> r;
  r.dia = a.dia;
  r.d1 = a.pd;
  r.d2 = {0, -1};
  return r;
}
template <typename T>
Path<T> add_vertex(const Point<T>& a, const Info<T>& info) {
  auto [x, i] = info;
  Path<T> r;
  r.dia = max(a.dia, {a.d1.d + x + a.d2.d, a.d1.u, a.d2.u});
  r.pd = r.cd = {a.d1.d + x, a.d1.u};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}

template <typename T>
using DR = DynamicRerooting<Path<T>, Point<T>, Info<T>, vertex<T>, compress<T>,
                            rake<T>, add_edge<T>, add_vertex<T>>;

void q() {
  ini(N);
  vi u(N - 1), v(N - 1);
  in2(u, v);
  each(x, u)-- x;
  each(x, v)-- x;

  V<Info<int>> init(2 * N - 1);
  rep(i, N) init[i] = {0, int(i)};
  rep(i, N - 1) init[N + i] = {1, -1};
  DR<int> dr(2 * N - 1, init);

  rep(i, N - 1) {
    int a = u[i], b = v[i];
    dr.add_edge(a, N + i);
    dr.add_edge(b, N + i);
  }

  ll ans = inf;
  rep(i, N - 1) {
    int a = u[i], b = v[i];
    int x = dr.query_subtree(b, a).dia.d;
    int y = dr.query_subtree(a, b).dia.d;
    amin(ans, max({x, y, (x + 1) / 2 + (y + 1) / 2 + 1}));
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
