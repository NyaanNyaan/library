#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
//
#include "../../template/template.hpp"
//
#include "../../data-structure-2d/segment-tree-on-wavelet-matrix.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan;

ll f(ll a, ll b) { return a + b; }
ll I() { return 0; }

void q() {
  WaveletMatrix<int, ll, f, I> wm;

  int N, Q;
  rd(N, Q);
  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q), v(Q);
  rep(i, N) {
    rd(X[i], Y[i], W[i]);
    wm.add_point(X[i], Y[i]);
  }
  rep(i, Q) {
    rd(c[i], s[i], t[i], u[i]);
    if (c[i]) {
      rd(v[i]);
    } else {
      wm.add_point(s[i], t[i]);
    }
  }

  wm.build();
  rep(i, N) { wm.add(X[i], Y[i], W[i]); }
  rep(i, Q) {
    if (c[i]) {
      out(wm.sum(s[i], t[i], u[i], v[i]));
    } else {
      wm.add(s[i], t[i], u[i]);
    }
  }
}

void Nyaan::solve() {
  int T = 1;

  // in(T);

  while (T--) q();
}
