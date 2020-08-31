#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../competitive-template.hpp"
#include "../../misc/fastio.hpp"
#include "../../math/kth-root-integral.hpp"

void solve() {
  int T;
  uint64_t A, K;
  rd(T);
  while (T--) {
    rd(A, K);
    wtn(kth_root_integral(A, K));
  }
}