#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include "../../competitive-template.hpp"
#include "../../modulo/tetration.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  int T;
  rd(T);
  rep(i, T) {
    uint32_t a, b, m;
    rd(a, b, m);
    wtn(tetration(a, b, m));
  }
}