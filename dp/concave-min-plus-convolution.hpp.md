---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/monotone-minima.hpp
    title: monotone minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/concave-min-plus-convolution.hpp\"\n\n#include <vector>\n\
    using namespace std;\n\n#line 2 \"dp/monotone-minima.hpp\"\n\n#include <functional>\n\
    #line 5 \"dp/monotone-minima.hpp\"\nusing namespace std;\n\n// NxN \u884C\u5217\
    \u304C\u3042\u308B\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\n// f(i,\
    \ j, k) :\n// A[i][j] \u3068 A[i][k] \u3092\u6BD4\u8F03 (j < k \u304C\u4FDD\u8A3C\
    \u3055\u308C\u3066\u3044\u308B)\n// A[i][j] <= A[i][k] \u306E\u3068\u304D true\
    \ \u3092\u8FD4\u3059\u95A2\u6570\u3092\u5165\u308C\u308B (\u7B49\u53F7\u306F\u3069\
    \u3061\u3089\u3067\u3082\u3088\u3044)\nvector<int> monotone_minima(int N, int\
    \ M,\n                            const function<bool(int, int, int)>& f) {\n\
    \  vector<int> res(N);\n  auto dfs = [&](auto rc, int is, int ie, int l, int r)\
    \ -> void {\n    if (is == ie) return;\n    int i = (is + ie) / 2;\n    int m\
    \ = l;\n    for (int k = l + 1; k < r; k++) {\n      if (!f(i, m, k)) m = k;\n\
    \    }\n    res[i] = m;\n    rc(rc, is, i, l, m + 1);\n    rc(rc, i + 1, ie, m,\
    \ r);\n  };\n  dfs(dfs, 0, N, 0, M);\n  return res;\n}\n\n// NxM \u884C\u5217\u304C\
    \u3042\u308B\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\u3067\
    \u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\n// A(i, j)\
    \ : A[i][j] \u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T>\nvector<int>\
    \ monotone_minima(int N, int M, const function<T(int, int)>& A) {\n  function<bool(int,\
    \ int, int)> f = [&](int i, int j, int k) -> bool {\n    return A(i, j) <= A(i,\
    \ k);\n  };\n  return monotone_minima(N, M, f);\n}\n\n/**\n * @brief monotone\
    \ minima\n */\n#line 7 \"dp/concave-min-plus-convolution.hpp\"\n\n// a \u306F\u4E0B\
    \u306B\u51F8, b \u306F\u81EA\u7531\ntemplate <typename T>\nvector<T> concave_min_plus_convolution(const\
    \ vector<T>& a, const vector<T>& b) {\n  int n = a.size(), m = b.size();\n  auto\
    \ argmin = monotone_minima(n + m - 1, m, [&](int i, int j, int k) {\n    if (i\
    \ < k) return true;\n    if (i - j >= n) return false;\n    return a[i - j] +\
    \ b[j] <= a[i - k] + b[k];\n  });\n  vector<T> ans(n + m - 1);\n  for (int i =\
    \ 0; i < n + m - 1; i++) {\n    int j = argmin[i];\n    ans[i] = a[i - j] + b[j];\n\
    \  }\n  return ans;\n}\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\n#include \"monotone-minima.hpp\"\
    \n\n// a \u306F\u4E0B\u306B\u51F8, b \u306F\u81EA\u7531\ntemplate <typename T>\n\
    vector<T> concave_min_plus_convolution(const vector<T>& a, const vector<T>& b)\
    \ {\n  int n = a.size(), m = b.size();\n  auto argmin = monotone_minima(n + m\
    \ - 1, m, [&](int i, int j, int k) {\n    if (i < k) return true;\n    if (i -\
    \ j >= n) return false;\n    return a[i - j] + b[j] <= a[i - k] + b[k];\n  });\n\
    \  vector<T> ans(n + m - 1);\n  for (int i = 0; i < n + m - 1; i++) {\n    int\
    \ j = argmin[i];\n    ans[i] = a[i - j] + b[j];\n  }\n  return ans;\n}\n"
  dependsOn:
  - dp/monotone-minima.hpp
  isVerificationFile: false
  path: dp/concave-min-plus-convolution.hpp
  requiredBy: []
  timestamp: '2023-09-05 21:46:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-2.test.cpp
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-1.test.cpp
documentation_of: dp/concave-min-plus-convolution.hpp
layout: document
redirect_from:
- /library/dp/concave-min-plus-convolution.hpp
- /library/dp/concave-min-plus-convolution.hpp.html
title: dp/concave-min-plus-convolution.hpp
---
