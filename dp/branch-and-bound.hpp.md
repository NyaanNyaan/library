---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-1-f-bandb.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-1-f-bandb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dpl/aoj-dpl-1-h-bandb.test.cpp
    title: verify/verify-aoj-dpl/aoj-dpl-1-h-bandb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/branch-and-bound.hpp\"\n\ntemplate <typename V, typename\
    \ W, typename D = long double>\nstruct BranchAndBound {\n  vector<pair<V, W>>\
    \ c;\n  V best;\n\n  BranchAndBound(const vector<V>& v, const vector<W>& w) {\n\
    \    assert(v.size() == w.size());\n    vector<int> ord(v.size());\n    iota(begin(ord),\
    \ end(ord), 0);\n    sort(begin(ord), end(ord),\n         [&](int i, int j) {\
    \ return D(v[i]) * w[j] > D(v[j]) * w[i]; });\n    for (auto& i : ord) c.emplace_back(v[i],\
    \ w[i]);\n  }\n\n  pair<D, bool> relax(int i, V v, W w) {\n    D ret = v;\n  \
    \  bool f = true;\n    while (i < (int)c.size()) {\n      if (w == 0) break;\n\
    \      if (w >= c[i].second) {\n        w -= c[i].second, ret += c[i].first, ++i;\n\
    \        continue;\n      }\n      f = false, ret += (D(c[i].first) * w) / c[i].second;\n\
    \      break;\n    }\n    return make_pair(ret, f);\n  }\n\n  void dfs(int i,\
    \ V v, W w) {\n    if (i == (int)c.size()) {\n      best = max(v, best);\n   \
    \   return;\n    }\n    auto [rel, flg] = relax(i, v, w);\n    if (flg) {\n  \
    \    best = max(best, V(rel));\n      return;\n    }\n    if (V(rel) < best) return;\n\
    \    if (w >= c[i].second) dfs(i + 1, v + c[i].first, w - c[i].second);\n    dfs(i\
    \ + 1, v, w);\n    return;\n  }\n\n  V run(W w) {\n    dfs(0, best = 0, w);\n\
    \    return best;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename V, typename W, typename D = long double>\n\
    struct BranchAndBound {\n  vector<pair<V, W>> c;\n  V best;\n\n  BranchAndBound(const\
    \ vector<V>& v, const vector<W>& w) {\n    assert(v.size() == w.size());\n   \
    \ vector<int> ord(v.size());\n    iota(begin(ord), end(ord), 0);\n    sort(begin(ord),\
    \ end(ord),\n         [&](int i, int j) { return D(v[i]) * w[j] > D(v[j]) * w[i];\
    \ });\n    for (auto& i : ord) c.emplace_back(v[i], w[i]);\n  }\n\n  pair<D, bool>\
    \ relax(int i, V v, W w) {\n    D ret = v;\n    bool f = true;\n    while (i <\
    \ (int)c.size()) {\n      if (w == 0) break;\n      if (w >= c[i].second) {\n\
    \        w -= c[i].second, ret += c[i].first, ++i;\n        continue;\n      }\n\
    \      f = false, ret += (D(c[i].first) * w) / c[i].second;\n      break;\n  \
    \  }\n    return make_pair(ret, f);\n  }\n\n  void dfs(int i, V v, W w) {\n  \
    \  if (i == (int)c.size()) {\n      best = max(v, best);\n      return;\n    }\n\
    \    auto [rel, flg] = relax(i, v, w);\n    if (flg) {\n      best = max(best,\
    \ V(rel));\n      return;\n    }\n    if (V(rel) < best) return;\n    if (w >=\
    \ c[i].second) dfs(i + 1, v + c[i].first, w - c[i].second);\n    dfs(i + 1, v,\
    \ w);\n    return;\n  }\n\n  V run(W w) {\n    dfs(0, best = 0, w);\n    return\
    \ best;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/branch-and-bound.hpp
  requiredBy: []
  timestamp: '2021-01-24 17:40:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dpl/aoj-dpl-1-h-bandb.test.cpp
  - verify/verify-aoj-dpl/aoj-dpl-1-f-bandb.test.cpp
documentation_of: dp/branch-and-bound.hpp
layout: document
redirect_from:
- /library/dp/branch-and-bound.hpp
- /library/dp/branch-and-bound.hpp.html
title: dp/branch-and-bound.hpp
---
