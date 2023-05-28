#pragma once

// 長さが等しい列同士の畳み込みしかしない
template <typename fps>
fps multivariate_multiplication(const fps& f, const fps& g,
                                const vector<int>& base) {
  assert(f.size() == g.size());
  int n = f.size(), s = base.size(), W = 1;
  if (s == 0) return fps{f[0] * g[0]};
  while (W < 2 * n) W *= 2;

  vector<int> chi(n);
  for (int i = 0; i < n; i++) {
    int x = i;
    for (int j = 0; j < s - 1; j++) chi[i] += (x /= base[j]);
    chi[i] %= s;
  }

  vector<fps> F(s, fps(W)), G(s, fps(W));
  for (int i = 0; i < n; i++) F[chi[i]][i] = f[i], G[chi[i]][i] = g[i];

  for (auto& x : F) x.ntt();
  for (auto& x : G) x.ntt();
  fps a(s);
  for (int k = 0; k < W; k++) {
    fill(begin(a), end(a), typename fps::value_type());
    for (int i = 0; i < s; i++)
      for (int j = 0; j < s; j++) {
        a[i + j - (i + j >= s ? s : 0)] += F[i][k] * G[j][k];
      }
    for (int i = 0; i < s; i++) F[i][k] = a[i];
  }
  for (auto& x : F) x.intt();
  fps h(n);
  for (int i = 0; i < n; i++) h[i] = F[chi[i]][i];
  return h;
}

/**
 * @brief Multivariate Multiplication
 * @docs docs/ntt/multivariate-multiplication.md
 */
