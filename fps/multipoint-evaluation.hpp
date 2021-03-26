#pragma once

#include "./formal-power-series.hpp"

template <typename mint>
struct ProductTree {
  using fps = FormalPowerSeries<mint>;
  const vector<mint> &xs;
  vector<fps> buf;
  int N, xsz;
  vector<int> l, r;
  ProductTree(const vector<mint> &xs_) : xs(xs_), xsz(xs.size()) {
    N = 1;
    while (N < (int)xs.size()) N *= 2;
    buf.resize(2 * N);
    l.resize(2 * N, xs.size());
    r.resize(2 * N, xs.size());
    fps::set_fft();
    if (fps::ntt_ptr == nullptr)
      build();
    else
      build_ntt();
  }

  void build() {
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i], 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else
        buf[i] = buf[(i << 1) | 0] * buf[(i << 1) | 1];
    }
  }

  void build_ntt() {
    fps f;
    f.reserve(N * 2);
    for (int i = 0; i < xsz; i++) {
      l[i + N] = i;
      r[i + N] = i + 1;
      buf[i + N] = {-xs[i] + 1, -xs[i] - 1};
    }
    for (int i = N - 1; i > 0; i--) {
      l[i] = l[(i << 1) | 0];
      r[i] = r[(i << 1) | 1];
      if (buf[(i << 1) | 0].empty())
        continue;
      else if (buf[(i << 1) | 1].empty())
        buf[i] = buf[(i << 1) | 0];
      else if (buf[(i << 1) | 0].size() == buf[(i << 1) | 1].size()) {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]),
             back_inserter(f));
        buf[i].ntt_doubling();
        f.ntt_doubling();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      } else {
        buf[i] = buf[(i << 1) | 0];
        f.clear();
        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]),
             back_inserter(f));
        buf[i].ntt_doubling();
        f.intt();
        f.resize(buf[i].size(), mint(0));
        f.ntt();
        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];
      }
    }
    for (int i = 0; i < 2 * N; i++) {
      buf[i].intt();
      buf[i].shrink();
    }
  }
};

template <typename mint>
vector<mint> InnerMultipointEvaluation(const FormalPowerSeries<mint> &f,
                                       const vector<mint> &xs,
                                       const ProductTree<mint> &ptree) {
  using fps = FormalPowerSeries<mint>;
  vector<mint> ret;
  ret.reserve(xs.size());
  auto rec = [&](auto self, fps a, int idx) {
    if (ptree.l[idx] == ptree.r[idx]) return;
    a %= ptree.buf[idx];
    if ((int)a.size() <= 64) {
      for (int i = ptree.l[idx]; i < ptree.r[idx]; i++)
        ret.push_back(a.eval(xs[i]));
      return;
    }
    self(self, a, (idx << 1) | 0);
    self(self, a, (idx << 1) | 1);
  };
  rec(rec, f, 1);
  return ret;
}

template <typename mint>
vector<mint> MultipointEvaluation(const FormalPowerSeries<mint> &f,
                                  const vector<mint> &xs) {
  if(f.empty() || xs.empty()) return vector<mint>(xs.size(), mint(0));
  return InnerMultipointEvaluation(f, xs, ProductTree<mint>(xs));
}

/**
 * @brief Multipoint Evaluation
 */
