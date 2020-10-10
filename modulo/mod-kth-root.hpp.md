---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':question:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/modulo/mod-kth-root.md
    document_title: kth root(Tonelli-Shanks algorithm)
    links: []
  bundledCode: "#line 2 \"modulo/mod-kth-root.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"inner/inner_math.hpp\"\nusing namespace std;\n\n\
    namespace inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 =\
    \ int64_t;\nusing u64 = uint64_t;\n\ntemplate <typename T>\nT gcd(T a, T b) {\n\
    \  while (b) swap(a %= b, b);\n  return a;\n}\n\ntemplate <typename T>\nT inv(T\
    \ a, T p) {\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\ntemplate <typename T, typename U>\nT modpow(T a, U n, T p)\
    \ {\n  T ret = 1 % p;\n  for (; n; n >>= 1, a = U(a) * a % p)\n    if (n & 1)\
    \ ret = U(ret) * a % p;\n  return ret;\n}\n\n}  // namespace inner\n#line 3 \"\
    modint/arbitrary-prime-modint.hpp\"\nusing namespace std;\n\nstruct ArbitraryLazyMontgomeryModInt\
    \ {\n  using mint = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n \
    \ using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n  static\
    \ u32 r;\n  static u32 n2;\n\n  static u32 get_r() {\n    u32 ret = mod;\n   \
    \ for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static void set_mod(u32 m) {\n    assert(m < (1 << 30));\n    assert((m & 1)\
    \ == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n\
    \  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod\
    \ + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u64(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 3 \"modint/modint-montgomery64.hpp\"\
    \nusing namespace std;\n\nstruct montgomery64 {\n  using mint = montgomery64;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\
    \n  static u64 mod;\n  static u64 r;\n  static u64 n2;\n\n  static u64 get_r()\
    \ {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u64 m) {\n    assert(m < (1LL <<\
    \ 62));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n   \
    \ r = get_r();\n    assert(r * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64()\
    \ : a(0) {}\n  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\
    \n  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b) * u64(-r))\
    \ * mod) >> 64;\n  }\n\n  mint &operator+=(const mint &b) {\n    if (i64(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator-=(const\
    \ mint &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \n  mint &operator*=(const mint &b) {\n    a = reduce(u128(a) * b.a);\n    return\
    \ *this;\n  }\n\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n\
    \    return *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this)\
    \ += b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n\
    \  mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n  bool operator==(const mint &b)\
    \ const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n\
    \  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return\
    \ mint() - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 3 \"prime/fast-factorize.hpp\"\
    \nusing namespace std;\n\n#line 3 \"misc/rng.hpp\"\nusing namespace std;\n\nunsigned\
    \ long long rng() {\n  static unsigned long long x_ = 88172645463325252ULL;\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n#line 9 \"prime/fast-factorize.hpp\"\
    \n\nnamespace fast_factorize {\nusing u64 = uint64_t;\n\ntemplate <typename mint>\n\
    bool miller_rabin(u64 n, vector<u64> as) {\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  u64 d = n - 1;\n  while (~d & 1) d >>= 1;\n  mint e{1}, rev{int64_t(n - 1)};\n\
    \  for (u64 a : as) {\n    if (n <= a) break;\n    u64 t = d;\n    mint y = mint(a).pow(t);\n\
    \    while (t != n - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n\
    \    }\n    if (y != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\
    \nbool is_prime(u64 n) {\n  if (~n & 1) return n == 2;\n  if (n <= 1) return false;\n\
    \  if (n < (1LL << 30))\n    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n,\
    \ {2, 7, 61});\n  else\n    return miller_rabin<montgomery64>(\n        n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint,\
    \ typename T>\nT pollard_rho(T n) {\n  if (~n & 1) return 2;\n  if (is_prime(n))\
    \ return n;\n  if (mint::get_mod() != n) mint::set_mod(n);\n  mint R, one = 1;\n\
    \  auto f = [&](mint x) { return x * x + R; };\n  auto rnd = [&]() { return rng()\
    \ % (n - 2) + 2; };\n  while (1) {\n    mint x, y, ys, q = one;\n    R = rnd(),\
    \ y = rnd();\n    T g = 1;\n    constexpr int m = 128;\n    for (int r = 1; g\
    \ == 1; r <<= 1) {\n      x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n\
    \      for (int k = 0; g == 1 && k < r; k += m) {\n        ys = y;\n        for\
    \ (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));\n        g = inner::gcd<T>(q.get(),\
    \ n);\n      }\n    }\n    if (g == n) do\n        g = inner::gcd<T>((x - (ys\
    \ = f(ys))).get(), n);\n      while (g == 1);\n    if (g != n) return g;\n  }\n\
    \  exit(1);\n}\n\nvector<u64> inner_factorize(u64 n) {\n  if (n <= 1) return {};\n\
    \  u64 p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt,\
    \ uint32_t>(n);\n  else\n    p = pollard_rho<montgomery64, uint64_t>(n);\n  if\
    \ (p == n) return {p};\n  auto l = inner_factorize(p);\n  auto r = inner_factorize(n\
    \ / p);\n  copy(begin(r), end(r), back_inserter(l));\n  return l;\n}\n\nvector<u64>\
    \ factorize(u64 n) {\n  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\n}  // namespace fast_factorize\nusing fast_factorize::factorize;\n\
    using fast_factorize::is_prime;\n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\u6570\
    \u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs docs/prime/fast-factorize.md\n\
    \ */\n#line 9 \"modulo/mod-kth-root.hpp\"\n\nnamespace kth_root_mod {\n\n// fast\
    \ BS-GS\ntemplate <typename T>\nstruct Memo {\n  Memo(const T &g, int s, int period)\n\
    \      : size(1 << __lg(min(s, period))),\n        mask(size - 1),\n        period(period),\n\
    \        vs(size),\n        os(size + 1) {\n    T x(1);\n    for (int i = 0; i\
    \ < size; ++i, x *= g) os[x.get() & mask]++;\n    for (int i = 1; i < size; ++i)\
    \ os[i] += os[i - 1];\n    x = 1;\n    for (int i = 0; i < size; ++i, x *= g)\
    \ vs[--os[x.get() & mask]] = {x, i};\n    gpow = x;\n    os[size] = size;\n  }\n\
    \  int find(T x) const {\n    for (int t = 0; t < period; t += size, x *= gpow)\
    \ {\n      for (int m = (x.get() & mask), i = os[m]; i < os[m + 1]; ++i) {\n \
    \       if (x == vs[i].first) {\n          int ret = vs[i].second - t;\n     \
    \     return ret < 0 ? ret + period : ret;\n        }\n      }\n    }\n    assert(0);\n\
    \  }\n  T gpow;\n  int size, mask, period;\n  vector<pair<T, int> > vs;\n  vector<int>\
    \ os;\n};\n\nusing inner::gcd;\nusing inner::inv;\nusing inner::modpow;\ntemplate\
    \ <typename INT, typename LINT, typename mint>\nmint pe_root(INT c, INT pi, INT\
    \ ei, INT p) {\n  if (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);\n\
    \  INT s = p - 1, t = 0;\n  while (s % pi == 0) s /= pi, ++t;\n  INT pe = 1;\n\
    \  for (INT _ = 0; _ < ei; ++_) pe *= pi;\n\n  INT u = inv(pe - s % pe, pe);\n\
    \  mint mc = c, one = 1;\n  mint z = mc.pow((s * u + 1) / pe);\n  mint zpe = mc.pow(s\
    \ * u);\n  if (zpe == one) return z;\n  assert(t > ei);\n  \n  mint vs;\n  {\n\
    \    INT ptm1 = 1;\n    for (INT _ = 0; _ < t - 1; ++_) ptm1 *= pi;\n    for (mint\
    \ v = 2;; v += one) {\n      vs = v.pow(s);\n      if (vs.pow(ptm1) != one) break;\n\
    \    }\n  }\n\n  mint vspe = vs.pow(pe);\n  INT vs_e = ei;\n  mint base = vspe;\n\
    \  for (INT _ = 0; _ < t - ei - 1; _++) base = base.pow(pi);\n  Memo<mint> memo(base,\
    \ (INT)(sqrt(t - ei) * sqrt(pi)) + 1, pi);\n\n  while (zpe != one) {\n    mint\
    \ tmp = zpe;\n    INT td = 0;\n    while (tmp != 1) ++td, tmp = tmp.pow(pi);\n\
    \    INT e = t - td;\n    while (vs_e != e) {\n      vs = vs.pow(pi);\n      vspe\
    \ = vspe.pow(pi);\n      ++vs_e;\n    }\n\n    // BS-GS ... find (zpe * ( vspe\
    \ ^ n ) ) ^( p_i ^ (td - 1) ) = 1\n    mint base_zpe = zpe.inverse();\n    for\
    \ (INT _ = 0; _ < td - 1; _++) base_zpe = base_zpe.pow(pi);\n    INT bsgs = memo.find(base_zpe);\n\
    \n    z *= vs.pow(bsgs);\n    zpe *= vspe.pow(bsgs);\n  }\n  return z;\n}\n\n\
    template <typename INT, typename LINT, typename mint>\nINT inner_kth_root(INT\
    \ a, INT k, INT p) {\n  a %= p;\n  if (k == 0) return a == 1 ? a : -1;\n  if (a\
    \ <= 1 || k <= 1) return a;\n  assert(p > 2);\n  if (mint::get_mod() != decltype(mint::a)(p))\
    \ mint::set_mod(p);\n  INT g = gcd(p - 1, k);\n  if (modpow<INT, LINT>(a, (p -\
    \ 1) / g, p) != 1) return -1;\n  a = mint(a).pow(inv(k / g, (p - 1) / g)).get();\n\
    \  unordered_map<INT, int> fac;\n  for (auto &f : factorize(g)) fac[f]++;\n  if\
    \ (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);\n  for (auto pp\
    \ : fac)\n    a = pe_root<INT, LINT, mint>(a, pp.first, pp.second, p).get();\n\
    \  return a;\n}\n\nint64_t kth_root(int64_t a, int64_t k, int64_t p) {\n  if (max({a,\
    \ k, p}) < (1LL << 30))\n    return inner_kth_root<int32_t, int64_t, ArbitraryLazyMontgomeryModInt>(a,\
    \ k,\n                                                                       \
    \    p);\n  else\n    return inner_kth_root<int64_t, __int128_t, montgomery64>(a,\
    \ k, p);\n}\n\n}  // namespace kth_root_mod\nusing kth_root_mod::kth_root;\n\n\
    /**\n * @brief kth root(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-kth-root.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../inner/inner_math.hpp\"\n#include \"../modint/arbitrary-prime-modint.hpp\"\
    \n#include \"../modint/modint-montgomery64.hpp\"\n#include \"../prime/fast-factorize.hpp\"\
    \n\nnamespace kth_root_mod {\n\n// fast BS-GS\ntemplate <typename T>\nstruct Memo\
    \ {\n  Memo(const T &g, int s, int period)\n      : size(1 << __lg(min(s, period))),\n\
    \        mask(size - 1),\n        period(period),\n        vs(size),\n       \
    \ os(size + 1) {\n    T x(1);\n    for (int i = 0; i < size; ++i, x *= g) os[x.get()\
    \ & mask]++;\n    for (int i = 1; i < size; ++i) os[i] += os[i - 1];\n    x =\
    \ 1;\n    for (int i = 0; i < size; ++i, x *= g) vs[--os[x.get() & mask]] = {x,\
    \ i};\n    gpow = x;\n    os[size] = size;\n  }\n  int find(T x) const {\n   \
    \ for (int t = 0; t < period; t += size, x *= gpow) {\n      for (int m = (x.get()\
    \ & mask), i = os[m]; i < os[m + 1]; ++i) {\n        if (x == vs[i].first) {\n\
    \          int ret = vs[i].second - t;\n          return ret < 0 ? ret + period\
    \ : ret;\n        }\n      }\n    }\n    assert(0);\n  }\n  T gpow;\n  int size,\
    \ mask, period;\n  vector<pair<T, int> > vs;\n  vector<int> os;\n};\n\nusing inner::gcd;\n\
    using inner::inv;\nusing inner::modpow;\ntemplate <typename INT, typename LINT,\
    \ typename mint>\nmint pe_root(INT c, INT pi, INT ei, INT p) {\n  if (mint::get_mod()\
    \ != decltype(mint::a)(p)) mint::set_mod(p);\n  INT s = p - 1, t = 0;\n  while\
    \ (s % pi == 0) s /= pi, ++t;\n  INT pe = 1;\n  for (INT _ = 0; _ < ei; ++_) pe\
    \ *= pi;\n\n  INT u = inv(pe - s % pe, pe);\n  mint mc = c, one = 1;\n  mint z\
    \ = mc.pow((s * u + 1) / pe);\n  mint zpe = mc.pow(s * u);\n  if (zpe == one)\
    \ return z;\n  assert(t > ei);\n  \n  mint vs;\n  {\n    INT ptm1 = 1;\n    for\
    \ (INT _ = 0; _ < t - 1; ++_) ptm1 *= pi;\n    for (mint v = 2;; v += one) {\n\
    \      vs = v.pow(s);\n      if (vs.pow(ptm1) != one) break;\n    }\n  }\n\n \
    \ mint vspe = vs.pow(pe);\n  INT vs_e = ei;\n  mint base = vspe;\n  for (INT _\
    \ = 0; _ < t - ei - 1; _++) base = base.pow(pi);\n  Memo<mint> memo(base, (INT)(sqrt(t\
    \ - ei) * sqrt(pi)) + 1, pi);\n\n  while (zpe != one) {\n    mint tmp = zpe;\n\
    \    INT td = 0;\n    while (tmp != 1) ++td, tmp = tmp.pow(pi);\n    INT e = t\
    \ - td;\n    while (vs_e != e) {\n      vs = vs.pow(pi);\n      vspe = vspe.pow(pi);\n\
    \      ++vs_e;\n    }\n\n    // BS-GS ... find (zpe * ( vspe ^ n ) ) ^( p_i ^\
    \ (td - 1) ) = 1\n    mint base_zpe = zpe.inverse();\n    for (INT _ = 0; _ <\
    \ td - 1; _++) base_zpe = base_zpe.pow(pi);\n    INT bsgs = memo.find(base_zpe);\n\
    \n    z *= vs.pow(bsgs);\n    zpe *= vspe.pow(bsgs);\n  }\n  return z;\n}\n\n\
    template <typename INT, typename LINT, typename mint>\nINT inner_kth_root(INT\
    \ a, INT k, INT p) {\n  a %= p;\n  if (k == 0) return a == 1 ? a : -1;\n  if (a\
    \ <= 1 || k <= 1) return a;\n  assert(p > 2);\n  if (mint::get_mod() != decltype(mint::a)(p))\
    \ mint::set_mod(p);\n  INT g = gcd(p - 1, k);\n  if (modpow<INT, LINT>(a, (p -\
    \ 1) / g, p) != 1) return -1;\n  a = mint(a).pow(inv(k / g, (p - 1) / g)).get();\n\
    \  unordered_map<INT, int> fac;\n  for (auto &f : factorize(g)) fac[f]++;\n  if\
    \ (mint::get_mod() != decltype(mint::a)(p)) mint::set_mod(p);\n  for (auto pp\
    \ : fac)\n    a = pe_root<INT, LINT, mint>(a, pp.first, pp.second, p).get();\n\
    \  return a;\n}\n\nint64_t kth_root(int64_t a, int64_t k, int64_t p) {\n  if (max({a,\
    \ k, p}) < (1LL << 30))\n    return inner_kth_root<int32_t, int64_t, ArbitraryLazyMontgomeryModInt>(a,\
    \ k,\n                                                                       \
    \    p);\n  else\n    return inner_kth_root<int64_t, __int128_t, montgomery64>(a,\
    \ k, p);\n}\n\n}  // namespace kth_root_mod\nusing kth_root_mod::kth_root;\n\n\
    /**\n * @brief kth root(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-kth-root.md\n\
    \ */\n"
  dependsOn:
  - inner/inner_math.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  - prime/fast-factorize.hpp
  - misc/rng.hpp
  isVerificationFile: false
  path: modulo/mod-kth-root.hpp
  requiredBy: []
  timestamp: '2020-09-20 01:55:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
