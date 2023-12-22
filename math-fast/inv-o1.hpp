#pragma once

#include <cmath>
using namespace std;

// O(1) 逆元, 素数 mod で動く
template <int MOD>
struct Inverse_O1 {
  static constexpr int p = MOD;
  static constexpr int n = ceil(pow(p, 1.0 / 3));
  static constexpr int n2 = n * n;
  static constexpr int preinv_size = n2 + (n << 10) + 10;

  int g[(p >> 10) + 1], preinv[preinv_size];
  Inverse_O1() {
    preinv[0] = preinv[1] = 1 % p;
    for (int i = 2; i < preinv_size; i++) {
      preinv[i] = 1LL * preinv[p % i] * (p - p / i) % p;
    }

    int pre[n2 + 1], suf[n2 + 1];
    for (int i = 0; i <= n2; i++) pre[i] = suf[i] = 0;
    for (int y = 1; y < n; y++) {
      for (int x = 0; x <= y; x++) {
        int z = x * n2 / y;
        if (!pre[z]) pre[z] = suf[z] = (x << 16) + y;
      }
    }
    for (int i = 1; i <= n2; i++) {
      if (!pre[i]) pre[i] = pre[i - 1];
    }
    for (int i = n2 - 1; i >= 0; i--) {
      if (!suf[i]) suf[i] = suf[i + 1];
    }
    for (int j = 0; (j << 10) < p; j++) {
      int a = j << 10;
      int i = 1LL * a * n2 / p;
      int x1 = pre[i] >> 16, y1 = pre[i] & 65535;
      int x2 = suf[i] >> 16, y2 = suf[i] & 65535;
      int u1 = 1LL * a * y1 - 1LL * p * x1;
      int u2 = 1LL * a * y2 - 1LL * p * x2;
      g[j] = abs(u1) < abs(u2) ? y1 : y2;
    }
  }

  int inv(int a) {
    int y = g[a >> 10], z = 1LL * a * y % p;
    return 1LL * y * (z < preinv_size ? preinv[z] : p - preinv[p - z]) % p;
  }
  int operator()(int a) { return inv(a); }
};
