#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

// 実行時間の問題から適当なランダムケースで test する
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../shortest-path/dijkstra.hpp"
//
#include "../../math/bigint-rational.hpp"
#include "../../matrix/linear-equation.hpp"
using namespace Nyaan;

template <typename T>
double calc(int N, int s, int t, vl q, vvi A) {
  WeightedGraph<int> g(N);
  rep(i, N) rep(j, N) if (A[i][j]) g[i].emplace_back(i, j, A[i][j]);
  vi d = dijkstra(g, t);
  if (d[s] == -1) return -1;
  VV<T> m(N, V<T>(N));
  V<T> b(N);
  rep(i, N) {
    if (i == t) {
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
    ll num = sz(dst);
    each(j, dst) {
      m[i][j] += T(1) / num;
      b[i] -= T(A[i][j]) / num;
    }
    m[i][i] -= 1;
  }
  auto ans = LinearEquation(m, b)[0];
  if constexpr (is_same_v<T, double>) {
    return ans[s];
  } else {
    return to_double(ans[s]);
  }
}

void test() {
  rep(t, 100) {
    int N = rng(2, 30);
    int S = -1, T = -1;
    do {
      S = rng(0, N - 1);
      T = rng(0, N - 1);
    } while (S == T);
    vl q(N);
    each(x, q) x = rng(0, 1);
    vvi A(N, vi(N));
    rep(i, N) rep(j, i) A[j][i] = A[i][j] = rng(0, 1) ? rng(1, 10) : 0;
    double a1 = calc<double>(N, S, T, q, A);
    double a2 = calc<BigRational>(N, S, T, q, A);
    double error = abs(a1 - a2) / max(1.0, a2);
    assert(error < 1e-8);
  }
}

void q() {
  test();
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
