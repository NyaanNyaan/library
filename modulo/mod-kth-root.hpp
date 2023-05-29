#pragma once

#include "../internal/internal-math.hpp"
#include "../modint/arbitrary-montgomery-modint.hpp"
#include "../prime/fast-factorize.hpp"

namespace kth_root_mod {

// fast BS-GS
template <typename T>
struct Memo {
  Memo(const T &g, int s, int period)
      : size(1 << __lg(min(s, period))),
        mask(size - 1),
        period(period),
        vs(size),
        os(size + 1) {
    T x(1);
    for (int i = 0; i < size; ++i, x *= g) os[x.get() & mask]++;
    for (int i = 1; i < size; ++i) os[i] += os[i - 1];
    x = 1;
    for (int i = 0; i < size; ++i, x *= g) vs[--os[x.get() & mask]] = {x, i};
    gpow = x;
    os[size] = size;
  }
  int find(T x) const {
    for (int t = 0; t < period; t += size, x *= gpow) {
      for (int m = (x.get() & mask), i = os[m]; i < os[m + 1]; ++i) {
        if (x == vs[i].first) {
          int ret = vs[i].second - t;
          return ret < 0 ? ret + period : ret;
        }
      }
    }
    assert(0);
  }
  T gpow;
  int size, mask, period;
  vector<pair<T, int>> vs;
  vector<int> os;
};

template <typename INT, typename LINT, typename mint>
mint pe_root(INT c, INT pi, INT ei, INT p) {
  if (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);
  INT s = p - 1, t = 0;
  while (s % pi == 0) s /= pi, ++t;
  INT pe = 1;
  for (INT _ = 0; _ < ei; ++_) pe *= pi;

  INT u = internal::inv(pe - s % pe, pe);
  mint mc = c, one = 1;
  mint z = mc.pow((s * u + 1) / pe);
  mint zpe = mc.pow(s * u);
  if (zpe == one) return z;
  assert(t > ei);

  mint vs;
  {
    INT ptm1 = 1;
    for (INT _ = 0; _ < t - 1; ++_) ptm1 *= pi;
    for (mint v = 2;; v += one) {
      vs = v.pow(s);
      if (vs.pow(ptm1) != one) break;
    }
  }

  mint vspe = vs.pow(pe);
  INT vs_e = ei;
  mint base = vspe;
  for (INT _ = 0; _ < t - ei - 1; _++) base = base.pow(pi);
  Memo<mint> memo(base, (INT)(sqrt(t - ei) * sqrt(pi)) + 1, pi);

  while (zpe != one) {
    mint tmp = zpe;
    INT td = 0;
    while (tmp != 1) ++td, tmp = tmp.pow(pi);
    INT e = t - td;
    while (vs_e != e) {
      vs = vs.pow(pi);
      vspe = vspe.pow(pi);
      ++vs_e;
    }

    // BS-GS ... find (zpe * ( vspe ^ n ) ) ^( p_i ^ (td - 1) ) = 1
    mint base_zpe = zpe.inverse();
    for (INT _ = 0; _ < td - 1; _++) base_zpe = base_zpe.pow(pi);
    INT bsgs = memo.find(base_zpe);

    z *= vs.pow(bsgs);
    zpe *= vspe.pow(bsgs);
  }
  return z;
}

template <typename INT, typename LINT, typename mint>
INT inner_kth_root(INT a, INT k, INT p) {
  a %= p;
  if (k == 0) return a == 1 ? a : -1;
  if (a <= 1 || k <= 1) return a;
  assert(p > 2);
  if (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);
  INT g = gcd(p - 1, k);
  if (internal::modpow<INT, LINT>(a, (p - 1) / g, p) != 1) return -1;
  a = mint(a).pow(internal::inv(k / g, (p - 1) / g)).get();
  unordered_map<INT, int> fac;
  for (auto &f : factorize(g)) fac[f]++;
  if (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);
  for (auto pp : fac)
    a = pe_root<INT, LINT, mint>(a, pp.first, pp.second, p).get();
  return a;
}

int64_t kth_root(int64_t a, int64_t k, int64_t p) {
  if (max({a, k, p}) < (1LL << 30))
    return inner_kth_root<int32_t, int64_t,
                          ArbitraryLazyMontgomeryModInt<163553130>>(a, k, p);
  else
    return inner_kth_root<int64_t, __int128_t,
                          ArbitraryLazyMontgomeryModInt64bit<504025646>>(a, k,
                                                                         p);
}

}  // namespace kth_root_mod
using kth_root_mod::kth_root;

/**
 * @brief kth root(Tonelli-Shanks algorithm)
 * @docs docs/modulo/mod-kth-root.md
 */
