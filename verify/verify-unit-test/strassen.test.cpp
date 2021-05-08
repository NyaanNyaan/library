#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../modulo/strassen.hpp"

namespace FastMatProd {
// for debug
template <typename fps>
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vector<fps>
naive_mul(const vector<fps>& _a, const vector<fps>& _b) {
  int n = _a.size(), m = _b[0].size(), p = _b.size();
  assert(p == (int)_a[0].size());
  vector<fps> _c(n, fps(m, 0));
  for (int i = 0; i < n; i++)
    for (int k = 0; k < p; k++)
      for (int j = 0; j < m; j++) _c[i][j] += _a[i][k] * _b[k][j];
  return _c;
}

}  // namespace FastMatProd

#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"

using namespace FastMatProd;
using fps = vector<mint>;

void time_test() {
  int N = 1024;
  int P = N, M = N;
  vector<fps> s(N, fps(P)), t(P, fps(M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;
  for (int i = 0; i < P; i++)
    for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;
  vector<fps> u, u2, u3;
  Timer timer;

  int loop = 5;
  timer.reset();
  for (int i = 0; i < loop; i++) u = FastMatProd::strassen(s, t);
  cerr << "strassen " << (timer.elapsed() / loop) << endl;

  timer.reset();
  u2 = FastMatProd::naive_mul(s, t);
  cerr << "naive " << timer.elapsed() << endl;

  timer.reset();
  for (int i = 0; i < loop; i++) u3 = FastMatProd::block_dec(s, t);
  cerr << "block dec " << (timer.elapsed() / loop) << endl;

  assert(u == u2);
  assert(u == u3);
}

void debug_test(int max = 500, int loop = 10) {
  int N, P, M;
  mt19937 rng(58);
  while (loop--) {
    N = rng() % max + 1;
    M = rng() % max + 1;
    P = rng() % max + 1;
    vector<fps> s(N, fps(P)), t(P, fps(M));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;
    for (int i = 0; i < P; i++)
      for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;
    auto u = strassen(s, t);
    auto u2 = naive_mul(s, t);
    auto u3 = block_dec(s, t);
    if (u != u2) {
      cerr << "ng u1 " << N << " " << P << " " << M << endl;
      exit(1);
    } else if (u != u3) {
      cerr << "ng u1 " << N << " " << P << " " << M << endl;
      exit(1);
    } 
  }
  cerr << "all ok" << endl;
}

void Nyaan::solve() {
  debug_test();
  debug_test(32, 2000);
  time_test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}