#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../prime/prime-enumerate.hpp"

struct divisor_transform {
  template <typename T>
  static void zeta_transform(vector<T> &a) {
    int N = a.size() - 1;
    auto sieve = prime_enumerate(N);
    for (auto &p : sieve)
      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];
  }
  template <typename T>
  static void mobius_transform(T &a) {
    int N = a.size() - 1;
    auto sieve = prime_enumerate(N);
    for (auto &p : sieve)
      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];
  }

  template <typename T>
  static void zeta_transform(map<long long, T> &a) {
    for (auto &x : a)
      for (auto &y : a) {
        if (x == y) break;
        if (x.first % y.first == 0) x.second += y.second;
      }
  }
  template <typename T>
  static void mobius_transform(map<long long, T> &a) {
    for (auto &x : a)
      for (auto &y : a) {
        if (x == y) break;
        if (x.first % y.first == 0) x.second -= y.second;
      }
  }
};

struct multiple_transform {
  template <typename T>
  static void zeta_transform(vector<T> &a) {
    int N = a.size() - 1;
    auto sieve = prime_enumerate(N);
    for (auto &p : sieve)
      for (int k = N / p; k > 0; --k) a[k] += a[k * p];
  }
  template <typename T>
  static void mobius_transform(vector<T> &a) {
    int N = a.size() - 1;
    auto sieve = prime_enumerate(N);
    for (auto &p : sieve)
      for (int k = 1; k * p <= N; ++k) a[k] -= a[k * p];
  }

  template <typename T>
  static void zeta_transform(map<long long, T> &a) {
    for (auto p1 = rbegin(a); p1 != rend(a); p1++)
      for (auto p2 = rbegin(a); p2 != p1; p2++)
        if (p2->first % p1->first == 0) p1->second += p2->second;
  }
  template <typename T>
  static void mobius_transform(map<long long, T> &a) {
    for (auto p1 = rbegin(a); p1 != rend(a); p1++)
      for (auto p2 = rbegin(a); p2 != p1; p2++)
        if (p2->first % p1->first == 0) p1->second -= p2->second;
  }
};
