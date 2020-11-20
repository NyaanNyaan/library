---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/hash-table.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nnamespace HashTableImpl {\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\n\ntemplate <typename Key, typename DS>\nstruct itrB : iterator<bidirectional_iterator_tag,\
    \ Key, ptrdiff_t, Key*, Key&> {\n  using base = iterator<bidirectional_iterator_tag,\
    \ Key, ptrdiff_t, Key*, Key&>;\n  using ptr = typename base::pointer;\n  using\
    \ ref = typename base::reference;\n\n  u32 i;\n  DS* p;\n  explicit constexpr\
    \ itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32 _i, DS* _p) : i(_i),\
    \ p(_p) {}\n  constexpr itrB(const itrB& r) : i(r.i), p(r.p) {}\n  itrB& operator=(const\
    \ itrB& r) { i = r.i, p = r.p; }\n  ~itrB() noexcept {}\n  friend void swap(itrB&\
    \ l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }\n  friend bool operator==(const\
    \ itrB& l, const itrB& r) { return l.i == r.i; }\n  friend bool operator!=(const\
    \ itrB& l, const itrB& r) { return l.i != r.i; }\n\n  ref operator*() const {\
    \ return p->data[i]; }\n  ptr operator->() const { return &(p->data[i]); }\n\n\
    \  itrB& operator++() {\n    assert(i != p->cap && \"itr::operator++()\");\n \
    \   do {\n      i++;\n      if (i == p->cap) break;\n      if (p->flag[i] == true\
    \ && p->dflag[i] == false) break;\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator++(int) {\n    itrB it(*this);\n    ++(*this);\n    return\
    \ it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n      if (p->flag[i]\
    \ == true && p->dflag[i] == false) break;\n      assert(i != 0 && \"itr::operator--()\"\
    );\n    } while (true);\n    return (*this);\n  }\n  itrB operator--(int) {\n\
    \    itrB it(*this);\n    --(*this);\n    return it;\n  }\n};\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashTableBase {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n  using itr = itrB<Data, HashTableBase>;\n\n protected:\n \
    \ template <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t>\
    \ = nullptr,\n            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n\
    \  inline u32 inner_hash(const K& key) {\n    return u32((u64(key) * 11995408973635179863ULL)\
    \ >> shift);\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) {\n    u64 a =\
    \ key.first;\n    u64 b = key.second;\n    a *= 11995408973635179863ULL;\n   \
    \ b *= 10150724397891781847ULL;\n    return u32((a + b) >> shift);\n  }\n  template\
    \ <typename D = Data,\n            enable_if_t<is_same<D, Key>::value, nullptr_t>\
    \ = nullptr>\n  inline u32 hash(const D& dat) {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) {\n    return\
    \ inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n            enable_if_t<is_same<D,\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 is_same_key(const D& l, const\
    \ D& r) const {\n    return l == r;\n  }\n  template <\n      typename D = Data,\n\
    \      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>\n\
    \  inline u32 is_same_key(const D& l, const D& r) const {\n    return l.first\
    \ == r.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n\
    \    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0;\
    \ i < cap; i++) {\n      if (flag[i] == true && dflag[i] == false) {\n       \
    \ u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap - 1);\n  \
    \      ndata[h] = data[i];\n        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n\
    \    flag.swap(nf);\n    cap = ncap;\n    dflag.resize(cap);\n    fill(std::begin(dflag),\
    \ std::end(dflag), false);\n  }\n\n  inline bool extend_rate() const { return\
    \ s + s / 2 >= cap; }\n\n  inline bool shrink_rate() const { return 8 < cap &&\
    \ s * 6 <= cap; }\n\n  inline void extend() { reallocate(cap << 1); }\n\n  inline\
    \ void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap, s;\n  vector<Data>\
    \ data;\n  vector<bool> flag, dflag;\n  u32 shift;\n\n  explicit HashTableBase()\n\
    \      : cap(8), s(0), data(cap), flag(cap), dflag(cap), shift(64 - __lg(cap))\
    \ {}\n\n  itr begin() { return ++itr(u32(-1), this); }\n  itr end() { return itr(this->cap,\
    \ this); }\n\n  itr find(const Data & d) {\n    u32 h = hash(d);\n    while (true)\
    \ {\n      if (flag[h] == false) return this->end();\n      if (is_same_key(data[h],\
    \ d)) {\n        if (dflag[h] == true) dflag[h] = false;\n        data[h] = d;\n\
    \        return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n\
    \  }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true)\
    \ {\n      if (flag[h] == false) {\n        if (extend_rate()) {\n          extend();\n\
    \          h = hash(d);\n          continue;\n        }\n        data[h] = d;\n\
    \        flag[h] = true;\n        ++s;\n        return itr(h, this);\n      }\n\
    \      if (is_same_key(data[h], d)) {\n        if (dflag[h] == true) dflag[h]\
    \ = false;\n        data[h] = d;\n        return itr(h, this);\n      }\n    \
    \  h = (h + 1) & (cap - 1);\n    }\n  }\n\n  // tips for speed up :\n  // if return\
    \ value is unnecessary, make argument_2 false.\n  itr erase(const itr& it, bool\
    \ get_next = true) {\n    assert(it != this->end() && \"itr erase(const itr& it)\"\
    );\n    s--;\n    if (shrink_rate()) {\n      Data d = data[it.i];\n      shrink();\n\
    \      // find key\n      it = find(d);\n    }\n    this->dflag[it.i] = true;\n\
    \    itr res = it;\n    if (get_next) ++res;\n    return res;\n  }\n};\n\n}  //\
    \ namespace HashTableImpl\n\ntemplate <typename Key, typename Val>\nstruct HashMap\
    \ : HashTableImpl::HashTableBase<Key, pair<Key, Val>> {\n  using base = typename\
    \ HashTableImpl::HashTableBase<Key, pair<Key, Val>>;\n  using base::HashTableBase;\n\
    \  using Data = pair<Key, Val>;\n\n  Val& operator[](const Key& k) {\n    typename\
    \ base::u32 h = base::hash(k);\n    while (true) {\n      if (base::flag[h] ==\
    \ false) {\n        if (base::extend_rate()) {\n          base::extend();\n  \
    \        h = base::hash(k);\n          continue;\n        }\n        base::data[h].first\
    \ = k;\n        base::data[h].second = Val();\n        base::flag[h] = true;\n\
    \        ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::dflag[h] == true) base::data[h].second = Val();\n\
    \        return base::data[h].second;\n      }\n      h = (h + 1) & (base::cap\
    \ - 1);\n    }\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace HashTableImpl\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate <typename Key, typename\
    \ DS>\nstruct itrB : iterator<bidirectional_iterator_tag, Key, ptrdiff_t, Key*,\
    \ Key&> {\n  using base = iterator<bidirectional_iterator_tag, Key, ptrdiff_t,\
    \ Key*, Key&>;\n  using ptr = typename base::pointer;\n  using ref = typename\
    \ base::reference;\n\n  u32 i;\n  DS* p;\n  explicit constexpr itrB() : i(0),\
    \ p(nullptr) {}\n  explicit constexpr itrB(u32 _i, DS* _p) : i(_i), p(_p) {}\n\
    \  constexpr itrB(const itrB& r) : i(r.i), p(r.p) {}\n  itrB& operator=(const\
    \ itrB& r) { i = r.i, p = r.p; }\n  ~itrB() noexcept {}\n  friend void swap(itrB&\
    \ l, itrB& r) { swap(l.i, r.i), swap(l.p, r.p); }\n  friend bool operator==(const\
    \ itrB& l, const itrB& r) { return l.i == r.i; }\n  friend bool operator!=(const\
    \ itrB& l, const itrB& r) { return l.i != r.i; }\n\n  ref operator*() const {\
    \ return p->data[i]; }\n  ptr operator->() const { return &(p->data[i]); }\n\n\
    \  itrB& operator++() {\n    assert(i != p->cap && \"itr::operator++()\");\n \
    \   do {\n      i++;\n      if (i == p->cap) break;\n      if (p->flag[i] == true\
    \ && p->dflag[i] == false) break;\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator++(int) {\n    itrB it(*this);\n    ++(*this);\n    return\
    \ it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n      if (p->flag[i]\
    \ == true && p->dflag[i] == false) break;\n      assert(i != 0 && \"itr::operator--()\"\
    );\n    } while (true);\n    return (*this);\n  }\n  itrB operator--(int) {\n\
    \    itrB it(*this);\n    --(*this);\n    return it;\n  }\n};\n\ntemplate <typename\
    \ Key, typename Data>\nstruct HashTableBase {\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n  using itr = itrB<Data, HashTableBase>;\n\n protected:\n \
    \ template <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t>\
    \ = nullptr,\n            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n\
    \  inline u32 inner_hash(const K& key) {\n    return u32((u64(key) * 11995408973635179863ULL)\
    \ >> shift);\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) {\n    u64 a =\
    \ key.first;\n    u64 b = key.second;\n    a *= 11995408973635179863ULL;\n   \
    \ b *= 10150724397891781847ULL;\n    return u32((a + b) >> shift);\n  }\n  template\
    \ <typename D = Data,\n            enable_if_t<is_same<D, Key>::value, nullptr_t>\
    \ = nullptr>\n  inline u32 hash(const D& dat) {\n    return inner_hash(dat);\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) {\n    return\
    \ inner_hash(dat.first);\n  }\n\n  template <typename D = Data,\n            enable_if_t<is_same<D,\
    \ Key>::value, nullptr_t> = nullptr>\n  inline u32 is_same_key(const D& l, const\
    \ D& r) const {\n    return l == r;\n  }\n  template <\n      typename D = Data,\n\
    \      enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr>\n\
    \  inline u32 is_same_key(const D& l, const D& r) const {\n    return l.first\
    \ == r.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data> ndata(ncap);\n\
    \    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n    for (u32 i = 0;\
    \ i < cap; i++) {\n      if (flag[i] == true && dflag[i] == false) {\n       \
    \ u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap - 1);\n  \
    \      ndata[h] = data[i];\n        nf[h] = true;\n      }\n    }\n    data.swap(ndata);\n\
    \    flag.swap(nf);\n    cap = ncap;\n    dflag.resize(cap);\n    fill(std::begin(dflag),\
    \ std::end(dflag), false);\n  }\n\n  inline bool extend_rate() const { return\
    \ s + s / 2 >= cap; }\n\n  inline bool shrink_rate() const { return 8 < cap &&\
    \ s * 6 <= cap; }\n\n  inline void extend() { reallocate(cap << 1); }\n\n  inline\
    \ void shrink() { reallocate(cap >> 1); }\n\n public:\n  u32 cap, s;\n  vector<Data>\
    \ data;\n  vector<bool> flag, dflag;\n  u32 shift;\n\n  explicit HashTableBase()\n\
    \      : cap(8), s(0), data(cap), flag(cap), dflag(cap), shift(64 - __lg(cap))\
    \ {}\n\n  itr begin() { return ++itr(u32(-1), this); }\n  itr end() { return itr(this->cap,\
    \ this); }\n\n  itr find(const Data & d) {\n    u32 h = hash(d);\n    while (true)\
    \ {\n      if (flag[h] == false) return this->end();\n      if (is_same_key(data[h],\
    \ d)) {\n        if (dflag[h] == true) dflag[h] = false;\n        data[h] = d;\n\
    \        return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n\
    \  }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n    while (true)\
    \ {\n      if (flag[h] == false) {\n        if (extend_rate()) {\n          extend();\n\
    \          h = hash(d);\n          continue;\n        }\n        data[h] = d;\n\
    \        flag[h] = true;\n        ++s;\n        return itr(h, this);\n      }\n\
    \      if (is_same_key(data[h], d)) {\n        if (dflag[h] == true) dflag[h]\
    \ = false;\n        data[h] = d;\n        return itr(h, this);\n      }\n    \
    \  h = (h + 1) & (cap - 1);\n    }\n  }\n\n  // tips for speed up :\n  // if return\
    \ value is unnecessary, make argument_2 false.\n  itr erase(const itr& it, bool\
    \ get_next = true) {\n    assert(it != this->end() && \"itr erase(const itr& it)\"\
    );\n    s--;\n    if (shrink_rate()) {\n      Data d = data[it.i];\n      shrink();\n\
    \      // find key\n      it = find(d);\n    }\n    this->dflag[it.i] = true;\n\
    \    itr res = it;\n    if (get_next) ++res;\n    return res;\n  }\n};\n\n}  //\
    \ namespace HashTableImpl\n\ntemplate <typename Key, typename Val>\nstruct HashMap\
    \ : HashTableImpl::HashTableBase<Key, pair<Key, Val>> {\n  using base = typename\
    \ HashTableImpl::HashTableBase<Key, pair<Key, Val>>;\n  using base::HashTableBase;\n\
    \  using Data = pair<Key, Val>;\n\n  Val& operator[](const Key& k) {\n    typename\
    \ base::u32 h = base::hash(k);\n    while (true) {\n      if (base::flag[h] ==\
    \ false) {\n        if (base::extend_rate()) {\n          base::extend();\n  \
    \        h = base::hash(k);\n          continue;\n        }\n        base::data[h].first\
    \ = k;\n        base::data[h].second = Val();\n        base::flag[h] = true;\n\
    \        ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::dflag[h] == true) base::data[h].second = Val();\n\
    \        return base::data[h].second;\n      }\n      h = (h + 1) & (base::cap\
    \ - 1);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash-table.hpp
  requiredBy: []
  timestamp: '2020-11-21 01:32:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/hash-table.hpp
layout: document
redirect_from:
- /library/data-structure/hash-table.hpp
- /library/data-structure/hash-table.hpp.html
title: data-structure/hash-table.hpp
---
