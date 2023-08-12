#define PROBLEM "https://yukicoder.me/problems/no/1777"
//
#include "../../template/template.hpp"
//
#include "../../math/sat-solver.hpp"
//
#include "../../graph/graph-template.hpp"
//
using namespace Nyaan;

struct Plane {
  vector<int> nodes;
  int index;
  static int all_index;

  Plane() : index(-1) {}
  bool in(int u) const { return find(all(nodes), u) != end(nodes); }
  bool in(int u, int v) const { return in(u) and in(v); }
  bool edge_in(int u, int v) const {
    if (u > v) swap(u, v);
    auto itu = find(all(nodes), u);
    auto itv = find(all(nodes), v);
    if (itu == end(nodes) or itv == end(nodes)) return false;
    if (itu + 1 == itv) return true;
    if (itv + 1 == end(nodes) and itu == begin(nodes)) return true;
    return false;
  }
  // 破壊的
  Plane split(int u, int v) {
    assert(in(u, v) and !edge_in(u, v));
    Plane chd;
    chd.set_index();
    if (u > v) swap(u, v);
    auto itl = find(all(nodes), u);
    auto itr = find(all(nodes), v);
    chd.nodes = {itl, itr + 1};
    nodes.erase(itl + 1, itr);
    return chd;
  }
  void set_index() { index = all_index++; }

  friend ostream &operator<<(ostream &os, const Plane &p) {
    os << endl;
    os << "index : " << p.index << endl;
    os << "nodes : " << p.nodes << endl;
    os << endl;
    return os;
  }
};
int Plane::all_index = 0;

void Nyaan::solve() {
  inl(N, M);
  auto g = graph(N, M);

  // 外周
  Plane soto;
  soto.set_index();
  Plane naka;
  naka.set_index();

  {
    vi init(N);
    iota(all(init), 0);
    soto.nodes = naka.nodes = init;
  }

  vector<Plane> ps;
  ps.push_back(naka);

  rep(i, N) each(j, g[i]) {
    if (i > j) continue;
    each(p, ps) {
      if (p.in(i, j)) {
        auto ch = p.split(i, j);
        ps.push_back(ch);
        break;
      }
    }
  }

  vp pg_es;
  auto es_push = [&](int i, int j) {
    if (i > j) swap(i, j);
    pg_es.emplace_back(i, j);
  };

  rep(i, N) {
    int j = (i + 1) % N;
    each(p, ps) {
      if (p.edge_in(i, j)) {
        es_push(0, p.index);
        break;
      }
    }
  }

  rep(i, N) each(j, g[i]) {
    int p1 = -1, p2 = -1;
    rep(k, sz(ps)) {
      if (ps[k].edge_in(i, j)) {
        p1 = k;
        break;
      }
    }
    reg(k, p1 + 1, sz(ps)) {
      if (ps[k].edge_in(i, j)) {
        p2 = k;
        break;
      }
    }
    if (p1 != -1 and p2 != -1) es_push(ps[p1].index, ps[p2].index);
  }
  pg_es = mkuni(pg_es);
  ps.insert(begin(ps), soto);

  M = sz(ps);
  using Clause = vector<pair<int, bool>>;
  SatSolver sat((N + M) * 4);
  rep(i, N + M) {
    Clause c;
    rep(j, 4) c.emplace_back(i * 4 + j, true);
    sat.add_clause(c);
  }
  auto add = [&](int a, int b) {
    trc(a, b);
    rep(j, 4) {
      Clause c;
      c.emplace_back(a * 4 + j, false);
      c.emplace_back(b * 4 + j, false);
      sat.add_clause(c);
    }
  };
  rep(i, N) {
    each(j, g[i]) add(i, j);
    add(i, (i + 1) % N);
  }
  each2(i, j, pg_es) add(i + N, j + N);
  each(p, ps) {
    int i = p.index + N;
    each(j, p.nodes) add(i, j);
  }
  auto sol = sat.solve();
  trc(sol);
  out(sol ? 4 : 5);
}
