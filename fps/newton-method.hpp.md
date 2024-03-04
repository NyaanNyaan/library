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
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2661.test.cpp
    title: verify/verify-yuki/yuki-2661.test.cpp
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
    \ {\n  assert(!f0.empty());\n  if (deg <= (int)f0.size()) return f0.pre(deg);\n\
    \  fps f = newton_method(calc_g, f0, (deg + 1) / 2);\n  int extra = 10, offset\
    \ = 0;\n  auto [g, dgdf] = calc_g(f, deg + extra);\n  while (offset < (int)dgdf.size()\
    \ && dgdf[offset] == 0) offset++;\n  assert(offset <= extra);\n  dgdf = dgdf >>\
    \ offset, g = g >> offset;\n  return (f - g * dgdf.inv()).pre(deg);\n}\n// G(f)\
    \ = 0 mod x^{deg} \u3092\u6E80\u305F\u3059 f \u3092\u8FD4\u3059\n// f0 : \u521D\
    \u671F\u89E3, \u975E\u7A7A\u306A fps \u304B mint \u3092\u5165\u308C\u308B\n//\
    \ g : (g(f), g'(f)) \u3092\u8FD4\u3059\ntemplate <typename fps>\nfps newton_method(function<pair<fps,\
    \ fps>(fps, int)> calc_g,\n                  typename fps::value_type f0, int\
    \ deg) {\n  return newton_method(calc_g, fps{f0}, deg);\n}\n\n/**\n * @brief \u30CB\
    \u30E5\u30FC\u30C8\u30F3\u6CD5\n */\n"
  code: "#pragma once\n\n#include <functional>\nusing namespace std;\n\n// G(f) =\
    \ 0 mod x^{deg} \u3092\u6E80\u305F\u3059 f \u3092\u8FD4\u3059\n// f0 : \u521D\u671F\
    \u89E3, \u975E\u7A7A\u306A fps \u304B mint \u3092\u5165\u308C\u308B\n// g : (g(f),\
    \ g'(f)) \u3092\u8FD4\u3059\ntemplate <typename fps>\nfps newton_method(function<pair<fps,\
    \ fps>(fps, int)> calc_g, fps f0, int deg) {\n  assert(!f0.empty());\n  if (deg\
    \ <= (int)f0.size()) return f0.pre(deg);\n  fps f = newton_method(calc_g, f0,\
    \ (deg + 1) / 2);\n  int extra = 10, offset = 0;\n  auto [g, dgdf] = calc_g(f,\
    \ deg + extra);\n  while (offset < (int)dgdf.size() && dgdf[offset] == 0) offset++;\n\
    \  assert(offset <= extra);\n  dgdf = dgdf >> offset, g = g >> offset;\n  return\
    \ (f - g * dgdf.inv()).pre(deg);\n}\n// G(f) = 0 mod x^{deg} \u3092\u6E80\u305F\
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
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2661.test.cpp
  - verify/verify-yosupo-fps/yosupo-compositional-inverse-newton.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-newton-method.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-newton-method.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-newton-method-2.test.cpp
documentation_of: fps/newton-method.hpp
layout: document
redirect_from:
- /library/fps/newton-method.hpp
- /library/fps/newton-method.hpp.html
title: "\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5"
---
