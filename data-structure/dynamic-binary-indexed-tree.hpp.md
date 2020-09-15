---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-binary-indexed-tree.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n// idx_t\u306Flong long\u307E\u3067\
    \u3092\u60F3\u5B9A\ntemplate <typename idx_t, typename data_t>\nstruct DynamicFenwickTree\
    \ {\n  idx_t N;\n  unordered_map<idx_t, data_t> data;\n  DynamicFenwickTree(idx_t\
    \ size) { N = size += 3; }\n\n  // i\u306Bx\u3092\u52A0\u7B97\n  void add(idx_t\
    \ k, data_t x) {\n    for (k++; k < N; k += k & -k) data[k] += x;\n  }\n\n  //\
    \ [0,i]\u306Esum\n  data_t sum(idx_t k) {\n    if (k < 0) return 0;\n    data_t\
    \ ret = 0;\n    for (k++; k > 0; k -= k & -k) ret += data[k];\n    return ret;\n\
    \  }\n\n  // [a,b]\u306Esum\n  data_t sum(idx_t a, idx_t b) { return sum(b) -\
    \ sum(a - 1); }\n\n   // get value of k\n  data_t operator[](idx_t k) { return\
    \ sum(k) - sum(k - 1); }\n\n  idx_t lower_bound(data_t w) {\n    if (w <= 0) return\
    \ 0;\n    idx_t x = 0;\n    for (idx_t k = 1 << (63 - __builtin_clzll((long long)(x)));\
    \ k > 0; k /= 2) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w\
    \ -= data[x + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  void\
    \ merge(DynamicFenwickTree<idx_t, data_t>& other) {\n    if (data.size() < other.data.size())\
    \ data.swap(other.data);\n    for (auto& x : other.data) data[x.fi] += x.se;\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// idx_t\u306F\
    long long\u307E\u3067\u3092\u60F3\u5B9A\ntemplate <typename idx_t, typename data_t>\n\
    struct DynamicFenwickTree {\n  idx_t N;\n  unordered_map<idx_t, data_t> data;\n\
    \  DynamicFenwickTree(idx_t size) { N = size += 3; }\n\n  // i\u306Bx\u3092\u52A0\
    \u7B97\n  void add(idx_t k, data_t x) {\n    for (k++; k < N; k += k & -k) data[k]\
    \ += x;\n  }\n\n  // [0,i]\u306Esum\n  data_t sum(idx_t k) {\n    if (k < 0) return\
    \ 0;\n    data_t ret = 0;\n    for (k++; k > 0; k -= k & -k) ret += data[k];\n\
    \    return ret;\n  }\n\n  // [a,b]\u306Esum\n  data_t sum(idx_t a, idx_t b) {\
    \ return sum(b) - sum(a - 1); }\n\n   // get value of k\n  data_t operator[](idx_t\
    \ k) { return sum(k) - sum(k - 1); }\n\n  idx_t lower_bound(data_t w) {\n    if\
    \ (w <= 0) return 0;\n    idx_t x = 0;\n    for (idx_t k = 1 << (63 - __builtin_clzll((long\
    \ long)(x))); k > 0; k /= 2) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n\
    \        w -= data[x + k];\n        x += k;\n      }\n    }\n    return x;\n \
    \ }\n\n  void merge(DynamicFenwickTree<idx_t, data_t>& other) {\n    if (data.size()\
    \ < other.data.size()) data.swap(other.data);\n    for (auto& x : other.data)\
    \ data[x.fi] += x.se;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic-binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-binary-indexed-tree.hpp
- /library/data-structure/dynamic-binary-indexed-tree.hpp.html
title: data-structure/dynamic-binary-indexed-tree.hpp
---
