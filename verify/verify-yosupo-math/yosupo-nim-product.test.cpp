#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "../../competitive-template.hpp"
#include "../../math/nim-product.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  int T;
  rd(T);
  rep(i, T) {
    uint64_t a, b;
    rd(a, b);
    wtn(nim_product(a, b));
  }
}