---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate-quotient.hpp
    title: "\u5546\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319"
    links:
    - https://codeforces.com/blog/entry/54150
  bundledCode: "#line 2 \"multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\
    \n\n#include <functional>\n#include <unordered_map>\nusing namespace std;\n\n\
    #line 2 \"math/enumerate-quotient.hpp\"\n\n#line 2 \"math/isqrt.hpp\"\n\n#include\
    \ <cmath>\nusing namespace std;\n\n// floor(sqrt(n)) \u3092\u8FD4\u3059 (\u305F\
    \u3060\u3057 n \u304C\u8CA0\u306E\u5834\u5408\u306F 0 \u3092\u8FD4\u3059)\nlong\
    \ long isqrt(long long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n\
    \  while ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n\
    }\n#line 4 \"math/enumerate-quotient.hpp\"\n\nnamespace EnumerateQuotientImpl\
    \ {\nlong long fast_div(long long a, long long b) { return 1.0 * a / b; };\nlong\
    \ long slow_div(long long a, long long b) { return a / b; };\n}  // namespace\
    \ EnumerateQuotientImpl\n\n// { (q, l, r) : forall x in (l,r], floor(N/x) = q\
    \ }\n// \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570f(q, l, r)\u3092\u6E21\
    \u3059\u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\u306E\u306B\u6CE8\
    \u610F\n// \u5546\u306F\u5C0F\u3055\u3044\u65B9\u304B\u3089\u8D70\u67FB\u3059\u308B\
    \ntemplate <typename T, typename F>\nvoid enumerate_quotient(T N, const F& f)\
    \ {\n  T sq = isqrt(N);\n\n#define FUNC(d)                       \\\n  T upper\
    \ = N, quo = 0;               \\\n  while (upper > sq) {                \\\n \
    \   T thres = d(N, (++quo + 1));      \\\n    f(quo, thres, upper);          \
    \   \\\n    upper = thres;                    \\\n  }                        \
    \           \\\n  while (upper > 0) {                 \\\n    f(d(N, upper), upper\
    \ - 1, upper); \\\n    upper--;                          \\\n  }\n\n  if (N <=\
    \ 1e12) {\n    FUNC(EnumerateQuotientImpl::fast_div);\n  } else {\n    FUNC(EnumerateQuotientImpl::slow_div);\n\
    \  }\n#undef FUNC\n}\n\n/**\n *  @brief \u5546\u306E\u5217\u6319\n */\n#line 9\
    \ \"multiplicative-function/enumerate-sum-of-multiplicative-function.hpp\"\n/**\n\
    \ * S(f, n) = f(1) + f(2) + ... + f(n) \u3068\u3059\u308B\n * f \u3068 g \u306E\
    \u30C7\u30A3\u30EA\u30AF\u30EC\u7A4D\u3092 h \u3068\u3059\u308B\n * S(h, n) \u3068\
    \ S(g, n) \u304C\u9AD8\u901F\u306B\u8A08\u7B97\u3067\u304D\u308B, \u304B\u3064\
    \ g(1) = 1 \u306E\u3068\u304D\n * S(f, N/i) \u3092 O(N^{3/4}) \u3067\u5217\u6319\
    \u3067\u304D\u308B\n *\n * \u3046\u307E\u304F\u3084\u308B\u3068 O~(N^{2/3}) \u306B\
    \u843D\u3061\u305F\u308A g(1) != 1 \u306B\u5BFE\u5FDC\u3067\u304D\u308B\n * https://codeforces.com/blog/entry/54150\n\
    \ */\ntemplate <typename T, typename SG, typename SH>\nstruct enumerate_mf_prefix_sum\
    \ {\n  long long N, sq;\n  const SG sg;\n  const SH sh;\n  vector<T> small, large;\n\
    \  T& ref(long long x) {\n    if (x <= sq) {\n      return small[x];\n    } else\
    \ if (N <= 1000000000000LL) {\n      return large[1.0 * N / x];\n    } else {\n\
    \      return large[N / x];\n    }\n  }\n  enumerate_mf_prefix_sum(long long _n,\
    \ SG _sg, SH _sh)\n      : N(_n), sq(isqrt(N)), sg(_sg), sh(_sh) {\n    small.resize(sq\
    \ + 1);\n    large.resize(sq + 1);\n    enumerate_quotient(N, [&](long long n,\
    \ long long, long long) {\n      T& cur = (ref(n) = sh(n));\n      enumerate_quotient(n,\
    \ [&](long long q, long long l, long long r) {\n        if (q != n) cur -= ref(q)\
    \ * (sg(r) - sg(l));\n      });\n    });\n  }\n  T get(long long n) { return ref(n);\
    \ }\n  T operator()(long long n) { return get(n); }\n};\n\n/**\n * @brief \u4E57\
    \u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <unordered_map>\nusing namespace\
    \ std;\n\n#include \"../math/enumerate-quotient.hpp\"\n#include \"../math/isqrt.hpp\"\
    \n/**\n * S(f, n) = f(1) + f(2) + ... + f(n) \u3068\u3059\u308B\n * f \u3068 g\
    \ \u306E\u30C7\u30A3\u30EA\u30AF\u30EC\u7A4D\u3092 h \u3068\u3059\u308B\n * S(h,\
    \ n) \u3068 S(g, n) \u304C\u9AD8\u901F\u306B\u8A08\u7B97\u3067\u304D\u308B, \u304B\
    \u3064 g(1) = 1 \u306E\u3068\u304D\n * S(f, N/i) \u3092 O(N^{3/4}) \u3067\u5217\
    \u6319\u3067\u304D\u308B\n *\n * \u3046\u307E\u304F\u3084\u308B\u3068 O~(N^{2/3})\
    \ \u306B\u843D\u3061\u305F\u308A g(1) != 1 \u306B\u5BFE\u5FDC\u3067\u304D\u308B\
    \n * https://codeforces.com/blog/entry/54150\n */\ntemplate <typename T, typename\
    \ SG, typename SH>\nstruct enumerate_mf_prefix_sum {\n  long long N, sq;\n  const\
    \ SG sg;\n  const SH sh;\n  vector<T> small, large;\n  T& ref(long long x) {\n\
    \    if (x <= sq) {\n      return small[x];\n    } else if (N <= 1000000000000LL)\
    \ {\n      return large[1.0 * N / x];\n    } else {\n      return large[N / x];\n\
    \    }\n  }\n  enumerate_mf_prefix_sum(long long _n, SG _sg, SH _sh)\n      :\
    \ N(_n), sq(isqrt(N)), sg(_sg), sh(_sh) {\n    small.resize(sq + 1);\n    large.resize(sq\
    \ + 1);\n    enumerate_quotient(N, [&](long long n, long long, long long) {\n\
    \      T& cur = (ref(n) = sh(n));\n      enumerate_quotient(n, [&](long long q,\
    \ long long l, long long r) {\n        if (q != n) cur -= ref(q) * (sg(r) - sg(l));\n\
    \      });\n    });\n  }\n  T get(long long n) { return ref(n); }\n  T operator()(long\
    \ long n) { return get(n); }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\
    \u306Eprefix sum \u306E\u5217\u6319\n */\n"
  dependsOn:
  - math/enumerate-quotient.hpp
  - math/isqrt.hpp
  isVerificationFile: false
  path: multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
  requiredBy: []
  timestamp: '2023-04-10 23:43:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2266.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
documentation_of: multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
layout: document
redirect_from:
- /library/multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
- /library/multiplicative-function/enumerate-sum-of-multiplicative-function.hpp.html
title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319"
---
