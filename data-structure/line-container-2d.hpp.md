---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/line-container.hpp
    title: data-structure/line-container.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-2012.test.cpp
    title: verify/verify-yuki/yuki-2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Line container (for max(ax + by) query)
    links: []
  bundledCode: "#line 2 \"data-structure/line-container-2d.hpp\"\n#include <algorithm>\n\
    using namespace std;\n\n#line 2 \"data-structure/line-container.hpp\"\n\n#include\
    \ <cassert>\n#include <set>\nusing namespace std;\n\nenum Objective {\n  MAXIMIZE\
    \ = +1,\n  MINIMIZE = -1,\n};\n\ntemplate <typename T>\nstruct Line {\n  mutable\
    \ T k, m, p;\n  bool operator<(const Line& o) const { return k < o.k; }\n  bool\
    \ operator<(T x) const { return p < x; }\n};\n\ntemplate <typename T>\nT lc_inf()\
    \ {\n  return numeric_limits<T>::max();\n}\ntemplate <>\nlong double lc_inf<long\
    \ double>() {\n  return 1 / .0;\n}\n\ntemplate <typename T>\nT lc_div(T a, T b)\
    \ {\n  return a / b - ((a ^ b) < 0 and a % b);\n}\ntemplate <>\nlong double lc_div(long\
    \ double a, long double b) {\n  return a / b;\n};\n\ntemplate <typename T, Objective\
    \ objective>\nstruct LineContainer : multiset<Line<T>, less<>> {\n  using super\
    \ = multiset<Line<T>, less<>>;\n  using super::begin, super::end, super::insert,\
    \ super::erase;\n  using super::empty, super::lower_bound;\n  const T inf = lc_inf<T>();\n\
    \  bool insect(typename super::iterator x, typename super::iterator y) {\n   \
    \ if (y == end()) return x->p = inf, false;\n    if (x->k == y->k)\n      x->p\
    \ = (x->m > y->m ? inf : -inf);\n    else\n      x->p = lc_div(y->m - x->m, x->k\
    \ - y->k);\n    return x->p >= y->p;\n  }\n  void add(T k, T m) {\n    auto z\
    \ = insert({k * objective, m * objective, 0}), y = z++, x = y;\n    while (insect(y,\
    \ z)) z = erase(z);\n    if (x != begin() and insect(--x, y)) insect(x, y = erase(y));\n\
    \    while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));\n  }\n\
    \  T query(T x) {\n    assert(!empty());\n    auto l = *lower_bound(x);\n    return\
    \ (l.k * x + l.m) * objective;\n  }\n};\ntemplate <typename T>\nusing MinLineContainer\
    \ = LineContainer<T, Objective::MINIMIZE>;\ntemplate <typename T>\nusing MaxLineContainer\
    \ = LineContainer<T, Objective::MAXIMIZE>;\n#line 6 \"data-structure/line-container-2d.hpp\"\
    \n\nstruct LineContainer2D {\n  using ld = long double;\n  using ll = long long;\n\
    \n  ld Xmax, Xmin, Ymax, Ymin;\n  static constexpr ld INF = 4.1e18;\n  MinLineContainer<ld>\
    \ minlc;\n  MaxLineContainer<ld> maxlc;\n  LineContainer2D() : Xmax(-INF), Xmin(INF),\
    \ Ymax(-INF), Ymin(INF) {}\n\n  void add(ld x, ld y) {\n    Xmax = max(Xmax, x),\
    \ Xmin = min(Xmin, x);\n    Ymax = max(Ymax, y), Ymin = min(Ymin, y);\n    minlc.add(y,\
    \ x), maxlc.add(y, x);\n  }\n\n  ld max_ld(ld a, ld b) {\n    if (a == 0) return\
    \ b * (b > 0 ? Ymax : Ymin);\n    if (b == 0) return a * (a > 0 ? Xmax : Xmin);\n\
    \    ld c = b / a;\n    if (a > 0) {\n      auto l = maxlc.lower_bound(c);\n \
    \     ld x = l->m, y = l->k;\n      return a * x + b * y;\n    } else {\n    \
    \  auto l = minlc.lower_bound(c);\n      ld x = -l->m, y = -l->k;\n      return\
    \ a * x + b * y;\n    }\n  }\n  ld min_ld(ld a, ld b) { return -max_ld(-a, -b);\
    \ }\n  ll max_ll(ll a, ll b) { return round(clamp<ll>(max_ld(a, b), -INF, INF));\
    \ }\n  ll min_ll(ll a, ll b) { return round(clamp<ll>(min_ld(a, b), -INF, INF));\
    \ }\n\n private:\n  ll round(ld a) { return a >= 0.0 ? a + 0.5 : a - 0.5; }\n\
    };\n\n/**\n * @brief Line container (for max(ax + by) query)\n */\n"
  code: "#pragma once\n#include <algorithm>\nusing namespace std;\n\n#include \"line-container.hpp\"\
    \n\nstruct LineContainer2D {\n  using ld = long double;\n  using ll = long long;\n\
    \n  ld Xmax, Xmin, Ymax, Ymin;\n  static constexpr ld INF = 4.1e18;\n  MinLineContainer<ld>\
    \ minlc;\n  MaxLineContainer<ld> maxlc;\n  LineContainer2D() : Xmax(-INF), Xmin(INF),\
    \ Ymax(-INF), Ymin(INF) {}\n\n  void add(ld x, ld y) {\n    Xmax = max(Xmax, x),\
    \ Xmin = min(Xmin, x);\n    Ymax = max(Ymax, y), Ymin = min(Ymin, y);\n    minlc.add(y,\
    \ x), maxlc.add(y, x);\n  }\n\n  ld max_ld(ld a, ld b) {\n    if (a == 0) return\
    \ b * (b > 0 ? Ymax : Ymin);\n    if (b == 0) return a * (a > 0 ? Xmax : Xmin);\n\
    \    ld c = b / a;\n    if (a > 0) {\n      auto l = maxlc.lower_bound(c);\n \
    \     ld x = l->m, y = l->k;\n      return a * x + b * y;\n    } else {\n    \
    \  auto l = minlc.lower_bound(c);\n      ld x = -l->m, y = -l->k;\n      return\
    \ a * x + b * y;\n    }\n  }\n  ld min_ld(ld a, ld b) { return -max_ld(-a, -b);\
    \ }\n  ll max_ll(ll a, ll b) { return round(clamp<ll>(max_ld(a, b), -INF, INF));\
    \ }\n  ll min_ll(ll a, ll b) { return round(clamp<ll>(min_ld(a, b), -INF, INF));\
    \ }\n\n private:\n  ll round(ld a) { return a >= 0.0 ? a + 0.5 : a - 0.5; }\n\
    };\n\n/**\n * @brief Line container (for max(ax + by) query)\n */\n"
  dependsOn:
  - data-structure/line-container.hpp
  isVerificationFile: false
  path: data-structure/line-container-2d.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:21:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-2012.test.cpp
documentation_of: data-structure/line-container-2d.hpp
layout: document
redirect_from:
- /library/data-structure/line-container-2d.hpp
- /library/data-structure/line-container-2d.hpp.html
title: Line container (for max(ax + by) query)
---
