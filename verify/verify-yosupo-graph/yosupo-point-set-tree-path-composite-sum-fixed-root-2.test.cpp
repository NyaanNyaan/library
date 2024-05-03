#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
//
using mint = LazyMontgomeryModInt<998244353>;

struct Path {
  mint a, b, s, x;
};
struct Point {
  mint s, x;
};
struct Info {
  bool vertex;
  mint x, y;
};
Path vertex(const Info &i) {
  if (i.vertex) return {1, 0, i.x, 1};
  return {i.x, i.y, 0, 0};
}
Path compress(const Path &p, const Path &c) {
  return {p.a * c.a, p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x, p.x + c.x};
}
Point rake(const Point &a, const Point &b) { return {a.s + b.s, a.x + b.x}; }
Point add_edge(const Path &a) { return {a.s, a.x}; }
Path add_vertex(const Point &a, const Info &i) {
  if (i.vertex) return {1, 0, a.s + i.x, a.x + 1};
  return {i.x, i.y, a.s * i.x + a.x * i.y, a.x};
}

using DR = DynamicRerooting<Path, Point, Info, vertex, compress, rake, add_edge,
                            add_vertex>;

using namespace Nyaan;

void Nyaan::solve() {
  int N, Q;
  in(N, Q);
  vector<int> A(N);
  for (auto &x : A) in(x);
  vector<int> U(N - 1), V(N - 1), B(N - 1), C(N - 1);
  for (int i = 0; i < N - 1; i++) in(U[i], V[i], B[i], C[i]);

  vector<Info> info(2 * N - 1);
  for (int i = 0; i < N; i++) info[i] = {true, A[i], 0};
  for (int i = 0; i < N - 1; i++) info[N + i] = {false, B[i], C[i]};

  DR dr{2 * N - 1, info};
  for (int i = 0; i < N - 1; i++) {
    dr.add_edge(N + i, U[i]), dr.add_edge(N + i, V[i]);
  }

  while (Q--) {
    int cmd, i, x;
    in(cmd, i, x);
    if (cmd == 0) {
      dr.set_info(i, {true, x, 0});
    } else {
      int y;
      in(y);
      dr.set_info(N + i, {false, x, y});
    }
    out(dr.query(0).s.get());
  }
}
