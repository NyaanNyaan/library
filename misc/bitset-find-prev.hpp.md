---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bitset-find-prev.test.cpp
    title: verify/verify-unit-test/bitset-find-prev.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: bitset::find_prev
    links:
    - https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/bitset
  bundledCode: "#line 2 \"misc/bitset-find-prev.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/bitset\n\
    template <size_t Nb>\nstruct Bitset : bitset<Nb> {\n  template <typename... Args>\n\
    \  Bitset(Args... args) : bitset<Nb>(args...) {}\n\n  static constexpr int N =\
    \ Nb;\n  static constexpr int array_size = (Nb + 63) / 64;\n\n  union raw_cast\
    \ {\n    array<uint64_t, array_size> a;\n    Bitset b;\n  };\n\n  int _Find_prev(size_t\
    \ i) const {\n    if (i == 0) return -1;\n    if ((*this)[--i] == true) return\
    \ i;\n    size_t M = i / 64;\n    const auto& a = ((raw_cast*)(this))->a;\n  \
    \  uint64_t buf = a[M] & ((1ull << (i & 63)) - 1);\n    if (buf != 0) return M\
    \ * 64 + 63 - __builtin_clzll(buf);\n    while (M--) {\n      if (a[M] != 0) return\
    \ M * 64 + 63 - __builtin_clzll(a[M]);\n    }\n    return -1;\n  }\n\n  inline\
    \ int _Find_last() const { return _Find_prev(N); }\n};\n\n/**\n * @brief bitset::find_prev\n\
    \ */\n"
  code: "#pragma once\n\n// \u53C2\u8003\uFF1Ahttps://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/bitset\n\
    template <size_t Nb>\nstruct Bitset : bitset<Nb> {\n  template <typename... Args>\n\
    \  Bitset(Args... args) : bitset<Nb>(args...) {}\n\n  static constexpr int N =\
    \ Nb;\n  static constexpr int array_size = (Nb + 63) / 64;\n\n  union raw_cast\
    \ {\n    array<uint64_t, array_size> a;\n    Bitset b;\n  };\n\n  int _Find_prev(size_t\
    \ i) const {\n    if (i == 0) return -1;\n    if ((*this)[--i] == true) return\
    \ i;\n    size_t M = i / 64;\n    const auto& a = ((raw_cast*)(this))->a;\n  \
    \  uint64_t buf = a[M] & ((1ull << (i & 63)) - 1);\n    if (buf != 0) return M\
    \ * 64 + 63 - __builtin_clzll(buf);\n    while (M--) {\n      if (a[M] != 0) return\
    \ M * 64 + 63 - __builtin_clzll(a[M]);\n    }\n    return -1;\n  }\n\n  inline\
    \ int _Find_last() const { return _Find_prev(N); }\n};\n\n/**\n * @brief bitset::find_prev\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/bitset-find-prev.hpp
  requiredBy: []
  timestamp: '2021-04-19 21:35:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/bitset-find-prev.test.cpp
documentation_of: misc/bitset-find-prev.hpp
layout: document
redirect_from:
- /library/misc/bitset-find-prev.hpp
- /library/misc/bitset-find-prev.hpp.html
title: bitset::find_prev
---
