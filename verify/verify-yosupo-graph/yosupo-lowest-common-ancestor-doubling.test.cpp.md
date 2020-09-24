---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/doubling.hpp
    title: "Binary Lifting(\u30C0\u30D6\u30EA\u30F3\u30B0)"
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"misc/doubling.hpp\"\nusing namespace std;\n\n\
    template <typename T>\nstruct BinaryLifting {\n  using Data = pair<int, T>;\n\n\
    \  const int N, LOG;\n  vector<vector<Data>> table;\n  T I;\n\n  BinaryLifting(int\
    \ n, int64_t lim, const T I_ = T())\n      : N(n), LOG(__lg(lim) + 2), I(I_) {\n\
    \    table.resize(n, vector<Data>(LOG, Data(-1, I)));\n  }\n\n  void set_next(int\
    \ k, int nxt, const T& t) { table[k][0] = Data(nxt, t); }\n\n  void build() {\n\
    \    for (int k = 0; k + 1 < LOG; ++k)\n      for (int i = 0; i < N; ++i) {\n\
    \        int pre = table[i][k].first;\n        if (pre == -1) {\n          table[i][k\
    \ + 1] = table[i][k];\n        } else {\n          table[i][k + 1].first = table[pre][k].first;\n\
    \          table[i][k + 1].second = table[i][k].second + table[pre][k].second;\n\
    \        }\n      }\n  }\n\n  // from i, move t times\n  Data query(int i, int64_t\
    \ t) const {\n    T d = I;\n    for (int k = LOG - 1; k >= 0; k--) {\n      if\
    \ ((t >> k) & 1) {\n        d = d + table[i][k].second;\n        i = table[i][k].first;\n\
    \      }\n      if (i == -1) break;\n    }\n    return Data(i, d);\n  }\n\n  //\
    \ query(i, pow(2, k))\n  inline Data query_pow(int i, int k) const { return table[i][k];\
    \ }\n\n  // assuming graph is DAG ( edge(u, v) <-> u < v )\n  // find max j |\
    \ j <= t, path from i to j exists\n  inline Data binary_search(int i, int t) {\n\
    \    int thres = i;\n    T d = I;\n    for (int k = LOG - 1; k >= 0; k--) {\n\
    \      int nxt = table[thres][k].first;\n      if(nxt != -1 && nxt <= t) {\n \
    \       d = d + table[thres][k].second;\n        thres = nxt;\n      }\n    }\n\
    \    return Data(thres, d);\n  }\n};\n\ntemplate <typename T>\nusing Doubling\
    \ = BinaryLifting<T>;\n\n/**\n * @brief Binary Lifting(\u30C0\u30D6\u30EA\u30F3\
    \u30B0)\n * @docs docs/misc/doubling.md\n */\n#line 3 \"misc/fastio.hpp\"\nusing\
    \ namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar\
    \ ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char\
    \ num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++)\
    \ {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4\
    \ + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\
    \ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir -\
    \ pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline\
    \ void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void\
    \ rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x)\
    \ {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while\
    \ (c < '-');\n  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x\
    \ < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n\
    \      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x)\
    \ - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n\
    \      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf +\
    \ por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 8 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n\nint main() {\n  int N, Q;\n  rd(N, Q);\n  Doubling<int> db(N, N, 0);\n  for\
    \ (int i = 1; i < N; i++) {\n    int p;\n    rd(p);\n    db.set_next(i, p, 1);\n\
    \  }\n  db.build();\n\n  while (Q--) {\n    int u, v;\n    rd(u, v);\n    int\
    \ du = db.query_pow(u, db.LOG - 1).second;\n    int dv = db.query_pow(v, db.LOG\
    \ - 1).second;\n    if (du > dv) swap(u, v), swap(du, dv);\n    int t = dv - du;\n\
    \    for (int k = 0; t; k++) {\n      if ((t >> k) & 1) {\n        v = db.query_pow(v,\
    \ k).first;\n        t ^= (1 << k);\n      }\n    }\n    if (u != v) {\n     \
    \ for (int k = db.LOG - 1; k >= 0; --k) {\n        int pu = db.query_pow(u, k).first;\n\
    \        int pv = db.query_pow(v, k).first;\n        if (pu != pv) u = pu, v =\
    \ pv;\n      }\n      u = db.query_pow(u, 0).first;\n    }\n    wtn(u);\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../misc/doubling.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n\nint main() {\n  int N, Q;\n  rd(N, Q);\n  Doubling<int> db(N, N, 0);\n  for\
    \ (int i = 1; i < N; i++) {\n    int p;\n    rd(p);\n    db.set_next(i, p, 1);\n\
    \  }\n  db.build();\n\n  while (Q--) {\n    int u, v;\n    rd(u, v);\n    int\
    \ du = db.query_pow(u, db.LOG - 1).second;\n    int dv = db.query_pow(v, db.LOG\
    \ - 1).second;\n    if (du > dv) swap(u, v), swap(du, dv);\n    int t = dv - du;\n\
    \    for (int k = 0; t; k++) {\n      if ((t >> k) & 1) {\n        v = db.query_pow(v,\
    \ k).first;\n        t ^= (1 << k);\n      }\n    }\n    if (u != v) {\n     \
    \ for (int k = db.LOG - 1; k >= 0; --k) {\n        int pu = db.query_pow(u, k).first;\n\
    \        int pv = db.query_pow(v, k).first;\n        if (pu != pv) u = pu, v =\
    \ pv;\n      }\n      u = db.query_pow(u, 0).first;\n    }\n    wtn(u);\n  }\n\
    }"
  dependsOn:
  - misc/doubling.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 00:54:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
---
