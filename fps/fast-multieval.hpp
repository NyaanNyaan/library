#pragma once
#include "../modint/montgomery-modint.hpp"
#include "./ntt-friendly-fps.hpp"

template <typename mint>
__attribute__((target("avx2"), optimize("unroll-loops"))) vector<mint>
FastMultiEval(const FormalPowerSeries<mint> &f, const vector<mint> &xs) {
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

  /**/
  fps::set_fft();
  NTT<mint> &ntt = *static_cast<NTT<mint> *>(fps::ntt_ptr);
  mint *ar1 = reinterpret_cast<mint *>(buf1_);
  mint *ar2 = reinterpret_cast<mint *>(buf2_);
  for (int i = 0; i < N; i++) ar1[i] = root[i];

  using A = array<int, 4>;
  queue<A> Q;
  Q.push({1, 0, 0, N});
  while (!Q.empty()) {
    auto [i, l, st, len] = Q.front();
    Q.pop();
    mint *f = ar1 + st;
    mint *g = ar2 + st;
    if (i >= N) continue;
    ntt.ntt(f, len);

    memcpy(g, f, len * sizeof(int));
    int m = l + (len >> 1);

    for (int j = 0; j < len; j++) f[j] *= buf[(i << 1) + 1][j];
    ntt.intt(f, len);
    memcpy(f, f + (len >> 1), (len >> 1) * sizeof(int));
    Q.push({i * 2 + 0, l, st, len >> 1});

    if (m >= s) continue;
    for (int j = 0; j < len; j++) g[j] *= buf[(i << 1) + 0][j];
    ntt.intt(g, len);
    memcpy(f + (len >> 1), g + (len >> 1), (len >> 1) * sizeof(int));
    Q.push({i * 2 + 1, m, st + (len >> 1), len >> 1});
  }

  vector<mint> ans(ar1, ar1 + s);
  return ans;
}