---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rational-number.test.cpp
    title: verify/verify-unit-test/rational-number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rational.hpp\"\n\nstruct Rational {\n  using R = Rational;\n\
    \  using i128 = __int128_t;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  long long x, y;\n  Rational() : x(0), y(1) {}\n  Rational(long\
    \ long _x, long long _y = 1) : x(_x), y(_y) {\n    assert(y != 0);\n    if (_y\
    \ != 1) {\n      long long g = gcd(x, y);\n      if (g != 0) x /= g, y /= g;\n\
    \      if (y < 0) x = -x, y = -y;\n    }\n  }\n\n  u64 gcd(i64 A, i64 B) {\n \
    \   u64 a = A >= 0 ? A : -A;\n    u64 b = B >= 0 ? B : -B;\n    if (a == 0 ||\
    \ b == 0) return a + b;\n    int n = __builtin_ctzll(a);\n    int m = __builtin_ctzll(b);\n\
    \    a >>= n;\n    b >>= m;\n    while (a != b) {\n      int d = __builtin_ctzll(a\
    \ - b);\n      bool f = a > b;\n      u64 c = f ? a : b;\n      b = f ? b : a;\n\
    \      a = (c - b) >> d;\n    }\n    return a << min(n, m);\n  }\n\n  friend R\
    \ operator+(const R& l, const R& r) {\n    return R(l.x * r.y + l.y * r.x, l.y\
    \ * r.y);\n  }\n  friend R operator-(const R& l, const R& r) {\n    return R(l.x\
    \ * r.y - l.y * r.x, l.y * r.y);\n  }\n  friend R operator*(const R& l, const\
    \ R& r) { return R(l.x * r.x, l.y * r.y); }\n  friend R operator/(const R& l,\
    \ const R& r) {\n    assert(r.x != 0);\n    return R(l.x * r.y, l.y * r.x);\n\
    \  }\n  R& operator+=(const R& r) { return (*this) = (*this) + r; }\n  R& operator-=(const\
    \ R& r) { return (*this) = (*this) - r; }\n  R& operator*=(const R& r) { return\
    \ (*this) = (*this) * r; }\n  R& operator/=(const R& r) { return (*this) = (*this)\
    \ / r; }\n  R operator-() const {\n    R r;\n    r.x = -x, r.y = y;\n    return\
    \ r;\n  }\n  R inverse() const {\n    assert(x != 0);\n    R r;\n    r.x = y,\
    \ r.y = x;\n    if (x < 0) r.x = -r.x, r.y = -r.y;\n    return r;\n  }\n  R pow(long\
    \ long p) const {\n    R res(1), base(*this);\n    while (p) {\n      if (p &\
    \ 1) res *= base;\n      base *= base;\n      p >>= 1;\n    }\n    return res;\n\
    \  }\n\n  friend bool operator==(const R& l, const R& r) {\n    return l.x ==\
    \ r.x && l.y == r.y;\n  };\n  friend bool operator!=(const R& l, const R& r) {\n\
    \    return l.x != r.x || l.y != r.y;\n  };\n  friend bool operator<(const R&\
    \ l, const R& r) {\n    return i128(l.x) * r.y < i128(l.y) * r.x;\n  };\n  friend\
    \ bool operator<=(const R& l, const R& r) { return l < r || l == r; }\n  friend\
    \ bool operator>(const R& l, const R& r) {\n    return i128(l.x) * r.y > i128(l.y)\
    \ * r.x;\n  };\n  friend bool operator>=(const R& l, const R& r) { return l >\
    \ r || l == r; }\n  friend ostream& operator<<(ostream& os, const R& r) {\n  \
    \  os << r.x;\n    if (r.x != 0 && r.y != 1) os << \"/\" << r.y;\n    return os;\n\
    \  }\n\n  long long toMint(long long mod) {\n    assert(mod != 0);\n    i64 a\
    \ = y, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n    \
    \  swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return i128((u\
    \ % mod + mod) % mod) * x % mod;\n  }\n};\n\ntemplate <typename R = Rational>\n\
    struct Binomial {\n  vector<R> fc;\n  Binomial(int = 0) { fc.emplace_back(1);\
    \ }\n  void extend() {\n    int n = fc.size();\n    R nxt = fc.back() * n;\n \
    \   fc.push_back(nxt);\n  }\n  R fac(int n) {\n    while ((int)fc.size() <= n)\
    \ extend();\n    return fc[n];\n  }\n  R finv(int n) { return fac(n).inverse();\
    \ }\n  R inv(int n) { return R{1, max(n, 1)}; }\n  R C(int n, int r) {\n    if\
    \ (n < 0 or r < 0 or n < r) return R{0};\n    return fac(n) * finv(n - r) * finv(r);\n\
    \  }\n  R operator()(int n, int r) { return C(n, r); }\n};\n"
  code: "#pragma once\n\nstruct Rational {\n  using R = Rational;\n  using i128 =\
    \ __int128_t;\n  using i64 = long long;\n  using u64 = unsigned long long;\n \
    \ long long x, y;\n  Rational() : x(0), y(1) {}\n  Rational(long long _x, long\
    \ long _y = 1) : x(_x), y(_y) {\n    assert(y != 0);\n    if (_y != 1) {\n   \
    \   long long g = gcd(x, y);\n      if (g != 0) x /= g, y /= g;\n      if (y <\
    \ 0) x = -x, y = -y;\n    }\n  }\n\n  u64 gcd(i64 A, i64 B) {\n    u64 a = A >=\
    \ 0 ? A : -A;\n    u64 b = B >= 0 ? B : -B;\n    if (a == 0 || b == 0) return\
    \ a + b;\n    int n = __builtin_ctzll(a);\n    int m = __builtin_ctzll(b);\n \
    \   a >>= n;\n    b >>= m;\n    while (a != b) {\n      int d = __builtin_ctzll(a\
    \ - b);\n      bool f = a > b;\n      u64 c = f ? a : b;\n      b = f ? b : a;\n\
    \      a = (c - b) >> d;\n    }\n    return a << min(n, m);\n  }\n\n  friend R\
    \ operator+(const R& l, const R& r) {\n    return R(l.x * r.y + l.y * r.x, l.y\
    \ * r.y);\n  }\n  friend R operator-(const R& l, const R& r) {\n    return R(l.x\
    \ * r.y - l.y * r.x, l.y * r.y);\n  }\n  friend R operator*(const R& l, const\
    \ R& r) { return R(l.x * r.x, l.y * r.y); }\n  friend R operator/(const R& l,\
    \ const R& r) {\n    assert(r.x != 0);\n    return R(l.x * r.y, l.y * r.x);\n\
    \  }\n  R& operator+=(const R& r) { return (*this) = (*this) + r; }\n  R& operator-=(const\
    \ R& r) { return (*this) = (*this) - r; }\n  R& operator*=(const R& r) { return\
    \ (*this) = (*this) * r; }\n  R& operator/=(const R& r) { return (*this) = (*this)\
    \ / r; }\n  R operator-() const {\n    R r;\n    r.x = -x, r.y = y;\n    return\
    \ r;\n  }\n  R inverse() const {\n    assert(x != 0);\n    R r;\n    r.x = y,\
    \ r.y = x;\n    if (x < 0) r.x = -r.x, r.y = -r.y;\n    return r;\n  }\n  R pow(long\
    \ long p) const {\n    R res(1), base(*this);\n    while (p) {\n      if (p &\
    \ 1) res *= base;\n      base *= base;\n      p >>= 1;\n    }\n    return res;\n\
    \  }\n\n  friend bool operator==(const R& l, const R& r) {\n    return l.x ==\
    \ r.x && l.y == r.y;\n  };\n  friend bool operator!=(const R& l, const R& r) {\n\
    \    return l.x != r.x || l.y != r.y;\n  };\n  friend bool operator<(const R&\
    \ l, const R& r) {\n    return i128(l.x) * r.y < i128(l.y) * r.x;\n  };\n  friend\
    \ bool operator<=(const R& l, const R& r) { return l < r || l == r; }\n  friend\
    \ bool operator>(const R& l, const R& r) {\n    return i128(l.x) * r.y > i128(l.y)\
    \ * r.x;\n  };\n  friend bool operator>=(const R& l, const R& r) { return l >\
    \ r || l == r; }\n  friend ostream& operator<<(ostream& os, const R& r) {\n  \
    \  os << r.x;\n    if (r.x != 0 && r.y != 1) os << \"/\" << r.y;\n    return os;\n\
    \  }\n\n  long long toMint(long long mod) {\n    assert(mod != 0);\n    i64 a\
    \ = y, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n    \
    \  swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n    return i128((u\
    \ % mod + mod) % mod) * x % mod;\n  }\n};\n\ntemplate <typename R = Rational>\n\
    struct Binomial {\n  vector<R> fc;\n  Binomial(int = 0) { fc.emplace_back(1);\
    \ }\n  void extend() {\n    int n = fc.size();\n    R nxt = fc.back() * n;\n \
    \   fc.push_back(nxt);\n  }\n  R fac(int n) {\n    while ((int)fc.size() <= n)\
    \ extend();\n    return fc[n];\n  }\n  R finv(int n) { return fac(n).inverse();\
    \ }\n  R inv(int n) { return R{1, max(n, 1)}; }\n  R C(int n, int r) {\n    if\
    \ (n < 0 or r < 0 or n < r) return R{0};\n    return fac(n) * finv(n - r) * finv(r);\n\
    \  }\n  R operator()(int n, int r) { return C(n, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rational.hpp
  requiredBy: []
  timestamp: '2021-11-21 20:53:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/rational-number.test.cpp
documentation_of: math/rational.hpp
layout: document
redirect_from:
- /library/math/rational.hpp
- /library/math/rational.hpp.html
title: math/rational.hpp
---
