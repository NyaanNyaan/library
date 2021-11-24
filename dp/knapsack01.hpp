#pragma once

long long knapsack01(const vector<long long>& v, const vector<long long>& w,
                     long long W) {
  double v_sum = 0;
  for (auto& x : v) v_sum += x;
  double cond1 = log2(double(W) * (v.size() + 1));
  double cond2 = log2(v_sum * (v.size() + 1));
  double cond3 = ((v.size() + 1) / 2) + log2(v.size() + 1);
  double cond_min = min({cond1, cond2, cond3});
  long long inf = numeric_limits<long long>::max() / 2.1;

  if (cond_min == cond1) {
    vector<long long> dp(W + 1);
    for (int i = 0; i < (int)v.size(); i++) {
      long long s = v[i], t = w[i];
      for (int j = W - t; j >= 0; --j) dp[j + t] = max(dp[j + t], dp[j] + s);
    }
    return *max_element(begin(dp), end(dp));
  }
  if (cond_min == cond2) {
    long long vs = accumulate(begin(v), end(v), 0LL);
    vector<long long> dp(vs + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < (int)v.size(); i++) {
      long long s = v[i], t = w[i];
      for (int j = vs - s; j >= 0; --j) dp[j + s] = min(dp[j + s], dp[j] + t);
    }
    long long ans = 0;
    for (long long i = 0; i <= vs; i++)
      if (dp[i] <= W) ans = max(ans, i);
    return ans;
  }

  using P = pair<long long, long long>;
  auto enumerate = [&](int l, int r) -> vector<P> {
    vector<P> res(1 << (r - l));
    res[0] = P{0, 0};
    for (int i = 0; i < r - l; i++) {
      int b = 1 << i;
      for (int j = 0; j < b; j++) {
        res[b + j] = P{res[j].first + w[l + i], res[j].second + v[l + i]};
      }
    }
    sort(begin(res), end(res));
    for (int i = 1; i < (int)res.size(); i++)
      res[i].second = max(res[i].second, res[i - 1].second);
    return res;
  };
  auto a = enumerate(0, (int)v.size() / 2);
  auto b = enumerate(v.size() / 2, v.size());
  reverse(begin(a), end(a));
  b.emplace_back(inf, inf);
  long long ans = 0, id = -1;
  for (auto& [t, s] : a) {
    while (t + b[id + 1].first <= W) ++id;
    if (id != -1) ans = max(ans, s + b[id].second);
  }
  return ans;
}

/**
 * @brief 0-1ナップサック問題
 * @docs docs/dp/knapsack01.md
 */
