---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-math.hpp
    title: internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-montgomery-modint.hpp
    title: modint/arbitrary-montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: prime/miller-rabin.hpp
    title: Miller-Rabin primality test
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/primitive-root-ll.hpp
    title: math/primitive-root-ll.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primitive-root.test.cpp
    title: verify/verify-unit-test/primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
    title: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0002.test.cpp
    title: verify/verify-yuki/yuki-0002.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/prime/fast-factorize.md
    document_title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's\
      \ Rho)"
    links: []
  bundledCode: "#line 2 \"prime/fast-factorize.hpp\"\n\n#include <cstdint>\n#include\
    \ <numeric>\n#include <vector>\nusing namespace std;\n\n#line 2 \"internal/internal-math.hpp\"\
    \n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n#include <type_traits>\n\
    using namespace std;\n\nnamespace internal {\ntemplate <typename T>\nusing is_broadly_integral\
    \ =\n    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n\
    \                               is_same_v<T, __uint128_t>,\n                 \
    \          true_type, false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed\
    \ =\n    typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n\
    \                           true_type, false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
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
    \ 4 \"internal/internal-math.hpp\"\n\nnamespace internal {\n\n#include <cassert>\n\
    #include <utility>\n#line 10 \"internal/internal-math.hpp\"\nusing namespace std;\n\
    \n// a mod p\ntemplate <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n  if constexpr\
    \ (is_broadly_signed_v<T>) {\n    if (a < 0) a += p;\n  }\n  return a;\n}\n\n\
    // \u8FD4\u308A\u5024\uFF1Apair(g, x)\n// s.t. g = gcd(a, b), xa = g (mod b),\
    \ 0 <= x < b/g\ntemplate <typename T>\npair<T, T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n\
    \  a = safe_mod(a, p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n\
    \  while (a != 0) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -=\
    \ q * x);\n  }\n  if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\
    \u5024 : a^{-1} mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename\
    \ T>\nT inv(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  T b = p, x = 1, y = 0;\n  while (a != 0) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\n// T : \u5E95\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 \u304B\u3064 \u6307\u6570\u306E\u578B\
    \ntemplate <typename T, typename U>\nT modpow(T a, U n, T p) {\n  a = safe_mod(a,\
    \ p);\n  T ret = 1 % p;\n  while (n != 0) {\n    if (n % 2 == 1) ret = U(ret)\
    \ * a % p;\n    a = U(a) * a % p;\n    n /= 2;\n  }\n  return ret;\n}\n\n// \u8FD4\
    \u308A\u5024 : pair(rem, mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0,\
    \ 0} \u3092\u8FD4\u3059\ntemplate <typename T>\npair<T, T> crt(const vector<T>&\
    \ r, const vector<T>& m) {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size()\
    \ == m.size());\n  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i =\
    \ 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1\
    \ = m[i];\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0)\
    \ {\n      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto\
    \ [g, im] = inv_gcd(m0, m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return\
    \ {0, 0};\n    T x = (r1 - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0\
    \ *= u1;\n    if (r0 < 0) r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace\
    \ internal\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"internal/internal-seed.hpp\"\
    \n\n#include <chrono>\nusing namespace std;\n\nnamespace internal {\nunsigned\
    \ long long non_deterministic_seed() {\n  unsigned long long m =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >> 31, m\
    \ ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() { return\
    \ 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210 (\u624B\
    \u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\u51FA\
    \u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\u304F\
    \u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\u30B7\
    \u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long long\
    \ seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return deterministic_seed();\n\
    #else\n  return non_deterministic_seed();\n#endif\n}\n\n}  // namespace internal\n\
    #line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x\
    \ = internal::seed();\n  return _x ^= _x << 7, _x ^= _x >> 9;\n}\n\n// [l, r]\n\
    i64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return l + rng() % u64(r - l + 1);\n\
    }\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n  assert(l < r);\n  return l + rng()\
    \ % u64(r - l);\n}\n\n// choose n numbers from [l, r) without overlapping\nvector<i64>\
    \ randset(i64 l, i64 r, i64 n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64>\
    \ s;\n  for (i64 i = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if\
    \ (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n\
    \  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\ndouble\
    \ rnd() { return rng() * 5.42101086242752217004e-20; }\n// [l, r)\ndouble rnd(double\
    \ l, double r) {\n  assert(l < r);\n  return l + rnd() * (r - l);\n}\n\ntemplate\
    \ <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n  for (int\
    \ i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace my_rand\n\
    \nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"modint/arbitrary-montgomery-modint.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\ntemplate <typename Int, typename\
    \ UInt, typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt\
    \ mod;\n  inline static UInt r;\n  inline static UInt n2;\n  static constexpr\
    \ int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret\
    \ = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n\
    \  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length\
    \ - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n\
    \  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n#line 2 \"prime/miller-rabin.hpp\"\
    \n\n#line 4 \"prime/miller-rabin.hpp\"\nusing namespace std;\n\n#line 8 \"prime/miller-rabin.hpp\"\
    \n\nnamespace fast_factorize {\n\ntemplate <typename T, typename U>\nbool miller_rabin(const\
    \ T& n, vector<T> ws) {\n  if (n <= 2) return n == 2;\n  if (n % 2 == 0) return\
    \ false;\n\n  T d = n - 1;\n  while (d % 2 == 0) d /= 2;\n  U e = 1, rev = n -\
    \ 1;\n  for (T w : ws) {\n    if (w % n == 0) continue;\n    T t = d;\n    U y\
    \ = internal::modpow<T, U>(w, t, n);\n    while (t != n - 1 && y != e && y !=\
    \ rev) y = y * y % n, t *= 2;\n    if (y != rev && t % 2 == 0) return false;\n\
    \  }\n  return true;\n}\n\nbool miller_rabin_u64(unsigned long long n) {\n  return\
    \ miller_rabin<unsigned long long, __uint128_t>(\n      n, {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint>\nbool miller_rabin(unsigned\
    \ long long n, vector<unsigned long long> ws) {\n  if (n <= 2) return n == 2;\n\
    \  if (n % 2 == 0) return false;\n\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  unsigned long long d = n - 1;\n  while (~d & 1) d >>= 1;\n  mint e = 1, rev\
    \ = n - 1;\n  for (unsigned long long w : ws) {\n    if (w % n == 0) continue;\n\
    \    unsigned long long t = d;\n    mint y = mint(w).pow(t);\n    while (t !=\
    \ n - 1 && y != e && y != rev) y *= y, t *= 2;\n    if (y != rev && t % 2 == 0)\
    \ return false;\n  }\n  return true;\n}\n\nbool is_prime(unsigned long long n)\
    \ {\n  using mint32 = ArbitraryLazyMontgomeryModInt<96229631>;\n  using mint64\
    \ = ArbitraryLazyMontgomeryModInt64bit<622196072>;\n\n  if (n <= 2) return n ==\
    \ 2;\n  if (n % 2 == 0) return false;\n  if (n < (1uLL << 30)) {\n    return miller_rabin<mint32>(n,\
    \ {2, 7, 61});\n  } else if (n < (1uLL << 62)) {\n    return miller_rabin<mint64>(\n\
    \        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n  } else {\n\
    \    return miller_rabin_u64(n);\n  }\n}\n\n}  // namespace fast_factorize\n\n\
    using fast_factorize::is_prime;\n\n/**\n * @brief Miller-Rabin primality test\n\
    \ */\n#line 12 \"prime/fast-factorize.hpp\"\n\nnamespace fast_factorize {\nusing\
    \ u64 = uint64_t;\n\ntemplate <typename mint, typename T>\nT pollard_rho(T n)\
    \ {\n  if (~n & 1) return 2;\n  if (is_prime(n)) return n;\n  if (mint::get_mod()\
    \ != n) mint::set_mod(n);\n  mint R, one = 1;\n  auto f = [&](mint x) { return\
    \ x * x + R; };\n  auto rnd_ = [&]() { return rng() % (n - 2) + 2; };\n  while\
    \ (1) {\n    mint x, y, ys, q = one;\n    R = rnd_(), y = rnd_();\n    T g = 1;\n\
    \    constexpr int m = 128;\n    for (int r = 1; g == 1; r <<= 1) {\n      x =\
    \ y;\n      for (int i = 0; i < r; ++i) y = f(y);\n      for (int k = 0; g ==\
    \ 1 && k < r; k += m) {\n        ys = y;\n        for (int i = 0; i < m && i <\
    \ r - k; ++i) q *= x - (y = f(y));\n        g = gcd(q.get(), n);\n      }\n  \
    \  }\n    if (g == n) do\n        g = gcd((x - (ys = f(ys))).get(), n);\n    \
    \  while (g == 1);\n    if (g != n) return g;\n  }\n  exit(1);\n}\n\nusing i64\
    \ = long long;\n\nvector<i64> inner_factorize(u64 n) {\n  using mint32 = ArbitraryLazyMontgomeryModInt<452288976>;\n\
    \  using mint64 = ArbitraryLazyMontgomeryModInt64bit<401243123>;\n\n  if (n <=\
    \ 1) return {};\n  u64 p;\n  if (n <= (1LL << 30)) {\n    p = pollard_rho<mint32,\
    \ uint32_t>(n);\n  } else if (n <= (1LL << 62)) {\n    p = pollard_rho<mint64,\
    \ uint64_t>(n);\n  } else {\n    exit(1);\n  }\n  if (p == n) return {i64(p)};\n\
    \  auto l = inner_factorize(p);\n  auto r = inner_factorize(n / p);\n  copy(begin(r),\
    \ end(r), back_inserter(l));\n  return l;\n}\n\nvector<i64> factorize(u64 n) {\n\
    \  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n  return ret;\n\
    }\n\nmap<i64, i64> factor_count(u64 n) {\n  map<i64, i64> mp;\n  for (auto &x\
    \ : factorize(n)) mp[x]++;\n  return mp;\n}\n\nvector<i64> divisors(u64 n) {\n\
    \  if (n == 0) return {};\n  vector<pair<i64, i64>> v;\n  for (auto &p : factorize(n))\
    \ {\n    if (v.empty() || v.back().first != p) {\n      v.emplace_back(p, 1);\n\
    \    } else {\n      v.back().second++;\n    }\n  }\n  vector<i64> ret;\n  auto\
    \ f = [&](auto rc, int i, i64 x) -> void {\n    if (i == (int)v.size()) {\n  \
    \    ret.push_back(x);\n      return;\n    }\n    rc(rc, i + 1, x);\n    for (int\
    \ j = 0; j < v[i].second; j++) rc(rc, i + 1, x *= v[i].first);\n  };\n  f(f, 0,\
    \ 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\n}  // namespace fast_factorize\n\
    \nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\nusing\
    \ fast_factorize::factorize;\n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\u6570\u5206\
    \u89E3(Miller Rabin/Pollard's Rho)\n * @docs docs/prime/fast-factorize.md\n */\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\n#include \"../internal/internal-math.hpp\"\n#include \"\
    ../misc/rng.hpp\"\n#include \"../modint/arbitrary-montgomery-modint.hpp\"\n#include\
    \ \"miller-rabin.hpp\"\n\nnamespace fast_factorize {\nusing u64 = uint64_t;\n\n\
    template <typename mint, typename T>\nT pollard_rho(T n) {\n  if (~n & 1) return\
    \ 2;\n  if (is_prime(n)) return n;\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  mint R, one = 1;\n  auto f = [&](mint x) { return x * x + R; };\n  auto rnd_\
    \ = [&]() { return rng() % (n - 2) + 2; };\n  while (1) {\n    mint x, y, ys,\
    \ q = one;\n    R = rnd_(), y = rnd_();\n    T g = 1;\n    constexpr int m = 128;\n\
    \    for (int r = 1; g == 1; r <<= 1) {\n      x = y;\n      for (int i = 0; i\
    \ < r; ++i) y = f(y);\n      for (int k = 0; g == 1 && k < r; k += m) {\n    \
    \    ys = y;\n        for (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));\n\
    \        g = gcd(q.get(), n);\n      }\n    }\n    if (g == n) do\n        g =\
    \ gcd((x - (ys = f(ys))).get(), n);\n      while (g == 1);\n    if (g != n) return\
    \ g;\n  }\n  exit(1);\n}\n\nusing i64 = long long;\n\nvector<i64> inner_factorize(u64\
    \ n) {\n  using mint32 = ArbitraryLazyMontgomeryModInt<452288976>;\n  using mint64\
    \ = ArbitraryLazyMontgomeryModInt64bit<401243123>;\n\n  if (n <= 1) return {};\n\
    \  u64 p;\n  if (n <= (1LL << 30)) {\n    p = pollard_rho<mint32, uint32_t>(n);\n\
    \  } else if (n <= (1LL << 62)) {\n    p = pollard_rho<mint64, uint64_t>(n);\n\
    \  } else {\n    exit(1);\n  }\n  if (p == n) return {i64(p)};\n  auto l = inner_factorize(p);\n\
    \  auto r = inner_factorize(n / p);\n  copy(begin(r), end(r), back_inserter(l));\n\
    \  return l;\n}\n\nvector<i64> factorize(u64 n) {\n  auto ret = inner_factorize(n);\n\
    \  sort(begin(ret), end(ret));\n  return ret;\n}\n\nmap<i64, i64> factor_count(u64\
    \ n) {\n  map<i64, i64> mp;\n  for (auto &x : factorize(n)) mp[x]++;\n  return\
    \ mp;\n}\n\nvector<i64> divisors(u64 n) {\n  if (n == 0) return {};\n  vector<pair<i64,\
    \ i64>> v;\n  for (auto &p : factorize(n)) {\n    if (v.empty() || v.back().first\
    \ != p) {\n      v.emplace_back(p, 1);\n    } else {\n      v.back().second++;\n\
    \    }\n  }\n  vector<i64> ret;\n  auto f = [&](auto rc, int i, i64 x) -> void\
    \ {\n    if (i == (int)v.size()) {\n      ret.push_back(x);\n      return;\n \
    \   }\n    rc(rc, i + 1, x);\n    for (int j = 0; j < v[i].second; j++) rc(rc,\
    \ i + 1, x *= v[i].first);\n  };\n  f(f, 0, 1);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\n}  // namespace fast_factorize\n\nusing fast_factorize::divisors;\n\
    using fast_factorize::factor_count;\nusing fast_factorize::factorize;\n\n/**\n\
    \ * @brief \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n\
    \ * @docs docs/prime/fast-factorize.md\n */\n"
  dependsOn:
  - internal/internal-math.hpp
  - internal/internal-type-traits.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - modint/arbitrary-montgomery-modint.hpp
  - prime/miller-rabin.hpp
  isVerificationFile: false
  path: prime/fast-factorize.hpp
  requiredBy:
  - math/primitive-root-ll.hpp
  - modulo/mod-kth-root.hpp
  - ntt/multivariate-circular-convolution.hpp
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/osak.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-yuki/yuki-0002.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
documentation_of: prime/fast-factorize.hpp
layout: document
redirect_from:
- /library/prime/fast-factorize.hpp
- /library/prime/fast-factorize.hpp.html
title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
---
## 高速な素因数分解

ミラーラビン素数判定法とポラード・ロー素因数分解法を組み合わせることで$\mathrm{O}(N^{\frac{1}{4}})$で素因数分解を行うライブラリ。

#### ミラー・ラビン素数判定法(Miller-Rabin primality test)

ミラーラビン素数判定法とは、与えられた数が素数かを高速に判定する乱択アルゴリズム(実用上は決定的アルゴリズム)である。

まず、任意の奇素数$p$について、

$x^2\equiv 1 \mod p \leftrightarrow x=1,-1 \mod p$

が成り立つ。(証明は左辺を因数分解すると示せる。)ここで$p-1=2^s\cdot d$とおくと、上記の事実から

$$ a^d \equiv 1 \mod p$$

またはある$r(0 \leq r \leq s - 1)$について

$$a ^ {2^r \cdot d} \equiv -1 \mod p$$

が成り立つことが示せる。この命題の対偶を取ると、「奇数$n$についてある数$a$が存在し、『$a^d \not \equiv 1 \mod n$』かつ『任意の$r(0 \leq r \leq s - 1)$について$a ^ {2^r \cdot d} \equiv -1 \mod p$』ならば$n$は合成数」となる。

ミラーラビン法では$a$をランダムにいくつか選んで$a^{2^r\cdot d}\mod n$の値を調べ、いずれかの$a$で合成数と判定されたら$n$は合成数、そうでない場合は$n$が素数であると判定するアルゴリズムである。

実際に$a$をランダムに選ぶと誤判定が発生しうるが、$a=2, 325, 9375, 28178, 450775, 9780504, 1795265022$を選ぶと$n \lt 2^{64}$である$n$について正確に判定できることが知られており([参照](http://miller-rabin.appspot.com/))、実用上は上記の$a$を選んで実験することで決定的な素数判定が可能となる。

#### ポラード・ロー素因数分解法(Pollard's rho algorithm)

TODO:書く

参考文献　[Kiri8128さんの記事](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)　[高校数学の美しい物語](https://mathtrain.jp/rhoalgorithm)
