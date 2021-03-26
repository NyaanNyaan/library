#pragma once
#include "../modint/montgomery-modint.hpp"
#include "./ntt-friendly-fps.hpp"

template <typename mint>
vector<mint> FastMultiEval(const FormalPowerSeries<mint> &f,
                           const vector<mint> &xs) {
  using fps = FormalPowerSeries<mint>;
  int s = xs.size();
  int N = 1 << (32 - __builtin_clz((int)xs.size() - 1));
  if(f.empty() || xs.empty()) return vector<mint>(s, mint(0));
  vector<FormalPowerSeries<mint>> buf(2 * N);
  for (int i = 0; i < N; i++) {
    mint n = mint{i < s ? -xs[i] : mint(0)};
    buf[i + N] = fps{n + 1, n - 1};
  }
  for (int i = N - 1; i > 0; i--) {
    fps &g(buf[(i << 1) | 0]), &h(buf[(i << 1) | 1]);
    int n = g.size();
    int m = n << 1;
    buf[i].reserve(m);
    buf[i].resize(n);
    for (int j = 0; j < n; j++) buf[i][j] = g[j] * h[j] - mint(1);
    if (i != 1) {
      buf[i].ntt_doubling();
      for (int j = 0; j < m; j++) buf[i][j] += j < n ? mint(1) : -mint(1);
    }
  }

  int fs = f.size();
  fps root = buf[1];
  root.intt();
  root.push_back(1);
  reverse(begin(root), end(root));
  root = root.inv(fs).rev() * f;
  root.erase(begin(root), begin(root) + fs - 1);
  root.resize(N, mint(0));

  vector<mint> ans(s);

  auto calc = [&](auto rec, int i, int l, int r, fps g) -> void {
    if (i >= N) {
      ans[i - N] = g[0];
      return;
    }
    int len = g.size(), m = (l + r) >> 1;
    g.ntt();
    fps tmp = buf[i * 2 + 1];
    for (int j = 0; j < len; j++) tmp[j] *= g[j];
    tmp.intt();
    rec(rec, i * 2 + 0, l, m, fps{begin(tmp) + (len >> 1), end(tmp)});
    if (m >= s) return;
    tmp = buf[i * 2 + 0];
    for (int j = 0; j < len; j++) tmp[j] *= g[j];
    tmp.intt();
    rec(rec, i * 2 + 1, m, r, fps{begin(tmp) + (len >> 1), end(tmp)});
  };
  calc(calc, 1, 0, N, root);
  return ans;
}

/**
 * @brief Multipoint Evaluation(高速化版)
 */
