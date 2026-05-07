#pragma once

#include <vector>
using namespace std;

#include "../modulo/binomial.hpp"

// 評価点 (0,1,...,N-1)
template <typename mint>
vector<mint> poly_interpolate(vector<mint> ys, Binomial<mint>& C) {
  int N = ys.size();
  vector<mint> L(N + 1);
  L[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = i; j >= 0; j--) L[j + 1] += L[j], L[j] *= -i;
  }
  vector<mint> w(N);
  for (int i = 0; i < N; i++) {
    w[i] = ys[i] * C.finv(N - 1 - i) * C.finv(i) * ((N - 1 - i) % 2 ? -1 : 1);
  }
  vector<mint> res(N);
  for (int x = 0; x < N; x++) {
    mint carry = 0;
    for (int i = N - 1; i >= 0; i--) {
      mint quo = L[i + 1] + carry;
      res[i] += quo * w[x];
      carry = quo * x;
    }
  }
  return res;
}
