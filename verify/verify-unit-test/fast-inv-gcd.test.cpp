#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
#include "../../trial/fast-inv.hpp"
#include "../../trial/fast-gcd.hpp"

using namespace Nyaan; void Nyaan::solve(){
  fast_inv::unit_test();
  fast_gcd::unit_test();

  int a,b;
  cin >> a >> b;
  cout << (a + b) << endl;
}