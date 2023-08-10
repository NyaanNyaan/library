---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/subset-convolution.hpp
    title: math-fast/subset-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/vectorize-modint.hpp
    title: vectorize modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n//\n\
    #include <immintrin.h>\n//\n#include <algorithm>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cstdint>\n#include <cstdio>\n#include <cstring>\n#include\
    \ <iostream>\n#include <random>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nusing namespace std;\n\n#line 2 \"misc/fastio.hpp\"\n\n#line\
    \ 5 \"misc/fastio.hpp\"\n#include <string>\n#line 8 \"misc/fastio.hpp\"\n\nusing\
    \ namespace std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n#line 4 \"\
    internal/internal-type-traits.hpp\"\nusing namespace std;\n\nnamespace internal\
    \ {\ntemplate <typename T>\nusing is_broadly_integral =\n    typename conditional_t<is_integral_v<T>\
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
    \n}  // namespace internal\n#line 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\n\
    static constexpr int SZ = 1 << 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ],\
    \ outbuf[SZ];\nint in_left = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n\
    \  char num[40000];\n  constexpr Pre() : num() {\n    for (int i = 0; i < 10000;\
    \ i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i\
    \ * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n  }\n} constexpr\
    \ pre;\n\nvoid load() {\n  int len = in_right - in_left;\n  memmove(inbuf, inbuf\
    \ + in_left, len);\n  in_right = len + fread(inbuf + len, 1, SZ - len, stdin);\n\
    \  in_left = 0;\n}\nvoid flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n\
    \  out_right = 0;\n}\nvoid skip_space() {\n  if (in_left + offset > in_right)\
    \ load();\n  while (inbuf[in_left] <= ' ') in_left++;\n}\n\nvoid single_read(char&\
    \ c) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  c = inbuf[in_left++];\n\
    }\nvoid single_read(string& S) {\n  skip_space();\n  while (true) {\n    if (in_left\
    \ == in_right) load();\n    int i = in_left;\n    for (; i != in_right; i++) {\n\
    \      if (inbuf[i] <= ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i,\
    \ back_inserter(S));\n    in_left = i;\n    if (i != in_right) break;\n  }\n}\n\
    template <typename T,\n          enable_if_t<internal::is_broadly_integral_v<T>>*\
    \ = nullptr>\nvoid single_read(T& x) {\n  if (in_left + offset > in_right) load();\n\
    \  skip_space();\n  char c = inbuf[in_left++];\n  [[maybe_unused]] bool minus\
    \ = false;\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (c ==\
    \ '-') minus = true, c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >= '0')\
    \ {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (minus) x = -x;\n  }\n}\nvoid rd()\
    \ {}\ntemplate <typename Head, typename... Tail>\nvoid rd(Head& head, Tail&...\
    \ tail) {\n  single_read(head);\n  rd(tail...);\n}\n\nvoid single_write(const\
    \ char& c) {\n  if (out_right > SZ - offset) flush();\n  outbuf[out_right++] =\
    \ c;\n}\nvoid single_write(const bool& b) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const string& S)\
    \ {\n  flush(), fwrite(S.data(), 1, S.size(), stdout);\n}\nvoid single_write(const\
    \ char* p) { flush(), fwrite(p, 1, strlen(p), stdout); }\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_write(const\
    \ T& _x) {\n  if (out_right > SZ - offset) flush();\n  if (_x == 0) {\n    outbuf[out_right++]\
    \ = '0';\n    return;\n  }\n  T x = _x;\n  if constexpr (internal::is_broadly_signed_v<T>)\
    \ {\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\n  }\n  constexpr int buffer_size\
    \ = sizeof(T) * 10 / 4;\n  char buf[buffer_size];\n  int i = buffer_size;\n  while\
    \ (x >= 10000) {\n    i -= 4;\n    memcpy(buf + i, pre.num + (x % 10000) * 4,\
    \ 4);\n    x /= 10000;\n  }\n  if (x < 100) {\n    if (x < 10) {\n      outbuf[out_right]\
    \ = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      outbuf[out_right]\
    \ = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n      out_right += 2;\n\
    \    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n      out_right += 3;\n    } else {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2), 4);\n      out_right += 4;\n    }\n  }\n  memcpy(outbuf\
    \ + out_right, buf + i, buffer_size - i);\n  out_right += buffer_size - i;\n}\n\
    void wt() {}\ntemplate <typename Head, typename... Tail>\nvoid wt(const Head&\
    \ head, const Tail&... tail) {\n  single_write(head);\n  wt(forward<const Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\nvoid wtn(const Args&... x) {\n  wt(forward<const\
    \ Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush);\
    \ }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\n\
    using fastio::wt;\nusing fastio::wtn;\n#line 20 \"verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\
    \n//\n#line 2 \"math-fast/subset-convolution.hpp\"\n\n#line 5 \"math-fast/subset-convolution.hpp\"\
    \nusing namespace std;\n\n#line 2 \"modint/vectorize-modint.hpp\"\n\n#pragma GCC\
    \ optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"avx2\")\n\n#line 8 \"modint/vectorize-modint.hpp\"\
    \nusing namespace std;\n\nusing m256 = __m256i;\nstruct alignas(32) mmint {\n\
    \  m256 x;\n  static mmint R, M0, M1, M2, N2;\n\n  mmint() : x() {}\n  inline\
    \ mmint(const m256& _x) : x(_x) {}\n  inline mmint(unsigned int a) : x(_mm256_set1_epi32(a))\
    \ {}\n  inline mmint(unsigned int a0, unsigned int a1, unsigned int a2,\n    \
    \           unsigned int a3, unsigned int a4, unsigned int a5,\n             \
    \  unsigned int a6, unsigned int a7)\n      : x(_mm256_set_epi32(a7, a6, a5, a4,\
    \ a3, a2, a1, a0)) {}\n  inline operator m256&() { return x; }\n  inline operator\
    \ const m256&() const { return x; }\n  inline int& operator[](int i) { return\
    \ *(reinterpret_cast<int*>(&x) + i); }\n  inline const int& operator[](int i)\
    \ const {\n    return *(reinterpret_cast<const int*>(&x) + i);\n  }\n\n  friend\
    \ ostream& operator<<(ostream& os, const mmint& m) {\n    unsigned r = R[0], mod\
    \ = M1[0];\n    auto reduce1 = [&](const uint64_t& b) {\n      unsigned res =\
    \ (b + uint64_t(unsigned(b) * unsigned(-r)) * mod) >> 32;\n      return res >=\
    \ mod ? res - mod : res;\n    };\n    for (int i = 0; i < 8; i++) {\n      os\
    \ << reduce1(m[i]) << (i == 7 ? \"\" : \" \");\n    }\n    return os;\n  }\n\n\
    \  template <typename mint>\n  static void set_mod() {\n    R = _mm256_set1_epi32(mint::r);\n\
    \    M0 = _mm256_setzero_si256();\n    M1 = _mm256_set1_epi32(mint::get_mod());\n\
    \    M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    N2 = _mm256_set1_epi32(mint::n2);\n\
    \  }\n\n  static inline mmint reduce(const mmint& prod02, const mmint& prod13)\
    \ {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);\n    m256 unpahi\
    \ = _mm256_unpackhi_epi32(prod02, prod13);\n    m256 prodlo = _mm256_unpacklo_epi64(unpalo,\
    \ unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);\n    m256\
    \ hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 prodlohi = _mm256_shuffle_epi32(prodlo,\
    \ 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(prodlo, R);\n    m256 lmlr13 = _mm256_mul_epu32(prodlohi,\
    \ R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    return _mm256_sub_epi32(hiplm1, prod);\n  }\n\n  static inline\
    \ mmint itom(const mmint& A) { return A * N2; }\n\n  static inline mmint mtoi(const\
    \ mmint& A) {\n    m256 A13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 lmlr02\
    \ = _mm256_mul_epu32(A, R);\n    m256 lmlr13 = _mm256_mul_epu32(A13, R);\n   \
    \ m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmp = _mm256_cmpgt_epi32(prod, M0);\n    m256 dif = _mm256_and_si256(cmp,\
    \ M1);\n    return _mm256_sub_epi32(dif, prod);\n  }\n\n  friend inline mmint\
    \ operator+(const mmint& A, const mmint& B) {\n    m256 apb = _mm256_add_epi32(A,\
    \ B);\n    m256 ret = _mm256_sub_epi32(apb, M2);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator-(const mmint& A, const mmint& B)\
    \ {\n    m256 ret = _mm256_sub_epi32(A, B);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator*(const mmint& A, const mmint& B)\
    \ {\n    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(B,\
    \ 0xF5);\n    m256 prod02 = _mm256_mul_epu32(A, B);\n    m256 prod13 = _mm256_mul_epu32(a13,\
    \ b13);\n    return reduce(prod02, prod13);\n  }\n\n  inline mmint& operator+=(const\
    \ mmint& A) { return (*this) = (*this) + A; }\n  inline mmint& operator-=(const\
    \ mmint& A) { return (*this) = (*this) - A; }\n  inline mmint& operator*=(const\
    \ mmint& A) { return (*this) = (*this) * A; }\n\n  bool operator==(const mmint&\
    \ A) {\n    m256 sub = _mm256_sub_epi32(x, A.x);\n    return _mm256_testz_si256(sub,\
    \ sub) == 1;\n  }\n  bool operator!=(const mmint& A) { return !((*this) == A);\
    \ }\n};\n__attribute__((aligned(32))) mmint mmint::R;\n__attribute__((aligned(32)))\
    \ mmint mmint::M0, mmint::M1, mmint::M2, mmint::N2;\n\n/**\n * @brief vectorize\
    \ modint\n */\n#line 8 \"math-fast/subset-convolution.hpp\"\n\ntemplate <typename\
    \ mint>\nvector<mint> fast_multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = a.size();\n  int d = __builtin_ctz(n);\n  assert(d <= 23);\n\
    \  mmint* a1 = new mmint[max(n, 8) * 3];\n  mmint* a2 = new mmint[max(n, 8) *\
    \ 3];\n  memset((void*)a1, 0, max(n, 8) * 3 * sizeof(mmint));\n  memset((void*)a2,\
    \ 0, max(n, 8) * 3 * sizeof(mmint));\n  mmint b1[24], b2[24], b3[24];\n\n  for\
    \ (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n  \
    \  a1[i * 3 + pc / 8][pc % 8] = a[i].a;\n    a2[i * 3 + pc / 8][pc % 8] = b[i].a;\n\
    \  }\n\n  for (int j = 2; j <= n; j += 2) {\n    unsigned int pc = __builtin_popcount(j);\n\
    \    unsigned int ctz = __builtin_ctz(j);\n    for (int h = 0; h < d; h++) {\n\
    \      if (j & (1 << h)) break;\n      int li = j - 2 * (1 << h), ri = j - (1\
    \ << h);\n      if (pc + ctz <= 16) {\n        for (int i = 0; i < 3 * (1 << h);\
    \ i += 3) {\n          a1[ri * 3 + i + 0] += a1[li * 3 + i + 0];\n          a2[ri\
    \ * 3 + i + 0] += a2[li * 3 + i + 0];\n          a1[ri * 3 + i + 1] += a1[li *\
    \ 3 + i + 1];\n          a2[ri * 3 + i + 1] += a2[li * 3 + i + 1];\n        }\n\
    \      } else {\n        for (int i = 0; i < 3 * (1 << h); i++) {\n          a1[ri\
    \ * 3 + i] += a1[li * 3 + i];\n          a2[ri * 3 + i] += a2[li * 3 + i];\n \
    \       }\n      }\n    }\n  }\n\n  mmint th = _mm256_set1_epi64x(4LL * mmint::M1[0]\
    \ * mmint::M1[0]);\n\n  for (int is = 0; is < n; is += 8) {\n    int mpc = d;\n\
    \n    for (int i = is; i < is + 8; i++) {\n      int pc = __builtin_popcount(i);\n\
    \      mpc = min(mpc, pc);\n      for (int j = 0; j <= d; j++) {\n        b1[j][i\
    \ - is] = a1[i * 3 + j / 8][j % 8];\n        b2[j][i - is] = a2[i * 3 + j / 8][j\
    \ % 8];\n        b3[j][i - is] = 0;\n      }\n    }\n\n    for (int j = 0; j <=\
    \ d; j++) {\n      m256 cmpB1 = _mm256_cmpgt_epi32(mmint::M1, b1[j]);\n      m256\
    \ cmpB2 = _mm256_cmpgt_epi32(mmint::M1, b2[j]);\n      m256 difB1 = _mm256_andnot_si256(cmpB1,\
    \ mmint::M1);\n      m256 difB2 = _mm256_andnot_si256(cmpB2, mmint::M1);\n   \
    \   b1[j] = _mm256_sub_epi32(b1[j], difB1);\n      b2[j] = _mm256_sub_epi32(b2[j],\
    \ difB2);\n    }\n\n#define PROD(k)                                          \
    \   \\\n  m256 A13##k = _mm256_shuffle_epi32(b1[j + k], 0xF5);      \\\n  m256\
    \ B13##k = _mm256_shuffle_epi32(b2[l - j - k], 0xF5);  \\\n  m256 p02##k = _mm256_mul_epi32(b1[j\
    \ + k], b2[l - j - k]); \\\n  m256 p13##k = _mm256_mul_epi32(A13##k, B13##k);\
    \           \\\n  prod02 = _mm256_add_epi64(prod02, p02##k);                \\\
    \n  prod13 = _mm256_add_epi64(prod13, p13##k)\n#define COMP()                \
    \                   \\\n  do {                                           \\\n\
    \    m256 cmp02 = _mm256_cmpgt_epi64(prod02, th); \\\n    m256 cmp13 = _mm256_cmpgt_epi64(prod13,\
    \ th); \\\n    m256 dif02 = _mm256_and_si256(cmp02, th);    \\\n    m256 dif13\
    \ = _mm256_and_si256(cmp13, th);    \\\n    prod02 = _mm256_sub_epi64(prod02,\
    \ dif02);    \\\n    prod13 = _mm256_sub_epi64(prod13, dif13);    \\\n  } while\
    \ (0)\n\n    for (int l = mpc; l <= d; l++) {\n      int j = 0;\n      mmint prod02\
    \ = mmint::M0, prod13 = mmint::M0;\n\n      for (; j <= l - 3; j += 4) {\n   \
    \     PROD(0);\n        PROD(1);\n        PROD(2);\n        PROD(3);\n       \
    \ COMP();\n      }\n      for (; j <= l; j++) {\n        PROD(0);\n      }\n \
    \     COMP();\n      b3[l] = mmint::reduce(prod02, prod13);\n    }\n\n#undef PROD\n\
    #undef COMP\n\n    for (int i = is; i < is + 8; i++) {\n      for (unsigned j\
    \ = mpc; j <= unsigned(d); j++) {\n        a1[i * 3 + j / 8][j % 8] = b3[j][i\
    \ - is];\n      }\n    }\n  }\n\n  for (int j = 2; j <= n; j += 2) {\n    for\
    \ (int h = 0; h < d; h++) {\n      if (j & (1 << h)) break;\n      int li = j\
    \ - 2 * (1 << h), ri = j - (1 << h);\n      for (int i = 0; i < 3 * (1 << h);\
    \ i++) {\n        a1[ri * 3 + i] -= a1[li * 3 + i];\n      }\n    }\n  }\n\n \
    \ vector<mint> c(n);\n  for (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n\
    \    c[i].a = a1[i * 3 + pc / 8][pc % 8];\n  }\n\n  delete[] (a1);\n  delete[]\
    \ (a2);\n  return c;\n}\n#line 22 \"verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\
    \n//\n#line 2 \"modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct\
    \ LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32 =\
    \ int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod < (1 << 30),\
    \ \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod\
    \ % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\");\n\n  u32\
    \ a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \ { return mod; }\n};\n#line 24 \"verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\
    \n\nint main() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  using vm\
    \ = vector<mint>;\n  mmint::set_mod<mint>();\n\n  int N;\n  rd(N);\n  using vm\
    \ = vector<mint>;\n  vm a(1 << N), b(1 << N);\n  unsigned int n;\n  for (int i\
    \ = 0; i < 1 << N; i++) {\n    rd(n);\n    a[i].a = mint::reduce(uint64_t(n) *\
    \ mint::n2);\n  }\n  for (int i = 0; i < 1 << N; i++) {\n    rd(n);\n    b[i].a\
    \ = mint::reduce(uint64_t(n) * mint::n2);\n  }\n  auto c = fast_multiply(a, b);\n\
    \n  for (int i = 0; i < 1 << N; i++) {\n    if (i) wt(' ');\n    wt(c[i].get());\n\
    \  }\n  wt('\\n');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    //\n#include <immintrin.h>\n//\n#include <algorithm>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cstdint>\n#include <cstdio>\n#include <cstring>\n#include\
    \ <iostream>\n#include <random>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nusing namespace std;\n\n#include \"../../misc/fastio.hpp\"\
    \n//\n#include \"../../math-fast/subset-convolution.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n\nint main() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  using vm\
    \ = vector<mint>;\n  mmint::set_mod<mint>();\n\n  int N;\n  rd(N);\n  using vm\
    \ = vector<mint>;\n  vm a(1 << N), b(1 << N);\n  unsigned int n;\n  for (int i\
    \ = 0; i < 1 << N; i++) {\n    rd(n);\n    a[i].a = mint::reduce(uint64_t(n) *\
    \ mint::n2);\n  }\n  for (int i = 0; i < 1 << N; i++) {\n    rd(n);\n    b[i].a\
    \ = mint::reduce(uint64_t(n) * mint::n2);\n  }\n  auto c = fast_multiply(a, b);\n\
    \n  for (int i = 0; i < 1 << N; i++) {\n    if (i) wt(' ');\n    wt(c[i].get());\n\
    \  }\n  wt('\\n');\n}\n"
  dependsOn:
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - math-fast/subset-convolution.hpp
  - modint/vectorize-modint.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 14:25:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp.html
title: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
---
