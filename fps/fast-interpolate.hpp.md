---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-polynomial-interpolation-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-polynomial-interpolation-fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/hos-lyric/libra/blob/master/algebra/poly_998244353.cpp
  bundledCode: "#line 2 \"fps/fast-interpolate.hpp\"\n\n#include <vector>\nusing namespace\
    \ std;\n\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\n\
    struct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using\
    \ FPS = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n    return *this;\n  }\n\n  FPS &operator+=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] += r;\n\
    \    return *this;\n  }\n\n  FPS &operator-=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n  FPS &operator-=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] -= r;\n\
    \    return *this;\n  }\n\n  FPS &operator*=(const mint &v) {\n    for (int k\
    \ = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return *this;\n  }\n\n\
    \  FPS &operator/=(const FPS &r) {\n    if (this->size() < r.size()) {\n     \
    \ this->clear();\n      return *this;\n    }\n    int n = this->size() - r.size()\
    \ + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n      g.shrink();\n\
    \      mint coeff = g.back().inverse();\n      for (auto &x : g) x *= coeff;\n\
    \      int deg = (int)f.size() - (int)g.size() + 1;\n      int gs = g.size();\n\
    \      FPS quo(deg);\n      for (int i = deg - 1; i >= 0; i--) {\n        quo[i]\
    \ = f[i + gs - 1];\n        for (int j = 0; j < gs; j++) f[i + j] -= quo[i] *\
    \ g[j];\n      }\n      *this = quo * coeff;\n      this->resize(n, mint(0));\n\
    \      return *this;\n    }\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \  }\n\n  FPS &operator%=(const FPS &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  FPS operator+(const FPS &r) const { return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint &v) const { return FPS(*this) += v; }\n\
    \  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint &v) const { return FPS(*this) -= v; }\n  FPS operator*(const FPS &r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator*(const mint &v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n \
    \ FPS operator%(const FPS &r) const { return FPS(*this) %= r; }\n  FPS operator-()\
    \ const {\n    FPS ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == mint(0)) this->pop_back();\n  }\n\n  FPS rev()\
    \ const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\u3059\u308B\
    \n  FPS pre(int sz) const {\n    FPS ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n    return ret;\n  }\n\
    \n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n\
    \    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert(!(*this).empty()\
    \ && (*this)[0] == mint(1));\n    if (deg == -1) deg = (int)this->size();\n  \
    \  return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS\
    \ pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n\
    \        FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret\
    \ *= (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if\
    \ ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return ret;\n   \
    \   }\n      if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \ }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void\
    \ set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n\n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n\
    \ */\n#line 7 \"fps/fast-interpolate.hpp\"\n\n// https://github.com/hos-lyric/libra/blob/master/algebra/poly_998244353.cpp\n\
    // \u306E\u591A\u9805\u5F0F\u88DC\u9593\u3092\u624B\u5143\u3067\u52D5\u304F\u3088\
    \u3046\u306B\u6539\u9020\n// xs \u304C distinct \u3058\u3083\u306A\u3044\u3068\
    \u58CA\u308C\u308B\ntemplate <typename mint>\nstruct SubproductTree {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int logN, n, nn;\n  vector<mint> xs;\n  vector<mint>\
    \ buf;\n  vector<mint *> gss;\n  fps all, roots;\n\n  void ntt(mint *a, int s)\
    \ const {\n    static fps buf2;\n    buf2.resize(s);\n    copy(a, a + s, buf2.data());\n\
    \    buf2.ntt();\n    copy(buf2.data(), buf2.data() + s, a);\n  }\n  void intt(mint\
    \ *a, int s) const {\n    static fps buf2;\n    buf2.resize(s);\n    copy(a, a\
    \ + s, buf2.data());\n    buf2.intt();\n    copy(buf2.data(), buf2.data() + s,\
    \ a);\n  }\n\n  SubproductTree(const vector<mint> &xs_) {\n    n = xs_.size();\n\
    \    for (logN = 0, nn = 1; nn < n; ++logN, nn <<= 1) {\n    }\n    roots.resize(logN\
    \ + 1);\n    for (int i = 0; i <= logN; i++) {\n      int mod = mint::get_mod();\n\
    \      roots[i] = mint{fps::ntt_pr()}.pow((mod - 1) >> i);\n    }\n    xs.assign(nn,\
    \ 0U);\n    memcpy(xs.data(), xs_.data(), n * sizeof(mint));\n    buf.assign((logN\
    \ + 1) * (nn << 1), 0U);\n    gss.assign(nn << 1, nullptr);\n    for (int h =\
    \ 0; h <= logN; ++h)\n      for (int u = 1 << h; u < 1 << (h + 1); ++u) {\n  \
    \      gss[u] =\n            buf.data() + (h * (nn << 1) + ((u - (1 << h)) <<\
    \ (logN - h + 1)));\n      }\n    for (int i = 0; i < nn; ++i) {\n      gss[nn\
    \ + i][0] = -xs[i] + 1;\n      gss[nn + i][1] = -xs[i] - 1;\n    }\n    if (nn\
    \ == 1) gss[1][1] += 2;\n    for (int h = logN; --h >= 0;) {\n      const int\
    \ m = 1 << (logN - h);\n      for (int u = 1 << (h + 1); --u >= 1 << h;) {\n \
    \       for (int i = 0; i < m; ++i)\n          gss[u][i] = gss[u << 1][i] * gss[u\
    \ << 1 | 1][i];\n        memcpy(gss[u] + m, gss[u], m * sizeof(mint));\n     \
    \   intt(gss[u] + m, m);\n        if (h > 0) {\n          gss[u][m] -= 2;\n  \
    \        const mint a = roots[logN - h + 1];\n          mint aa = 1;\n       \
    \   for (int i = m; i < m << 1; ++i) {\n            gss[u][i] *= aa;\n       \
    \     aa *= a;\n          };\n          ntt(gss[u] + m, m);\n        }\n     \
    \ }\n    }\n    all.resize(nn + 1);\n    all[0] = 1;\n    for (int i = 1; i <\
    \ nn; ++i) all[i] = gss[1][nn + nn - i];\n    all[nn] = gss[1][nn] - 1;\n  }\n\
    \  vector<mint> multiEval(const fps &fs) const {\n    vector<mint> work0(nn),\
    \ work1(nn), work2(nn);\n    {\n      const int m = max<int>(fs.size(), 1);\n\
    \      auto invAll = all.inv(m);\n      std::reverse(invAll.begin(), invAll.end());\n\
    \      int mm;\n      for (mm = 1; mm < m - 1 + nn; mm <<= 1) {\n      }\n   \
    \   invAll.resize(mm, 0U);\n      ntt(invAll.data(), invAll.size());\n      vector<mint>\
    \ ffs(mm, 0U);\n      memcpy(ffs.data(), fs.data(), fs.size() * sizeof(mint));\n\
    \      ntt(ffs.data(), ffs.size());\n      for (int i = 0; i < mm; ++i) ffs[i]\
    \ *= invAll[i];\n      intt(ffs.data(), ffs.size());\n      memcpy(((logN & 1)\
    \ ? work1 : work0).data(), ffs.data() + m - 1,\n             nn * sizeof(mint));\n\
    \    }\n    for (int h = 0; h < logN; ++h) {\n      const int m = 1 << (logN -\
    \ h);\n      for (int u = 1 << h; u < 1 << (h + 1); ++u) {\n        mint *hs =\
    \ (((logN - h) & 1) ? work1 : work0).data() +\n                   ((u - (1 <<\
    \ h)) << (logN - h));\n        mint *hs0 = (((logN - h) & 1) ? work0 : work1).data()\
    \ +\n                    ((u - (1 << h)) << (logN - h));\n        mint *hs1 =\
    \ hs0 + (m >> 1);\n        ntt(hs, m);\n        for (int i = 0; i < m; ++i) work2[i]\
    \ = gss[u << 1 | 1][i] * hs[i];\n        intt(work2.data(), m);\n        memcpy(hs0,\
    \ work2.data() + (m >> 1), (m >> 1) * sizeof(mint));\n        for (int i = 0;\
    \ i < m; ++i) work2[i] = gss[u << 1][i] * hs[i];\n        intt(work2.data(), m);\n\
    \        memcpy(hs1, work2.data() + (m >> 1), (m >> 1) * sizeof(mint));\n    \
    \  }\n    }\n    work0.resize(n);\n    return work0;\n  }\n\n  fps interpolate(const\
    \ vector<mint> &ys) const {\n    assert(static_cast<int>(ys.size()) == n);\n \
    \   fps gs(n);\n    for (int i = 0; i < n; ++i) gs[i] = all[n - (i + 1)] * (i\
    \ + 1);\n    const vector<mint> denoms = multiEval(gs);\n    vector<mint> work(nn\
    \ << 1, 0U);\n    for (int i = 0; i < n; ++i) {\n      assert(denoms[i] != 0);\n\
    \      work[i << 1] = work[i << 1 | 1] = ys[i] / denoms[i];\n    }\n    for (int\
    \ h = logN; --h >= 0;) {\n      const int m = 1 << (logN - h);\n      for (int\
    \ u = 1 << (h + 1); --u >= 1 << h;) {\n        mint *hs = work.data() + ((u -\
    \ (1 << h)) << (logN - h + 1));\n        for (int i = 0; i < m; ++i)\n       \
    \   hs[i] = gss[u << 1 | 1][i] * hs[i] + gss[u << 1][i] * hs[m + i];\n       \
    \ if (h > 0) {\n          memcpy(hs + m, hs, m * sizeof(mint));\n          intt(hs\
    \ + m, m);\n          const mint a = roots[logN - h + 1];\n          mint aa =\
    \ 1;\n          for (int i = m; i < m << 1; ++i) {\n            hs[i] *= aa;\n\
    \            aa *= a;\n          };\n          ntt(hs + m, m);\n        }\n  \
    \    }\n    }\n    intt(work.data(), nn);\n    return {work.data() + nn - n, work.data()\
    \ + nn};\n  }\n};\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\n#include \"formal-power-series.hpp\"\
    \n\n// https://github.com/hos-lyric/libra/blob/master/algebra/poly_998244353.cpp\n\
    // \u306E\u591A\u9805\u5F0F\u88DC\u9593\u3092\u624B\u5143\u3067\u52D5\u304F\u3088\
    \u3046\u306B\u6539\u9020\n// xs \u304C distinct \u3058\u3083\u306A\u3044\u3068\
    \u58CA\u308C\u308B\ntemplate <typename mint>\nstruct SubproductTree {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int logN, n, nn;\n  vector<mint> xs;\n  vector<mint>\
    \ buf;\n  vector<mint *> gss;\n  fps all, roots;\n\n  void ntt(mint *a, int s)\
    \ const {\n    static fps buf2;\n    buf2.resize(s);\n    copy(a, a + s, buf2.data());\n\
    \    buf2.ntt();\n    copy(buf2.data(), buf2.data() + s, a);\n  }\n  void intt(mint\
    \ *a, int s) const {\n    static fps buf2;\n    buf2.resize(s);\n    copy(a, a\
    \ + s, buf2.data());\n    buf2.intt();\n    copy(buf2.data(), buf2.data() + s,\
    \ a);\n  }\n\n  SubproductTree(const vector<mint> &xs_) {\n    n = xs_.size();\n\
    \    for (logN = 0, nn = 1; nn < n; ++logN, nn <<= 1) {\n    }\n    roots.resize(logN\
    \ + 1);\n    for (int i = 0; i <= logN; i++) {\n      int mod = mint::get_mod();\n\
    \      roots[i] = mint{fps::ntt_pr()}.pow((mod - 1) >> i);\n    }\n    xs.assign(nn,\
    \ 0U);\n    memcpy(xs.data(), xs_.data(), n * sizeof(mint));\n    buf.assign((logN\
    \ + 1) * (nn << 1), 0U);\n    gss.assign(nn << 1, nullptr);\n    for (int h =\
    \ 0; h <= logN; ++h)\n      for (int u = 1 << h; u < 1 << (h + 1); ++u) {\n  \
    \      gss[u] =\n            buf.data() + (h * (nn << 1) + ((u - (1 << h)) <<\
    \ (logN - h + 1)));\n      }\n    for (int i = 0; i < nn; ++i) {\n      gss[nn\
    \ + i][0] = -xs[i] + 1;\n      gss[nn + i][1] = -xs[i] - 1;\n    }\n    if (nn\
    \ == 1) gss[1][1] += 2;\n    for (int h = logN; --h >= 0;) {\n      const int\
    \ m = 1 << (logN - h);\n      for (int u = 1 << (h + 1); --u >= 1 << h;) {\n \
    \       for (int i = 0; i < m; ++i)\n          gss[u][i] = gss[u << 1][i] * gss[u\
    \ << 1 | 1][i];\n        memcpy(gss[u] + m, gss[u], m * sizeof(mint));\n     \
    \   intt(gss[u] + m, m);\n        if (h > 0) {\n          gss[u][m] -= 2;\n  \
    \        const mint a = roots[logN - h + 1];\n          mint aa = 1;\n       \
    \   for (int i = m; i < m << 1; ++i) {\n            gss[u][i] *= aa;\n       \
    \     aa *= a;\n          };\n          ntt(gss[u] + m, m);\n        }\n     \
    \ }\n    }\n    all.resize(nn + 1);\n    all[0] = 1;\n    for (int i = 1; i <\
    \ nn; ++i) all[i] = gss[1][nn + nn - i];\n    all[nn] = gss[1][nn] - 1;\n  }\n\
    \  vector<mint> multiEval(const fps &fs) const {\n    vector<mint> work0(nn),\
    \ work1(nn), work2(nn);\n    {\n      const int m = max<int>(fs.size(), 1);\n\
    \      auto invAll = all.inv(m);\n      std::reverse(invAll.begin(), invAll.end());\n\
    \      int mm;\n      for (mm = 1; mm < m - 1 + nn; mm <<= 1) {\n      }\n   \
    \   invAll.resize(mm, 0U);\n      ntt(invAll.data(), invAll.size());\n      vector<mint>\
    \ ffs(mm, 0U);\n      memcpy(ffs.data(), fs.data(), fs.size() * sizeof(mint));\n\
    \      ntt(ffs.data(), ffs.size());\n      for (int i = 0; i < mm; ++i) ffs[i]\
    \ *= invAll[i];\n      intt(ffs.data(), ffs.size());\n      memcpy(((logN & 1)\
    \ ? work1 : work0).data(), ffs.data() + m - 1,\n             nn * sizeof(mint));\n\
    \    }\n    for (int h = 0; h < logN; ++h) {\n      const int m = 1 << (logN -\
    \ h);\n      for (int u = 1 << h; u < 1 << (h + 1); ++u) {\n        mint *hs =\
    \ (((logN - h) & 1) ? work1 : work0).data() +\n                   ((u - (1 <<\
    \ h)) << (logN - h));\n        mint *hs0 = (((logN - h) & 1) ? work0 : work1).data()\
    \ +\n                    ((u - (1 << h)) << (logN - h));\n        mint *hs1 =\
    \ hs0 + (m >> 1);\n        ntt(hs, m);\n        for (int i = 0; i < m; ++i) work2[i]\
    \ = gss[u << 1 | 1][i] * hs[i];\n        intt(work2.data(), m);\n        memcpy(hs0,\
    \ work2.data() + (m >> 1), (m >> 1) * sizeof(mint));\n        for (int i = 0;\
    \ i < m; ++i) work2[i] = gss[u << 1][i] * hs[i];\n        intt(work2.data(), m);\n\
    \        memcpy(hs1, work2.data() + (m >> 1), (m >> 1) * sizeof(mint));\n    \
    \  }\n    }\n    work0.resize(n);\n    return work0;\n  }\n\n  fps interpolate(const\
    \ vector<mint> &ys) const {\n    assert(static_cast<int>(ys.size()) == n);\n \
    \   fps gs(n);\n    for (int i = 0; i < n; ++i) gs[i] = all[n - (i + 1)] * (i\
    \ + 1);\n    const vector<mint> denoms = multiEval(gs);\n    vector<mint> work(nn\
    \ << 1, 0U);\n    for (int i = 0; i < n; ++i) {\n      assert(denoms[i] != 0);\n\
    \      work[i << 1] = work[i << 1 | 1] = ys[i] / denoms[i];\n    }\n    for (int\
    \ h = logN; --h >= 0;) {\n      const int m = 1 << (logN - h);\n      for (int\
    \ u = 1 << (h + 1); --u >= 1 << h;) {\n        mint *hs = work.data() + ((u -\
    \ (1 << h)) << (logN - h + 1));\n        for (int i = 0; i < m; ++i)\n       \
    \   hs[i] = gss[u << 1 | 1][i] * hs[i] + gss[u << 1][i] * hs[m + i];\n       \
    \ if (h > 0) {\n          memcpy(hs + m, hs, m * sizeof(mint));\n          intt(hs\
    \ + m, m);\n          const mint a = roots[logN - h + 1];\n          mint aa =\
    \ 1;\n          for (int i = m; i < m << 1; ++i) {\n            hs[i] *= aa;\n\
    \            aa *= a;\n          };\n          ntt(hs + m, m);\n        }\n  \
    \    }\n    }\n    intt(work.data(), nn);\n    return {work.data() + nn - n, work.data()\
    \ + nn};\n  }\n};\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fast-interpolate.hpp
  requiredBy: []
  timestamp: '2024-05-04 00:10:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-polynomial-interpolation-fast.test.cpp
documentation_of: fps/fast-interpolate.hpp
layout: document
redirect_from:
- /library/fps/fast-interpolate.hpp
- /library/fps/fast-interpolate.hpp.html
title: fps/fast-interpolate.hpp
---
