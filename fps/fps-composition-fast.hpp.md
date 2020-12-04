---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':x:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':x:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':x:'
    path: modulo/strassen.hpp
    title: modulo/strassen.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
    links: []
  bundledCode: "#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\n\
    struct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using\
    \ FPS = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if (r.size()\
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
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
    \ {\n  using mint = LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32\
    \ = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n \
    \   u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n  \
    \  return ret;\n  }\n\n  static constexpr u32 r = get_r();\n  static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"invalid, r * mod\
    \ != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod\
    \ & 1) == 1, \"invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt()\
    \ : a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 2 \"modulo/strassen.hpp\"\n#include <immintrin.h>\n\
    //\n\n\n\n#line 2 \"modint/simd-montgomery.hpp\"\n\n\n#line 5 \"modint/simd-montgomery.hpp\"\
    \n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline)) __m128i\n\
    my128_mullo_epu32(const __m128i &a, const __m128i &b) {\n  return _mm_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmy128_mulhi_epu32(const __m128i &a, const __m128i &b) {\n  __m128i\
    \ a13 = _mm_shuffle_epi32(a, 0xF5);\n  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);\n\
    \  __m128i prod02 = _mm_mul_epu32(a, b);\n  __m128i prod13 = _mm_mul_epu32(a13,\
    \ b13);\n  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),\n\
    \                                    _mm_unpackhi_epi32(prod02, prod13));\n  return\
    \ prod;\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &r,\n                   const __m128i &m1) {\n  return _mm_sub_epi32(\n    \
    \  _mm_add_epi32(my128_mulhi_epu32(a, b), m1),\n      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_add_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a,\
    \ b), m2);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2),\
    \ ret);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(a,\
    \ b);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);\n\
    }\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mullo_epu32(const __m256i &a, const __m256i &b) {\n  return _mm256_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mulhi_epu32(const __m256i &a, const __m256i &b) {\n  __m256i a13 = _mm256_shuffle_epi32(a,\
    \ 0xF5);\n  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);\n  __m256i prod02 = _mm256_mul_epu32(a,\
    \ b);\n  __m256i prod13 = _mm256_mul_epu32(a13, b13);\n  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02,\
    \ prod13),\n                                       _mm256_unpackhi_epi32(prod02,\
    \ prod13));\n  return prod;\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &r,\n                   const __m256i &m1) {\n  return _mm256_sub_epi32(\n \
    \     _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),\n      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_add_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &m2,\n                   const __m256i &m0) {\n  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a,\
    \ b), m2);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n\n__attribute__((target(\"avx2\"\
    ))) __attribute__((always_inline)) __m256i\nmontgomery_sub_256(const __m256i &a,\
    \ const __m256i &b, const __m256i &m2,\n                   const __m256i &m0)\
    \ {\n  __m256i ret = _mm256_sub_epi32(a, b);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n#line 10 \"modulo/strassen.hpp\"\
    \n\nnamespace FastMatProd {\n\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using vm = vector<mint>;\nusing vvm = vector<vm>;\nusing fps = FormalPowerSeries<mint>;\n\
    using u32 = uint32_t;\nusing i32 = int32_t;\nusing u64 = uint64_t;\nusing m256\
    \ = __m256i;\n\nconstexpr u32 SHIFT_ = 6;\nu32 a[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));\n\
    u32 b[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));\nu32 c[1 << (SHIFT_ * 2)]\
    \ __attribute__((aligned(64)));\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) void\ninner_simd_mul(u32 n, u32 m, u32 p) {\n  memset(c,\
    \ 0, sizeof(c));\n  const m256 R = _mm256_set1_epi32(mint::r);\n  const m256 M0\
    \ = _mm256_set1_epi32(0);\n  const m256 M1 = _mm256_set1_epi32(mint::get_mod());\n\
    \  const m256 M2 = _mm256_set1_epi32(mint::get_mod() << 1);\n\n  u32 k0 = 0;\n\
    \  for (; i32(k0) < i32(p) - 3; k0 += 4) {\n    const u32 k1 = k0 + 1;\n    const\
    \ u32 k2 = k0 + 2;\n    const u32 k3 = k0 + 3;\n    u32 j0 = 0;\n    for (; i32(j0)\
    \ < i32(m) - 7; j0 += 8) {\n      const m256 B00 = _mm256_load_si256((m256*)(b\
    \ + (k0 << SHIFT_) + j0));\n      const m256 B10 = _mm256_load_si256((m256*)(b\
    \ + (k1 << SHIFT_) + j0));\n      const m256 B20 = _mm256_load_si256((m256*)(b\
    \ + (k2 << SHIFT_) + j0));\n      const m256 B30 = _mm256_load_si256((m256*)(b\
    \ + (k3 << SHIFT_) + j0));\n      for (u32 i0 = 0; i0 < n; ++i0) {\n        const\
    \ m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);\n        const m256 A01\
    \ = _mm256_set1_epi32(a[(i0 << SHIFT_) | k1]);\n        const m256 A02 = _mm256_set1_epi32(a[(i0\
    \ << SHIFT_) | k2]);\n        const m256 A03 = _mm256_set1_epi32(a[(i0 << SHIFT_)\
    \ | k3]);\n        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);\n\
    \        const m256 A01B10 = montgomery_mul_256(A01, B10, R, M1);\n        const\
    \ m256 A02B20 = montgomery_mul_256(A02, B20, R, M1);\n        const m256 A03B30\
    \ = montgomery_mul_256(A03, B30, R, M1);\n        const u32* pc00 = c + (i0 <<\
    \ SHIFT_) + j0;\n        const m256 C00 = _mm256_load_si256((m256*)pc00);\n  \
    \      const m256 C00_01 = montgomery_add_256(A00B00, A01B10, M2, M0);\n     \
    \   const m256 C00_23 = montgomery_add_256(A02B20, A03B30, M2, M0);\n        const\
    \ m256 C00_al = montgomery_add_256(C00_01, C00_23, M2, M0);\n        const m256\
    \ C00_ad = montgomery_add_256(C00, C00_al, M2, M0);\n        _mm256_store_si256((m256*)pc00,\
    \ C00_ad);\n      }\n    }\n    for (; j0 < m; j0++) {\n      for (u32 i0 = 0;\
    \ i0 < n; ++i0) {\n        u32 ab0 =\n            mint::reduce(u64(a[(i0 << SHIFT_)\
    \ | k0]) * b[(k0 << SHIFT_) | j0]);\n        u32 ab1 =\n            mint::reduce(u64(a[(i0\
    \ << SHIFT_) | k1]) * b[(k1 << SHIFT_) | j0]);\n        u32 ab2 =\n          \
    \  mint::reduce(u64(a[(i0 << SHIFT_) | k2]) * b[(k2 << SHIFT_) | j0]);\n     \
    \   u32 ab3 =\n            mint::reduce(u64(a[(i0 << SHIFT_) | k3]) * b[(k3 <<\
    \ SHIFT_) | j0]);\n        if ((ab0 += ab1) >= 2 * mint::get_mod()) ab0 -= 2 *\
    \ mint::get_mod();\n        if ((ab2 += ab3) >= 2 * mint::get_mod()) ab2 -= 2\
    \ * mint::get_mod();\n        if ((ab0 += ab2) >= 2 * mint::get_mod()) ab0 -=\
    \ 2 * mint::get_mod();\n        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())\n\
    \          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();\n      }\n    }\n  }\n\
    \n  for (; k0 < p; k0++) {\n    u32 j0 = 0;\n    for (; i32(j0) < i32(m) - 7;\
    \ j0 += 8) {\n      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_)\
    \ + j0));\n      for (u32 i0 = 0; i0 < n; ++i0) {\n        const m256 A00 = _mm256_set1_epi32(a[(i0\
    \ << SHIFT_) | k0]);\n        const m256 A00B00 = montgomery_mul_256(A00, B00,\
    \ R, M1);\n        const u32* pc00 = c + (i0 << SHIFT_) + j0;\n        const m256\
    \ C00 = _mm256_load_si256((m256*)pc00);\n        const m256 C00_ad = montgomery_add_256(C00,\
    \ A00B00, M2, M0);\n        _mm256_store_si256((m256*)pc00, C00_ad);\n      }\n\
    \    }\n    for (; j0 < m; j0++) {\n      for (u32 i0 = 0; i0 < n; ++i0) {\n \
    \       u32 ab0 =\n            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0\
    \ << SHIFT_) | j0]);\n        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())\n\
    \          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();\n      }\n    }\n  }\n\
    }\n\n// for debug\n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) vvm naive_mul(\n    const vvm& a, const vvm& b) {\n  int n = a.size(), m =\
    \ b[0].size(), p = b.size();\n  assert(p == (int)a[0].size());\n  vvm c(n, fps(m,\
    \ 0));\n  for (int i = 0; i < n; i++)\n    for (int k = 0; k < p; k++)\n     \
    \ for (int j = 0; j < m; j++) c[i][j] += a[i][k] * b[k][j];\n  return c;\n}\n\n\
    struct Mat {\n  int H, W, HM, WM;\n  mint* a;\n\n  Mat(int H_, int W_, mint* a_)\
    \ : H(H_), W(W_), a(a_) {\n    HM = (H >> 1) + (H & 1);\n    WM = (W >> 1) + (W\
    \ & 1);\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) void\n  range_add(mint* b, int as, int ae, int bs) const {\n    const m256\
    \ M0 = _mm256_set1_epi32(0);\n    const m256 M2 = _mm256_set1_epi32(mint::get_mod()\
    \ * 2);\n    for (; as < ae - 31; as += 32, bs += 32) {\n      int a0 = as;\n\
    \      int a1 = as + 8;\n      int a2 = as + 16;\n      int a3 = as + 24;\n  \
    \    int b0 = bs;\n      int b1 = bs + 8;\n      int b2 = bs + 16;\n      int\
    \ b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));\n\
    \      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const m256\
    \ A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_add_256(B0, A0, M2, M0);\n      const m256 BA1 = montgomery_add_256(B1,\
    \ A1, M2, M0);\n      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);\n \
    \     const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);\n      _mm256_storeu_si256((m256*)(b\
    \ + b0), BA0);\n      _mm256_storeu_si256((m256*)(b + b1), BA1);\n      _mm256_storeu_si256((m256*)(b\
    \ + b2), BA2);\n      _mm256_storeu_si256((m256*)(b + b3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) b[bs] += a[as];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) void\n  range_sub(mint* b, int as, int\
    \ ae, int bs) const {\n    const m256 M0 = _mm256_set1_epi32(0);\n    const m256\
    \ M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    for (; as < ae - 31; as +=\
    \ 32, bs += 32) {\n      int a0 = as;\n      int a1 = as + 8;\n      int a2 =\
    \ as + 16;\n      int a3 = as + 24;\n      int b0 = bs;\n      int b1 = bs + 8;\n\
    \      int b2 = bs + 16;\n      int b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a\
    \ + a0));\n      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const\
    \ m256 A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_sub_256(B0, A0, M2, M0);\n      const m256 BA1 = montgomery_sub_256(B1,\
    \ A1, M2, M0);\n      const m256 BA2 = montgomery_sub_256(B2, A2, M2, M0);\n \
    \     const m256 BA3 = montgomery_sub_256(B3, A3, M2, M0);\n      _mm256_storeu_si256((m256*)(b\
    \ + b0), BA0);\n      _mm256_storeu_si256((m256*)(b + b1), BA1);\n      _mm256_storeu_si256((m256*)(b\
    \ + b2), BA2);\n      _mm256_storeu_si256((m256*)(b + b3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) b[bs] -= a[as];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) void\n  op_range_add(mint* b, int as,\
    \ int ae, int bs) const {\n    const m256 M0 = _mm256_set1_epi32(0);\n    const\
    \ m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    for (; as < ae - 31;\
    \ as += 32, bs += 32) {\n      int a0 = as;\n      int a1 = as + 8;\n      int\
    \ a2 = as + 16;\n      int a3 = as + 24;\n      int b0 = bs;\n      int b1 = bs\
    \ + 8;\n      int b2 = bs + 16;\n      int b3 = bs + 24;\n      const m256 A0\
    \ = _mm256_loadu_si256((m256*)(a + a0));\n      const m256 A1 = _mm256_loadu_si256((m256*)(a\
    \ + a1));\n      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const\
    \ m256 A3 = _mm256_loadu_si256((m256*)(a + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b\
    \ + b0));\n      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const\
    \ m256 B2 = _mm256_loadu_si256((m256*)(b + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b\
    \ + b3));\n      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);\n      const\
    \ m256 BA1 = montgomery_add_256(B1, A1, M2, M0);\n      const m256 BA2 = montgomery_add_256(B2,\
    \ A2, M2, M0);\n      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);\n \
    \     _mm256_storeu_si256((m256*)(a + a0), BA0);\n      _mm256_storeu_si256((m256*)(a\
    \ + a1), BA1);\n      _mm256_storeu_si256((m256*)(a + a2), BA2);\n      _mm256_storeu_si256((m256*)(a\
    \ + a3), BA3);\n    }\n    for (; as < ae; ++as, ++bs) a[as] += b[bs];\n  }\n\n\
    \  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\n\
    \  op_range_sub(mint* b, int as, int ae, int bs) const {\n    const m256 M0 =\
    \ _mm256_set1_epi32(0);\n    const m256 M2 = _mm256_set1_epi32(mint::get_mod()\
    \ * 2);\n    for (; as < ae - 31; as += 32, bs += 32) {\n      int a0 = as;\n\
    \      int a1 = as + 8;\n      int a2 = as + 16;\n      int a3 = as + 24;\n  \
    \    int b0 = bs;\n      int b1 = bs + 8;\n      int b2 = bs + 16;\n      int\
    \ b3 = bs + 24;\n      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));\n\
    \      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));\n      const m256\
    \ A2 = _mm256_loadu_si256((m256*)(a + a2));\n      const m256 A3 = _mm256_loadu_si256((m256*)(a\
    \ + a3));\n      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));\n      const\
    \ m256 B1 = _mm256_loadu_si256((m256*)(b + b1));\n      const m256 B2 = _mm256_loadu_si256((m256*)(b\
    \ + b2));\n      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));\n      const\
    \ m256 BA0 = montgomery_sub_256(A0, B0, M2, M0);\n      const m256 BA1 = montgomery_sub_256(A1,\
    \ B1, M2, M0);\n      const m256 BA2 = montgomery_sub_256(A2, B2, M2, M0);\n \
    \     const m256 BA3 = montgomery_sub_256(A3, B3, M2, M0);\n      _mm256_storeu_si256((m256*)(a\
    \ + a0), BA0);\n      _mm256_storeu_si256((m256*)(a + a1), BA1);\n      _mm256_storeu_si256((m256*)(a\
    \ + a2), BA2);\n      _mm256_storeu_si256((m256*)(a + a3), BA3);\n    }\n    for\
    \ (; as < ae; ++as, ++bs) a[as] -= b[bs];\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) inline void\n  A11(mint* b) const {\n\
    \    for (int i = 0; i < HM; i++)\n      memcpy(b + i * WM, a + i * W, WM * sizeof(int));\n\
    \  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\")))\
    \ inline void\n  A12(mint* b) const {\n    for (int i = 0; i < HM; i++)\n    \
    \  memcpy(b + i * WM, a + i * W + WM, (W - WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  A21(mint* b) const\
    \ {\n    for (int i = 0; i < H - HM; i++)\n      memcpy(b + i * WM, a + (i + HM)\
    \ * W, WM * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) inline void\n  A22(mint* b) const {\n    for (int i\
    \ = 0; i < H - HM; i++)\n      memcpy(b + i * WM, a + (i + HM) * W + WM, (W -\
    \ WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) inline void\n  subA11(mint* b) const {\n    for (int i =\
    \ 0; i < HM; i++) {\n      int as = i * W;\n      int ae = i * W + WM;\n     \
    \ int bs = i * WM;\n      range_sub(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  addA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++) {\n      int as = i * W + WM;\n      int\
    \ ae = i * W + W;\n      int bs = i * WM;\n      range_add(b, as, ae, bs);\n \
    \   }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  addA22(mint* b) const {\n    for (int i = 0; i < H - HM; i++)\
    \ {\n      int as = (i + HM) * W + WM;\n      int ae = as + W - WM;\n      int\
    \ bs = i * WM;\n      range_add(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  subA22(mint* b) const\
    \ {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W + WM;\n\
    \      int ae = as + W - WM;\n      int bs = i * WM;\n      range_sub(b, as, ae,\
    \ bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  updA11(mint* b) const {\n    for (int i = 0; i < HM; i++)\n\
    \      memcpy(a + i * W, b + i * WM, WM * sizeof(int));\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  updA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++)\n      memcpy(a + i * W + WM, b + i * WM,\
    \ (W - WM) * sizeof(int));\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) inline void\n  updA21(mint* b) const {\n    for (int\
    \ i = 0; i < H - HM; i++)\n      memcpy(a + (i + HM) * W, b + i * WM, WM * sizeof(int));\n\
    \  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\")))\
    \ inline void\n  updA22(mint* b) const {\n    for (int i = 0; i < H - HM; i++)\n\
    \      memcpy(a + (i + HM) * W + WM, b + i * WM, (W - WM) * sizeof(int));\n  }\n\
    \n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline\
    \ void\n  opaddA11(mint* b) const {\n    for (int i = 0; i < HM; i++) {\n    \
    \  int as = i * W;\n      int ae = i * W + WM;\n      int bs = i * WM;\n     \
    \ op_range_add(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"\
    ), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opaddA12(mint* b) const\
    \ {\n    for (int i = 0; i < HM; i++) {\n      int as = i * W + WM;\n      int\
    \ ae = i * W + W;\n      int bs = i * WM;\n      op_range_add(b, as, ae, bs);\n\
    \    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) inline void\n  opaddA21(mint* b) const {\n    for (int i = 0; i < H - HM;\
    \ i++) {\n      int as = (i + HM) * W;\n      int ae = (i + HM) * W + WM;\n  \
    \    int bs = i * WM;\n      op_range_add(b, as, ae, bs);\n    }\n    //  for\
    \ (int j = 0; j < WM; j++) a[(i + HM) * W + j] += b[i * WM + j];\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opaddA22(mint* b)\
    \ const {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W\
    \ + WM;\n      int ae = (i + HM) * W + W;\n      int bs = i * WM;\n      op_range_add(b,\
    \ as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) inline void\n  opsubA11(mint* b) const {\n    for (int i\
    \ = 0; i < HM; i++) {\n      int as = i * W;\n      int ae = i * W + WM;\n   \
    \   int bs = i * WM;\n      op_range_sub(b, as, ae, bs);\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) inline void\n  opsubA22(mint* b)\
    \ const {\n    for (int i = 0; i < H - HM; i++) {\n      int as = (i + HM) * W\
    \ + WM;\n      int ae = (i + HM) * W + W;\n      int bs = i * WM;\n      op_range_sub(b,\
    \ as, ae, bs);\n    }\n  }\n\n  void dump() const {\n    cerr << \"[ \" << endl\
    \ << \" \";\n    for (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++)\n\
    \        cerr << a[i * W + j] << (j == W - 1 ? \",\\n \" : \" \");\n    cerr <<\
    \ \"] \" << endl;\n  }\n};\n\n#ifndef BUFFER_SIZE\n#define BUFFER_SIZE (1 << 21)\n\
    #endif\nmint A[BUFFER_SIZE] __attribute__((aligned(64)));\nmint B[BUFFER_SIZE]\
    \ __attribute__((aligned(64)));\nmint C[BUFFER_SIZE] __attribute__((aligned(64)));\n\
    \n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\n\
    inner_fast_mul(const Mat* s, const Mat* t, const Mat* u) {\n  int n = s->H, m\
    \ = t->W, p = s->W;\n  for (int i = 0; i < n; i++)\n    memcpy((mint*)(a + (i\
    \ << SHIFT_)), s->a + i * p, p * sizeof(int));\n  for (int i = 0; i < p; i++)\n\
    \    memcpy((mint*)(b + (i << SHIFT_)), t->a + i * m, m * sizeof(int));\n  inner_simd_mul(n,\
    \ m, p);\n  for (int i = 0; i < n; i++)\n    memcpy(u->a + i * m, (mint*)(c +\
    \ (i << SHIFT_)), m * sizeof(int));\n}\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) void\ninner_block_dec_mul(const Mat* s, const Mat* t,\
    \ const Mat* u) {\n  int n = s->H, m = t->W, p = s->W;\n  memset((int*)(u->a),\
    \ 0, n * m * sizeof(int));\n  for (int is = 0; is < n; is += (1 << SHIFT_))\n\
    \    for (int ks = 0; ks < p; ks += (1 << SHIFT_))\n      for (int js = 0; js\
    \ < m; js += (1 << SHIFT_)) {\n        int ie = min(is + (1 << SHIFT_), n);\n\
    \        int je = min(js + (1 << SHIFT_), m);\n        int ke = min(ks + (1 <<\
    \ SHIFT_), p);\n        for (int l = is; l < ie; l++)\n          memcpy((mint*)(a\
    \ + ((l - is) << SHIFT_)), s->a + l * p + ks,\n                 (ke - ks) * sizeof(int));\n\
    \        for (int l = ks; l < ke; l++)\n          memcpy((mint*)(b + ((l - ks)\
    \ << SHIFT_)), t->a + l * m + js,\n                 (je - js) * sizeof(int));\n\
    \        inner_simd_mul(ie - is, je - js, ke - ks);\n        for (int l = is;\
    \ l < ie; l++) {\n          for (int ll = js; ll < je; ll++) {\n            u->a[l\
    \ * m + ll] +=\n                *reinterpret_cast<mint*>(c + ((l - is) << SHIFT_)\
    \ + (ll - js));\n          }\n        }\n      }\n}\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) void\ninner_strassen(const Mat*\
    \ a, const Mat* b, const Mat* c) {\n  int n = a->H, m = b->W, p = a->W;\n  if\
    \ (max({n, m, p}) <= (1 << SHIFT_)) {\n    inner_fast_mul(a, b, c);\n    return;\n\
    \  }\n  if (min({n, m, p}) <= (1 << (SHIFT_ - 2))) {\n    inner_block_dec_mul(a,\
    \ b, c);\n    return;\n  }\n  int nm = n / 2 + (n & 1);\n  int mm = m / 2 + (m\
    \ & 1);\n  int pm = p / 2 + (p & 1);\n\n  Mat s(nm, pm, a->a + n * p);\n  Mat\
    \ t(pm, mm, b->a + p * m);\n  Mat u(nm, mm, c->a + n * m);\n\n  // P1 = (A11 +\
    \ A22) * (B11 + B22)\n  a->A11(s.a);\n  a->addA22(s.a);\n  b->A11(t.a);\n  b->addA22(t.a);\n\
    \  inner_strassen(&s, &t, &u);\n  c->updA11(u.a);\n  c->updA22(u.a);\n\n  // P2\
    \ = (A21 + A22) * B11\n  memset((int*)s.a, 0, nm * pm * sizeof(int));\n  a->A21(s.a);\n\
    \  a->addA22(s.a);\n  b->A11(t.a);\n  inner_strassen(&s, &t, &u);\n  c->updA21(u.a);\n\
    \  c->opsubA22(u.a);\n\n  // P3 = A11 (B12 - B22)\n  a->A11(s.a);\n  memset((int*)t.a,\
    \ 0, pm * mm * sizeof(int));\n  b->A12(t.a);\n  b->subA22(t.a);\n  inner_strassen(&s,\
    \ &t, &u);\n  c->updA12(u.a);\n  c->opaddA22(u.a);\n\n  // P4 = A22 (B21 - B11)\n\
    \  memset((int*)s.a, 0, nm * pm * sizeof(int));\n  a->A22(s.a);\n  memset((int*)t.a\
    \ + (pm - 1) * mm, 0, mm * sizeof(int));\n  b->A21(t.a);\n  b->subA11(t.a);\n\
    \  inner_strassen(&s, &t, &u);\n  c->opaddA11(u.a);\n  c->opaddA21(u.a);\n\n \
    \ // P5 = (A11 + A12) B22\n  memset((int*)t.a, 0, pm * mm * sizeof(int));\n  a->A11(s.a);\n\
    \  a->addA12(s.a);\n  b->A22(t.a);\n  inner_strassen(&s, &t, &u);\n  c->opsubA11(u.a);\n\
    \  c->opaddA12(u.a);\n\n  // P6 = (A21 - A11) (B11 + B12)\n  memset((int*)s.a\
    \ + (nm - 1) * pm, 0, pm * sizeof(int));\n  a->A21(s.a);\n  a->subA11(s.a);\n\
    \  b->A11(t.a);\n  b->addA12(t.a);\n  inner_strassen(&s, &t, &u);\n  c->opaddA22(u.a);\n\
    \n  // P7 = (A12 - A22) (B21 + B22)\n  memset((int*)s.a, 0, nm * pm * sizeof(int));\n\
    \  a->A12(s.a);\n  a->subA22(s.a);\n  memset((int*)t.a + (pm - 1) * mm, 0, mm\
    \ * sizeof(int));\n  b->A21(t.a);\n  b->addA22(t.a);\n  inner_strassen(&s, &t,\
    \ &u);\n  c->opaddA11(u.a);\n}\n\nusing vfps = vector<fps>;\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) vvm block_dec(\n    const vvm& s,\
    \ const vvm& t) {\n  int n = s.size(), p = s[0].size(), m = t[0].size();\n  assert(int(n\
    \ * p * 1.4) <= BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n\
    \ * m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n\
    \  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C, 0, int(m * n * 1.4)\
    \ * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(),\
    \ p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(),\
    \ m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_block_dec_mul(&S,\
    \ &T, &U);\n  vvm u(n, vm(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(),\
    \ C + i * m, m * sizeof(int));\n  return std::move(u);\n}\n\n__attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) vfps block_dec(\n    const vfps&\
    \ s, const vfps& t) {\n  int n = s.size(), p = s[0].size(), m = t[0].size();\n\
    \  assert(int(n * p * 1.4) <= BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n\
    \  assert(int(n * m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) *\
    \ sizeof(int));\n  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C,\
    \ 0, int(m * n * 1.4) * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A\
    \ + i * p, s[i].data(), p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B\
    \ + i * m, t[i].data(), m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n,\
    \ m, C);\n  inner_block_dec_mul(&S, &T, &U);\n  vfps u(n, fps(m));\n  for (int\
    \ i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));\n  return\
    \ std::move(u);\n}\n\n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) vvm strassen(\n    const vvm& s, const vvm& t) {\n  int n = s.size(), p =\
    \ s[0].size(), m = t[0].size();\n  assert(int(n * p * 1.4) <= BUFFER_SIZE);\n\
    \  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n * m * 1.4) <= BUFFER_SIZE);\n\
    \  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n  memset(B, 0, int(p * m * 1.4)\
    \ * sizeof(int));\n  memset(C, 0, int(m * n * 1.4) * sizeof(int));\n\n  for (int\
    \ i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));\n  for (int\
    \ i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));\n\n  Mat\
    \ S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_strassen(&S, &T, &U);\n  vvm u(n,\
    \ vm(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));\n\
    \  return std::move(u);\n}\n\n__attribute__((target(\"avx2\"), optimize(\"O3\"\
    , \"unroll-loops\"))) vfps strassen(\n    const vfps& s, const vfps& t) {\n  int\
    \ n = s.size(), p = s[0].size(), m = t[0].size();\n  assert(int(n * p * 1.4) <=\
    \ BUFFER_SIZE);\n  assert(int(p * m * 1.4) <= BUFFER_SIZE);\n  assert(int(n *\
    \ m * 1.4) <= BUFFER_SIZE);\n  memset(A, 0, int(n * p * 1.4) * sizeof(int));\n\
    \  memset(B, 0, int(p * m * 1.4) * sizeof(int));\n  memset(C, 0, int(m * n * 1.4)\
    \ * sizeof(int));\n\n  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(),\
    \ p * sizeof(int));\n  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(),\
    \ m * sizeof(int));\n\n  Mat S(n, p, A), T(p, m, B), U(n, m, C);\n  inner_strassen(&S,\
    \ &T, &U);\n  vfps u(n, fps(m));\n  for (int i = 0; i < n; i++) memcpy(u[i].data(),\
    \ C + i * m, m * sizeof(int));\n  return std::move(u);\n}\n\n#ifdef BUFFER_SIZE\n\
    #undef BUFFER_SIZE\n#endif\n\n#line 2 \"misc/timer.hpp\"\n\n\n\nstruct Timer {\n\
    \  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset(); }\n\n\
    \  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 635 \"modulo/strassen.hpp\"\nvoid time_test() {\n  int N = 1024;\n  int P =\
    \ N, M = N;\n  mt19937 rng(58);\n  vvm s(N, vm(P)), t(P, vm(M));\n  for (int i\
    \ = 0; i < N; i++)\n    for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;\n\
    \  for (int i = 0; i < P; i++)\n    for (int j = 0; j < M; j++) t[i][j] = rng()\
    \ % 998244353;\n  vvm u, u2;\n  Timer timer;\n\n  int loop = 5;\n  timer.reset();\n\
    \  for (int i = 0; i < loop; i++) u = FastMatProd::strassen(s, t);\n  cout <<\
    \ \"strassen \" << (timer.elapsed() / loop) << endl;\n\n  timer.reset();\n  u2\
    \ = FastMatProd::naive_mul(s, t);\n  cout << \"naive \" << (timer.elapsed() /\
    \ loop) << endl;\n\n  timer.reset();\n  auto u3 = FastMatProd::block_dec(s, t);\n\
    \  cout << \"block dec \" << (timer.elapsed() / loop) << endl;\n\n  assert(u ==\
    \ u2);\n  assert(u == u3);\n}\n\nvoid debug_test() {\n  // time_test();\n  int\
    \ N, P, M;\n  mt19937 rng(58);\n  int loop = 1000;\n  while (loop--) {\n    N\
    \ = rng() % 500 + 1;\n    M = rng() % 500 + 1;\n    P = rng() % 500 + 1;\n   \
    \ vvm s(N, vm(P)), t(P, vm(M));\n    for (int i = 0; i < N; i++)\n      for (int\
    \ j = 0; j < P; j++) s[i][j] = rng() % 998244353;\n    for (int i = 0; i < P;\
    \ i++)\n      for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;\n    auto\
    \ u = strassen(s, t);\n    auto u2 = naive_mul(s, t);\n    auto u3 = block_dec(s,\
    \ t);\n    if (u != u2) {\n      cout << \"ng u1 \" << N << \" \" << P << \" \"\
    \ << M << endl;\n      exit(1);\n    } else if (u != u3) {\n      cout << \"ng\
    \ u1 \" << N << \" \" << P << \" \" << M << endl;\n      exit(1);\n    } else\
    \ {\n      cout << \"ok \" << N << \" \" << P << \" \" << M << endl;\n    }\n\
    \  }\n  cout << \"all ok\";\n}\n}  // namespace FastMatProd\n#line 5 \"fps/fps-composition-fast.hpp\"\
    \n\nusing mint = LazyMontgomeryModInt<998244353>;\nusing fps = FormalPowerSeries<mint>;\n\
    \n__attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) fps Composition(\n\
    \    fps P, fps Q, int deg = -1) {\n  int N = (deg == -1) ? min(P.size(), Q.size())\
    \ : deg;\n  if (N == 0) return fps{};\n  P.shrink();\n  if (P.size() == 0) {\n\
    \    fps R(N, mint(0));\n    R[0] = Q.empty() ? mint(0) : Q[0];\n    return R;\n\
    \  }\n  if (N == 1) return fps{Q.eval(P[0])};\n\n  int K = max<int>(ceil(sqrt(N)),\
    \ 2);\n  assert(N <= K * K);\n\n  vector<fps> PS(K + 1);\n  {\n    // step 1\n\
    \    PS[0].resize(N, mint());\n    PS[0][0] = 1;\n    PS[1] = P;\n    fps::set_fft();\n\
    \    if (fps::ntt_ptr == nullptr) {\n      for (int i = 2; i <= K; i++) PS[i]\
    \ = (PS[i - 1] * P).pre(N);\n    } else {\n      int len = 1 << (32 - __builtin_clz(2\
    \ * N - 2));\n      fps Pomega = P;\n      Pomega.resize(len);\n      Pomega.ntt();\n\
    \      for (int i = 2; i <= K; i++) {\n        PS[i].resize(len);\n        for\
    \ (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];\n        PS[i].ntt();\n   \
    \     for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];\n        PS[i].intt();\n\
    \        PS[i].resize(N);\n        PS[i].shrink_to_fit();\n      }\n    }\n  }\n\
    \n  vector<fps> TS(K);\n  {\n    // step 2\n    TS[0].resize(N, mint());\n   \
    \ TS[0][0] = 1;\n    TS[1] = PS[K];\n    if (fps::ntt_ptr == nullptr) {\n    \
    \  for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);\n    } else\
    \ {\n      int len = 1 << (32 - __builtin_clz(2 * N - 2));\n      fps Tomega =\
    \ TS[1];\n      Tomega.resize(len);\n      Tomega.ntt();\n      for (int i = 2;\
    \ i < K; i++) {\n        TS[i].resize(len);\n        for (int j = 0; j < N; j++)\
    \ TS[i][j] = TS[i - 1][j];\n        TS[i].ntt();\n        for (int j = 0; j <\
    \ len; j++) TS[i][j] *= Tomega[j];\n        TS[i].intt();\n        TS[i].resize(N);\n\
    \        TS[i].shrink_to_fit();\n      }\n    }\n  }\n\n  // step 3\n  vector<fps>\
    \ QP;\n  {\n    PS.pop_back();\n    vector<fps> QS(K, fps(K, mint()));\n    for\
    \ (int i = 0; i < K; i++)\n      for (int j = 0; j < K; j++) {\n        QS[i][j]\
    \ = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();\n      }\n    QP = FastMatProd::strassen(QS,\
    \ PS);\n  }\n\n  fps ans(N, mint());\n  {\n    // step 4,5\n    for (int i = 0;\
    \ i < K; i++) ans += (QP[i] * TS[i]).pre(N);\n  }\n  return ans;\n}\n\n/**\n *\
    \ @brief \u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )\n */\n"
  code: "#pragma once\n#include \"../fps/formal-power-series.hpp\"\n#include \"../modint/montgomery-modint.hpp\"\
    \n#include \"../modulo/strassen.hpp\"\n\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    using fps = FormalPowerSeries<mint>;\n\n__attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) fps Composition(\n    fps P, fps Q, int deg = -1) {\n\
    \  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;\n  if (N == 0) return\
    \ fps{};\n  P.shrink();\n  if (P.size() == 0) {\n    fps R(N, mint(0));\n    R[0]\
    \ = Q.empty() ? mint(0) : Q[0];\n    return R;\n  }\n  if (N == 1) return fps{Q.eval(P[0])};\n\
    \n  int K = max<int>(ceil(sqrt(N)), 2);\n  assert(N <= K * K);\n\n  vector<fps>\
    \ PS(K + 1);\n  {\n    // step 1\n    PS[0].resize(N, mint());\n    PS[0][0] =\
    \ 1;\n    PS[1] = P;\n    fps::set_fft();\n    if (fps::ntt_ptr == nullptr) {\n\
    \      for (int i = 2; i <= K; i++) PS[i] = (PS[i - 1] * P).pre(N);\n    } else\
    \ {\n      int len = 1 << (32 - __builtin_clz(2 * N - 2));\n      fps Pomega =\
    \ P;\n      Pomega.resize(len);\n      Pomega.ntt();\n      for (int i = 2; i\
    \ <= K; i++) {\n        PS[i].resize(len);\n        for (int j = 0; j < N; j++)\
    \ PS[i][j] = PS[i - 1][j];\n        PS[i].ntt();\n        for (int j = 0; j <\
    \ len; j++) PS[i][j] *= Pomega[j];\n        PS[i].intt();\n        PS[i].resize(N);\n\
    \        PS[i].shrink_to_fit();\n      }\n    }\n  }\n\n  vector<fps> TS(K);\n\
    \  {\n    // step 2\n    TS[0].resize(N, mint());\n    TS[0][0] = 1;\n    TS[1]\
    \ = PS[K];\n    if (fps::ntt_ptr == nullptr) {\n      for (int i = 2; i < K; i++)\
    \ TS[i] = (TS[i - 1] * TS[1]).pre(N);\n    } else {\n      int len = 1 << (32\
    \ - __builtin_clz(2 * N - 2));\n      fps Tomega = TS[1];\n      Tomega.resize(len);\n\
    \      Tomega.ntt();\n      for (int i = 2; i < K; i++) {\n        TS[i].resize(len);\n\
    \        for (int j = 0; j < N; j++) TS[i][j] = TS[i - 1][j];\n        TS[i].ntt();\n\
    \        for (int j = 0; j < len; j++) TS[i][j] *= Tomega[j];\n        TS[i].intt();\n\
    \        TS[i].resize(N);\n        TS[i].shrink_to_fit();\n      }\n    }\n  }\n\
    \n  // step 3\n  vector<fps> QP;\n  {\n    PS.pop_back();\n    vector<fps> QS(K,\
    \ fps(K, mint()));\n    for (int i = 0; i < K; i++)\n      for (int j = 0; j <\
    \ K; j++) {\n        QS[i][j] = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();\n\
    \      }\n    QP = FastMatProd::strassen(QS, PS);\n  }\n\n  fps ans(N, mint());\n\
    \  {\n    // step 4,5\n    for (int i = 0; i < K; i++) ans += (QP[i] * TS[i]).pre(N);\n\
    \  }\n  return ans;\n}\n\n/**\n * @brief \u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$\
    \ )\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modint/montgomery-modint.hpp
  - modulo/strassen.hpp
  - modint/simd-montgomery.hpp
  - misc/timer.hpp
  isVerificationFile: false
  path: fps/fps-composition-fast.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:16:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
documentation_of: fps/fps-composition-fast.hpp
layout: document
redirect_from:
- /library/fps/fps-composition-fast.hpp
- /library/fps/fps-composition-fast.hpp.html
title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
---
