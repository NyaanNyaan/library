#pragma once

#include <algorithm>
#include <vector>
using namespace std;

// x^0, x^1, ..., x^N をオンラインで計算する
// x^{n-1} までを確定させた時点で, c[n] には a_0 b_n と
// a_n b_0 以外の寄与の和が入っているので, それを利用することもできる
template <typename fps>
struct RelaxedConvolution {
  using mint = typename fps::value_type;
  int N, q;
  vector<mint> a, b, c;
  fps f, g;
  vector<fps> as, bs;

  RelaxedConvolution(int _n) : N(_n), q(0) {
    a.resize(N + 1), b.resize(N + 1), c.resize(N + 1);
  }

  // a[q] = x, b[q] = y であるとき c[q] を get
  mint get(mint x, mint y) {
    assert(q <= N);
    a[q] = x, b[q] = y;
    c[q] += a[q] * b[0] + (q ? b[q] * a[0] : 0);

    auto precalc = [&](int lg) {
      if ((int)as.size() <= lg) as.resize(lg + 1), bs.resize(lg + 1);
      if (!as[lg].empty()) return;
      int d = 1 << lg;
      fps s{begin(a), begin(a) + d * 2};
      fps t{begin(b), begin(b) + d * 2};
      s.ntt(), t.ntt();
      as[lg] = s, bs[lg] = t;
    };

    q++;
    if (q > N) return c[q - 1];
    for (int d = 1, lg = 0; d <= q; d *= 2, lg++) {
      if (q % (2 * d) != d) continue;
      if (q == d) {
        f.assign(2 * d, mint{});
        g.assign(2 * d, mint{});
        for (int i = 0; i < d; i++) f[i] = a[i];
        for (int i = 0; i < d; i++) g[i] = b[i];
        f.ntt(), g.ntt();
        for (int i = 0; i < d * 2; i++) f[i] *= g[i];
        f.intt();
        for (int i = q; i < min(q + d, N + 1); i++) c[i] += f[d + i - q];
      } else {
        precalc(lg);
        f.assign(2 * d, mint{});
        g.assign(2 * d, mint{});
        for (int i = 0; i < d; i++) f[i] = a[q - d + i];
        for (int i = 0; i < d; i++) g[i] = b[q - d + i];
        f.ntt(), g.ntt();
        fps& s = as[lg];
        fps& t = bs[lg];
        for (int i = 0; i < d * 2; i++) f[i] = f[i] * t[i] + g[i] * s[i];
        f.intt();
        for (int i = q; i < min(q + d, N + 1); i++) c[i] += f[d + i - q];
      }
    }
    return c[q - 1];
  }
};

/**
 * @brief Relaxed Convolution
 */
