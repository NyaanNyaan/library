---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
    title: verify/verify-yosupo-math/yosupo-nim-product.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/nim-product.md
    document_title: Nim Product
    links: []
  bundledCode: "#line 2 \"math/nim-product.hpp\"\n\n\n\nnamespace nimber {\nusing\
    \ u64 = uint64_t;\n\nu64 calc(u64, u64, int p, int pre);\n\nstruct Precalc {\n\
    \  u64 dp[256][256];\n  Precalc() {\n    for (int i = 0; i < 256; i++)\n     \
    \ for (int j = 0; j <= i; j++) {\n        dp[i][j] = dp[j][i] = calc(i, j, 8,\
    \ true);\n      }\n  }\n\n} precalc;\n\nu64 calc(u64 a, u64 b, int p = 64, int\
    \ pre = false) {\n  if (min(a, b) <= 1) return a * b;\n  while (max(a, b) < 1ull\
    \ << (p >> 1)) p >>= 1;\n  if (!pre && p <= 8) return precalc.dp[a][b];\n  p >>=\
    \ 1;\n  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);\n  u64 b1 = b >> p, b2 =\
    \ b & ((1ull << p) - 1);\n  u64 c = calc(a1, b1, p, pre);\n  u64 d = calc(a2,\
    \ b2, p, pre);\n  u64 e = calc(a1 ^ a2, b1 ^ b2, p, pre);\n  return calc(c, 1ull\
    \ << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);\n}\n\nu64 nim_product(u64 a, u64 b)\
    \ { return calc(a, b); }\n\n}  // namespace nimber\nusing nimber::nim_product;\n\
    \n/**\n * @brief Nim Product\n * @docs docs/math/nim-product.md\n */\n"
  code: "#pragma once\n\n\n\nnamespace nimber {\nusing u64 = uint64_t;\n\nu64 calc(u64,\
    \ u64, int p, int pre);\n\nstruct Precalc {\n  u64 dp[256][256];\n  Precalc()\
    \ {\n    for (int i = 0; i < 256; i++)\n      for (int j = 0; j <= i; j++) {\n\
    \        dp[i][j] = dp[j][i] = calc(i, j, 8, true);\n      }\n  }\n\n} precalc;\n\
    \nu64 calc(u64 a, u64 b, int p = 64, int pre = false) {\n  if (min(a, b) <= 1)\
    \ return a * b;\n  while (max(a, b) < 1ull << (p >> 1)) p >>= 1;\n  if (!pre &&\
    \ p <= 8) return precalc.dp[a][b];\n  p >>= 1;\n  u64 a1 = a >> p, a2 = a & ((1ull\
    \ << p) - 1);\n  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);\n  u64 c = calc(a1,\
    \ b1, p, pre);\n  u64 d = calc(a2, b2, p, pre);\n  u64 e = calc(a1 ^ a2, b1 ^\
    \ b2, p, pre);\n  return calc(c, 1ull << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);\n\
    }\n\nu64 nim_product(u64 a, u64 b) { return calc(a, b); }\n\n}  // namespace nimber\n\
    using nimber::nim_product;\n\n/**\n * @brief Nim Product\n * @docs docs/math/nim-product.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/nim-product.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-nim-product.test.cpp
documentation_of: math/nim-product.hpp
layout: document
redirect_from:
- /library/math/nim-product.hpp
- /library/math/nim-product.hpp.html
title: Nim Product
---
## Nim Product

$$a \oplus b =\mathrm{mex}(\lbrace a' \oplus b \mid a'<a \rbrace\cup\lbrace a \oplus b' \mid b'<b \rbrace)$$

$$a \otimes b =\mathrm{mex}(\lbrace a' \otimes b \oplus a \otimes b' \oplus a' \otimes b' \mid a'<a,b'<b \rbrace)$$

と置いたとき、$a\otimes b\ (a,b<2^{64})$を高速に計算するライブラリ。

[Wikipedia](https://en.wikipedia.org/wiki/Nimber)　[kyopro_friendsさんによる資料](https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit)

#### 使い方

- `nim_product(a, b)` ： $a\otimes b$を返す関数。
