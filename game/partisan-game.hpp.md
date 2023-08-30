---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: game/surreal-number.hpp
    title: "\u8D85\u73FE\u5B9F\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1377.test.cpp
    title: verify/verify-aoj-other/aoj-1377.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0"
    links: []
  bundledCode: "#line 2 \"game/partisan-game.hpp\"\n\n#include <map>\n#include <vector>\n\
    using namespace std;\n\n#line 2 \"game/surreal-number.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n#include <utility>\nusing namespace std;\n\n// reference\
    \ : http://www.ivis.co.jp/text/20111102.pdf\nstruct SurrealNumber {\n  using S\
    \ = SurrealNumber;\n  using i64 = long long;\n\n  // p / 2^q \u306E\u5F62\u3067\
    \u4FDD\u6301\n  i64 p, q;\n  SurrealNumber(i64 _p = 0, i64 _q = 0) : p(_p), q(_q)\
    \ {}\n  friend ostream& operator<<(ostream& os, const SurrealNumber& r) {\n  \
    \  os << r.p;\n    if (r.q != 0) os << \" / \" << (i64{1} << r.q);\n    return\
    \ os;\n  }\n\n  static S normalize(S s) {\n    if (s.p != 0) {\n      while (s.p\
    \ % 2 == 0 and s.q != 0) s.p /= 2, s.q--;\n    } else {\n      s.q = 0;\n    }\n\
    \    return {s.p, s.q};\n  }\n\n  // \u52A0\u7B97\u30FB\u6E1B\u7B97\n  friend\
    \ S operator+(const S& l, const S& r) {\n    i64 cq = max(l.q, r.q);\n    i64\
    \ cp = (l.p << (cq - l.q)) + (r.p << (cq - r.q));\n    return normalize(S{cp,\
    \ cq});\n  }\n  friend S operator-(const S& l, const S& r) {\n    i64 cq = max(l.q,\
    \ r.q);\n    i64 cp = (l.p << (cq - l.q)) - (r.p << (cq - r.q));\n    return normalize(S{cp,\
    \ cq});\n  }\n  S& operator+=(const S& r) { return (*this) = (*this) + r; }\n\
    \  S& operator-=(const S& r) { return (*this) = (*this) - r; }\n\n  S operator-()\
    \ const { return {-p, q}; }\n  S operator+() const { return {p, q}; }\n\n  //\
    \ \u5927\u5C0F\u95A2\u4FC2\n  friend bool operator<(const S& l, const S& r) {\
    \ return (r - l).p > 0; }\n  friend bool operator<=(const S& l, const S& r) {\
    \ return (r - l).p >= 0; }\n  friend bool operator>(const S& l, const S& r) {\
    \ return (l - r).p > 0; }\n  friend bool operator>=(const S& l, const S& r) {\
    \ return (l - r).p >= 0; }\n  friend bool operator==(const S& l, const S& r) {\
    \ return (l - r).p == 0; }\n  friend bool operator!=(const S& l, const S& r) {\
    \ return (l - r).p != 0; }\n\n  // \u5DE6\u53F3\u306E\u5B50\u3092\u8FD4\u3059\u95A2\
    \u6570\n  pair<S, S> child() const {\n    if (p == 0) return {-1, 1};\n    if\
    \ (q == 0 and p > 0) return {S{p * 2 - 1, 1}, p + 1};\n    if (q == 0 and p <\
    \ 0) return {p - 1, S{p * 2 + 1, 1}};\n    return {(*this) - S{1, q + 1}, (*this)\
    \ + S{1, q + 1}};\n  }\n\n  S larger() const {\n    S root = 0;\n    while ((*this)\
    \ >= root) root = root.child().second;\n    return root;\n  }\n  S smaller() const\
    \ {\n    S root = 0;\n    while ((*this) <= root) root = root.child().first;\n\
    \    return root;\n  }\n  friend S reduce(const S& l, const S& r) {\n    assert(l\
    \ < r);\n    S root = 0;\n    while (l >= root or root >= r) {\n      auto [lr,\
    \ rr] = root.child();\n      root = (r <= root ? lr : rr);\n    }\n    return\
    \ root;\n  }\n};\n\n/**\n * @brief \u8D85\u73FE\u5B9F\u6570\n */\n#line 8 \"game/partisan-game.hpp\"\
    \n\n// F : pair(vector<Game>, vector<Game>) \u3092\u8FD4\u3059\u95A2\u6570\ntemplate\
    \ <typename Game, typename F>\nstruct PartisanGameSolver {\n  using Games = vector<Game>;\n\
    \  using S = SurrealNumber;\n\n  map<Game, S> mp;\n  F f;\n\n  PartisanGameSolver(const\
    \ F& _f) : f(_f) {}\n\n  S zero() const { return S{0}; }\n\n  S get(Game g) {\n\
    \    if (mp.count(g)) return mp[g];\n    return mp[g] = _get(g);\n  }\n\n private:\n\
    \  S _get(Game g) {\n    Games gl, gr;\n    tie(gl, gr) = f(g);\n    if (gl.empty()\
    \ and gr.empty()) return 0;\n    vector<S> l, r;\n    for (auto& cg : gl) l.push_back(get(cg));\n\
    \    for (auto& cg : gr) r.push_back(get(cg));\n    S sl, sr;\n    if (!l.empty())\
    \ sl = *max_element(begin(l), end(l));\n    if (!r.empty()) sr = *min_element(begin(r),\
    \ end(r));\n    if (r.empty()) return sl.larger();\n    if (l.empty()) return\
    \ sr.smaller();\n    assert(sl < sr);\n    return reduce(sl, sr);\n  }\n};\n\n\
    /**\n * @brief \u975E\u4E0D\u504F\u30B2\u30FC\u30E0\n */\n"
  code: "#pragma once\n\n#include <map>\n#include <vector>\nusing namespace std;\n\
    \n#include \"surreal-number.hpp\"\n\n// F : pair(vector<Game>, vector<Game>) \u3092\
    \u8FD4\u3059\u95A2\u6570\ntemplate <typename Game, typename F>\nstruct PartisanGameSolver\
    \ {\n  using Games = vector<Game>;\n  using S = SurrealNumber;\n\n  map<Game,\
    \ S> mp;\n  F f;\n\n  PartisanGameSolver(const F& _f) : f(_f) {}\n\n  S zero()\
    \ const { return S{0}; }\n\n  S get(Game g) {\n    if (mp.count(g)) return mp[g];\n\
    \    return mp[g] = _get(g);\n  }\n\n private:\n  S _get(Game g) {\n    Games\
    \ gl, gr;\n    tie(gl, gr) = f(g);\n    if (gl.empty() and gr.empty()) return\
    \ 0;\n    vector<S> l, r;\n    for (auto& cg : gl) l.push_back(get(cg));\n   \
    \ for (auto& cg : gr) r.push_back(get(cg));\n    S sl, sr;\n    if (!l.empty())\
    \ sl = *max_element(begin(l), end(l));\n    if (!r.empty()) sr = *min_element(begin(r),\
    \ end(r));\n    if (r.empty()) return sl.larger();\n    if (l.empty()) return\
    \ sr.smaller();\n    assert(sl < sr);\n    return reduce(sl, sr);\n  }\n};\n\n\
    /**\n * @brief \u975E\u4E0D\u504F\u30B2\u30FC\u30E0\n */\n"
  dependsOn:
  - game/surreal-number.hpp
  isVerificationFile: false
  path: game/partisan-game.hpp
  requiredBy: []
  timestamp: '2023-05-25 17:46:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-1377.test.cpp
documentation_of: game/partisan-game.hpp
layout: document
redirect_from:
- /library/game/partisan-game.hpp
- /library/game/partisan-game.hpp.html
title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0"
---