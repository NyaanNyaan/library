#pragma once

#include <vector>
using namespace std;

#include "monotone-minima.hpp"

template <typename T>
bool is_downward_concave(const vector<T>& v) {
  if ((int)v.size() <= 2) return true;
  T d1 = v[1] - v[0];
  for (int i = 1; i + 1 < (int)v.size(); i++) {
    T d2 = v[i + 1] - v[i];
    if (d1 > d2) return false;
    d1 = d2;
  }
  return true;
}

// a は下に凸, b は自由
template <typename T>
vector<T> concave_min_plus_convolution(const vector<T>& a, const vector<T>& b) {
  assert(is_downward_concave(a));
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size();
  if (is_downward_concave(b)) {
    vector<T> c{a[0] + b[0]};
    int i = 0, j = 0;
    while (i + 1 != n && j + 1 != m) {
      T d1 = a[i + 1] - a[i];
      T d2 = b[j + 1] - b[j];
      if (d1 <= d2) {
        c.push_back(c.back() + d1), i++;
      } else {
        c.push_back(c.back() + d2), j++;
      }
    }
    while (i + 1 != n) c.push_back(c.back() + a[i + 1] - a[i]), i++;
    while (j + 1 != m) c.push_back(c.back() + b[j + 1] - b[j]), j++;
    return c;
  }
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

template <typename T>
bool is_upward_concave(const vector<T>& v) {
  if ((int)v.size() <= 2) return true;
  T d1 = v[1] - v[0];
  for (int i = 1; i + 1 < (int)v.size(); i++) {
    T d2 = v[i + 1] - v[i];
    if (d1 < d2) return false;
    d1 = d2;
  }
  return true;
}

// a は上に凸, b は自由
template <typename T>
vector<T> concave_max_plus_convolution(const vector<T>& a, const vector<T>& b) {
  assert(is_upward_concave(a));
  if (a.empty() or b.empty()) return {};
  int n = a.size(), m = b.size();
  if (is_upward_concave(b)) {
    vector<T> c{a[0] + b[0]};
    int i = 0, j = 0;
    while (i + 1 != n && j + 1 != m) {
      T d1 = a[i + 1] - a[i];
      T d2 = b[j + 1] - b[j];
      if (d1 >= d2) {
        c.push_back(c.back() + d1), i++;
      } else {
        c.push_back(c.back() + d2), j++;
      }
    }
    while (i + 1 != n) c.push_back(c.back() + a[i + 1] - a[i]), i++;
    while (j + 1 != m) c.push_back(c.back() + b[j + 1] - b[j]), j++;
    return c;
  }
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
