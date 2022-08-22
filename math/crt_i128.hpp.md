---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/crt_i128.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace atcoder {\n\
    \n// @param m `1 <= m`\n// @return x mod m\ntemplate <typename T>\nconstexpr T\
    \ safe_mod(T x, T m) {\n  x %= m;\n  if (x < 0) x += m;\n  return x;\n}\n\n//\
    \ @param b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b),\
    \ 0 <= x < b/g\ntemplate <typename T>\nconstexpr std::pair<T, T> inv_gcd(T a,\
    \ T b) {\n  a = safe_mod(a, b);\n  if (a == 0) return {b, 0};\n\n  // Contracts:\n\
    \  // [1] s - m0 * a = 0 (mod b)\n  // [2] t - m1 * a = 0 (mod b)\n  // [3] s\
    \ * |m1| + t * |m0| <= b\n  T s = b, t = a;\n  T m0 = 0, m1 = 1;\n\n  while (t)\
    \ {\n    T u = s / t;\n    s -= t * u;\n    m0 -= m1 * u;  // |m1 * u| <= |m1|\
    \ * s <= b\n\n    // [3]:\n    // (s - t * u) * |m1| + t * |m0 - m1 * u|\n   \
    \ // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)\n    // = s * |m1| + t\
    \ * |m0| <= b\n\n    auto tmp = s;\n    s = t;\n    t = tmp;\n    tmp = m0;\n\
    \    m0 = m1;\n    m1 = tmp;\n  }\n  // by [3]: |m0| <= b/g\n  // by g != b: |m0|\
    \ < b/g\n  if (m0 < 0) m0 += b / s;\n  return {s, m0};\n}\n\ntemplate <typename\
    \ T>\nT inv_mod(T x, T m) {\n  assert(1 <= m);\n  auto z = inv_gcd(x, m);\n  assert(z.first\
    \ == 1);\n  return z.second;\n}\n\n// (rem, mod)\ntemplate <typename T>\nstd::pair<T,\
    \ T> crt(const std::vector<T>& r, const std::vector<T>& m) {\n  assert(r.size()\
    \ == m.size());\n  int n = int(r.size());\n  // Contracts: 0 <= r0 < m0\n  T r0\
    \ = 0, m0 = 1;\n  for (int i = 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T\
    \ r1 = safe_mod(r[i], m[i]), m1 = m[i];\n    if (m0 < m1) {\n      std::swap(r0,\
    \ r1);\n      std::swap(m0, m1);\n    }\n    if (m0 % m1 == 0) {\n      if (r0\
    \ % m1 != r1) return {0, 0};\n      continue;\n    }\n    // assume: m0 > m1,\
    \ lcm(m0, m1) >= 2 * max(m0, m1)\n\n    // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0,\
    \ m1));\n    // r2 % m0 = r0\n    // r2 % m1 = r1\n    // -> (r0 + x*m0) % m1\
    \ = r1\n    // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)\n    // ->\
    \ x = (r1 - r0) / g * inv(u0) (mod u1)\n\n    // im = inv(u0) (mod u1) (0 <= im\
    \ < u1)\n    T g, im;\n    std::tie(g, im) = inv_gcd(m0, m1);\n\n    T u1 = (m1\
    \ / g);\n    // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n    if ((r1 - r0) % g) return\
    \ {0, 0};\n\n    // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n\
    \    T x = (r1 - r0) / g % u1 * im % u1;\n\n    // |r0| + |m0 * x|\n    // < m0\
    \ + m0 * (u1 - 1)\n    // = m0 + m0 * m1 / g - m0\n    // = lcm(m0, m1)\n    r0\
    \ += x * m0;\n    m0 *= u1;  // -> lcm(m0, m1)\n    if (r0 < 0) r0 += m0;\n  }\n\
    \  return {r0, m0};\n}\n}  // namespace atcoder\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace atcoder {\n\n// @param m `1\
    \ <= m`\n// @return x mod m\ntemplate <typename T>\nconstexpr T safe_mod(T x,\
    \ T m) {\n  x %= m;\n  if (x < 0) x += m;\n  return x;\n}\n\n// @param b `1 <=\
    \ b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\n\
    template <typename T>\nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\n  a = safe_mod(a,\
    \ b);\n  if (a == 0) return {b, 0};\n\n  // Contracts:\n  // [1] s - m0 * a =\
    \ 0 (mod b)\n  // [2] t - m1 * a = 0 (mod b)\n  // [3] s * |m1| + t * |m0| <=\
    \ b\n  T s = b, t = a;\n  T m0 = 0, m1 = 1;\n\n  while (t) {\n    T u = s / t;\n\
    \    s -= t * u;\n    m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n    // [3]:\n\
    \    // (s - t * u) * |m1| + t * |m0 - m1 * u|\n    // <= s * |m1| - t * u * |m1|\
    \ + t * (|m0| + |m1| * u)\n    // = s * |m1| + t * |m0| <= b\n\n    auto tmp =\
    \ s;\n    s = t;\n    t = tmp;\n    tmp = m0;\n    m0 = m1;\n    m1 = tmp;\n \
    \ }\n  // by [3]: |m0| <= b/g\n  // by g != b: |m0| < b/g\n  if (m0 < 0) m0 +=\
    \ b / s;\n  return {s, m0};\n}\n\ntemplate <typename T>\nT inv_mod(T x, T m) {\n\
    \  assert(1 <= m);\n  auto z = inv_gcd(x, m);\n  assert(z.first == 1);\n  return\
    \ z.second;\n}\n\n// (rem, mod)\ntemplate <typename T>\nstd::pair<T, T> crt(const\
    \ std::vector<T>& r, const std::vector<T>& m) {\n  assert(r.size() == m.size());\n\
    \  int n = int(r.size());\n  // Contracts: 0 <= r0 < m0\n  T r0 = 0, m0 = 1;\n\
    \  for (int i = 0; i < n; i++) {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n    if (m0 < m1) {\n      std::swap(r0, r1);\n      std::swap(m0,\
    \ m1);\n    }\n    if (m0 % m1 == 0) {\n      if (r0 % m1 != r1) return {0, 0};\n\
    \      continue;\n    }\n    // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\
    \n    // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n    // r2 % m0 = r0\n\
    \    // r2 % m1 = r1\n    // -> (r0 + x*m0) % m1 = r1\n    // -> x*u0*g % (u1*g)\
    \ = (r1 - r0) (u0*g = m0, u1*g = m1)\n    // -> x = (r1 - r0) / g * inv(u0) (mod\
    \ u1)\n\n    // im = inv(u0) (mod u1) (0 <= im < u1)\n    T g, im;\n    std::tie(g,\
    \ im) = inv_gcd(m0, m1);\n\n    T u1 = (m1 / g);\n    // |r1 - r0| < (m0 + m1)\
    \ <= lcm(m0, m1)\n    if ((r1 - r0) % g) return {0, 0};\n\n    // u1 * u1 <= m1\
    \ * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n    T x = (r1 - r0) / g % u1 * im\
    \ % u1;\n\n    // |r0| + |m0 * x|\n    // < m0 + m0 * (u1 - 1)\n    // = m0 +\
    \ m0 * m1 / g - m0\n    // = lcm(m0, m1)\n    r0 += x * m0;\n    m0 *= u1;  //\
    \ -> lcm(m0, m1)\n    if (r0 < 0) r0 += m0;\n  }\n  return {r0, m0};\n}\n}  //\
    \ namespace atcoder"
  dependsOn: []
  isVerificationFile: false
  path: math/crt_i128.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:21:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt_i128.hpp
layout: document
redirect_from:
- /library/math/crt_i128.hpp
- /library/math/crt_i128.hpp.html
title: math/crt_i128.hpp
---
