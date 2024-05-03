#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
#include "../../tree/static-top-tree-vertex-based.hpp"
//
using mint = LazyMontgomeryModInt<998244353>;

struct Path {
  mint a, b, s, x;
};
struct Point {
  mint s, x;
};
vector<mint> calc(int N, int Q, vector<int> A, vector<int> U, vector<int> V,
                  vector<int> B, vector<int> C, vector<int> cmd, vector<int> I,
                  vector<int> X, vector<int> Y) {
  vector<vector<int>> g(2 * N - 1);
  rep(e, N - 1) {
    g[N + e].push_back(U[e]), g[U[e]].push_back(N + e);
    g[N + e].push_back(V[e]), g[V[e]].push_back(N + e);
  }
  auto vertex = [&](int i) -> Path {
    if (i < N) return {1, 0, A[i], 1};
    int e = i - N;
    return {B[e], C[e], 0, 0};
  };
  auto compress = [&](const Path& p, const Path& c) -> Path {
    return {p.a * c.a, p.a * c.b + p.b, p.s + p.a * c.s + p.b * c.x, p.x + c.x};
  };
  auto rake = [&](const Point& a, const Point& b) -> Point {
    return {a.s + b.s, a.x + b.x};
  };
  auto add_edge = [&](const Path& a) -> Point { return {a.s, a.x}; };
  auto add_vertex = [&](const Point& a, int i) -> Path {
    if (i < N) return {1, 0, a.s + A[i], a.x + 1};
    int e = i - N;
    return {B[e], C[e], a.s * B[e] + a.x * C[e], a.x};
  };

  HeavyLightDecomposition hld{g};
  DPonStaticTopTreeVertexBased<
      vector<vector<int>>, Path, Point, decltype(vertex), decltype(compress),
      decltype(rake), decltype(add_edge), decltype(add_vertex)>
      dp(hld, vertex, compress, rake, add_edge, add_vertex);

  vector<mint> ans(Q);
  rep(q, Q) {
    if (cmd[q] == 0) {
      A[I[q]] = X[q];
      dp.update(I[q]);
    } else {
      B[I[q]] = X[q], C[I[q]] = Y[q];
      dp.update(N + I[q]);
    }
    ans[q] = dp.get().s;
  }
  return ans;
}

void Nyaan::solve() {
  int N, Q;
  in(N, Q);
  vector<int> A(N);
  for (auto& x : A) in(x);
  vector<int> U(N - 1), V(N - 1), B(N - 1), C(N - 1);
  rep(i, N - 1) in(U[i], V[i], B[i], C[i]);
  vector<int> cmd(Q), I(Q), X(Q), Y(Q, -1);
  rep(i, Q) {
    in(cmd[i], I[i], X[i]);
    if (cmd[i] == 1) in(Y[i]);
  }
  auto ac = calc(N, Q, A, U, V, B, C, cmd, I, X, Y);
  for (auto& x : ac) out(x.get());
}
