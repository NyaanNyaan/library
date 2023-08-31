#pragma once

#include "../math/constexpr-primitive-root.hpp"
#include "arbitrary-ntt.hpp"

template <typename mint>
struct RaderNTT {
  int p, pr, len;
  const vector<mint>& w;
  vector<int> prs, iprs;
  RaderNTT() {}
  RaderNTT(int _p, int _len, const vector<mint>& _w)
      : p(_p), pr(constexpr_primitive_root(p)), len(_len), w(_w) {
    prs.resize(p - 1);
    iprs.resize(p, -1);
    for (int i = 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;
    for (int i = 0; i < p - 1; i++) iprs[prs[i]] = i;
  }

  void ntt(vector<mint>& a) {
    vector<mint> s(p - 1), t(p - 1);
    for (int i = 0; i < p - 1; i++) s[i] = a[prs[i]];
    for (int i = 0, ldp = len / p; i < p - 1; i++)
      t[i] = w[ldp * prs[i ? p - 1 - i : 0]];
    vector<mint> u = ArbitraryNTT::multiply(s, t);
    s.resize(p);
    fill(begin(s), end(s), a[0]);
    for (int i = 1; i < p; i++) s[0] += a[i];
    for (int i = 0, y = 0; i < (int)u.size(); i++) {
      s[prs[y]] += u[i];
      if (--y < 0) y += p - 1;
    }
    swap(a, s);
  }
};

/**
 * @brief Rader's FFT Algorithm
 */
