#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../dp/concave-min-plus-convolution.hpp"
#include "../../misc/rng.hpp"
using namespace Nyaan;

void q() {
  rep(t, TEN(5)) {
    int N = rng(1, 5);
    int M = rng(1, 5);

    // a : concave
    vi a;
    {
      vi ds(N - 1);
      each(d, ds) d = rng(-5, 5);
      sort(all(ds));
      int x = rng(0, 10);
      a.push_back(x);
      each(d, ds) x += d, a.push_back(x);
    }
    vi b(M);
    each(x, b) x = rng(-10, 10);

    // min-plus
    {
      vi c = concave_min_plus_convolution(a, b);
      vi d(N + M - 1, inf);
      rep(i, N) rep(j, M) amin(d[i + j], a[i] + b[j]);
      assert(c == d);
    }
    // max-plus
    {
      each(x, a) x = -x;
      vi c = concave_max_plus_convolution(a, b);
      vi d(N + M - 1, -inf);
      rep(i, N) rep(j, M) amax(d[i + j], a[i] + b[j]);
      assert(c == d);
    }
  }
  trc2("OK");

  {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
