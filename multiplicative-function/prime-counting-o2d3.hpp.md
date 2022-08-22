---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/prime-counting-o2d3.md
    document_title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$\
      \ )"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/prime-counting-o2d3.hpp\"\n\n\n\n\
    #line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17,\
    \ ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1,\
    \ 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d,\
    \ i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d * p\
    \ / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n      \
    \   q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n\
    \  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 6 \"multiplicative-function/prime-counting-o2d3.hpp\"\
    \n\ninline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };\n\n\
    int64_t prime_counting(long long N) {\n  if(N < 2) return 0;\n\n  using i64 =\
    \ long long;\n\n  i64 N6, N3, N2, N23, nsz;\n  vector<i64> ns, h;\n  vector<int>\
    \ bit;\n\n  // calculate N^{1/2}, N^{1/3}, N{1/6}, N{2/3}\n  N2 = sqrt(N);\n \
    \ N3 = pow(N, 1.0 / 3.0);\n  while (N3 * N3 * N3 > N) N3--;\n  while ((N3 + 1)\
    \ * (N3 + 1) * (N3 + 1) <= N) N3++;\n  N6 = sqrt(N3);\n  N23 = N / N3;\n\n  //\
    \ precalc prime sieve below N ^ {1/2}\n  auto prime = prime_enumerate(N2 + 1000);\n\
    \  // index of prime\n  int pidx = 0;\n  // restore pi(p - 1)\n  i64 pi = 0;\n\
    \n  // initialize ns\n  ns.reserve(N2 * 2 + 2);\n  ns.push_back(0);\n  for (int\
    \ i = 1; i <= N2; i++) ns.push_back(my_div(N, i));\n  for (int i = ns.back() -\
    \ 1; i > 0; i--) ns.push_back(i);\n  nsz = ns.size();\n\n  // initialize h\n \
    \ copy(begin(ns), end(ns), back_inserter(h));\n  for (auto &i : h) --i;\n\n  //\
    \ p <= N ^ {1/6}\n  while (prime[pidx] <= N6) {\n    int p = prime[pidx];\n  \
    \  i64 p2 = i64(p) * p;\n    for (i64 i = 1, n = ns[i]; i < nsz && n >= p2; n\
    \ = ns[++i])\n      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n, p)] - pi;\n\
    \    ++pidx;\n    ++pi;\n  }\n\n  // fenwick tree, which restore [ h(p, 1), h(p,\
    \ N ^ {2/3}) )\n  // bit[i] corresponds to h[i + N3] (1 <= i)\n  bit.resize(nsz\
    \ - N3);\n\n  auto dfs = [&](auto rec, i64 cur, int pid, int flag) -> void {\n\
    \    if (flag) {\n      // if cur > N^{1/2} :\n      // cur <= floor(N / id)\n\
    \      // -> cur * id + n = N, n < id < cur\n      // -> id <= floor(N / cur)\n\
    \      int id = cur <= N2 ? nsz - cur : my_div(N, cur);\n      // decrease h[N3]\
    \ ~ h[id]\n      if (id > N3)\n        for (id -= N3; id; id -= id & -id) --bit[id];\n\
    \    }\n    for (int dst = pid; cur * prime[dst] < N23; dst++)\n      rec(rec,\
    \ cur * prime[dst], dst, true);\n  };\n\n  // N ^ {1/6} < p <= N ^ {1/3}\n  while\
    \ (prime[pidx] <= N3) {\n    int p = prime[pidx];\n    i64 p2 = i64(p) * p;\n\
    \    // update N ^ {2/3} <= n <= N\n    for (i64 i = 1; i <= N3; i++) {\n    \
    \  // ns[i] >= p2 > N^{1/3}\n      if (p2 > ns[i]) break;\n      // id of floor(N/ip)\n\
    \      int id = i * p <= N2 ? i * p : nsz - my_div(ns[i], p);\n      // current\
    \ value of h[id]\n\n      i64 sm = h[id];\n      // if floor(N/ip) < N^{2/3},\
    \ add sum of fenwick tree\n      if (id > N3)\n        for (id -= N3; id < (int)bit.size();\
    \ id += id & -id) sm += bit[id];\n      h[i] -= sm - pi;\n    }\n\n    // update\
    \ N ^ {1/3} <= n < N ^ {2/3}, using dfs\n    dfs(dfs, p, pidx, false);\n\n   \
    \ ++pidx;\n    ++pi;\n  }\n\n  // reflect fenwick tree\n  for (int i = (int)bit.size()\
    \ - 1; i; i--) {\n    int j = i + (i & -i);\n    if (j < (int)bit.size()) bit[i]\
    \ += bit[j];\n  }\n  for (int i = 1; i < (int)bit.size(); i++) h[i + N3] += bit[i];\n\
    \n  // N ^ {1/3} < p <= N ^ {1/2}\n  while (prime[pidx] <= N2) {\n    int p =\
    \ prime[pidx];\n    i64 p2 = i64(p) * p;\n    for (i64 i = 1, n = ns[i]; i < nsz\
    \ && n >= p2; n = ns[++i])\n      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n,\
    \ p)] - pi;\n    ++pidx;\n    ++pi;\n  }\n\n  return h[1];\n}\n\n/**\n * @brief\
    \ \u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$ )\n *\
    \ @docs docs/multiplicative-function/prime-counting-o2d3.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../prime/prime-enumerate.hpp\"\n\ninline int64_t\
    \ my_div(int64_t n, int64_t p) { return double(n) / p; };\n\nint64_t prime_counting(long\
    \ long N) {\n  if(N < 2) return 0;\n\n  using i64 = long long;\n\n  i64 N6, N3,\
    \ N2, N23, nsz;\n  vector<i64> ns, h;\n  vector<int> bit;\n\n  // calculate N^{1/2},\
    \ N^{1/3}, N{1/6}, N{2/3}\n  N2 = sqrt(N);\n  N3 = pow(N, 1.0 / 3.0);\n  while\
    \ (N3 * N3 * N3 > N) N3--;\n  while ((N3 + 1) * (N3 + 1) * (N3 + 1) <= N) N3++;\n\
    \  N6 = sqrt(N3);\n  N23 = N / N3;\n\n  // precalc prime sieve below N ^ {1/2}\n\
    \  auto prime = prime_enumerate(N2 + 1000);\n  // index of prime\n  int pidx =\
    \ 0;\n  // restore pi(p - 1)\n  i64 pi = 0;\n\n  // initialize ns\n  ns.reserve(N2\
    \ * 2 + 2);\n  ns.push_back(0);\n  for (int i = 1; i <= N2; i++) ns.push_back(my_div(N,\
    \ i));\n  for (int i = ns.back() - 1; i > 0; i--) ns.push_back(i);\n  nsz = ns.size();\n\
    \n  // initialize h\n  copy(begin(ns), end(ns), back_inserter(h));\n  for (auto\
    \ &i : h) --i;\n\n  // p <= N ^ {1/6}\n  while (prime[pidx] <= N6) {\n    int\
    \ p = prime[pidx];\n    i64 p2 = i64(p) * p;\n    for (i64 i = 1, n = ns[i]; i\
    \ < nsz && n >= p2; n = ns[++i])\n      h[i] -= h[i * p <= N2 ? i * p : nsz -\
    \ my_div(n, p)] - pi;\n    ++pidx;\n    ++pi;\n  }\n\n  // fenwick tree, which\
    \ restore [ h(p, 1), h(p, N ^ {2/3}) )\n  // bit[i] corresponds to h[i + N3] (1\
    \ <= i)\n  bit.resize(nsz - N3);\n\n  auto dfs = [&](auto rec, i64 cur, int pid,\
    \ int flag) -> void {\n    if (flag) {\n      // if cur > N^{1/2} :\n      //\
    \ cur <= floor(N / id)\n      // -> cur * id + n = N, n < id < cur\n      // ->\
    \ id <= floor(N / cur)\n      int id = cur <= N2 ? nsz - cur : my_div(N, cur);\n\
    \      // decrease h[N3] ~ h[id]\n      if (id > N3)\n        for (id -= N3; id;\
    \ id -= id & -id) --bit[id];\n    }\n    for (int dst = pid; cur * prime[dst]\
    \ < N23; dst++)\n      rec(rec, cur * prime[dst], dst, true);\n  };\n\n  // N\
    \ ^ {1/6} < p <= N ^ {1/3}\n  while (prime[pidx] <= N3) {\n    int p = prime[pidx];\n\
    \    i64 p2 = i64(p) * p;\n    // update N ^ {2/3} <= n <= N\n    for (i64 i =\
    \ 1; i <= N3; i++) {\n      // ns[i] >= p2 > N^{1/3}\n      if (p2 > ns[i]) break;\n\
    \      // id of floor(N/ip)\n      int id = i * p <= N2 ? i * p : nsz - my_div(ns[i],\
    \ p);\n      // current value of h[id]\n\n      i64 sm = h[id];\n      // if floor(N/ip)\
    \ < N^{2/3}, add sum of fenwick tree\n      if (id > N3)\n        for (id -= N3;\
    \ id < (int)bit.size(); id += id & -id) sm += bit[id];\n      h[i] -= sm - pi;\n\
    \    }\n\n    // update N ^ {1/3} <= n < N ^ {2/3}, using dfs\n    dfs(dfs, p,\
    \ pidx, false);\n\n    ++pidx;\n    ++pi;\n  }\n\n  // reflect fenwick tree\n\
    \  for (int i = (int)bit.size() - 1; i; i--) {\n    int j = i + (i & -i);\n  \
    \  if (j < (int)bit.size()) bit[i] += bit[j];\n  }\n  for (int i = 1; i < (int)bit.size();\
    \ i++) h[i + N3] += bit[i];\n\n  // N ^ {1/3} < p <= N ^ {1/2}\n  while (prime[pidx]\
    \ <= N2) {\n    int p = prime[pidx];\n    i64 p2 = i64(p) * p;\n    for (i64 i\
    \ = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])\n      h[i] -= h[i * p <= N2\
    \ ? i * p : nsz - my_div(n, p)] - pi;\n    ++pidx;\n    ++pi;\n  }\n\n  return\
    \ h[1];\n}\n\n/**\n * @brief \u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\\
    frac{2}{3}})$ )\n * @docs docs/multiplicative-function/prime-counting-o2d3.md\n\
    \ */\n"
  dependsOn:
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/prime-counting-o2d3.hpp
  requiredBy: []
  timestamp: '2021-09-05 13:40:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
documentation_of: multiplicative-function/prime-counting-o2d3.hpp
layout: document
redirect_from:
- /library/multiplicative-function/prime-counting-o2d3.hpp
- /library/multiplicative-function/prime-counting-o2d3.hpp.html
title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$ )"
---
[Min_25氏の記事およびツイート](https://twitter.com/min_25_/status/1247483565933121537)を参考にした素数カウントの$\mathrm{O}(N^{\frac{2}{3}})$での実装。実装の詳細はコメントに記した。

計算量は改善されているが、競プロの制約($N \leq 10^{11}$)では[シンプルな実装](https://nyaannyaan.github.io/library/library/multiplicative-function/prime-counting.hpp.html)と実行速度に大きな差が出ないようだ。

TODO: 計算量解析を書く