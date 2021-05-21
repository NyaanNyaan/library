---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/sample-point-shift.hpp
    title: fps/sample-point-shift.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/gauss-elimination.hpp
    title: matrix/gauss-elimination.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/linear-equation.hpp
    title: matrix/linear-equation.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-prefix-prod.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/find-p-recursive.md
    document_title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
    links: []
  bundledCode: "#line 2 \"fps/find-p-recursive.hpp\"\n\n#line 2 \"matrix/polynomial-matrix-prefix-prod.hpp\"\
    \n\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct\
    \ FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using FPS\
    \ = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if (r.size()\
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
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/sample-point-shift.hpp\"\
    \n\n#line 2 \"modulo/binomial.hpp\"\n\ntemplate <typename T>\nstruct Binomial\
    \ {\n  vector<T> f, g, h;\n  Binomial(int MAX = 0) : f(1, T(1)), g(1, T(1)), h(1,\
    \ T(1)) {\n    while (MAX >= (int)f.size()) extend();\n  }\n\n  void extend()\
    \ {\n    int n = f.size();\n    int m = n * 2;\n    f.resize(m);\n    g.resize(m);\n\
    \    h.resize(m);\n    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n \
    \   g[m - 1] = f[m - 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for\
    \ (int i = m - 2; i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i]\
    \ = g[i] * f[i - 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n\
    \    while (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int\
    \ i) {\n    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n\
    \    return g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n\
    \    while (i >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int\
    \ n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n)\
    \ * finv(n - r) * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return\
    \ C(n, r); }\n\n  T C_naive(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    T ret = T(1);\n    r = min(r, n - r);\n    for (int i = 1;\
    \ i <= r; ++i) ret *= inv(i) * (n--);\n    return ret;\n  }\n\n  T P(int n, int\
    \ r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n\
    \ - r);\n  }\n\n  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n\
    \    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 5 \"fps/sample-point-shift.hpp\"\
    \n\n// input  : h(0), h(1), ..., h(d - 1)\n// output : h(m), h(m + 1), ..., h(m\
    \ + d - 1)\ntemplate <typename mint>\nFormalPowerSeries<mint> SamplePointShift(FormalPowerSeries<mint>&\
    \ ys, mint m) {\n  static Binomial<mint> C;\n  int d = ys.size() - 1;\n  FormalPowerSeries<mint>\
    \ f(d + 1), g(d * 2 + 1);\n  for (int i = 0; i <= d; i++) {\n    f[i] = ys[i]\
    \ * C.finv(i) * C.finv(d - i);\n    if ((d - i) & 1) f[i] = -f[i];\n  }\n  for\
    \ (int i = 0; i <= 2 * d; i++) {\n    assert(m - d + i != mint(0));\n    g[i]\
    \ = (m - d + i).inverse();\n  }\n  auto h = f * g;\n  mint coeff = 1;\n  for (int\
    \ i = 0; i <= d; i++) coeff *= (m - d + i);\n  for (int i = 0; i <= d; i++) {\n\
    \    h[i + d] *= coeff;\n    coeff *= (m + i + 1) * g[i];\n  }\n  return FormalPowerSeries<mint>{begin(h)\
    \ + d, begin(h) + 2 * d + 1};\n}\n#line 2 \"matrix/matrix.hpp\"\n\ntemplate <class\
    \ T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix() = default;\n  Matrix(int\
    \ n, int m) : A(n, vector<T>(m, T())) {}\n  Matrix(int n) : A(n, vector<T>(n,\
    \ T())){};\n\n  int H() const { return A.size(); }\n\n  int W() const { return\
    \ A[0].size(); }\n\n  int size() const { return A.size(); }\n\n  inline const\
    \ vector<T> &operator[](int k) const { return A[k]; }\n\n  inline vector<T> &operator[](int\
    \ k) { return A[k]; }\n\n  static Matrix I(int n) {\n    Matrix mat(n);\n    for\
    \ (int i = 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for\
    \ (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -=\
    \ B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B)\
    \ {\n    int n = H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T>\
    \ > C(n, vector<T>(m, T{}));\n    for (int i = 0; i < n; i++)\n      for (int\
    \ k = 0; k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k\
    \ & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  bool operator==(const Matrix &B) const {\n    assert(H()\
    \ == B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int\
    \ j = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return false;\n    return\
    \ true;\n  }\n\n  bool operator!=(const Matrix &B) const {\n    assert(H() ==\
    \ B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int j\
    \ = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return true;\n    return\
    \ false;\n  }\n\n  friend ostream &operator<<(ostream &os, const Matrix &p) {\n\
    \    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n      os <<\
    \ (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++) {\n      \
    \  os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n    return\
    \ (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n    assert(H()\
    \ == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n      int idx\
    \ = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i] != 0) {\n\
    \          idx = j;\n          break;\n        }\n      }\n      if (idx == -1)\
    \ return 0;\n      if (i != idx) {\n        ret *= T(-1);\n        swap(B[i],\
    \ B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n  \
    \    for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n     \
    \ for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a ==\
    \ 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k] -=\
    \ B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n *\
    \ @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n#line 6 \"matrix/polynomial-matrix-prefix-prod.hpp\"\
    \n\n// return m(k-1) * m(k-2) * ... * m(1) * m(0)\ntemplate <typename mint>\n\
    Matrix<mint> polynomial_matrix_prod(Matrix<FormalPowerSeries<mint>> &m,\n    \
    \                                long long k) {\n  using Mat = Matrix<mint>;\n\
    \  using fps = FormalPowerSeries<mint>;\n\n  auto shift = [](vector<Mat> &G, mint\
    \ x) -> vector<Mat> {\n    int d = G.size(), n = G[0].size();\n    vector<Mat>\
    \ H(d, Mat(n));\n    for (int i = 0; i < n; i++) {\n      for (int j = 0; j <\
    \ n; j++) {\n        fps g(d);\n        for (int l = 0; l < d; l++) g[l] = G[l][i][j];\n\
    \        fps h = SamplePointShift(g, x);\n        for (int l = 0; l < d; l++)\
    \ H[l][i][j] = h[l];\n      }\n    }\n    return H;\n  };\n\n  int n = m.size();\n\
    \  int deg = 1;\n  for (auto &_ : m.A) {\n    for (auto &x : _) deg = max<int>(deg,\
    \ (int)x.size() - 1);\n  }\n  while (deg & (deg - 1)) deg++;\n\n  vector<Mat>\
    \ G(deg + 1);\n  long long v = 1;\n  while (deg * v * v < k) v *= 2;\n  mint iv\
    \ = mint(v).inverse();\n\n  for (int i = 0; i < (int)G.size(); i++) {\n    mint\
    \ x = mint(v) * i;\n    Mat mt(n);\n    for (int j = 0; j < n; j++)\n      for\
    \ (int l = 0; l < n; l++) mt[j][l] = m[j][l].eval(x);\n    G[i] = mt;\n  }\n\n\
    \  for (long long w = 1; w != v; w <<= 1) {\n    mint W = w;\n    auto G1 = shift(G,\
    \ W * iv);\n    auto G2 = shift(G, (W * deg * v + v) * iv);\n    auto G3 = shift(G,\
    \ (W * deg * v + v + W) * iv);\n    for (int i = 0; i <= w * deg; i++)\n     \
    \ G[i] = G1[i] * G[i], G2[i] = G3[i] * G2[i];\n    copy(begin(G2), end(G2) - 1,\
    \ back_inserter(G));\n  }\n\n  Mat res = Mat::I(n);\n  long long i = 0;\n  while\
    \ (i + v <= k) res = G[i / v] * res, i += v;\n  while (i < k) {\n    Mat mt(n);\n\
    \    for (int j = 0; j < n; j++)\n      for (int l = 0; l < n; l++) mt[j][l] =\
    \ m[j][l].eval(i);\n    res = mt * res;\n    i++;\n  }\n  return res;\n}\n\n/**\n\
    \ * @brief \u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product\n */\n#line 2 \"\
    matrix/linear-equation.hpp\"\n\n#line 2 \"matrix/gauss-elimination.hpp\"\n\n#line\
    \ 4 \"matrix/gauss-elimination.hpp\"\n\ntemplate <typename mint>\nstd::pair<int,\
    \ mint> GaussElimination(vector<vector<mint>> &a,\n                          \
    \            bool LE = false) {\n  int H = a.size(), W = a[0].size();\n  int rank\
    \ = 0, je = LE ? W - 1 : W;\n  mint det = 1;\n  for (int j = 0; j < je; j++) {\n\
    \    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      if (a[i][j] !=\
    \ mint(0)) {\n        idx = i;\n        break;\n      }\n    }\n    if (idx ==\
    \ -1) {\n      det = 0;\n      continue;\n    }\n    if (rank != idx) {\n    \
    \  det = -det;\n      swap(a[rank], a[idx]);\n    }\n    det *= a[rank][j];\n\
    \    if (LE && a[rank][j] != mint(1)) {\n      mint coeff = a[rank][j].inverse();\n\
    \      for (int k = j; k < W; k++) a[rank][k] *= coeff;\n    }\n    int is = LE\
    \ ? 0 : rank + 1;\n    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n\
    \      if (a[i][j] != mint(0)) {\n        mint coeff = a[i][j] / a[rank][j];\n\
    \        for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n\
    \    }\n    rank++;\n  }\n  return make_pair(rank, det);\n}\n#line 4 \"matrix/linear-equation.hpp\"\
    \n\n\ntemplate <typename mint>\nvector<vector<mint>> LinearEquation(vector<vector<mint>>\
    \ a, vector<mint> b) {\n  int H = a.size(), W = a[0].size();\n  for (int i = 0;\
    \ i < H; i++) a[i].push_back(b[i]);\n  auto p = GaussElimination(a, true);\n \
    \ int rank = p.first;\n\n  for (int i = rank; i < H; ++i) {\n    if (a[i][W] !=\
    \ 0) return vector<vector<mint>>{};\n  }\n\n  vector<vector<mint>> res(1, vector<mint>(W));\n\
    \  vector<int> pivot(W, -1);\n  for (int i = 0, j = 0; i < rank; ++i) {\n    while\
    \ (a[i][j] == 0) ++j;\n    res[0][j] = a[i][W], pivot[j] = i;\n  }\n  for (int\
    \ j = 0; j < W; ++j) {\n    if (pivot[j] == -1) {\n      vector<mint> x(W);\n\
    \      x[j] = 1;\n      for (int k = 0; k < j; ++k) {\n        if (pivot[k] !=\
    \ -1) x[k] = -a[pivot[k]][j];\n      }\n      res.push_back(x);\n    }\n  }\n\
    \  return res;\n}\n#line 6 \"fps/find-p-recursive.hpp\"\n\n// return polynomial\
    \ coefficient s.t. sum_{j=k...0} f_j(i) a_{i+j} = 0\n// (In more details, read\
    \ verification code.)\ntemplate <typename mint>\nvector<FormalPowerSeries<mint>>\
    \ find_p_recursive(vector<mint>& a, int d) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = a.size();\n  int k = (n + 2) / (d + 2) - 1;\n  if (k <= 0) return {};\n\
    \  int m = (k + 1) * (d + 1);\n  vector<vector<mint>> M(m - 1, vector<mint>(m));\n\
    \  for (int i = 0; i < m - 1; i++) {\n    for (int j = 0; j <= k; j++) {\n   \
    \   mint base = 1;\n      for (int l = 0; l <= d; l++) {\n        M[i][(d + 1)\
    \ * j + l] = base * a[i + j];\n        base *= i + j;\n      }\n    }\n  }\n \
    \ auto gauss = LinearEquation<mint>(M, vector<mint>(m - 1, 0));\n  if (gauss.size()\
    \ <= 1) return {};\n  auto c = gauss[1];\n  while (all_of(end(c) - d - 1, end(c),\
    \ [](mint x) { return x == mint(0); })) {\n    c.erase(end(c) - d - 1, end(c));\n\
    \  }\n  k = c.size() / (d + 1) - 1;\n  vector<fps> res;\n  for (int i = 0, j =\
    \ 0; i < (int)c.size(); i += d + 1, j++) {\n    fps f{1}, base{j, 1};\n    fps\
    \ sm;\n    for (int l = 0; l <= d; l++) sm += f * c[i + l], f *= base;\n    res.push_back(sm);\n\
    \  }\n  reverse(begin(res), end(res));\n  return res;\n}\n\ntemplate<typename\
    \ mint>\nmint kth_term_of_p_recursive(vector<mint>& a, long long k, int d) {\n\
    \  if (k < (int)a.size()) return a[k];\n  auto fs = find_p_recursive(a, d);\n\
    \  assert(fs.empty() == false);\n  int deg = fs.size() - 1;\n  assert(deg >= 1);\n\
    \  Matrix<FormalPowerSeries<mint>> m(deg), denom(1);\n  for (int i = 0; i < deg;\
    \ i++) m[0][i] = -fs[i + 1];\n  for (int i = 1; i < deg; i++) m[i][i - 1] = fs[0];\n\
    \  denom[0][0] = fs[0];\n  Matrix<mint> a0(deg);\n  for (int i = 0; i < deg; i++)\
    \ a0[i][0] = a[deg - 1 - i];\n  mint res = (polynomial_matrix_prod(m, k - deg\
    \ + 1) * a0)[0][0];\n  res /= polynomial_matrix_prod(denom, k - deg + 1)[0][0];\n\
    \  return res;\n}\n\n/**\n * @brief P-recursive\u306E\u9AD8\u901F\u8A08\u7B97\n\
    \ * @docs docs/fps/find-p-recursive.md\n */\n"
  code: "#pragma once\n\n#include \"../matrix/polynomial-matrix-prefix-prod.hpp\"\n\
    #include \"formal-power-series.hpp\"\n#include \"../matrix/linear-equation.hpp\"\
    \n\n// return polynomial coefficient s.t. sum_{j=k...0} f_j(i) a_{i+j} = 0\n//\
    \ (In more details, read verification code.)\ntemplate <typename mint>\nvector<FormalPowerSeries<mint>>\
    \ find_p_recursive(vector<mint>& a, int d) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = a.size();\n  int k = (n + 2) / (d + 2) - 1;\n  if (k <= 0) return {};\n\
    \  int m = (k + 1) * (d + 1);\n  vector<vector<mint>> M(m - 1, vector<mint>(m));\n\
    \  for (int i = 0; i < m - 1; i++) {\n    for (int j = 0; j <= k; j++) {\n   \
    \   mint base = 1;\n      for (int l = 0; l <= d; l++) {\n        M[i][(d + 1)\
    \ * j + l] = base * a[i + j];\n        base *= i + j;\n      }\n    }\n  }\n \
    \ auto gauss = LinearEquation<mint>(M, vector<mint>(m - 1, 0));\n  if (gauss.size()\
    \ <= 1) return {};\n  auto c = gauss[1];\n  while (all_of(end(c) - d - 1, end(c),\
    \ [](mint x) { return x == mint(0); })) {\n    c.erase(end(c) - d - 1, end(c));\n\
    \  }\n  k = c.size() / (d + 1) - 1;\n  vector<fps> res;\n  for (int i = 0, j =\
    \ 0; i < (int)c.size(); i += d + 1, j++) {\n    fps f{1}, base{j, 1};\n    fps\
    \ sm;\n    for (int l = 0; l <= d; l++) sm += f * c[i + l], f *= base;\n    res.push_back(sm);\n\
    \  }\n  reverse(begin(res), end(res));\n  return res;\n}\n\ntemplate<typename\
    \ mint>\nmint kth_term_of_p_recursive(vector<mint>& a, long long k, int d) {\n\
    \  if (k < (int)a.size()) return a[k];\n  auto fs = find_p_recursive(a, d);\n\
    \  assert(fs.empty() == false);\n  int deg = fs.size() - 1;\n  assert(deg >= 1);\n\
    \  Matrix<FormalPowerSeries<mint>> m(deg), denom(1);\n  for (int i = 0; i < deg;\
    \ i++) m[0][i] = -fs[i + 1];\n  for (int i = 1; i < deg; i++) m[i][i - 1] = fs[0];\n\
    \  denom[0][0] = fs[0];\n  Matrix<mint> a0(deg);\n  for (int i = 0; i < deg; i++)\
    \ a0[i][0] = a[deg - 1 - i];\n  mint res = (polynomial_matrix_prod(m, k - deg\
    \ + 1) * a0)[0][0];\n  res /= polynomial_matrix_prod(denom, k - deg + 1)[0][0];\n\
    \  return res;\n}\n\n/**\n * @brief P-recursive\u306E\u9AD8\u901F\u8A08\u7B97\n\
    \ * @docs docs/fps/find-p-recursive.md\n */\n"
  dependsOn:
  - matrix/polynomial-matrix-prefix-prod.hpp
  - fps/formal-power-series.hpp
  - fps/sample-point-shift.hpp
  - modulo/binomial.hpp
  - matrix/matrix.hpp
  - matrix/linear-equation.hpp
  - matrix/gauss-elimination.hpp
  isVerificationFile: false
  path: fps/find-p-recursive.hpp
  requiredBy: []
  timestamp: '2021-05-10 21:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/p-recursive.test.cpp
