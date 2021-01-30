---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: fps/multipoint-evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':question:'
    path: fps/polynomial-interpolation.hpp
    title: fps/polynomial-interpolation.hpp
  - icon: ':question:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':x:'
    path: matrix/polynomial-matrix-determinant.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u884C\u5217\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\
      \u30F3\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"matrix/matrix-tree.hpp\"\n\n\n\n#line 2 \"matrix/matrix.hpp\"\
    \n\n\n\ntemplate <class T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix()\
    \ = default;\n  Matrix(int n, int m) : A(n, vector<T>(m, T())) {}\n  Matrix(int\
    \ n) : A(n, vector<T>(n, T())){};\n\n  int H() const { return A.size(); }\n\n\
    \  int W() const { return A[0].size(); }\n\n  int size() const { return A.size();\
    \ }\n\n  inline const vector<T> &operator[](int k) const { return A[k]; }\n\n\
    \  inline vector<T> &operator[](int k) { return A[k]; }\n\n  static Matrix I(int\
    \ n) {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++) mat[i][i] = 1;\n \
    \   return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n    int n =\
    \ H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for (int i = 0; i\
    \ < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n   \
    \ return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    int n =\
    \ H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for (int i = 0; i\
    \ < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n   \
    \ return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B) {\n    int n =\
    \ H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T> > C(n,\
    \ vector<T>(m, 0));\n    for (int i = 0; i < n; i++)\n      for (int k = 0; k\
    \ < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k] * B[k][j];\n\
    \    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long long k)\
    \ {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k & 1) B *=\
    \ *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n \
    \   return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, const Matrix\
    \ &p) {\n    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n  \
    \     os << (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++)\
    \ {\n        os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n\
    \    return (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n  \
    \  assert(H() == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n\
    \      int idx = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i]\
    \ != 0) {\n          idx = j;\n          break;\n        }\n      }\n      if\
    \ (idx == -1) return 0;\n      if (i != idx) {\n        ret *= T(-1);\n      \
    \  swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n\
    \      for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n   \
    \   for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a\
    \ == 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k]\
    \ -= B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n\
    \ * @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n#line 2 \"matrix/polynomial-matrix-determinant.hpp\"\
    \n\n\n\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\n\
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
    \   return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
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
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/polynomial-interpolation.hpp\"\
    \n\n#line 2 \"fps/multipoint-evaluation.hpp\"\n\n#line 4 \"fps/multipoint-evaluation.hpp\"\
    \n\ntemplate <typename mint>\nstruct ProductTree {\n  using fps = FormalPowerSeries<mint>;\n\
    \  const vector<mint> &xs;\n  vector<fps> buf;\n  int N, xsz;\n  vector<int> l,\
    \ r;\n  ProductTree(const vector<mint> &xs_) : xs(xs_), xsz(xs.size()) {\n   \
    \ N = 1;\n    while (N < (int)xs.size()) N *= 2;\n    buf.resize(2 * N);\n   \
    \ l.resize(2 * N, xs.size());\n    r.resize(2 * N, xs.size());\n    fps::set_fft();\n\
    \    if (fps::ntt_ptr == nullptr)\n      build();\n    else\n      build_ntt();\n\
    \  }\n\n  void build() {\n    for (int i = 0; i < xsz; i++) {\n      l[i + N]\
    \ = i;\n      r[i + N] = i + 1;\n      buf[i + N] = {-xs[i], 1};\n    }\n    for\
    \ (int i = N - 1; i > 0; i--) {\n      l[i] = l[(i << 1) | 0];\n      r[i] = r[(i\
    \ << 1) | 1];\n      if (buf[(i << 1) | 0].empty())\n        continue;\n     \
    \ else if (buf[(i << 1) | 1].empty())\n        buf[i] = buf[(i << 1) | 0];\n \
    \     else\n        buf[i] = buf[(i << 1) | 0] * buf[(i << 1) | 1];\n    }\n \
    \ }\n\n  void build_ntt() {\n    fps f;\n    f.reserve(N * 2);\n    for (int i\
    \ = 0; i < xsz; i++) {\n      l[i + N] = i;\n      r[i + N] = i + 1;\n      buf[i\
    \ + N] = {-xs[i] + 1, -xs[i] - 1};\n    }\n    for (int i = N - 1; i > 0; i--)\
    \ {\n      l[i] = l[(i << 1) | 0];\n      r[i] = r[(i << 1) | 1];\n      if (buf[(i\
    \ << 1) | 0].empty())\n        continue;\n      else if (buf[(i << 1) | 1].empty())\n\
    \        buf[i] = buf[(i << 1) | 0];\n      else if (buf[(i << 1) | 0].size()\
    \ == buf[(i << 1) | 1].size()) {\n        buf[i] = buf[(i << 1) | 0];\n      \
    \  f.clear();\n        copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]),\n\
    \             back_inserter(f));\n        buf[i].ntt_doubling();\n        f.ntt_doubling();\n\
    \        for (int j = 0; j < (int)buf[i].size(); j++) buf[i][j] *= f[j];\n   \
    \   } else {\n        buf[i] = buf[(i << 1) | 0];\n        f.clear();\n      \
    \  copy(begin(buf[(i << 1) | 1]), end(buf[(i << 1) | 1]),\n             back_inserter(f));\n\
    \        buf[i].ntt_doubling();\n        f.intt();\n        f.resize(buf[i].size(),\
    \ mint(0));\n        f.ntt();\n        for (int j = 0; j < (int)buf[i].size();\
    \ j++) buf[i][j] *= f[j];\n      }\n    }\n    for (int i = 0; i < 2 * N; i++)\
    \ {\n      buf[i].intt();\n      buf[i].shrink();\n    }\n  }\n};\n\ntemplate\
    \ <typename mint>\nvector<mint> InnerMultipointEvaluation(const FormalPowerSeries<mint>\
    \ &f,\n                                       const vector<mint> &xs,\n      \
    \                                 const ProductTree<mint> &ptree) {\n  using fps\
    \ = FormalPowerSeries<mint>;\n  vector<mint> ret;\n  ret.reserve(xs.size());\n\
    \  auto rec = [&](auto self, fps a, int idx) {\n    if (ptree.l[idx] == ptree.r[idx])\
    \ return;\n    a %= ptree.buf[idx];\n    if ((int)a.size() <= 64) {\n      for\
    \ (int i = ptree.l[idx]; i < ptree.r[idx]; i++)\n        ret.push_back(a.eval(xs[i]));\n\
    \      return;\n    }\n    self(self, a, (idx << 1) | 0);\n    self(self, a, (idx\
    \ << 1) | 1);\n  };\n  rec(rec, f, 1);\n  return ret;\n}\n\ntemplate <typename\
    \ mint>\nvector<mint> MultipointEvaluation(const FormalPowerSeries<mint> &f,\n\
    \                                  const vector<mint> &xs) {\n  return InnerMultipointEvaluation(f,\
    \ xs, ProductTree<mint>(xs));\n}\n\n/**\n * @brief Multipoint Evaluation\n */\n\
    #line 5 \"fps/polynomial-interpolation.hpp\"\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ PolynomialInterpolation(const vector<mint> &xs,\n                          \
    \                      const vector<mint> &ys) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert(xs.size() == ys.size());\n  ProductTree<mint> ptree(xs);\n  fps w =\
    \ ptree.buf[1].diff();\n  vector<mint> vs = InnerMultipointEvaluation<mint>(w,\
    \ xs, ptree);\n  auto rec = [&](auto self, int idx) -> fps {\n    if (idx >= ptree.N)\
    \ {\n      if (idx - ptree.N < (int)xs.size())\n        return {ys[idx - ptree.N]\
    \ / vs[idx - ptree.N]};\n      else\n        return {mint(1)};\n    }\n    if\
    \ (ptree.buf[idx << 1 | 0].empty())\n      return {};\n    else if (ptree.buf[idx\
    \ << 1 | 1].empty())\n      return self(self, idx << 1 | 0);\n    return self(self,\
    \ idx << 1 | 0) * ptree.buf[idx << 1 | 1] +\n           self(self, idx << 1 |\
    \ 1) * ptree.buf[idx << 1 | 0];\n  };\n  return rec(rec, 1);\n}\n#line 8 \"matrix/polynomial-matrix-determinant.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> PolynomialMatrixDeterminant(\n\
    \    const Matrix<FormalPowerSeries<mint>> &m) {\n  int N = m.size();\n  int deg\
    \ = 0;\n  for (int i = 0; i < N; ++i) deg += max<int>(1, m[i][i].size()) - 1;\n\
    \  vector<mint> xs(deg + 1);\n  vector<mint> ys(deg + 1);\n  Matrix<mint> M(N);\n\
    \  for (int x = 0; x <= deg; x++) {\n    xs[x] = x;\n    for (int i = 0; i < N;\
    \ ++i)\n      for (int j = 0; j < N; ++j) M[i][j] = m[i][j].eval(x);\n    ys[x]\
    \ = M.determinant();\n  }\n  return PolynomialInterpolation<mint>(xs, ys);\n}\n\
    \n/**\n * @brief \u591A\u9805\u5F0F\u884C\u5217\u306E\u884C\u5217\u5F0F\n * @docs\
    \ docs/matrix/polynomial-matrix-determinant.md\n */\n#line 7 \"matrix/matrix-tree.hpp\"\
    \n\ntemplate <typename T>\nstruct MatrixTree {\n  int n;\n  Matrix<T> m;\n  MatrixTree(int\
    \ _n) : n(_n), m(_n) { assert(n > 0); }\n\n  void add(int i, int j, const T& x)\
    \ {\n    if (i < n) m[i][i] += x;\n    if (j < n) m[j][j] += x;\n    if (i < n\
    \ and j < n) {\n      m[i][j] -= x;\n      m[j][i] -= x;\n    }\n  }\n\n  Matrix<T>\
    \ get() const { return m; }\n\n  template <typename U, typename = void>\n  struct\
    \ has_value_type : false_type {};\n  template <typename U>\n  struct has_value_type<\n\
    \      U, typename conditional<false, typename U::value_type, void>::type>\n \
    \     : true_type {};\n\n  template <typename U = T,\n            enable_if_t<has_value_type<U>::value,\
    \ nullptr_t> = nullptr>\n  T calc() {\n    return PolynomialMatrixDeterminant(m);\n\
    \  }\n  template <typename U = T,\n            enable_if_t<!has_value_type<U>::value,\
    \ nullptr_t> = nullptr>\n  T calc() {\n    return m.determinant();\n  }\n};\n\n\
    /**\n * @brief \u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\
    \u884C\u5217)\n */\n"
  code: "#pragma once\n\n\n\n#include \"matrix.hpp\"\n#include \"polynomial-matrix-determinant.hpp\"\
    \n\ntemplate <typename T>\nstruct MatrixTree {\n  int n;\n  Matrix<T> m;\n  MatrixTree(int\
    \ _n) : n(_n), m(_n) { assert(n > 0); }\n\n  void add(int i, int j, const T& x)\
    \ {\n    if (i < n) m[i][i] += x;\n    if (j < n) m[j][j] += x;\n    if (i < n\
    \ and j < n) {\n      m[i][j] -= x;\n      m[j][i] -= x;\n    }\n  }\n\n  Matrix<T>\
    \ get() const { return m; }\n\n  template <typename U, typename = void>\n  struct\
    \ has_value_type : false_type {};\n  template <typename U>\n  struct has_value_type<\n\
    \      U, typename conditional<false, typename U::value_type, void>::type>\n \
    \     : true_type {};\n\n  template <typename U = T,\n            enable_if_t<has_value_type<U>::value,\
    \ nullptr_t> = nullptr>\n  T calc() {\n    return PolynomialMatrixDeterminant(m);\n\
    \  }\n  template <typename U = T,\n            enable_if_t<!has_value_type<U>::value,\
    \ nullptr_t> = nullptr>\n  T calc() {\n    return m.determinant();\n  }\n};\n\n\
    /**\n * @brief \u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\
    \u884C\u5217)\n */\n"
  dependsOn:
  - matrix/matrix.hpp
  - matrix/polynomial-matrix-determinant.hpp
  - fps/formal-power-series.hpp
  - fps/polynomial-interpolation.hpp
  - fps/multipoint-evaluation.hpp
  isVerificationFile: false
  path: matrix/matrix-tree.hpp
  requiredBy: []
  timestamp: '2021-01-31 00:21:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1303.test.cpp
documentation_of: matrix/matrix-tree.hpp
layout: document
redirect_from:
- /library/matrix/matrix-tree.hpp
- /library/matrix/matrix-tree.hpp.html
title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\u884C\u5217\
  )"
---
