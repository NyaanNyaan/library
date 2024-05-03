#define PROBLEM "https://yukicoder.me/problems/no/1254"
//
#include "../../template/template.hpp"
//
#include "../../graph/namori.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  ini(N);
  Namori<ll> g(N);
  vp es;
  rep(i, N) {
    ini(u, v);
    --u, --v;
    g.add_edge(u, v);
    if (u > v) swap(u, v);
    es.emplace_back(u, v);
  }

  set<pl> namo;
  rep(i, sz(g.loop)) {
    int u = g.loop[i].first;
    int v = g.loop[(i + 1) % sz(g.loop)].first;
    if (u > v) swap(u, v);
    namo.emplace(u, v);
  }

  vi ans;
  rep(i, N) {
    if (namo.find(es[i]) != namo.end()) ans.push_back(i + 1);
  }
  out(sz(ans));
  out(ans);
}