#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "../../template/template.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int T;
  rd(T);
  rep(i, T) {
    long long a, b;
    rd(a);
    rd(b);
    wt(a + b);
    wt('\n');
  }
}