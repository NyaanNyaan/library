#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../template/template.hpp"
#include "../../modulo/mod-sqrt.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(T);
  rep(_, T) {
    inl(y, p);
    out(mod_sqrt(y, p));
  }
}