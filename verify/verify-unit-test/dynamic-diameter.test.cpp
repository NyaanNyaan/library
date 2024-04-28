#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../tree/dynamic-diameter.hpp"
using namespace Nyaan;
//
#include "../../graph/graph-utility.hpp"
//
#include "../../shortest-path/dijkstra.hpp"
//
#include "../../misc/rng.hpp"

void test() {
  ll wmax = TEN(9);

  rep1(N, 50) {
    rep(_, 100) {
      WeightedGraph<ll> g;
      Edges<ll> es;
      rep1(i, N - 1) {
        int j = rng(0, i - 1);
        es.emplace_back(j, i, rng(0, wmax));
      }

      auto gen = [&]() {
        g.clear();
        g.resize(N);
        each(e, es) {
          g[e.src].emplace_back(e.src, e.to, e.cost);
          g[e.to].emplace_back(e.to, e.src, e.cost);
        }
      };
      gen();

      auto DP = DynamicDiameter(g);

      rep(t, 100) {
        // check
        auto [d, uv] = DP.get();

        ll d2 = -1;
        {
          int u = 0;
          auto du = dijkstra(g, u);
          int v = max_element(all(du)) - begin(du);
          auto dv = dijkstra(g, v);
          int w = max_element(all(dv)) - begin(dv);
          d2 = dv[w];
        }
        assert(uv.first != -1 and uv.second != -1);
        assert(d == d2);
        assert(d == dijkstra(g, uv.first)[uv.second]);

        if (N >= 2) {
          // update
          int e_num = rng(0, N - 2);
          int u = es[e_num].src, v = es[e_num].to;
          ll x = rng(0, wmax);

          DP.update(u, v, x);
          es[e_num].cost = x;
          gen();
        }
      }
    }
  }
  trc2("OK");
}

void q() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
