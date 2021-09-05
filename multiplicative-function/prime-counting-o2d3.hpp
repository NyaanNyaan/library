#pragma once



#include "../prime/prime-enumerate.hpp"

inline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };

int64_t prime_counting(long long N) {
  if(N < 2) return 0;

  using i64 = long long;

  i64 N6, N3, N2, N23, nsz;
  vector<i64> ns, h;
  vector<int> bit;

  // calculate N^{1/2}, N^{1/3}, N{1/6}, N{2/3}
  N2 = sqrt(N);
  N3 = pow(N, 1.0 / 3.0);
  while (N3 * N3 * N3 > N) N3--;
  while ((N3 + 1) * (N3 + 1) * (N3 + 1) <= N) N3++;
  N6 = sqrt(N3);
  N23 = N / N3;

  // precalc prime sieve below N ^ {1/2}
  auto prime = prime_enumerate(N2 + 1000);
  // index of prime
  int pidx = 0;
  // restore pi(p - 1)
  i64 pi = 0;

  // initialize ns
  ns.reserve(N2 * 2 + 2);
  ns.push_back(0);
  for (int i = 1; i <= N2; i++) ns.push_back(my_div(N, i));
  for (int i = ns.back() - 1; i > 0; i--) ns.push_back(i);
  nsz = ns.size();

  // initialize h
  copy(begin(ns), end(ns), back_inserter(h));
  for (auto &i : h) --i;

  // p <= N ^ {1/6}
  while (prime[pidx] <= N6) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    for (i64 i = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])
      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n, p)] - pi;
    ++pidx;
    ++pi;
  }

  // fenwick tree, which restore [ h(p, 1), h(p, N ^ {2/3}) )
  // bit[i] corresponds to h[i + N3] (1 <= i)
  bit.resize(nsz - N3);

  auto dfs = [&](auto rec, i64 cur, int pid, int flag) -> void {
    if (flag) {
      // if cur > N^{1/2} :
      // cur <= floor(N / id)
      // -> cur * id + n = N, n < id < cur
      // -> id <= floor(N / cur)
      int id = cur <= N2 ? nsz - cur : my_div(N, cur);
      // decrease h[N3] ~ h[id]
      if (id > N3)
        for (id -= N3; id; id -= id & -id) --bit[id];
    }
    for (int dst = pid; cur * prime[dst] < N23; dst++)
      rec(rec, cur * prime[dst], dst, true);
  };

  // N ^ {1/6} < p <= N ^ {1/3}
  while (prime[pidx] <= N3) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    // update N ^ {2/3} <= n <= N
    for (i64 i = 1; i <= N3; i++) {
      // ns[i] >= p2 > N^{1/3}
      if (p2 > ns[i]) break;
      // id of floor(N/ip)
      int id = i * p <= N2 ? i * p : nsz - my_div(ns[i], p);
      // current value of h[id]

      i64 sm = h[id];
      // if floor(N/ip) < N^{2/3}, add sum of fenwick tree
      if (id > N3)
        for (id -= N3; id < (int)bit.size(); id += id & -id) sm += bit[id];
      h[i] -= sm - pi;
    }

    // update N ^ {1/3} <= n < N ^ {2/3}, using dfs
    dfs(dfs, p, pidx, false);

    ++pidx;
    ++pi;
  }

  // reflect fenwick tree
  for (int i = (int)bit.size() - 1; i; i--) {
    int j = i + (i & -i);
    if (j < (int)bit.size()) bit[i] += bit[j];
  }
  for (int i = 1; i < (int)bit.size(); i++) h[i + N3] += bit[i];

  // N ^ {1/3} < p <= N ^ {1/2}
  while (prime[pidx] <= N2) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    for (i64 i = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])
      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n, p)] - pi;
    ++pidx;
    ++pi;
  }

  return h[1];
}

/**
 * @brief 素数カウント( $\mathrm{O}(N^{\frac{2}{3}})$ )
 * @docs docs/multiplicative-function/prime-counting-o2d3.md
 */
