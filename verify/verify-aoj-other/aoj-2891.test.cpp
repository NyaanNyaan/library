#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"
//
#include "../../template/template.hpp"
//
#include "../../graph/namori.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  ini(N);
  Namori<ll> g(N);
  rep(i, N) {
    ini(u, v);
    --u, --v;
    g.add_edge(u, v);
  }

  ini(Q);
  rep(i, Q) {
    ini(a, b);
    --a, --b;
    auto [_, xa] = g.idx(a);
    auto [__, xb] = g.idx(b);
    if (xa != 0 or xb != 0)
      out(1);
    else
      out(2);
  }
}