documentation_of: modulo/mod-kth-root.hpp
layout: document
redirect_from:
- /library/modulo/mod-kth-root.hpp
- /library/modulo/mod-kth-root.hpp.html
title: kth root(Tonelli-Shanks algorithm)
---

## kth root

整数$a,k$、素数$p$に対して$x^k \equiv a \mod p$を満たす$x$を$\mathrm{O}(\min (p,k)^{\frac{1}{4}})$で計算するライブラリ。

#### 概要

[37zigenさんの解説](https://yukicoder.me/problems/no/981/editorial)を参考にしました。

原始根を利用して考察する。$\mod p$上の原始根を$r$と置き、$x\equiv r^y,a\equiv r^b$とすると上の等式は

$$x^k \equiv a \mod p \leftrightarrow ky \equiv b \mod p-1$$

と言い換えられる。ここで$g = \gcd(k,p-1)$と置くと、上の合同式が成り立つ条件は$b \equiv 0 \mod g$であることがわかる。よって、

- $b \not \equiv 0 \mod g$の場合は解が存在しない。
- $b \equiv 0 \mod g$の場合は、$\frac{k}{g}$と$\frac{p-1}{g}$が互いに素なので$\left(\frac{k}{g}\right)^{-1}\mod \frac{p-1}{g}$が存在して、この時$y \equiv \frac{b}{g} \left(\frac{k}{g}\right)^{-1}\mod \frac{p-1}{g}$が解となる。

以上より解を求めることが出来たが、このままでは計算量は離散対数問題と同じ$\mathrm{O}(\sqrt{p})$なので、[mod sqrt](https://nyaannyaan.github.io/library/library/modulo/mod-sqrt.hpp.html)の時と同様にTonelli-Shanks algorithmを利用して高速化を図る。

まず、解の存在条件は

$$b \equiv 0 \mod g$$

$$\leftrightarrow \frac{b(p-1)}{g}\equiv 0 \mod p-1$$

$$\leftrightarrow a^\frac{p-1}{g} \equiv 1 \mod p$$

となる。以下は解が存在する時のみ考える。

$k\left(gk^{-1} \mod \frac{p-1}{g}\right)\equiv g\mod p-1$であるから、与式は

$$x^k \equiv a \mod p \leftrightarrow x^g\equiv \mathrm{pow}\left(a,gk^{-1} \mod \frac{p-1}{g}\right)\mod p$$

となる。(このように$x$の底を$k$から$g$に変換することで、$g\mid p-1$の性質を利用したToneli-Shanksのアルゴリズムが適用可能になる。)ここで$g = \Pi_i p_i^{e_i}$と置いたとき、

$$z^{p_i^{e_i}}\equiv c \mod p \ \ \ \cdots (\ast)$$

を解くことが出来れば、($\ast$)を繰り返し元の式に適用することで$x$を求めることが出来る。よって($\ast$)を高速に計算する方法を考えればよく、この問題は[mod sqrt](https://nyaannyaan.github.io/library/library/modulo/mod-sqrt.hpp.html)と同様にしてTonelli-Shanksのアルゴリズムが適用出来る。

原始根$r$に対して$r^w=z,r^d=c,p-1=sp_i^t$($\gcd(s,p_i)=1$)とおくと、

$$(\ast) \leftrightarrow p_i^{e_i}w\equiv d\mod p$$

$$\leftrightarrow p_i^{e_i}w\equiv d\mod s\ \wedge p_i^{e_i} w\equiv d\mod p_i^t$$

となる。ここで、$\left(-s^{-1} \mod {p_i}^{e_i}\right)=u$と置き、$z$の初期値を$z_0 \equiv \mathrm{pow}(c,\frac{su+1}{ {p_i}^{e_i}}) \mod p$とおくと、

$$p_i^{e_i}w_0 \equiv d(su+1) \mod p-1$$

$$\leftrightarrow p_i^{e_i}w_0\equiv d\mod s\ \wedge p_i^{e_i} w\equiv d(su+1)\mod p_i^t$$

となるので$\mod s$の方は条件を満たしており、$\mod p_i^{t_i}$を調整すればよいとわかる。

ここで、$\mathrm{pow}\left(v,\frac{p-1}{p_i}\right)\not\equiv 1$である$v$を乱択で選ぶ。(条件を満たす$v$は$1-\frac{1}{p_i}$の確率で手に入る。)この時、

$$\mathrm{Ind}_r v^{s} \equiv 0\mod s\ ,\mathrm{Ind}_r v^s \not\equiv 0\mod p_i$$

が成り立つ。($\mathrm{Ind}_r$は$r$を底、$p$を法としたときの指数。)この$v^s$を利用してTonelli-Shanks algorithmを実行する。

まず、現在の$z$の誤差項$p_i^{e^i} z - d\mod p_i^{e_i}$の誤差が$np_i^e$と表せるとする。この時$e$は、$c^{-1}z^{p_i^{e_i}}$を$p_i$乗していって$1$になるまでにかかった回数を$t'$としたときに
$e=t-t'$となる。$e$が分かったら、$z^{ {p_i}^{t'-1}}\equiv 1$を満たすまで$z$に$\mathrm{pow}(v^s,p^{e-e_i})$を掛け続ける。このアルゴリズムを$t'=0$になるまで繰り返せば$z$を求めることが出来る。

このままだとTonelli-Shanksのループ一回あたり最大$p_i-1$回の乗算が必要となるが、最後の$\mathrm{pow}(v^s,2^{e-e_i})$を掛ける所でBaby Step Giant Stepを利用することで、ループあたりの乗算回数を$\mathrm{O}(\sqrt{p_i})$回に落とすことが出来る。

また、Tonelli-Shanksのループ回数は高々$\lfloor\log_{p_i}p\rfloor - 1$回となる。つまり、$t=e_i=1$の時($g$と$p-1$がともに$p_i$で1回ずつしか割り切れないとき)はループに入らないので、$p_i > \sqrt{p-1}$である素数に対しては高速に解が計算できるとわかる。よって、全体の計算量は$g=\gcd(k,p-1)$が$\mathrm{O}(\sqrt{p})$程度の重複度2の素因数を含む時が最大で、この時$\mathrm{O}(g^{\frac{1}{4}})=\mathrm{O}(\min (p,k)^{\frac{1}{4}})$となる。

$g$の素因数分解も[Millar-rabinとPollardの$\rho$法](https://nyaannyaan.github.io/library/prime/fast-factorize.hpp)を利用すれば$\mathrm{O}(g^{\frac{1}{4}})$で計算できるので、全体の計算量は$\mathrm{O}(\min (p,k)^{\frac{1}{4}})$となる。
