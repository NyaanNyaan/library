---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/li-chao-tree-abstruct.test.cpp
    title: verify/verify-unit-test/li-chao-tree-abstruct.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-3.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-4.test.cpp
    title: verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment-tree/li-chao-tree-abstruct.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n// Line : T operator(ll)\
    \ \u3092\u5B9A\u7FA9\u3059\u308B\ntemplate <typename Line, bool MINIMIZE = true,\
    \ bool RANGE_GET = false>\nstruct LiChaoTree {\n  using T = decltype(Line{}(0));\n\
    \n  vector<long long> xs;\n  vector<Line> dat;\n  vector<pair<int, T>> val;  //\
    \ (\u8A55\u4FA1\u70B9(\u5EA7\u5727\u5F8C), \u8A55\u4FA1\u3057\u305F\u5024)\n \
    \ int n, size;\n  T inf;\n\n  LiChaoTree(const vector<long long>& _xs, Line I)\
    \ { init(_xs, I); }\n  LiChaoTree(int _n, Line I) {\n    vector<long long> _xs(_n);\n\
    \    for (int i = 0; i < _n; i++) _xs[i] = i;\n    init(_xs, I);\n  }\n\n  int\
    \ get_idx(long long x) {\n    return lower_bound(begin(xs), end(xs), x) - begin(xs);\n\
    \  }\n\n  void add_line(Line f) { return apply(1, f); }\n\n  // [xl, xr) \u534A\
    \u958B\n  void add_segment(long long xl, long long xr, Line f) {\n    xl = get_idx(xl),\
    \ xr = get_idx(xr);\n    if (xl == xr) return;\n    xl += size, xr += size;\n\
    \    int l = xl, r = xr;\n    for (; xl < xr; xl >>= 1, xr >>= 1) {\n      if\
    \ (xl & 1) apply(xl++, f);\n      if (xr & 1) apply(--xr, f);\n    }\n    if (RANGE_GET)\
    \ {\n      for (int i = 1; i <= __builtin_ctz(size); i++) {\n        if (((l >>\
    \ i) << i) != l) update(l >> i);\n        if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n      }\n    }\n  }\n\n  // (\u5024, Line) \u306E\u7D44\n  pair<T,\
    \ Line> get_val(long long x) {\n    int i = get_idx(x);\n    assert(0 <= i and\
    \ i < n);\n    Line f = dat[0];\n    T fx = f(x);\n    for (i += size; i; i >>=\
    \ 1) {\n      Line g = dat[i];\n      T gx = g(x);\n      if ((MINIMIZE && gx\
    \ < fx) || (!MINIMIZE && gx > fx)) {\n        f = g, fx = gx;\n      }\n    }\n\
    \    return {fx, f};\n  }\n\n  // [xl, xr) \u534A\u958B\n  // \u8FD4\u308A\u5024\
    \ : (\u8A55\u4FA1\u70B9 x, x \u3067\u8A55\u4FA1\u3057\u305F\u5024)\n  // \u8FFD\
    \u52A0\u3059\u308B\u76F4\u7DDA\u306B\u5358\u8ABF\u6027\u304C\u3042\u308B\u6642\
    \u306E\u307F\u4F7F\u7528\u53EF\u80FD\n  // RANGE_GET \u3092 true \u306B\u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n  pair<long long, T> get(long long xl, long long\
    \ xr) {\n    assert(RANGE_GET == true);\n    xl = get_idx(xl), xr = get_idx(xr);\n\
    \    assert(xl != xr);\n    pair<int, T> best = _get(1, 0, size, xl, xr);\n  \
    \  assert(best.first != -1);\n    return make_pair(xs[best.first], best.second);\n\
    \  }\n\n private:\n  void init(const vector<long long>& _xs, Line I) {\n    xs\
    \ = _xs;\n    sort(begin(xs), end(xs));\n    xs.erase(unique(begin(xs), end(xs)),\
    \ end(xs));\n    n = xs.size();\n    int lg = 1;\n    while ((1 << lg) < n) lg++;\n\
    \    size = 1 << lg;\n    dat.resize(size * 2, I);\n    inf = (MINIMIZE ? numeric_limits<T>::max()\
    \ : numeric_limits<T>::min()) / 2;\n    val.resize(size * 2, make_pair(-1, inf));\n\
    \    for (int i = size * 2 - 1; i; i--) update(i);\n  }\n\n  T eval(int i, Line\
    \ f) { return f(xs[min(i, n - 1)]); }\n\n  void apply(int i, Line f) {\n    int\
    \ upper_bit = 31 - __builtin_clz(i);\n    int l = (size >> upper_bit) * (i - (1\
    \ << upper_bit));\n    int r = l + (size >> upper_bit);\n    Line g = dat[i];\n\
    \    T fl = eval(l, f), fr = eval(r - 1, f);\n    T gl = eval(l, g), gr = eval(r\
    \ - 1, g);\n    bool bl = (MINIMIZE ? fl < gl : fl > gl);\n    bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n    if (!bl and !br) return;\n    if (bl and br) {\n\
    \      dat[i] = f;\n    } else {\n      int m = (l + r) / 2;\n      T fm = eval(m,\
    \ f), gm = eval(m, g);\n      bool bm = (MINIMIZE ? fm < gm : fm > gm);\n    \
    \  if (bm) {\n        dat[i] = f;\n        f = g;\n        apply(i * 2 + bl, f);\n\
    \      } else {\n        apply(i * 2 + 1 - bl, f);\n      }\n    }\n    update(i);\n\
    \  }\n\n  void update(int i) {\n    if constexpr (RANGE_GET) {\n      if (i ==\
    \ 0) return;\n      int upper_bit = 31 - __builtin_clz(i);\n      int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n      int r = l + (size >> upper_bit);\n\
    \      val[i] = make_pair(-1, inf);\n      auto chmin = [&](int x, T y) {\n  \
    \      if (MINIMIZE ? y < val[i].second : val[i].second < y) {\n          val[i]\
    \ = make_pair(x, y);\n        }\n      };\n      if (l < n) {\n        chmin(l,\
    \ eval(l, dat[i]));\n        chmin(min(r - 1, n - 1), eval(r - 1, dat[i]));\n\
    \      }\n      if (i < size) {\n        chmin(val[i * 2 + 0].first, val[i * 2\
    \ + 0].second);\n        chmin(val[i * 2 + 1].first, val[i * 2 + 1].second);\n\
    \      }\n    }\n  }\n\n  pair<int, T> _get(int idx, int l, int r, int xl, int\
    \ xr) {\n    assert(l < r and xl < xr);\n    assert(l <= xl and xr <= r);\n  \
    \  if (xl == l and xr == r) return val[idx];\n\n    pair<int, T> best = make_pair(-1,\
    \ inf);\n    auto chmin = [&](int x, T y) {\n      if (MINIMIZE ? y < best.second\
    \ : y > best.second) {\n        best = make_pair(x, y);\n      }\n    };\n\n \
    \   chmin(xl, eval(xl, dat[idx]));\n    chmin(xr - 1, eval(xr - 1, dat[idx]));\n\
    \n    int m = (l + r) / 2;\n    if (xl < m) {\n      auto [x, y] = _get(idx *\
    \ 2 + 0, l, m, xl, min(xr, m));\n      chmin(x, y);\n    }\n    if (m < xr) {\n\
    \      auto [x, y] = _get(idx * 2 + 1, m, r, max(xl, m), xr);\n      chmin(x,\
    \ y);\n    }\n    return best;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n// Line : T operator(ll) \u3092\u5B9A\u7FA9\u3059\u308B\
    \ntemplate <typename Line, bool MINIMIZE = true, bool RANGE_GET = false>\nstruct\
    \ LiChaoTree {\n  using T = decltype(Line{}(0));\n\n  vector<long long> xs;\n\
    \  vector<Line> dat;\n  vector<pair<int, T>> val;  // (\u8A55\u4FA1\u70B9(\u5EA7\
    \u5727\u5F8C), \u8A55\u4FA1\u3057\u305F\u5024)\n  int n, size;\n  T inf;\n\n \
    \ LiChaoTree(const vector<long long>& _xs, Line I) { init(_xs, I); }\n  LiChaoTree(int\
    \ _n, Line I) {\n    vector<long long> _xs(_n);\n    for (int i = 0; i < _n; i++)\
    \ _xs[i] = i;\n    init(_xs, I);\n  }\n\n  int get_idx(long long x) {\n    return\
    \ lower_bound(begin(xs), end(xs), x) - begin(xs);\n  }\n\n  void add_line(Line\
    \ f) { return apply(1, f); }\n\n  // [xl, xr) \u534A\u958B\n  void add_segment(long\
    \ long xl, long long xr, Line f) {\n    xl = get_idx(xl), xr = get_idx(xr);\n\
    \    if (xl == xr) return;\n    xl += size, xr += size;\n    int l = xl, r = xr;\n\
    \    for (; xl < xr; xl >>= 1, xr >>= 1) {\n      if (xl & 1) apply(xl++, f);\n\
    \      if (xr & 1) apply(--xr, f);\n    }\n    if (RANGE_GET) {\n      for (int\
    \ i = 1; i <= __builtin_ctz(size); i++) {\n        if (((l >> i) << i) != l) update(l\
    \ >> i);\n        if (((r >> i) << i) != r) update((r - 1) >> i);\n      }\n \
    \   }\n  }\n\n  // (\u5024, Line) \u306E\u7D44\n  pair<T, Line> get_val(long long\
    \ x) {\n    int i = get_idx(x);\n    assert(0 <= i and i < n);\n    Line f = dat[0];\n\
    \    T fx = f(x);\n    for (i += size; i; i >>= 1) {\n      Line g = dat[i];\n\
    \      T gx = g(x);\n      if ((MINIMIZE && gx < fx) || (!MINIMIZE && gx > fx))\
    \ {\n        f = g, fx = gx;\n      }\n    }\n    return {fx, f};\n  }\n\n  //\
    \ [xl, xr) \u534A\u958B\n  // \u8FD4\u308A\u5024 : (\u8A55\u4FA1\u70B9 x, x \u3067\
    \u8A55\u4FA1\u3057\u305F\u5024)\n  // \u8FFD\u52A0\u3059\u308B\u76F4\u7DDA\u306B\
    \u5358\u8ABF\u6027\u304C\u3042\u308B\u6642\u306E\u307F\u4F7F\u7528\u53EF\u80FD\
    \n  // RANGE_GET \u3092 true \u306B\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\n\
    \  pair<long long, T> get(long long xl, long long xr) {\n    assert(RANGE_GET\
    \ == true);\n    xl = get_idx(xl), xr = get_idx(xr);\n    assert(xl != xr);\n\
    \    pair<int, T> best = _get(1, 0, size, xl, xr);\n    assert(best.first != -1);\n\
    \    return make_pair(xs[best.first], best.second);\n  }\n\n private:\n  void\
    \ init(const vector<long long>& _xs, Line I) {\n    xs = _xs;\n    sort(begin(xs),\
    \ end(xs));\n    xs.erase(unique(begin(xs), end(xs)), end(xs));\n    n = xs.size();\n\
    \    int lg = 1;\n    while ((1 << lg) < n) lg++;\n    size = 1 << lg;\n    dat.resize(size\
    \ * 2, I);\n    inf = (MINIMIZE ? numeric_limits<T>::max() : numeric_limits<T>::min())\
    \ / 2;\n    val.resize(size * 2, make_pair(-1, inf));\n    for (int i = size *\
    \ 2 - 1; i; i--) update(i);\n  }\n\n  T eval(int i, Line f) { return f(xs[min(i,\
    \ n - 1)]); }\n\n  void apply(int i, Line f) {\n    int upper_bit = 31 - __builtin_clz(i);\n\
    \    int l = (size >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size\
    \ >> upper_bit);\n    Line g = dat[i];\n    T fl = eval(l, f), fr = eval(r - 1,\
    \ f);\n    T gl = eval(l, g), gr = eval(r - 1, g);\n    bool bl = (MINIMIZE ?\
    \ fl < gl : fl > gl);\n    bool br = (MINIMIZE ? fr < gr : fr > gr);\n    if (!bl\
    \ and !br) return;\n    if (bl and br) {\n      dat[i] = f;\n    } else {\n  \
    \    int m = (l + r) / 2;\n      T fm = eval(m, f), gm = eval(m, g);\n      bool\
    \ bm = (MINIMIZE ? fm < gm : fm > gm);\n      if (bm) {\n        dat[i] = f;\n\
    \        f = g;\n        apply(i * 2 + bl, f);\n      } else {\n        apply(i\
    \ * 2 + 1 - bl, f);\n      }\n    }\n    update(i);\n  }\n\n  void update(int\
    \ i) {\n    if constexpr (RANGE_GET) {\n      if (i == 0) return;\n      int upper_bit\
    \ = 31 - __builtin_clz(i);\n      int l = (size >> upper_bit) * (i - (1 << upper_bit));\n\
    \      int r = l + (size >> upper_bit);\n      val[i] = make_pair(-1, inf);\n\
    \      auto chmin = [&](int x, T y) {\n        if (MINIMIZE ? y < val[i].second\
    \ : val[i].second < y) {\n          val[i] = make_pair(x, y);\n        }\n   \
    \   };\n      if (l < n) {\n        chmin(l, eval(l, dat[i]));\n        chmin(min(r\
    \ - 1, n - 1), eval(r - 1, dat[i]));\n      }\n      if (i < size) {\n       \
    \ chmin(val[i * 2 + 0].first, val[i * 2 + 0].second);\n        chmin(val[i * 2\
    \ + 1].first, val[i * 2 + 1].second);\n      }\n    }\n  }\n\n  pair<int, T> _get(int\
    \ idx, int l, int r, int xl, int xr) {\n    assert(l < r and xl < xr);\n    assert(l\
    \ <= xl and xr <= r);\n    if (xl == l and xr == r) return val[idx];\n\n    pair<int,\
    \ T> best = make_pair(-1, inf);\n    auto chmin = [&](int x, T y) {\n      if\
    \ (MINIMIZE ? y < best.second : y > best.second) {\n        best = make_pair(x,\
    \ y);\n      }\n    };\n\n    chmin(xl, eval(xl, dat[idx]));\n    chmin(xr - 1,\
    \ eval(xr - 1, dat[idx]));\n\n    int m = (l + r) / 2;\n    if (xl < m) {\n  \
    \    auto [x, y] = _get(idx * 2 + 0, l, m, xl, min(xr, m));\n      chmin(x, y);\n\
    \    }\n    if (m < xr) {\n      auto [x, y] = _get(idx * 2 + 1, m, r, max(xl,\
    \ m), xr);\n      chmin(x, y);\n    }\n    return best;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/li-chao-tree-abstruct.hpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/li-chao-tree-abstruct.test.cpp
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-3.test.cpp
  - verify/verify-yosupo-math/yosupo-concave-min-plus-convolution-4.test.cpp
documentation_of: segment-tree/li-chao-tree-abstruct.hpp
layout: document
redirect_from:
- /library/segment-tree/li-chao-tree-abstruct.hpp
- /library/segment-tree/li-chao-tree-abstruct.hpp.html
title: segment-tree/li-chao-tree-abstruct.hpp
---
