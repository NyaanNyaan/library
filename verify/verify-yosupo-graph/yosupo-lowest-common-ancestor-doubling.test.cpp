#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.hpp"
//
#include "../../misc/doubling.hpp"
#include "../../misc/fastio.hpp"

void Nyaan::solve() {
  int N, Q;
  rd(N, Q);
  Doubling<int> db(N, N, 0);
  for (int i = 1; i < N; i++) {
    int p;
    rd(p);
    db.set_next(i, p, 1);
  }
  db.build();

  while (Q--) {
    int u, v;
    rd(u, v);
    int du = db.query_pow(u, db.LOG - 1).second;
    int dv = db.query_pow(v, db.LOG - 1).second;
    if (du > dv) swap(u, v), swap(du, dv);
    int t = dv - du;
    for (int k = 0; t; k++) {
      if ((t >> k) & 1) {
        v = db.query_pow(v, k).first;
        t ^= (1 << k);
      }
    }
    if (u != v) {
      for (int k = db.LOG - 1; k >= 0; --k) {
        int pu = db.query_pow(u, k).first;
        int pv = db.query_pow(v, k).first;
        if (pu != pv) u = pu, v = pv;
      }
      u = db.query_pow(u, 0).first;
    }
    wtn(u);
  }
}