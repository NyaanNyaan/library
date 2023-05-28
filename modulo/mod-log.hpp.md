---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: internal/internal-math.hpp
    title: internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/mod-log.hpp\"\n\n#line 2 \"hashmap/hashmap.hpp\"\n\
    \n#line 2 \"hashmap/hashmap-base.hpp\"\n\n#include <cstdint>\nusing namespace\
    \ std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename\
    \ Key, typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&> {\n  using base =\n      iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&>;\n  using ptr = typename base::pointer;\n  using\
    \ ref = typename base::reference;\n\n  u32 i;\n  HashMapBase<Key, Data>* p;\n\n\
    \  explicit constexpr itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32\
    \ _i, HashMapBase<Key, Data>* _p) : i(_i), p(_p) {}\n  explicit constexpr itrB(u32\
    \ _i, const HashMapBase<Key, Data>* _p)\n      : i(_i), p(const_cast<HashMapBase<Key,\
    \ Data>*>(_p)) {}\n  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p,\
    \ r.p); }\n  friend bool operator==(const itrB& l, const itrB& r) { return l.i\
    \ == r.i; }\n  friend bool operator!=(const itrB& l, const itrB& r) { return l.i\
    \ != r.i; }\n  const ref operator*() const {\n    return const_cast<const HashMapBase<Key,\
    \ Data>*>(p)->data[i];\n  }\n  ref operator*() { return p->data[i]; }\n  ptr operator->()\
    \ const { return &(p->data[i]); }\n\n  itrB& operator++() {\n    assert(i != p->cap\
    \ && \"itr::operator++()\");\n    do {\n      i++;\n      if (i == p->cap) break;\n\
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n      assert(i\
    \ != 0 && \"itr::operator--()\");\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator--(int) {\n    itrB it(*this);\n    --(*this);\n    return\
    \ it;\n  }\n};\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase {\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  using iterator = itrB<Key,\
    \ Data>;\n  using itr = iterator;\n\n protected:\n  template <typename K>\n  inline\
    \ u64 randomized(const K& key) const {\n    return u64(key) ^ r;\n  }\n\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n  inline\
    \ u32 inner_hash(const K& key) const {\n    return (randomized(key) * 11995408973635179863ULL)\
    \ >> shift;\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    u64\
    \ a = randomized(key.first), b = randomized(key.second);\n    a *= 11995408973635179863ULL;\n\
    \    b *= 10150724397891781847ULL;\n    return (a + b) >> shift;\n  }\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<typename K::value_type>::value, nullptr_t>\
    \ =\n                nullptr>\n  inline u32 inner_hash(const K& key) const {\n\
    \    static constexpr u64 mod = (1LL << 61) - 1;\n    static constexpr u64 base\
    \ = 950699498548472943ULL;\n    u64 res = 0;\n    for (auto& elem : key) {\n \
    \     __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);\n  \
    \    res = (x & mod) + (x >> 61);\n    }\n    __uint128_t x = __uint128_t(res)\
    \ * base;\n    res = (x & mod) + (x >> 61);\n    if (res >= mod) res -= mod;\n\
    \    return res >> (shift - 3);\n  }\n\n  template <typename D = Data,\n     \
    \       enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline u32\
    \ hash(const D& dat) const {\n    return inner_hash(dat);\n  }\n  template <\n\
    \      typename D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat.first);\n\
    \  }\n\n  template <typename D = Data,\n            enable_if_t<is_same<D, Key>::value,\
    \ nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const {\n    return\
    \ dat;\n  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const\
    \ {\n    return dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data>\
    \ ndata(ncap);\n    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n   \
    \ for (u32 i = 0; i < cap; i++) {\n      if (occupied_flag[i] && !deleted_flag[i])\
    \ {\n        u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap\
    \ - 1);\n        ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n \
    \   }\n    data.swap(ndata);\n    occupied_flag.swap(nf);\n    cap = ncap;\n \
    \   occupied = s;\n    deleted_flag.resize(cap);\n    fill(std::begin(deleted_flag),\
    \ std::end(deleted_flag), false);\n  }\n\n  inline bool extend_rate(u32 x) const\
    \ { return x * 2 >= cap; }\n\n  inline bool shrink_rate(u32 x) const {\n    return\
    \ HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;\n  }\n\n  inline void extend()\
    \ { reallocate(cap << 1); }\n\n  inline void shrink() { reallocate(cap >> 1);\
    \ }\n\n public:\n  u32 cap, s, occupied;\n  vector<Data> data;\n  vector<bool>\
    \ occupied_flag, deleted_flag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n\
    \        s(0),\n        occupied(0),\n        data(cap),\n        occupied_flag(cap),\n\
    \        deleted_flag(cap),\n        shift(64 - __lg(cap)) {}\n\n  itr begin()\
    \ const {\n    u32 h = 0;\n    while (h != cap) {\n      if (occupied_flag[h]\
    \ && !deleted_flag[h]) break;\n      h++;\n    }\n    return itr(h, this);\n \
    \ }\n  itr end() const { return itr(this->cap, this); }\n\n  friend itr begin(const\
    \ HashMapBase& h) { return h.begin(); }\n  friend itr end(const HashMapBase& h)\
    \ { return h.end(); }\n\n  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n\
    \    while (true) {\n      if (occupied_flag[h] == false) return this->end();\n\
    \      if (data_to_key(data[h]) == key) {\n        if (deleted_flag[h] == true)\
    \ return this->end();\n        return itr(h, this);\n      }\n      h = (h + 1)\
    \ & (cap - 1);\n    }\n  }\n\n  bool contain(const Key& key) const { return find(key)\
    \ != this->end(); }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n \
    \   while (true) {\n      if (occupied_flag[h] == false) {\n        if (extend_rate(occupied\
    \ + 1)) {\n          extend();\n          h = hash(d);\n          continue;\n\
    \        }\n        data[h] = d;\n        occupied_flag[h] = true;\n        ++occupied,\
    \ ++s;\n        return itr(h, this);\n      }\n      if (data_to_key(data[h])\
    \ == data_to_key(d)) {\n        if (deleted_flag[h] == true) {\n          data[h]\
    \ = d;\n          deleted_flag[h] = false;\n          ++s;\n        }\n      \
    \  return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\
    \n  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (!get_next) {\n      this->deleted_flag[it.i]\
    \ = true;\n      if (shrink_rate(s)) shrink();\n      return this->end();\n  \
    \  }\n    itr nxt = it;\n    nxt++;\n    this->deleted_flag[it.i] = true;\n  \
    \  if (shrink_rate(s)) {\n      Data d = data[nxt.i];\n      shrink();\n     \
    \ it = find(data_to_key(d));\n    }\n    return nxt;\n  }\n\n  itr erase(const\
    \ Key& key) { return erase(find(key)); }\n\n  int count(const Key& key) { return\
    \ find(key) == end() ? 0 : 1; }\n\n  bool empty() const { return s == 0; }\n\n\
    \  int size() const { return s; }\n\n  void clear() {\n    fill(std::begin(occupied_flag),\
    \ std::end(occupied_flag), false);\n    fill(std::begin(deleted_flag), std::end(deleted_flag),\
    \ false);\n    s = occupied = 0;\n  }\n\n  void reserve(int n) {\n    if (n <=\
    \ 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n\
    \  }\n};\n\ntemplate <typename Key, typename Data>\nuint64_t HashMapBase<Key,\
    \ Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n#line 4 \"hashmap/hashmap.hpp\"\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {\n  using base\
    \ = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n  using HashMapImpl::HashMapBase<Key,\
    \ pair<Key, Val>>::HashMapBase;\n  using Data = pair<Key, Val>;\n\n  Val& operator[](const\
    \ Key& k) {\n    typename base::u32 h = base::inner_hash(k);\n    while (true)\
    \ {\n      if (base::occupied_flag[h] == false) {\n        if (base::extend_rate(base::occupied\
    \ + 1)) {\n          base::extend();\n          h = base::hash(k);\n         \
    \ continue;\n        }\n        base::data[h].first = k;\n        base::data[h].second\
    \ = Val();\n        base::occupied_flag[h] = true;\n        ++base::occupied,\
    \ ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::deleted_flag[h] == true) {\n          base::data[h].second\
    \ = Val();\n          base::deleted_flag[h] = false;\n          ++base::s;\n \
    \       }\n        return base::data[h].second;\n      }\n      h = (h + 1) &\
    \ (base::cap - 1);\n    }\n  }\n\n  typename base::itr emplace(const Key& key,\
    \ const Val& val) {\n    return base::insert(Data(key, val));\n  }\n};\n\n/*\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217\
    )\n * @docs docs/hashmap/hashmap.md\n **/\n#line 2 \"internal/internal-math.hpp\"\
    \n\n#line 2 \"internal/internal-type-traits.hpp\"\n\n#include <type_traits>\n\
    using namespace std;\n\nnamespace internal {\ntemplate <typename T>\nusing is_broadly_integral\
    \ =\n    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||\n\
    \                               is_same_v<T, __uint128_t>,\n                 \
    \          true_type, false_type>::type;\n\ntemplate <typename T>\nusing is_broadly_signed\
    \ =\n    typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,\n\
    \                           true_type, false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
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
    \n}  // namespace internal\n#line 4 \"internal/internal-math.hpp\"\n\nnamespace\
    \ internal {\n\n#include <cassert>\nusing namespace std;\n\n// a mod p\ntemplate\
    \ <typename T>\nT safe_mod(T a, T p) {\n  a %= p;\n  if constexpr (is_broadly_signed_v<T>)\
    \ {\n    if (a < 0) a += p;\n  }\n  return a;\n}\n\n// \u8FD4\u308A\u5024\uFF1A\
    pair(g, x)\n// s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\ntemplate <typename\
    \ T>\npair<T, T> inv_gcd(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n\
    \  a = safe_mod(a, p);\n  if (a == 0) return {p, 0};\n  T b = p, x = 1, y = 0;\n\
    \  while (a) {\n    T q = b / a;\n    swap(a, b %= a);\n    swap(x, y -= q * x);\n\
    \  }\n  if (y < 0) y += p / b;\n  return {b, y};\n}\n\n// \u8FD4\u308A\u5024 :\
    \ a^{-1} mod p\n// gcd(a, p) != 1 \u304C\u5FC5\u8981\ntemplate <typename T>\n\
    T inv(T a, T p) {\n  static_assert(is_broadly_signed_v<T>);\n  a = safe_mod(a,\
    \ p);\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n    swap(a,\
    \ b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return y < 0 ?\
    \ y + p : y;\n}\n\n// T : \u5024\u306E\u578B\n// U : T*T \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\ntemplate <typename T, typename\
    \ U>\nT modpow(T a, __int128_t n, T p) {\n  a = safe_mod(a, p);\n  T ret = 1 %\
    \ p;\n  while (n) {\n    if (n & 1) ret = U(ret) * a % p;\n    a = U(a) * a %\
    \ p;\n    n >>= 1;\n  }\n  return ret;\n}\n\n// \u8FD4\u308A\u5024 : pair(rem,\
    \ mod)\n// \u89E3\u306A\u3057\u306E\u3068\u304D\u306F {0, 0} \u3092\u8FD4\u3059\
    \ntemplate <typename T>\npair<T, T> crt(const vector<T>& r, const vector<T>& m)\
    \ {\n  static_assert(is_broadly_signed_v<T>);\n  assert(r.size() == m.size());\n\
    \  int n = int(r.size());\n  T r0 = 0, m0 = 1;\n  for (int i = 0; i < n; i++)\
    \ {\n    assert(1 <= m[i]);\n    T r1 = safe_mod(r[i], m[i]), m1 = m[i];\n   \
    \ if (m0 < m1) swap(r0, r1), swap(m0, m1);\n    if (m0 % m1 == 0) {\n      if\
    \ (r0 % m1 != r1) return {0, 0};\n      continue;\n    }\n    auto [g, im] = inv_gcd(m0,\
    \ m1);\n    T u1 = m1 / g;\n    if ((r1 - r0) % g) return {0, 0};\n    T x = (r1\
    \ - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0 *= u1;\n    if (r0 < 0)\
    \ r0 += m0;\n  }\n  return {r0, m0};\n}\n\n}  // namespace internal\n#line 5 \"\
    modulo/mod-log.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b, int64_t p) {\n \
    \ if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n  int64_t f, g, r =\
    \ 1 % p;\n  for (f = 0; (g = gcd(a, p)) > 1; ++f) {\n    if (b % g) return (r\
    \ == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n  }\n \
    \ if (p == 1) return f;\n  int64_t ir = internal::inv(r, p);\n  (b *= ir) %= p;\n\
    \  int64_t k = 0, ak = 1;\n  HashMap<int64_t, int64_t> baby;\n  for (; k * k <\
    \ p; ++k) {\n    if(baby.find(ak) == baby.end()) baby[ak] = k;\n    (ak *= a)\
    \ %= p;\n  }\n  int64_t iak = internal::inv(ak, p);\n  for (int64_t i = 0; i <\
    \ k; ++i) {\n    if (baby.find(b) != baby.end()) return f + i * k + baby[b];\n\
    \    (b *= iak) %= p;\n  }\n  return -1;\n}\n"
  code: "#pragma once\n\n#include \"../hashmap/hashmap.hpp\"\n#include \"../internal/internal-math.hpp\"\
    \n\nint64_t mod_log(int64_t a, int64_t b, int64_t p) {\n  if ((a %= p) < 0) a\
    \ += p;\n  if ((b %= p) < 0) b += p;\n  int64_t f, g, r = 1 % p;\n  for (f = 0;\
    \ (g = gcd(a, p)) > 1; ++f) {\n    if (b % g) return (r == b) ? f : -1;\n    b\
    \ /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n  }\n  if (p == 1) return f;\n\
    \  int64_t ir = internal::inv(r, p);\n  (b *= ir) %= p;\n  int64_t k = 0, ak =\
    \ 1;\n  HashMap<int64_t, int64_t> baby;\n  for (; k * k < p; ++k) {\n    if(baby.find(ak)\
    \ == baby.end()) baby[ak] = k;\n    (ak *= a) %= p;\n  }\n  int64_t iak = internal::inv(ak,\
    \ p);\n  for (int64_t i = 0; i < k; ++i) {\n    if (baby.find(b) != baby.end())\
    \ return f + i * k + baby[b];\n    (b *= iak) %= p;\n  }\n  return -1;\n}"
  dependsOn:
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  - internal/internal-math.hpp
  - internal/internal-type-traits.hpp
  isVerificationFile: false
  path: modulo/mod-log.hpp
  requiredBy: []
  timestamp: '2023-05-28 20:44:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: modulo/mod-log.hpp
layout: document
redirect_from:
- /library/modulo/mod-log.hpp
- /library/modulo/mod-log.hpp.html
title: modulo/mod-log.hpp
---
