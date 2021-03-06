---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  - icon: ':question:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/mod-log.hpp\"\n\n\n\n#line 2 \"data-structure/hash-map-variable-length.hpp\"\
    \n\ntemplate <typename Key, typename Val>\nstruct HashMap {\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n  u32 cap, s;\n  vector<Key> keys;\n  vector<Val>\
    \ vals;\n  vector<bool> flag;\n  u64 r;\n  u32 shift;\n  Val DefaultValue;\n\n\
    \  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    vector<Key> k(cap);\n    vector<Val>\
    \ v(cap);\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n    for (int i =\
    \ 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n        u32 hash = (u64(keys[i])\
    \ * r) >> sh;\n        while (f[hash]) hash = (hash + 1) & (cap - 1);\n      \
    \  k[hash] = keys[i];\n        v[hash] = vals[i];\n        f[hash] = 1;\n    \
    \  }\n    }\n    keys.swap(k);\n    vals.swap(v);\n    flag.swap(f);\n    --shift;\n\
    \  }\n\n  explicit HashMap()\n      : cap(8),\n        s(0),\n        keys(cap),\n\
    \        vals(cap),\n        flag(cap),\n        r(rng()),\n        shift(64 -\
    \ __lg(cap)),\n        DefaultValue(Val()) {}\n\n  Val& operator[](const Key&\
    \ i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n      if (!flag[hash])\
    \ {\n        if (s + s / 4 >= cap) {\n          reallocate();\n          return\
    \ (*this)[i];\n        }\n        keys[hash] = i;\n        flag[hash] = 1;\n \
    \       ++s;\n        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash]\
    \ == i) return vals[hash];\n      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\
    \n  // exist -> return pointer of Val\n  // not exist -> return nullptr\n  const\
    \ Val* find(const Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n   \
    \ while (true) {\n      if (!flag[hash]) return nullptr;\n      if (keys[hash]\
    \ == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap - 1);\n    }\n \
    \ }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<Key, Val>>\
    \ enumerate() const {\n    vector<pair<Key, Val>> ret;\n    for (u32 i = 0; i\
    \ < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i], vals[i]);\n    return\
    \ ret;\n  }\n\n  int size() const { return s; }\n\n  // set default_value\n  void\
    \ set_default(const Val& val) { DefaultValue = val; }\n};\n\n/**\n * @brief Hash\
    \ Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n */\n\
    #line 2 \"inner/inner_math.hpp\"\n\nnamespace inner {\n\nusing i32 = int32_t;\n\
    using u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\ntemplate\
    \ <typename T>\nT gcd(T a, T b) {\n  while (b) swap(a %= b, b);\n  return a;\n\
    }\n\ntemplate <typename T>\nT inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n  while\
    \ (a) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n\
    \  assert(b == 1);\n  return y < 0 ? y + p : y;\n}\n\ntemplate <typename T, typename\
    \ U>\nT modpow(T a, U n, T p) {\n  T ret = 1 % p;\n  for (; n; n >>= 1, a = U(a)\
    \ * a % p)\n    if (n & 1) ret = U(ret) * a % p;\n  return ret;\n}\n\n}  // namespace\
    \ inner\n#line 7 \"modulo/mod-log.hpp\"\n\nint64_t mod_log(int64_t a, int64_t\
    \ b, int64_t p) {\n  using namespace inner;\n  if ((a %= p) < 0) a += p;\n  if\
    \ ((b %= p) < 0) b += p;\n  int64_t f, g, r = 1 % p;\n  for (f = 0; (g = gcd(a,\
    \ p)) > 1; ++f) {\n    if (b % g) return (r == b) ? f : -1;\n    b /= g;\n   \
    \ p /= g;\n    (r *= (a / g)) %= p;\n  }\n  if (p == 1) return f;\n  int64_t ir\
    \ = inv(r, p);\n  (b *= ir) %= p;\n  int64_t k = 0, ak = 1;\n  HashMap<int64_t,\
    \ int64_t> baby;\n  for (; k * k < p; ++k) {\n    if(!baby.find(ak)) baby[ak]\
    \ = k;\n    (ak *= a) %= p;\n  }\n  int64_t iak = inv(ak, p);\n  for (int64_t\
    \ i = 0; i < k; ++i) {\n    if (baby.find(b)) return f + i * k + baby[b];\n  \
    \  (b *= iak) %= p;\n  }\n  return -1;\n}\n"
  code: "#pragma once\n\n\n\n#include \"../data-structure/hash-map-variable-length.hpp\"\
    \n#include \"../inner/inner_math.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b,\
    \ int64_t p) {\n  using namespace inner;\n  if ((a %= p) < 0) a += p;\n  if ((b\
    \ %= p) < 0) b += p;\n  int64_t f, g, r = 1 % p;\n  for (f = 0; (g = gcd(a, p))\
    \ > 1; ++f) {\n    if (b % g) return (r == b) ? f : -1;\n    b /= g;\n    p /=\
    \ g;\n    (r *= (a / g)) %= p;\n  }\n  if (p == 1) return f;\n  int64_t ir = inv(r,\
    \ p);\n  (b *= ir) %= p;\n  int64_t k = 0, ak = 1;\n  HashMap<int64_t, int64_t>\
    \ baby;\n  for (; k * k < p; ++k) {\n    if(!baby.find(ak)) baby[ak] = k;\n  \
    \  (ak *= a) %= p;\n  }\n  int64_t iak = inv(ak, p);\n  for (int64_t i = 0; i\
    \ < k; ++i) {\n    if (baby.find(b)) return f + i * k + baby[b];\n    (b *= iak)\
    \ %= p;\n  }\n  return -1;\n}"
  dependsOn:
  - data-structure/hash-map-variable-length.hpp
  - inner/inner_math.hpp
  isVerificationFile: false
  path: modulo/mod-log.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: modulo/mod-log.hpp
layout: document
redirect_from:
- /library/modulo/mod-log.hpp
- /library/modulo/mod-log.hpp.html
title: modulo/mod-log.hpp
---
