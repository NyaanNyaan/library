---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/gcd.hpp
    title: binary GCD
  - icon: ':heavy_check_mark:'
    path: math/rational-binomial.hpp
    title: math/rational-binomial.hpp
  - icon: ':heavy_check_mark:'
    path: math/rational.hpp
    title: math/rational.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/bigint-all.hpp
    title: math/bigint-all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigrational.test.cpp
    title: verify/verify-unit-test/bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rational-number.test.cpp
    title: verify/verify-unit-test/rational-number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rational-fps.hpp\"\n\n#line 2 \"math/rational-binomial.hpp\"\
    \n\n#line 2 \"math/rational.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
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
    \ T1& _x, const T2& _y) : x(_x), y(_y) {\n    assert(y != 0);\n    if (y == -1)\
    \ x = -x, y = -y;\n    if (y != 1) {\n      T g;\n      if constexpr (internal::is_broadly_integral_v<T>)\
    \ {\n        if constexpr (sizeof(T) == 16) {\n          g = binary_gcd128(x,\
    \ y);\n        } else {\n          g = binary_gcd(x, y);\n        }\n      } else\
    \ {\n        g = gcd(x, y);\n      }\n      if (g != 0) x /= g, y /= g;\n    \
    \  if (y < 0) x = -x, y = -y;\n    }\n  }\n  // y = 0 \u306E\u4EE3\u5165\u3082\
    \u8A8D\u3081\u308B\n  static R raw(T _x, T _y) {\n    R r;\n    r.x = _x, r.y\
    \ = _y;\n    return r;\n  }\n  friend R operator+(const R& l, const R& r) {\n\
    \    if (l.y == r.y) return R{l.x + r.x, l.y};\n    return R{l.x * r.y + l.y *\
    \ r.x, l.y * r.y};\n  }\n  friend R operator-(const R& l, const R& r) {\n    if\
    \ (l.y == r.y) return R{l.x - r.x, l.y};\n    return R{l.x * r.y - l.y * r.x,\
    \ l.y * r.y};\n  }\n  friend R operator*(const R& l, const R& r) { return R{l.x\
    \ * r.x, l.y * r.y}; }\n  friend R operator/(const R& l, const R& r) { return\
    \ R{l.x * r.y, l.y * r.x}; }\n  R& operator+=(const R& r) { return (*this) = (*this)\
    \ + r; }\n  R& operator-=(const R& r) { return (*this) = (*this) - r; }\n  R&\
    \ operator*=(const R& r) { return (*this) = (*this) * r; }\n  R& operator/=(const\
    \ R& r) { return (*this) = (*this) / r; }\n  R operator-() const { return raw(-x,\
    \ y); }\n  R inverse() const {\n    assert(x != 0);\n    R r = raw(y, x);\n  \
    \  if (r.y < 0) r.x = -r.x, r.y = -r.y;\n    return r;\n  }\n  R pow(long long\
    \ p) const {\n    R res{1}, base{*this};\n    while (p) {\n      if (p & 1) res\
    \ *= base;\n      base *= base;\n      p >>= 1;\n    }\n    return res;\n  }\n\
    \  friend bool operator==(const R& l, const R& r) {\n    return l.x == r.x &&\
    \ l.y == r.y;\n  };\n  friend bool operator!=(const R& l, const R& r) {\n    return\
    \ l.x != r.x || l.y != r.y;\n  };\n  friend bool operator<(const R& l, const R&\
    \ r) {\n    return U{l.x} * r.y < U{l.y} * r.x;\n  };\n  friend bool operator<=(const\
    \ R& l, const R& r) { return l < r || l == r; }\n  friend bool operator>(const\
    \ R& l, const R& r) {\n    return U{l.x} * r.y > U{l.y} * r.x;\n  };\n  friend\
    \ bool operator>=(const R& l, const R& r) { return l > r || l == r; }\n  friend\
    \ ostream& operator<<(ostream& os, const R& r) {\n    os << r.x;\n    if (r.x\
    \ != 0 && r.y != 1) os << \"/\" << r.y;\n    return os;\n  }\n\n  // T \u306B\u30AD\
    \u30E3\u30B9\u30C8\u3055\u308C\u308B\u306E\u3067 T \u304C bigint \u306E\u5834\u5408\
    \u306F to_ll \u3082\u8981\u308B\n  T to_mint(T mod) const {\n    assert(mod !=\
    \ 0);\n    T a = y, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t =\
    \ a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return\
    \ U((u % mod + mod) % mod) * x % mod;\n  }\n};\n\nusing Rational = RationalBase<long\
    \ long, __int128_t>;\n#line 4 \"math/rational-binomial.hpp\"\n\ntemplate <typename\
    \ R = Rational>\nstruct Binomial_rational {\n  vector<R> fc;\n  Binomial_rational(int\
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
    \ multinomial(r);\n  }\n};\n#line 5 \"math/rational-fps.hpp\"\n\ntemplate <typename\
    \ R = Rational>\nstruct FormalPowerSeries_rational : vector<R> {\n  using vector<R>::vector;\n\
    \  using fps = FormalPowerSeries_rational;\n\n  fps &operator+=(const fps &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n  }\n\n\
    \  fps &operator+=(const R &r) {\n    if (this->empty()) this->resize(1);\n  \
    \  (*this)[0] += r;\n    return *this;\n  }\n\n  fps &operator-=(const fps &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  fps &operator-=(const R &r) {\n    if (this->empty()) this->resize(1);\n  \
    \  (*this)[0] -= r;\n    return *this;\n  }\n\n  fps &operator*=(const fps &r)\
    \ {\n    int n = this->size() + r.size() - 1;\n    fps f(n);\n    for (int i =\
    \ 0; i < (int)this->size(); i++) {\n      for (int j = 0; j < (int)r.size(); j++)\
    \ {\n        f[i + j] += (*this)[i] * r[j];\n      }\n    }\n    return *this\
    \ = f;\n  }\n\n  fps &operator*=(const R &v) {\n    for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n\n  fps &operator/=(const fps\
    \ &r) {\n    if (this->size() < r.size()) {\n      this->clear();\n      return\
    \ *this;\n    }\n    int n = this->size() - r.size() + 1;\n    fps f(*this), g(r);\n\
    \    g.shrink();\n    R coeff = g.back().inverse();\n    for (auto &x : g) x *=\
    \ coeff;\n    int deg = (int)f.size() - (int)g.size() + 1;\n    int gs = g.size();\n\
    \    fps quo(deg);\n    for (int i = deg - 1; i >= 0; i--) {\n      quo[i] = f[i\
    \ + gs - 1];\n      for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n\
    \    }\n    *this = quo * coeff;\n    this->resize(n, R(0));\n    return *this;\n\
    \  }\n\n  fps &operator%=(const fps &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  fps operator+(const fps &r) const { return fps(*this)\
    \ += r; }\n  fps operator+(const R &v) const { return fps(*this) += v; }\n  fps\
    \ operator-(const fps &r) const { return fps(*this) -= r; }\n  fps operator-(const\
    \ R &v) const { return fps(*this) -= v; }\n  fps operator*(const fps &r) const\
    \ { return fps(*this) *= r; }\n  fps operator*(const R &v) const { return fps(*this)\
    \ *= v; }\n  fps operator/(const fps &r) const { return fps(*this) /= r; }\n \
    \ fps operator%(const fps &r) const { return fps(*this) %= r; }\n  fps operator-()\
    \ const {\n    fps ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == R(0)) this->pop_back();\n  }\n\n  fps rev()\
    \ const {\n    fps ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  fps dot(fps r) const {\n    fps ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\u3059\u308B\
    \n  fps pre(int sz) const {\n    fps ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n    return ret;\n  }\n\
    \n  fps operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n\
    \    fps ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  fps operator<<(int sz) const {\n    fps ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, R(0));\n    return ret;\n  }\n\n  fps diff() const {\n    const int n =\
    \ (int)this->size();\n    fps ret(max(0, n - 1));\n    R one(1), coeff(1);\n \
    \   for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n  \
    \    coeff += one;\n    }\n    return ret;\n  }\n\n  fps integral() const {\n\
    \    const int n = (int)this->size();\n    fps ret(n + 1);\n    for (int i = 0;\
    \ i < n; i++) ret[i + 1] = (*this)[i] / (i + 1);\n    return ret;\n  }\n\n  R\
    \ eval(R x) const {\n    R r = 0, w = 1;\n    for (auto &v : *this) r += w * v,\
    \ w *= x;\n    return r;\n  }\n\n  fps inv(int deg = -1) const {\n    assert((*this)[0]\
    \ != R(0));\n    if (deg == -1) deg = (*this).size();\n    fps ret{R(1) / (*this)[0]};\n\
    \    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret + ret - ret * ret *\
    \ (*this).pre(i << 1)).pre(i << 1);\n    }\n    return ret.pre(deg);\n  }\n  fps\
    \ log(int deg = -1) const {\n    assert(!(*this).empty() && (*this)[0] == R(1));\n\
    \    if (deg == -1) deg = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n  fps exp(int deg = -1) const {\n    assert((*this).size()\
    \ == 0 || (*this)[0] == R(0));\n    if (deg == -1) deg = (int)this->size();\n\
    \    fps ret{R(1)};\n    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret\
    \ * (pre(i << 1) + R(1) - ret.log(i << 1))).pre(i << 1);\n    }\n    return ret.pre(deg);\n\
    \  }\n  fps pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      fps ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != R(0)) {\n        R rev = R(1) / (*this)[i];\n   \
    \     fps ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret *=\
    \ (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size()\
    \ < deg) ret.resize(deg, R(0));\n        return ret;\n      }\n      if (__int128_t(i\
    \ + 1) * k >= deg) return fps(deg, R(0));\n    }\n    return fps(deg, R(0));\n\
    \  }\n};\n"
  code: "#pragma once\n\n#include \"rational-binomial.hpp\"\n#include \"rational.hpp\"\
    \n\ntemplate <typename R = Rational>\nstruct FormalPowerSeries_rational : vector<R>\
    \ {\n  using vector<R>::vector;\n  using fps = FormalPowerSeries_rational;\n\n\
    \  fps &operator+=(const fps &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  fps &operator+=(const R &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  fps &operator-=(const fps &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  fps &operator-=(const R &r) {\n    if (this->empty()) this->resize(1);\n  \
    \  (*this)[0] -= r;\n    return *this;\n  }\n\n  fps &operator*=(const fps &r)\
    \ {\n    int n = this->size() + r.size() - 1;\n    fps f(n);\n    for (int i =\
    \ 0; i < (int)this->size(); i++) {\n      for (int j = 0; j < (int)r.size(); j++)\
    \ {\n        f[i + j] += (*this)[i] * r[j];\n      }\n    }\n    return *this\
    \ = f;\n  }\n\n  fps &operator*=(const R &v) {\n    for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n    return *this;\n  }\n\n  fps &operator/=(const fps\
    \ &r) {\n    if (this->size() < r.size()) {\n      this->clear();\n      return\
    \ *this;\n    }\n    int n = this->size() - r.size() + 1;\n    fps f(*this), g(r);\n\
    \    g.shrink();\n    R coeff = g.back().inverse();\n    for (auto &x : g) x *=\
    \ coeff;\n    int deg = (int)f.size() - (int)g.size() + 1;\n    int gs = g.size();\n\
    \    fps quo(deg);\n    for (int i = deg - 1; i >= 0; i--) {\n      quo[i] = f[i\
    \ + gs - 1];\n      for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n\
    \    }\n    *this = quo * coeff;\n    this->resize(n, R(0));\n    return *this;\n\
    \  }\n\n  fps &operator%=(const fps &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  fps operator+(const fps &r) const { return fps(*this)\
    \ += r; }\n  fps operator+(const R &v) const { return fps(*this) += v; }\n  fps\
    \ operator-(const fps &r) const { return fps(*this) -= r; }\n  fps operator-(const\
    \ R &v) const { return fps(*this) -= v; }\n  fps operator*(const fps &r) const\
    \ { return fps(*this) *= r; }\n  fps operator*(const R &v) const { return fps(*this)\
    \ *= v; }\n  fps operator/(const fps &r) const { return fps(*this) /= r; }\n \
    \ fps operator%(const fps &r) const { return fps(*this) %= r; }\n  fps operator-()\
    \ const {\n    fps ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == R(0)) this->pop_back();\n  }\n\n  fps rev()\
    \ const {\n    fps ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  fps dot(fps r) const {\n    fps ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\u3059\u308B\
    \n  fps pre(int sz) const {\n    fps ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n    return ret;\n  }\n\
    \n  fps operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n\
    \    fps ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  fps operator<<(int sz) const {\n    fps ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, R(0));\n    return ret;\n  }\n\n  fps diff() const {\n    const int n =\
    \ (int)this->size();\n    fps ret(max(0, n - 1));\n    R one(1), coeff(1);\n \
    \   for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n  \
    \    coeff += one;\n    }\n    return ret;\n  }\n\n  fps integral() const {\n\
    \    const int n = (int)this->size();\n    fps ret(n + 1);\n    for (int i = 0;\
    \ i < n; i++) ret[i + 1] = (*this)[i] / (i + 1);\n    return ret;\n  }\n\n  R\
    \ eval(R x) const {\n    R r = 0, w = 1;\n    for (auto &v : *this) r += w * v,\
    \ w *= x;\n    return r;\n  }\n\n  fps inv(int deg = -1) const {\n    assert((*this)[0]\
    \ != R(0));\n    if (deg == -1) deg = (*this).size();\n    fps ret{R(1) / (*this)[0]};\n\
    \    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret + ret - ret * ret *\
    \ (*this).pre(i << 1)).pre(i << 1);\n    }\n    return ret.pre(deg);\n  }\n  fps\
    \ log(int deg = -1) const {\n    assert(!(*this).empty() && (*this)[0] == R(1));\n\
    \    if (deg == -1) deg = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n  fps exp(int deg = -1) const {\n    assert((*this).size()\
    \ == 0 || (*this)[0] == R(0));\n    if (deg == -1) deg = (int)this->size();\n\
    \    fps ret{R(1)};\n    for (int i = 1; i < deg; i <<= 1) {\n      ret = (ret\
    \ * (pre(i << 1) + R(1) - ret.log(i << 1))).pre(i << 1);\n    }\n    return ret.pre(deg);\n\
    \  }\n  fps pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      fps ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != R(0)) {\n        R rev = R(1) / (*this)[i];\n   \
    \     fps ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret *=\
    \ (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size()\
    \ < deg) ret.resize(deg, R(0));\n        return ret;\n      }\n      if (__int128_t(i\
    \ + 1) * k >= deg) return fps(deg, R(0));\n    }\n    return fps(deg, R(0));\n\
    \  }\n};\n"
  dependsOn:
  - math/rational-binomial.hpp
  - math/rational.hpp
  - internal/internal-type-traits.hpp
  - math-fast/gcd.hpp
  isVerificationFile: false
  path: math/rational-fps.hpp
  requiredBy:
  - math/bigint-all.hpp
  timestamp: '2023-09-05 21:46:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/rational-number.test.cpp
  - verify/verify-unit-test/bigrational.test.cpp
documentation_of: math/rational-fps.hpp
layout: document
redirect_from:
- /library/math/rational-fps.hpp
- /library/math/rational-fps.hpp.html
title: math/rational-fps.hpp
---
