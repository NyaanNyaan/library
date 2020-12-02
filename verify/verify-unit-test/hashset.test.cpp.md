---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: hashmap/hashmap-base.hpp
    title: hashmap/hashmap-base.hpp
  - icon: ':question:'
    path: hashmap/hashset.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8(\u96C6\u5408)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/hashset.test.cpp\"\n#define PROBLEM\
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
    \n}  // namespace HashMapImpl\n#line 2 \"hashmap/hashset.hpp\"\n\ntemplate <typename\
    \ Key>\nstruct HashSet : HashMapImpl::HashMapBase<Key, Key> {\n  using HashMapImpl::HashMapBase<Key,\
    \ Key>::HashMapBase;\n};\n\n/* \n * @brief \u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\
    \u30C8(\u96C6\u5408)\n * @docs docs/hashmap/hashset.md\n**/\n#line 6 \"verify/verify-unit-test/hashset.test.cpp\"\
    \nuint64_t rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n// [l, r)\nint64_t\
    \ randint(int64_t l, int64_t r) {\n  assert(l < r);\n  return l + rng() % (r -\
    \ l);\n}\n\nnamespace HashSetTest {\n\ntemplate <typename HS, typename Data_t>\n\
    void same_set(HS& hs, set<Data_t>& us, int mx) {\n  assert(mx > 0);\n  // iterator\n\
    \  {\n    set<Data_t> buf;\n    for (auto& x : hs) buf.insert(x);\n    assert(buf\
    \ == us && \"The range-based for statement\");\n  }\n  // itr::operator++(), itr::operator++(int)\n\
    \  {\n    set<Data_t> buf;\n    for (auto it = hs.begin(); it != hs.end();) {\n\
    \      buf.insert(*it);\n\n      auto oit = it;\n      assert(oit == it++ && \"\
    itr::operator++(int)\");\n      ++oit;\n      assert(oit == it && \"itr::operator++()\"\
    );\n    }\n    assert(buf == us && \"itr::operator++()\");\n  }\n\n  // itr::operator--(),\
    \ itr::operator--(int)\n  {\n    set<Data_t> buf;\n    for (auto it = hs.end();\
    \ it != hs.begin();) {\n      auto oit = it;\n      assert(oit == it-- && \"itr::operator--(int)\"\
    );\n      --oit;\n      assert(oit == it && \"itr::operator--()\");\n\n      buf.insert(*it);\n\
    \    }\n    assert(buf == us && \"itr::operator--()\");\n  }\n\n  // begin(*this),\
    \ end(*this)\n  assert(begin(hs) == hs.begin() && \"begin(*this)\");\n  assert(end(hs)\
    \ == hs.end() && \"end(*this)\");\n\n  // ensure empty space in hash table\n \
    \ {\n    uint32_t s = 0;\n    for (uint32_t i = 0; i < hs.cap; ++i) s += hs.flag[i];\n\
    \    assert(s != hs.cap && \"hash table is full!\");\n  }\n\n  // find, contain\n\
    \  if constexpr (is_integral<Data_t>::value) {\n    for (Data_t k = 0; k < mx;\
    \ ++k) {\n      auto flg1 = hs.find(k) != hs.end();\n      auto flg2 = us.find(k)\
    \ != us.end();\n      auto flg3 = hs.contain(k);\n      assert(flg1 == flg2 &&\
    \ \"find(k)\");\n      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  } else\
    \ {\n    for (int t = 0; t < 2 * mx; ++t) {\n      Data_t k{rng() % mx, rng()\
    \ % mx};\n      auto flg1 = hs.find(k) != hs.end();\n      auto flg2 = us.find(k)\
    \ != us.end();\n      auto flg3 = hs.contain(k);\n      assert(flg1 == flg2 &&\
    \ \"find(k)\");\n      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  }\n\n\
    \  // empty\n  assert(hs.empty() == us.empty() && \"empty()\");\n  // size\n \
    \ assert(hs.size() == (int)us.size() && \"size()\");\n}\n\n#include <cxxabi.h>\n\
    string get_name(const type_info& id) {\n  int stat;\n  char* name = abi::__cxa_demangle(id.name(),\
    \ 0, 0, &stat);\n  assert(name != NULL && stat == 0);\n  string res = string(name);\n\
    \  free(name);\n  return res;\n}\n\ntemplate <typename T>\nvoid stress_test(int\
    \ mx, int loop_time) {\n  cerr << \"type : \" << get_name(typeid(T)) << \", \"\
    ;\n  cerr << \"loop : \" << loop_time << \", \";\n  cerr << \"max : \" << mx <<\
    \ endl;\n  HashSet<T> hs;\n  set<T> us;\n  vector<T> ord;\n  if constexpr (is_integral<T>::value)\
    \ {\n    ord.resize(mx);\n    iota(begin(ord), end(ord), mx);\n  } else {\n  \
    \  set<T> s;\n    while ((int)s.size() < mx) s.insert(T{rng() % mx, rng() % mx});\n\
    \    for (auto& x : s) ord.push_back(x);\n  }\n\n  mt19937_64 mt(rng());\n\n \
    \ // insert, erase\n  for (int _ = 0; _ < loop_time; _++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n\
    \      same_set<HashSet<T>, T>(hs, us, mx);\n      same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    }\n    assert(hs.size() == mx && \"insert(k)\");\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.erase(i);\n      us.erase(i);\n\
    \      same_set<HashSet<T>, T>(hs, us, mx);\n      same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    }\n    assert(hs.size() == 0 && \"erase(k)\");\n  }\n\n\
    \  // clear\n  for (int _ = 0; _ < loop_time; _++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n\
    \    }\n    same_set<HashSet<T>, T>(hs, us, mx);\n    same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    assert(hs.size() == mx && \"clear()\");\n    hs.clear();\n\
    \    us.clear();\n    same_set<HashSet<T>, T>(hs, us, mx);\n    same_set<const\
    \ HashSet<T>, T>(hs, us, mx);\n    assert(hs.size() == 0 && \"clear()\");\n  }\n\
    \n  // reserve\n  for (int _ = 0; _ < loop_time; _++) {\n    hs.reserve(mx);\n\
    \    uint32_t pcap = hs.cap;\n    shuffle(begin(ord), end(ord), mt);\n    for\
    \ (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n    }\n    same_set<HashSet<T>,\
    \ T>(hs, us, mx);\n    same_set<const HashSet<T>, T>(hs, us, mx);\n    assert(hs.size()\
    \ == mx && \"reserve()\");\n    assert(hs.cap == pcap && \"reserve()\");\n   \
    \ hs.clear();\n    us.clear();\n    same_set<HashSet<T>, T>(hs, us, mx);\n   \
    \ same_set<const HashSet<T>, T>(hs, us, mx);\n    assert(hs.size() == 0 && \"\
    reserve()\");\n  }\n}\n\ntemplate <typename T>\nvoid unit_test() {\n  stress_test<T>(1,\
    \ 1000);\n  stress_test<T>(2, 1000);\n  stress_test<T>(4, 1000);\n  stress_test<T>(8,\
    \ 1000);\n  stress_test<T>(16, 100);\n  stress_test<T>(64, 10);\n  stress_test<T>(256,\
    \ 5);\n}\n\n}  // namespace HashSetTest\n\nint main() {\n  HashSetTest::unit_test<int>();\n\
    \  HashSetTest::unit_test<int64_t>();\n  HashSetTest::unit_test<pair<int,int>>();\n\
    \  int64_t a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../hashmap/hashset.hpp\"\nuint64_t rng()\
    \ {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n// [l, r)\nint64_t\
    \ randint(int64_t l, int64_t r) {\n  assert(l < r);\n  return l + rng() % (r -\
    \ l);\n}\n\nnamespace HashSetTest {\n\ntemplate <typename HS, typename Data_t>\n\
    void same_set(HS& hs, set<Data_t>& us, int mx) {\n  assert(mx > 0);\n  // iterator\n\
    \  {\n    set<Data_t> buf;\n    for (auto& x : hs) buf.insert(x);\n    assert(buf\
    \ == us && \"The range-based for statement\");\n  }\n  // itr::operator++(), itr::operator++(int)\n\
    \  {\n    set<Data_t> buf;\n    for (auto it = hs.begin(); it != hs.end();) {\n\
    \      buf.insert(*it);\n\n      auto oit = it;\n      assert(oit == it++ && \"\
    itr::operator++(int)\");\n      ++oit;\n      assert(oit == it && \"itr::operator++()\"\
    );\n    }\n    assert(buf == us && \"itr::operator++()\");\n  }\n\n  // itr::operator--(),\
    \ itr::operator--(int)\n  {\n    set<Data_t> buf;\n    for (auto it = hs.end();\
    \ it != hs.begin();) {\n      auto oit = it;\n      assert(oit == it-- && \"itr::operator--(int)\"\
    );\n      --oit;\n      assert(oit == it && \"itr::operator--()\");\n\n      buf.insert(*it);\n\
    \    }\n    assert(buf == us && \"itr::operator--()\");\n  }\n\n  // begin(*this),\
    \ end(*this)\n  assert(begin(hs) == hs.begin() && \"begin(*this)\");\n  assert(end(hs)\
    \ == hs.end() && \"end(*this)\");\n\n  // ensure empty space in hash table\n \
    \ {\n    uint32_t s = 0;\n    for (uint32_t i = 0; i < hs.cap; ++i) s += hs.flag[i];\n\
    \    assert(s != hs.cap && \"hash table is full!\");\n  }\n\n  // find, contain\n\
    \  if constexpr (is_integral<Data_t>::value) {\n    for (Data_t k = 0; k < mx;\
    \ ++k) {\n      auto flg1 = hs.find(k) != hs.end();\n      auto flg2 = us.find(k)\
    \ != us.end();\n      auto flg3 = hs.contain(k);\n      assert(flg1 == flg2 &&\
    \ \"find(k)\");\n      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  } else\
    \ {\n    for (int t = 0; t < 2 * mx; ++t) {\n      Data_t k{rng() % mx, rng()\
    \ % mx};\n      auto flg1 = hs.find(k) != hs.end();\n      auto flg2 = us.find(k)\
    \ != us.end();\n      auto flg3 = hs.contain(k);\n      assert(flg1 == flg2 &&\
    \ \"find(k)\");\n      assert(flg1 == flg3 && \"contain(k)\");\n    }\n  }\n\n\
    \  // empty\n  assert(hs.empty() == us.empty() && \"empty()\");\n  // size\n \
    \ assert(hs.size() == (int)us.size() && \"size()\");\n}\n\n#include <cxxabi.h>\n\
    string get_name(const type_info& id) {\n  int stat;\n  char* name = abi::__cxa_demangle(id.name(),\
    \ 0, 0, &stat);\n  assert(name != NULL && stat == 0);\n  string res = string(name);\n\
    \  free(name);\n  return res;\n}\n\ntemplate <typename T>\nvoid stress_test(int\
    \ mx, int loop_time) {\n  cerr << \"type : \" << get_name(typeid(T)) << \", \"\
    ;\n  cerr << \"loop : \" << loop_time << \", \";\n  cerr << \"max : \" << mx <<\
    \ endl;\n  HashSet<T> hs;\n  set<T> us;\n  vector<T> ord;\n  if constexpr (is_integral<T>::value)\
    \ {\n    ord.resize(mx);\n    iota(begin(ord), end(ord), mx);\n  } else {\n  \
    \  set<T> s;\n    while ((int)s.size() < mx) s.insert(T{rng() % mx, rng() % mx});\n\
    \    for (auto& x : s) ord.push_back(x);\n  }\n\n  mt19937_64 mt(rng());\n\n \
    \ // insert, erase\n  for (int _ = 0; _ < loop_time; _++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n\
    \      same_set<HashSet<T>, T>(hs, us, mx);\n      same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    }\n    assert(hs.size() == mx && \"insert(k)\");\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.erase(i);\n      us.erase(i);\n\
    \      same_set<HashSet<T>, T>(hs, us, mx);\n      same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    }\n    assert(hs.size() == 0 && \"erase(k)\");\n  }\n\n\
    \  // clear\n  for (int _ = 0; _ < loop_time; _++) {\n    shuffle(begin(ord),\
    \ end(ord), mt);\n    for (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n\
    \    }\n    same_set<HashSet<T>, T>(hs, us, mx);\n    same_set<const HashSet<T>,\
    \ T>(hs, us, mx);\n    assert(hs.size() == mx && \"clear()\");\n    hs.clear();\n\
    \    us.clear();\n    same_set<HashSet<T>, T>(hs, us, mx);\n    same_set<const\
    \ HashSet<T>, T>(hs, us, mx);\n    assert(hs.size() == 0 && \"clear()\");\n  }\n\
    \n  // reserve\n  for (int _ = 0; _ < loop_time; _++) {\n    hs.reserve(mx);\n\
    \    uint32_t pcap = hs.cap;\n    shuffle(begin(ord), end(ord), mt);\n    for\
    \ (auto& i : ord) {\n      hs.insert(i);\n      us.insert(i);\n    }\n    same_set<HashSet<T>,\
    \ T>(hs, us, mx);\n    same_set<const HashSet<T>, T>(hs, us, mx);\n    assert(hs.size()\
    \ == mx && \"reserve()\");\n    assert(hs.cap == pcap && \"reserve()\");\n   \
    \ hs.clear();\n    us.clear();\n    same_set<HashSet<T>, T>(hs, us, mx);\n   \
    \ same_set<const HashSet<T>, T>(hs, us, mx);\n    assert(hs.size() == 0 && \"\
    reserve()\");\n  }\n}\n\ntemplate <typename T>\nvoid unit_test() {\n  stress_test<T>(1,\
    \ 1000);\n  stress_test<T>(2, 1000);\n  stress_test<T>(4, 1000);\n  stress_test<T>(8,\
    \ 1000);\n  stress_test<T>(16, 100);\n  stress_test<T>(64, 10);\n  stress_test<T>(256,\
    \ 5);\n}\n\n}  // namespace HashSetTest\n\nint main() {\n  HashSetTest::unit_test<int>();\n\
    \  HashSetTest::unit_test<int64_t>();\n  HashSetTest::unit_test<pair<int,int>>();\n\
    \  int64_t a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  dependsOn:
  - hashmap/hashset.hpp
  - hashmap/hashmap-base.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/hashset.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 20:13:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/hashset.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/hashset.test.cpp
- /verify/verify/verify-unit-test/hashset.test.cpp.html
title: verify/verify-unit-test/hashset.test.cpp
---
