#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "../../template/template.hpp"
//
#include "../../math/nimber.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  int T;
  rd(T);
  rep(i, T) {
    uint64_t a, b;
    rd(a, b);
    wtn(NimberImpl::product64(a, b));
  }
}
