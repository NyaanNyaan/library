---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/dynamic-union-find.hpp
    title: "\u52D5\u7684Union Find"
  - icon: ':heavy_check_mark:'
    path: graph/offline-dynamic-connectivity.hpp
    title: graph/offline-dynamic-connectivity.hpp
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashset.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8(\u96C6\u5408)"
  - icon: ':heavy_check_mark:'
    path: modulo/mod-log.hpp
    title: modulo/mod-log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
    title: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/hashmap.test.cpp
    title: verify/verify-unit-test/hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/hashset.test.cpp
    title: verify/verify-unit-test/hashset.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-hashmap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
    title: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\
      \u30FB\u57FA\u5E95\u30AF\u30E9\u30B9)"
    links: []
  bundledCode: "#line 2 \"hashmap/hashmap-base.hpp\"\n\n#include <cstdint>\nusing\
    \ namespace std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\
    \ntemplate <typename Key, typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag,\
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
    )\n */\n"
  code: "#pragma once\n\n#include <cstdint>\nusing namespace std;\n\nnamespace HashMapImpl\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate <typename Key, typename\
    \ Data>\nstruct HashMapBase;\n\ntemplate <typename Key, typename Data>\nstruct\
    \ itrB\n    : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data*, Data&>\
    \ {\n  using base =\n      iterator<bidirectional_iterator_tag, Data, ptrdiff_t,\
    \ Data*, Data&>;\n  using ptr = typename base::pointer;\n  using ref = typename\
    \ base::reference;\n\n  u32 i;\n  HashMapBase<Key, Data>* p;\n\n  explicit constexpr\
    \ itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32 _i, HashMapBase<Key,\
    \ Data>* _p) : i(_i), p(_p) {}\n  explicit constexpr itrB(u32 _i, const HashMapBase<Key,\
    \ Data>* _p)\n      : i(_i), p(const_cast<HashMapBase<Key, Data>*>(_p)) {}\n \
    \ friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }\n  friend\
    \ bool operator==(const itrB& l, const itrB& r) { return l.i == r.i; }\n  friend\
    \ bool operator!=(const itrB& l, const itrB& r) { return l.i != r.i; }\n  const\
    \ ref operator*() const {\n    return const_cast<const HashMapBase<Key, Data>*>(p)->data[i];\n\
    \  }\n  ref operator*() { return p->data[i]; }\n  ptr operator->() const { return\
    \ &(p->data[i]); }\n\n  itrB& operator++() {\n    assert(i != p->cap && \"itr::operator++()\"\
    );\n    do {\n      i++;\n      if (i == p->cap) break;\n      if (p->occupied_flag[i]\
    \ && !p->deleted_flag[i]) break;\n    } while (true);\n    return (*this);\n \
    \ }\n  itrB operator++(int) {\n    itrB it(*this);\n    ++(*this);\n    return\
    \ it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n      if (p->occupied_flag[i]\
    \ && !p->deleted_flag[i]) break;\n      assert(i != 0 && \"itr::operator--()\"\
    );\n    } while (true);\n    return (*this);\n  }\n  itrB operator--(int) {\n\
    \    itrB it(*this);\n    --(*this);\n    return it;\n  }\n};\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashMapBase {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n  using iterator = itrB<Key, Data>;\n  using itr = iterator;\n\
    \n protected:\n  template <typename K>\n  inline u64 randomized(const K& key)\
    \ const {\n    return u64(key) ^ r;\n  }\n\n  template <typename K,\n        \
    \    enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n            enable_if_t<is_integral<K>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    return\
    \ (randomized(key) * 11995408973635179863ULL) >> shift;\n  }\n  template <\n \
    \     typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \      enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,\n\
    \      enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>\n\
    \  inline u32 inner_hash(const K& key) const {\n    u64 a = randomized(key.first),\
    \ b = randomized(key.second);\n    a *= 11995408973635179863ULL;\n    b *= 10150724397891781847ULL;\n\
    \    return (a + b) >> shift;\n  }\n  template <typename K,\n            enable_if_t<is_same<K,\
    \ Key>::value, nullptr_t> = nullptr,\n            enable_if_t<is_integral<typename\
    \ K::value_type>::value, nullptr_t> =\n                nullptr>\n  inline u32\
    \ inner_hash(const K& key) const {\n    static constexpr u64 mod = (1LL << 61)\
    \ - 1;\n    static constexpr u64 base = 950699498548472943ULL;\n    u64 res =\
    \ 0;\n    for (auto& elem : key) {\n      __uint128_t x = __uint128_t(res) * base\
    \ + (randomized(elem) & mod);\n      res = (x & mod) + (x >> 61);\n    }\n   \
    \ __uint128_t x = __uint128_t(res) * base;\n    res = (x & mod) + (x >> 61);\n\
    \    if (res >= mod) res -= mod;\n    return res >> (shift - 3);\n  }\n\n  template\
    \ <typename D = Data,\n            enable_if_t<is_same<D, Key>::value, nullptr_t>\
    \ = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n\
    \    return inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n  \
    \          enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline\
    \ Key data_to_key(const D& dat) const {\n    return dat;\n  }\n  template <\n\
    \      typename D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const {\n    return\
    \ dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n\
    \    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0;\
    \ i < cap; i++) {\n      if (occupied_flag[i] && !deleted_flag[i]) {\n       \
    \ u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap - 1);\n  \
    \      ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n\
    \    occupied_flag.swap(nf);\n    cap = ncap;\n    occupied = s;\n    deleted_flag.resize(cap);\n\
    \    fill(std::begin(deleted_flag), std::end(deleted_flag), false);\n  }\n\n \
    \ inline bool extend_rate(u32 x) const { return x * 2 >= cap; }\n\n  inline bool\
    \ shrink_rate(u32 x) const {\n    return HASHMAP_DEFAULT_SIZE < cap && x * 10\
    \ <= cap;\n  }\n\n  inline void extend() { reallocate(cap << 1); }\n\n  inline\
    \ void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap, s, occupied;\n\
    \  vector<Data> data;\n  vector<bool> occupied_flag, deleted_flag;\n  u32 shift;\n\
    \  static u64 r;\n  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit\
    \ HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n        s(0),\n        occupied(0),\n\
    \        data(cap),\n        occupied_flag(cap),\n        deleted_flag(cap),\n\
    \        shift(64 - __lg(cap)) {}\n\n  itr begin() const {\n    u32 h = 0;\n \
    \   while (h != cap) {\n      if (occupied_flag[h] && !deleted_flag[h]) break;\n\
    \      h++;\n    }\n    return itr(h, this);\n  }\n  itr end() const { return\
    \ itr(this->cap, this); }\n\n  friend itr begin(const HashMapBase& h) { return\
    \ h.begin(); }\n  friend itr end(const HashMapBase& h) { return h.end(); }\n\n\
    \  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n    while (true)\
    \ {\n      if (occupied_flag[h] == false) return this->end();\n      if (data_to_key(data[h])\
    \ == key) {\n        if (deleted_flag[h] == true) return this->end();\n      \
    \  return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\
    \n  bool contain(const Key& key) const { return find(key) != this->end(); }\n\n\
    \  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true) {\n   \
    \   if (occupied_flag[h] == false) {\n        if (extend_rate(occupied + 1)) {\n\
    \          extend();\n          h = hash(d);\n          continue;\n        }\n\
    \        data[h] = d;\n        occupied_flag[h] = true;\n        ++occupied, ++s;\n\
    \        return itr(h, this);\n      }\n      if (data_to_key(data[h]) == data_to_key(d))\
    \ {\n        if (deleted_flag[h] == true) {\n          data[h] = d;\n        \
    \  deleted_flag[h] = false;\n          ++s;\n        }\n        return itr(h,\
    \ this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n  // tips for\
    \ speed up :\n  // if return value is unnecessary, make argument_2 false.\n  itr\
    \ erase(itr it, bool get_next = true) {\n    if (it == this->end()) return this->end();\n\
    \    s--;\n    if (!get_next) {\n      this->deleted_flag[it.i] = true;\n    \
    \  if (shrink_rate(s)) shrink();\n      return this->end();\n    }\n    itr nxt\
    \ = it;\n    nxt++;\n    this->deleted_flag[it.i] = true;\n    if (shrink_rate(s))\
    \ {\n      Data d = data[nxt.i];\n      shrink();\n      it = find(data_to_key(d));\n\
    \    }\n    return nxt;\n  }\n\n  itr erase(const Key& key) { return erase(find(key));\
    \ }\n\n  int count(const Key& key) { return find(key) == end() ? 0 : 1; }\n\n\
    \  bool empty() const { return s == 0; }\n\n  int size() const { return s; }\n\
    \n  void clear() {\n    fill(std::begin(occupied_flag), std::end(occupied_flag),\
    \ false);\n    fill(std::begin(deleted_flag), std::end(deleted_flag), false);\n\
    \    s = occupied = 0;\n  }\n\n  void reserve(int n) {\n    if (n <= 0) return;\n\
    \    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n  }\n\
    };\n\ntemplate <typename Key, typename Data>\nuint64_t HashMapBase<Key, Data>::r\
    \ =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: hashmap/hashmap-base.hpp
  requiredBy:
  - data-structure/dynamic-union-find.hpp
  - modulo/mod-log.hpp
  - graph/offline-dynamic-connectivity.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashset.hpp
  timestamp: '2023-03-25 00:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-unit-test/hashset.test.cpp
  - verify/verify-unit-test/hashmap.test.cpp
  - verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
  - verify/verify-yosupo-ds/yosupo-hashmap.test.cpp
  - verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
documentation_of: hashmap/hashmap-base.hpp
layout: document
redirect_from:
- /library/hashmap/hashmap-base.hpp
- /library/hashmap/hashmap-base.hpp.html
title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
  \u5E95\u30AF\u30E9\u30B9)"
---
