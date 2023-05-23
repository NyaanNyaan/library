#pragma once

#include <functional>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// (start からの距離, 1 個前の頂点) を格納する map を返す
// ただし始点は d[start] = {0, Index{}}
template <typename Index, typename Cost, bool has_goal = true>
map<Index, pair<Cost, Index>> dijkstra_abstruct(
    const function<void(Index, Cost, function<void(Index, Cost)>)>& f,
    const Index& start, const Index& goal) {
  using P = pair<Cost, Index>;

  map<Index, P> d;
  priority_queue<P, vector<P>, greater<P>> Q;
  d[start] = P(0, Index{});
  Q.emplace(0, start);

  while (!Q.empty()) {
    auto [u, t] = Q.top();
    Q.pop();
    if (d[t].first != u) continue;
    if (has_goal && t == goal) return d;
    auto add = [&](Index nt, Cost nu) {
      if (d.count(nt) == 0 or nu < d[nt].first) {
        d[nt] = P(nu, t);
        Q.emplace(nu, nt);
      }
    };
    f(t, u, add);
  }
  return d;
}
