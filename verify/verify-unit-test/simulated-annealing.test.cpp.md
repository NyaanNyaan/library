---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: marathon/log_table.hpp
    title: marathon/log_table.hpp
  - icon: ':heavy_check_mark:'
    path: marathon/simulated-annealing.hpp
    title: Simulated Annealing
  - icon: ':question:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':question:'
    path: misc/timer.hpp
    title: misc/timer.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/simulated-annealing.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate\
    \ <typename U, typename = void>\nstruct is_specialize : false_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<\n    U, typename conditional<false, typename\
    \ U::iterator, void>::type>\n    : true_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, decltype(U::first), void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value,\
    \ void>> : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid\
    \ dump(const string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t\
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
    \ {\n      if (t == -Nyaan::infLL) res = \"-inf\";\n    }\n  }\n  if (res.empty())\
    \ res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename T, typename U>\n\
    void dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const pair<T*,\
    \ int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename\
    \ T::iterator>::value>* = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin();\
    \ it != t.end();) {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \"\
    , \");\n  }\n  cerr << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const\
    \ pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n \
    \ dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++)\
    \ {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1 ? \"\" : \", \");\n\
    \  }\n  cerr << \" ]\";\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/simulated-annealing.test.cpp\"\
    \n//\n#line 2 \"marathon/simulated-annealing.hpp\"\n\n#line 2 \"misc/timer.hpp\"\
    \n\n#line 4 \"misc/timer.hpp\"\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n#line 2 \"marathon/log_table.hpp\"\n\nstruct log_table {\n  double l[65536];\n\
    \  constexpr log_table() : l() {\n    unsigned long long x = 88172645463325252ULL;\n\
    \    double log_u64max = log(2) * 64;\n    for (int i = 0; i < 65536; i++) {\n\
    \      x = x ^ (x << 7);\n      x = x ^ (x >> 9);\n      l[i] = log(double(x))\
    \ - log_u64max;\n    }\n  }\n};\n#line 5 \"marathon/simulated-annealing.hpp\"\n\
    \ntemplate <typename Input, typename State, typename Diff>\nstruct Simulated_Annealing\
    \ {\n private:\n  log_table rand_log;\n  double end_time, inv_time, cur_time;\n\
    \  double start_temp, diff_temp, cur_temp;\n  Timer *timer;\n\n  void set_time(double\
    \ start_time) {\n    inv_time = 1.0 / (end_time - start_time);\n    cur_time =\
    \ start_time;\n  }\n  void set_temp() {\n    cur_temp = max(0.0, start_temp -\
    \ cur_time * diff_temp * inv_time);\n  }\n\n public:\n  Simulated_Annealing(double\
    \ _end_time, double _start_temp, double _end_temp,\n                      Timer\
    \ *_timer = nullptr)\n      : end_time(_end_time),\n        start_temp(_start_temp),\n\
    \        diff_temp(_start_temp - _end_temp),\n        timer(_timer) {\n    if\
    \ (timer == nullptr) timer = new Timer;\n    set_time(timer->elapsed());\n   \
    \ set_temp();\n  }\n\n  void reset() { timer->reset(); }\n\n  State run(const\
    \ Input &input) {\n    State st(input);\n    for (int iter = 0;; iter++) {\n \
    \     if ((iter & 0xFF) == 0) {\n        st.dump();\n        if ((cur_time = timer->elapsed())\
    \ > end_time) break;\n        set_temp();\n      }\n      Diff d(st);\n      if\
    \ (d.diff() > cur_temp * rand_log.l[iter & 0xFFFF]) {\n        st.update(d);\n\
    \      } else {\n        st.undo(d);\n      }\n    }\n    return st;\n  }\n\n\
    \  decltype(State().score()) test(const vector<string> &filenames) {\n    decltype(State().score())\
    \ scores = 0.0;\n    for (auto &filename : filenames) {\n      timer->reset();\n\
    \      ifstream is(filename);\n      cin.rdbuf(is.rdbuf());\n      Input input;\n\
    \      input.scan();\n      auto res = run(input);\n      scores += res.score();\n\
    \    }\n    return scores;\n  }\n};\n\n/**\n * @brief Simulated Annealing\n *\
    \ @docs docs/marathon/simulated-annealing.md\n */\n#line 2 \"misc/rng.hpp\"\n\n\
    namespace my_rand {\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    \n// [0, 2^64 - 1)\nu64 rng() {\n  static u64 _x =\n      u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \              chrono::high_resolution_clock::now().time_since_epoch())\n    \
    \          .count()) *\n      10150724397891781847ULL;\n  _x ^= _x << 7;\n  return\
    \ _x ^= _x >> 9;\n}\n\n// [l, r]\ni64 rng(i64 l, i64 r) {\n  assert(l <= r);\n\
    \  return l + rng() % (r - l + 1);\n}\n\n// [l, r)\ni64 randint(i64 l, i64 r)\
    \ {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<i64> randset(i64 l, i64 r, i64 n) {\n\
    \  assert(l <= r && n <= r - l);\n  unordered_set<i64> s;\n  for (i64 i = n; i;\
    \ --i) {\n    i64 m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m\
    \ = r - i;\n    s.insert(m);\n  }\n  vector<i64> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n// [0.0, 1.0)\ndouble rnd() { return rng() * 5.42101086242752217004e-20;\
    \ }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);\n}\n\n}  // namespace\
    \ my_rand\n\nusing my_rand::randint;\nusing my_rand::randset;\nusing my_rand::randshf;\n\
    using my_rand::rnd;\nusing my_rand::rng;\n#line 7 \"verify/verify-unit-test/simulated-annealing.test.cpp\"\
    \n\nusing namespace Nyaan;\n\nusing score_t = double;\nstruct Input {\n  int N;\n\
    \  V<P<double, double>> ps;\n  Input() = default;\n  void scan() {\n    in(N);\n\
    \    ps.resize(N);\n    in(ps);\n  }\n};\n\nstruct State {\n  int N;\n  V<P<double,\
    \ double>> ps;\n  vi used;\n  P<double, double> res;\n\n  struct Diff {\n    const\
    \ State *st;\n    int n;\n    P<double, double> res;\n    double d;\n    Diff()\
    \ = default;\n    Diff(const State &state) : st(&state), res(state.res) {\n  \
    \    n = rng() % state.N;\n      if (state.used[n]) {\n        res -= state.ps[n];\n\
    \      } else {\n        res += state.ps[n];\n      }\n      d = res.first * res.first\
    \ + res.second * res.second - state.score();\n    }\n    double diff() const {\
    \ return d; }\n  };\n\n  State() = default;\n  State(const Input &input) : N(input.N),\
    \ ps(input.ps) {\n    used.resize(N);\n    rep(i, N) used[i] = rng() & 1;\n  \
    \  res = P<double, double>(0, 0);\n    rep(i, N) {\n      if (used[i]) res +=\
    \ ps[i];\n    }\n  }\n  void update(const Diff &b) {\n    res = b.res;\n    used[b.n]\
    \ ^= 1;\n  }\n  void undo(const Diff &) {}\n  score_t score() const {\n    return\
    \ res.first * res.first + res.second * res.second;\n  }\n\n  bool operator>(const\
    \ State &s) { return score() > s.score(); };\n  void dump() {}\n};\nusing SA =\
    \ Simulated_Annealing<Input, State, typename State::Diff>;\n\nusing pd = Nyaan::P<double,\
    \ double>;\n\ndouble yakinamashi(int n, V<pd> ps) {\n  Input ip;\n  ip.N = n;\n\
    \  ip.ps = ps;\n  SA sa(10, 1000, 1);\n  State ans{};\n  rep(i, 10) {\n    sa.reset();\n\
    \    auto s = sa.run(ip);\n    if (s > ans) swap(ans, s);\n  }\n  return sqrt(ans.score());\n\
    }\n\ndouble argsort(int N, V<pd> v) {\n  repr(i, N) {\n    if (v[i] == pd(0, 0))\
    \ v.erase(v.begin() + i);\n  }\n  N = sz(v);\n  sort(all(v), [](pd a, pd b) {\n\
    \    return atan2(double(a.second), double(a.first)) <\n           atan2(double(b.second),\
    \ double(b.first));\n  });\n  double ans = 0;\n  rep(i, N) rep(j, N) {\n    double\
    \ cx = 0, cy = 0;\n    for (int ii = i;; ii = (ii + 1) % N) {\n      cx += v[ii].first,\
    \ cy += v[ii].second;\n      if (ii == j) break;\n    }\n    amax(ans, sqrt(cx\
    \ * cx + cy * cy));\n  }\n  return ans;\n}\n\nvoid Nyaan::solve() {\n  rep(i,\
    \ 20) {\n    int n = 100;\n    V<pd> v(n);\n    rep(j, n) v[j] = pd(randint(0,\
    \ 2 * TEN(6) + 1) + TEN(6),\n                        randint(0, 2 * TEN(6) + 1)\
    \ + TEN(6));\n    auto ans1 = argsort(n, v);\n    auto ans2 = yakinamashi(n, v);\n\
    \    cerr << abs(ans1 - ans2) << endl;\n  }\n\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../marathon/simulated-annealing.hpp\"\
    \n#include \"../../misc/rng.hpp\"\n\nusing namespace Nyaan;\n\nusing score_t =\
    \ double;\nstruct Input {\n  int N;\n  V<P<double, double>> ps;\n  Input() = default;\n\
    \  void scan() {\n    in(N);\n    ps.resize(N);\n    in(ps);\n  }\n};\n\nstruct\
    \ State {\n  int N;\n  V<P<double, double>> ps;\n  vi used;\n  P<double, double>\
    \ res;\n\n  struct Diff {\n    const State *st;\n    int n;\n    P<double, double>\
    \ res;\n    double d;\n    Diff() = default;\n    Diff(const State &state) : st(&state),\
    \ res(state.res) {\n      n = rng() % state.N;\n      if (state.used[n]) {\n \
    \       res -= state.ps[n];\n      } else {\n        res += state.ps[n];\n   \
    \   }\n      d = res.first * res.first + res.second * res.second - state.score();\n\
    \    }\n    double diff() const { return d; }\n  };\n\n  State() = default;\n\
    \  State(const Input &input) : N(input.N), ps(input.ps) {\n    used.resize(N);\n\
    \    rep(i, N) used[i] = rng() & 1;\n    res = P<double, double>(0, 0);\n    rep(i,\
    \ N) {\n      if (used[i]) res += ps[i];\n    }\n  }\n  void update(const Diff\
    \ &b) {\n    res = b.res;\n    used[b.n] ^= 1;\n  }\n  void undo(const Diff &)\
    \ {}\n  score_t score() const {\n    return res.first * res.first + res.second\
    \ * res.second;\n  }\n\n  bool operator>(const State &s) { return score() > s.score();\
    \ };\n  void dump() {}\n};\nusing SA = Simulated_Annealing<Input, State, typename\
    \ State::Diff>;\n\nusing pd = Nyaan::P<double, double>;\n\ndouble yakinamashi(int\
    \ n, V<pd> ps) {\n  Input ip;\n  ip.N = n;\n  ip.ps = ps;\n  SA sa(10, 1000, 1);\n\
    \  State ans{};\n  rep(i, 10) {\n    sa.reset();\n    auto s = sa.run(ip);\n \
    \   if (s > ans) swap(ans, s);\n  }\n  return sqrt(ans.score());\n}\n\ndouble\
    \ argsort(int N, V<pd> v) {\n  repr(i, N) {\n    if (v[i] == pd(0, 0)) v.erase(v.begin()\
    \ + i);\n  }\n  N = sz(v);\n  sort(all(v), [](pd a, pd b) {\n    return atan2(double(a.second),\
    \ double(a.first)) <\n           atan2(double(b.second), double(b.first));\n \
    \ });\n  double ans = 0;\n  rep(i, N) rep(j, N) {\n    double cx = 0, cy = 0;\n\
    \    for (int ii = i;; ii = (ii + 1) % N) {\n      cx += v[ii].first, cy += v[ii].second;\n\
    \      if (ii == j) break;\n    }\n    amax(ans, sqrt(cx * cx + cy * cy));\n \
    \ }\n  return ans;\n}\n\nvoid Nyaan::solve() {\n  rep(i, 20) {\n    int n = 100;\n\
    \    V<pd> v(n);\n    rep(j, n) v[j] = pd(randint(0, 2 * TEN(6) + 1) + TEN(6),\n\
    \                        randint(0, 2 * TEN(6) + 1) + TEN(6));\n    auto ans1\
    \ = argsort(n, v);\n    auto ans2 = yakinamashi(n, v);\n    cerr << abs(ans1 -\
    \ ans2) << endl;\n  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - marathon/simulated-annealing.hpp
  - misc/timer.hpp
  - marathon/log_table.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/simulated-annealing.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/simulated-annealing.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/simulated-annealing.test.cpp
- /verify/verify/verify-unit-test/simulated-annealing.test.cpp.html
title: verify/verify-unit-test/simulated-annealing.test.cpp
---
