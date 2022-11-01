---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/garner.hpp
    title: Garner's algorithm
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/nimber-to-field.hpp
    title: "Nimber <-> \u591A\u9805\u5F0F\u74B0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/karatsuba.test.cpp
    title: verify/verify-unit-test/karatsuba.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/nimber-to-field.test.cpp
    title: verify/verify-unit-test/nimber-to-field.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/nimber.test.cpp
    title: verify/verify-unit-test/nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
    title: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1775.test.cpp
    title: verify/verify-yuki/yuki-1775.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/nimber.md
    document_title: Nim Product
    links: []
  bundledCode: "#line 2 \"math/nimber.hpp\"\n\n#line 2 \"math/garner.hpp\"\n\n// input\
    \  : a, M (0 < a < M)\n// output : pair(g, x) s.t. g = gcd(a, M), xa = g (mod\
    \ M), 0 <= x < b/g\ntemplate <typename uint>\npair<uint, uint> gcd_inv(uint a,\
    \ uint M) {\n  assert(M != 0 && 0 < a);\n  a %= M;\n  uint b = M, s = 1, t = 0;\n\
    \  while (true) {\n    if (a == 0) return {b, t + M};\n    t -= b / a * s;\n \
    \   b %= a;\n    if (b == 0) return {a, s};\n    s -= a / b * t;\n    a %= b;\n\
    \  }\n}\n\n// \u5165\u529B : 0 <= rem[i] < mod[i], 1 <= mod[i]\n// \u5B58\u5728\
    \u3059\u308B\u3068\u304D   : return {rem, mod}\n// \u5B58\u5728\u3057\u306A\u3044\
    \u3068\u304D : return {0, 0}\ntemplate <typename T, typename U>\npair<unsigned\
    \ long long, unsigned long long> garner(const vector<T>& rem,\n              \
    \                                      const vector<U>& mod) {\n  assert(rem.size()\
    \ == mod.size());\n  using u64 = unsigned long long;\n  u64 r0 = 0, m0 = 1;\n\
    \  for (int i = 0; i < (int)rem.size(); i++) {\n    assert(1 <= mod[i]);\n   \
    \ assert(0 <= rem[i] && rem[i] < mod[i]);\n    u64 m1 = mod[i], r1 = rem[i] %\
    \ m1;\n    if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0) {\n\
    \      if (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    u64 g, im;\n\
    \    tie(g, im) = gcd_inv(m0, m1);\n    u64 y = r0 < r1 ? r1 - r0 : r0 - r1;\n\
    \    if (y % g != 0) return {0, 0};\n    u64 u1 = m1 / g;\n    y = y / g % u1;\n\
    \    if (r0 > r1 && y != 0) y = u1 - y;\n    u64 x = y * im % u1;\n    r0 += x\
    \ * m0;\n    m0 *= u1;\n  }\n  return {r0, m0};\n}\n\n/**\n * @brief Garner's\
    \ algorithm\n */\n#line 4 \"math/nimber.hpp\"\n\nnamespace NimberImpl {\nusing\
    \ u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\nstruct calc8\
    \ {\n  u16 dp[1 << 8][1 << 8];\n  constexpr calc8() : dp() {\n    dp[0][0] = dp[0][1]\
    \ = dp[1][0] = 0;\n    dp[1][1] = 1;\n    for (int e = 1; e <= 3; e++) {\n   \
    \   int p = 1 << e, q = p >> 1;\n      u16 ep = 1u << p, eq = 1u << q;\n     \
    \ for (u16 i = 0; i < ep; i++) {\n        for (u16 j = i; j < ep; j++) {\n   \
    \       if (i < eq && j < eq) continue;\n          if (min(i, j) <= 1u) {\n  \
    \          dp[i][j] = dp[j][i] = i * j;\n            continue;\n          }\n\
    \          u16 iu = i >> q, il = i & (eq - 1);\n          u16 ju = j >> q, jl\
    \ = j & (eq - 1);\n          u16 u = dp[iu][ju], l = dp[il][jl];\n          u16\
    \ ul = dp[iu ^ il][ju ^ jl];\n          u16 uq = dp[u][eq >> 1];\n          dp[i][j]\
    \ = ((ul ^ l) << q) ^ uq ^ l;\n          dp[j][i] = dp[i][j];\n        }\n   \
    \   }\n    }\n  }\n} constexpr c8;\n\nstruct calc16 {\n  static constexpr u16\
    \ proot = 10279;\n  static constexpr u32 ppoly = 92191;\n  static constexpr int\
    \ order = 65535;\n\n  u16 base[16], exp[(1 << 18) + 100];\n  int log[1 << 16];\n\
    \n private:\n  constexpr u16 d(u32 x) { return (x << 1) ^ (x < 32768u ? 0 : ppoly);\
    \ }\n\n  constexpr u16 naive(u16 i, u16 j) {\n    if (min(i, j) <= 1u) return\
    \ i * j;\n    u16 q = 8, eq = 1u << 8;\n    u16 iu = i >> q, il = i & (eq - 1);\n\
    \    u16 ju = j >> q, jl = j & (eq - 1);\n    u16 u = c8.dp[iu][ju];\n    u16\
    \ l = c8.dp[il][jl];\n    u16 ul = c8.dp[iu ^ il][ju ^ jl];\n    u16 uq = c8.dp[u][eq\
    \ >> 1];\n    return ((ul ^ l) << q) ^ uq ^ l;\n  }\n\n public:\n  constexpr calc16()\
    \ : base(), exp(), log() {\n    base[0] = 1;\n    for (int i = 1; i < 16; i++)\
    \ base[i] = naive(base[i - 1], proot);\n    exp[0] = 1;\n    for (int i = 1; i\
    \ < order; i++) exp[i] = d(exp[i - 1]);\n    u16* pre = exp + order + 1;\n   \
    \ pre[0] = 0;\n    for (int b = 0; b < 16; b++) {\n      int is = 1 << b, ie =\
    \ is << 1;\n      for (int i = is; i < ie; i++) pre[i] = pre[i - is] ^ base[b];\n\
    \    }\n    for (int i = 0; i < order; i++) exp[i] = pre[exp[i]], log[exp[i]]\
    \ = i;\n\n    int ie = 2 * order + 30;\n    for (int i = order; i < ie; i++) exp[i]\
    \ = exp[i - order];\n    for (unsigned int i = ie; i < sizeof(exp) / sizeof(u16);\
    \ i++) exp[i] = 0;\n    log[0] = ie + 1;\n  }\n\n  constexpr u16 prod(u16 i, u16\
    \ j) const { return exp[log[i] + log[j]]; }\n\n  // exp[3] = 2^{15} = 32768\n\
    \  constexpr u16 Hprod(u16 i, u16 j) const { return exp[log[i] + log[j] + 3];\
    \ }\n  constexpr u16 H(u16 i) const { return exp[log[i] + 3]; }\n  constexpr u16\
    \ H2(u16 i) const { return exp[log[i] + 6]; }\n} constexpr c16;\n\nu16 product16(u16\
    \ i, u16 j) { return c16.prod(i, j); }\n\nconstexpr u32 product32(u32 i, u32 j)\
    \ {\n  u16 iu = i >> 16, il = i & 65535;\n  u16 ju = j >> 16, jl = j & 65535;\n\
    \  u16 l = c16.prod(il, jl);\n  u16 ul = c16.prod(iu ^ il, ju ^ jl);\n  u16 uq\
    \ = c16.Hprod(iu, ju);\n  return (u32(ul ^ l) << 16) ^ uq ^ l;\n}\n\n// (+ : xor,\
    \ x : nim product, * : integer product)\n// i x j\n// = (iu x ju + il x ju + iu\
    \ x ji) * 2^{16}\n// + (iu x ju x 2^{15}) + il x jl\n// (assign ju = 2^{15}, jl\
    \ = 0)\n// = ((iu + il) x 2^{15}) * 2^{16} + (iu x 2^{15} x 2^{15})\nconstexpr\
    \ u32 H(u32 i) {\n  u16 iu = i >> 16;\n  u16 il = i & 65535;\n  return (u32(c16.H(iu\
    \ ^ il)) << 16) ^ c16.H2(iu);\n}\n\nconstexpr u64 product64(u64 i, u64 j) {\n\
    \  u32 iu = i >> 32, il = i & u32(-1);\n  u32 ju = j >> 32, jl = j & u32(-1);\n\
    \  u32 l = product32(il, jl);\n  u32 ul = product32(iu ^ il, ju ^ jl);\n  u32\
    \ uq = H(product32(iu, ju));\n  return (u64(ul ^ l) << 32) ^ uq ^ l;\n}\n}  //\
    \ namespace NimberImpl\n\ntemplate <typename uint, uint (*prod)(uint, uint)>\n\
    struct NimberBase {\n  using N = NimberBase;\n  uint x;\n  NimberBase() : x(0)\
    \ {}\n  NimberBase(uint _x) : x(_x) {}\n  static N id0() { return {}; }\n  static\
    \ N id1() { return {1}; }\n\n  N& operator+=(const N& p) {\n    x ^= p.x;\n  \
    \  return *this;\n  }\n  N& operator-=(const N& p) {\n    x ^= p.x;\n    return\
    \ *this;\n  }\n  N& operator*=(const N& p) {\n    x = prod(x, p.x);\n    return\
    \ *this;\n  }\n  N operator+(const N& p) const { return x ^ p.x; }\n  N operator-(const\
    \ N& p) const { return x ^ p.x; }\n  N operator*(const N& p) const { return prod(x,\
    \ p.x); }\n  bool operator==(const N& p) const { return x == p.x; }\n  bool operator!=(const\
    \ N& p) const { return x != p.x; }\n  N pow(uint64_t n) const {\n    N a = *this,\
    \ r = 1;\n    for (; n; a *= a, n >>= 1)\n      if (n & 1) r *= a;\n    return\
    \ r;\n  }\n  friend ostream& operator<<(ostream& os, const N& p) { return os <<\
    \ p.x; }\n\n  // calculate log_a (b)\n  uint discrete_logarithm(N y) const {\n\
    \    assert(x != 0 && y != 0);\n    vector<uint> rem, mod;\n    for (uint p :\
    \ {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p) continue;\n\
    \      uint q = uint(-1) / p;\n      uint STEP = 1;\n      while (4 * STEP * STEP\
    \ < p) STEP *= 2;\n      // a^m = z \u3092\u6E80\u305F\u3059 1 \u4EE5\u4E0A\u306E\
    \u6574\u6570 m \u3092\u8FD4\u3059\n      auto inside = [&](N a, N z) -> uint {\n\
    \        unordered_map<uint, int> mp;\n        N big = 1, now = 1;  // x^m\n \
    \       for (int i = 0; i < int(STEP); i++) {\n          mp[z.x] = i, z *= a,\
    \ big *= a;\n        }\n        for (int step = 0; step < int(p + 10); step +=\
    \ STEP) {\n          now *= big;\n          if (mp.find(now.x) != mp.end()) return\
    \ (step + STEP) - mp[now.x];\n        }\n        return uint(-1);\n      };\n\
    \      N xq = (*this).pow(q), yq = y.pow(q);\n      if (xq == 1 and yq == 1) continue;\n\
    \      if (xq == 1 and yq != 1) return uint(-1);\n      uint res = inside(xq,\
    \ yq);\n      if (res == uint(-1)) return uint(-1);\n      rem.push_back(res %\
    \ p);\n      mod.push_back(p);\n    }\n    return garner(rem, mod).first;\n  }\n\
    \n  uint is_primitive_root() const {\n    if (x == 0) return false;\n    for (uint\
    \ p : {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p != 0) continue;\n\
    \      if ((*this).pow(uint(-1) / p) == 1) return false;\n    }\n    return true;\n\
    \  }\n};\n\nusing Nimber16 = NimberBase<uint16_t, NimberImpl::product16>;\nusing\
    \ Nimber32 = NimberBase<uint32_t, NimberImpl::product32>;\nusing Nimber64 = NimberBase<uint64_t,\
    \ NimberImpl::product64>;\nusing Nimber = Nimber64;\n\n/**\n * @brief Nim Product\n\
    \ * @docs docs/math/nimber.md\n */\n"
  code: "#pragma once\n\n#include \"garner.hpp\"\n\nnamespace NimberImpl {\nusing\
    \ u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\nstruct calc8\
    \ {\n  u16 dp[1 << 8][1 << 8];\n  constexpr calc8() : dp() {\n    dp[0][0] = dp[0][1]\
    \ = dp[1][0] = 0;\n    dp[1][1] = 1;\n    for (int e = 1; e <= 3; e++) {\n   \
    \   int p = 1 << e, q = p >> 1;\n      u16 ep = 1u << p, eq = 1u << q;\n     \
    \ for (u16 i = 0; i < ep; i++) {\n        for (u16 j = i; j < ep; j++) {\n   \
    \       if (i < eq && j < eq) continue;\n          if (min(i, j) <= 1u) {\n  \
    \          dp[i][j] = dp[j][i] = i * j;\n            continue;\n          }\n\
    \          u16 iu = i >> q, il = i & (eq - 1);\n          u16 ju = j >> q, jl\
    \ = j & (eq - 1);\n          u16 u = dp[iu][ju], l = dp[il][jl];\n          u16\
    \ ul = dp[iu ^ il][ju ^ jl];\n          u16 uq = dp[u][eq >> 1];\n          dp[i][j]\
    \ = ((ul ^ l) << q) ^ uq ^ l;\n          dp[j][i] = dp[i][j];\n        }\n   \
    \   }\n    }\n  }\n} constexpr c8;\n\nstruct calc16 {\n  static constexpr u16\
    \ proot = 10279;\n  static constexpr u32 ppoly = 92191;\n  static constexpr int\
    \ order = 65535;\n\n  u16 base[16], exp[(1 << 18) + 100];\n  int log[1 << 16];\n\
    \n private:\n  constexpr u16 d(u32 x) { return (x << 1) ^ (x < 32768u ? 0 : ppoly);\
    \ }\n\n  constexpr u16 naive(u16 i, u16 j) {\n    if (min(i, j) <= 1u) return\
    \ i * j;\n    u16 q = 8, eq = 1u << 8;\n    u16 iu = i >> q, il = i & (eq - 1);\n\
    \    u16 ju = j >> q, jl = j & (eq - 1);\n    u16 u = c8.dp[iu][ju];\n    u16\
    \ l = c8.dp[il][jl];\n    u16 ul = c8.dp[iu ^ il][ju ^ jl];\n    u16 uq = c8.dp[u][eq\
    \ >> 1];\n    return ((ul ^ l) << q) ^ uq ^ l;\n  }\n\n public:\n  constexpr calc16()\
    \ : base(), exp(), log() {\n    base[0] = 1;\n    for (int i = 1; i < 16; i++)\
    \ base[i] = naive(base[i - 1], proot);\n    exp[0] = 1;\n    for (int i = 1; i\
    \ < order; i++) exp[i] = d(exp[i - 1]);\n    u16* pre = exp + order + 1;\n   \
    \ pre[0] = 0;\n    for (int b = 0; b < 16; b++) {\n      int is = 1 << b, ie =\
    \ is << 1;\n      for (int i = is; i < ie; i++) pre[i] = pre[i - is] ^ base[b];\n\
    \    }\n    for (int i = 0; i < order; i++) exp[i] = pre[exp[i]], log[exp[i]]\
    \ = i;\n\n    int ie = 2 * order + 30;\n    for (int i = order; i < ie; i++) exp[i]\
    \ = exp[i - order];\n    for (unsigned int i = ie; i < sizeof(exp) / sizeof(u16);\
    \ i++) exp[i] = 0;\n    log[0] = ie + 1;\n  }\n\n  constexpr u16 prod(u16 i, u16\
    \ j) const { return exp[log[i] + log[j]]; }\n\n  // exp[3] = 2^{15} = 32768\n\
    \  constexpr u16 Hprod(u16 i, u16 j) const { return exp[log[i] + log[j] + 3];\
    \ }\n  constexpr u16 H(u16 i) const { return exp[log[i] + 3]; }\n  constexpr u16\
    \ H2(u16 i) const { return exp[log[i] + 6]; }\n} constexpr c16;\n\nu16 product16(u16\
    \ i, u16 j) { return c16.prod(i, j); }\n\nconstexpr u32 product32(u32 i, u32 j)\
    \ {\n  u16 iu = i >> 16, il = i & 65535;\n  u16 ju = j >> 16, jl = j & 65535;\n\
    \  u16 l = c16.prod(il, jl);\n  u16 ul = c16.prod(iu ^ il, ju ^ jl);\n  u16 uq\
    \ = c16.Hprod(iu, ju);\n  return (u32(ul ^ l) << 16) ^ uq ^ l;\n}\n\n// (+ : xor,\
    \ x : nim product, * : integer product)\n// i x j\n// = (iu x ju + il x ju + iu\
    \ x ji) * 2^{16}\n// + (iu x ju x 2^{15}) + il x jl\n// (assign ju = 2^{15}, jl\
    \ = 0)\n// = ((iu + il) x 2^{15}) * 2^{16} + (iu x 2^{15} x 2^{15})\nconstexpr\
    \ u32 H(u32 i) {\n  u16 iu = i >> 16;\n  u16 il = i & 65535;\n  return (u32(c16.H(iu\
    \ ^ il)) << 16) ^ c16.H2(iu);\n}\n\nconstexpr u64 product64(u64 i, u64 j) {\n\
    \  u32 iu = i >> 32, il = i & u32(-1);\n  u32 ju = j >> 32, jl = j & u32(-1);\n\
    \  u32 l = product32(il, jl);\n  u32 ul = product32(iu ^ il, ju ^ jl);\n  u32\
    \ uq = H(product32(iu, ju));\n  return (u64(ul ^ l) << 32) ^ uq ^ l;\n}\n}  //\
    \ namespace NimberImpl\n\ntemplate <typename uint, uint (*prod)(uint, uint)>\n\
    struct NimberBase {\n  using N = NimberBase;\n  uint x;\n  NimberBase() : x(0)\
    \ {}\n  NimberBase(uint _x) : x(_x) {}\n  static N id0() { return {}; }\n  static\
    \ N id1() { return {1}; }\n\n  N& operator+=(const N& p) {\n    x ^= p.x;\n  \
    \  return *this;\n  }\n  N& operator-=(const N& p) {\n    x ^= p.x;\n    return\
    \ *this;\n  }\n  N& operator*=(const N& p) {\n    x = prod(x, p.x);\n    return\
    \ *this;\n  }\n  N operator+(const N& p) const { return x ^ p.x; }\n  N operator-(const\
    \ N& p) const { return x ^ p.x; }\n  N operator*(const N& p) const { return prod(x,\
    \ p.x); }\n  bool operator==(const N& p) const { return x == p.x; }\n  bool operator!=(const\
    \ N& p) const { return x != p.x; }\n  N pow(uint64_t n) const {\n    N a = *this,\
    \ r = 1;\n    for (; n; a *= a, n >>= 1)\n      if (n & 1) r *= a;\n    return\
    \ r;\n  }\n  friend ostream& operator<<(ostream& os, const N& p) { return os <<\
    \ p.x; }\n\n  // calculate log_a (b)\n  uint discrete_logarithm(N y) const {\n\
    \    assert(x != 0 && y != 0);\n    vector<uint> rem, mod;\n    for (uint p :\
    \ {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p) continue;\n\
    \      uint q = uint(-1) / p;\n      uint STEP = 1;\n      while (4 * STEP * STEP\
    \ < p) STEP *= 2;\n      // a^m = z \u3092\u6E80\u305F\u3059 1 \u4EE5\u4E0A\u306E\
    \u6574\u6570 m \u3092\u8FD4\u3059\n      auto inside = [&](N a, N z) -> uint {\n\
    \        unordered_map<uint, int> mp;\n        N big = 1, now = 1;  // x^m\n \
    \       for (int i = 0; i < int(STEP); i++) {\n          mp[z.x] = i, z *= a,\
    \ big *= a;\n        }\n        for (int step = 0; step < int(p + 10); step +=\
    \ STEP) {\n          now *= big;\n          if (mp.find(now.x) != mp.end()) return\
    \ (step + STEP) - mp[now.x];\n        }\n        return uint(-1);\n      };\n\
    \      N xq = (*this).pow(q), yq = y.pow(q);\n      if (xq == 1 and yq == 1) continue;\n\
    \      if (xq == 1 and yq != 1) return uint(-1);\n      uint res = inside(xq,\
    \ yq);\n      if (res == uint(-1)) return uint(-1);\n      rem.push_back(res %\
    \ p);\n      mod.push_back(p);\n    }\n    return garner(rem, mod).first;\n  }\n\
    \n  uint is_primitive_root() const {\n    if (x == 0) return false;\n    for (uint\
    \ p : {3, 5, 17, 257, 641, 65537, 6700417}) {\n      if (uint(-1) % p != 0) continue;\n\
    \      if ((*this).pow(uint(-1) / p) == 1) return false;\n    }\n    return true;\n\
    \  }\n};\n\nusing Nimber16 = NimberBase<uint16_t, NimberImpl::product16>;\nusing\
    \ Nimber32 = NimberBase<uint32_t, NimberImpl::product32>;\nusing Nimber64 = NimberBase<uint64_t,\
    \ NimberImpl::product64>;\nusing Nimber = Nimber64;\n\n/**\n * @brief Nim Product\n\
    \ * @docs docs/math/nimber.md\n */\n"
  dependsOn:
  - math/garner.hpp
  isVerificationFile: false
  path: math/nimber.hpp
  requiredBy:
  - math/nimber-to-field.hpp
  timestamp: '2021-12-23 23:20:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1775.test.cpp
  - verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  - verify/verify-unit-test/nimber-to-field.test.cpp
  - verify/verify-unit-test/karatsuba.test.cpp
  - verify/verify-unit-test/nimber.test.cpp
documentation_of: math/nimber.hpp
layout: document
redirect_from:
- /library/math/nimber.hpp
- /library/math/nimber.hpp.html
title: Nim Product
---
## Nim Product

$$a \oplus b =\mathrm{mex}(\lbrace a' \oplus b \mid a'<a \rbrace\cup\lbrace a \oplus b' \mid b'<b \rbrace)$$

$$a \otimes b =\mathrm{mex}(\lbrace a' \otimes b \oplus a \otimes b' \oplus a' \otimes b' \mid a'<a,b'<b \rbrace)$$

と置いたとき、$a\otimes b\ (a,b<2^{64})$を高速に計算するライブラリ。

[Wikipedia](https://en.wikipedia.org/wiki/Nimber) [kyopro_friendsさんによる資料](https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit)
