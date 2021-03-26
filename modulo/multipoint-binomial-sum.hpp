#pragma once

#include "../misc/mo.hpp"
#include "binomial.hpp"

template <typename mint>
vector<mint> multipoint_binomial_sum(const vector<pair<int, int>>& qs) {
  int N = 2;
  for (auto& p : qs) N = max(N, p.first);
  Binomial<mint> b(N + 1);
  int Q = qs.size();
  Mo mo(N, Q);
  for (auto& p : qs) {
    assert(p.second <= p.first);
    assert(p.first <= N);
    mo.insert(p.second, p.first);
  }
  vector<mint> ans(Q);
  mint cur = 1;
  int n = 0, m = 0;
  auto al = [&](int) { cur -= b.C(n, m--); };
  auto ar = [&](int) { cur += cur - b.C(n++, m); };
  auto el = [&](int) { cur += b.C(n, ++m); };
  auto er = [&](int) { cur = (cur + b.C(--n, m)) * b.inv(2); };
  auto q = [&](int i) { ans[i] = cur; };
  mo.run(al, ar, el, er, q);
  return ans;
}

/**
 * @brief 二項係数のprefix sumの多点評価
 */
