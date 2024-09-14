---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/sum-of-mf.test.cpp
    title: verify/verify-unit-test/sum-of-mf.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1781.test.cpp
    title: verify/verify-yuki/yuki-1781.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/sum-of-multiplicative-function.quo
    document_title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n#line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13,\
    \ 17, ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 +\
    \ 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6\
    \ - d, i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d\
    \ * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n  \
    \       q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2,\
    \ 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 4 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n// f(p, c) : f(p^c) \u306E\u5024\u3092\u8FD4\u3059\ntemplate <typename T,\
    \ T (*f)(long long, long long)>\nstruct mf_prefix_sum {\n  using i64 = long long;\n\
    \n  i64 M, sq, s;\n  vector<int> p;\n  int ps;\n  vector<T> buf;\n  T ans;\n\n\
    \  mf_prefix_sum(i64 m) : M(m) {\n    assert(m <= 1e15);\n    sq = sqrt(M);\n\
    \    while (sq * sq > M) sq--;\n    while ((sq + 1) * (sq + 1) <= M) sq++;\n\n\
    \    if (M != 0) {\n      i64 hls = quo(M, sq);\n      while (hls != 1 && quo(M,\
    \ hls - 1) == sq) hls--;\n      s = hls + sq;\n\n      p = prime_enumerate(sq);\n\
    \      ps = p.size();\n      ans = T{};\n    }\n  }\n\n  // \u7D20\u6570\u306E\
    \u500B\u6570\u95A2\u6570\u306B\u95A2\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T>\
    \ pi_table() {\n    if (M == 0) return {};\n    i64 hls = s - sq;\n    vector<i64>\
    \ hl(hls);\n    for (int i = 1; i < hls; i++) hl[i] = quo(M, i) - 1;\n\n    vector<int>\
    \ hs(sq + 1);\n    iota(begin(hs), end(hs), -1);\n\n    int pi = 0;\n    for (auto&\
    \ x : p) {\n      i64 x2 = i64(x) * x;\n      i64 imax = min<i64>(hls, quo(M,\
    \ x2) + 1);\n      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {\n       \
    \ hl[i] -= (ix < hls ? hl[ix] : hs[quo(M, ix)]) - pi;\n      }\n      for (int\
    \ n = sq; n >= x2; n--) hs[n] -= hs[quo(n, x)] - pi;\n      pi++;\n    }\n\n \
    \   vector<T> res;\n    res.reserve(2 * sq + 10);\n    for (auto& x : hl) res.push_back(x);\n\
    \    for (int i = hs.size(); --i;) res.push_back(hs[i]);\n    assert((int)res.size()\
    \ == s);\n    return res;\n  }\n\n  // \u7D20\u6570\u306E prefix sum \u306B\u95A2\
    \u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> prime_sum_table() {\n    if\
    \ (M == 0) return {};\n    i64 hls = s - sq;\n    vector<T> h(s);\n    T inv2\
    \ = T{2}.inverse();\n    for (int i = 1; i < hls; i++) {\n      T x = quo(M, i);\n\
    \      h[i] = x * (x + 1) * inv2 - 1;\n    }\n    for (int i = 1; i <= sq; i++)\
    \ {\n      T x = i;\n      h[s - i] = x * (x + 1) * inv2 - 1;\n    }\n\n    for\
    \ (auto& x : p) {\n      T xt = x;\n      T pi = h[s - x + 1];\n      i64 x2 =\
    \ i64(x) * x;\n      i64 imax = min<i64>(hls, quo(M, x2) + 1);\n      i64 ix =\
    \ x;\n      for (i64 i = 1; i < imax; ++i, ix += x) {\n        h[i] -= ((ix <\
    \ hls ? h[ix] : h[s - quo(M, ix)]) - pi) * xt;\n      }\n      for (int n = sq;\
    \ n >= x2; n--) {\n        h[s - n] -= (h[s - quo(n, x)] - pi) * xt;\n      }\n\
    \    }\n\n    assert((int)h.size() == s);\n    return h;\n  }\n\n  void dfs(int\
    \ i, int c, i64 prod, T cur) {\n    ans += cur * f(p[i], c + 1);\n    i64 lim\
    \ = quo(M, prod);\n    if (lim >= 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod,\
    \ cur);\n    cur *= f(p[i], c);\n    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n\
    \    int j = i + 1;\n    // p_j < 2**21 -> (p_j)^3 < 2**63\n    for (; j < ps\
    \ && p[j] < (1 << 21) && 1LL * p[j] * p[j] * p[j] <= lim; j++) {\n      dfs(j,\
    \ 1, prod * p[j], cur);\n    }\n    for (; j < ps && 1LL * p[j] * p[j] <= lim;\
    \ j++) {\n      T sm = f(p[j], 2);\n      int id1 = idx(quo(lim, p[j])), id2 =\
    \ idx(p[j]);\n      sm += f(p[j], 1) * (buf[id1] - buf[id2]);\n      ans += cur\
    \ * sm;\n    }\n  }\n\n  // black algorithm\n  T run(const vector<T>& Fprime)\
    \ {\n    if (M == 0) return {};\n    assert((int)Fprime.size() == s);\n    buf\
    \ = Fprime;\n    ans = buf[idx(M)] + 1;\n    for (int i = 0; i < ps; i++) dfs(i,\
    \ 1, p[i], 1);\n    return ans;\n  }\n\n  vector<T> min_25_sieve(const vector<T>&\
    \ Fprime) {\n    if(M == 0) return {};\n    assert((int)Fprime.size() == s);\n\
    \n    vector<i64> ns{0};\n    for (int i = 1; i < s - sq; i++) ns.push_back(quo(M,\
    \ i));\n    for (int i = sq; i > 0; i--) ns.push_back(i);\n\n    vector<T> F =\
    \ Fprime, G = Fprime;\n    for (int j = p.size() - 1; j >= 0; j--) {\n      i64\
    \ P = p[j], pc = P, c = 1;\n      while (quo(M, P) >= pc) {\n        T f_p_c =\
    \ f(P, c), f_p_cp1 = f(P, c + 1);\n        T Fprime_p = Fprime[idx(P)];\n    \
    \    for (int i = 1; i < s; i++) {\n          i64 n = ns[i];\n          if (P\
    \ * pc > n) break;\n          G[i] += f_p_c * (F[idx(quo(n, pc))] - Fprime_p)\
    \ + f_p_cp1;\n        }\n        c++, pc *= P;\n      }\n      copy(begin(G),\
    \ begin(G) + min<int>(s, idx(P * P) + 1), begin(F));\n    }\n    for (int i =\
    \ 1; i < (int)ns.size(); i++) F[i] += 1;\n    return F;\n  }\n\n  i64 quo(i64\
    \ n, i64 d) { return double(n) / d; }\n  i64 idx(i64 n) { return n <= sq ? s -\
    \ n : quo(M, n); }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306E\
    prefix sum\n * @docs docs/multiplicative-function/sum-of-multiplicative-function.quo\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../prime/prime-enumerate.hpp\"\n\n// f(p, c) :\
    \ f(p^c) \u306E\u5024\u3092\u8FD4\u3059\ntemplate <typename T, T (*f)(long long,\
    \ long long)>\nstruct mf_prefix_sum {\n  using i64 = long long;\n\n  i64 M, sq,\
    \ s;\n  vector<int> p;\n  int ps;\n  vector<T> buf;\n  T ans;\n\n  mf_prefix_sum(i64\
    \ m) : M(m) {\n    assert(m <= 1e15);\n    sq = sqrt(M);\n    while (sq * sq >\
    \ M) sq--;\n    while ((sq + 1) * (sq + 1) <= M) sq++;\n\n    if (M != 0) {\n\
    \      i64 hls = quo(M, sq);\n      while (hls != 1 && quo(M, hls - 1) == sq)\
    \ hls--;\n      s = hls + sq;\n\n      p = prime_enumerate(sq);\n      ps = p.size();\n\
    \      ans = T{};\n    }\n  }\n\n  // \u7D20\u6570\u306E\u500B\u6570\u95A2\u6570\
    \u306B\u95A2\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> pi_table() {\n \
    \   if (M == 0) return {};\n    i64 hls = s - sq;\n    vector<i64> hl(hls);\n\
    \    for (int i = 1; i < hls; i++) hl[i] = quo(M, i) - 1;\n\n    vector<int> hs(sq\
    \ + 1);\n    iota(begin(hs), end(hs), -1);\n\n    int pi = 0;\n    for (auto&\
    \ x : p) {\n      i64 x2 = i64(x) * x;\n      i64 imax = min<i64>(hls, quo(M,\
    \ x2) + 1);\n      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {\n       \
    \ hl[i] -= (ix < hls ? hl[ix] : hs[quo(M, ix)]) - pi;\n      }\n      for (int\
    \ n = sq; n >= x2; n--) hs[n] -= hs[quo(n, x)] - pi;\n      pi++;\n    }\n\n \
    \   vector<T> res;\n    res.reserve(2 * sq + 10);\n    for (auto& x : hl) res.push_back(x);\n\
    \    for (int i = hs.size(); --i;) res.push_back(hs[i]);\n    assert((int)res.size()\
    \ == s);\n    return res;\n  }\n\n  // \u7D20\u6570\u306E prefix sum \u306B\u95A2\
    \u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> prime_sum_table() {\n    if\
    \ (M == 0) return {};\n    i64 hls = s - sq;\n    vector<T> h(s);\n    T inv2\
    \ = T{2}.inverse();\n    for (int i = 1; i < hls; i++) {\n      T x = quo(M, i);\n\
    \      h[i] = x * (x + 1) * inv2 - 1;\n    }\n    for (int i = 1; i <= sq; i++)\
    \ {\n      T x = i;\n      h[s - i] = x * (x + 1) * inv2 - 1;\n    }\n\n    for\
    \ (auto& x : p) {\n      T xt = x;\n      T pi = h[s - x + 1];\n      i64 x2 =\
    \ i64(x) * x;\n      i64 imax = min<i64>(hls, quo(M, x2) + 1);\n      i64 ix =\
    \ x;\n      for (i64 i = 1; i < imax; ++i, ix += x) {\n        h[i] -= ((ix <\
    \ hls ? h[ix] : h[s - quo(M, ix)]) - pi) * xt;\n      }\n      for (int n = sq;\
    \ n >= x2; n--) {\n        h[s - n] -= (h[s - quo(n, x)] - pi) * xt;\n      }\n\
    \    }\n\n    assert((int)h.size() == s);\n    return h;\n  }\n\n  void dfs(int\
    \ i, int c, i64 prod, T cur) {\n    ans += cur * f(p[i], c + 1);\n    i64 lim\
    \ = quo(M, prod);\n    if (lim >= 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod,\
    \ cur);\n    cur *= f(p[i], c);\n    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n\
    \    int j = i + 1;\n    // p_j < 2**21 -> (p_j)^3 < 2**63\n    for (; j < ps\
    \ && p[j] < (1 << 21) && 1LL * p[j] * p[j] * p[j] <= lim; j++) {\n      dfs(j,\
    \ 1, prod * p[j], cur);\n    }\n    for (; j < ps && 1LL * p[j] * p[j] <= lim;\
    \ j++) {\n      T sm = f(p[j], 2);\n      int id1 = idx(quo(lim, p[j])), id2 =\
    \ idx(p[j]);\n      sm += f(p[j], 1) * (buf[id1] - buf[id2]);\n      ans += cur\
    \ * sm;\n    }\n  }\n\n  // black algorithm\n  T run(const vector<T>& Fprime)\
    \ {\n    if (M == 0) return {};\n    assert((int)Fprime.size() == s);\n    buf\
    \ = Fprime;\n    ans = buf[idx(M)] + 1;\n    for (int i = 0; i < ps; i++) dfs(i,\
    \ 1, p[i], 1);\n    return ans;\n  }\n\n  vector<T> min_25_sieve(const vector<T>&\
    \ Fprime) {\n    if(M == 0) return {};\n    assert((int)Fprime.size() == s);\n\
    \n    vector<i64> ns{0};\n    for (int i = 1; i < s - sq; i++) ns.push_back(quo(M,\
    \ i));\n    for (int i = sq; i > 0; i--) ns.push_back(i);\n\n    vector<T> F =\
    \ Fprime, G = Fprime;\n    for (int j = p.size() - 1; j >= 0; j--) {\n      i64\
    \ P = p[j], pc = P, c = 1;\n      while (quo(M, P) >= pc) {\n        T f_p_c =\
    \ f(P, c), f_p_cp1 = f(P, c + 1);\n        T Fprime_p = Fprime[idx(P)];\n    \
    \    for (int i = 1; i < s; i++) {\n          i64 n = ns[i];\n          if (P\
    \ * pc > n) break;\n          G[i] += f_p_c * (F[idx(quo(n, pc))] - Fprime_p)\
    \ + f_p_cp1;\n        }\n        c++, pc *= P;\n      }\n      copy(begin(G),\
    \ begin(G) + min<int>(s, idx(P * P) + 1), begin(F));\n    }\n    for (int i =\
    \ 1; i < (int)ns.size(); i++) F[i] += 1;\n    return F;\n  }\n\n  i64 quo(i64\
    \ n, i64 d) { return double(n) / d; }\n  i64 idx(i64 n) { return n <= sq ? s -\
    \ n : quo(M, n); }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306E\
    prefix sum\n * @docs docs/multiplicative-function/sum-of-multiplicative-function.quo\n\
    \ */\n"
  dependsOn:
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/sum-of-multiplicative-function.hpp
  requiredBy: []
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/sum-of-mf.test.cpp
  - verify/verify-yuki/yuki-1781.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
documentation_of: multiplicative-function/sum-of-multiplicative-function.hpp
layout: document
redirect_from:
- /library/multiplicative-function/sum-of-multiplicative-function.hpp
- /library/multiplicative-function/sum-of-multiplicative-function.hpp.html
title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum"
---
