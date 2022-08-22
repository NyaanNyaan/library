---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1467.test.cpp
    title: verify/verify-yuki/yuki-1467.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Slope Trick
    links: []
  bundledCode: "#line 2 \"data-structure/slope-trick.hpp\"\n\nstruct SlopeTrick {\n\
    \ private:\n  using ll = long long;\n  // x : \u5EA7\u6A19, c : \u50BE\u304D\u306E\
    \u5909\u5316\u91CF\n  struct P {\n    ll x, c;\n    P(ll _x, ll _c) : x(_x), c(_c)\
    \ {}\n    friend bool operator<(const P& a, const P& b) { return a.x < b.x; }\n\
    \    friend bool operator>(const P& a, const P& b) { return a.x > b.x; }\n  };\n\
    \  ll addL, addR, min_y;\n  priority_queue<P> L;\n  priority_queue<P, vector<P>,\
    \ greater<>> R;\n  void pushL(ll x, ll c = 1) { L.emplace(x - addL, c); }\n  void\
    \ pushR(ll x, ll c = 1) { R.emplace(x - addR, c); }\n  P getL() { return P{L.top().x\
    \ + addL, L.top().c}; }\n  P getR() { return P{R.top().x + addR, R.top().c}; }\n\
    \  void popL() { L.pop(); }\n  void popR() { R.pop(); }\n\n public:\n  SlopeTrick()\
    \ : addL(0), addR(0), min_y(0) {}\n\n  void debug() {\n    cerr << \"addL, addR,\
    \ min_y : \";\n    cerr << addL << \", \" << addR << \", \" << min_y << endl;\n\
    \n    auto LL{L};\n    cerr << \"L : \";\n    while (!LL.empty()) {\n      cerr\
    \ << \"( \" << LL.top().x + addL << \", \" << LL.top().c << \" ), \";\n      LL.pop();\n\
    \    }\n    cerr << endl;\n\n    auto RR{R};\n    cerr << \"R : \";\n    while\
    \ (!RR.empty()) {\n      cerr << \"( \" << RR.top().x + addR << \", \" << RR.top().c\
    \ << \" ), \";\n      RR.pop();\n    }\n    cerr << endl;\n\n    cerr << \"min\
    \ : \";\n    cerr << \"( \" << get_min().first << \", \" << get_min().second <<\
    \ \" )\" << endl;\n  }\n\n  // return {x, y} s.t. {argmin, min}\n  pair<ll, ll>\
    \ get_min() {\n    ll x = L.empty() ? R.empty() ? 0 : getR().x : getL().x;\n \
    \   return {x, min_y};\n  }\n\n  void shift_L(ll a) { addL += a; }\n  void shift_R(ll\
    \ a) { addR += a; }\n  // f(x) <- f(x - a)\n  void shift_x(ll a) { addL += a,\
    \ addR += a; }\n  // f(x) <- f(x) + a\n  void shift_y(ll a) { min_y += a; }\n\n\
    \  // add (x-a)_+   _____/\n  void add_xma(ll a, ll c = 1) {\n    ll used = 0;\n\
    \    while (used < c && !L.empty()) {\n      auto [X, C] = getL();\n      if (X\
    \ <= a) break;\n      popL();\n      ll tmp = min(c - used, C);\n      pushR(X,\
    \ tmp);\n      if (C != tmp) pushL(X, C - tmp);\n      min_y += (X - a) * tmp;\n\
    \      used += tmp;\n    }\n    if (used) pushL(a, used);\n    if (c - used) pushR(a,\
    \ c - used);\n  }\n\n  // add (a-x)_+   \\_____\n  void add_amx(ll a, ll c = 1)\
    \ {\n    ll used = 0;\n    while (used < c && !R.empty()) {\n      auto [X, C]\
    \ = getR();\n      if (X >= a) break;\n      popR();\n      ll tmp = min(c - used,\
    \ C);\n      pushL(X, tmp);\n      if (C != tmp) pushR(X, C - tmp);\n      min_y\
    \ += (a - X) * tmp;\n      used += tmp;\n    }\n    if (used) pushR(a, used);\n\
    \    if (c - used) pushL(a, c - used);\n  }\n\n  // add |x-a|     \\____/\n  void\
    \ add_abs_xma(ll a, ll c = 1) { add_xma(a, c), add_amx(a, c); }\n\n  //  chmin\
    \ right side \\_/ -> \\__\n  void chmin_right() { decltype(R){}.swap(R); }\n \
    \ //  chmin left side  \\_/ -> __/\n  void chmin_left() { decltype(L){}.swap(L);\
    \ }\n\n  // destructive merge\n  void merge(SlopeTrick& r) {\n    if (L.size()\
    \ + R.size() < r.L.size() + r.R.size()) swap(*this, r);\n    while (!r.L.empty())\
    \ {\n      auto [x, c] = r.getL();\n      r.popL();\n      add_amx(x, c);\n  \
    \  }\n    while (!r.R.empty()) {\n      auto [x, c] = r.getR();\n      r.popR();\n\
    \      add_xma(x, c);\n    }\n    shift_y(r.min_y);\n  }\n\n  // eval f(x) O(|L|\
    \ + |R|) TODO : verify\n  ll eval(ll x) {\n    ll y = min_y;\n    auto LL{L};\n\
    \    while (!LL.empty()) {\n      auto [X, C] = LL.top();\n      X += addL;\n\
    \      if(X < x) break;\n      y += (X - x) * C;\n      LL.pop();\n    }\n   \
    \ auto RR{R};\n    while (!RR.empty()) {\n      auto [X, C] = RR.top();\n    \
    \  X += addR;\n      if(x < X) break;\n      y += (x - X) * C;\n      RR.pop();\n\
    \    }\n    return y;\n  }\n};\n\n/**\n * @brief Slope Trick\n */\n"
  code: "#pragma once\n\nstruct SlopeTrick {\n private:\n  using ll = long long;\n\
    \  // x : \u5EA7\u6A19, c : \u50BE\u304D\u306E\u5909\u5316\u91CF\n  struct P {\n\
    \    ll x, c;\n    P(ll _x, ll _c) : x(_x), c(_c) {}\n    friend bool operator<(const\
    \ P& a, const P& b) { return a.x < b.x; }\n    friend bool operator>(const P&\
    \ a, const P& b) { return a.x > b.x; }\n  };\n  ll addL, addR, min_y;\n  priority_queue<P>\
    \ L;\n  priority_queue<P, vector<P>, greater<>> R;\n  void pushL(ll x, ll c =\
    \ 1) { L.emplace(x - addL, c); }\n  void pushR(ll x, ll c = 1) { R.emplace(x -\
    \ addR, c); }\n  P getL() { return P{L.top().x + addL, L.top().c}; }\n  P getR()\
    \ { return P{R.top().x + addR, R.top().c}; }\n  void popL() { L.pop(); }\n  void\
    \ popR() { R.pop(); }\n\n public:\n  SlopeTrick() : addL(0), addR(0), min_y(0)\
    \ {}\n\n  void debug() {\n    cerr << \"addL, addR, min_y : \";\n    cerr << addL\
    \ << \", \" << addR << \", \" << min_y << endl;\n\n    auto LL{L};\n    cerr <<\
    \ \"L : \";\n    while (!LL.empty()) {\n      cerr << \"( \" << LL.top().x + addL\
    \ << \", \" << LL.top().c << \" ), \";\n      LL.pop();\n    }\n    cerr << endl;\n\
    \n    auto RR{R};\n    cerr << \"R : \";\n    while (!RR.empty()) {\n      cerr\
    \ << \"( \" << RR.top().x + addR << \", \" << RR.top().c << \" ), \";\n      RR.pop();\n\
    \    }\n    cerr << endl;\n\n    cerr << \"min : \";\n    cerr << \"( \" << get_min().first\
    \ << \", \" << get_min().second << \" )\" << endl;\n  }\n\n  // return {x, y}\
    \ s.t. {argmin, min}\n  pair<ll, ll> get_min() {\n    ll x = L.empty() ? R.empty()\
    \ ? 0 : getR().x : getL().x;\n    return {x, min_y};\n  }\n\n  void shift_L(ll\
    \ a) { addL += a; }\n  void shift_R(ll a) { addR += a; }\n  // f(x) <- f(x - a)\n\
    \  void shift_x(ll a) { addL += a, addR += a; }\n  // f(x) <- f(x) + a\n  void\
    \ shift_y(ll a) { min_y += a; }\n\n  // add (x-a)_+   _____/\n  void add_xma(ll\
    \ a, ll c = 1) {\n    ll used = 0;\n    while (used < c && !L.empty()) {\n   \
    \   auto [X, C] = getL();\n      if (X <= a) break;\n      popL();\n      ll tmp\
    \ = min(c - used, C);\n      pushR(X, tmp);\n      if (C != tmp) pushL(X, C -\
    \ tmp);\n      min_y += (X - a) * tmp;\n      used += tmp;\n    }\n    if (used)\
    \ pushL(a, used);\n    if (c - used) pushR(a, c - used);\n  }\n\n  // add (a-x)_+\
    \   \\_____\n  void add_amx(ll a, ll c = 1) {\n    ll used = 0;\n    while (used\
    \ < c && !R.empty()) {\n      auto [X, C] = getR();\n      if (X >= a) break;\n\
    \      popR();\n      ll tmp = min(c - used, C);\n      pushL(X, tmp);\n     \
    \ if (C != tmp) pushR(X, C - tmp);\n      min_y += (a - X) * tmp;\n      used\
    \ += tmp;\n    }\n    if (used) pushR(a, used);\n    if (c - used) pushL(a, c\
    \ - used);\n  }\n\n  // add |x-a|     \\____/\n  void add_abs_xma(ll a, ll c =\
    \ 1) { add_xma(a, c), add_amx(a, c); }\n\n  //  chmin right side \\_/ -> \\__\n\
    \  void chmin_right() { decltype(R){}.swap(R); }\n  //  chmin left side  \\_/\
    \ -> __/\n  void chmin_left() { decltype(L){}.swap(L); }\n\n  // destructive merge\n\
    \  void merge(SlopeTrick& r) {\n    if (L.size() + R.size() < r.L.size() + r.R.size())\
    \ swap(*this, r);\n    while (!r.L.empty()) {\n      auto [x, c] = r.getL();\n\
    \      r.popL();\n      add_amx(x, c);\n    }\n    while (!r.R.empty()) {\n  \
    \    auto [x, c] = r.getR();\n      r.popR();\n      add_xma(x, c);\n    }\n \
    \   shift_y(r.min_y);\n  }\n\n  // eval f(x) O(|L| + |R|) TODO : verify\n  ll\
    \ eval(ll x) {\n    ll y = min_y;\n    auto LL{L};\n    while (!LL.empty()) {\n\
    \      auto [X, C] = LL.top();\n      X += addL;\n      if(X < x) break;\n   \
    \   y += (X - x) * C;\n      LL.pop();\n    }\n    auto RR{R};\n    while (!RR.empty())\
    \ {\n      auto [X, C] = RR.top();\n      X += addR;\n      if(x < X) break;\n\
    \      y += (x - X) * C;\n      RR.pop();\n    }\n    return y;\n  }\n};\n\n/**\n\
    \ * @brief Slope Trick\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slope-trick.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1467.test.cpp
documentation_of: data-structure/slope-trick.hpp
layout: document
redirect_from:
- /library/data-structure/slope-trick.hpp
- /library/data-structure/slope-trick.hpp.html
title: Slope Trick
---
