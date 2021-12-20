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
    assert(m < (1LL << 42));
    sq = sqrt(M);
    while (sq * sq > M) sq--;
    while ((sq + 1) * (sq + 1) <= M) sq++;

    if (M != 0) {
      i64 hls = md(M, sq);
      if (hls != 1 && md(M, hls - 1) == sq) hls--;
      s = hls + sq;

      p = prime_enumerate(sq);
      ps = p.size();
      ans = T{};
    }
  }

  // 素数の個数関数に関するテーブル
  vector<T> pi_table() {
    if (M == 0) return {};
    i64 hls = md(M, sq);
    if (hls != 1 && md(M, hls - 1) == sq) hls--;

    vector<i64> hl(hls);
    for (int i = 1; i < hls; i++) hl[i] = md(M, i) - 1;

    vector<int> hs(sq + 1);
    iota(begin(hs), end(hs), -1);

    int pi = 0;
    for (auto& x : p) {
      i64 x2 = i64(x) * x;
      i64 imax = min<i64>(hls, md(M, x2) + 1);
      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {
        hl[i] -= (ix < hls ? hl[ix] : hs[md(M, ix)]) - pi;
      }
      for (int n = sq; n >= x2; n--) hs[n] -= hs[md(n, x)] - pi;
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
    i64 hls = md(M, sq);
    if (hls != 1 && md(M, hls - 1) == sq) hls--;

    vector<T> h(s);
    T inv2 = T{2}.inverse();
    for (int i = 1; i < hls; i++) {
      T x = md(M, i);
      h[i] = x * (x + 1) * inv2 - 1;
    }
    for (int i = 1; i <= sq; i++) {
      T x = i;
      h[s - i] = x * (x + 1) / 2 - 1;
    }

    for (auto& x : p) {
      T xt = x;
      T pi = h[s - x + 1];
      i64 x2 = i64(x) * x;
      i64 imax = min<i64>(hls, md(M, x2) + 1);
      i64 ix = x;
      for (i64 i = 1; i < imax; ++i, ix += x) {
        h[i] -= ((ix < hls ? h[ix] : h[s - md(M, ix)]) - pi) * xt;
      }
      for (int n = sq; n >= x2; n--) {
        h[s - n] -= (h[s - md(n, x)] - pi) * xt;
      }
    }

    assert((int)h.size() == s);
    return h;
  }

  void dfs(int i, int c, i64 prod, T cur) {
    ans += cur * f(p[i], c + 1);
    i64 lim = md(M, prod);
    if (lim >= 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod, cur);
    cur *= f(p[i], c);
    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);
    int j = i + 1;
    // M < 2**42 -> p_j < 2**21 -> (p_j)^3 < 2**63
    for (; j < ps && 1LL * p[j] * p[j] * p[j] <= lim; j++) {
      dfs(j, 1, prod * p[j], cur);
    }
    for (; j < ps && 1LL * p[j] * p[j] <= lim; j++) {
      T sm = f(p[j], 2);
      int id1 = idx(md(lim, p[j])), id2 = idx(p[j]);
      sm += f(p[j], 1) * (buf[id1] - buf[id2]);
      ans += cur * sm;
    }
  }

  // fprime 破壊的
  T run(vector<T>& fprime) {
    if (M == 0) return {};
    set_buf(fprime);
    assert((int)buf.size() == s);
    ans = buf[idx(M)] + 1;
    for (int i = 0; i < ps; i++) dfs(i, 1, p[i], 1);
    return ans;
  }

 private:
  i64 md(i64 n, i64 d) { return double(n) / d; }
  i64 idx(i64 n) { return n <= sq ? s - n : md(M, n); }
  void set_buf(vector<T>& _buf) { swap(buf, _buf); }
};

/**
 * @brief 乗法的関数のprefix sum
 * @docs docs/multiplicative-function/sum-of-multiplicative-function.md
 */
