#pragma once

#include "../prime/prime-enumerate.hpp"
#include "../template/template.hpp"

// f(n, p, c) : n = pow(p, c), f is multiplicative function

template <typename T, T (*f)(int, int, int)>
struct enamurate_multiplicative_function {
  enamurate_multiplicative_function(int _n)
      : ps(prime_enumerate(_n)), a(_n + 1, T()), n(_n), p(ps.size()) {}

  vector<T> run() {
    a[1] = 1;
    dfs(-1, 1, 1);
    return a;
  }

 private:
  vector<int> ps;
  vector<T> a;
  int n, p;
  void dfs(int i, long long x, T y) {
    a[x] = y;
    if (y == T()) return;
    for (int j = i + 1; j < p; j++) {
      long long nx = x * ps[j];
      long long dx = ps[j];
      if (nx > n) break;
      for (int c = 1; nx <= n; nx *= ps[j], dx *= ps[j], ++c) {
        dfs(j, nx, y * f(dx, ps[j], c));
      }
    }
  }
};

/**
 * @brief 乗法的関数の列挙
 */
