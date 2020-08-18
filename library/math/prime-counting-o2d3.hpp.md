---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: 素数カウント($\mathrm{O}(N^{\frac{2}{3}})$) <small>(math/prime-counting-o2d3.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime-counting-o2d3.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-19 02:01:39+09:00




[Min_25氏の記事およびツイート](https://twitter.com/min_25_/status/1247483565933121537)を参考にした素数カウントの$\mathrm{O}(N^{\frac{2}{3}})$での実装。実装の詳細はコメントに記した。

計算量は改善されているが、競プロの制約($N \leq 10^{11}$)では[シンプルな実装](https://nyaannyaan.github.io/library/library/math/prime-counting.hpp.html)と実行速度に大きな差が出ないようだ。

TODO: 計算量解析を書く

## Depends on

* :heavy_check_mark: <a href="prime-table.hpp.html">math/prime-table.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp.html">verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./prime-table.hpp"

inline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };

int64_t prime_counting(long long N) {
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
  auto prime = PrimeTable(N2 + 1000);
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
 * @brief 素数カウント($\mathrm{O}(N^{\frac{2}{3}})$)
 * @docs docs/math/prime-counting-o2d3.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/prime-counting-o2d3.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "math/prime-table.hpp"
using namespace std;

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> PrimeTable(int N) {
  vector<bool> sieve(N / 3 + 1, 1);
  for (int p = 5, d = 4, i = 1, sqn = int(sqrt(N) + 0.1); p <= sqn;
       p += d = 6 - d, i++) {
    if (!sieve[i]) continue;
    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,
             qe = sieve.size();
         q < qe; q += r = s - r)
      sieve[q] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
    if (sieve[i]) ret.push_back(p);
  while (!ret.empty() && ret.back() > N) ret.pop_back();
  return ret;
}
#line 6 "math/prime-counting-o2d3.hpp"

inline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };

int64_t prime_counting(long long N) {
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
  auto prime = PrimeTable(N2 + 1000);
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
 * @brief 素数カウント($\mathrm{O}(N^{\frac{2}{3}})$)
 * @docs docs/math/prime-counting-o2d3.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

