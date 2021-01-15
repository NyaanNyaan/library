---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/chromatic-number.md
    document_title: "\u5F69\u8272\u6570"
    links: []
  bundledCode: "#line 2 \"graph/chromatic-number.hpp\"\n\n#include <cstdint>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\nnamespace ChromaticNumberImpl\
    \ {\nusing i64 = int64_t;\ntemplate <uint32_t mod>\nint calc(int n, vector<pair<int,\
    \ int>> hist) {\n  for (int c = 1; c <= n; c++) {\n    i64 sm = 0;\n    for (auto&\
    \ [i, x] : hist) sm += (x = i64(x) * i % mod);\n    if (sm % mod != 0) return\
    \ c;\n  }\n  return n;\n}\n}  // namespace ChromaticNumberImpl\n\ntemplate <typename\
    \ G>\n__attribute__((target(\"avx2\"))) int ChromaticNumber(G& g) {\n  int n =\
    \ g.size();\n  vector<int> adj(n), dp(1 << n);\n  for (int i = 0; i < n; i++)\n\
    \    for (auto& j : g[i]) adj[i] |= 1 << j, adj[j] |= 1 << i;\n  dp[0] = 1;\n\
    \  for (int i = 1; i < (1 << n); i++) {\n    int j = __builtin_ctz(i);\n    int\
    \ k = i & (i - 1);\n    dp[i] = dp[k] + dp[k & ~adj[j]];\n  }\n  vector<int> memo((1\
    \ << n) + 1);\n  for (int i = 0; i < (1 << n); i++)\n    memo[dp[i]] += __builtin_parity(i)\
    \ ? -1 : 1;\n  vector<pair<int, int>> hist;\n  for (int i = 1; i <= (1 << n);\
    \ i++)\n    if (memo[i]) hist.emplace_back(i, memo[i]);\n  return min(ChromaticNumberImpl::calc<1000000021>(n,\
    \ hist),\n             ChromaticNumberImpl::calc<1000000033>(n, hist));\n}\n\n\
    /**\n * @brief \u5F69\u8272\u6570\n * @docs docs/graph/chromatic-number.md\n */\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\nnamespace ChromaticNumberImpl {\nusing i64 = int64_t;\n\
    template <uint32_t mod>\nint calc(int n, vector<pair<int, int>> hist) {\n  for\
    \ (int c = 1; c <= n; c++) {\n    i64 sm = 0;\n    for (auto& [i, x] : hist) sm\
    \ += (x = i64(x) * i % mod);\n    if (sm % mod != 0) return c;\n  }\n  return\
    \ n;\n}\n}  // namespace ChromaticNumberImpl\n\ntemplate <typename G>\n__attribute__((target(\"\
    avx2\"))) int ChromaticNumber(G& g) {\n  int n = g.size();\n  vector<int> adj(n),\
    \ dp(1 << n);\n  for (int i = 0; i < n; i++)\n    for (auto& j : g[i]) adj[i]\
    \ |= 1 << j, adj[j] |= 1 << i;\n  dp[0] = 1;\n  for (int i = 1; i < (1 << n);\
    \ i++) {\n    int j = __builtin_ctz(i);\n    int k = i & (i - 1);\n    dp[i] =\
    \ dp[k] + dp[k & ~adj[j]];\n  }\n  vector<int> memo((1 << n) + 1);\n  for (int\
    \ i = 0; i < (1 << n); i++)\n    memo[dp[i]] += __builtin_parity(i) ? -1 : 1;\n\
    \  vector<pair<int, int>> hist;\n  for (int i = 1; i <= (1 << n); i++)\n    if\
    \ (memo[i]) hist.emplace_back(i, memo[i]);\n  return min(ChromaticNumberImpl::calc<1000000021>(n,\
    \ hist),\n             ChromaticNumberImpl::calc<1000000033>(n, hist));\n}\n\n\
    /**\n * @brief \u5F69\u8272\u6570\n * @docs docs/graph/chromatic-number.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic-number.hpp
  requiredBy: []
  timestamp: '2021-01-15 18:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic-number.hpp
layout: document
redirect_from:
- /library/graph/chromatic-number.hpp
- /library/graph/chromatic-number.hpp.html
title: "\u5F69\u8272\u6570"
---
## 彩色数

頂点数$n$のグラフの彩色数を$\mathrm{O}(2^n n)$で求めるライブラリ。

#### 概要

[wata氏の指数時間アルゴリズムの資料](https://www.slideshare.net/wata_orz/ss-12131479)や[noshi氏のライブラリの解説](https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/chromatic_number.rs)などに詳しい。

$\lbrace1,2,\ldots,m\rbrace$の部分集合からなる集合を$[m]$、実数の集合$R$を$[m]$に対して拡張したものを$R[U_m]$と置き、subset zeta convolutionを$R[U_m]$上の乗法とする。

この時、グラフ$G(V,E),|V|=n$が$k$彩色可能であることは、$d[s]=[s$が独立集合である$]$を満たす$d \in R[U_n]$について$d^k[\lbrace1,2,\ldots,n\rbrace] \neq 0$
であることと同値である。

よって、係数が非零になるまで$d^k$を昇順に計算していけば彩色数が求まる。これは愚直に計算すると$\mathrm{O}(2^n n^2)$だが、必要な係数は一つだけなのでゼータ/メビウス変換を陽に計算する必要はない事実を利用すると計算量を$\mathrm{O}(2^n n)$に改善できる。
