#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR 0.0000001

#include "../../template/template.hpp"
//
#include "../../shortest-path/dijkstra.hpp"
//
#include "../../matrix/linear-equation.hpp"
using namespace Nyaan;

void q() {
  int N, S, T;
  for (; cin >> N >> S >> T, N;) {
    --S, --T;
    vl q(N);
    in(q);
    vvi A(N, vi(N));
    in(A);

    WeightedGraph<int> g(N);
    rep(i, N) rep(j, N) if (A[i][j]) g[i].emplace_back(i, j, A[i][j]);
    vi d = dijkstra(g, T);
    trc(d);
    if (d[S] == -1) {
      out("impossible");
      continue;
    }
    VV<double> m(N, V<double>(N));
    V<double> b(N);
    rep(i, N) {
      if (i == T) {
        m[i][i] = 1;
        continue;
      }
      vi dst;
      if (q[i]) {
        rep(j, N) {
          if (A[i][j] and d[i] == d[j] + A[i][j]) dst.push_back(j);
        }
      } else {
        rep(j, N) {
          if (A[i][j]) dst.push_back(j);
        }
      }
      trc(i, dst);
      double num = sz(dst);
      // (sum_{j in dst} (E_j + A_{i,j}) / num) = E_i
      each(j, dst) {
        m[i][j] += 1.0 / num;
        b[i] -= A[i][j] / num;
      }
      m[i][i] += -1.0;
    }
    auto ans = LinearEquation(m, b)[0];
    trc(ans);
    out(ans[S]);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
