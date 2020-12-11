#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../template/template.hpp"
//
#include "../../orderedmap/orderedmap.hpp"

using namespace Nyaan;

#include "../../misc/fastio.hpp"
void Nyaan::solve() {
  int Q;
  rd(Q);

  OrderedMap<ll, ll> m;

  while (Q--) {
    int cmd;
    rd(cmd);
    if (cmd) {
      long long k;
      rd(k);
      auto p = m.find(k);
      out(p ? p->val : 0);
    } else {
      long long k, v;
      rd(k, v);
      m[k] = v;
    }
  }
}
