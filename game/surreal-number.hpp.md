---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: game/partisan-game.hpp
    title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1377.test.cpp
    title: verify/verify-aoj-other/aoj-1377.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8D85\u73FE\u5B9F\u6570"
    links:
    - http://www.ivis.co.jp/text/20111102.pdf
  bundledCode: "#line 2 \"game/surreal-number.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <utility>\nusing namespace std;\n\n// reference : http://www.ivis.co.jp/text/20111102.pdf\n\
    struct SurrealNumber {\n  using S = SurrealNumber;\n  using i64 = long long;\n\
    \n  // p / 2^q \u306E\u5F62\u3067\u4FDD\u6301\n  i64 p, q;\n  SurrealNumber(i64\
    \ _p = 0, i64 _q = 0) : p(_p), q(_q) {}\n  friend ostream& operator<<(ostream&\
    \ os, const SurrealNumber& r) {\n    os << r.p;\n    if (r.q != 0) os << \" /\
    \ \" << (i64{1} << r.q);\n    return os;\n  }\n\n  static S normalize(S s) {\n\
    \    if (s.p != 0) {\n      while (s.p % 2 == 0 and s.q != 0) s.p /= 2, s.q--;\n\
    \    } else {\n      s.q = 0;\n    }\n    return {s.p, s.q};\n  }\n\n  // \u52A0\
    \u7B97\u30FB\u6E1B\u7B97\n  friend S operator+(const S& l, const S& r) {\n   \
    \ i64 cq = max(l.q, r.q);\n    i64 cp = (l.p << (cq - l.q)) + (r.p << (cq - r.q));\n\
    \    return normalize(S{cp, cq});\n  }\n  friend S operator-(const S& l, const\
    \ S& r) {\n    i64 cq = max(l.q, r.q);\n    i64 cp = (l.p << (cq - l.q)) - (r.p\
    \ << (cq - r.q));\n    return normalize(S{cp, cq});\n  }\n  S& operator+=(const\
    \ S& r) { return (*this) = (*this) + r; }\n  S& operator-=(const S& r) { return\
    \ (*this) = (*this) - r; }\n\n  S operator-() const { return {-p, q}; }\n  S operator+()\
    \ const { return {p, q}; }\n\n  // \u5927\u5C0F\u95A2\u4FC2\n  friend bool operator<(const\
    \ S& l, const S& r) { return (r - l).p > 0; }\n  friend bool operator<=(const\
    \ S& l, const S& r) { return (r - l).p >= 0; }\n  friend bool operator>(const\
    \ S& l, const S& r) { return (l - r).p > 0; }\n  friend bool operator>=(const\
    \ S& l, const S& r) { return (l - r).p >= 0; }\n  friend bool operator==(const\
    \ S& l, const S& r) { return (l - r).p == 0; }\n  friend bool operator!=(const\
    \ S& l, const S& r) { return (l - r).p != 0; }\n\n  // \u5DE6\u53F3\u306E\u5B50\
    \u3092\u8FD4\u3059\u95A2\u6570\n  pair<S, S> child() const {\n    if (p == 0)\
    \ return {-1, 1};\n    if (q == 0 and p > 0) return {S{p * 2 - 1, 1}, p + 1};\n\
    \    if (q == 0 and p < 0) return {p - 1, S{p * 2 + 1, 1}};\n    return {(*this)\
    \ - S{1, q + 1}, (*this) + S{1, q + 1}};\n  }\n\n  S larger() const {\n    S root\
    \ = 0;\n    while ((*this) >= root) root = root.child().second;\n    return root;\n\
    \  }\n  S smaller() const {\n    S root = 0;\n    while ((*this) <= root) root\
    \ = root.child().first;\n    return root;\n  }\n  friend S reduce(const S& l,\
    \ const S& r) {\n    assert(l < r);\n    S root = 0;\n    while (l >= root or\
    \ root >= r) {\n      auto [lr, rr] = root.child();\n      root = (r <= root ?\
    \ lr : rr);\n    }\n    return root;\n  }\n};\n\n/**\n * @brief \u8D85\u73FE\u5B9F\
    \u6570\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\
    using namespace std;\n\n// reference : http://www.ivis.co.jp/text/20111102.pdf\n\
    struct SurrealNumber {\n  using S = SurrealNumber;\n  using i64 = long long;\n\
    \n  // p / 2^q \u306E\u5F62\u3067\u4FDD\u6301\n  i64 p, q;\n  SurrealNumber(i64\
    \ _p = 0, i64 _q = 0) : p(_p), q(_q) {}\n  friend ostream& operator<<(ostream&\
    \ os, const SurrealNumber& r) {\n    os << r.p;\n    if (r.q != 0) os << \" /\
    \ \" << (i64{1} << r.q);\n    return os;\n  }\n\n  static S normalize(S s) {\n\
    \    if (s.p != 0) {\n      while (s.p % 2 == 0 and s.q != 0) s.p /= 2, s.q--;\n\
    \    } else {\n      s.q = 0;\n    }\n    return {s.p, s.q};\n  }\n\n  // \u52A0\
    \u7B97\u30FB\u6E1B\u7B97\n  friend S operator+(const S& l, const S& r) {\n   \
    \ i64 cq = max(l.q, r.q);\n    i64 cp = (l.p << (cq - l.q)) + (r.p << (cq - r.q));\n\
    \    return normalize(S{cp, cq});\n  }\n  friend S operator-(const S& l, const\
    \ S& r) {\n    i64 cq = max(l.q, r.q);\n    i64 cp = (l.p << (cq - l.q)) - (r.p\
    \ << (cq - r.q));\n    return normalize(S{cp, cq});\n  }\n  S& operator+=(const\
    \ S& r) { return (*this) = (*this) + r; }\n  S& operator-=(const S& r) { return\
    \ (*this) = (*this) - r; }\n\n  S operator-() const { return {-p, q}; }\n  S operator+()\
    \ const { return {p, q}; }\n\n  // \u5927\u5C0F\u95A2\u4FC2\n  friend bool operator<(const\
    \ S& l, const S& r) { return (r - l).p > 0; }\n  friend bool operator<=(const\
    \ S& l, const S& r) { return (r - l).p >= 0; }\n  friend bool operator>(const\
    \ S& l, const S& r) { return (l - r).p > 0; }\n  friend bool operator>=(const\
    \ S& l, const S& r) { return (l - r).p >= 0; }\n  friend bool operator==(const\
    \ S& l, const S& r) { return (l - r).p == 0; }\n  friend bool operator!=(const\
    \ S& l, const S& r) { return (l - r).p != 0; }\n\n  // \u5DE6\u53F3\u306E\u5B50\
    \u3092\u8FD4\u3059\u95A2\u6570\n  pair<S, S> child() const {\n    if (p == 0)\
    \ return {-1, 1};\n    if (q == 0 and p > 0) return {S{p * 2 - 1, 1}, p + 1};\n\
    \    if (q == 0 and p < 0) return {p - 1, S{p * 2 + 1, 1}};\n    return {(*this)\
    \ - S{1, q + 1}, (*this) + S{1, q + 1}};\n  }\n\n  S larger() const {\n    S root\
    \ = 0;\n    while ((*this) >= root) root = root.child().second;\n    return root;\n\
    \  }\n  S smaller() const {\n    S root = 0;\n    while ((*this) <= root) root\
    \ = root.child().first;\n    return root;\n  }\n  friend S reduce(const S& l,\
    \ const S& r) {\n    assert(l < r);\n    S root = 0;\n    while (l >= root or\
    \ root >= r) {\n      auto [lr, rr] = root.child();\n      root = (r <= root ?\
    \ lr : rr);\n    }\n    return root;\n  }\n};\n\n/**\n * @brief \u8D85\u73FE\u5B9F\
    \u6570\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: game/surreal-number.hpp
  requiredBy:
  - game/partisan-game.hpp
  timestamp: '2023-05-25 17:46:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-1377.test.cpp
documentation_of: game/surreal-number.hpp
layout: document
redirect_from:
- /library/game/surreal-number.hpp
- /library/game/surreal-number.hpp.html
title: "\u8D85\u73FE\u5B9F\u6570"
---
