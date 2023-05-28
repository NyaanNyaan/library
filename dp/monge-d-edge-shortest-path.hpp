#pragma once

#include "golden-section-search.hpp"
#include "monge-shortest-path.hpp"

// 辺コストが monge である DAG の D 辺 0-N 最短路
// f : from -> to のコスト (long long)
// upper : max abs(辺数を 1 増減させたときのコストの変化)
// (内部で int128 で計算しているので upper は 1e18 でも壊れない)
long long monge_d_edge_shortest_path(int N, int D, long long upper,
                                     const function<long long(int, int)>& f) {
  using T = __int128_t;
  upper = abs(upper);
  auto dp = [&](long long x) -> T {
    auto g = [&](int from, int to) -> T { return f(from, to) + x; };
    T cost = monge_shortest_path<T>(N, g)[N];
    return cost - T{1} * D * x;
  };
  auto [_, res] = golden_section_search<T, false>(dp, -upper, upper);
  return res;
}

/**
 * @brief monge グラフ上の d-辺最短路
 */
