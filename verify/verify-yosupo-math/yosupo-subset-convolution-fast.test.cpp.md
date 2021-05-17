---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math-fast/subset-convolution.hpp
    title: math-fast/subset-convolution.hpp
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: modint/vectorize-modint.hpp
    title: vectorize modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ 6 \"misc/fastio.hpp\"\n\nusing namespace std;\n\nnamespace fastio {\nstatic\
    \ constexpr int SZ = 1 << 17;\nchar inbuf[SZ], outbuf[SZ];\nint in_left = 0, in_right\
    \ = 0, out_right = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr Pre() :\
    \ num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n      for\
    \ (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n       \
    \ n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void load() {\n  int\
    \ len = in_right - in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right\
    \ = len + fread(inbuf + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\n\ninline\
    \ void flush() {\n  fwrite(outbuf, 1, out_right, stdout);\n  out_right = 0;\n\
    }\n\ninline void skip_space() {\n  if (in_left + 32 > in_right) load();\n  while\
    \ (inbuf[in_left] <= ' ') in_left++;\n}\n\ninline void rd(char& c) {\n  if (in_left\
    \ + 32 > in_right) load();\n  c = inbuf[in_left++];\n}\ntemplate <typename T>\n\
    inline void rd(T& x) {\n  if (in_left + 32 > in_right) load();\n  char c;\n  do\
    \ c = inbuf[in_left++];\n  while (c < '-');\n  [[maybe_unused]] bool minus = false;\n\
    \  if constexpr (is_signed<T>::value == true) {\n    if (c == '-') minus = true,\
    \ c = inbuf[in_left++];\n  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 +\
    \ (c & 15);\n    c = inbuf[in_left++];\n  }\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (minus) x = -x;\n  }\n}\ninline void rd() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n\
    \  rd(tail...);\n}\n\ninline void wt(char c) {\n  if (out_right > SZ - 32) flush();\n\
    \  outbuf[out_right++] = c;\n}\ninline void wt(bool b) {\n  if (out_right > SZ\
    \ - 32) flush();\n  outbuf[out_right++] = b ? '1' : '0';\n}\ntemplate <typename\
    \ T>\ninline void wt(T x) {\n  if (out_right > SZ - 32) flush();\n  if (!x) {\n\
    \    outbuf[out_right++] = '0';\n    return;\n  }\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i\
    \ = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num\
    \ + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n\
    \    if (x < 10) {\n      outbuf[out_right] = '0' + x;\n      ++out_right;\n \
    \   } else {\n      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r\
    \ = uint32_t(x) - q * 10;\n      outbuf[out_right] = '0' + q;\n      outbuf[out_right\
    \ + 1] = '0' + r;\n      out_right += 2;\n    }\n  } else {\n    if (x < 1000)\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\n      out_right\
    \ += 3;\n    } else {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n\
    \      out_right += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4,\
    \ 12 - i);\n  out_right += 12 - i;\n}\ninline void wt() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n\
    \  wt(forward<Tail>(tail)...);\n}\ntemplate <typename... Args>\ninline void wtn(Args&&...\
    \ x) {\n  wt(forward<Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy()\
    \ { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 20 \"\
    verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\n//\n#line\
    \ 2 \"math-fast/subset-convolution.hpp\"\n\n#line 2 \"modint/vectorize-modint.hpp\"\
    \n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"avx2\")\n\n\
    using m256 = __m256i;\nstruct alignas(32) mmint {\n  m256 x;\n  static mmint R,\
    \ mR, M0, M1, M2, N2;\n\n  mmint() : x() {}\n  inline mmint(const m256& _x) :\
    \ x(_x) {}\n  inline mmint(int a) : x(_mm256_set1_epi32(a)) {}\n  inline mmint(int\
    \ a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)\n      : x(_mm256_set_epi32(a7,\
    \ a6, a5, a4, a3, a2, a1, a0)) {}\n  inline operator m256&() { return x; }\n \
    \ inline operator const m256&() const { return x; }\n  inline int& operator[](int\
    \ i) { return *(reinterpret_cast<int*>(&x) + i); }\n  inline const int& operator[](int\
    \ i) const {\n    return *(reinterpret_cast<const int*>(&x) + i);\n  }\n\n  friend\
    \ ostream& operator<<(ostream& os, const mmint& m) {\n    unsigned r = R[0], mod\
    \ = M1[0];\n    auto reduce1 = [&](const uint64_t& b) {\n      unsigned res =\
    \ (b + uint64_t(unsigned(b) * unsigned(-r)) * mod) >> 32;\n      return res >=\
    \ mod ? res - mod : res;\n    };\n    for (int i = 0; i < 8; i++) {\n      os\
    \ << reduce1(m[i]) << (i == 7 ? \"\" : \" \");\n    }\n    return os;\n  }\n\n\
    \  template <typename mint>\n  static void set_mod() {\n    R = _mm256_set1_epi32(mint::r);\n\
    \    M0 = _mm256_setzero_si256();\n    M1 = _mm256_set1_epi32(mint::get_mod());\n\
    \    M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    N2 = _mm256_set1_epi32(mint::n2);\n\
    \    mR = _mm256_sub_epi32(M0, R);\n  }\n\n  static inline mmint reduce(const\
    \ mmint& prod02, const mmint& prod13) {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02,\
    \ prod13);\n    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);\n    m256\
    \ prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 lomulr =\
    \ _mm256_mullo_epi32(prodlo, R);\n    m256 a13 = _mm256_shuffle_epi32(lomulr,\
    \ 0xF5);\n    m256 prod02_ = _mm256_mul_epu32(lomulr, M1);\n    m256 prod13_ =\
    \ _mm256_mul_epu32(a13, M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_,\
    \ prod13_);\n    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n   \
    \ m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);\n    return _mm256_sub_epi32(hiplm1,\
    \ prod);\n  }\n\n  static inline mmint itom(const mmint& A) { return A * N2; }\n\
    \n  static inline mmint mtoi(const mmint& A) {\n    m256 lomulr = _mm256_mullo_epi32(A,\
    \ mR);\n    m256 a13 = _mm256_shuffle_epi32(lomulr, 0xF5);\n    m256 prod02_ =\
    \ _mm256_mul_epu32(lomulr, M1);\n    m256 prod13_ = _mm256_mul_epu32(a13, M1);\n\
    \    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256 unpahi_\
    \ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmpA = _mm256_cmpgt_epi32(A, M0);\n    m256 addA = _mm256_and_si256(cmpA,\
    \ mmint(1));\n    return _mm256_add_epi32(prod, addA);\n  }\n\n  friend inline\
    \ mmint operator+(const mmint& A, const mmint& B) {\n    m256 apb = _mm256_add_epi32(A,\
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
    \ }\n};\n__attribute__((aligned(32))) mmint mmint::R, mmint::mR;\n__attribute__((aligned(32)))\
    \ mmint mmint::M0, mmint::M1, mmint::M2, mmint::N2;\n\n/**\n * @brief vectorize\
    \ modint\n */\n#line 4 \"math-fast/subset-convolution.hpp\"\n//\ntemplate <typename\
    \ mint>\nvector<mint> fast_multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = a.size();\n  int d = __builtin_ctz(n);\n  assert(n <= 23);\n\
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
    \    c[i].a = a1[i * 3 + pc / 8][pc % 8];\n  }\n\n  delete[](a1);\n  delete[](a2);\n\
    \  return c;\n}\n#line 22 \"verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp\"\
    \n//\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\n\
    struct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32\
    \ = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"\
    invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    \  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
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
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
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
  - math-fast/subset-convolution.hpp
  - modint/vectorize-modint.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
  requiredBy: []
  timestamp: '2021-05-17 18:16:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
- /verify/verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp.html
title: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
---
