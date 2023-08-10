---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-compositional-inverse-newton.test.cpp
    title: verify/verify-yosupo-fps/yosupo-compositional-inverse-newton.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp-newton-method-2.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp-newton-method-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp-newton-method.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp-newton-method.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-newton-method.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-newton-method.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5"
    links: []
  bundledCode: "#line 2 \"fps/newton-method.hpp\"\n\n#include <functional>\nusing\
    \ namespace std;\n\n// G(f) = 0 mod x^{deg} \u3092\u6E80\u305F\u3059 f \u3092\u8FD4\
    \u3059\n// f0 : \u521D\u671F\u89E3, \u975E\u7A7A\u306A fps \u304B mint \u3092\u5165\
    \u308C\u308B\n// g : (g(f), g'(f)) \u3092\u8FD4\u3059\ntemplate <typename fps>\n\
    fps newton_method(function<pair<fps, fps>(fps, int)> calc_g, fps f0, int deg)\
    \ {\n  assert(!f0.empty());\n  fps f{f0};\n  for (int d = f.size(); d < deg; d\
    \ *= 2) {\n    // \u5C11\u3057\u591A\u3081\u306B\u8A08\u7B97\u3057\u3066\u304A\
    \u304F\n    const int extra = d + 10;\n    auto [g, dgdf] = calc_g(f, d * 2 +\
    \ extra);\n    int offset = 0;\n    while (offset < (int)dgdf.size() && dgdf[offset]\
    \ == 0) offset++;\n    assert(offset <= extra);\n    dgdf = dgdf >> offset;\n\
    \    g = g >> offset;\n    f = (f - g * dgdf.inv()).pre(d * 2);\n  }\n  return\
    \ f.pre(deg);\n}\n// G(f) = 0 mod x^{deg} \u3092\u6E80\u305F\u3059 f \u3092\u8FD4\
    \u3059\n// f0 : \u521D\u671F\u89E3, \u975E\u7A7A\u306A fps \u304B mint \u3092\u5165\
    \u308C\u308B\n// g : (g(f), g'(f)) \u3092\u8FD4\u3059\ntemplate <typename fps>\n\
    fps newton_method(function<pair<fps, fps>(fps, int)> calc_g,\n               \
    \   typename fps::value_type f0, int deg) {\n  return newton_method(calc_g, fps{f0},\
    \ deg);\n}\n\n/**\n * @brief \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\n */\n"
  code: "#pragma once\n\n#include <functional>\nusing namespace std;\n\n// G(f) =\
    \ 0 mod x^{deg} \u3092\u6E80\u305F\u3059 f \u3092\u8FD4\u3059\n// f0 : \u521D\u671F\
    \u89E3, \u975E\u7A7A\u306A fps \u304B mint \u3092\u5165\u308C\u308B\n// g : (g(f),\
    \ g'(f)) \u3092\u8FD4\u3059\ntemplate <typename fps>\nfps newton_method(function<pair<fps,\
    \ fps>(fps, int)> calc_g, fps f0, int deg) {\n  assert(!f0.empty());\n  fps f{f0};\n\
    \  for (int d = f.size(); d < deg; d *= 2) {\n    // \u5C11\u3057\u591A\u3081\u306B\
    \u8A08\u7B97\u3057\u3066\u304A\u304F\n    const int extra = d + 10;\n    auto\
    \ [g, dgdf] = calc_g(f, d * 2 + extra);\n    int offset = 0;\n    while (offset\
    \ < (int)dgdf.size() && dgdf[offset] == 0) offset++;\n    assert(offset <= extra);\n\
    \    dgdf = dgdf >> offset;\n    g = g >> offset;\n    f = (f - g * dgdf.inv()).pre(d\
    \ * 2);\n  }\n  return f.pre(deg);\n}\n// G(f) = 0 mod x^{deg} \u3092\u6E80\u305F\
    \u3059 f \u3092\u8FD4\u3059\n// f0 : \u521D\u671F\u89E3, \u975E\u7A7A\u306A fps\
    \ \u304B mint \u3092\u5165\u308C\u308B\n// g : (g(f), g'(f)) \u3092\u8FD4\u3059\
    \ntemplate <typename fps>\nfps newton_method(function<pair<fps, fps>(fps, int)>\
    \ calc_g,\n                  typename fps::value_type f0, int deg) {\n  return\
    \ newton_method(calc_g, fps{f0}, deg);\n}\n\n/**\n * @brief \u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/newton-method.hpp
  requiredBy: []
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-exp-newton-method-2.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-newton-method.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-newton-method.test.cpp
  - verify/verify-yosupo-fps/yosupo-compositional-inverse-newton.test.cpp
documentation_of: fps/newton-method.hpp
layout: document
redirect_from:
- /library/fps/newton-method.hpp
- /library/fps/newton-method.hpp.html
title: "\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5"
---
