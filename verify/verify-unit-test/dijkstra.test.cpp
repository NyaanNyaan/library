#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../competitive-template.hpp"
#include "../../misc/rng.hpp"
#include "../../shortest-path/dijkstra-fast.hpp"
#include "../../shortest-path/dijkstra-radix-heap.hpp"
#include "../../shortest-path/dijkstra.hpp"

template <int N, int M, int C>
void test() {
  static_assert(N >= 1);
  vector<tuple<int, int, ll>> es;

  // connectivity
  mt19937_64 mt(rng());
  vi ord(N - 1);
  iota(all(ord), 1);
  shuffle(all(ord), mt);
  ord.insert(begin(ord), 0);
  rep(i, N - 1) {
    int u = ord[i], v = ord[i + 1];
    ll c = randint(0, C + 1);
    es.emplace_back(u, v, c);
  }
  rep(_, M - (N - 1)) {
    int u, v;
    do {
      u = randint(0, N), v = randint(0, N);
    } while (u == v);
    ll c = randint(0, C + 1);
    es.emplace_back(u, v, c);
  }

  shuffle(all(es), mt);
  WeightedGraph<ll> g(N);
  StaticGraph<ll> dg(N, M);
  if (es.size() > M) es.resize(M);

  for (auto&& [u, v, c] : es) {
    g[u].emplace_back(v, c);
    dg.add_edge(u, v, c);
  }

  vl d1, d2, d3;

  d1 = dijkstra(g);
  d2 = dijkstra_radix_heap(g);
  d3 = dijkstra(g);
  
  assert(d1 == d2);
  assert(d1 == d3);
}

void solve() {
  test<1, 0, 100>();
  test<2, 0, 100>();
  test<2, 1, 100>();
  test<3, 0, 100>();
  test<3, 1, 100>();
  test<3, 2, 100>();
  test<TEN(2), TEN(1), 100>();
  test<TEN(2), TEN(2) - 1, 100>();
  test<TEN(2), TEN(2) * 2, 100>();
  test<TEN(3), TEN(3) * 2, 100>();
  test<TEN(4), TEN(4) * 2, 100>();
  test<TEN(5), TEN(5) * 2, 100>();
  test<TEN(6), TEN(6) * 2, 100>();

  int n, m;
  cin >> n >> m;
  cout << n + m << endl;
}