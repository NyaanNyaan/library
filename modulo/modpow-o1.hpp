#pragma once

#include <cmath>
#include <utility>
#include <vector>
using namespace std;

#include "../math/primitive-root-ll.hpp"
#include "../modint/barrett-reduction.hpp"
#include "../prime/factor-enumerate.hpp"
#include "mod-log-fast.hpp"

// 2^{30} < mod < 2^{31} の時は LOG_T = ll にする！
template <typename mint, typename LOG_T = int>
struct Modulo_O1 {
  int p, proot, n, n2, table_size, sqrt_p, shift, mask;
  LOG_T log_m1;
  vector<pair<int, int>> info;
  vector<mint> preinv, prelo, prehi;
  vector<LOG_T> prelog;
  Barrett barrett_pm1;

  Modulo_O1(int _proot = -1)
      : p(mint::get_mod()), proot(_proot), barrett_pm1(p - 1) {
    assert(p >= 2);
    if (proot == -1) proot = primitive_root_ll(p);
    n = ceil(std::pow(p, 1.0 / 3)) + 1, n2 = n * n;
    table_size = p / n + (n << 10) + 10;
    sqrt_p = ceil(sqrt(p)) + 1;
    shift = 1;
    while ((1 << shift) <= sqrt_p) shift++;
    mask = (1 << shift) - 1;
    log_m1 = (p - 1) / 2;

    vector<int> pre(n2 + 1), suf(n2 + 1);
    for (int i = 0; i <= n2; i++) pre[i] = suf[i] = 0;
    for (int y = 1; y < n; y++) {
      for (int x = 0; x <= y; x++) {
        int z = 1LL * x * n2 / y;
        if (!pre[z]) pre[z] = suf[z] = (x << 16) + y;
      }
    }
    for (int i = 1; i <= n2; i++) {
      if (!pre[i]) pre[i] = pre[i - 1];
    }
    for (int i = n2 - 1; i >= 0; i--) {
      if (!suf[i]) suf[i] = suf[i + 1];
    }

    info.resize((p >> 10) + 1);
    for (int j = 0; j <= (p >> 10); j++) {
      int a = j << 10;
      int i = 1LL * a * n2 / p;
      int x1 = pre[i] >> 16, y1 = pre[i] & 65535;
      int x2 = suf[i] >> 16, y2 = suf[i] & 65535;
      int u1 = 1LL * a * y1 - 1LL * p * x1;
      int u2 = 1LL * a * y2 - 1LL * p * x2;
      int y = abs(u1) < abs(u2) ? y1 : y2;
      int z = 1LL * a * y % p;
      if (z >= p / 2) z -= p;
      info[j] = make_pair(y, z);
    }

    preinv.resize(table_size);
    preinv[0] = preinv[1] = 1;
    for (int i = 2; i < table_size; i++) {
      if (i >= p) {
        preinv[i] = preinv[i - p];
      } else {
        preinv[i] = preinv[p % i] * (p - p / i);
      }
    }

    int Q = max<int>(1, sqrt_p / std::log(sqrt_p));
    FastBSGS<mint> bsgs(proot, sqrt(1LL * p * Q), p - 1);
    prelog.resize(table_size);
    prelog[0] = prelog[1] = 0;
    auto lpf = factor_enumerate(sqrt_p);
    for (int i = 2; i < table_size; i++) {
      if (i >= p) {
        prelog[i] = prelog[i - p];
      } else if (i <= sqrt_p) {
        if (lpf[i] == i) {
          prelog[i] = bsgs.find(i);
        } else {
          prelog[i] = prelog[i / lpf[i]] + prelog[lpf[i]];
          if (prelog[i] >= p - 1) prelog[i] -= p - 1;
        }
      } else {
        int j = p / i, k = p % i;
        prelog[i] = prelog[k] + log_m1 - prelog[j];
        if (prelog[i] >= p - 1) prelog[i] -= p - 1;
        if (prelog[i] < 0) prelog[i] += p - 1;
      }
    }

    prelo.resize(1 << shift), prehi.resize(1 << shift);
    mint x = 1, y = proot;
    for (int i = 0; i < (1 << shift); i++) prelo[i] = x, x *= y;
    swap(x, y = 1);
    for (int i = 0; i < (1 << shift); i++) prehi[i] = x, x *= y;
  }

  mint inv(int a) {
    auto [y, z] = info[a >> 10];
    z += (a & 1023) * y;
    return (z < 0 ? -preinv[-z] : preinv[z]) * y;
  }
  LOG_T log(int a) {
    auto [y, z] = info[a >> 10];
    z += (a & 1023) * y;
    LOG_T lg = (z < 0 ? prelog[-z] + log_m1 : prelog[z]) - prelog[y];
    return lg >= p - 1 ? lg - (p - 1) : lg < 0 ? lg + p - 1 : lg;
  }
  mint pow(int a, long long e) {
    assert(0 <= a and a < p);
    if (a == 0) return e == 0 ? 1 : 0;
    if (e > p - 1) e = barrett_pm1.rem(e);
    if ((e *= log(a)) > p - 1) e = barrett_pm1.rem(e);
    return prelo[e & mask] * prehi[e >> shift];
  }
  mint inv(mint a) { return inv(a.get()); }
  LOG_T log(mint a) { return log(a.get()); }
  mint pow(mint a, long long e) { return pow(a.get(), e); }
};
