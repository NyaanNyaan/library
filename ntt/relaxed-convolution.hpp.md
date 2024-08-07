---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/relaxed-convolution.test.cpp
    title: verify/verify-unit-test/relaxed-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp-relaxed-convolution.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp-relaxed-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-relaxed-convolution.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-relaxed-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-relaxed-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-relaxed-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Relaxed Convolution
    links: []
  bundledCode: "#line 2 \"ntt/relaxed-convolution.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n\n// x^0, x^1, ..., x^N \u3092\u30AA\u30F3\
    \u30E9\u30A4\u30F3\u3067\u8A08\u7B97\u3059\u308B\n// x^{n-1} \u307E\u3067\u3092\
    \u78BA\u5B9A\u3055\u305B\u305F\u6642\u70B9\u3067, c[n] \u306B\u306F a_0 b_n \u3068\
    \n// a_n b_0 \u4EE5\u5916\u306E\u5BC4\u4E0E\u306E\u548C\u304C\u5165\u3063\u3066\
    \u3044\u308B\u306E\u3067, \u305D\u308C\u3092\u5229\u7528\u3059\u308B\u3053\u3068\
    \u3082\u3067\u304D\u308B\ntemplate <typename fps>\nstruct RelaxedConvolution {\n\
    \  using mint = typename fps::value_type;\n  int N, q;\n  vector<mint> a, b, c;\n\
    \  fps f, g;\n  vector<fps> as, bs;\n\n  RelaxedConvolution(int _n) : N(_n), q(0)\
    \ {\n    a.resize(N + 1), b.resize(N + 1), c.resize(N + 1);\n  }\n\n  // a[q]\
    \ = x, b[q] = y \u3067\u3042\u308B\u3068\u304D c[q] \u3092 get\n  mint get(mint\
    \ x, mint y) {\n    assert(q <= N);\n    a[q] = x, b[q] = y;\n    c[q] += a[q]\
    \ * b[0] + (q ? b[q] * a[0] : 0);\n\n    auto precalc = [&](int lg) {\n      if\
    \ ((int)as.size() <= lg) as.resize(lg + 1), bs.resize(lg + 1);\n      if (!as[lg].empty())\
    \ return;\n      int d = 1 << lg;\n      fps s{begin(a), begin(a) + d * 2};\n\
    \      fps t{begin(b), begin(b) + d * 2};\n      s.ntt(), t.ntt();\n      as[lg]\
    \ = s, bs[lg] = t;\n    };\n\n    q++;\n    if (q > N) return c[q - 1];\n    for\
    \ (int d = 1, lg = 0; d <= q; d *= 2, lg++) {\n      if (q % (2 * d) != d) continue;\n\
    \      if (q == d) {\n        f.assign(2 * d, mint{});\n        g.assign(2 * d,\
    \ mint{});\n        for (int i = 0; i < d; i++) f[i] = a[i];\n        for (int\
    \ i = 0; i < d; i++) g[i] = b[i];\n        f.ntt(), g.ntt();\n        for (int\
    \ i = 0; i < d * 2; i++) f[i] *= g[i];\n        f.intt();\n        for (int i\
    \ = q; i < min(q + d, N + 1); i++) c[i] += f[d + i - q];\n      } else {\n   \
    \     precalc(lg);\n        f.assign(2 * d, mint{});\n        g.assign(2 * d,\
    \ mint{});\n        for (int i = 0; i < d; i++) f[i] = a[q - d + i];\n       \
    \ for (int i = 0; i < d; i++) g[i] = b[q - d + i];\n        f.ntt(), g.ntt();\n\
    \        fps& s = as[lg];\n        fps& t = bs[lg];\n        for (int i = 0; i\
    \ < d * 2; i++) f[i] = f[i] * t[i] + g[i] * s[i];\n        f.intt();\n       \
    \ for (int i = q; i < min(q + d, N + 1); i++) c[i] += f[d + i - q];\n      }\n\
    \    }\n    return c[q - 1];\n  }\n};\n\n/**\n * @brief Relaxed Convolution\n\
    \ */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\nusing namespace\
    \ std;\n\n// x^0, x^1, ..., x^N \u3092\u30AA\u30F3\u30E9\u30A4\u30F3\u3067\u8A08\
    \u7B97\u3059\u308B\n// x^{n-1} \u307E\u3067\u3092\u78BA\u5B9A\u3055\u305B\u305F\
    \u6642\u70B9\u3067, c[n] \u306B\u306F a_0 b_n \u3068\n// a_n b_0 \u4EE5\u5916\u306E\
    \u5BC4\u4E0E\u306E\u548C\u304C\u5165\u3063\u3066\u3044\u308B\u306E\u3067, \u305D\
    \u308C\u3092\u5229\u7528\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B\ntemplate\
    \ <typename fps>\nstruct RelaxedConvolution {\n  using mint = typename fps::value_type;\n\
    \  int N, q;\n  vector<mint> a, b, c;\n  fps f, g;\n  vector<fps> as, bs;\n\n\
    \  RelaxedConvolution(int _n) : N(_n), q(0) {\n    a.resize(N + 1), b.resize(N\
    \ + 1), c.resize(N + 1);\n  }\n\n  // a[q] = x, b[q] = y \u3067\u3042\u308B\u3068\
    \u304D c[q] \u3092 get\n  mint get(mint x, mint y) {\n    assert(q <= N);\n  \
    \  a[q] = x, b[q] = y;\n    c[q] += a[q] * b[0] + (q ? b[q] * a[0] : 0);\n\n \
    \   auto precalc = [&](int lg) {\n      if ((int)as.size() <= lg) as.resize(lg\
    \ + 1), bs.resize(lg + 1);\n      if (!as[lg].empty()) return;\n      int d =\
    \ 1 << lg;\n      fps s{begin(a), begin(a) + d * 2};\n      fps t{begin(b), begin(b)\
    \ + d * 2};\n      s.ntt(), t.ntt();\n      as[lg] = s, bs[lg] = t;\n    };\n\n\
    \    q++;\n    if (q > N) return c[q - 1];\n    for (int d = 1, lg = 0; d <= q;\
    \ d *= 2, lg++) {\n      if (q % (2 * d) != d) continue;\n      if (q == d) {\n\
    \        f.assign(2 * d, mint{});\n        g.assign(2 * d, mint{});\n        for\
    \ (int i = 0; i < d; i++) f[i] = a[i];\n        for (int i = 0; i < d; i++) g[i]\
    \ = b[i];\n        f.ntt(), g.ntt();\n        for (int i = 0; i < d * 2; i++)\
    \ f[i] *= g[i];\n        f.intt();\n        for (int i = q; i < min(q + d, N +\
    \ 1); i++) c[i] += f[d + i - q];\n      } else {\n        precalc(lg);\n     \
    \   f.assign(2 * d, mint{});\n        g.assign(2 * d, mint{});\n        for (int\
    \ i = 0; i < d; i++) f[i] = a[q - d + i];\n        for (int i = 0; i < d; i++)\
    \ g[i] = b[q - d + i];\n        f.ntt(), g.ntt();\n        fps& s = as[lg];\n\
    \        fps& t = bs[lg];\n        for (int i = 0; i < d * 2; i++) f[i] = f[i]\
    \ * t[i] + g[i] * s[i];\n        f.intt();\n        for (int i = q; i < min(q\
    \ + d, N + 1); i++) c[i] += f[d + i - q];\n      }\n    }\n    return c[q - 1];\n\
    \  }\n};\n\n/**\n * @brief Relaxed Convolution\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/relaxed-convolution.hpp
  requiredBy: []
  timestamp: '2023-04-15 00:09:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-relaxed-convolution.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-relaxed-convolution.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-relaxed-convolution.test.cpp
  - verify/verify-unit-test/relaxed-convolution.test.cpp
documentation_of: ntt/relaxed-convolution.hpp
layout: document
redirect_from:
- /library/ntt/relaxed-convolution.hpp
- /library/ntt/relaxed-convolution.hpp.html
title: Relaxed Convolution
---
