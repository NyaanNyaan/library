---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':question:'
    path: hashmap/hashmap-base.hpp
    title: hashmap/hashmap-base.hpp
  - icon: ':question:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':question:'
    path: hashmap/hashset.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8(\u96C6\u5408)"
  - icon: ':question:'
    path: template/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/debug.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"competitive-template.hpp\"\
    \n#pragma region kyopro_template\n#define Nyaan_template\n#include <immintrin.h>\n\
    #include <bits/stdc++.h>\n#define pb push_back\n#define eb emplace_back\n#define\
    \ fi first\n#define se second\n#define each(x, v) for (auto &x : v)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define sz(v) ((int)(v).size())\n#define mem(a, val)\
    \ memset(a, val, sizeof(a))\n#define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inl(...)         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define\
    \ inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)\
    \                           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\
    \n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)  \
    \                      \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n  \
    \  in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)  \
    \                   \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i], v[i]);             \\\n  }\n#define rep(i, N) for (long long i =\
    \ 0; i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define die(...) \
    \     \\\n  do {                \\\n    out(__VA_ARGS__); \\\n    return;    \
    \       \\\n  } while (0)\nusing namespace std;\nusing ll = long long;\ntemplate\
    \ <class T>\nusing V = vector<T>;\nusing vi = vector<int>;\nusing vl = vector<long\
    \ long>;\nusing vvi = vector<vector<int>>;\nusing vd = V<double>;\nusing vs =\
    \ V<string>;\nusing vvl = vector<vector<long long>>;\nusing P = pair<long long,\
    \ long long>;\nusing vp = vector<P>;\nusing pii = pair<int, int>;\nusing vpi =\
    \ vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\nconstexpr long long\
    \ infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\ninline bool amin(T\
    \ &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename\
    \ T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true)\
    \ : false;\n}\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return\
    \ os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"hashmap/hashmap-base.hpp\"\
    \nusing namespace std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\
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
    \ docs/hashmap/hashmap.md\n**/\n#line 2 \"hashmap/hashset.hpp\"\n\ntemplate <typename\
    \ Key>\nstruct HashSet : HashMapImpl::HashMapBase<Key, Key> {\n  using HashMapImpl::HashMapBase<Key,\
    \ Key>::HashMapBase;\n};\n\n/* \n * @brief \u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\
    \u30C8(\u96C6\u5408)\n * @docs docs/hashmap/hashset.md\n**/\n#line 1 \"template/debug.hpp\"\
    \nnamespace DebugImpl {\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>*\
    \ = nullptr) {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \" ]\" : \", \");\n  }\n}\n\
    \ntemplate <typename T, typename U>\nvoid dump(const pair<T, U>& t) {\n  cerr\
    \ << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n  cerr <<\
    \ \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>& t) {\n \
    \ cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \" ]\" : \", \");\n  }\n}\n\nvoid trace() {\
    \ cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid trace(Head&&\
    \ head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n  if (sizeof...(tail)\
    \ != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n}\n\n}  // namespace\
    \ DebugImpl\n\nusing DebugImpl::trace;\n\n#ifdef NyaanDebug\n#define trc(...)\
    \                            \\\n  do {                                      \\\
    \n    cerr << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n\n/**\n * @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u30C0\u30F3\u30D7\u95A2\u6570\n */\n#line 7 \"\
    verify/verify-unit-test/debug.test.cpp\"\n\nvoid test() {\n  // Integral\n  {\n\
    \    trace(1, 2, 3);\n    trace(inf, -inf, infLL);\n    trace(-infLL, 1001001000,\
    \ 1LL << 61);\n  }\n  // pair\n  {\n    pair<int, int> p1{1, 2};\n    pair<pair<int,\
    \ int>, int> p2{p1, 3};\n    pair<vector<int>, int> p3{{1, 2}, 3};\n    trace(p1,\
    \ p2, p3);\n  }\n  // Container\n  {\n    vector<int> vc{1, inf};\n    set<int>\
    \ st{2, 3};\n    array<int, 3> ar{{1, 2, 3}};\n    trace(vc, st, ar);\n  }\n \
    \ // Dict\n  {\n    map<int, int> m;\n    m[0] = 1, m[1] = 2;\n    trace(m);\n\
    \  }\n  // Native array\n  {\n    int a[] = {1, 2, 3, 4, 5};\n    trace(make_pair(a,\
    \ 2), make_pair(a + 3, 2));\n  }\n  // string, char\n  {\n    char c = 'a';\n\
    \    string s = \"abc\";\n    trace(c, s);\n  }\n  // other\n  {\n    vector<pair<int,\
    \ int>> v;\n    v.push_back({0, 1});\n    v.push_back({2, 3});\n    trace(v);\n\
    \    vector<vector<int>> a(2);\n    a[0] = vector<int>{0, 1};\n    a[1] = vector<int>{2,\
    \ 3};\n    trace(a);\n    vector<vector<vector<int>>> b(2);\n    b[0] = b[1] =\
    \ a;\n    trace(b);\n  }\n  // original structure\n  {\n    HashSet<int> st;\n\
    \    st.insert(2);\n    st.insert(3);\n    HashMap<int, int> m;\n    m[0] = 1,\
    \ m[1] = 2;\n    trace(st, m);\n  }\n  // cv qualifier\n  {\n    int a0 = 0;\n\
    \    const int a1 = 1;\n    int& a2 = a0;\n    const int& a3 = a1;\n    trace(a0,\
    \ a1, a2, a3);\n  }\n}\n\nvoid solve() {\n  test();\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../competitive-template.hpp\"\n#include \"../../hashmap/hashmap.hpp\"\n#include\
    \ \"../../hashmap/hashset.hpp\"\n#include \"../../template/debug.hpp\"\n\nvoid\
    \ test() {\n  // Integral\n  {\n    trace(1, 2, 3);\n    trace(inf, -inf, infLL);\n\
    \    trace(-infLL, 1001001000, 1LL << 61);\n  }\n  // pair\n  {\n    pair<int,\
    \ int> p1{1, 2};\n    pair<pair<int, int>, int> p2{p1, 3};\n    pair<vector<int>,\
    \ int> p3{{1, 2}, 3};\n    trace(p1, p2, p3);\n  }\n  // Container\n  {\n    vector<int>\
    \ vc{1, inf};\n    set<int> st{2, 3};\n    array<int, 3> ar{{1, 2, 3}};\n    trace(vc,\
    \ st, ar);\n  }\n  // Dict\n  {\n    map<int, int> m;\n    m[0] = 1, m[1] = 2;\n\
    \    trace(m);\n  }\n  // Native array\n  {\n    int a[] = {1, 2, 3, 4, 5};\n\
    \    trace(make_pair(a, 2), make_pair(a + 3, 2));\n  }\n  // string, char\n  {\n\
    \    char c = 'a';\n    string s = \"abc\";\n    trace(c, s);\n  }\n  // other\n\
    \  {\n    vector<pair<int, int>> v;\n    v.push_back({0, 1});\n    v.push_back({2,\
    \ 3});\n    trace(v);\n    vector<vector<int>> a(2);\n    a[0] = vector<int>{0,\
    \ 1};\n    a[1] = vector<int>{2, 3};\n    trace(a);\n    vector<vector<vector<int>>>\
    \ b(2);\n    b[0] = b[1] = a;\n    trace(b);\n  }\n  // original structure\n \
    \ {\n    HashSet<int> st;\n    st.insert(2);\n    st.insert(3);\n    HashMap<int,\
    \ int> m;\n    m[0] = 1, m[1] = 2;\n    trace(st, m);\n  }\n  // cv qualifier\n\
    \  {\n    int a0 = 0;\n    const int a1 = 1;\n    int& a2 = a0;\n    const int&\
    \ a3 = a1;\n    trace(a0, a1, a2, a3);\n  }\n}\n\nvoid solve() {\n  test();\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - competitive-template.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  - hashmap/hashset.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/debug.test.cpp
  requiredBy: []
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-unit-test/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/debug.test.cpp
- /verify/verify/verify-unit-test/debug.test.cpp.html
title: verify/verify-unit-test/debug.test.cpp
---
