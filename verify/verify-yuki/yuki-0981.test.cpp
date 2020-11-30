#define PROBLEM "https://yukicoder.me/problems/no/981"

#include "../../competitive-template.hpp"
#include "../../modulo/mod-kth-root.hpp"

void solve() {
  ini(T);
  rep(_, T) {
    inl(p, k, a);
    out(kth_root(a, k, p));
  }
}
