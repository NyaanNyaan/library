---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-interpolation.hpp
    title: fps/polynomial-interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
    title: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-multieval.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/multipoint-evaluation.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"fps/formal-power-series.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n\
    \  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const\
    \ FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  FPS &operator*=(const mint\
    \ &v) {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n  \
    \  return *this;\n  }\n\n  FPS &operator/=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) {\n      this->clear();\n      return *this;\n    }\n    int n =\
    \ this->size() - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this),\
    \ g(r);\n      g.shrink();\n      mint coeff = g.back().inverse();\n      for\
    \ (auto &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n\
    \      int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i\
    \ >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n\n  FPS &operator%=(const FPS &r) {\n\
    \    *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  void shrink() {\n    while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n  }\n\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n\n  FPS operator>>(int sz)\
    \ const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret.erase(ret.begin(), ret.begin() + sz);\n    return ret;\n  }\n\n  FPS\
    \ operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS pow(int64_t k, int\
    \ deg = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1)\
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 6 \"fps/multipoint-evaluation.hpp\"\n\ntemplate <typename mint>\nstruct ProductTree\
    \ {\n  using fps = FormalPowerSeries<mint>;\n  const vector<mint> &xs;\n  vector<fps>\
    \ buf;\n  int N, xsz;\n  vector<int> l, r;\n  ProductTree(const vector<mint> &xs_)\
    \ : xs(xs_), xsz(xs.size()) {\n    N = 1;\n    while (N < (int)xs.size()) N *=\
    \ 2;\n    buf.resize(2 * N);\n    l.resize(2 * N, xs.size());\n    r.resize(2\
    \ * N, xs.size());\n    fps::set_fft();\n    if (fps::ntt_ptr == nullptr)\n  \
    \    build();\n    else\n      build_ntt();\n  }\n\n  void build() {\n    for\
    \ (int i = 0; i < xsz; i++) {\n      l[i + N] = i;\n      r[i + N] = i + 1;\n\
    \      buf[i + N] = {-xs[i], 1};\n    }\n    for (int i = N - 1; i > 0; i--) {\n\
    \      l[i] = l[(i << 1) | 0];\n      r[i] = r[(i << 1) | 1];\n      if (buf[(i\
    \ << 1) | 0].empty())\n        continue;\n      else if (buf[(i << 1) | 1].empty())\n\
    \        buf[i] = buf[(i << 1) | 0];\n      else\n        buf[i] = buf[(i << 1)\
    \ | 0] * buf[(i << 1) | 1];\n    }\n  }\n\n  void build_ntt() {\n    fps f;\n\
    \    f.reserve(N * 2);\n    for (int i = 0; i < xsz; i++) {\n      l[i + N] =\
    \ i;\n      r[i + N] = i + 1;\n      buf[i + N] = {-xs[i] + 1, -xs[i] - 1};\n\
    \    }\n    for (int i = N - 1; i > 0; i--) {\n      l[i] = l[(i << 1) | 0];\n\
    \      r[i] = r[(i << 1) | 1];\n      if (buf[(i << 1) | 0].empty())\n       \
    \ continue;\n      else if (buf[(i << 1) | 1].empty())\n        buf[i] = buf[(i\
    \ << 1) | 0];\n      else if (buf[(i << 1) | 0].size() == buf[(i << 1) | 1].size())\
    \ {\n        buf[i] = buf[(i << 1) | 0];\n        f.clear();\n        copy(begin(buf[(i\
    \ << 1) | 1]), end(buf[(i << 1) | 1]),\n             back_inserter(f));\n    \
    \    buf[i].ntt_doubling();\n        f.ntt_doubling();\n        for (int j = 0;\
    \ j < (int)buf[i].size(); j++) buf[i][j] *= f[j];\n      } else {\n        buf[i]\
    \ = buf[(i << 1) | 0];\n        f.clear();\n        copy(begin(buf[(i << 1) |\
    \ 1]), end(buf[(i << 1) | 1]),\n             back_inserter(f));\n        buf[i].ntt_doubling();\n\
    \        f.intt();\n        f.resize(buf[i].size(), mint(0));\n        f.ntt();\n\
    \        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];\n   \
    \   }\n    }\n    for (int i = 0; i < 2 * N; i++) {\n      buf[i].intt();\n  \
    \    buf[i].shrink();\n    }\n  }\n};\n\ntemplate <typename mint>\nvector<mint>\
    \ InnerMultipointEvaluation(const FormalPowerSeries<mint> &f,\n              \
    \                         const vector<mint> &xs,\n                          \
    \             const ProductTree<mint> &ptree) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  vector<mint> ret;\n  ret.reserve(xs.size());\n  auto rec = [&](auto self, fps\
    \ a, int idx) {\n    if (ptree.l[idx] == ptree.r[idx]) return;\n    a %= ptree.buf[idx];\n\
    \    if ((int)a.size() <= 64) {\n      for (int i = ptree.l[idx]; i < ptree.r[idx];\
    \ i++)\n        ret.push_back(a.eval(xs[i]));\n      return;\n    }\n    self(self,\
    \ a, (idx << 1) | 0);\n    self(self, a, (idx << 1) | 1);\n  };\n  rec(rec, f,\
    \ 1);\n  return ret;\n}\n\ntemplate <typename mint>\nvector<mint> MultipointEvaluation(const\
    \ FormalPowerSeries<mint> &f,\n                                  const vector<mint>\
    \ &xs) {\n  return InnerMultipointEvaluation(f, xs, ProductTree<mint>(xs));\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct ProductTree\
    \ {\n  using fps = FormalPowerSeries<mint>;\n  const vector<mint> &xs;\n  vector<fps>\
    \ buf;\n  int N, xsz;\n  vector<int> l, r;\n  ProductTree(const vector<mint> &xs_)\
    \ : xs(xs_), xsz(xs.size()) {\n    N = 1;\n    while (N < (int)xs.size()) N *=\
    \ 2;\n    buf.resize(2 * N);\n    l.resize(2 * N, xs.size());\n    r.resize(2\
    \ * N, xs.size());\n    fps::set_fft();\n    if (fps::ntt_ptr == nullptr)\n  \
    \    build();\n    else\n      build_ntt();\n  }\n\n  void build() {\n    for\
    \ (int i = 0; i < xsz; i++) {\n      l[i + N] = i;\n      r[i + N] = i + 1;\n\
    \      buf[i + N] = {-xs[i], 1};\n    }\n    for (int i = N - 1; i > 0; i--) {\n\
    \      l[i] = l[(i << 1) | 0];\n      r[i] = r[(i << 1) | 1];\n      if (buf[(i\
    \ << 1) | 0].empty())\n        continue;\n      else if (buf[(i << 1) | 1].empty())\n\
    \        buf[i] = buf[(i << 1) | 0];\n      else\n        buf[i] = buf[(i << 1)\
    \ | 0] * buf[(i << 1) | 1];\n    }\n  }\n\n  void build_ntt() {\n    fps f;\n\
    \    f.reserve(N * 2);\n    for (int i = 0; i < xsz; i++) {\n      l[i + N] =\
    \ i;\n      r[i + N] = i + 1;\n      buf[i + N] = {-xs[i] + 1, -xs[i] - 1};\n\
    \    }\n    for (int i = N - 1; i > 0; i--) {\n      l[i] = l[(i << 1) | 0];\n\
    \      r[i] = r[(i << 1) | 1];\n      if (buf[(i << 1) | 0].empty())\n       \
    \ continue;\n      else if (buf[(i << 1) | 1].empty())\n        buf[i] = buf[(i\
    \ << 1) | 0];\n      else if (buf[(i << 1) | 0].size() == buf[(i << 1) | 1].size())\
    \ {\n        buf[i] = buf[(i << 1) | 0];\n        f.clear();\n        copy(begin(buf[(i\
    \ << 1) | 1]), end(buf[(i << 1) | 1]),\n             back_inserter(f));\n    \
    \    buf[i].ntt_doubling();\n        f.ntt_doubling();\n        for (int j = 0;\
    \ j < (int)buf[i].size(); j++) buf[i][j] *= f[j];\n      } else {\n        buf[i]\
    \ = buf[(i << 1) | 0];\n        f.clear();\n        copy(begin(buf[(i << 1) |\
    \ 1]), end(buf[(i << 1) | 1]),\n             back_inserter(f));\n        buf[i].ntt_doubling();\n\
    \        f.intt();\n        f.resize(buf[i].size(), mint(0));\n        f.ntt();\n\
    \        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];\n   \
    \   }\n    }\n    for (int i = 0; i < 2 * N; i++) {\n      buf[i].intt();\n  \
    \    buf[i].shrink();\n    }\n  }\n};\n\ntemplate <typename mint>\nvector<mint>\
    \ InnerMultipointEvaluation(const FormalPowerSeries<mint> &f,\n              \
    \                         const vector<mint> &xs,\n                          \
    \             const ProductTree<mint> &ptree) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  vector<mint> ret;\n  ret.reserve(xs.size());\n  auto rec = [&](auto self, fps\
    \ a, int idx) {\n    if (ptree.l[idx] == ptree.r[idx]) return;\n    a %= ptree.buf[idx];\n\
    \    if ((int)a.size() <= 64) {\n      for (int i = ptree.l[idx]; i < ptree.r[idx];\
    \ i++)\n        ret.push_back(a.eval(xs[i]));\n      return;\n    }\n    self(self,\
    \ a, (idx << 1) | 0);\n    self(self, a, (idx << 1) | 1);\n  };\n  rec(rec, f,\
    \ 1);\n  return ret;\n}\n\ntemplate <typename mint>\nvector<mint> MultipointEvaluation(const\
    \ FormalPowerSeries<mint> &f,\n                                  const vector<mint>\
    \ &xs) {\n  return InnerMultipointEvaluation(f, xs, ProductTree<mint>(xs));\n}"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/multipoint-evaluation.hpp
  requiredBy:
  - fps/polynomial-interpolation.hpp
  timestamp: '2020-08-21 15:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-multieval.test.cpp
  - verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
documentation_of: fps/multipoint-evaluation.hpp
layout: document
redirect_from:
- /library/fps/multipoint-evaluation.hpp
- /library/fps/multipoint-evaluation.hpp.html
title: fps/multipoint-evaluation.hpp
---
