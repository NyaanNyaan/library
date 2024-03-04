---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/monge-d-edge-shortest-path.hpp
    title: "monge \u30B0\u30E9\u30D5\u4E0A\u306E d-\u8FBA\u6700\u77ED\u8DEF"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0952.test.cpp
    title: verify/verify-yuki/yuki-0952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9EC4\u91D1\u5206\u5272\u63A2\u7D22"
    links:
    - https://twitter.com/noshi91/status/1399003086362865673
  bundledCode: "#line 2 \"dp/golden-section-search.hpp\"\n\n#include <cassert>\n#include\
    \ <functional>\n#include <utility>\nusing namespace std;\n\n// reference\uFF1A\
    https://twitter.com/noshi91/status/1399003086362865673\n\nnamespace golden_section_search_impl\
    \ {\n\nusing i64 = long long;\n\n// [min, max] \u306F\u9589\u533A\u9593\u3092\u5165\
    \u529B\u3059\u308B\ntemplate <typename T, bool get_min = true>\npair<i64, T> golden_section_search(const\
    \ function<T(i64)>& f, i64 min,\n                                   i64 max) {\n\
    \  assert(min <= max);\n  i64 a = min - 1, x, b;\n  {\n    i64 s = 1, t = 2;\n\
    \    while (t < max - min + 2) swap(s += t, t);\n    x = a + t - s, b = a + t;\n\
    \  }\n  T fx = f(x), fy;\n  while (a + b != 2 * x) {\n    i64 y = a + b - x;\n\
    \    if (max < y || (fy = f(y), get_min ? fx < fy : fx > fy)) {\n      b = a;\n\
    \      a = y;\n    } else {\n      a = x;\n      x = y;\n      fx = fy;\n    }\n\
    \  }\n  return {x, fx};\n}\n\n}  // namespace golden_section_search_impl\n\nusing\
    \ golden_section_search_impl::golden_section_search;\n\n/*\n  @brief \u9EC4\u91D1\
    \u5206\u5272\u63A2\u7D22\n*/\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <utility>\n\
    using namespace std;\n\n// reference\uFF1Ahttps://twitter.com/noshi91/status/1399003086362865673\n\
    \nnamespace golden_section_search_impl {\n\nusing i64 = long long;\n\n// [min,\
    \ max] \u306F\u9589\u533A\u9593\u3092\u5165\u529B\u3059\u308B\ntemplate <typename\
    \ T, bool get_min = true>\npair<i64, T> golden_section_search(const function<T(i64)>&\
    \ f, i64 min,\n                                   i64 max) {\n  assert(min <=\
    \ max);\n  i64 a = min - 1, x, b;\n  {\n    i64 s = 1, t = 2;\n    while (t <\
    \ max - min + 2) swap(s += t, t);\n    x = a + t - s, b = a + t;\n  }\n  T fx\
    \ = f(x), fy;\n  while (a + b != 2 * x) {\n    i64 y = a + b - x;\n    if (max\
    \ < y || (fy = f(y), get_min ? fx < fy : fx > fy)) {\n      b = a;\n      a =\
    \ y;\n    } else {\n      a = x;\n      x = y;\n      fx = fy;\n    }\n  }\n \
    \ return {x, fx};\n}\n\n}  // namespace golden_section_search_impl\n\nusing golden_section_search_impl::golden_section_search;\n\
    \n/*\n  @brief \u9EC4\u91D1\u5206\u5272\u63A2\u7D22\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/golden-section-search.hpp
  requiredBy:
  - dp/monge-d-edge-shortest-path.hpp
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0952.test.cpp
documentation_of: dp/golden-section-search.hpp
layout: document
redirect_from:
- /library/dp/golden-section-search.hpp
- /library/dp/golden-section-search.hpp.html
title: "\u9EC4\u91D1\u5206\u5272\u63A2\u7D22"
---
