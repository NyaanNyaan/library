---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#350dfa5f4985bc48300c39d2bca2b63d">verify/verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 17:31:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/graph-template.hpp.html">graph/graph-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/graph-utility.hpp.html">graph/graph-utility.hpp</a>
* :question: <a href="../../../library/misc/fastio.hpp.html">misc/fastio.hpp</a>
* :question: <a href="../../../library/modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>
* :heavy_check_mark: <a href="../../../library/segment-tree/segment-tree.hpp.html">segment-tree/segment-tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/tree/heavy-light-decomposition.hpp.html">tree/heavy-light-decomposition.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../competitive-template.hpp"
#include "../../graph/graph-utility.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  int N, Q;
  rd(N);
  rd(Q);
  V<mint> a(N), b(N);
  for (int i = 0; i < N; i++) {
    int buf;
    rd(buf);
    a[i] = buf;
    rd(buf);
    b[i] = buf;
  }
  vvi g(N);
  rep(_, N - 1) {
    int u, v;
    rd(u);
    rd(v);
    g[u].pb(v);
    g[v].pb(u);
  }
  HeavyLightDecomposition<vvi> hld(g);

  using P = pair<mint, mint>;
  auto mul = [](P a, P b) {
    return P{a.first * b.first, a.second * b.first + b.second};
  };
  auto fl = [&mul](P a, P b) { return mul(a, b); };
  auto fr = [&mul](P a, P b) { return mul(b, a); };
  SegmentTree<P, decltype(fl)> segl(N, fl, P{1, 0});
  SegmentTree<P, decltype(fr)> segr(N, fr, P{1, 0});
  rep(i, N) {
    segl.set(hld.in[i], P{a[i], b[i]});
    segr.set(hld.in[i], P{a[i], b[i]});
  }
  segl.build();
  segr.build();

  rep(_, Q) {
    int cmd, x, y, z;
    rd(cmd);
    rd(x);
    rd(y);
    rd(z);
    if (!cmd) {
      segl.update(hld.in[x], P{y, z});
      segr.update(hld.in[x], P{y, z});
    } else {
      P L{1, 0}, R{1, 0};
      auto f = [&](int u, int v, int le) {
        if (le) {
          if (u < v)
            L = mul(L, segl.query(u, v));
          else
            L = mul(L, segr.query(v, u));
        } else {
          if (u < v)
            R = mul(segl.query(u, v), R);
          else
            R = mul(segr.query(v, u), R);
        }
      };
      hld.uncommutable_node_query(x, y, f);
      P res = mul(L, R);
      wt((res.first * z + res.second).get());
      wt('\n');
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#line 1 "competitive-template.hpp"
#pragma region kyopro_template
#define Nyaan_template
#include <immintrin.h>
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define mem(a, val) memset(a, val, sizeof(a))
#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define inl(...)         \
  long long __VA_ARGS__; \
  in(__VA_ARGS__)
#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define inc(...)    \
  char __VA_ARGS__; \
  in(__VA_ARGS__)
#define in2(s, t)                           \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i]);                         \
  }
#define in3(s, t, u)                        \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i]);                   \
  }
#define in4(s, t, u, v)                     \
  for (int i = 0; i < (int)s.size(); i++) { \
    in(s[i], t[i], u[i], v[i]);             \
  }
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define die(...)      \
  do {                \
    out(__VA_ARGS__); \
    return;           \
  } while (0)
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vd = V<double>;
using vs = V<string>;
using vvl = vector<vector<long long>>;
using P = pair<long long, long long>;
using vp = vector<P>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;
constexpr int inf = 1001001001;
constexpr long long infLL = (1LL << 61) - 1;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename T, class... U>
void in(T &t, U &... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, const U &... u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}

#ifdef NyaanDebug
#define trc(...)                   \
  do {                             \
    cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__);          \
  } while (0)
#define trca(v, N)       \
  do {                   \
    cerr << #v << " = "; \
    array_out(v, N);     \
  } while (0)
#define trcc(v)                             \
  do {                                      \
    cerr << #v << " = {";                   \
    each(x, v) { cerr << " " << x << ","; } \
    cerr << "}" << endl;                    \
  } while (0)
template <typename T>
void _cout(const T &c) {
  cerr << c;
}
void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}
void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}
void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}
template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}
template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}
template <typename T>
void _cout(const vector<vector<T>> &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}
void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}
template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}
template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}
#else
#define trc(...)
#define trca(...)
#define trcc(...)
#endif

