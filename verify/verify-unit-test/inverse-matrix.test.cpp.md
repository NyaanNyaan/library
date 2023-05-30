---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/gauss-elimination.hpp
    title: matrix/gauss-elimination.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/inverse-matrix.hpp
    title: matrix/inverse-matrix.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/inverse-matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include <cassert>\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\nusing namespace std;\n\
    \n#line 2 \"matrix/gauss-elimination.hpp\"\n\n#include <utility>\n#line 5 \"matrix/gauss-elimination.hpp\"\
    \nusing namespace std;\n\n// {rank, det(\u975E\u6B63\u65B9\u884C\u5217\u306E\u5834\
    \u5408\u306F\u672A\u5B9A\u7FA9)} \u3092\u8FD4\u3059\n// \u578B\u304C double \u3084\
    \ Rational \u3067\u3082\u52D5\u304F\u306F\u305A\uFF1F(\u672A\u691C\u8A3C)\n//\n\
    // pivot \u5019\u88DC : [0, pivot_end)\ntemplate <typename T>\nstd::pair<int,\
    \ T> GaussElimination(vector<vector<T>> &a, int pivot_end = -1,\n            \
    \                       bool diagonalize = false) {\n  int H = a.size(), W = a[0].size(),\
    \ rank = 0;\n  if (pivot_end == -1) pivot_end = W;\n  T det = 1;\n  for (int j\
    \ = 0; j < pivot_end; j++) {\n    int idx = -1;\n    for (int i = rank; i < H;\
    \ i++) {\n      if (a[i][j] != T(0)) {\n        idx = i;\n        break;\n   \
    \   }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n    }\n \
    \   if (rank != idx) det = -det, swap(a[rank], a[idx]);\n    det *= a[rank][j];\n\
    \    if (diagonalize && a[rank][j] != T(1)) {\n      T coeff = T(1) / a[rank][j];\n\
    \      for (int k = j; k < W; k++) a[rank][k] *= coeff;\n    }\n    int is = diagonalize\
    \ ? 0 : rank + 1;\n    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n\
    \      if (a[i][j] != T(0)) {\n        T coeff = a[i][j] / a[rank][j];\n     \
    \   for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n\
    \    rank++;\n  }\n  return make_pair(rank, det);\n}\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\"\
    );\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n  constexpr mint operator+() const { return mint(*this); }\n\n  constexpr\
    \ mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  constexpr mint inverse() const {\n    int x = get(), y = mod,\
    \ u = 1, v = 0, t = 0, tmp = 0;\n    while (y > 0) {\n      t = x / y;\n     \
    \ x -= t * y, u -= t * v;\n      tmp = x, x = y, y = tmp;\n      tmp = u, u =\
    \ v, v = tmp;\n    }\n    return mint{u};\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n\n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"matrix/inverse-matrix.hpp\"\n\n#line 4 \"matrix/inverse-matrix.hpp\"\
    \n\ntemplate <typename mint>\nvector<vector<mint>> inverse_matrix(const vector<vector<mint>>&\
    \ a) {\n  int N = a.size();\n  assert(N > 0);\n  assert(N == (int)a[0].size());\n\
    \n  vector<vector<mint>> m(N, vector<mint>(2 * N));\n  for (int i = 0; i < N;\
    \ i++) {\n    copy(begin(a[i]), end(a[i]), begin(m[i]));\n    m[i][N + i] = 1;\n\
    \  }\n\n  auto [rank, det] = GaussElimination(m, N, true);\n  if (rank != N) return\
    \ {};\n\n  vector<vector<mint>> b(N);\n  for (int i = 0; i < N; i++) {\n    copy(begin(m[i])\
    \ + N, end(m[i]), back_inserter(b[i]));\n  }\n  return b;\n}\n#line 12 \"verify/verify-unit-test/inverse-matrix.test.cpp\"\
    \n\ntemplate <typename mint>\nvoid verify(const vector<vector<mint>>& a, const\
    \ vector<vector<mint>>& b) {\n  int N = a.size();\n  auto _a = a;\n  auto [rank,\
    \ det] = GaussElimination(_a);\n\n  if (det == 0 or rank != N) {\n    assert(det\
    \ == 0 and rank != N);\n    if (!b.empty()) {\n      assert(false and \"b is not\
    \ empty is spite of det == 0.\");\n    }\n    return;\n  }\n  assert(!b.empty());\n\
    \  vector<vector<mint>> c(N, vector<mint>(N));\n  for (int i = 0; i < N; i++)\
    \ {\n    for (int k = 0; k < N; k++) {\n      for (int j = 0; j < N; j++) {\n\
    \        c[i][j] += a[i][k] * b[k][j];\n      }\n    }\n  }\n\n  for (int i =\
    \ 0; i < N; i++) {\n    for (int j = 0; j < N; j++) {\n      assert(c[i][j] ==\
    \ (i == j));\n    }\n  }\n}\n\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    \nvoid test() {\n  int testcase = 1000;\n\n  long long _x = 1;\n  auto rng = [&]()\
    \ { return _x = _x * 100000 % 998244353; };\n\n  for (int t = 0; t < testcase;\
    \ t++) {\n    int N = t % 30 + 1;\n    vector<vector<mint>> a(N, vector<mint>(N));\n\
    \    for (auto& v : a) {\n      for (auto& x : v) {\n        x = rng();\n    \
    \  }\n    }\n    auto b = inverse_matrix(a);\n    verify(a, b);\n  }\n}\n\nint\
    \ main() {\n  test();\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ <cassert>\n#include <cstdint>\n#include <iostream>\n#include <vector>\nusing\
    \ namespace std;\n\n#include \"../../matrix/gauss-elimination.hpp\"\n#include\
    \ \"../../modint/montgomery-modint.hpp\"\n#include \"../../matrix/inverse-matrix.hpp\"\
    \n\ntemplate <typename mint>\nvoid verify(const vector<vector<mint>>& a, const\
    \ vector<vector<mint>>& b) {\n  int N = a.size();\n  auto _a = a;\n  auto [rank,\
    \ det] = GaussElimination(_a);\n\n  if (det == 0 or rank != N) {\n    assert(det\
    \ == 0 and rank != N);\n    if (!b.empty()) {\n      assert(false and \"b is not\
    \ empty is spite of det == 0.\");\n    }\n    return;\n  }\n  assert(!b.empty());\n\
    \  vector<vector<mint>> c(N, vector<mint>(N));\n  for (int i = 0; i < N; i++)\
    \ {\n    for (int k = 0; k < N; k++) {\n      for (int j = 0; j < N; j++) {\n\
    \        c[i][j] += a[i][k] * b[k][j];\n      }\n    }\n  }\n\n  for (int i =\
    \ 0; i < N; i++) {\n    for (int j = 0; j < N; j++) {\n      assert(c[i][j] ==\
    \ (i == j));\n    }\n  }\n}\n\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    \nvoid test() {\n  int testcase = 1000;\n\n  long long _x = 1;\n  auto rng = [&]()\
    \ { return _x = _x * 100000 % 998244353; };\n\n  for (int t = 0; t < testcase;\
    \ t++) {\n    int N = t % 30 + 1;\n    vector<vector<mint>> a(N, vector<mint>(N));\n\
    \    for (auto& v : a) {\n      for (auto& x : v) {\n        x = rng();\n    \
    \  }\n    }\n    auto b = inverse_matrix(a);\n    verify(a, b);\n  }\n}\n\nint\
    \ main() {\n  test();\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n\
    }"
  dependsOn:
  - matrix/gauss-elimination.hpp
  - modint/montgomery-modint.hpp
  - matrix/inverse-matrix.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/inverse-matrix.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 20:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/inverse-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/inverse-matrix.test.cpp
- /verify/verify/verify-unit-test/inverse-matrix.test.cpp.html
title: verify/verify-unit-test/inverse-matrix.test.cpp
---
