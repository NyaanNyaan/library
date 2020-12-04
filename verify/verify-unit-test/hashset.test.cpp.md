---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: hashmap/hashmap-base.hpp
    title: hashmap/hashmap-base.hpp
  - icon: ':x:'
    path: hashmap/hashset.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8(\u96C6\u5408)"
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/hashset.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <csetjmp>\n#include\
    \ <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include\
    \ <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\ntemplate <typename T, size_t N>\nvoid mem(T (&a)[N], int c) {\n\
    \  memset(a, c, sizeof(T) * N);\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate\
    \ <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ?\
    \ (x = y, true) : false;\n}\n\ntemplate <typename T>\nint lb(const vector<T> &v,\
    \ const T &a) {\n  return lower_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint ub(const vector<T> &v, const T &a) {\n  return upper_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\n\nconstexpr long long TEN(int n) {\n  long long ret\
    \ = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return\
    \ ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const T &t, const\
    \ U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const\
    \ vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev)\
    \ {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i +\
    \ 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i]\
    \ + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const\
    \ vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\n\
    vector<T> reord(const vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n\
    \  vector<T> ret(N);\n  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return\
    \ ret;\n};\n\ntemplate <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T>\
    \ ret(N);\n  iota(begin(ret), end(ret), 0);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<int> mkinv(vector<T> &v, int max_val = -1) {\n  if (max_val < (int)v.size())\
    \ max_val = v.size() - 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i =\
    \ 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace\
    \ Nyaan\n#line 70 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n#line 73 \"template/template.hpp\"\n\n// inout\n#line 1 \"\
    template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \"\
    \ \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return\
    \ is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \"\
    \ \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\n\
    template <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const\
    \ U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 76 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \", \");\n  }\n  cerr\
    \ << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n\
    \  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>&\
    \ t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \"\" : \", \");\n  }\n  cerr << \" ]\";\n}\n\
    \nvoid trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void trace(Head&& head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n \
    \ if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n#line 79 \"template/template.hpp\"\
    \n\n// macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x\
    \ : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n\
    #define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define\
    \ rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for (long long i =\
    \ (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long i = (a); (cond);\
    \ i++)\n#define enm(i, val, vec)                                  \\\n  for (long\
    \ long i = 0; i < (long long)(vec).size(); i++) \\\n    if (auto& val = vec[i];\
    \ false)                        \\\n      ;                                  \
    \                 \\\n    else\n\n#define ini(...)   \\\n  int __VA_ARGS__; \\\
    \n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s,\
    \ t)                           \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)\
    \                        \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)\
    \                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n   \
    \ in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)        \
    \     \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n \
    \   return;                  \\\n  } while (0)\n#line 82 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 4 \"verify/verify-unit-test/hashset.test.cpp\"\n\n\n#line 2 \"hashmap/hashmap-base.hpp\"\
    \n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\n\
    template <typename Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename\
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
    \u30C8(\u96C6\u5408)\n * @docs docs/hashmap/hashset.md\n**/\n#line 7 \"verify/verify-unit-test/hashset.test.cpp\"\
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
    \ 5);\n}\n\n}  // namespace HashSetTest\n\nvoid Nyaan::solve() {\n  HashSetTest::unit_test<int>();\n\
    \  HashSetTest::unit_test<int64_t>();\n  HashSetTest::unit_test<pair<int,int>>();\n\
    \  int64_t a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n\n\n#include \"../../hashmap/hashset.hpp\"\nuint64_t\
    \ rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \ 5);\n}\n\n}  // namespace HashSetTest\n\nvoid Nyaan::solve() {\n  HashSetTest::unit_test<int>();\n\
    \  HashSetTest::unit_test<int64_t>();\n  HashSetTest::unit_test<pair<int,int>>();\n\
    \  int64_t a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - hashmap/hashset.hpp
  - hashmap/hashmap-base.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/hashset.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-unit-test/hashset.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/hashset.test.cpp
- /verify/verify/verify-unit-test/hashset.test.cpp.html
title: verify/verify-unit-test/hashset.test.cpp
---
