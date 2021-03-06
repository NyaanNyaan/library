---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/misc/doubling.md
    document_title: "Binary Lifting(\u30C0\u30D6\u30EA\u30F3\u30B0)"
    links: []
  bundledCode: "#line 2 \"misc/doubling.hpp\"\n\n\n\ntemplate <typename T>\nstruct\
    \ BinaryLifting {\n  using Data = pair<int, T>;\n\n  const int N, LOG;\n  vector<vector<Data>>\
    \ table;\n  T I;\n\n  BinaryLifting(int n, uint64_t lim, const T I_ = T())\n \
    \     : N(n), LOG(__lg(lim) + 2), I(I_) {\n    table.resize(n, vector<Data>(LOG,\
    \ Data(-1, I)));\n  }\n\n  void set_next(int k, int nxt, const T& t) { table[k][0]\
    \ = Data(nxt, t); }\n\n  void build() {\n    for (int k = 0; k + 1 < LOG; ++k)\n\
    \      for (int i = 0; i < N; ++i) {\n        int pre = table[i][k].first;\n \
    \       if (pre == -1) {\n          table[i][k + 1] = table[i][k];\n        }\
    \ else {\n          table[i][k + 1].first = table[pre][k].first;\n          table[i][k\
    \ + 1].second = table[i][k].second + table[pre][k].second;\n        }\n      }\n\
    \  }\n\n  // from i, move t times\n  Data query(int i, uint64_t t) const {\n \
    \   T d = I;\n    for (int k = LOG - 1; k >= 0; k--) {\n      if ((t >> k) & 1)\
    \ {\n        d = d + table[i][k].second;\n        i = table[i][k].first;\n   \
    \   }\n      if (i == -1) break;\n    }\n    return Data(i, d);\n  }\n\n  // query(i,\
    \ pow(2, k))\n  inline Data query_pow(int i, int k) const { return table[i][k];\
    \ }\n\n  // assuming graph is DAG ( edge(u, v) <-> u < v )\n  // find max j |\
    \ j <= t, path from i to j exists\n  inline pair<uint64_t, Data> binary_search(int\
    \ i, int t) {\n    int thres = i;\n    T d = I;\n    uint64_t times = 0;\n   \
    \ for (int k = LOG - 1; k >= 0; k--) {\n      int nxt = table[thres][k].first;\n\
    \      if (nxt != -1 && nxt <= t) {\n        d = d + table[thres][k].second;\n\
    \        thres = nxt;\n        times += 1LL << k;\n      }\n    }\n    return\
    \ make_pair(times, Data(thres, d));\n  }\n};\n\ntemplate <typename T>\nusing Doubling\
    \ = BinaryLifting<T>;\n\n/**\n * @brief Binary Lifting(\u30C0\u30D6\u30EA\u30F3\
    \u30B0)\n * @docs docs/misc/doubling.md\n */\n"
  code: "#pragma once\n\n\n\ntemplate <typename T>\nstruct BinaryLifting {\n  using\
    \ Data = pair<int, T>;\n\n  const int N, LOG;\n  vector<vector<Data>> table;\n\
    \  T I;\n\n  BinaryLifting(int n, uint64_t lim, const T I_ = T())\n      : N(n),\
    \ LOG(__lg(lim) + 2), I(I_) {\n    table.resize(n, vector<Data>(LOG, Data(-1,\
    \ I)));\n  }\n\n  void set_next(int k, int nxt, const T& t) { table[k][0] = Data(nxt,\
    \ t); }\n\n  void build() {\n    for (int k = 0; k + 1 < LOG; ++k)\n      for\
    \ (int i = 0; i < N; ++i) {\n        int pre = table[i][k].first;\n        if\
    \ (pre == -1) {\n          table[i][k + 1] = table[i][k];\n        } else {\n\
    \          table[i][k + 1].first = table[pre][k].first;\n          table[i][k\
    \ + 1].second = table[i][k].second + table[pre][k].second;\n        }\n      }\n\
    \  }\n\n  // from i, move t times\n  Data query(int i, uint64_t t) const {\n \
    \   T d = I;\n    for (int k = LOG - 1; k >= 0; k--) {\n      if ((t >> k) & 1)\
    \ {\n        d = d + table[i][k].second;\n        i = table[i][k].first;\n   \
    \   }\n      if (i == -1) break;\n    }\n    return Data(i, d);\n  }\n\n  // query(i,\
    \ pow(2, k))\n  inline Data query_pow(int i, int k) const { return table[i][k];\
    \ }\n\n  // assuming graph is DAG ( edge(u, v) <-> u < v )\n  // find max j |\
    \ j <= t, path from i to j exists\n  inline pair<uint64_t, Data> binary_search(int\
    \ i, int t) {\n    int thres = i;\n    T d = I;\n    uint64_t times = 0;\n   \
    \ for (int k = LOG - 1; k >= 0; k--) {\n      int nxt = table[thres][k].first;\n\
    \      if (nxt != -1 && nxt <= t) {\n        d = d + table[thres][k].second;\n\
    \        thres = nxt;\n        times += 1LL << k;\n      }\n    }\n    return\
    \ make_pair(times, Data(thres, d));\n  }\n};\n\ntemplate <typename T>\nusing Doubling\
    \ = BinaryLifting<T>;\n\n/**\n * @brief Binary Lifting(\u30C0\u30D6\u30EA\u30F3\
    \u30B0)\n * @docs docs/misc/doubling.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/doubling.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
documentation_of: misc/doubling.hpp
layout: document
redirect_from:
- /library/misc/doubling.hpp
- /library/misc/doubling.hpp.html
title: "Binary Lifting(\u30C0\u30D6\u30EA\u30F3\u30B0)"
---
## Binary Lifting(ダブリング)

辺の重みがモノイドであり、各頂点の出次数が高々1のグラフが存在したとき、$i$を始点として$t$回グラフを移動したときの終点$j$とパス$(i,j)$の重みの和を前計算$\mathrm{O}(N \log \max(t))$、クエリ$\mathrm{O}(\log t)$計算するライブラリ。

TODO: 書く　[わかりやすい解説](https://ei1333.github.io/luzhiled/snippets/memo/doubling.html)

#### 使い方

- `template<typename T> BinaryLifting(k, lim, I)`　$\cdots$　コンストラクタ。
  - `T`は`operator +`が定義されているモノイド
  - `k`はグラフの頂点数
  - `lim`は移動回数の最大値
  - `I`はモノイドの単位元
- `set_next(k, nxt, t)`　$\cdots$　$k$から$nxt$に重み$t$の辺を貼る。
- `build()` $\cdots$ データ構造を構築する。
- `query(i, t)` $\cdots$ $i$を始点として$t$回移動したときの(遷移先,始点と終点の間のパスの重みの和)を返す。遷移先が存在しない場合は($-1$, 最後に到達した点までのパスの重みの和)を返す。
