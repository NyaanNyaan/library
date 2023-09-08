---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-seed.hpp
    title: internal/internal-seed.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/arbitrary-ntt-mod18446744069414584321.test.cpp
    title: verify/verify-unit-test/arbitrary-ntt-mod18446744069414584321.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigint2.test.cpp
    title: verify/verify-unit-test/bigint2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigint3.test.cpp
    title: verify/verify-unit-test/bigint3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/radix-sort.test.cpp
    title: verify/verify-unit-test/radix-sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rbst-segment-tree.test.cpp
    title: verify/verify-unit-test/rbst-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/all.hpp\"\n\n#line 2 \"misc/fastio.hpp\"\n\n#include\
    \ <cstdio>\n#include <cstring>\n#include <string>\n#include <type_traits>\n#include\
    \ <utility>\n\nusing namespace std;\n\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#line 4 \"internal/internal-type-traits.hpp\"\nusing namespace std;\n\nnamespace\
    \ internal {\ntemplate <typename T>\nusing is_broadly_integral =\n    typename\
    \ conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n            \
    \                   is_same_v<T, __uint128_t>,\n                           true_type,\
    \ false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed =\n   \
    \ typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n       \
    \                    true_type, false_type>::type;\n\ntemplate <typename T>\n\
    using is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T> || is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    #define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
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
    \ 12 \"misc/fastio.hpp\"\n\nnamespace fastio {\nstatic constexpr int SZ = 1 <<\
    \ 17;\nstatic constexpr int offset = 64;\nchar inbuf[SZ], outbuf[SZ];\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\nvoid load() {\n  int\
    \ len = in_right - in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right\
    \ = len + fread(inbuf + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\nvoid flush()\
    \ {\n  fwrite(outbuf, 1, out_right, stdout);\n  out_right = 0;\n}\nvoid skip_space()\
    \ {\n  if (in_left + offset > in_right) load();\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\n}\n\nvoid single_read(char& c) {\n  if (in_left + offset > in_right)\
    \ load();\n  skip_space();\n  c = inbuf[in_left++];\n}\nvoid single_read(string&\
    \ S) {\n  skip_space();\n  while (true) {\n    if (in_left == in_right) load();\n\
    \    int i = in_left;\n    for (; i != in_right; i++) {\n      if (inbuf[i] <=\
    \ ' ') break;\n    }\n    copy(inbuf + in_left, inbuf + i, back_inserter(S));\n\
    \    in_left = i;\n    if (i != in_right) break;\n  }\n}\ntemplate <typename T,\n\
    \          enable_if_t<internal::is_broadly_integral_v<T>>* = nullptr>\nvoid single_read(T&\
    \ x) {\n  if (in_left + offset > in_right) load();\n  skip_space();\n  char c\
    \ = inbuf[in_left++];\n  [[maybe_unused]] bool minus = false;\n  if constexpr\
    \ (internal::is_broadly_signed_v<T>) {\n    if (c == '-') minus = true, c = inbuf[in_left++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n\
    \  }\n  if constexpr (internal::is_broadly_signed_v<T>) {\n    if (minus) x =\
    \ -x;\n  }\n}\nvoid rd() {}\ntemplate <typename Head, typename... Tail>\nvoid\
    \ rd(Head& head, Tail&... tail) {\n  single_read(head);\n  rd(tail...);\n}\n\n\
    void single_write(const char& c) {\n  if (out_right > SZ - offset) flush();\n\
    \  outbuf[out_right++] = c;\n}\nvoid single_write(const bool& b) {\n  if (out_right\
    \ > SZ - offset) flush();\n  outbuf[out_right++] = b ? '1' : '0';\n}\nvoid single_write(const\
    \ string& S) {\n  flush(), fwrite(S.data(), 1, S.size(), stdout);\n}\nvoid single_write(const\
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
    using fastio::wt;\nusing fastio::wtn;\n#line 2 \"misc/rng.hpp\"\n\n#line 2 \"\
    internal/internal-seed.hpp\"\n\n#include <chrono>\nusing namespace std;\n\nnamespace\
    \ internal {\nunsigned long long non_deterministic_seed() {\n  unsigned long long\
    \ m =\n      chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  m ^= 9845834732710364265uLL;\n  m ^= m << 24, m ^= m >>\
    \ 31, m ^= m << 35;\n  return m;\n}\nunsigned long long deterministic_seed() {\
    \ return 88172645463325252UL; }\n\n// 64 bit \u306E seed \u5024\u3092\u751F\u6210\
    \ (\u624B\u5143\u3067\u306F seed \u56FA\u5B9A)\n// \u9023\u7D9A\u3067\u547C\u3073\
    \u51FA\u3059\u3068\u540C\u3058\u5024\u304C\u4F55\u5EA6\u3082\u8FD4\u3063\u3066\
    \u304F\u308B\u306E\u3067\u6CE8\u610F\n// #define RANDOMIZED_SEED \u3059\u308B\u3068\
    \u30B7\u30FC\u30C9\u304C\u30E9\u30F3\u30C0\u30E0\u306B\u306A\u308B\nunsigned long\
    \ long seed() {\n#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)\n  return\
    \ deterministic_seed();\n#else\n  return non_deterministic_seed();\n#endif\n}\n\
    \n}  // namespace internal\n#line 4 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    using i64 = long long;\nusing u64 = unsigned long long;\n\n// [0, 2^64 - 1)\n\
    u64 rng() {\n  static u64 _x = internal::seed();\n  return _x ^= _x << 7, _x ^=\
    \ _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n  return\
    \ l + rng() % u64(r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r) {\n \
    \ assert(l < r);\n  return l + rng() % u64(r - l);\n}\n\n// choose n numbers from\
    \ [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n  assert(l\
    \ <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i; --i) {\n\
    \    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m = r - i;\n\
    \    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n// [l, r)\ndouble rnd(double l, double r) {\n  assert(l < r);\n  return l\
    \ + rnd() * (r - l);\n}\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n\
    \  int n = v.size();\n  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i\
    \ + 1)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\n\
    using my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n#line 2 \"\
    misc/timer.hpp\"\n\n#line 4 \"misc/timer.hpp\"\nusing namespace std;\n\nstruct\
    \ Timer {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset();\
    \ }\n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  long long\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n  long long\
    \ operator()() { return elapsed(); }\n};\n#line 6 \"misc/all.hpp\"\n"
  code: '#pragma once


    #include "fastio.hpp"

    #include "rng.hpp"

    #include "timer.hpp"

    '
  dependsOn:
  - misc/fastio.hpp
  - internal/internal-type-traits.hpp
  - misc/rng.hpp
  - internal/internal-seed.hpp
  - misc/timer.hpp
  isVerificationFile: false
  path: misc/all.hpp
  requiredBy: []
  timestamp: '2023-09-05 21:46:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/bigint3.test.cpp
  - verify/verify-unit-test/bigint2.test.cpp
  - verify/verify-unit-test/arbitrary-ntt-mod18446744069414584321.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/rbst-segment-tree.test.cpp
  - verify/verify-unit-test/radix-sort.test.cpp
documentation_of: misc/all.hpp
layout: document
redirect_from:
- /library/misc/all.hpp
- /library/misc/all.hpp.html
title: misc/all.hpp
---
