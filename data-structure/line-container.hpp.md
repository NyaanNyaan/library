---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/line-container-2d.hpp
    title: Line container (for max(ax + by) query)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-2012.test.cpp
    title: verify/verify-yuki/yuki-2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Line container
    links: []
  bundledCode: "#line 2 \"data-structure/line-container.hpp\"\n\n#include <cassert>\n\
    #include <set>\nusing namespace std;\n\nenum Objective {\n  MAXIMIZE = +1,\n \
    \ MINIMIZE = -1,\n};\n\ntemplate <typename T>\nstruct Line {\n  mutable T k, m,\
    \ p;\n  bool operator<(const Line& o) const { return k < o.k; }\n  bool operator<(T\
    \ x) const { return p < x; }\n};\n\ntemplate <typename T>\nT lc_inf() {\n  return\
    \ numeric_limits<T>::max();\n}\ntemplate <>\nlong double lc_inf<long double>()\
    \ {\n  return 1 / .0;\n}\n\ntemplate <typename T>\nT lc_div(T a, T b) {\n  return\
    \ a / b - ((a ^ b) < 0 and a % b);\n}\ntemplate <>\nlong double lc_div(long double\
    \ a, long double b) {\n  return a / b;\n};\n\ntemplate <typename T, Objective\
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
    \ = LineContainer<T, Objective::MAXIMIZE>;\n\n/**\n * @brief Line container\n\
    \ */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <set>\nusing namespace std;\n\
    \nenum Objective {\n  MAXIMIZE = +1,\n  MINIMIZE = -1,\n};\n\ntemplate <typename\
    \ T>\nstruct Line {\n  mutable T k, m, p;\n  bool operator<(const Line& o) const\
    \ { return k < o.k; }\n  bool operator<(T x) const { return p < x; }\n};\n\ntemplate\
    \ <typename T>\nT lc_inf() {\n  return numeric_limits<T>::max();\n}\ntemplate\
    \ <>\nlong double lc_inf<long double>() {\n  return 1 / .0;\n}\n\ntemplate <typename\
    \ T>\nT lc_div(T a, T b) {\n  return a / b - ((a ^ b) < 0 and a % b);\n}\ntemplate\
    \ <>\nlong double lc_div(long double a, long double b) {\n  return a / b;\n};\n\
    \ntemplate <typename T, Objective objective>\nstruct LineContainer : multiset<Line<T>,\
    \ less<>> {\n  using super = multiset<Line<T>, less<>>;\n  using super::begin,\
    \ super::end, super::insert, super::erase;\n  using super::empty, super::lower_bound;\n\
    \  const T inf = lc_inf<T>();\n  bool insect(typename super::iterator x, typename\
    \ super::iterator y) {\n    if (y == end()) return x->p = inf, false;\n    if\
    \ (x->k == y->k)\n      x->p = (x->m > y->m ? inf : -inf);\n    else\n      x->p\
    \ = lc_div(y->m - x->m, x->k - y->k);\n    return x->p >= y->p;\n  }\n  void add(T\
    \ k, T m) {\n    auto z = insert({k * objective, m * objective, 0}), y = z++,\
    \ x = y;\n    while (insect(y, z)) z = erase(z);\n    if (x != begin() and insect(--x,\
    \ y)) insect(x, y = erase(y));\n    while ((y = x) != begin() and (--x)->p >=\
    \ y->p) insect(x, erase(y));\n  }\n  T query(T x) {\n    assert(!empty());\n \
    \   auto l = *lower_bound(x);\n    return (l.k * x + l.m) * objective;\n  }\n\
    };\ntemplate <typename T>\nusing MinLineContainer = LineContainer<T, Objective::MINIMIZE>;\n\
    template <typename T>\nusing MaxLineContainer = LineContainer<T, Objective::MAXIMIZE>;\n\
    \n/**\n * @brief Line container\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/line-container.hpp
  requiredBy:
  - data-structure/line-container-2d.hpp
  timestamp: '2022-08-22 20:09:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-2012.test.cpp
documentation_of: data-structure/line-container.hpp
layout: document
redirect_from:
- /library/data-structure/line-container.hpp
- /library/data-structure/line-container.hpp.html
title: Line container
---
