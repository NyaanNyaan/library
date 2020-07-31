#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../competitive-template.hpp"
#include "../modulo/mod-sqrt.hpp"

void solve() {
  ini(T);
  rep(_, T) {
    inl(y, p);
    out(mod_sqrt(y, p));
  }
}