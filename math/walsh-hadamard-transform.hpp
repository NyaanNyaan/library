#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void walsh_hadamard_transform(vector<T>& f, int inverse = false) {
  int n = f.size();
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = x + y, f[j | i] = x - y;
        if (inverse) f[j] /= 2, f[j | i] /= 2;
      }
    }
  }
}
