#pragma once

#include "../prime/prime-enumerate.hpp"

// f(p, c) : f(p^c) の値を返す
template <typename T, T (*f)(long long, long long)>
struct mf_prefix_sum {
  using i64 = long long;

  i64 M, sq, s;
  vector<int> p;
  int ps;
  vector<T> buf;
  T ans;

  mf_prefix_sum(i64 m) : M(m) {
    assert(m <= 1e15);
    sq = sqrt(M);
    while (sq * sq > M) sq--;
    while ((sq + 1) * (sq + 1) <= M) sq++;

    if (M != 0) {
      i64 hls = quo(M, sq);
      while (hls != 1 && quo(M, hls - 1) == sq) hls--;
      s = hls + sq;

      p = prime_enumerate(sq);
      ps = p.size();
      ans = T{};
    }
  }

  // 素数の個数関数に関するテーブル
  vector<T> pi_table() {
    if (M == 0) return {};
    i64 hls = s - sq;
    vector<i64> hl(hls);
    for (int i = 1; i < hls; i++) hl[i] = quo(M, i) - 1;

    vector<int> hs(sq + 1);
    iota(begin(hs), end(hs), -1);

    int pi = 0;
    for (auto& x : p) {
      i64 x2 = i64(x) * x;
      i64 imax = min<i64>(hls, quo(M, x2) + 1);
      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {
        hl[i] -= (ix < hls ? hl[ix] : hs[quo(M, ix)]) - pi;
      }
      for (int n = sq; n >= x2; n--) hs[n] -= hs[quo(n, x)] - pi;
      pi++;
    }

    vector<T> res;
    res.reserve(2 * sq + 10);
    for (auto& x : hl) res.push_back(x);
    for (int i = hs.size(); --i;) res.push_back(hs[i]);
    assert((int)res.size() == s);
    return res;
  }

  // 素数の prefix sum に関するテーブル
  vector<T> prime_sum_table() {
    if (M == 0) return {};
    i64 hls = s - sq;
    vector<T> h(s);
    T inv2 = T{2}.inverse();
    for (int i = 1; i < hls; i++) {
      T x = quo(M, i);
      h[i] = x * (x + 1) * inv2 - 1;
    }
    for (int i = 1; i <= sq; i++) {
      T x = i;
      h[s - i] = x * (x + 1) * inv2 - 1;
    }

    for (auto& x : p) {
      T xt = x;
      T pi = h[s - x + 1];
      i64 x2 = i64(x) * x;
      i64 imax = min<i64>(hls, quo(M, x2) + 1);
      i64 ix = x;
      for (i64 i = 1; i < imax; ++i, ix += x) {
        h[i] -= ((ix < hls ? h[ix] : h[s - quo(M, ix)]) - pi) * xt;
      }
      for (int n = sq; n >= x2; n--) {
        h[s - n] -= (h[s - quo(n, x)] - pi) * xt;
      }
    }

    assert((int)h.size() == s);
    return h;
  }

  void dfs(int i, int c, i64 prod, T cur) {
    ans += cur * f(p[i], c + 1);
    i64 lim = quo(M, prod);
    if (lim >= 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod, cur);
    cur *= f(p[i], c);
    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);
    int j = i + 1;
    // p_j < 2**21 -> (p_j)^3 < 2**63
    for (; j < ps && p[j] < (1 << 21) && 1LL * p[j] * p[j] * p[j] <= lim; j++) {
      dfs(j, 1, prod * p[j], cur);
    }
    for (; j < ps && 1LL * p[j] * p[j] <= lim; j++) {
      T sm = f(p[j], 2);
      int id1 = idx(quo(lim, p[j])), id2 = idx(p[j]);
      sm += f(p[j], 1) * (buf[id1] - buf[id2]);
      ans += cur * sm;
    }
  }

  // black algorithm
  T run(const vector<T>& Fprime) {
    if (M == 0) return {};
    assert((int)Fprime.size() == s);
    buf = Fprime;
    ans = buf[idx(M)] + 1;
    for (int i = 0; i < ps; i++) dfs(i, 1, p[i], 1);
    return ans;
  }

  vector<T> min_25_sieve(const vector<T>& Fprime) {
    if(M == 0) return {};
    assert((int)Fprime.size() == s);

    vector<i64> ns{0};
    for (int i = 1; i < s - sq; i++) ns.push_back(quo(M, i));
    for (int i = sq; i > 0; i--) ns.push_back(i);

    vector<T> F = Fprime, G = Fprime;
    for (int j = p.size() - 1; j >= 0; j--) {
      i64 P = p[j], pc = P, c = 1;
      while (quo(M, P) >= pc) {
        T f_p_c = f(P, c), f_p_cp1 = f(P, c + 1);
        T Fprime_p = Fprime[idx(P)];
        for (int i = 1; i < s; i++) {
          i64 n = ns[i];
          if (P * pc > n) break;
          G[i] += f_p_c * (F[idx(quo(n, pc))] - Fprime_p) + f_p_cp1;
        }
        c++, pc *= P;
      }
      copy(begin(G), begin(G) + min<int>(s, idx(P * P) + 1), begin(F));
    }
    for (int i = 1; i < (int)ns.size(); i++) F[i] += 1;
    return F;
  }

  i64 quo(i64 n, i64 d) { return double(n) / d; }
  i64 idx(i64 n) { return n <= sq ? s - n : quo(M, n); }
};

/**
 * @brief 乗法的関数のprefix sum
 * @docs docs/multiplicative-function/sum-of-multiplicative-function.md
 */
