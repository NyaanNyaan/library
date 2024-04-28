#pragma once

#include <vector>
using namespace std;

#include "monotone-minima.hpp"

// a は下に凸, b は自由
template <typename T>
vector<T> concave_min_plus_convolution(const vector<T>& a, const vector<T>& b) {
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size();
  auto argmin = monotone_minima(n + m - 1, m, [&](int i, int j, int k) {
    if (i < k) return true;
    if (i - j >= n) return false;
    return a[i - j] + b[j] <= a[i - k] + b[k];
  });
  vector<T> ans(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    int j = argmin[i];
    ans[i] = a[i - j] + b[j];
  }
  return ans;
}

// a は上に凸, b は自由
template <typename T>
vector<T> concave_max_plus_convolution(const vector<T>& a, const vector<T>& b) {
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size();
  auto argmin = monotone_minima(n + m - 1, m, [&](int i, int j, int k) {
    if (i < k) return true;
    if (i - j >= n) return false;
    return a[i - j] + b[j] >= a[i - k] + b[k];
  });
  vector<T> ans(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    int j = argmin[i];
    ans[i] = a[i - j] + b[j];
  }
  return ans;
}