documentation_of: fps/find-p-recursive.hpp
layout: document
redirect_from:
- /library/fps/find-p-recursive.hpp
- /library/fps/find-p-recursive.hpp.html
title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
---
## P-recursiveの高速計算

P-recursiveの第$k$項を$\mathrm{O}(\sqrt{k} \log k)$で計算出来たり出来なかったりするライブラリ。

#### 使い方

- `find_p_recursive(a, d)`

十分長い数列$a$および次数$d$が与えられたとき、

$$a_{i+n} f_n(i) + \ldots + a_{i}f_0(i) \equiv 0 \pmod {p} $$

を満たす$d$次多項式の列$f_n(i),\ldots,f_1(i),f_0(i)$を返すライブラリ。他のライブラリとの関係上、列が降順($(f_n,\ldots,f_1,f_0)$の順番)になっているのに注意。

適切に立式すれば一次連立方程式に帰着するのでガウスの掃き出し法を使えば求まる。計算量は$\mathrm{O}((dn)^3)$程度。

- `kth_term_of_p_recursive(a, k, d)`

十分長い数列$a$および次数$d$、整数$k$が与えられたとき、$a_k$を返すライブラリ。

計算量は数列が$n$項間漸化式で表せるときに$\mathrm{O}(n^2 \sqrt{kd} (\log p + \log kd))$程度。

