---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: matrix/inverse-matrix.hpp
    title: matrix/inverse-matrix.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
    title: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
    title: verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1533.test.cpp
    title: verify/verify-yuki/yuki-1533.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product"
    links: []
  bundledCode: "#line 2 \"matrix/polynomial-matrix-prefix-prod.hpp\"\n\n#line 2 \"\
    fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \n  FPS &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
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
    \ * r[i];\n    return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\
    \u304F\u308B\u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\
    \u3059\u308B\n  FPS pre(int sz) const {\n    FPS ret(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n\
    \    return ret;\n  }\n\n  FPS operator>>(int sz) const {\n    if ((int)this->size()\
    \ <= sz) return {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    return ret;\n  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n\
    \    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n  }\n\n  FPS diff()\
    \ const {\n    const int n = (int)this->size();\n    FPS ret(max(0, n - 1));\n\
    \    mint one(1), coeff(1);\n    for (int i = 1; i < n; i++) {\n      ret[i -\
    \ 1] = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return ret;\n  }\n\
    \n  FPS integral() const {\n    const int n = (int)this->size();\n    FPS ret(n\
    \ + 1);\n    ret[0] = mint(0);\n    if (n > 0) ret[1] = mint(1);\n    auto mod\
    \ = mint::get_mod();\n    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i])\
    \ * (mod / i);\n    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n  \
    \  return ret;\n  }\n\n  mint eval(mint x) const {\n    mint r = 0, w = 1;\n \
    \   for (auto &v : *this) r += w * v, w *= x;\n    return r;\n  }\n\n  FPS log(int\
    \ deg = -1) const {\n    assert(!(*this).empty() && (*this)[0] == mint(1));\n\
    \    if (deg == -1) deg = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n\n  FPS pow(int64_t k, int deg = -1) const {\n    const\
    \ int n = (int)this->size();\n    if (deg == -1) deg = n;\n    if (k == 0) {\n\
    \      FPS ret(deg);\n      if (deg) ret[0] = 1;\n      return ret;\n    }\n \
    \   for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0)) {\n      \
    \  mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n        ret = (ret << (i\
    \ * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \        return ret;\n      }\n      if (__int128_t(i + 1) * k >= deg) return\
    \ FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void\
    \ *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void\
    \ ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS\
    \ inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename\
    \ mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\
    \u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\
    \n * @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/sample-point-shift.hpp\"\
    \n\n#line 2 \"modulo/binomial.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306E MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\
    \u6295\u3052\u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\
    \u500D\u901F\u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\
    \u524D\u8A08\u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\
    \u5BFE\u7B56\u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T>\
    \ f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 5 \"fps/sample-point-shift.hpp\"\n\n\
    // input : y(0), y(1), ..., y(n - 1)\n// output : y(t), y(t + 1), ..., y(t + m\
    \ - 1)\n// (if m is default, m = n)\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ SamplePointShift(FormalPowerSeries<mint>& y, mint t,\n                     \
    \                    int m = -1) {\n  if (m == -1) m = y.size();\n  long long\
    \ T = t.get();\n  int k = (int)y.size() - 1;\n  T %= mint::get_mod();\n  if (T\
    \ <= k) {\n    FormalPowerSeries<mint> ret(m);\n    int ptr = 0;\n    for (int64_t\
    \ i = T; i <= k and ptr < m; i++) {\n      ret[ptr++] = y[i];\n    }\n    if (k\
    \ + 1 < T + m) {\n      auto suf = SamplePointShift<mint>(y, k + 1, m - ptr);\n\
    \      for (int i = k + 1; i < T + m; i++) {\n        ret[ptr++] = suf[i - (k\
    \ + 1)];\n      }\n    }\n    return ret;\n  }\n  if (T + m > mint::get_mod())\
    \ {\n    auto pref = SamplePointShift<mint>(y, T, mint::get_mod() - T);\n    auto\
    \ suf = SamplePointShift<mint>(y, 0, m - pref.size());\n    copy(begin(suf), end(suf),\
    \ back_inserter(pref));\n    return pref;\n  }\n\n  FormalPowerSeries<mint> finv(k\
    \ + 1, 1), d(k + 1);\n  for (int i = 2; i <= k; i++) finv[k] *= i;\n  finv[k]\
    \ = mint(1) / finv[k];\n  for (int i = k; i >= 1; i--) finv[i - 1] = finv[i] *\
    \ i;\n  for (int i = 0; i <= k; i++) {\n    d[i] = finv[i] * finv[k - i] * y[i];\n\
    \    if ((k - i) & 1) d[i] = -d[i];\n  }\n\n  FormalPowerSeries<mint> h(m + k);\n\
    \  for (int i = 0; i < m + k; i++) {\n    h[i] = mint(1) / (T - k + i);\n  }\n\
    \n  auto dh = d * h;\n\n  FormalPowerSeries<mint> ret(m);\n  mint cur = T;\n \
    \ for (int i = 1; i <= k; i++) cur *= T - i;\n  for (int i = 0; i < m; i++) {\n\
    \    ret[i] = cur * dh[k + i];\n    cur *= T + i + 1;\n    cur *= h[i];\n  }\n\
    \  return ret;\n}\n#line 2 \"matrix/matrix.hpp\"\n\n#line 2 \"matrix/inverse-matrix.hpp\"\
    \n\n#line 2 \"matrix/gauss-elimination.hpp\"\n\n#include <utility>\n#line 5 \"\
    matrix/gauss-elimination.hpp\"\nusing namespace std;\n\n// {rank, det(\u975E\u6B63\
    \u65B9\u884C\u5217\u306E\u5834\u5408\u306F\u672A\u5B9A\u7FA9)} \u3092\u8FD4\u3059\
    \n// \u578B\u304C double \u3084 Rational \u3067\u3082\u52D5\u304F\u306F\u305A\uFF1F\
    (\u672A\u691C\u8A3C)\n//\n// pivot \u5019\u88DC : [0, pivot_end)\ntemplate <typename\
    \ T>\nstd::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end =\
    \ -1,\n                                   bool diagonalize = false) {\n  int H\
    \ = a.size(), W = a[0].size(), rank = 0;\n  if (pivot_end == -1) pivot_end = W;\n\
    \  T det = 1;\n  for (int j = 0; j < pivot_end; j++) {\n    int idx = -1;\n  \
    \  for (int i = rank; i < H; i++) {\n      if (a[i][j] != T(0)) {\n        idx\
    \ = i;\n        break;\n      }\n    }\n    if (idx == -1) {\n      det = 0;\n\
    \      continue;\n    }\n    if (rank != idx) det = -det, swap(a[rank], a[idx]);\n\
    \    det *= a[rank][j];\n    if (diagonalize && a[rank][j] != T(1)) {\n      T\
    \ coeff = T(1) / a[rank][j];\n      for (int k = j; k < W; k++) a[rank][k] *=\
    \ coeff;\n    }\n    int is = diagonalize ? 0 : rank + 1;\n    for (int i = is;\
    \ i < H; i++) {\n      if (i == rank) continue;\n      if (a[i][j] != T(0)) {\n\
    \        T coeff = a[i][j] / a[rank][j];\n        for (int k = j; k < W; k++)\
    \ a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n    rank++;\n  }\n  return make_pair(rank,\
    \ det);\n}\n#line 4 \"matrix/inverse-matrix.hpp\"\n\ntemplate <typename mint>\n\
    vector<vector<mint>> inverse_matrix(const vector<vector<mint>>& a) {\n  int N\
    \ = a.size();\n  assert(N > 0);\n  assert(N == (int)a[0].size());\n\n  vector<vector<mint>>\
    \ m(N, vector<mint>(2 * N));\n  for (int i = 0; i < N; i++) {\n    copy(begin(a[i]),\
    \ end(a[i]), begin(m[i]));\n    m[i][N + i] = 1;\n  }\n\n  auto [rank, det] =\
    \ GaussElimination(m, N, true);\n  if (rank != N) return {};\n\n  vector<vector<mint>>\
    \ b(N);\n  for (int i = 0; i < N; i++) {\n    copy(begin(m[i]) + N, end(m[i]),\
    \ back_inserter(b[i]));\n  }\n  return b;\n}\n#line 4 \"matrix/matrix.hpp\"\n\n\
    template <class T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix() = default;\n\
    \  Matrix(int n, int m) : A(n, vector<T>(m, T())) {}\n  Matrix(int n) : A(n, vector<T>(n,\
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
    \ false;\n  }\n\n  Matrix inverse() const {\n    assert(H() == W());\n    Matrix\
    \ B(H());\n    B.A = inverse_matrix(A);\n    return B;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const Matrix &p) {\n    int n = p.H(), m = p.W();\n\
    \    for (int i = 0; i < n; i++) {\n      os << (i ? \"   \" : \"\") << \"[\"\
    ;\n      for (int j = 0; j < m; j++) {\n        os << p[i][j] << (j + 1 == m ?\
    \ \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\n  T determinant()\
    \ const {\n    Matrix B(*this);\n    assert(H() == W());\n    T ret = 1;\n   \
    \ for (int i = 0; i < H(); i++) {\n      int idx = -1;\n      for (int j = i;\
    \ j < W(); j++) {\n        if (B[j][i] != 0) {\n          idx = j;\n         \
    \ break;\n        }\n      }\n      if (idx == -1) return 0;\n      if (i != idx)\
    \ {\n        ret *= T(-1);\n        swap(B[i], B[idx]);\n      }\n      ret *=\
    \ B[i][i];\n      T inv = T(1) / B[i][i];\n      for (int j = 0; j < W(); j++)\
    \ {\n        B[i][j] *= inv;\n      }\n      for (int j = i + 1; j < H(); j++)\
    \ {\n        T a = B[j][i];\n        if (a == 0) continue;\n        for (int k\
    \ = i; k < W(); k++) {\n          B[j][k] -= B[i][k] * a;\n        }\n      }\n\
    \    }\n    return ret;\n  }\n};\n\n/**\n * @brief \u884C\u5217\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n */\n#line 6 \"matrix/polynomial-matrix-prefix-prod.hpp\"\n\n//\
    \ return m(k-1) * m(k-2) * ... * m(1) * m(0)\ntemplate <typename mint>\nMatrix<mint>\
    \ polynomial_matrix_prod(Matrix<FormalPowerSeries<mint>> &m,\n               \
    \                     long long k) {\n  using Mat = Matrix<mint>;\n  using fps\
    \ = FormalPowerSeries<mint>;\n\n  auto shift = [](vector<Mat> &G, mint x) -> vector<Mat>\
    \ {\n    int d = G.size(), n = G[0].size();\n    vector<Mat> H(d, Mat(n));\n \
    \   for (int i = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n     \
    \   fps g(d);\n        for (int l = 0; l < d; l++) g[l] = G[l][i][j];\n      \
    \  fps h = SamplePointShift(g, x);\n        for (int l = 0; l < d; l++) H[l][i][j]\
    \ = h[l];\n      }\n    }\n    return H;\n  };\n\n  int n = m.size();\n  int deg\
    \ = 1;\n  for (auto &_ : m.A) {\n    for (auto &x : _) deg = max<int>(deg, (int)x.size()\
    \ - 1);\n  }\n  while (deg & (deg - 1)) deg++;\n\n  vector<Mat> G(deg + 1);\n\
    \  long long v = 1;\n  while (deg * v * v < k) v *= 2;\n  mint iv = mint(v).inverse();\n\
    \n  for (int i = 0; i < (int)G.size(); i++) {\n    mint x = mint(v) * i;\n   \
    \ Mat mt(n);\n    for (int j = 0; j < n; j++)\n      for (int l = 0; l < n; l++)\
    \ mt[j][l] = m[j][l].eval(x);\n    G[i] = mt;\n  }\n\n  for (long long w = 1;\
    \ w != v; w <<= 1) {\n    mint W = w;\n    auto G1 = shift(G, W * iv);\n    auto\
    \ G2 = shift(G, (W * deg * v + v) * iv);\n    auto G3 = shift(G, (W * deg * v\
    \ + v + W) * iv);\n    for (int i = 0; i <= w * deg; i++)\n      G[i] = G1[i]\
    \ * G[i], G2[i] = G3[i] * G2[i];\n    copy(begin(G2), end(G2) - 1, back_inserter(G));\n\
    \  }\n\n  Mat res = Mat::I(n);\n  long long i = 0;\n  while (i + v <= k) res =\
    \ G[i / v] * res, i += v;\n  while (i < k) {\n    Mat mt(n);\n    for (int j =\
    \ 0; j < n; j++)\n      for (int l = 0; l < n; l++) mt[j][l] = m[j][l].eval(i);\n\
    \    res = mt * res;\n    i++;\n  }\n  return res;\n}\n\n/**\n * @brief \u591A\
    \u9805\u5F0F\u884C\u5217\u306Eprefix product\n */\n"
  code: "#pragma once\n\n#include \"../fps/formal-power-series.hpp\"\n#include \"\
    ../fps/sample-point-shift.hpp\"\n#include \"matrix.hpp\"\n\n// return m(k-1) *\
    \ m(k-2) * ... * m(1) * m(0)\ntemplate <typename mint>\nMatrix<mint> polynomial_matrix_prod(Matrix<FormalPowerSeries<mint>>\
    \ &m,\n                                    long long k) {\n  using Mat = Matrix<mint>;\n\
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
    \ * @brief \u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/sample-point-shift.hpp
  - modulo/binomial.hpp
  - matrix/matrix.hpp
  - matrix/inverse-matrix.hpp
  - matrix/gauss-elimination.hpp
  isVerificationFile: false
  path: matrix/polynomial-matrix-prefix-prod.hpp
  requiredBy:
  - fps/find-p-recursive.hpp
  timestamp: '2023-12-22 19:57:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1533.test.cpp
  - verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
documentation_of: matrix/polynomial-matrix-prefix-prod.hpp
layout: document
redirect_from:
- /library/matrix/polynomial-matrix-prefix-prod.hpp
- /library/matrix/polynomial-matrix-prefix-prod.hpp.html
title: "\u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product"
---
