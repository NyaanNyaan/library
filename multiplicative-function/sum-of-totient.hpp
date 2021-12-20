#pragma once

template <typename T>
T sum_of_totient(long long N) {
  if (N < 2) return N;
  using i64 = long long;

  auto f = [](i64 v, i64 p, i64) -> i64 { return v / p * (p - 1); };
  vector<i64> ns{0}, p;
  for (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);
  i64 s = ns.size(), sq = sqrt(N);
  auto idx = [&](i64 n) { return n <= sq ? s - n : N / n; };

  vector<T> h0(s), h1(s), buf(s);
  for (int i = 0; i < s; i++) {
    T x = ns[i];
    h0[i] = x - 1;
    h1[i] = x * (x + 1) / 2 - 1;
  }

  for (i64 x = 2; x <= sq; ++x) {
    if (h0[s - x] == h0[s - x + 1]) continue;
    p.push_back(x);
    i64 x2 = x * x;
    for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i]) {
      int id = (i * x <= sq ? i * x : s - n / x);
      h0[i] -= h0[id] - h0[s - x + 1];
      h1[i] -= (h1[id] - h1[s - x + 1]) * x;
    }
  }

  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];
  T ans = buf[idx(N)] + 1;

  auto dfs = [&](auto rec, int i, int c, i64 v, i64 lim, T cur) -> void {
    ans += cur * f(p[i] * v, p[i], c + 1);
    if (lim >= p[i] * p[i]) rec(rec, i, c + 1, p[i] * v, lim / p[i], cur);
    cur *= f(v, p[i], c);
    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);
    for (int j = i + 1; j < (int)p.size() && p[j] * p[j] <= lim; j++) {
      rec(rec, j, 1, p[j], lim / p[j], cur);
    }
  };

  for (int i = 0; i < (int)p.size(); i++) dfs(dfs, i, 1, p[i], N / p[i], 1);
  return ans;
}

/**
 * @brief トーシェント関数の和
 */
