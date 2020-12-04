#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../template/template.hpp"
#include "../../misc/fastio.hpp"
#include "../../math/kth-root-integral.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int T;
  uint64_t A, K;
  rd(T);
  while (T--) {
    rd(A, K);
    wtn(kth_root_integral(A, K));
  }
}