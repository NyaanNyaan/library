#pragma once

struct log_table {
  static constexpr int M = 65536;
  static constexpr int mask = M - 1;
  double l[M];
  log_table() : l() {
    unsigned long long x = 88172645463325252ULL;
    double log_u64max = log(2) * 64;
    for (int i = 0; i < M; i++) {
      x = x ^ (x << 7);
      x = x ^ (x >> 9);
      l[i] = log(double(x)) - log_u64max;
    }
  }
  double operator()(int i) const { return l[i & mask]; }
};
