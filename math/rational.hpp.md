---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/bigint-all.hpp
    title: math/bigint-all.hpp
  - icon: ':heavy_check_mark:'
    path: math/bigint-rational.hpp
    title: math/bigint-rational.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational-binomial.hpp
    title: math/rational-binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational-fps.hpp
    title: math/rational-fps.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
    title: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigrational.test.cpp
    title: verify/verify-unit-test/bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rational-number.test.cpp
    title: verify/verify-unit-test/rational-number.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2262.test.cpp
    title: verify/verify-yuki/yuki-2262.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rational.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#include <type_traits>\nusing namespace std;\n\nnamespace internal {\ntemplate\
    \ <typename T>\nusing is_broadly_integral =\n    typename conditional_t<is_integral_v<T>\
    \ || is_same_v<T, __int128_t> ||\n                               is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    template <typename T>\nusing is_broadly_signed =\n    typename conditional_t<is_signed_v<T>\
    \ || is_same_v<T, __int128_t>,\n                           true_type, false_type>::type;\n\
    \ntemplate <typename T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
    \ || is_same_v<T, __uint128_t>,\n                           true_type, false_type>::type;\n\
    \n#define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                   \\\n  template <class, class = void>     \
    \                          \\\n  struct has_##var : false_type {};           \
    \                 \\\n  template <class T>                                   \
    \        \\\n  struct has_##var<T, void_t<typename T::var>> : true_type {}; \\\
    \n  template <class T>                                           \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n#define ENABLE_HAS_VAR(var)   \
    \                                  \\\n  template <class, class = void>      \
    \                          \\\n  struct has_##var : false_type {};           \
    \                  \\\n  template <class T>                                  \
    \          \\\n  struct has_##var<T, void_t<decltype(T::var)>> : true_type {};\
    \ \\\n  template <class T>                                            \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n}  // namespace internal\n#line\
    \ 2 \"math-fast/gcd.hpp\"\n\n#include <algorithm>\nusing namespace std;\n\nnamespace\
    \ BinaryGCDImpl {\nusing u64 = unsigned long long;\nusing i8 = char;\n\nu64 binary_gcd(u64\
    \ a, u64 b) {\n  if (a == 0 || b == 0) return a + b;\n  i8 n = __builtin_ctzll(a);\n\
    \  i8 m = __builtin_ctzll(b);\n  a >>= n;\n  b >>= m;\n  n = min(n, m);\n  while\
    \ (a != b) {\n    u64 d = a - b;\n    i8 s = __builtin_ctzll(d);\n    bool f =\
    \ a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a << n;\n\
    }\n\nusing u128 = __uint128_t;\n// a > 0\nint ctz128(u128 a) {\n  u64 lo = a &\
    \ u64(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);\n\
    }\nu128 binary_gcd128(u128 a, u128 b) {\n  if (a == 0 || b == 0) return a + b;\n\
    \  i8 n = ctz128(a);\n  i8 m = ctz128(b);\n  a >>= n;\n  b >>= m;\n  n = min(n,\
    \ m);\n  while (a != b) {\n    u128 d = a - b;\n    i8 s = ctz128(d);\n    bool\
    \ f = a > b;\n    b = f ? b : a;\n    a = (f ? d : -d) >> s;\n  }\n  return a\
    \ << n;\n}\n\n}  // namespace BinaryGCDImpl\n\nlong long binary_gcd(long long\
    \ a, long long b) {\n  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));\n}\n\
    __int128_t binary_gcd128(__int128_t a, __int128_t b) {\n  if (a < 0) a = -a;\n\
    \  if (b < 0) b = -b;\n  return BinaryGCDImpl::binary_gcd128(a, b);\n}\n\n/**\n\
    \ * @brief binary GCD\n */\n#line 10 \"math/rational.hpp\"\n\n// T : \u5024, U\
    \ : \u6BD4\u8F03\u7528\ntemplate <typename T, typename U>\nstruct RationalBase\
    \ {\n  using R = RationalBase;\n  using Key = T;\n  T x, y;\n  RationalBase()\
    \ : x(0), y(1) {}\n  template <typename T1>\n  RationalBase(const T1& _x) : RationalBase<T,\
    \ U>(_x, T1{1}) {}\n  template <typename T1, typename T2>\n  RationalBase(const\
    \ pair<T1, T2>& _p)\n      : RationalBase<T, U>(_p.first, _p.second) {}\n  template\
    \ <typename T1, typename T2>\n  RationalBase(const T1& _x, const T2& _y) : x(_x),\
    \ y(_y) {\n    assert(y != 0);\n    if (y == -1) x = -x, y = -y;\n    if (y !=\
    \ 1) {\n      T g;\n      if constexpr (internal::is_broadly_integral_v<T>) {\n\
    \        if constexpr (sizeof(T) == 16) {\n          g = binary_gcd128(x, y);\n\
    \        } else {\n          g = binary_gcd(x, y);\n        }\n      } else {\n\
    \        g = gcd(x, y);\n      }\n      if (g != 0) x /= g, y /= g;\n      if\
    \ (y < 0) x = -x, y = -y;\n    }\n  }\n  // y = 0 \u306E\u4EE3\u5165\u3082\u8A8D\
    \u3081\u308B\n  static R raw(T _x, T _y) {\n    R r;\n    r.x = _x, r.y = _y;\n\
    \    return r;\n  }\n  friend R operator+(const R& l, const R& r) {\n    if (l.y\
    \ == r.y) return R{l.x + r.x, l.y};\n    return R{l.x * r.y + l.y * r.x, l.y *\
    \ r.y};\n  }\n  friend R operator-(const R& l, const R& r) {\n    if (l.y == r.y)\
    \ return R{l.x - r.x, l.y};\n    return R{l.x * r.y - l.y * r.x, l.y * r.y};\n\
    \  }\n  friend R operator*(const R& l, const R& r) { return R{l.x * r.x, l.y *\
    \ r.y}; }\n  friend R operator/(const R& l, const R& r) { return R{l.x * r.y,\
    \ l.y * r.x}; }\n  R& operator+=(const R& r) { return (*this) = (*this) + r; }\n\
    \  R& operator-=(const R& r) { return (*this) = (*this) - r; }\n  R& operator*=(const\
    \ R& r) { return (*this) = (*this) * r; }\n  R& operator/=(const R& r) { return\
    \ (*this) = (*this) / r; }\n  R operator-() const { return raw(-x, y); }\n  R\
    \ inverse() const {\n    assert(x != 0);\n    R r = raw(y, x);\n    if (r.y <\
    \ 0) r.x = -r.x, r.y = -r.y;\n    return r;\n  }\n  R pow(long long p) const {\n\
    \    R res{1}, base{*this};\n    while (p) {\n      if (p & 1) res *= base;\n\
    \      base *= base;\n      p >>= 1;\n    }\n    return res;\n  }\n  friend bool\
    \ operator==(const R& l, const R& r) {\n    return l.x == r.x && l.y == r.y;\n\
    \  };\n  friend bool operator!=(const R& l, const R& r) {\n    return l.x != r.x\
    \ || l.y != r.y;\n  };\n  friend bool operator<(const R& l, const R& r) {\n  \
    \  return U{l.x} * r.y < U{l.y} * r.x;\n  };\n  friend bool operator<=(const R&\
    \ l, const R& r) { return l < r || l == r; }\n  friend bool operator>(const R&\
    \ l, const R& r) {\n    return U{l.x} * r.y > U{l.y} * r.x;\n  };\n  friend bool\
    \ operator>=(const R& l, const R& r) { return l > r || l == r; }\n  friend ostream&\
    \ operator<<(ostream& os, const R& r) {\n    os << r.x;\n    if (r.x != 0 && r.y\
    \ != 1) os << \"/\" << r.y;\n    return os;\n  }\n\n  // T \u306B\u30AD\u30E3\u30B9\
    \u30C8\u3055\u308C\u308B\u306E\u3067 T \u304C bigint \u306E\u5834\u5408\u306F\
    \ to_ll \u3082\u8981\u308B\n  T to_mint(T mod) const {\n    assert(mod != 0);\n\
    \    T a = y, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return U((u\
    \ % mod + mod) % mod) * x % mod;\n  }\n};\n\nusing Rational = RationalBase<long\
    \ long, __int128_t>;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\n#include \"../internal/internal-type-traits.hpp\"\n#include\
    \ \"../math-fast/gcd.hpp\"\n\n// T : \u5024, U : \u6BD4\u8F03\u7528\ntemplate\
    \ <typename T, typename U>\nstruct RationalBase {\n  using R = RationalBase;\n\
    \  using Key = T;\n  T x, y;\n  RationalBase() : x(0), y(1) {}\n  template <typename\
    \ T1>\n  RationalBase(const T1& _x) : RationalBase<T, U>(_x, T1{1}) {}\n  template\
    \ <typename T1, typename T2>\n  RationalBase(const pair<T1, T2>& _p)\n      :\
    \ RationalBase<T, U>(_p.first, _p.second) {}\n  template <typename T1, typename\
    \ T2>\n  RationalBase(const T1& _x, const T2& _y) : x(_x), y(_y) {\n    assert(y\
    \ != 0);\n    if (y == -1) x = -x, y = -y;\n    if (y != 1) {\n      T g;\n  \
    \    if constexpr (internal::is_broadly_integral_v<T>) {\n        if constexpr\
    \ (sizeof(T) == 16) {\n          g = binary_gcd128(x, y);\n        } else {\n\
    \          g = binary_gcd(x, y);\n        }\n      } else {\n        g = gcd(x,\
    \ y);\n      }\n      if (g != 0) x /= g, y /= g;\n      if (y < 0) x = -x, y\
    \ = -y;\n    }\n  }\n  // y = 0 \u306E\u4EE3\u5165\u3082\u8A8D\u3081\u308B\n \
    \ static R raw(T _x, T _y) {\n    R r;\n    r.x = _x, r.y = _y;\n    return r;\n\
    \  }\n  friend R operator+(const R& l, const R& r) {\n    if (l.y == r.y) return\
    \ R{l.x + r.x, l.y};\n    return R{l.x * r.y + l.y * r.x, l.y * r.y};\n  }\n \
    \ friend R operator-(const R& l, const R& r) {\n    if (l.y == r.y) return R{l.x\
    \ - r.x, l.y};\n    return R{l.x * r.y - l.y * r.x, l.y * r.y};\n  }\n  friend\
    \ R operator*(const R& l, const R& r) { return R{l.x * r.x, l.y * r.y}; }\n  friend\
    \ R operator/(const R& l, const R& r) { return R{l.x * r.y, l.y * r.x}; }\n  R&\
    \ operator+=(const R& r) { return (*this) = (*this) + r; }\n  R& operator-=(const\
    \ R& r) { return (*this) = (*this) - r; }\n  R& operator*=(const R& r) { return\
    \ (*this) = (*this) * r; }\n  R& operator/=(const R& r) { return (*this) = (*this)\
    \ / r; }\n  R operator-() const { return raw(-x, y); }\n  R inverse() const {\n\
    \    assert(x != 0);\n    R r = raw(y, x);\n    if (r.y < 0) r.x = -r.x, r.y =\
    \ -r.y;\n    return r;\n  }\n  R pow(long long p) const {\n    R res{1}, base{*this};\n\
    \    while (p) {\n      if (p & 1) res *= base;\n      base *= base;\n      p\
    \ >>= 1;\n    }\n    return res;\n  }\n  friend bool operator==(const R& l, const\
    \ R& r) {\n    return l.x == r.x && l.y == r.y;\n  };\n  friend bool operator!=(const\
    \ R& l, const R& r) {\n    return l.x != r.x || l.y != r.y;\n  };\n  friend bool\
    \ operator<(const R& l, const R& r) {\n    return U{l.x} * r.y < U{l.y} * r.x;\n\
    \  };\n  friend bool operator<=(const R& l, const R& r) { return l < r || l ==\
    \ r; }\n  friend bool operator>(const R& l, const R& r) {\n    return U{l.x} *\
    \ r.y > U{l.y} * r.x;\n  };\n  friend bool operator>=(const R& l, const R& r)\
    \ { return l > r || l == r; }\n  friend ostream& operator<<(ostream& os, const\
    \ R& r) {\n    os << r.x;\n    if (r.x != 0 && r.y != 1) os << \"/\" << r.y;\n\
    \    return os;\n  }\n\n  // T \u306B\u30AD\u30E3\u30B9\u30C8\u3055\u308C\u308B\
    \u306E\u3067 T \u304C bigint \u306E\u5834\u5408\u306F to_ll \u3082\u8981\u308B\
    \n  T to_mint(T mod) const {\n    assert(mod != 0);\n    T a = y, b = mod, u =\
    \ 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b,\
    \ b);\n      swap(u -= t * v, v);\n    }\n    return U((u % mod + mod) % mod)\
    \ * x % mod;\n  }\n};\n\nusing Rational = RationalBase<long long, __int128_t>;\n"
  dependsOn:
  - internal/internal-type-traits.hpp
  - math-fast/gcd.hpp
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy:
  - math/bigint-rational.hpp
  - math/rational-fps.hpp
  - math/rational-binomial.hpp
  - math/bigint-all.hpp
  timestamp: '2023-12-18 23:52:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2262.test.cpp
  - verify/verify-yuki/yuki-2266.test.cpp
  - verify/verify-unit-test/rational-number.test.cpp
  - verify/verify-unit-test/bigrational.test.cpp
  - verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
  - verify/verify-yosupo-math/yosupo-stern-brocot-tree-2.test.cpp
documentation_of: math/rational.hpp
layout: document
redirect_from:
- /library/math/rational.hpp
- /library/math/rational.hpp.html
title: math/rational.hpp
---