アルゴリズム初出の日本語記事は削除済みだが、[CF 1479E editorial](https://codeforces.com/blog/entry/87598)に関連するアルゴリズムの解説がある。

##### verification codeの出力(一部加筆)

P-recursiveの例も兼ねて貼る。

```
Constant Function
a_{k+1} = a_{k}
Identity Function (a_i = i + 1)
(k + 1)a_{k+1} = (k + 2)a_{k}
Factorial
a_{k+1} = (k + 1)a_{k}
Inversion of Factorial
(k + 1)a_{k+1} = a_{k}
Binomial (a_i = binom(i + 3, 3))
(k + 1)a_{k+1} = (k + 4)a_{k}
Montmort Number
a_{k+2} = (k + 1)a_{k+1} + (k + 1)a_{k}
Catalan Number
(k + 2)a_{k+1} = (4k + 2)a_{k}
Motzkin Number
(k + 4)a_{k+2} = (2k + 5)a_{k+1} + (3k + 3)a_{k}
Schroder number
(k + 3)a_{k+2} = (6k + 9)a_{k+1} + (998244352k + 0)a_{k}
```

#### 注意点

バグりやすい上に数列によっては正しい値を求められない。

- $d$に正しい値を指定しないと、バグる(誤った関係式を導出する)
- $i + k \leq n$について$f_{n}(i) \not \equiv 0$が必要。そうでない場合、バグる(そもそも漸化式から正しい値を求めることが不可能？)

また、P-recursiveで表せない列の第$k$項は当然求められない。

- 例えばBell Numberや$S(n,k)$は二項係数の和で表せるのでP-recursiveのような気がしてくるが(本当？)、実際は違うので高速計算できない(と思う)。