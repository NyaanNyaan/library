---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp
    title: verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-inliner-multiply.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-inliner-multiply.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-swag.test.cpp
    title: verify/verify-yosupo-ds/yosupo-swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
    title: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
    title: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factrization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factrization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
    title: verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
    title: verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
    title: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
    title: verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"misc/fastio.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ],\
    \ obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10\
    \ + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void\
    \ load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush()\
    \ {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c)\
    \ { c = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil\
    \ + 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  int\
    \ d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);\n  memcpy(obuf + por, pre.num\
    \ + x * 4 + 4 - d, d);\n  por += d;\n  memcpy(obuf + por, buf + i + 4, 12 - i);\n\
    \  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void wt(Head head, Tail... tail) {\n  wt(head);\n  wt(tail...);\n\
    }\ntemplate<typename T>\ninline void wtn(T x){\n  wt(x, '\\n');\n}\n\nstruct Dummy\
    \ {\n  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::wt;\nusing fastio::wtn;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint\
    \ pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void load()\
    \ {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf +\
    \ pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush() {\n\
    \  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c) { c\
    \ = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil +\
    \ 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  int\
    \ d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);\n  memcpy(obuf + por, pre.num\
    \ + x * 4 + 4 - d, d);\n  por += d;\n  memcpy(obuf + por, buf + i + 4, 12 - i);\n\
    \  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void wt(Head head, Tail... tail) {\n  wt(head);\n  wt(tail...);\n\
    }\ntemplate<typename T>\ninline void wtn(T x){\n  wt(x, '\\n');\n}\n\nstruct Dummy\
    \ {\n  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::wt;\nusing fastio::wtn;"
  dependsOn: []
  isVerificationFile: false
  path: misc/fastio.hpp
  requiredBy: []
  timestamp: '2020-08-09 17:31:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-other/yosupo-many-a-plus-b.test.cpp
  - verify/verify-yosupo-ntt/yosupo-inliner-multiply.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  - verify/verify-yosupo-ds/yosupo-swag.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  - verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-prime-table.test.cpp
  - verify/verify-yosupo-math/yosupo-factrization.test.cpp
  - verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
  - verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp
  - verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp
  - verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - verify/verify-yosupo-fps/yosupo-linear-recurrence.test.cpp
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
documentation_of: misc/fastio.hpp
layout: document
redirect_from:
- /library/misc/fastio.hpp
- /library/misc/fastio.hpp.html
title: misc/fastio.hpp
---
