#pragma once

#include "./formal-power-series.hpp"
#include "./multipoint-evaluation.hpp"

template <class mint>
FormalPowerSeries<mint> PolynomialInterpolation(const vector<mint> &xs,
                                                const vector<mint> &ys) {
  using fps = FormalPowerSeries<mint>;
  assert(xs.size() == ys.size());
  ProductTree<mint> ptree(xs);
  fps w = ptree.buf[1].diff();
  vector<mint> vs = InnerMultipointEvaluation<mint>(w, xs, ptree);
  auto rec = [&](auto self, int idx) -> fps {
    if (idx >= ptree.N) {
      if (idx - ptree.N < (int)xs.size())
        return {ys[idx - ptree.N] / vs[idx - ptree.N]};
      else
        return {mint(1)};
    }
    if (ptree.buf[idx << 1 | 0].empty())
      return {};
    else if (ptree.buf[idx << 1 | 1].empty())
      return self(self, idx << 1 | 0);
    return self(self, idx << 1 | 0) * ptree.buf[idx << 1 | 1] +
           self(self, idx << 1 | 1) * ptree.buf[idx << 1 | 0];
  };
  return rec(rec, 1);
}
