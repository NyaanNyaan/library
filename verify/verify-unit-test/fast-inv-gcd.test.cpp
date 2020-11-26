#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../competitive-template.hpp"
#include "../../trial/fast-inv.hpp"
#include "../../trial/fast-gcd.hpp"

void solve(){
  fast_inv::unit_test();
  fast_gcd::unit_test();

  int a,b;
  cin >> a >> b;
  cout << (a + b) << endl;
}