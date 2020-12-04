#pragma once

vector<int> factor_enumerate(int N) {
  vector<int> lp(N + 1, 0);
  if (N < 2) return lp;
  vector<int> pr{2, 3};
  for (int i = 2; i <= N; i += 2) lp[i] = 2;
  for (int i = 3; i <= N; i += 6) lp[i] = 3;
  for (int i = 5, d = 4; i <= N; i += d = 6 - d) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 2; j < (int)pr.size() && i * pr[j] <= N; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) break;
    }
  }
  return lp;
}