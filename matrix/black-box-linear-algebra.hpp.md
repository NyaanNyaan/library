---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp-massey.hpp
    title: fps/berlekamp-massey.hpp
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/mod-pow.hpp
    title: Mod-Pow ($f(x)^k \mod g(x)$)
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112-sparse.test.cpp
    title: verify/verify-yuki/yuki-1112-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112.test.cpp
    title: verify/verify-yuki/yuki-1112.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Black Box Linear Algebra
    links: []
  bundledCode: "#line 1 \"matrix/black-box-linear-algebra.hpp\"\n\n#line 2 \"fps/berlekamp-massey.hpp\"\
    \n\ntemplate <typename mint>\nvector<mint> BerlekampMassey(const vector<mint>\
    \ &s) {\n  const int N = (int)s.size();\n  vector<mint> b, c;\n  b.reserve(N +\
    \ 1);\n  c.reserve(N + 1);\n  b.push_back(mint(1));\n  c.push_back(mint(1));\n\
    \  mint y = mint(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size());\n    mint x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * s[ed - l + i];\n    b.emplace_back(mint(0));\n    m++;\n    if (x == mint(0))\
    \ continue;\n    mint freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n \
    \     c.insert(begin(c), m - l, mint(0));\n      for (int i = 0; i < m; i++) c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  reverse(begin(c), end(c));\n  return c;\n}\n#line 2 \"fps/formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n  using\
    \ vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const\
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
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/mod-pow.hpp\"\n\n\
    #line 4 \"fps/mod-pow.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ mod_pow(int64_t k, const FormalPowerSeries<mint>& base,\n                  \
    \              const FormalPowerSeries<mint>& d) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert(!d.empty());\n  auto inv = d.rev().inv();\n  auto quo = [&](const fps&\
    \ poly) {\n    if (poly.size() < d.size()) return fps{};\n    int n = poly.size()\
    \ - d.size() + 1;\n    return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n\
    \  };\n  fps res{1}, b(base);\n  while (k) {\n    if (k & 1) {\n      res *= b;\n\
    \      res -= quo(res) * d;\n      res.shrink();\n    }\n    b *= b;\n    b -=\
    \ quo(b) * d;\n    b.shrink();\n    k >>= 1;\n    assert(b.size() + 1 <= d.size());\n\
    \    assert(res.size() + 1 <= d.size());\n  }\n  return res;\n}\n\n/**\n * @brief\
    \ Mod-Pow ($f(x)^k \\mod g(x)$)\n */\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand\
    \ {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 6 \"matrix/black-box-linear-algebra.hpp\"\n//\nnamespace BBLAImpl {\n\n\
    template <typename mint>\nmint inner_product(const FormalPowerSeries<mint>& a,\n\
    \                   const FormalPowerSeries<mint>& b) {\n  mint res = 0;\n  int\
    \ n = a.size();\n  assert(n == (int)b.size());\n  for (int i = 0; i < n; i++)\
    \ res += a[i] * b[i];\n  return res;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ random_poly(int n) {\n  FormalPowerSeries<mint> res(n);\n  for (auto& x : res)\
    \ x = randint(0, mint::get_mod());\n  return res;\n}\n\ntemplate <typename mint>\n\
    struct ModMatrix : vector<FormalPowerSeries<mint>> {\n  using fps = FormalPowerSeries<mint>;\n\
    \n  ModMatrix(int n) : vector<fps>(n, fps(n)) {}\n\n  inline void add(int i, int\
    \ j, mint x) { (*this)[i][j] += x; }\n\n  friend fps operator*(const ModMatrix&\
    \ m, const fps& r) {\n    int n = m.size();\n    assert(n == (int)r.size());\n\
    \    fps res(n);\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < n;\
    \ j++) res[i] += m[i][j] * r[j];\n    return res;\n  }\n\n  void apply(int i,\
    \ mint r) {\n    int n = (*this).size();\n    for (int j = 0; j < n; j++) (*this)[i][j]\
    \ *= r;\n  }\n};\n\ntemplate <typename mint>\nstruct SparseMatrix : vector<vector<pair<int,\
    \ mint>>> {\n  using fps = FormalPowerSeries<mint>;\n\n  template <typename...\
    \ Args>\n  SparseMatrix(Args... args) : vector<vector<pair<int, mint>>>(args...)\
    \ {}\n\n  inline void add(int i, int j, mint x) { (*this)[i].emplace_back(j, x);\
    \ }\n\n  friend fps operator*(const SparseMatrix& m, const fps& r) {\n    int\
    \ n = m.size();\n    assert(n == (int)r.size());\n    fps res(n);\n    for (int\
    \ i = 0; i < n; i++)\n      for (auto&& [j, x] : m[i]) res[i] += x * r[j];\n \
    \   return res;\n  }\n\n  void apply(int i, mint r) {\n    for (auto&& [_, x]\
    \ : (*this)[i]) x *= r;\n  }\n};\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ vector_minpoly(\n    const vector<FormalPowerSeries<mint>>& b) {\n  assert(!b.empty());\n\
    \  int n = b.size(), m = b[0].size();\n  FormalPowerSeries<mint> u = random_poly<mint>(m),\
    \ a(n);\n  for (int i = 0; i < n; i++) a[i] = inner_product(b[i], u);\n  auto\
    \ mp = BerlekampMassey<mint>(a);\n  return {mp.begin(), mp.end()};\n}\n\ntemplate\
    \ <typename mint, typename Mat>\nFormalPowerSeries<mint> mat_minpoly(const Mat&\
    \ A) {\n  int n = A.size();\n  FormalPowerSeries<mint> u = random_poly<mint>(n);\n\
    \  vector<FormalPowerSeries<mint>> b(n * 2 + 1);\n  for (int i = 0; i < (int)b.size();\
    \ i++) b[i] = u, u = A * u;\n  FormalPowerSeries<mint> mp = vector_minpoly(b);\n\
    \  return mp;\n}\n\n// calculate A^k b\ntemplate <typename mint, typename Mat>\n\
    FormalPowerSeries<mint> fast_pow(const Mat& A, FormalPowerSeries<mint> b,\n  \
    \                               int64_t k) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = b.size();\n  fps mp = mat_minpoly<mint, Mat>(A);\n  fps c = mod_pow<mint>(k,\
    \ fps{0, 1}, mp.rev());\n  fps res(n);\n  for (int i = 0; i < (int)c.size(); i++)\
    \ res += b * c[i], b = A * b;\n  return res;\n}\n\ntemplate <typename mint, typename\
    \ Mat>\nmint fast_det(const Mat& A) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = A.size();\n  fps D;\n  while (true) {\n    do {\n      D = random_poly<mint>(n);\n\
    \    } while (any_of(begin(D), end(D), [](mint x) { return x == mint(0); }));\n\
    \n    Mat AD = A;\n    for (int i = 0; i < n; i++) AD.apply(i, D[i]);\n    fps\
    \ mp = mat_minpoly<mint, Mat>(AD);\n    if (mp.back() == 0) return 0;\n    if\
    \ ((int)mp.size() != n + 1) continue;\n    mint det = n & 1 ? -mp.back() : mp.back();\n\
    \    mint Ddet = 1;\n    for (auto& d : D) Ddet *= d;\n    return det / Ddet;\n\
    \  }\n  exit(1);\n}\n\ntemplate <typename mint, typename Mat>\nFormalPowerSeries<mint>\
    \ fast_linear_equation(const Mat& A, const FormalPowerSeries<mint>& b) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int n = A.size();\n  fps mp = mat_minpoly<mint,\
    \ Mat>(A).rev();\n  fps buf = b, res(n);\n  for (int i = 1; i < (int)mp.size();\
    \ i++) {\n    res = buf * mp[i];\n    buf = A * buf;\n  }\n  return buf * mp[0].inverse();\n\
    }\n\n}  // namespace BBLAImpl\n\nusing BBLAImpl::fast_det;\nusing BBLAImpl::fast_pow;\n\
    using BBLAImpl::ModMatrix;\nusing BBLAImpl::SparseMatrix;\n\n/**\n * @brief Black\
    \ Box Linear Algebra\n */\n"
  code: "\n#include \"../fps/berlekamp-massey.hpp\"\n#include \"../fps/formal-power-series.hpp\"\
    \n#include \"../fps/mod-pow.hpp\"\n#include \"../misc/rng.hpp\"\n//\nnamespace\
    \ BBLAImpl {\n\ntemplate <typename mint>\nmint inner_product(const FormalPowerSeries<mint>&\
    \ a,\n                   const FormalPowerSeries<mint>& b) {\n  mint res = 0;\n\
    \  int n = a.size();\n  assert(n == (int)b.size());\n  for (int i = 0; i < n;\
    \ i++) res += a[i] * b[i];\n  return res;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ random_poly(int n) {\n  FormalPowerSeries<mint> res(n);\n  for (auto& x : res)\
    \ x = randint(0, mint::get_mod());\n  return res;\n}\n\ntemplate <typename mint>\n\
    struct ModMatrix : vector<FormalPowerSeries<mint>> {\n  using fps = FormalPowerSeries<mint>;\n\
    \n  ModMatrix(int n) : vector<fps>(n, fps(n)) {}\n\n  inline void add(int i, int\
    \ j, mint x) { (*this)[i][j] += x; }\n\n  friend fps operator*(const ModMatrix&\
    \ m, const fps& r) {\n    int n = m.size();\n    assert(n == (int)r.size());\n\
    \    fps res(n);\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < n;\
    \ j++) res[i] += m[i][j] * r[j];\n    return res;\n  }\n\n  void apply(int i,\
    \ mint r) {\n    int n = (*this).size();\n    for (int j = 0; j < n; j++) (*this)[i][j]\
    \ *= r;\n  }\n};\n\ntemplate <typename mint>\nstruct SparseMatrix : vector<vector<pair<int,\
    \ mint>>> {\n  using fps = FormalPowerSeries<mint>;\n\n  template <typename...\
    \ Args>\n  SparseMatrix(Args... args) : vector<vector<pair<int, mint>>>(args...)\
    \ {}\n\n  inline void add(int i, int j, mint x) { (*this)[i].emplace_back(j, x);\
    \ }\n\n  friend fps operator*(const SparseMatrix& m, const fps& r) {\n    int\
    \ n = m.size();\n    assert(n == (int)r.size());\n    fps res(n);\n    for (int\
    \ i = 0; i < n; i++)\n      for (auto&& [j, x] : m[i]) res[i] += x * r[j];\n \
    \   return res;\n  }\n\n  void apply(int i, mint r) {\n    for (auto&& [_, x]\
    \ : (*this)[i]) x *= r;\n  }\n};\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ vector_minpoly(\n    const vector<FormalPowerSeries<mint>>& b) {\n  assert(!b.empty());\n\
    \  int n = b.size(), m = b[0].size();\n  FormalPowerSeries<mint> u = random_poly<mint>(m),\
    \ a(n);\n  for (int i = 0; i < n; i++) a[i] = inner_product(b[i], u);\n  auto\
    \ mp = BerlekampMassey<mint>(a);\n  return {mp.begin(), mp.end()};\n}\n\ntemplate\
    \ <typename mint, typename Mat>\nFormalPowerSeries<mint> mat_minpoly(const Mat&\
    \ A) {\n  int n = A.size();\n  FormalPowerSeries<mint> u = random_poly<mint>(n);\n\
    \  vector<FormalPowerSeries<mint>> b(n * 2 + 1);\n  for (int i = 0; i < (int)b.size();\
    \ i++) b[i] = u, u = A * u;\n  FormalPowerSeries<mint> mp = vector_minpoly(b);\n\
    \  return mp;\n}\n\n// calculate A^k b\ntemplate <typename mint, typename Mat>\n\
    FormalPowerSeries<mint> fast_pow(const Mat& A, FormalPowerSeries<mint> b,\n  \
    \                               int64_t k) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = b.size();\n  fps mp = mat_minpoly<mint, Mat>(A);\n  fps c = mod_pow<mint>(k,\
    \ fps{0, 1}, mp.rev());\n  fps res(n);\n  for (int i = 0; i < (int)c.size(); i++)\
    \ res += b * c[i], b = A * b;\n  return res;\n}\n\ntemplate <typename mint, typename\
    \ Mat>\nmint fast_det(const Mat& A) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = A.size();\n  fps D;\n  while (true) {\n    do {\n      D = random_poly<mint>(n);\n\
    \    } while (any_of(begin(D), end(D), [](mint x) { return x == mint(0); }));\n\
    \n    Mat AD = A;\n    for (int i = 0; i < n; i++) AD.apply(i, D[i]);\n    fps\
    \ mp = mat_minpoly<mint, Mat>(AD);\n    if (mp.back() == 0) return 0;\n    if\
    \ ((int)mp.size() != n + 1) continue;\n    mint det = n & 1 ? -mp.back() : mp.back();\n\
    \    mint Ddet = 1;\n    for (auto& d : D) Ddet *= d;\n    return det / Ddet;\n\
    \  }\n  exit(1);\n}\n\ntemplate <typename mint, typename Mat>\nFormalPowerSeries<mint>\
    \ fast_linear_equation(const Mat& A, const FormalPowerSeries<mint>& b) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int n = A.size();\n  fps mp = mat_minpoly<mint,\
    \ Mat>(A).rev();\n  fps buf = b, res(n);\n  for (int i = 1; i < (int)mp.size();\
    \ i++) {\n    res = buf * mp[i];\n    buf = A * buf;\n  }\n  return buf * mp[0].inverse();\n\
    }\n\n}  // namespace BBLAImpl\n\nusing BBLAImpl::fast_det;\nusing BBLAImpl::fast_pow;\n\
    using BBLAImpl::ModMatrix;\nusing BBLAImpl::SparseMatrix;\n\n/**\n * @brief Black\
    \ Box Linear Algebra\n */\n"
  dependsOn:
  - fps/berlekamp-massey.hpp
  - fps/formal-power-series.hpp
  - fps/mod-pow.hpp
  - misc/rng.hpp
  isVerificationFile: false
  path: matrix/black-box-linear-algebra.hpp
  requiredBy: []
  timestamp: '2021-01-31 00:21:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - verify/verify-yuki/yuki-1112.test.cpp
  - verify/verify-yuki/yuki-1112-sparse.test.cpp
documentation_of: matrix/black-box-linear-algebra.hpp
layout: document
redirect_from:
- /library/matrix/black-box-linear-algebra.hpp
- /library/matrix/black-box-linear-algebra.hpp.html
title: Black Box Linear Algebra
---
