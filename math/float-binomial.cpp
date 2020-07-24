#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

struct float_bicom {
  vector<long double> fac;
  float_bicom(int MAX) {
    fac.resize(MAX + 1, 0.0);
    fac[0] = 0.0;
    for (int i = 1; i <= MAX; i++) {
      fac[i] = fac[i - 1] + log(i);
    }
  }
  long double C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k] - fac[k]);
  }
  long double P(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k]);
  }
};