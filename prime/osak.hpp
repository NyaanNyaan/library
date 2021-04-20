#pragma once

#include "factor-enumerate.hpp"

template <int MAX>
vector<int> osak(int n) {
  static vector<int> f = factor_enumerate(MAX);
  vector<int> ret;
  while (f[n]) ret.push_back(f[n]), n /= f[n];
  return ret;
}

template <int MAX>
vector<pair<int, int>> osak_table(int n) {
  static vector<int> f = factor_enumerate(MAX);
  vector<pair<int, int>> v;
  for (; f[n]; n /= f[n]) {
    if (v.empty() || v.back().first != f[n]) {
      v.emplace_back(f[n], 1);
    } else {
      v.back().second++;
    }
  }
  return v;
}

template <int MAX>
vector<int> osak_divisors(int n) {
  if(n == 0) return {};
  if(n == 1) return vector<int>(1, 1);
  auto p = osak_table<MAX>(n);
  vector<int> ds;

  auto dfs = [&](auto r, int i, int c) {
    if (i == (int)p.size()) {
      ds.push_back(c);
      return;
    }
    for (int j = 0; j <= p[i].second; j++) {
      r(r, i + 1, c);
      c *= p[i].first;
    }
  };

  dfs(dfs, 0, 1);
  sort(begin(ds), end(ds));
  return ds;
}