inline int popcnt(unsigned long long a) { return __builtin_popcountll(a); }
inline int lsb(unsigned long long a) { return __builtin_ctzll(a); }
inline int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }
template <typename T>
inline int getbit(T a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void setbit(T &a, int i) {
  a |= (1LL << i);
}
template <typename T>
inline void delbit(T &a, int i) {
  a &= ~(1LL << i);
}
template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int btw(T a, T x, T b) {
  return a <= x && x < b;
}
template <typename T, typename U>
T ceil(T a, U b) {
  return (a + b - 1) / b;
}
constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}
template <typename T>
vector<T> mkrui(const vector<T> &v) {
  vector<T> ret(v.size() + 1);
  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  return ret;
};
template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}
template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}
template <typename T = int>
vector<T> mkiota(int N) {
  vector<T> ret(N);
  iota(begin(ret), end(ret), 0);
  return ret;
}
template <typename T>
vector<int> mkinv(vector<T> &v) {
  vector<int> inv(v.size());
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;

void solve();
int main() { solve(); }

#pragma endregion
#line 3 "graph/graph-utility.hpp"
using namespace std;

#line 3 "graph/graph-template.hpp"
using namespace std;

template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;

// Input of (Unweighted) Graph
UnweightedGraph graph(int N, int M = -1, bool is_directed = false,
                      bool is_1origin = true) {
  UnweightedGraph g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    if (is_1origin) x--, y--;
    g[x].push_back(y);
    if (!is_directed) g[y].push_back(x);
  }
  return g;
}

// Input of Weighted Graph
template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool is_directed = false,
                        bool is_1origin = true) {
  WeightedGraph<T> g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    cin >> c;
    if (is_1origin) x--, y--;
    g[x].eb(x, y, c);
    if (!is_directed) g[y].eb(y, x, c);
  }
  return g;
}

// Input of Edges
template <typename T>
Edges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {
  Edges<T> es;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    es.emplace_back(x, y, c);
  }
  return es;
}

// Input of Adjacency Matrix
template <typename T>
vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,
                           bool is_directed = false, bool is_1origin = true) {
  vector<vector<T>> d(N, vector<T>(N, INF));
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    d[x][y] = c;
    if (!is_directed) d[y][x] = c;
  }
  return d;
}
#line 6 "graph/graph-utility.hpp"

// Depth of Rooted Tree
// unvisited nodes : d = -1
vector<int> Depth(const UnweightedGraph &g, int start = 0) {
  vector<int> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    d[cur] = par == -1 ? 0 : d[par] + 1;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
    }
  };
  dfs(dfs, start);
  return d;
}

// Depth of Rooted Weighted Tree
// unvisited nodes : d = -1
template <typename T>
vector<T> Depth(const WeightedGraph<T> &g, int start = 0) {
  vector<T> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, T val, int par = -1) -> void {
    d[cur] = val;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, val + dst.cost, cur);
    }
  };
  dfs(dfs, start, 0);
  return d;
}

// Diameter of Tree
// return value : { {u, v}, length }
pair<pair<int, int>, int> Diameter(const UnweightedGraph &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// Diameter of Weighted Tree
// return value : { {u, v}, length }
template <typename T>
pair<pair<int, int>, T> Diameter(const WeightedGraph<T> &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// nodes on the path u-v ( O(N) )
template <typename G>
vector<int> Path(G &g, int u, int v) {
  vi ret;
  int end = 0;
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    ret.push_back(cur);
    if (cur == v) {
      end = 1;
      return;
    }
    for (int dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
      if (end) return;
    }
    if (end) return;
    ret.pop_back();
  };
  dfs(dfs, u);
  return ret;
}
#line 3 "misc/fastio.hpp"
using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
}
inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

inline void rd(char& c) { c = ibuf[pil++]; }
template <typename T>
inline void rd(T& x) {
  if (pil + 32 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if (c == '-') {
    minus = 1;
    c = ibuf[pil++];
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    c = ibuf[pil++];
  }
  if (minus) x = -x;
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head& head, Tail&... tail) {
  rd(head);
  rd(tail...);
}

inline void wt(char c) { obuf[por++] = c; }
template <typename T>
inline void wt(T x) {
  if (por > SZ - 32) flush();
  if (!x) {
    obuf[por++] = '0';
    return;
  }
  if (x < 0) {
    obuf[por++] = '-';
    x = -x;
  }
  int i = 12;
  char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
    x /= 10000;
    i -= 4;
  }
  int d = x < 100 ? (x < 10 ? 1 : 2) : (x < 1000 ? 3 : 4);
  memcpy(obuf + por, pre.num + x * 4 + 4 - d, d);
  por += d;
  memcpy(obuf + por, buf + i + 4, 12 - i);
  por += 12 - i;
}

inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head head, Tail... tail) {
  wt(head);
  wt(tail...);
}
template<typename T>
inline void wtn(T x){
  wt(x, '\n');
}

struct Dummy {
  Dummy() { atexit(flush); }
} dummy;

}  // namespace fastio
using fastio::rd;
using fastio::wt;
using fastio::wtn;
#line 3 "modint/montgomery-modint.hpp"
using namespace std;

template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 a;

  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  constexpr mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }

  constexpr mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  
  constexpr mint inverse() const { return pow(mod - 2); }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }
  
  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};
#line 3 "segment-tree/segment-tree.hpp"
using namespace std;

template <typename T, typename F>
struct SegmentTree {
  int size;
  vector<T> seg;
  const F func;
  const T UNIT;

  SegmentTree(int N, F func, T UNIT) : func(func), UNIT(UNIT) {
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
  }

