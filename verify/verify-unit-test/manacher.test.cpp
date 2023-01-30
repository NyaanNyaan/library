#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../string/manacher.hpp"
//
#include "../../misc/rng.hpp"
using namespace Nyaan;

void test() {
  int N = rng(5, 100);
  string S;
  int upper = rng(1, 10);
  rep(i, N) S.push_back('a' + rng(0, upper - 1));
  trc(S);
  auto p = enumerate_leftmost_palindromes(S);
  trc(p);
  rep(r, N) {
    int mn = r;
    rep(l, r) {
      string T = S.substr(l, r - l + 1);
      string U = T;
      reverse(all(U));
      if (T == U) {
        mn = l;
        break;
      }
    }
    assert(mn == p[r]);
  }
}

void Nyaan::solve() {
  rep(t, 1000) test();
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
