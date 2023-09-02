#pragma once

#include <vector>
using namespace std;

template <typename mint>
mint determinant_arbitrary_mod(vector<vector<mint>> a) {
  int n = a.size();
  mint det = 1;
  for (int j = 0; j < n; j++) {
    for (int i = j; i < n; i++) {
      if (a[i][j] == 0) continue;
      if (i != j) swap(a[i], a[j]), det = -det;
      break;
    }
    if (a[j][j] == 0) return 0;
    for (int i = j + 1; i < n; i++) {
      while (a[i][j] != 0) {
        long long q = a[j][j].get() / a[i][j].get();
        mint c = -q;
        for (int k = j; k < n; k++) a[j][k] += a[i][k] * c;
        swap(a[i], a[j]), det = -det;
      }
    }
  }

  for (int i = 0; i < n; i++) det *= a[i][i];
  return det;
}