  SegmentTree(const vector<T> &v, F func, T UNIT) : func(func), UNIT(UNIT) {
    int N = (int)v.size();
    size = 1;
    while (size < N) size <<= 1;
    seg.assign(2 * size, UNIT);
    for (int i = 0; i < N; i++) {
      seg[i + size] = v[i];
    }
    build();
  }

  void set(int k, T x) { seg[k + size] = x; }

  void build() {
    for (int k = size - 1; k > 0; k--) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void update(int k, T x) {
    k += size;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  void add(int k, T x) {
    k += size;
    seg[k] += x;
    while (k >>= 1) {
      seg[k] = func(seg[2 * k], seg[2 * k + 1]);
    }
  }

  // query to [a, b)
  T query(int a, int b) {
    T L = UNIT, R = UNIT;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = func(L, seg[a++]);
      if (b & 1) R = func(seg[--b], R);
    }
    return func(L, R);
  }

  T &operator[](const int &k) { return seg[k + size]; }

  template <typename C>
  int find_subtree(int a, const C &check, T &M, bool type) {
    while (a < size) {
      T nxt = type ? func(seg[2 * a + type], M) : func(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - size;
  }

  template <typename C>
  int find_first(int a, const C &check) {
    T L = UNIT;
    if (a <= 0) {
      if (check(func(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = size;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        T nxt = func(L, seg[a]);
        if (check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template <typename C>
  int find_last(int b, const C &check) {
    T R = UNIT;
    if (b >= size) {
      if (check(func(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = size;
    for (b += size; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        T nxt = func(seg[--b], R);
        if (check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
#line 3 "tree/heavy-light-decomposition.hpp"
using namespace std;

#line 6 "tree/heavy-light-decomposition.hpp"

template <typename G>
struct HeavyLightDecomposition {
  G& g;
  int idx;
  vector<int> size, depth, in, out, nxt, par;
  HeavyLightDecomposition(G& g, int root = 0)
      : g(g),
        idx(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        in(g.size(), -1),
        out(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    in[cur] = idx++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    out[cur] = idx;
  }

  template <typename F>
  void edge_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }

  // TODO : verify
  template <typename F>
  void uncommutable_edge_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u] + 1, in[nxt[u]], true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (in[u] != in[v]) {
          if (in[u] > in[v])
            f(in[u] + 1, in[v] + 1, true);
          else
            f(in[u] + 1, in[v] + 1, true);
        }
        break;
      }
    }
  }

  template <typename F>
  void node_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        f(in[u], in[v] + 1);
        break;
      }
    }
  }

  template <typename F>
  void uncommutable_node_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u] + 1, in[nxt[u]], true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (in[u] > in[v])
          f(in[u] + 1, in[v], true);
        else
          f(in[u], in[v] + 1, true);
        break;
      }
    }
  }

  template <typename F>
  void sub_edge_query(int u, const F& f) {
    f(in[u] + 1, out[u]);
  }

  template <typename F>
  void sub_node_query(int u, const F& f) {
    f(in[u], out[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (in[a] < in[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }
};
#line 9 "verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  int N, Q;
  rd(N);
  rd(Q);
  V<mint> a(N), b(N);
  for (int i = 0; i < N; i++) {
    int buf;
    rd(buf);
    a[i] = buf;
    rd(buf);
    b[i] = buf;
  }
  vvi g(N);
  rep(_, N - 1) {
    int u, v;
    rd(u);
    rd(v);
    g[u].pb(v);
    g[v].pb(u);
  }
  HeavyLightDecomposition<vvi> hld(g);

  using P = pair<mint, mint>;
  auto mul = [](P a, P b) {
    return P{a.first * b.first, a.second * b.first + b.second};
  };
  auto fl = [&mul](P a, P b) { return mul(a, b); };
  auto fr = [&mul](P a, P b) { return mul(b, a); };
  SegmentTree<P, decltype(fl)> segl(N, fl, P{1, 0});
  SegmentTree<P, decltype(fr)> segr(N, fr, P{1, 0});
  rep(i, N) {
    segl.set(hld.in[i], P{a[i], b[i]});
    segr.set(hld.in[i], P{a[i], b[i]});
  }
  segl.build();
  segr.build();

  rep(_, Q) {
    int cmd, x, y, z;
    rd(cmd);
    rd(x);
    rd(y);
    rd(z);
    if (!cmd) {
      segl.update(hld.in[x], P{y, z});
      segr.update(hld.in[x], P{y, z});
    } else {
      P L{1, 0}, R{1, 0};
      auto f = [&](int u, int v, int le) {
        if (le) {
          if (u < v)
            L = mul(L, segl.query(u, v));
          else
            L = mul(L, segr.query(v, u));
        } else {
          if (u < v)
            R = mul(segl.query(u, v), R);
          else
            R = mul(segr.query(v, u), R);
        }
      };
      hld.uncommutable_node_query(x, y, f);
      P res = mul(L, R);
      wt((res.first * z + res.second).get());
      wt('\n');
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
