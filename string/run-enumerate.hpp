#pragma once

#include <algorithm>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#include "z-algorithm.hpp"

// (p, l, r) : S[l, r) は周期 p かつ極大
// sum_{(p,l,r)} 1 <= n
// sum_{(p,l,r)} (r-l)/p <= 3n
// sum_{(p,l,r)} (r-l+1-2*p) = O(n log n)
template <typename C>
vector<tuple<int, int, int>> run_enumerate(const C& S) {
  int N = S.size();
  using T = tuple<int, int, int>;
  vector<vector<pair<int, int>>> by_p(N + 1);

  auto solve_sub = [&](const C& l, const C& r) {
    vector<T> res;
    int n = l.size(), m = r.size();
    C s = l, t = r;
    t.insert(end(t), begin(l), end(l));
    t.insert(end(t), begin(r), end(r));
    reverse(begin(s), end(s));
    auto ZS = z_algorithm(s), ZT = z_algorithm(t);
    for (int p = 1; p <= n; p++) {
      int a = p == n ? p : min(ZS[p] + p, n);
      int b = min(ZT[n + m - p], m);
      if (a + b < 2 * p) continue;
      res.emplace_back(p, a, b);
    }
    return res;
  };

  auto dfs = [&](auto rc, int L, int R) -> void {
    if (R - L <= 1) return;
    int M = (L + R) / 2;
    rc(rc, L, M), rc(rc, M, R);
    C SL{begin(S) + L, begin(S) + M};
    C SR{begin(S) + M, begin(S) + R};
    auto sub_res1 = solve_sub(SL, SR);
    for (auto& [p, a, b] : sub_res1) by_p[p].emplace_back(M - a, M + b);
    reverse(begin(SL), end(SL));
    reverse(begin(SR), end(SR));
    auto sub_res2 = solve_sub(SR, SL);
    for (auto& [p, a, b] : sub_res2) by_p[p].emplace_back(M - b, M + a);
  };
  dfs(dfs, 0, N);

  vector<T> res;
  set<pair<int, int>> done;
  for (int p = 0; p <= N; p++) {
    auto& LR = by_p[p];
    sort(begin(LR), end(LR), [](auto& x, auto& y) {
      if (x.first == y.first) return x.second > y.second;
      return x.first < y.first;
    });
    int r = -1;
    for (auto& lr : LR) {
      if (r >= lr.second) continue;
      r = lr.second;
      if (!done.count(lr)) {
        done.insert(lr);
        res.emplace_back(p, lr.first, lr.second);
      }
    }
  }
  return res;
}
