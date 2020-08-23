#pragma once
#include "../modint/montgomery-modint.hpp"
#include "./ntt-friendly-fps.hpp"

template <typename mint>
vector<mint> FastMultiEval(const FormalPowerSeries<mint> &f,
                           const vector<mint> &xs) {
  using fps = FormalPowerSeries<mint>;
  int s = xs.size();
  int N = 1 << (32 - __builtin_clz((int)xs.size() - 1));

  vector<FormalPowerSeries<mint>> buf(2 * N);
  for (int i = 0; i < N; i++) {
    mint n = mint{i < s ? -xs[i] : mint(0)};
    buf[i + N] = fps{n + 1, n - 1};
  }
  for (int i = N - 1; i > 0; i--) {
    fps &f(buf[(i << 1) | 0]), &g(buf[(i << 1) | 1]);
    int n = f.size();
    int m = n << 1;
    buf[i].reserve(m);
    buf[i].resize(n);
    for (int j = 0; j < n; j++) buf[i][j] = f[j] * g[j] - mint(1);
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

  auto calc = [&](auto rec, int i, int l, int r, fps f) -> void {
    if (i >= N) {
      ans[i - N] = f[0];
      return;
    }
    int len = f.size(), m = (l + r) >> 1;
    f.ntt();
    fps tmp = buf[i * 2 + 1];
    for (int j = 0; j < len; j++) tmp[j] *= f[j];
    tmp.intt();
    rec(rec, i * 2 + 0, l, m, fps{begin(tmp) + (len >> 1), end(tmp)});
    if (m >= s) return;
    tmp = buf[i * 2 + 0];
    for (int j = 0; j < len; j++) tmp[j] *= f[j];
    tmp.intt();
    rec(rec, i * 2 + 1, m, r, fps{begin(tmp) + (len >> 1), end(tmp)});
  };
  calc(calc, 1, 0, N, root);
  return ans;
}
