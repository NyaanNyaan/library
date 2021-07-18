---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u52D5\u7684bitset"
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-bitset.hpp\"\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n\nstruct BitSet {\n  using u64 = unsigned long long;\n  vector<u64>\
    \ a;\n  size_t N;\n\n  static u64 maskbit(size_t pos) { return 1uLL << pos; }\n\
    \n  struct ref {\n    u64 *p;\n    size_t pos;\n    ref(BitSet &b, size_t _pos)\
    \ {\n      p = b.a.data() + _pos / 64;\n      pos = _pos % 64;\n    }\n    operator\
    \ bool() const { return (*p & maskbit(pos)) != 0; }\n    bool operator~() const\
    \ { return (*p & maskbit(pos)) == 0; }\n    ref &flip() {\n      *p ^= maskbit(pos);\n\
    \      return *this;\n    }\n    ref &operator=(bool x) {\n      if (x) {\n  \
    \      *p |= maskbit(pos);\n      } else {\n        *p &= ~maskbit(pos);\n   \
    \   }\n      return *this;\n    }\n    ref &operator=(const ref &r) { return *this\
    \ = bool(r); }\n  };\n\n  BitSet(size_t _N) : a((_N + 63) / 64, 0), N(_N) {}\n\
    \n  ref operator[](size_t pos) { return ref(*this, pos); }\n  bool operator[](size_t\
    \ pos) const {\n    return (a[pos / 64] & maskbit(pos % 64)) != 0;\n  }\n  bool\
    \ test(size_t pos) const { return (a[pos / 64] & maskbit(pos % 64)) != 0; }\n\
    \  void set(size_t pos) { a[pos / 64] |= maskbit(pos % 64); }\n  void reset(size_t\
    \ pos) { a[pos / 64] &= ~maskbit(pos % 64); }\n  void flip(size_t pos) { a[pos\
    \ / 64] ^= maskbit(pos % 64); }\n  size_t size() const { return N; }\n\n  __attribute__((optimize(\"\
    O3,unroll-loops\"))) BitSet &operator^=(\n      const BitSet &r) {\n    assert(a.size()\
    \ == r.a.size());\n    for (size_t i = 0; i < a.size(); i++) a[i] ^= r.a[i];\n\
    \    return *this;\n  }\n\n  __attribute__((optimize(\"O3,unroll-loops\"))) int\
    \ _Find_next(size_t i) const {\n    ++i;\n    if (i >= N) return N;\n    size_t\
    \ M = i / 64;\n    u64 buf = a[M];\n    buf &= ~u64(0) << (i % 64);\n    if (buf\
    \ != 0) return M * 64 + __builtin_ctzll(buf);\n    for (; ++M < a.size();) {\n\
    \      if (a[M] != 0) return M * 64 + __builtin_ctzll(a[M]);\n    }\n    return\
    \ N;\n  }\n  int _Find_first() const { return _Find_next(-1); }\n\n  __attribute__((optimize(\"\
    O3,unroll-loops\"))) int _Find_prev(size_t i) const {\n    if (i == 0) return\
    \ -1;\n    if ((*this)[--i] == true) return i;\n    size_t M = i / 64;\n    u64\
    \ buf = a[M];\n    buf &= maskbit(i % 64) - 1;\n    if (buf != 0) return M * 64\
    \ + 63 - __builtin_clzll(buf);\n    while (M--) {\n      if (a[M] != 0) return\
    \ M * 64 + 63 - __builtin_clzll(a[M]);\n    }\n    return -1;\n  }\n  int _Find_last()\
    \ const { return _Find_prev(N); }\n};\n\n/**\n * @brief \u52D5\u7684bitset\n */\n"
  code: "#pragma once\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\nstruct BitSet\
    \ {\n  using u64 = unsigned long long;\n  vector<u64> a;\n  size_t N;\n\n  static\
    \ u64 maskbit(size_t pos) { return 1uLL << pos; }\n\n  struct ref {\n    u64 *p;\n\
    \    size_t pos;\n    ref(BitSet &b, size_t _pos) {\n      p = b.a.data() + _pos\
    \ / 64;\n      pos = _pos % 64;\n    }\n    operator bool() const { return (*p\
    \ & maskbit(pos)) != 0; }\n    bool operator~() const { return (*p & maskbit(pos))\
    \ == 0; }\n    ref &flip() {\n      *p ^= maskbit(pos);\n      return *this;\n\
    \    }\n    ref &operator=(bool x) {\n      if (x) {\n        *p |= maskbit(pos);\n\
    \      } else {\n        *p &= ~maskbit(pos);\n      }\n      return *this;\n\
    \    }\n    ref &operator=(const ref &r) { return *this = bool(r); }\n  };\n\n\
    \  BitSet(size_t _N) : a((_N + 63) / 64, 0), N(_N) {}\n\n  ref operator[](size_t\
    \ pos) { return ref(*this, pos); }\n  bool operator[](size_t pos) const {\n  \
    \  return (a[pos / 64] & maskbit(pos % 64)) != 0;\n  }\n  bool test(size_t pos)\
    \ const { return (a[pos / 64] & maskbit(pos % 64)) != 0; }\n  void set(size_t\
    \ pos) { a[pos / 64] |= maskbit(pos % 64); }\n  void reset(size_t pos) { a[pos\
    \ / 64] &= ~maskbit(pos % 64); }\n  void flip(size_t pos) { a[pos / 64] ^= maskbit(pos\
    \ % 64); }\n  size_t size() const { return N; }\n\n  __attribute__((optimize(\"\
    O3,unroll-loops\"))) BitSet &operator^=(\n      const BitSet &r) {\n    assert(a.size()\
    \ == r.a.size());\n    for (size_t i = 0; i < a.size(); i++) a[i] ^= r.a[i];\n\
    \    return *this;\n  }\n\n  __attribute__((optimize(\"O3,unroll-loops\"))) int\
    \ _Find_next(size_t i) const {\n    ++i;\n    if (i >= N) return N;\n    size_t\
    \ M = i / 64;\n    u64 buf = a[M];\n    buf &= ~u64(0) << (i % 64);\n    if (buf\
    \ != 0) return M * 64 + __builtin_ctzll(buf);\n    for (; ++M < a.size();) {\n\
    \      if (a[M] != 0) return M * 64 + __builtin_ctzll(a[M]);\n    }\n    return\
    \ N;\n  }\n  int _Find_first() const { return _Find_next(-1); }\n\n  __attribute__((optimize(\"\
    O3,unroll-loops\"))) int _Find_prev(size_t i) const {\n    if (i == 0) return\
    \ -1;\n    if ((*this)[--i] == true) return i;\n    size_t M = i / 64;\n    u64\
    \ buf = a[M];\n    buf &= maskbit(i % 64) - 1;\n    if (buf != 0) return M * 64\
    \ + 63 - __builtin_clzll(buf);\n    while (M--) {\n      if (a[M] != 0) return\
    \ M * 64 + 63 - __builtin_clzll(a[M]);\n    }\n    return -1;\n  }\n  int _Find_last()\
    \ const { return _Find_prev(N); }\n};\n\n/**\n * @brief \u52D5\u7684bitset\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic-bitset.hpp
  requiredBy: []
  timestamp: '2021-07-18 18:42:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-bitset.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-bitset.hpp
- /library/data-structure/dynamic-bitset.hpp.html
title: "\u52D5\u7684bitset"
---
