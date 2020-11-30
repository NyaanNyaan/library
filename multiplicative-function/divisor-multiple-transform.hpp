#pragma once
#include <bits/stdc++.h>
using namespace std;

struct divisor_transform {
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a) {
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for (int p = 2; p <= N; p++)
      if (sieve[p])
        for (int k = 1; k * p <= N; ++k) sieve[k * p] = false, a[k * p] += a[k];
  }
  template <typename T>
  static constexpr void mobius_transform(T &a) {
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for (int p = 2; p <= N; p++)
      if (sieve[p])
        for (int k = N / p; k > 0; --k) sieve[k * p] = false, a[k * p] -= a[k];
  }

  template <typename T>
  static constexpr void zeta_transform(map<long long, T> &a) {
    for (auto &x : a)
      for (auto &y : a) {
        if (x == y) break;
        if (x.first % y.first == 0) x.second += y.second;
      }
  }
  template <typename T>
  static constexpr void mobius_transform(map<long long, T> &a) {
    for (auto &x : a)
      for (auto &y : a) {
        if (x == y) break;
        if (x.first % y.first == 0) x.second -= y.second;
      }
  }
};

struct multiple_transform {
  template <typename T>
  static constexpr void zeta_transform(vector<T> &a) {
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for (int p = 2; p <= N; ++p)
      if (sieve[p])
        for (int k = N / p; k > 0; --k) sieve[k * p] = false, a[k] += a[k * p];
  }
  template <typename T>
  static constexpr void mobius_transform(vector<T> &a) {
    int N = a.size() - 1;
    vector<int> sieve(N + 1, true);
    for (int p = 2; p <= N; ++p)
      if (sieve[p])
        for (int k = 1; k * p <= N; ++k) sieve[k * p] = false, a[k] -= a[k * p];
  }

  template <typename T>
  static constexpr void zeta_transform(map<long long, T> &a) {
    for (auto it = a.rbegin(); it != a.rend(); it++)
      for (auto it2 = a.rbegin(); it2 != it; it2++)
        if (it2->first % it->first == 0) it->second += it2->second;
  }
  template <typename T>
  static constexpr void mobius_transform(map<long long, T> &a) {
    for (auto it = a.rbegin(); it != a.rend(); it++)
      for (auto it2 = a.rbegin(); it2 != it; it2++)
        if (it2->first % it->first == 0) it->second -= it2->second;
  }
};
