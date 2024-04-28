#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-rerooting.hpp"
using namespace Nyaan;

struct HalfPath {
  ll d;
  int u;
  friend HalfPath max(const HalfPath &lhs, const HalfPath &rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    return lhs.u > rhs.u ? lhs : rhs;
  }
};
struct Path {
  ll d;
  int u, v;
  friend Path max(const Path &lhs, const Path &rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    if (lhs.u != rhs.u) return lhs.u > rhs.u ? lhs : rhs;
    return lhs.v > rhs.v ? lhs : rhs;
  }
};
struct L {
  Path dia;
  HalfPath d1, d2;
};
struct H {
  Path dia;
  HalfPath pd, cd;
  ll p_to_c;
  int p, c;
};
using I = pair<ll, int>;
H vertex(const I &xi) {
  auto [x, i] = xi;
  H r;
  r.dia = {x, i, i};
  r.pd = r.cd = {x, i};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}
H compress(const H &p, const H &c) {
  H r;
  r.dia = max(max(p.dia, c.dia), {p.cd.d + c.pd.d, p.cd.u, c.pd.u});
  r.pd = max(p.pd, {p.p_to_c + c.pd.d, c.pd.u});
  r.cd = max(c.cd, {c.p_to_c + p.cd.d, p.cd.u});
  r.p_to_c = p.p_to_c + c.p_to_c;
  r.p = p.p, r.c = c.c;
  return r;
}
L rake(const L &a, const L &b) {
  L r;
  r.dia = max(a.dia, b.dia);
  if (a.d1.d > b.d1.d) {
    r.d1 = a.d1;
    r.d2 = max(a.d2, b.d1);
  } else {
    r.d1 = b.d1;
    r.d2 = max(b.d2, a.d1);
  }
  return r;
}
L add_edge(const H &a) {
  L r;
  r.dia = a.dia;
  r.d1 = a.pd;
  r.d2 = {0, -1};
  return r;
}
H add_vertex(const L &a, const I &xi) {
  auto [x, i] = xi;
  H r;
  r.dia = max(a.dia, {a.d1.d + x + a.d2.d, a.d1.u, a.d2.u});
  r.pd = r.cd = {a.d1.d + x, a.d1.u};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}

using DD =
    TopTree<H, L, I, vertex, compress, rake, add_edge, add_vertex>;

void q() {
  int N;
  cin >> N;
  DD lct;
  vector<vector<pair<int, int> > > g(N);
  for (int i = 1; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  vector<typename DD::NP> vs(N), es(N);
  auto dfs = [&](auto rec, int idx, int par) -> void {
    vs[idx] = lct.alloc(make_pair(0, idx));
    for (auto &e : g[idx]) {
      if (e.first == par) continue;
      rec(rec, e.first, idx);
      es[e.first] = lct.alloc(make_pair(e.second, -1));
      lct.link(vs[e.first], es[e.first]);
      lct.link(es[e.first], vs[idx]);
    }
  };
  dfs(dfs, 0, -1);

  set<long long> anss;
  for (int i = 0; i < N; i++) {
    long long d = lct.query(vs[i]).dia.d;
    anss.emplace(d);
  }
  if (anss.size() != 1u) exit(1);
  cout << *begin(anss) << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
