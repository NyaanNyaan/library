---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: hashmap/hashmap.hpp
    title: hashmap/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: hashmap/hashset.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/hashset.test.cpp
    title: verify/verify-unit-test/hashset.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"hashmap/hashmap-base.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\
    \ntemplate <typename Key, typename Data>\nstruct itrB : iterator<bidirectional_iterator_tag,\
    \ Key, ptrdiff_t, Key*, Key&> {\n  using base = iterator<bidirectional_iterator_tag,\
    \ Key, ptrdiff_t, Key*, Key&>;\n  using ptr = typename base::pointer;\n  using\
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
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n      assert(i\
    \ != 0 && \"itr::operator--()\");\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator--(int) {\n    itrB it(*this);\n    --(*this);\n    return\
    \ it;\n  }\n};\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase {\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  using iterator = itrB<Key,\
    \ Data>;\n  using itr = iterator;\n protected:\n  template <typename K,\n    \
    \        enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n         \
    \   enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n  inline u32 inner_hash(const\
    \ K& key) const {\n    return u32((u64(key ^ r) * 11995408973635179863ULL) >>\
    \ shift);\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    u64\
    \ a = key.first ^ r;\n    u64 b = key.second ^ r;\n    a *= 11995408973635179863ULL;\n\
    \    b *= 10150724397891781847ULL;\n    return u32((a + b) >> shift);\n  }\n \
    \ template <typename D = Data,\n            enable_if_t<is_same<D, Key>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n\
    \    return inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n  \
    \          enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline\
    \ Key dtok(const D& dat) const {\n    return dat;\n  }\n  template <\n      typename\
    \ D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t>\
    \ = nullptr>\n  inline Key dtok(const D& dat) const {\n    return dat.first;\n\
    \  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n    vector<bool>\
    \ nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0; i < cap; i++) {\n\
    \      if (flag[i] == true && dflag[i] == false) {\n        u32 h = hash(data[i]);\n\
    \        while (nf[h]) h = (h + 1) & (ncap - 1);\n        ndata[h] = data[i];\n\
    \        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n    flag.swap(nf);\n\
    \    cap = ncap;\n    dflag.resize(cap);\n    fill(std::begin(dflag), std::end(dflag),\
    \ false);\n  }\n\n  inline bool extend_rate(u32 x) const { return x * 2 >= cap;\
    \ }\n\n  inline bool shrink_rate(u32 x) const {\n    return HASHMAP_DEFAULT_SIZE\
    \ < cap && x * 10 <= cap;\n  }\n\n  inline void extend() { reallocate(cap << 1);\
    \ }\n\n  inline void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap,\
    \ s;\n  vector<Data> data;\n  vector<bool> flag, dflag;\n  u32 shift;\n  static\
    \ u64 r;\n  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit\
    \ HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n        s(0),\n        data(cap),\n\
    \        flag(cap),\n        dflag(cap),\n        shift(64 - __lg(cap)) {}\n\n\
    \  itr begin() const {\n    u32 h = 0;\n    while (h != cap) {\n      if (flag[h]\
    \ == true && dflag[h] == false) break;\n      h++;\n    }\n    return itr(h, this);\n\
    \  }\n  itr end() const { return itr(this->cap, this); }\n\n  friend itr begin(const\
    \ HashMapBase& h) { return h.begin(); }\n  friend itr end(const HashMapBase& h)\
    \ { return h.end(); }\n\n  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n\
    \    while (true) {\n      if (flag[h] == false) return this->end();\n      if\
    \ (dtok(data[h]) == key) {\n        if (dflag[h] == true) return this->end();\n\
    \        return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n\
    \  }\n\n  bool contain(const Key& key) const { return find(key) != this->end();\
    \ }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true) {\n\
    \      if (flag[h] == false) {\n        if (extend_rate(s + 1)) {\n          extend();\n\
    \          h = hash(d);\n          continue;\n        }\n        data[h] = d;\n\
    \        flag[h] = true;\n        ++s;\n        return itr(h, this);\n      }\n\
    \      if (dtok(data[h]) == dtok(d)) {\n        data[h] = d;\n        if (dflag[h]\
    \ == true) {\n          dflag[h] = false;\n          ++s;\n        }\n       \
    \ return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n\
    \  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (shrink_rate(s)) {\n      Data d = data[it.i];\n\
    \      shrink();\n      it = find(d);\n    }\n    int ni = (it.i + 1) & (cap -\
    \ 1);\n    if (this->flag[ni]) {\n      this->dflag[it.i] = true;\n    } else\
    \ {\n      this->flag[it.i] = false;\n    }\n    if (get_next) ++it;\n    return\
    \ it;\n  }\n\n  itr erase(const Key& key) { return erase(find(key)); }\n\n  bool\
    \ empty() const { return s == 0; }\n\n  int size() const { return s; }\n\n  void\
    \ clear() {\n    fill(std::begin(flag), std::end(flag), false);\n    fill(std::begin(dflag),\
    \ std::end(dflag), false);\n    s = 0;\n  }\n\n  void reserve(int n) {\n    if\
    \ (n <= 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n))\
    \ reallocate(n);\n  }\n};\n\ntemplate <typename Key, typename Data>\nuint64_t\
    \ HashMapBase<Key, Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n\
    \        chrono::high_resolution_clock::now().time_since_epoch())\n        .count();\n\
    \n}  // namespace HashMapImpl\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename Key, typename\
    \ Data>\nstruct itrB : iterator<bidirectional_iterator_tag, Key, ptrdiff_t, Key*,\
    \ Key&> {\n  using base = iterator<bidirectional_iterator_tag, Key, ptrdiff_t,\
    \ Key*, Key&>;\n  using ptr = typename base::pointer;\n  using ref = typename\
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
    );\n    do {\n      i++;\n      if (i == p->cap) break;\n      if (p->flag[i]\
    \ == true && p->dflag[i] == false) break;\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator++(int) {\n    itrB it(*this);\n    ++(*this);\n    return\
    \ it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n      if (p->flag[i]\
    \ == true && p->dflag[i] == false) break;\n      assert(i != 0 && \"itr::operator--()\"\
    );\n    } while (true);\n    return (*this);\n  }\n  itrB operator--(int) {\n\
    \    itrB it(*this);\n    --(*this);\n    return it;\n  }\n};\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashMapBase {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n  using iterator = itrB<Key, Data>;\n  using itr = iterator;\n\
    \ protected:\n  template <typename K,\n            enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n            enable_if_t<is_integral<K>::value, nullptr_t>\
    \ = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    return u32((u64(key\
    \ ^ r) * 11995408973635179863ULL) >> shift);\n  }\n  template <\n      typename\
    \ K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    u64\
    \ a = key.first ^ r;\n    u64 b = key.second ^ r;\n    a *= 11995408973635179863ULL;\n\
    \    b *= 10150724397891781847ULL;\n    return u32((a + b) >> shift);\n  }\n \
    \ template <typename D = Data,\n            enable_if_t<is_same<D, Key>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n\
    \    return inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n  \
    \          enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline\
    \ Key dtok(const D& dat) const {\n    return dat;\n  }\n  template <\n      typename\
    \ D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t>\
    \ = nullptr>\n  inline Key dtok(const D& dat) const {\n    return dat.first;\n\
    \  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n    vector<bool>\
    \ nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0; i < cap; i++) {\n\
    \      if (flag[i] == true && dflag[i] == false) {\n        u32 h = hash(data[i]);\n\
    \        while (nf[h]) h = (h + 1) & (ncap - 1);\n        ndata[h] = data[i];\n\
    \        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n    flag.swap(nf);\n\
    \    cap = ncap;\n    dflag.resize(cap);\n    fill(std::begin(dflag), std::end(dflag),\
    \ false);\n  }\n\n  inline bool extend_rate(u32 x) const { return x * 2 >= cap;\
    \ }\n\n  inline bool shrink_rate(u32 x) const {\n    return HASHMAP_DEFAULT_SIZE\
    \ < cap && x * 10 <= cap;\n  }\n\n  inline void extend() { reallocate(cap << 1);\
    \ }\n\n  inline void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap,\
    \ s;\n  vector<Data> data;\n  vector<bool> flag, dflag;\n  u32 shift;\n  static\
    \ u64 r;\n  static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit\
    \ HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n        s(0),\n        data(cap),\n\
    \        flag(cap),\n        dflag(cap),\n        shift(64 - __lg(cap)) {}\n\n\
    \  itr begin() const {\n    u32 h = 0;\n    while (h != cap) {\n      if (flag[h]\
    \ == true && dflag[h] == false) break;\n      h++;\n    }\n    return itr(h, this);\n\
    \  }\n  itr end() const { return itr(this->cap, this); }\n\n  friend itr begin(const\
    \ HashMapBase& h) { return h.begin(); }\n  friend itr end(const HashMapBase& h)\
    \ { return h.end(); }\n\n  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n\
    \    while (true) {\n      if (flag[h] == false) return this->end();\n      if\
    \ (dtok(data[h]) == key) {\n        if (dflag[h] == true) return this->end();\n\
    \        return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n\
    \  }\n\n  bool contain(const Key& key) const { return find(key) != this->end();\
    \ }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true) {\n\
    \      if (flag[h] == false) {\n        if (extend_rate(s + 1)) {\n          extend();\n\
    \          h = hash(d);\n          continue;\n        }\n        data[h] = d;\n\
    \        flag[h] = true;\n        ++s;\n        return itr(h, this);\n      }\n\
    \      if (dtok(data[h]) == dtok(d)) {\n        data[h] = d;\n        if (dflag[h]\
    \ == true) {\n          dflag[h] = false;\n          ++s;\n        }\n       \
    \ return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n\
    \  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (shrink_rate(s)) {\n      Data d = data[it.i];\n\
    \      shrink();\n      it = find(d);\n    }\n    int ni = (it.i + 1) & (cap -\
    \ 1);\n    if (this->flag[ni]) {\n      this->dflag[it.i] = true;\n    } else\
    \ {\n      this->flag[it.i] = false;\n    }\n    if (get_next) ++it;\n    return\
    \ it;\n  }\n\n  itr erase(const Key& key) { return erase(find(key)); }\n\n  bool\
    \ empty() const { return s == 0; }\n\n  int size() const { return s; }\n\n  void\
    \ clear() {\n    fill(std::begin(flag), std::end(flag), false);\n    fill(std::begin(dflag),\
    \ std::end(dflag), false);\n    s = 0;\n  }\n\n  void reserve(int n) {\n    if\
    \ (n <= 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n))\
    \ reallocate(n);\n  }\n};\n\ntemplate <typename Key, typename Data>\nuint64_t\
    \ HashMapBase<Key, Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n\
    \        chrono::high_resolution_clock::now().time_since_epoch())\n        .count();\n\
    \n}  // namespace HashMapImpl"
  dependsOn: []
  isVerificationFile: false
  path: hashmap/hashmap-base.hpp
  requiredBy:
  - hashmap/hashset.hpp
  - hashmap/hashmap.hpp
  timestamp: '2020-11-22 17:17:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/hashset.test.cpp
documentation_of: hashmap/hashmap-base.hpp
layout: document
redirect_from:
- /library/hashmap/hashmap-base.hpp
- /library/hashmap/hashmap-base.hpp.html
title: hashmap/hashmap-base.hpp
---
