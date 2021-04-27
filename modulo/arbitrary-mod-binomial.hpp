#pragma once

#include <vector>

#include "atcoder/math.hpp"
using namespace std;

#define PRIME_POWER_BINOMIAL_M_MAX ((1LL << 30) - 1)
#define PRIME_POWER_BINOMIAL_N_MAX 20000000

struct prime_power_binomial {
  int p, q, M;
  vector<int> fac, ifac, inv;
  int delta;

  using i64 = long long;
  using u64 = unsigned long long;
  u64 iM, ip;

  inline i64 modulo_M(u64 n) {
    u64 x = u64((__uint128_t(n) * iM) >> 64);
    i64 r = i64(n - x * M);
    if (r < 0) r += M;
    return r;
  }

  inline i64 divide_p(u64 n) {
    u64 x = u64((__uint128_t(n) * ip) >> 64);
    i64 r = i64(n - x * p);
    if (r < 0) x--;
    return i64(x);
  }

  inline pair<i64, int> quorem_p(u64 n) {
    u64 x = u64((__uint128_t(n) * ip) >> 64);
    i64 r = i64(n - x * p);
    if (r < 0) r += M, x--;
    return make_pair(i64(x), int(r));
  }

  int modpow(int a, long long e) {
    int r = 1;
    while (e) {
      if (e & 1) r = modulo_M(1LL * r * a);
      a = modulo_M(1LL * a * a);
      e >>= 1;
    }
    return r;
  }

  prime_power_binomial(int _p, int _q) : p(_p), q(_q) {
    assert(1 < p && p <= PRIME_POWER_BINOMIAL_M_MAX);
    assert(_q > 0);
    long long m = 1;
    while (_q--) {
      m *= p;
      assert(m <= PRIME_POWER_BINOMIAL_M_MAX);
    }
    M = m;
    iM = u64(-1) / M + 1;
    ip = u64(-1) / p + 1;
    enumerate();
    delta = (p == 2 && q >= 3) ? 1 : M - 1;
  }

  void enumerate() {
    int MX = min<int>(M, PRIME_POWER_BINOMIAL_N_MAX + 10);
    fac.resize(MX);
    ifac.resize(MX);
    inv.resize(MX);
    fac[0] = ifac[0] = inv[0] = 1;
    fac[1] = ifac[1] = inv[1] = 1;
    for (int i = 2; i < MX; i++) {
      if (i % p == 0) {
        fac[i] = fac[i - 1];
        fac[i + 1] = modulo_M(1LL * fac[i - 1] * (i + 1));
        i++;
      } else {
        fac[i] = modulo_M(1LL * fac[i - 1] * i);
      }
    }
    ifac[MX - 1] = modpow(fac[MX - 1], M / p * (p - 1) - 1);
    for (int i = MX - 2; i > 1; --i) {
      if (i % p == 0) {
        ifac[i] = modulo_M(1LL * ifac[i + 1] * (i + 1));
        ifac[i - 1] = ifac[i];
        i--;
      } else {
        ifac[i] = modulo_M(1LL * ifac[i + 1] * (i + 1));
      }
    }
  }

  long long Lucas(long long n, long long m) {
    int res = 1;
    while (n) {
      int n0, m0;
      tie(n, n0) = quorem_p(n);
      tie(m, m0) = quorem_p(m);
      if (n0 < m0) return 0;
      res = modulo_M(1LL * res * fac[n0]);
      int buf = modulo_M(1LL * ifac[n0 - m0] * ifac[m0]);
      res = modulo_M(1LL * res * buf);
    }
    return res;
  }

  long long C(long long n, long long m) {
    if (n < m || n < 0 || m < 0) return 0;
    if (q == 1) return Lucas(n, m);
    long long r = n - m;
    int e0 = 0, eq = 0, i = 0;
    int res = 1;
    while (n) {
      res = modulo_M(1LL * res * fac[modulo_M(n)]);
      res = modulo_M(1LL * res * ifac[modulo_M(m)]);
      res = modulo_M(1LL * res * ifac[modulo_M(r)]);
      n = divide_p(n);
      m = divide_p(m);
      r = divide_p(r);
      int eps = n - m - r;
      e0 += eps;
      if (e0 >= q) return 0;
      if (++i >= q) eq += eps;
    }
    res = modulo_M(1LL * res * modpow(delta, eq));
    res = modulo_M(1LL * res * modpow(p, e0));
    return res;
  }
};

// constraints:
// (M <= 1e7 and max(N) <= 1e18) or (M < 2^30 and max(N) <= 2e7)
struct arbitrary_mod_binomial {
  int mod;
  vector<int> M;
  vector<prime_power_binomial> cs;

  arbitrary_mod_binomial(long long md) : mod(md) {
    assert(1 <= md);
    assert(md <= PRIME_POWER_BINOMIAL_M_MAX);
    for (int i = 2; i * i <= md; i++) {
      if (md % i == 0) {
        int j = 0, k = 1;
        while (md % i == 0) md /= i, j++, k *= i;
        M.push_back(k);
        cs.emplace_back(i, j);
        assert(M.back() == cs.back().M);
      }
    }
    if (md != 1) {
      M.push_back(md);
      cs.emplace_back(md, 1);
    }
    assert(M.size() == cs.size());
  }

  long long C(long long n, long long m) {
    if (mod == 1) return 0;
    vector<long long> rem, d;
    for (int i = 0; i < (int)cs.size(); i++) {
      rem.push_back(cs[i].C(n, m));
      d.push_back(M[i]);
    }
    return atcoder::crt(rem, d).first;
  }
};

#undef PRIME_POWER_BINOMIAL_M_MAX
#undef PRIME_POWER_BINOMIAL_N_MAX

/**
 * @brief 任意mod二項係数
 * @docs docs/modulo/arbitrary-mod-binomial.md
 */
