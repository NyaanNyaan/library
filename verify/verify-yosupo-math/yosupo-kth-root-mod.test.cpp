#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"

#include "../../template/template.hpp"
#include "../../modulo/mod-kth-root.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(T);
  rep(_, T) {
    inl(K, Y, P);
    out(kth_root(Y, K, P));
  }
}