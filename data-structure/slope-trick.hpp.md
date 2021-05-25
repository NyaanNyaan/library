---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/slope-trick.hpp\"\n\nstruct SlopeTrick {\n\
    \  using ll = long long;\n  ll lazx, mn;\n  priority_queue<ll> L;\n  priority_queue<ll,\
    \ vector<ll>, greater<>> R;\n\n  SlopeTrick() : lazx(0), mn(0) {}\n\n  pair<ll,\
    \ ll> get_min() {\n    ll x = L.empty() ? R.empty() ? 0 : R.top() : L.top();\n\
    \    return {x + lazx, mn};\n  }\n\n  // f(x) <- f(x - a)\n  void shift_x(ll a)\
    \ { lazx += a; }\n  // f(x) <- f(x) + a\n  void shift_y(ll a) { mn += a; }\n\n\
    \  /**\n   * add (x-a)_+\n   *           /\n   *          /\n   *   _____ /\n\
    \   */\n  void add_xma(ll a) {\n    a -= lazx;\n    if (!L.empty()) mn += max(0LL,\
    \ L.top() - a);\n    L.push(a);\n    R.push(L.top());\n    L.pop();\n  }\n\n \
    \ /**\n   * add (a-x)_+\n   *   \\\n   *    \\\n   *     \\_____\n   */\n  void\
    \ add_amx(ll a) {\n    a -= lazx;\n    if (!R.empty()) mn += max(0LL, R.top()\
    \ - a);\n    R.push(a);\n    L.push(R.top());\n    R.pop();\n  }\n\n  void add_abs_xma(ll\
    \ a) { add_xma(a), add_amx(a); }\n\n  //  \\_/ -> \\__\n  void accum_min_right()\
    \ {\n    decltype(R) dummy;\n    swap(dummy, R);\n  }\n\n  // \\_/ -> __/\n  void\
    \ accum_min_left() {\n    decltype(L) dummy;\n    swap(dummy, L);\n  }\n};\n"
  code: "#pragma once\n\nstruct SlopeTrick {\n  using ll = long long;\n  ll lazx,\
    \ mn;\n  priority_queue<ll> L;\n  priority_queue<ll, vector<ll>, greater<>> R;\n\
    \n  SlopeTrick() : lazx(0), mn(0) {}\n\n  pair<ll, ll> get_min() {\n    ll x =\
    \ L.empty() ? R.empty() ? 0 : R.top() : L.top();\n    return {x + lazx, mn};\n\
    \  }\n\n  // f(x) <- f(x - a)\n  void shift_x(ll a) { lazx += a; }\n  // f(x)\
    \ <- f(x) + a\n  void shift_y(ll a) { mn += a; }\n\n  /**\n   * add (x-a)_+\n\
    \   *           /\n   *          /\n   *   _____ /\n   */\n  void add_xma(ll a)\
    \ {\n    a -= lazx;\n    if (!L.empty()) mn += max(0LL, L.top() - a);\n    L.push(a);\n\
    \    R.push(L.top());\n    L.pop();\n  }\n\n  /**\n   * add (a-x)_+\n   *   \\\
    \n   *    \\\n   *     \\_____\n   */\n  void add_amx(ll a) {\n    a -= lazx;\n\
    \    if (!R.empty()) mn += max(0LL, R.top() - a);\n    R.push(a);\n    L.push(R.top());\n\
    \    R.pop();\n  }\n\n  void add_abs_xma(ll a) { add_xma(a), add_amx(a); }\n\n\
    \  //  \\_/ -> \\__\n  void accum_min_right() {\n    decltype(R) dummy;\n    swap(dummy,\
    \ R);\n  }\n\n  // \\_/ -> __/\n  void accum_min_left() {\n    decltype(L) dummy;\n\
    \    swap(dummy, L);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slope-trick.hpp
  requiredBy: []
  timestamp: '2021-05-25 16:58:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slope-trick.hpp
layout: document
redirect_from:
- /library/data-structure/slope-trick.hpp
- /library/data-structure/slope-trick.hpp.html
title: data-structure/slope-trick.hpp
---
