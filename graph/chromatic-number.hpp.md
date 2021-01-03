---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/chromatic-number.md
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
    /**\n * @brief \u5F69\u8272\u6570\n * @docs docs/chromatic-number.md\n */\n"
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
    /**\n * @brief \u5F69\u8272\u6570\n * @docs docs/chromatic-number.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic-number.hpp
  requiredBy: []
  timestamp: '2021-01-03 23:33:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic-number.hpp
layout: document
redirect_from:
- /library/graph/chromatic-number.hpp
- /library/graph/chromatic-number.hpp.html
title: "\u5F69\u8272\u6570"
---
