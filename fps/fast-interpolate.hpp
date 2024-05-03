#pragma once

#include <vector>
using namespace std;

#include "formal-power-series.hpp"

// https://github.com/hos-lyric/libra/blob/master/algebra/poly_998244353.cpp
// の多項式補間を手元で動くように改造
// xs が distinct じゃないと壊れる
template <typename mint>
struct SubproductTree {
  using fps = FormalPowerSeries<mint>;
  int logN, n, nn;
  vector<mint> xs;
  vector<mint> buf;
  vector<mint *> gss;
  fps all, roots;

  void ntt(mint *a, int s) const {
    static fps buf2;
    buf2.resize(s);
    copy(a, a + s, buf2.data());
    buf2.ntt();
    copy(buf2.data(), buf2.data() + s, a);
  }
  void intt(mint *a, int s) const {
    static fps buf2;
    buf2.resize(s);
    copy(a, a + s, buf2.data());
    buf2.intt();
    copy(buf2.data(), buf2.data() + s, a);
  }

  SubproductTree(const vector<mint> &xs_) {
    n = xs_.size();
    for (logN = 0, nn = 1; nn < n; ++logN, nn <<= 1) {
    }
    roots.resize(logN + 1);
    for (int i = 0; i <= logN; i++) {
      int mod = mint::get_mod();
      roots[i] = mint{fps::ntt_pr()}.pow((mod - 1) >> i);
    }
    xs.assign(nn, 0U);
    memcpy(xs.data(), xs_.data(), n * sizeof(mint));
    buf.assign((logN + 1) * (nn << 1), 0U);
    gss.assign(nn << 1, nullptr);
    for (int h = 0; h <= logN; ++h)
      for (int u = 1 << h; u < 1 << (h + 1); ++u) {
        gss[u] =
            buf.data() + (h * (nn << 1) + ((u - (1 << h)) << (logN - h + 1)));
      }
    for (int i = 0; i < nn; ++i) {
      gss[nn + i][0] = -xs[i] + 1;
      gss[nn + i][1] = -xs[i] - 1;
    }
    if (nn == 1) gss[1][1] += 2;
    for (int h = logN; --h >= 0;) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h;) {
        for (int i = 0; i < m; ++i)
          gss[u][i] = gss[u << 1][i] * gss[u << 1 | 1][i];
        memcpy(gss[u] + m, gss[u], m * sizeof(mint));
        intt(gss[u] + m, m);
        if (h > 0) {
          gss[u][m] -= 2;
          const mint a = roots[logN - h + 1];
          mint aa = 1;
          for (int i = m; i < m << 1; ++i) {
            gss[u][i] *= aa;
            aa *= a;
          };
          ntt(gss[u] + m, m);
        }
      }
    }
    all.resize(nn + 1);
    all[0] = 1;
    for (int i = 1; i < nn; ++i) all[i] = gss[1][nn + nn - i];
    all[nn] = gss[1][nn] - 1;
  }
  vector<mint> multiEval(const fps &fs) const {
    vector<mint> work0(nn), work1(nn), work2(nn);
    {
      const int m = max<int>(fs.size(), 1);
      auto invAll = all.inv(m);
      std::reverse(invAll.begin(), invAll.end());
      int mm;
      for (mm = 1; mm < m - 1 + nn; mm <<= 1) {
      }
      invAll.resize(mm, 0U);
      ntt(invAll.data(), invAll.size());
      vector<mint> ffs(mm, 0U);
      memcpy(ffs.data(), fs.data(), fs.size() * sizeof(mint));
      ntt(ffs.data(), ffs.size());
      for (int i = 0; i < mm; ++i) ffs[i] *= invAll[i];
      intt(ffs.data(), ffs.size());
      memcpy(((logN & 1) ? work1 : work0).data(), ffs.data() + m - 1,
             nn * sizeof(mint));
    }
    for (int h = 0; h < logN; ++h) {
      const int m = 1 << (logN - h);
      for (int u = 1 << h; u < 1 << (h + 1); ++u) {
        mint *hs = (((logN - h) & 1) ? work1 : work0).data() +
                   ((u - (1 << h)) << (logN - h));
        mint *hs0 = (((logN - h) & 1) ? work0 : work1).data() +
                    ((u - (1 << h)) << (logN - h));
        mint *hs1 = hs0 + (m >> 1);
        ntt(hs, m);
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1 | 1][i] * hs[i];
        intt(work2.data(), m);
        memcpy(hs0, work2.data() + (m >> 1), (m >> 1) * sizeof(mint));
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1][i] * hs[i];
        intt(work2.data(), m);
        memcpy(hs1, work2.data() + (m >> 1), (m >> 1) * sizeof(mint));
      }
    }
    work0.resize(n);
    return work0;
  }

  fps interpolate(const vector<mint> &ys) const {
    assert(static_cast<int>(ys.size()) == n);
    fps gs(n);
    for (int i = 0; i < n; ++i) gs[i] = all[n - (i + 1)] * (i + 1);
    const vector<mint> denoms = multiEval(gs);
    vector<mint> work(nn << 1, 0U);
    for (int i = 0; i < n; ++i) {
      assert(denoms[i] != 0);
      work[i << 1] = work[i << 1 | 1] = ys[i] / denoms[i];
    }
    for (int h = logN; --h >= 0;) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h;) {
        mint *hs = work.data() + ((u - (1 << h)) << (logN - h + 1));
        for (int i = 0; i < m; ++i)
          hs[i] = gss[u << 1 | 1][i] * hs[i] + gss[u << 1][i] * hs[m + i];
        if (h > 0) {
          memcpy(hs + m, hs, m * sizeof(mint));
          intt(hs + m, m);
          const mint a = roots[logN - h + 1];
          mint aa = 1;
          for (int i = m; i < m << 1; ++i) {
            hs[i] *= aa;
            aa *= a;
          };
          ntt(hs + m, m);
        }
      }
    }
    intt(work.data(), nn);
    return {work.data() + nn - n, work.data() + nn};
  }
};
