#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math/semiring.hpp"
#include "../../shortest-path/warshall-floyd.hpp"
using namespace Nyaan;

#include "../../misc/rng.hpp"

ll f(ll a, ll b) { return min(a, b); }
ll g(ll a, ll b) { return a + b; }
ll i0() { return -1; }
ll i1() { return 0; }
using rig = semiring<ll, f, g, i0, i1>;

void test() {
  constexpr int n = 100;
  vvl d(n, vl(n, infLL));
  rep(i, n) d[i][i] = 0;

  int ratio = (n / 3) * pow(2, randint(0, 5));
  rep(i, n) rep(j, i) {
    if (randint(0, ratio) == 0) d[i][j] = d[j][i] = randint(0, 100);
  }

  Mat<rig, n> m;
  rep(i, n) rep(j, n) m[i][j] = d[i][j] == infLL ? i0() : d[i][j];
  m ^= n - 1;

  warshall_floyd(d);
  rep(i, n) rep(j, n) assert(m[i][j] == (d[i][j] == infLL ? i0() : d[i][j]));
}

void Nyaan::solve() {
  rep(i, 50) test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
