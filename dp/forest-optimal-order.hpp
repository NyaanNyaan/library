#pragma once

#include <queue>
#include <utility>
#include <vector>
using namespace std;

#include "../data-structure/union-find.hpp"

/*
p_i : i の親頂点 (i が根の時は -1)
T で定義されるべき演算
T() : 単位元
operator* : T 同士のマージ T
operator< : 木の制約が無い時の左右の位置関係(const がないとコンパイル通らない？)
*/
template <typename T>
pair<vector<int>, T> ForestOptimalOrder(int N, vector<int> p, vector<T> dat) {
  // 頂点 N を仮想的な根とする
  for (auto& x : p) {
    if (x == -1) x = N;
  }
  p.push_back(-1);
  dat.push_back(T{});
  UnionFind uf(N + 1);
  vector<int> head(N + 1), tail(N + 1), nxt(N + 1, -1);
  for (int i = 0; i <= N; i++) head[i] = tail[i] = i;
  using D = tuple<T, int, int>;
  priority_queue<D, vector<D>, greater<D>> Q;
  for (int i = 0; i < N; i++) Q.emplace(dat[i], i, i);
  while (!Q.empty()) {
    auto [_, v, tailv] = Q.top();
    Q.pop();
    if (tail[v] != tailv) continue;
    int u = head[uf.find(p[v])];
    uf.unite(u, v, [&](int x, int y) { head[x] = head[y] = u; });
    nxt[tail[u]] = v;
    tail[u] = tail[v];
    dat[u] = dat[u] * dat[v];
    if (u != N) Q.emplace(dat[u], u, tail[u]);
  }
  vector<int> order;
  for (int i = nxt[N]; i != -1; i = nxt[i]) order.push_back(i);
  return {order, dat[N]};
}
