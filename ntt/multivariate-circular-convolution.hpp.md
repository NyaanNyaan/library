---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: internal/internal-math.hpp
    title: internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-modint.hpp
    title: "modint (2^{30} \u672A\u6E80\u306E\u4EFB\u610F mod)"
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/barrett-reduction.hpp
    title: modint/barrett-reduction.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/chirp-z.hpp
    title: Chirp Z-transform(Bluestein's algorithm)
  - icon: ':heavy_check_mark:'
    path: ntt/multidimensional-ntt.hpp
    title: "\u591A\u6B21\u5143FFT"
  - icon: ':heavy_check_mark:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 2 \"ntt/multivariate-circular-convolution.hpp\"\n//\n#include\
    \ <cassert>\n#include <unordered_map>\n#include <vector>\nusing namespace std;\n\
    \n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct\
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
    \ deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if (deg) ret[0] = 1;\n\
    \      return ret;\n    }\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i]\
    \ != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n  \
    \      ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if (__int128_t(i + 1) * k >=\
    \ deg) return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n\
    \  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS\
    \ &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n\
    \  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate\
    \ <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n\
    \ * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line 2 \"\
    internal/internal-math.hpp\"\n\n#line 2 \"internal/internal-type-traits.hpp\"\n\
    \n#include <type_traits>\nusing namespace std;\n\nnamespace internal {\ntemplate\
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
    \                                              \\\n  template <class, class =\
    \ void>                                         \\\n  struct has_##var : std::false_type\
    \ {};                                 \\\n  template <class T>               \
    \                                      \\\n  struct has_##var<T, std::void_t<typename\
    \ T::var>> : std::true_type {}; \\\n  template <class T>                     \
    \                                \\\n  constexpr auto has_##var##_v = has_##var<T>::value;\n\
    \n}  // namespace internal\n#line 4 \"internal/internal-math.hpp\"\n\nnamespace\
    \ internal {\n\n#line 8 \"internal/internal-math.hpp\"\nusing namespace std;\n\
    \n// a mod p\ntemplate <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n  if constexpr\
    \ (is_broadly_signed_v<T>) {\n    if (a < 0) a += p;\n  }\n  return a;\n}\n\n\
    // \u8FD4\u308A\u5024\uFF1Apair(g, x)\n// s.t. g = gcd(a, b), xa = g (mod b),\
    \ 0 <= x < b/g\ntemplate <typename T>\npair<T, T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n\
    \  a = safe_mod(a, p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n\
    \  while (a) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n\
    \  }\n  if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\u5024 :\
    \ a^{-1} mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\n\
    T inv(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\n// T : \u5024\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\ntemplate <typename T, typename\
    \ U>\nT modpow(T a, __int128_t n, T p) {\n  a = safe_mod(a, p);\n  T ret = 1 %\
    \ p;\n  while (n) {\n    if (n & 1) ret = U(ret) * a % p;\n    a = U(a) * a %\
    \ p;\n    n >>= 1;\n  }\n  return ret;\n}\n\n// \u8FD4\u308A\u5024 : pair(rem,\
    \ mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0, 0} \u3092\u8FD4\u3059\
    \ntemplate <typename T>\npair<T, T> crt(const vector<T>& r, const vector<T>& m)\
    \ {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size() == m.size());\n\
    \  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i = 0; i < n; i++)\
    \ {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1 = m[i];\n   \
    \ if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0) {\n      if\
    \ (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto [g, im] = inv_gcd(m0,\
    \ m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return {0, 0};\n    T x = (r1\
    \ - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0 *= u1;\n    if (r0 < 0)\
    \ r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace internal\n#line 2 \"\
    math/primitive-root.hpp\"\n\nconstexpr uint32_t PrimitiveRoot(uint32_t mod) {\n\
    \  using u64 = uint64_t;\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n  int\
    \ idx = 0;\n  u64 m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n    if (m\
    \ % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n    }\n\
    \  }\n  if (m != 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n    int\
    \ flg = 1;\n    for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b = (mod -\
    \ 1) / ds[i], r = 1;\n      while (b) {\n        if (b & 1) r = r * a % mod;\n\
    \        a = a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1) {\n  \
    \      flg = 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n  \
    \  ++pr;\n  }\n  return pr;\n}\n\n/**\n * @brief \u539F\u59CB\u6839\n */\n#line\
    \ 2 \"modint/arbitrary-modint.hpp\"\n\n#line 2 \"modint/barrett-reduction.hpp\"\
    \n\n#include <utility>\nusing namespace std;\n\nstruct Barrett {\n  using u32\
    \ = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned long long;\n\
    \  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n) : m(n), im(u64(-1)\
    \ / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? x - 1 : x;\n  }\n\
    \  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >>\
    \ 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n  constexpr\
    \ inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im)\
    \ >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n  \
    \  return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32 a\
    \ = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    };\n#line 4 \"modint/arbitrary-modint.hpp\"\n\ntemplate <int id>\nstruct ArbitraryModIntBase\
    \ {\n  int x;\n\n  ArbitraryModIntBase() : x(0) {}\n\n  ArbitraryModIntBase(int64_t\
    \ y) {\n    int z = y % get_mod();\n    if (z < 0) z += get_mod();\n    x = z;\n\
    \  }\n\n  ArbitraryModIntBase &operator+=(const ArbitraryModIntBase &p) {\n  \
    \  if ((x += p.x) >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ &operator-=(const ArbitraryModIntBase &p) {\n    if ((x += get_mod() - p.x)\
    \ >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ &operator*=(const ArbitraryModIntBase &p) {\n    x = rem((unsigned long long)x\
    \ * p.x);\n    return *this;\n  }\n\n  ArbitraryModIntBase &operator/=(const ArbitraryModIntBase\
    \ &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ operator-() const { return ArbitraryModIntBase(-x); }\n\n  ArbitraryModIntBase\
    \ operator+(const ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this)\
    \ += p;\n  }\n\n  ArbitraryModIntBase operator-(const ArbitraryModIntBase &p)\
    \ const {\n    return ArbitraryModIntBase(*this) -= p;\n  }\n\n  ArbitraryModIntBase\
    \ operator*(const ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this)\
    \ *= p;\n  }\n\n  ArbitraryModIntBase operator/(const ArbitraryModIntBase &p)\
    \ const {\n    return ArbitraryModIntBase(*this) /= p;\n  }\n\n  bool operator==(const\
    \ ArbitraryModIntBase &p) const { return x == p.x; }\n\n  bool operator!=(const\
    \ ArbitraryModIntBase &p) const { return x != p.x; }\n\n  ArbitraryModIntBase\
    \ inverse() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while\
    \ (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t *\
    \ v, v);\n    }\n    return ArbitraryModIntBase(u);\n  }\n\n  ArbitraryModIntBase\
    \ pow(int64_t n) const {\n    ArbitraryModIntBase ret(1), mul(x);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const\
    \ ArbitraryModIntBase &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream\
    \ &is, ArbitraryModIntBase &a) {\n    int64_t t;\n    is >> t;\n    a = ArbitraryModIntBase(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned\
    \ int rem(unsigned long long p) { return barrett().rem(p); }\n\n  static inline\
    \ Barrett &barrett() {\n    static Barrett b;\n    return b;\n  }\n\n  static\
    \ inline int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\n \
    \ static void set_mod(int md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n\
    \    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n\nusing ArbitraryModInt\
    \ = ArbitraryModIntBase<-1>;\n\n/**\n * @brief modint (2^{30} \u672A\u6E80\u306E\
    \u4EFB\u610F mod)\n */\n#line 2 \"prime/fast-factorize.hpp\"\n\n#include <cstdint>\n\
    #include <numeric>\n#line 6 \"prime/fast-factorize.hpp\"\nusing namespace std;\n\
    \n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x\
    \ =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n              chrono::high_resolution_clock::now().time_since_epoch())\n\
    \              .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n\
    \  return _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l\
    \ <= r);\n  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l,\
    \ i64 r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n\
    \ numbers from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64\
    \ n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i\
    \ = n; i; --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end())\
    \ m = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"modint/arbitrary-prime-modint.hpp\"\
    \n\n\n\nstruct ArbitraryLazyMontgomeryModInt {\n  using mint = ArbitraryLazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static u32 mod;\n  static u32 r;\n  static u32 n2;\n\n  static u32 get_r()\
    \ {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u32 m) {\n    assert(m < (1 <<\
    \ 30));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r\
    \ = get_r();\n    assert(r * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt()\
    \ : a(0) {}\n  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b\
    \ + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint\
    \ &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const\
    \ mint &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b)\
    \ const { return mint(*this) -= b; }\n  mint operator*(const mint &b) const {\
    \ return mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
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
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 2 \"modint/modint-montgomery64.hpp\"\
    \n\n\n\nstruct montgomery64 {\n  using mint = montgomery64;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\n  static u64 mod;\n \
    \ static u64 r;\n  static u64 n2;\n\n  static u64 get_r() {\n    u64 ret = mod;\n\
    \    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\
    \n  static void set_mod(u64 m) {\n    assert(m < (1LL << 62));\n    assert((m\
    \ & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64() : a(0) {}\n  montgomery64(const\
    \ int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\n  static u64 reduce(const\
    \ u128 &b) {\n    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i64(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u128(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 12 \"prime/fast-factorize.hpp\"\
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
    \  auto f = [&](mint x) { return x * x + R; };\n  auto rnd_ = [&]() { return rng()\
    \ % (n - 2) + 2; };\n  while (1) {\n    mint x, y, ys, q = one;\n    R = rnd_(),\
    \ y = rnd_();\n    T g = 1;\n    constexpr int m = 128;\n    for (int r = 1; g\
    \ == 1; r <<= 1) {\n      x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n\
    \      for (int k = 0; g == 1 && k < r; k += m) {\n        ys = y;\n        for\
    \ (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));\n        g = gcd(q.get(),\
    \ n);\n      }\n    }\n    if (g == n) do\n        g = gcd((x - (ys = f(ys))).get(),\
    \ n);\n      while (g == 1);\n    if (g != n) return g;\n  }\n  exit(1);\n}\n\n\
    using i64 = long long;\n\nvector<i64> inner_factorize(u64 n) {\n  if (n <= 1)\
    \ return {};\n  u64 p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt,\
    \ uint32_t>(n);\n  else\n    p = pollard_rho<montgomery64, uint64_t>(n);\n  if\
    \ (p == n) return {i64(p)};\n  auto l = inner_factorize(p);\n  auto r = inner_factorize(n\
    \ / p);\n  copy(begin(r), end(r), back_inserter(l));\n  return l;\n}\n\nvector<i64>\
    \ factorize(u64 n) {\n  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\nmap<i64, i64> factor_count(u64 n) {\n  map<i64, i64> mp;\n\
    \  for (auto &x : factorize(n)) mp[x]++;\n  return mp;\n}\n\nvector<i64> divisors(u64\
    \ n) {\n  if (n == 0) return {};\n  vector<pair<i64, i64>> v;\n  for (auto &p\
    \ : factorize(n)) {\n    if (v.empty() || v.back().first != p) {\n      v.emplace_back(p,\
    \ 1);\n    } else {\n      v.back().second++;\n    }\n  }\n  vector<i64> ret;\n\
    \  auto f = [&](auto rc, int i, i64 x) -> void {\n    if (i == (int)v.size())\
    \ {\n      ret.push_back(x);\n      return;\n    }\n    for (int j = v[i].second;;\
    \ --j) {\n      rc(rc, i + 1, x);\n      if (j == 0) break;\n      x *= v[i].first;\n\
    \    }\n  };\n  f(f, 0, 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\
    \n}  // namespace fast_factorize\n\nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\n\
    using fast_factorize::factorize;\nusing fast_factorize::is_prime;\n\n/**\n * @brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs\
    \ docs/prime/fast-factorize.md\n */\n#line 2 \"ntt/chirp-z.hpp\"\n\n#line 2 \"\
    ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate\
    \ <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"ntt/ntt.hpp\"\n\ntemplate <typename mint>\nstruct\
    \ NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t _mod = mint::get_mod();\n\
    \    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int idx = 0;\n    u64 m\
    \ = _mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n      if (m % i == 0) {\n\
    \        ds[idx++] = i;\n        while (m % i == 0) m /= i;\n      }\n    }\n\
    \    if (m != 1) ds[idx++] = m;\n\n    uint32_t _pr = 2;\n    while (1) {\n  \
    \    int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n        u64 a = _pr,\
    \ b = (_mod - 1) / ds[i], r = 1;\n        while (b) {\n          if (b & 1) r\
    \ = r * a % _mod;\n          a = a * a % _mod;\n          b >>= 1;\n        }\n\
    \        if (r == 1) {\n          flg = 0;\n          break;\n        }\n    \
    \  }\n      if (flg == 1) break;\n      ++_pr;\n    }\n    return _pr;\n  };\n\
    \n  static constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t\
    \ pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod - 1);\n \
    \ mint dw[level], dy[level];\n\n  void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2]\
    \ * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  NTT() {\
    \ setwy(level); }\n\n  void fft4(vector<mint> &a, int k) {\n    if ((int)a.size()\
    \ <= 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] -\
    \ a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1) {\n   \
    \   int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n        mint ajv\
    \ = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n      }\n\
    \    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k & 1));\n\
    \    mint one = mint(1);\n    mint imag = dw[1];\n    while (v) {\n      // jh\
    \ = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n        int j2 = j1\
    \ + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3)\
    \ {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n        \
    \  mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 =\
    \ (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n   \
    \       a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      //\
    \ jh >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n      for (int jh\
    \ = 4; jh < u;) {\n        ww = xx * xx, wx = ww * xx;\n        int j0 = jh *\
    \ v;\n        int je = j0 + v;\n        int j2 = je + v;\n        for (; j0 <\
    \ je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2]\
    \ * ww,\n               t3 = a[j2 + v] * wx;\n          mint t0p2 = t0 + t2, t1p3\
    \ = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n      \
    \    a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3,\
    \ a[j2 + v] = t0m2 - t1m3;\n        }\n        xx *= dw[__builtin_ctzll((jh +=\
    \ 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n    }\n  }\n\n  void ifft4(vector<mint>\
    \ &a, int k) {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n     \
    \ mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    mint one = mint(1);\n \
    \   mint imag = dy[1];\n    while (u) {\n      // jh = 0\n      {\n        int\
    \ j0 = 0;\n        int j1 = v;\n        int j2 = v + v;\n        int j3 = j2 +\
    \ v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {\n          mint t0 = a[j0],\
    \ t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          mint t0p1 = t0 + t1, t2p3 = t2\
    \ + t3;\n          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;\n          a[j0]\
    \ = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n          a[j1] = t0m1 + t2m3, a[j3] =\
    \ t0m1 - t2m3;\n        }\n      }\n      // jh >= 1\n      mint ww = one, xx\
    \ = one * dy[2], yy = one;\n      u <<= 2;\n      for (int jh = 4; jh < u;) {\n\
    \        ww = xx * xx, yy = xx * imag;\n        int j0 = jh * v;\n        int\
    \ je = j0 + v;\n        int j2 = je + v;\n        for (; j0 < je; ++j0, ++j2)\
    \ {\n          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];\n\
    \          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint t0m1 = (t0 - t1)\
    \ * xx, t2m3 = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 -\
    \ t2p3) * ww;\n          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) *\
    \ ww;\n        }\n        xx *= dy[__builtin_ctzll(jh += 4)];\n      }\n     \
    \ u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k - 1);\n\
    \      for (int j = 0; j < u; ++j) {\n        mint ajv = a[j] - a[j + u];\n  \
    \      a[j] += a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n  }\n\n  void\
    \ ntt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n    fft4(a, __builtin_ctz(a.size()));\n\
    \  }\n\n  void intt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n\
    \    ifft4(a, __builtin_ctz(a.size()));\n    mint iv = mint(a.size()).inverse();\n\
    \    for (auto &x : a) x *= iv;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(),\
    \ b.size()) <= 40) {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size();\
    \ ++i)\n        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n\
    \    setwy(k);\n    vector<mint> s(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    fft4(s, k);\n    if (a.size() == b.size() && a == b)\
    \ {\n      for (int i = 0; i < M; ++i) s[i] *= s[i];\n    } else {\n      vector<mint>\
    \ t(M);\n      for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n      fft4(t,\
    \ k);\n      for (int i = 0; i < M; ++i) s[i] *= t[i];\n    }\n    ifft4(s, k);\n\
    \    s.resize(l);\n    mint invm = mint(M).inverse();\n    for (int i = 0; i <\
    \ l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
    \ &a) {\n    int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint r\
    \ = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for (int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};\n#line 5 \"ntt/arbitrary-ntt.hpp\"\n\nnamespace\
    \ ArbitraryNTT {\nusing i64 = int64_t;\nusing u128 = __uint128_t;\nconstexpr int32_t\
    \ m0 = 167772161;\nconstexpr int32_t m1 = 469762049;\nconstexpr int32_t m2 = 754974721;\n\
    using mint0 = LazyMontgomeryModInt<m0>;\nusing mint1 = LazyMontgomeryModInt<m1>;\n\
    using mint2 = LazyMontgomeryModInt<m2>;\nconstexpr int r01 = mint1(m0).inverse().get();\n\
    constexpr int r02 = mint2(m0).inverse().get();\nconstexpr int r12 = mint2(m1).inverse().get();\n\
    constexpr int r02r12 = i64(r02) * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr\
    \ i64 w2 = i64(m0) * m1;\n\ntemplate <typename T, typename submint>\nvector<submint>\
    \ mul(const vector<T> &a, const vector<T> &b) {\n  static NTT<submint> ntt;\n\
    \  vector<submint> s(a.size()), t(b.size());\n  for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = i64(a[i] % submint::get_mod());\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = i64(b[i] % submint::get_mod());\n  return ntt.multiply(s, t);\n\
    }\n\ntemplate <typename T>\nvector<int> multiply(const vector<T> &s, const vector<T>\
    \ &t, int mod) {\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s,\
    \ t);\n  auto d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<int> ret(n);\n\
    \  const int W1 = w1 % mod;\n  const int W2 = w2 % mod;\n  for (int i = 0; i <\
    \ n; i++) {\n    int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n  \
    \  int b = i64(n1 + m1 - a) * r01 % m1;\n    int c = (i64(n2 + m2 - a) * r02r12\
    \ + i64(m2 - b) * r12) % m2;\n    ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2)\
    \ % mod;\n  }\n  return ret;\n}\n\ntemplate <typename mint>\nvector<mint> multiply(const\
    \ vector<mint> &a, const vector<mint> &b) {\n  if (a.size() == 0 && b.size() ==\
    \ 0) return {};\n  if (min<int>(a.size(), b.size()) < 128) {\n    vector<mint>\
    \ ret(a.size() + b.size() - 1);\n    for (int i = 0; i < (int)a.size(); ++i)\n\
    \      for (int j = 0; j < (int)b.size(); ++j) ret[i + j] += a[i] * b[j];\n  \
    \  return ret;\n  }\n  vector<int> s(a.size()), t(b.size());\n  for (int i = 0;\
    \ i < (int)a.size(); ++i) s[i] = a[i].get();\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i].get();\n  vector<int> u = multiply<int>(s, t, mint::get_mod());\n\
    \  vector<mint> ret(u.size());\n  for (int i = 0; i < (int)u.size(); ++i) ret[i]\
    \ = mint(u[i]);\n  return ret;\n}\n\ntemplate <typename T>\nvector<u128> multiply_u128(const\
    \ vector<T> &s, const vector<T> &t) {\n  if (s.size() == 0 && t.size() == 0) return\
    \ {};\n  if (min<int>(s.size(), t.size()) < 128) {\n    vector<u128> ret(s.size()\
    \ + t.size() - 1);\n    for (int i = 0; i < (int)s.size(); ++i)\n      for (int\
    \ j = 0; j < (int)t.size(); ++j) ret[i + j] += i64(s[i]) * t[j];\n    return ret;\n\
    \  }\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s, t);\n  auto\
    \ d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<u128> ret(n);\n  for\
    \ (int i = 0; i < n; i++) {\n    i64 n1 = d1[i].get(), n2 = d2[i].get();\n   \
    \ i64 a = d0[i].get();\n    i64 b = (n1 + m1 - a) * r01 % m1;\n    i64 c = ((n2\
    \ + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + u128(c)\
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 4 \"ntt/chirp-z.hpp\"\
    \n\n// f(A W^0), f(A W^1), ..., f(A W^{N-1}) \u3092\u8FD4\u3059\ntemplate <typename\
    \ fps>\nfps ChirpZ(fps f, typename fps::value_type W, int N = -1,\n          \
    \ typename fps::value_type A = 1) {\n  using mint = typename fps::value_type;\n\
    \  if (N == -1) N = f.size();\n  if (f.empty() or N == 0) return fps(N, mint{});\n\
    \  int M = f.size();\n  if (A != 1) {\n    mint x = 1;\n    for (int i = 0; i\
    \ < M; i++) f[i] *= x, x *= A;\n  }\n  if (W == 0) {\n    fps F(N, f[0]);\n  \
    \  for (int i = 1; i < M; i++) F[0] += f[i];\n    return F;\n  }\n  fps wc(N +\
    \ M), iwc(max(N, M));\n  mint ws = 1, iW = W.inverse(), iws = 1;\n  wc[0] = 1,\
    \ iwc[0] = 1;\n  for (int i = 1; i < N + M; i++) wc[i] = ws * wc[i - 1], ws *=\
    \ W;\n  for (int i = 1; i < max(N, M); i++) iwc[i] = iws * iwc[i - 1], iws *=\
    \ iW;\n  for (int i = 0; i < M; i++) f[i] *= iwc[i];\n  reverse(begin(f), end(f));\n\
    \  fps g = f * wc;\n  fps F{begin(g) + M - 1, begin(g) + M + N - 1};\n  for (int\
    \ i = 0; i < N; i++) F[i] *= iwc[i];\n  return F;\n}\n\n/**\n * @brief Chirp Z-transform(Bluestein's\
    \ algorithm)\n */\n#line 2 \"ntt/multidimensional-ntt.hpp\"\n\n// f(vector<mint>&\
    \ a, bool rev) : 1 \u6B21\u5143 DFT (rev \u306F\u9006\u5909\u63DB\u304B\u3069\u3046\
    \u304B)\ntemplate <typename T>\nstruct MultidimensionalFourierTransform {\n  vector<int>\
    \ base;\n  function<void(vector<T>&, bool)> dft1d;\n\n  MultidimensionalFourierTransform(const\
    \ vector<int>& bs,\n                                   const function<void(vector<T>&,\
    \ bool)>& f)\n      : base(bs), dft1d(f) {}\n\n  bool ascend(vector<int>& v) {\n\
    \    int i = 0;\n    v[i] += 1;\n    while (v[i] == base[i]) {\n      if (i ==\
    \ (int)v.size() - 1) return false;\n      v[i] = 0;\n      v[++i] += 1;\n    }\n\
    \    return true;\n  }\n\n  int operator()(vector<int>& a) {\n    int res = a[0],\
    \ coeff = 1;\n    for (int i = 1; i < (int)a.size(); i++)\n      coeff *= base[i\
    \ - 1], res += coeff * a[i];\n    return res;\n  }\n\n  void inner(vector<T>&\
    \ a, int dim, bool rev = false) {\n    int i = 0, shift = 1, n = base[dim];\n\
    \    vector<T> f(n);\n    vector<int> id(base.size());\n    for (int j = 0; j\
    \ < dim; j++) shift *= base[j];\n    do {\n      if (id[dim] != 0) continue;\n\
    \      for (int j = 0, t = i; j < n; j++, t += shift) f[j] = a[t];\n      dft1d(f,\
    \ rev);\n      for (int j = 0, t = i; j < n; j++, t += shift) a[t] = f[j];\n \
    \     id[dim] = 0;\n    } while (++i && ascend(id));\n  }\n  void fft(vector<T>&\
    \ a, bool rev = false) {\n    if (!rev)\n      for (int i = 0; i < (int)base.size();\
    \ i++) inner(a, i);\n    else\n      for (int i = (int)base.size(); i--;) inner(a,\
    \ i, true);\n  }\n};\n\n/**\n * @brief \u591A\u6B21\u5143FFT\n */\n#line 15 \"\
    ntt/multivariate-circular-convolution.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ multivariate_circular_convolution(\n    const FormalPowerSeries<mint>& f, const\
    \ FormalPowerSeries<mint>& g,\n    const vector<int>& base) {\n  int prod = 1;\n\
    \  for (auto& b : base) prod *= b;\n  assert((int)f.size() == prod && (int)g.size()\
    \ == prod);\n\n  vector<int> primes;\n  for (int p = 900000000 / prod * prod +\
    \ 1; (int)primes.size() < 3; p += prod) {\n    if (is_prime(p)) primes.push_back(p);\n\
    \  }\n\n  vector<vector<int>> buf;\n  using submint = ArbitraryModIntBase<20230528>;\n\
    \  for (int p : primes) {\n    submint::set_mod(p);\n    int proot = PrimitiveRoot(p);\n\
    \    unordered_map<int, pair<submint, submint>> len_to_W;\n    for (auto& b :\
    \ base) {\n      submint w = submint{proot}.pow((p - 1) / b);\n      submint iw\
    \ = w.inverse();\n      len_to_W[b] = {w, iw};\n    }\n    FormalPowerSeries<submint>\
    \ s(prod), t(prod);\n    for (int i = 0; i < prod; i++) s[i] = f[i].get(), t[i]\
    \ = g[i].get();\n    auto dft = [&](vector<submint>& v, bool rev) -> void {\n\
    \      auto& val = len_to_W[v.size()];\n      submint w = rev ? val.second : val.first;\n\
    \      auto res = ChirpZ<FormalPowerSeries<submint>>({begin(v), end(v)}, w);\n\
    \      v = vector<submint>{begin(res), end(res)};\n    };\n    MultidimensionalFourierTransform<submint>\
    \ mdft(base, dft);\n    mdft.fft(s), mdft.fft(t);\n    for (int i = 0; i < prod;\
    \ i++) s[i] *= t[i];\n    mdft.fft(s, true);\n    submint iprod = submint{prod}.inverse();\n\
    \    vector<int> res;\n    for (auto& x : s) res.push_back((x * iprod).get());\n\
    \    buf.push_back(res);\n  }\n\n  FormalPowerSeries<mint> h;\n  auto m = mint::get_mod();\n\
    \  vector<__int128_t> rem(3), mod(3);\n  for (int j = 0; j < 3; j++) mod[j] =\
    \ primes[j];\n  for (int i = 0; i < prod; i++) {\n    for (int j = 0; j < 3; j++)\
    \ rem[j] = buf[j][i];\n    h.push_back(internal::crt(rem, mod).first % m);\n \
    \ }\n  return h;\n}\n\n/**\n * @brief \u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\
    \u8FBC\u307F\n */\n"
  code: "#pragma once\n//\n#include <cassert>\n#include <unordered_map>\n#include\
    \ <vector>\nusing namespace std;\n\n#include \"../fps/formal-power-series.hpp\"\
    \n#include \"../internal/internal-math.hpp\"\n#include \"../math/primitive-root.hpp\"\
    \n#include \"../modint/arbitrary-modint.hpp\"\n#include \"../prime/fast-factorize.hpp\"\
    \n#include \"chirp-z.hpp\"\n#include \"multidimensional-ntt.hpp\"\n\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> multivariate_circular_convolution(\n\
    \    const FormalPowerSeries<mint>& f, const FormalPowerSeries<mint>& g,\n   \
    \ const vector<int>& base) {\n  int prod = 1;\n  for (auto& b : base) prod *=\
    \ b;\n  assert((int)f.size() == prod && (int)g.size() == prod);\n\n  vector<int>\
    \ primes;\n  for (int p = 900000000 / prod * prod + 1; (int)primes.size() < 3;\
    \ p += prod) {\n    if (is_prime(p)) primes.push_back(p);\n  }\n\n  vector<vector<int>>\
    \ buf;\n  using submint = ArbitraryModIntBase<20230528>;\n  for (int p : primes)\
    \ {\n    submint::set_mod(p);\n    int proot = PrimitiveRoot(p);\n    unordered_map<int,\
    \ pair<submint, submint>> len_to_W;\n    for (auto& b : base) {\n      submint\
    \ w = submint{proot}.pow((p - 1) / b);\n      submint iw = w.inverse();\n    \
    \  len_to_W[b] = {w, iw};\n    }\n    FormalPowerSeries<submint> s(prod), t(prod);\n\
    \    for (int i = 0; i < prod; i++) s[i] = f[i].get(), t[i] = g[i].get();\n  \
    \  auto dft = [&](vector<submint>& v, bool rev) -> void {\n      auto& val = len_to_W[v.size()];\n\
    \      submint w = rev ? val.second : val.first;\n      auto res = ChirpZ<FormalPowerSeries<submint>>({begin(v),\
    \ end(v)}, w);\n      v = vector<submint>{begin(res), end(res)};\n    };\n   \
    \ MultidimensionalFourierTransform<submint> mdft(base, dft);\n    mdft.fft(s),\
    \ mdft.fft(t);\n    for (int i = 0; i < prod; i++) s[i] *= t[i];\n    mdft.fft(s,\
    \ true);\n    submint iprod = submint{prod}.inverse();\n    vector<int> res;\n\
    \    for (auto& x : s) res.push_back((x * iprod).get());\n    buf.push_back(res);\n\
    \  }\n\n  FormalPowerSeries<mint> h;\n  auto m = mint::get_mod();\n  vector<__int128_t>\
    \ rem(3), mod(3);\n  for (int j = 0; j < 3; j++) mod[j] = primes[j];\n  for (int\
    \ i = 0; i < prod; i++) {\n    for (int j = 0; j < 3; j++) rem[j] = buf[j][i];\n\
    \    h.push_back(internal::crt(rem, mod).first % m);\n  }\n  return h;\n}\n\n\
    /**\n * @brief \u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - internal/internal-math.hpp
  - internal/internal-type-traits.hpp
  - math/primitive-root.hpp
  - modint/arbitrary-modint.hpp
  - modint/barrett-reduction.hpp
  - prime/fast-factorize.hpp
  - misc/rng.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  - ntt/chirp-z.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  - ntt/multidimensional-ntt.hpp
  isVerificationFile: false
  path: ntt/multivariate-circular-convolution.hpp
  requiredBy: []
  timestamp: '2023-05-28 20:44:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
documentation_of: ntt/multivariate-circular-convolution.hpp
layout: document
redirect_from:
- /library/ntt/multivariate-circular-convolution.hpp
- /library/ntt/multivariate-circular-convolution.hpp.html
title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
---
