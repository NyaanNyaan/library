#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_big_integers"
//
#include "../../template/template.hpp"
//
#include "../../math/bigint.hpp"
//
#include "../../misc/fastio.hpp"
using namespace Nyaan;

void q() {
  int t;
  rd(t);
  while (t--) {
    string buf1, buf2;
    rd(buf1, buf2);
    bigint a = buf1, b = buf2;
    wtn((a * b).to_string());
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
