---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: hashmap/hashmap-base.hpp
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/hashmap.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"hashmap/hashmap-base.hpp\"\nusing namespace std;\n\
    \nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate\
    \ <typename Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename Key,\
    \ typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag, Data,\
    \ ptrdiff_t, Data*, Data&> {\n  using base =\n      iterator<bidirectional_iterator_tag,\
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
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n      assert(i\
    \ != 0 && \"itr::operator--()\");\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator--(int) {\n    itrB it(*this);\n    --(*this);\n    return\
    \ it;\n  }\n};\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase {\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  using iterator = itrB<Key,\
    \ Data>;\n  using itr = iterator;\n\n protected:\n  template <typename K,\n  \
    \          enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n       \
    \     enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n  inline u32 inner_hash(const\
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
    \      if (dtok(data[h]) == dtok(d)) {\n        if (dflag[h] == true) {\n    \
    \      data[h] = d;\n          dflag[h] = false;\n          ++s;\n        }\n\
    \        return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n\
    \  }\n\n  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (shrink_rate(s)) {\n      Data d = data[it.i];\n\
    \      shrink();\n      it = find(dtok(d));\n    }\n    int ni = (it.i + 1) &\
    \ (cap - 1);\n    if (this->flag[ni]) {\n      this->dflag[it.i] = true;\n   \
    \ } else {\n      this->flag[it.i] = false;\n    }\n    if (get_next) ++it;\n\
    \    return it;\n  }\n\n  itr erase(const Key& key) { return erase(find(key));\
    \ }\n\n  bool empty() const { return s == 0; }\n\n  int size() const { return\
    \ s; }\n\n  void clear() {\n    fill(std::begin(flag), std::end(flag), false);\n\
    \    fill(std::begin(dflag), std::end(dflag), false);\n    s = 0;\n  }\n\n  void\
    \ reserve(int n) {\n    if (n <= 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n\
    \    if (cap < u32(n)) reallocate(n);\n  }\n};\n\ntemplate <typename Key, typename\
    \ Data>\nuint64_t HashMapBase<Key, Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n\
    \        chrono::high_resolution_clock::now().time_since_epoch())\n        .count();\n\
    \n}  // namespace HashMapImpl\n#line 2 \"hashmap/hashmap.hpp\"\n\ntemplate <typename\
    \ Key, typename Val>\nstruct HashMap : HashMapImpl::HashMapBase<Key, pair<Key,\
    \ Val>> {\n  using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n\
    \  using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;\n  using\
    \ Data = pair<Key, Val>;\n\n  Val& operator[](const Key& k) {\n    typename base::u32\
    \ h = base::inner_hash(k);\n    while (true) {\n      if (base::flag[h] == false)\
    \ {\n        if (base::extend_rate(base::s + 1)) {\n          base::extend();\n\
    \          h = base::hash(k);\n          continue;\n        }\n        base::data[h].first\
    \ = k;\n        base::data[h].second = Val();\n        base::flag[h] = true;\n\
    \        ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::dflag[h] == true) base::data[h].second = Val();\n\
    \        return base::data[h].second;\n      }\n      h = (h + 1) & (base::cap\
    \ - 1);\n    }\n  }\n\n  typename base::itr emplace(const Key& key, const Val&\
    \ val) {\n    return base::insert(Data(key, val));\n  }\n};\n\n/* \n * @brief\
    \ \u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)\n * @docs\
    \ docs/hashmap/hashmap.md\n**/\n#line 6 \"verify/verify-unit-test/hashmap.test.cpp\"\
    \n\nnamespace HashMapTest {\n\nuint64_t rng() {\n  static uint64_t x_ =\n    \
    \  chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n// [l, r)\n\
    int64_t randint(int64_t l, int64_t r) {\n  assert(l < r);\n  return l + rng()\
    \ % (r - l);\n}\n\ntemplate <typename K, enable_if_t<is_integral<K>::value, nullptr_t>\
    \ = nullptr>\nK random_key(int mx) {\n  return K{K(randint(0, mx))};\n}\ntemplate\
    \ <typename K, enable_if_t<is_integral<decltype(K::first)>::value,\n         \
    \                         nullptr_t> = nullptr>\nK random_key(int mx) {\n  return\
    \ K{decltype(K::first)(randint(0, mx)),\n           decltype(K::second)(randint(0,\
    \ mx))};\n}\n\ntemplate <typename HM, typename M, typename K>\nvoid same_map(HM&\
    \ hm, M& m, int mx) {\n  // iterator\n  {\n    M buf;\n    for (auto& x : hm)\
    \ buf[x.first] = x.second;\n    assert(buf == m);\n  }\n\n  // ensure empty space\
    \ in hash table\n  {\n    uint32_t s = 0;\n    for (uint32_t i = 0; i < hm.cap;\
    \ ++i) s += hm.flag[i];\n    assert(s != hm.cap && \"hash table is full!\");\n\
    \  }\n\n  // find\n  {\n    for (int i = 0; i < 2 * mx; i++) {\n      K k = random_key<K>(mx);\n\
    \      auto flg1 = hm.find(k) != hm.end();\n      auto flg2 = m.find(k) != m.end();\n\
    \      auto flg3 = hm.contain(k);\n      assert(flg1 == flg2 && \"find(k)\");\n\
    \      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  }\n\n  // empty\n  assert(hm.empty()\
    \ == m.empty() && \"empty()\");\n  // size\n  assert(hm.size() == (int)m.size()\
    \ && \"size()\");\n}\n\ntemplate <typename Key, typename Val>\nvoid stress_test(int\
    \ mx, int loop_time) {\n  using HM = HashMap<Key, Val>;\n  using M = map<Key,\
    \ Val>;\n\n  HM hm;\n  M m;\n\n  // insert [], erase(key)\n  for (int loop = 0;\
    \ loop < loop_time; loop++) {\n    vector<Key> key;\n    vector<Val> val;\n  \
    \  for (int i = mx; i--;) {\n      key.push_back(random_key<Key>(mx));\n     \
    \ val.push_back(random_key<Val>(mx));\n    }\n    for (int i = 0; i < mx; i++)\
    \ {\n      hm[key[i]] = val[i];\n      m[key[i]] = val[i];\n      same_map<HM,\
    \ M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n \
    \   assert(hm.size() == int(m.size()));\n    for (int i = 0; i < mx; i++) {\n\
    \      hm.erase(key[i]);\n      m.erase(key[i]);\n      same_map<HM, M, Key>(hm,\
    \ m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n    assert(hm.size()\
    \ == int(m.size()));\n    assert(hm.empty() == true);\n  }\n\n  // insert(Data),\
    \ erase(it)\n  for (int loop = 0; loop < loop_time; loop++) {\n    vector<Key>\
    \ key;\n    vector<Val> val;\n    for (int i = mx; i--;) {\n      key.push_back(random_key<Key>(mx));\n\
    \      val.push_back(random_key<Val>(mx));\n    }\n    for (int i = 0; i < mx;\
    \ i++) {\n      hm.emplace(key[i], val[i]);\n      m.emplace(key[i], val[i]);\n\
    \      same_map<HM, M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm,\
    \ m, mx);\n    }\n    assert(hm.size() == int(m.size()));\n    for (int i = 0;\
    \ i < mx; i++) {\n      hm.erase(key[i]);\n      m.erase(key[i]);\n      same_map<HM,\
    \ M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n \
    \   assert(hm.size() == int(m.size()));\n    assert(hm.empty() == true);\n  }\n\
    \  {\n    vector<Key> key;\n    vector<Val> val;\n    for (int i = mx; i--;) {\n\
    \      key.push_back(random_key<Key>(mx));\n      val.push_back(random_key<Val>(mx));\n\
    \    }\n    for (int i = 0; i < mx; i++) {\n      hm.emplace(key[i], val[i]);\n\
    \      m.emplace(key[i], val[i]);\n      same_map<HM, M, Key>(hm, m, mx);\n  \
    \    same_map<const HM, M, Key>(hm, m, mx);\n    }\n    // clear\n    hm.clear();\n\
    \    m.clear();\n    same_map<HM, M, Key>(hm, m, mx);\n    same_map<const HM,\
    \ M, Key>(hm, m, mx);\n    assert(hm.size() == int(m.size()));\n    assert(hm.empty()\
    \ == true);\n\n    // reverse\n    hm.reserve(mx);\n    uint32_t cap = hm.cap;\n\
    \    for (int i = 0; i < mx; i++) {\n      hm.emplace(key[i], val[i]);\n     \
    \ m.emplace(key[i], val[i]);\n      same_map<HM, M, Key>(hm, m, mx);\n      same_map<const\
    \ HM, M, Key>(hm, m, mx);\n    }\n    assert(hm.cap == cap);\n  }\n}\n\ntemplate\
    \ <typename Key, typename Val = int>\nvoid test() {\n  stress_test<Key, Val>(1,\
    \ 100);\n  stress_test<Key, Val>(2, 100);\n  stress_test<Key, Val>(4, 100);\n\
    \  stress_test<Key, Val>(8, 100);\n  stress_test<Key, Val>(16, 100);\n  stress_test<Key,\
    \ Val>(32, 10);\n  stress_test<Key, Val>(64, 10);\n  stress_test<Key, Val>(128,\
    \ 3);\n  stress_test<Key, Val>(256, 3);\n}\n\n}  // namespace HashMapTest\n\n\
    int main() {\n  HashMapTest::test<int, int>();\n  HashMapTest::test<long long,\
    \ int>();\n  HashMapTest::test<pair<int, int>, int>();\n  HashMapTest::test<pair<long\
    \ long, int>, int>();\n  HashMapTest::test<pair<int, long long>, int>();\n  HashMapTest::test<pair<long\
    \ long, long long>, int>();\n\n  int64_t a, b;\n  cin >> a >> b;\n  cout << (a\
    \ + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../hashmap/hashmap.hpp\"\n\nnamespace HashMapTest\
    \ {\n\nuint64_t rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n// [l, r)\nint64_t\
    \ randint(int64_t l, int64_t r) {\n  assert(l < r);\n  return l + rng() % (r -\
    \ l);\n}\n\ntemplate <typename K, enable_if_t<is_integral<K>::value, nullptr_t>\
    \ = nullptr>\nK random_key(int mx) {\n  return K{K(randint(0, mx))};\n}\ntemplate\
    \ <typename K, enable_if_t<is_integral<decltype(K::first)>::value,\n         \
    \                         nullptr_t> = nullptr>\nK random_key(int mx) {\n  return\
    \ K{decltype(K::first)(randint(0, mx)),\n           decltype(K::second)(randint(0,\
    \ mx))};\n}\n\ntemplate <typename HM, typename M, typename K>\nvoid same_map(HM&\
    \ hm, M& m, int mx) {\n  // iterator\n  {\n    M buf;\n    for (auto& x : hm)\
    \ buf[x.first] = x.second;\n    assert(buf == m);\n  }\n\n  // ensure empty space\
    \ in hash table\n  {\n    uint32_t s = 0;\n    for (uint32_t i = 0; i < hm.cap;\
    \ ++i) s += hm.flag[i];\n    assert(s != hm.cap && \"hash table is full!\");\n\
    \  }\n\n  // find\n  {\n    for (int i = 0; i < 2 * mx; i++) {\n      K k = random_key<K>(mx);\n\
    \      auto flg1 = hm.find(k) != hm.end();\n      auto flg2 = m.find(k) != m.end();\n\
    \      auto flg3 = hm.contain(k);\n      assert(flg1 == flg2 && \"find(k)\");\n\
    \      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  }\n\n  // empty\n  assert(hm.empty()\
    \ == m.empty() && \"empty()\");\n  // size\n  assert(hm.size() == (int)m.size()\
    \ && \"size()\");\n}\n\ntemplate <typename Key, typename Val>\nvoid stress_test(int\
    \ mx, int loop_time) {\n  using HM = HashMap<Key, Val>;\n  using M = map<Key,\
    \ Val>;\n\n  HM hm;\n  M m;\n\n  // insert [], erase(key)\n  for (int loop = 0;\
    \ loop < loop_time; loop++) {\n    vector<Key> key;\n    vector<Val> val;\n  \
    \  for (int i = mx; i--;) {\n      key.push_back(random_key<Key>(mx));\n     \
    \ val.push_back(random_key<Val>(mx));\n    }\n    for (int i = 0; i < mx; i++)\
    \ {\n      hm[key[i]] = val[i];\n      m[key[i]] = val[i];\n      same_map<HM,\
    \ M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n \
    \   assert(hm.size() == int(m.size()));\n    for (int i = 0; i < mx; i++) {\n\
    \      hm.erase(key[i]);\n      m.erase(key[i]);\n      same_map<HM, M, Key>(hm,\
    \ m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n    assert(hm.size()\
    \ == int(m.size()));\n    assert(hm.empty() == true);\n  }\n\n  // insert(Data),\
    \ erase(it)\n  for (int loop = 0; loop < loop_time; loop++) {\n    vector<Key>\
    \ key;\n    vector<Val> val;\n    for (int i = mx; i--;) {\n      key.push_back(random_key<Key>(mx));\n\
    \      val.push_back(random_key<Val>(mx));\n    }\n    for (int i = 0; i < mx;\
    \ i++) {\n      hm.emplace(key[i], val[i]);\n      m.emplace(key[i], val[i]);\n\
    \      same_map<HM, M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm,\
    \ m, mx);\n    }\n    assert(hm.size() == int(m.size()));\n    for (int i = 0;\
    \ i < mx; i++) {\n      hm.erase(key[i]);\n      m.erase(key[i]);\n      same_map<HM,\
    \ M, Key>(hm, m, mx);\n      same_map<const HM, M, Key>(hm, m, mx);\n    }\n \
    \   assert(hm.size() == int(m.size()));\n    assert(hm.empty() == true);\n  }\n\
    \  {\n    vector<Key> key;\n    vector<Val> val;\n    for (int i = mx; i--;) {\n\
    \      key.push_back(random_key<Key>(mx));\n      val.push_back(random_key<Val>(mx));\n\
    \    }\n    for (int i = 0; i < mx; i++) {\n      hm.emplace(key[i], val[i]);\n\
    \      m.emplace(key[i], val[i]);\n      same_map<HM, M, Key>(hm, m, mx);\n  \
    \    same_map<const HM, M, Key>(hm, m, mx);\n    }\n    // clear\n    hm.clear();\n\
    \    m.clear();\n    same_map<HM, M, Key>(hm, m, mx);\n    same_map<const HM,\
    \ M, Key>(hm, m, mx);\n    assert(hm.size() == int(m.size()));\n    assert(hm.empty()\
    \ == true);\n\n    // reverse\n    hm.reserve(mx);\n    uint32_t cap = hm.cap;\n\
    \    for (int i = 0; i < mx; i++) {\n      hm.emplace(key[i], val[i]);\n     \
    \ m.emplace(key[i], val[i]);\n      same_map<HM, M, Key>(hm, m, mx);\n      same_map<const\
    \ HM, M, Key>(hm, m, mx);\n    }\n    assert(hm.cap == cap);\n  }\n}\n\ntemplate\
    \ <typename Key, typename Val = int>\nvoid test() {\n  stress_test<Key, Val>(1,\
    \ 100);\n  stress_test<Key, Val>(2, 100);\n  stress_test<Key, Val>(4, 100);\n\
    \  stress_test<Key, Val>(8, 100);\n  stress_test<Key, Val>(16, 100);\n  stress_test<Key,\
    \ Val>(32, 10);\n  stress_test<Key, Val>(64, 10);\n  stress_test<Key, Val>(128,\
    \ 3);\n  stress_test<Key, Val>(256, 3);\n}\n\n}  // namespace HashMapTest\n\n\
    int main() {\n  HashMapTest::test<int, int>();\n  HashMapTest::test<long long,\
    \ int>();\n  HashMapTest::test<pair<int, int>, int>();\n  HashMapTest::test<pair<long\
    \ long, int>, int>();\n  HashMapTest::test<pair<int, long long>, int>();\n  HashMapTest::test<pair<long\
    \ long, long long>, int>();\n\n  int64_t a, b;\n  cin >> a >> b;\n  cout << (a\
    \ + b) << endl;\n}\n"
  dependsOn:
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/hashmap.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 20:13:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/hashmap.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/hashmap.test.cpp
- /verify/verify/verify-unit-test/hashmap.test.cpp.html
title: verify/verify-unit-test/hashmap.test.cpp
---
