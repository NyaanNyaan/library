#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include "../../template/template.hpp"
#include "../../modulo/tetration.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int T;
  rd(T);
  rep(i, T) {
    uint32_t a, b, m;
    rd(a, b, m);
    wtn(tetration(a, b, m));
  }
}