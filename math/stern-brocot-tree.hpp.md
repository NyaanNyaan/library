---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: math/rational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stern-brocot-tree.hpp\"\n\n#line 2 \"math/rational.hpp\"\
    \n\n#include <cassert>\n#include <numeric>\n#include <vector>\nusing namespace\
    \ std;\n\n#line 2 \"math-fast/gcd.hpp\"\n\n#include <algorithm>\nusing namespace\
    \ std;\n\nnamespace BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8\
    \ = char;\n\nu64 binary_gcd(u64 a, u64 b) {\n  if (a == 0 || b == 0) return a\
    \ + b;\n  i8 n = __builtin_ctzll(a);\n  i8 m = __builtin_ctzll(b);\n  a >>= n;\n\
    \  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u64 d = a - b;\n    i8\
    \ s = __builtin_ctzll(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a = (f\
    \ ? d : -d) >> s;\n  }\n  return a << n;\n}\n\nusing u128 = __uint128_t;\n// a\
    \ > 0\nint ctz128(u128 a) {\n  u64 lo = a & u64(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n}\nu128 binary_gcd128(u128 a, u128 b) {\n\
    \  if (a == 0 || b == 0) return a + b;\n  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n\
    \  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while (a != b) {\n    u128 d = a\
    \ - b;\n    i8 s = ctz128(d);\n    bool f = a > b;\n    b = f ? b : a;\n    a\
    \ = (f ? d : -d) >> s;\n  }\n  return a << n;\n}\n\n}  // namespace BinaryGCDImpl\n\
    \nlong long binary_gcd(long long a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a),\
    \ abs(b));\n}\n__int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a\
    \ < 0) a = -a;\n  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a,\
    \ b);\n}\n\n/**\n * @brief binary GCD\n */\n#line 9 \"math/rational.hpp\"\n\n\
    // T : \u5024, U : \u6BD4\u8F03\u7528\ntemplate <typename T, typename U>\nstruct\
    \ RationalBase {\n  using R = RationalBase;\n  using Key = T;\n  T x, y;\n  RationalBase()\
    \ : x(0), y(1) {}\n  RationalBase(T _x, T _y = 1) : x(_x), y(_y) {\n    assert(y\
    \ != 0);\n    if (y == -1) x = -x, y = -y;\n    if (y != 1) {\n      T g;\n  \
    \    if constexpr (is_same_v<T, int> || is_same_v<T, long long>) {\n        g\
    \ = binary_gcd(abs(x), abs(y));\n      } else {\n        assert(false);\n    \
    \  }\n      if (g != 0) x /= g, y /= g;\n      if (y < 0) x = -x, y = -y;\n  \
    \  }\n  }\n  // y = 0 \u306E\u4EE3\u5165\u3082\u8A8D\u3081\u308B\n  static R raw(T\
    \ _x, T _y) {\n    R r;\n    r.x = _x, r.y = _y;\n    return r;\n  }\n  friend\
    \ R operator+(const R& l, const R& r) {\n    if (l.y == r.y) return R{l.x + r.x,\
    \ l.y};\n    return R{l.x * r.y + l.y * r.x, l.y * r.y};\n  }\n  friend R operator-(const\
    \ R& l, const R& r) {\n    if (l.y == r.y) return R{l.x - r.x, l.y};\n    return\
    \ R{l.x * r.y - l.y * r.x, l.y * r.y};\n  }\n  friend R operator*(const R& l,\
    \ const R& r) { return R{l.x * r.x, l.y * r.y}; }\n  friend R operator/(const\
    \ R& l, const R& r) { return R{l.x * r.y, l.y * r.x}; }\n  R& operator+=(const\
    \ R& r) { return (*this) = (*this) + r; }\n  R& operator-=(const R& r) { return\
    \ (*this) = (*this) - r; }\n  R& operator*=(const R& r) { return (*this) = (*this)\
    \ * r; }\n  R& operator/=(const R& r) { return (*this) = (*this) / r; }\n  R operator-()\
    \ const { return raw(-x, y); }\n  R inverse() const {\n    assert(x != 0);\n \
    \   R r = raw(y, x);\n    if (r.y < 0) r.x = -r.x, r.y = -r.y;\n    return r;\n\
    \  }\n  R pow(long long p) const {\n    R res{1}, base{*this};\n    while (p)\
    \ {\n      if (p & 1) res *= base;\n      base *= base;\n      p >>= 1;\n    }\n\
    \    return res;\n  }\n  friend bool operator==(const R& l, const R& r) {\n  \
    \  return l.x == r.x && l.y == r.y;\n  };\n  friend bool operator!=(const R& l,\
    \ const R& r) {\n    return l.x != r.x || l.y != r.y;\n  };\n  friend bool operator<(const\
    \ R& l, const R& r) {\n    return U{l.x} * r.y < U{l.y} * r.x;\n  };\n  friend\
    \ bool operator<=(const R& l, const R& r) { return l < r || l == r; }\n  friend\
    \ bool operator>(const R& l, const R& r) {\n    return U{l.x} * r.y > U{l.y} *\
    \ r.x;\n  };\n  friend bool operator>=(const R& l, const R& r) { return l > r\
    \ || l == r; }\n  friend ostream& operator<<(ostream& os, const R& r) {\n    os\
    \ << r.x;\n    if (r.x != 0 && r.y != 1) os << \"/\" << r.y;\n    return os;\n\
    \  }\n\n  T toMint(T mod) {\n    assert(mod != 0);\n    T a = y, b = mod, u =\
    \ 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b,\
    \ b);\n      swap(u -= t * v, v);\n    }\n    return U((u % mod + mod) % mod)\
    \ * x % mod;\n  }\n};\n\nusing Rational = RationalBase<long long, __int128_t>;\n\
    \ntemplate <typename R = Rational>\nstruct Binomial {\n  vector<R> fc;\n  Binomial(int\
    \ = 0) { fc.emplace_back(1); }\n  void extend() {\n    int n = fc.size();\n  \
    \  R nxt = fc.back() * n;\n    fc.push_back(nxt);\n  }\n  R fac(int n) {\n   \
    \ if (n < 0) return 0;\n    while ((int)fc.size() <= n) extend();\n    return\
    \ fc[n];\n  }\n  R finv(int n) {\n    if (n < 0) return 0;\n    return fac(n).inverse();\n\
    \  }\n  R inv(int n) {\n    if (n < 0) return -inv(-n);\n    return R{1, max(n,\
    \ 1)};\n  }\n  R C(int n, int r) {\n    if (n < 0 or r < 0 or n < r) return R{0};\n\
    \    return fac(n) * finv(n - r) * finv(r);\n  }\n  R operator()(int n, int r)\
    \ { return C(n, r); }\n  template <typename I>\n  R multinomial(const vector<I>&\
    \ r) {\n    static_assert(is_integral<I>::value == true);\n    int n = 0;\n  \
    \  for (auto& x : r) {\n      if (x < 0) return R{0};\n      n += x;\n    }\n\
    \    R res = fac(n);\n    for (auto& x : r) res *= finv(x);\n    return res;\n\
    \  }\n\n  template <typename I>\n  R operator()(const vector<I>& r) {\n    return\
    \ multinomial(r);\n  }\n};\n#line 4 \"math/stern-brocot-tree.hpp\"\n\n// f(x)\
    \ \u304C true, \u304B\u3064\u5206\u5B50\u3068\u5206\u6BCD\u304C INF \u4EE5\u4E0B\
    \u3067\u3042\u308B\u6700\u5C0F\u306E\u65E2\u7D04\u5206\u6570 x \u3092\u6C42\u3081\
    \u308B\n// f(0) = true \u306E\u5834\u5408\u306F 0 \u3092, true \u306B\u306A\u308B\
    \u5206\u6570\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F 1/0 \u3092\u8FD4\
    \u3059\nusing T = Rational;\nusing I = typename T::Key;\ntemplate <typename F>\n\
    T binary_search_on_stern_brocot_tree(const F& f, const I& INF) {\n  // INF >=\
    \ 1\n  assert(1 <= INF);\n  auto gen_frac = [&](const T& a, const I& b, const\
    \ T& c) -> T {\n    return T{a.x * b + c.x, a.y * b + c.y};\n  };\n\n  T L{0,\
    \ 1}, M{1, 1}, R = T::raw(1, 0);\n  if (f(L)) return L;\n  int go_left = f(M);\n\
    \  while (true) {\n    if (go_left) {\n      // (L, M] \u306B\u7B54\u3048\u304C\
    \u3042\u308B\n      // (f(L * b + M) = false) or (INF \u8D85\u3048) \u306B\u306A\
    \u308B b \u306E\u6700\u5C0F\u306F\uFF1F\n      I a = 0, b = 1;\n      while (true)\
    \ {\n        T x = gen_frac(L, b, M);\n        if (max(x.x, x.y) > INF or !f(x))\
    \ break;\n        a = b, b += b;\n      }\n      while (a + 1 < b) {\n       \
    \ I c = (a + b) / 2;\n        T x = gen_frac(L, c, M);\n        (max(x.x, x.y)\
    \ > INF or !f(x) ? b : a) = c;\n      }\n      R = gen_frac(L, a, M);\n      M\
    \ = gen_frac(L, b, M);\n      if (max(M.x, M.y) > INF) return R;\n    } else {\n\
    \      // f(M) = false -> (M, R] \u306B\u7B54\u3048\u304C\u3042\u308B\n      //\
    \ (f(M + R * b) = true) or (INF \u8D85\u3048) \u306B\u306A\u308B b \u306E\u6700\
    \u5C0F\u306F\uFF1F\n      I a = 0, b = 1;\n      while (true) {\n        T x =\
    \ gen_frac(R, b, M);\n        if (max(x.x, x.y) > INF or f(x)) break;\n      \
    \  a = b, b += b;\n      }\n      while (a + 1 < b) {\n        I c = (a + b) /\
    \ 2;\n        T x = gen_frac(R, c, M);\n        (max(x.x, x.y) > INF or f(x) ?\
    \ b : a) = c;\n      }\n      L = gen_frac(R, a, M);\n      M = gen_frac(R, b,\
    \ M);\n      if (max(M.x, M.y) > INF) return R;\n    }\n    go_left ^= 1;\n  }\n\
    }\n\n/**\n * Stern-Brocot Tree \u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n */\n"
  code: "#pragma once\n\n#include \"rational.hpp\"\n\n// f(x) \u304C true, \u304B\u3064\
    \u5206\u5B50\u3068\u5206\u6BCD\u304C INF \u4EE5\u4E0B\u3067\u3042\u308B\u6700\u5C0F\
    \u306E\u65E2\u7D04\u5206\u6570 x \u3092\u6C42\u3081\u308B\n// f(0) = true \u306E\
    \u5834\u5408\u306F 0 \u3092, true \u306B\u306A\u308B\u5206\u6570\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F 1/0 \u3092\u8FD4\u3059\nusing T = Rational;\n\
    using I = typename T::Key;\ntemplate <typename F>\nT binary_search_on_stern_brocot_tree(const\
    \ F& f, const I& INF) {\n  // INF >= 1\n  assert(1 <= INF);\n  auto gen_frac =\
    \ [&](const T& a, const I& b, const T& c) -> T {\n    return T{a.x * b + c.x,\
    \ a.y * b + c.y};\n  };\n\n  T L{0, 1}, M{1, 1}, R = T::raw(1, 0);\n  if (f(L))\
    \ return L;\n  int go_left = f(M);\n  while (true) {\n    if (go_left) {\n   \
    \   // (L, M] \u306B\u7B54\u3048\u304C\u3042\u308B\n      // (f(L * b + M) = false)\
    \ or (INF \u8D85\u3048) \u306B\u306A\u308B b \u306E\u6700\u5C0F\u306F\uFF1F\n\
    \      I a = 0, b = 1;\n      while (true) {\n        T x = gen_frac(L, b, M);\n\
    \        if (max(x.x, x.y) > INF or !f(x)) break;\n        a = b, b += b;\n  \
    \    }\n      while (a + 1 < b) {\n        I c = (a + b) / 2;\n        T x = gen_frac(L,\
    \ c, M);\n        (max(x.x, x.y) > INF or !f(x) ? b : a) = c;\n      }\n     \
    \ R = gen_frac(L, a, M);\n      M = gen_frac(L, b, M);\n      if (max(M.x, M.y)\
    \ > INF) return R;\n    } else {\n      // f(M) = false -> (M, R] \u306B\u7B54\
    \u3048\u304C\u3042\u308B\n      // (f(M + R * b) = true) or (INF \u8D85\u3048\
    ) \u306B\u306A\u308B b \u306E\u6700\u5C0F\u306F\uFF1F\n      I a = 0, b = 1;\n\
    \      while (true) {\n        T x = gen_frac(R, b, M);\n        if (max(x.x,\
    \ x.y) > INF or f(x)) break;\n        a = b, b += b;\n      }\n      while (a\
    \ + 1 < b) {\n        I c = (a + b) / 2;\n        T x = gen_frac(R, c, M);\n \
    \       (max(x.x, x.y) > INF or f(x) ? b : a) = c;\n      }\n      L = gen_frac(R,\
    \ a, M);\n      M = gen_frac(R, b, M);\n      if (max(M.x, M.y) > INF) return\
    \ R;\n    }\n    go_left ^= 1;\n  }\n}\n\n/**\n * Stern-Brocot Tree \u4E0A\u306E\
    \u4E8C\u5206\u63A2\u7D22\n */\n"
  dependsOn:
  - math/rational.hpp
  - math-fast/gcd.hpp
  isVerificationFile: false
  path: math/stern-brocot-tree.hpp
  requiredBy: []
  timestamp: '2023-04-11 20:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2266.test.cpp
documentation_of: math/stern-brocot-tree.hpp
layout: document
redirect_from:
- /library/math/stern-brocot-tree.hpp
- /library/math/stern-brocot-tree.hpp.html
title: math/stern-brocot-tree.hpp
---
