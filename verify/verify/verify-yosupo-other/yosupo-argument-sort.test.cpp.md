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


# :heavy_check_mark: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d39daa9a5438d03dc407439811d187a2">verify/verify-yosupo-other</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-other/yosupo-argument-sort.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 18:12:46+09:00


* see: <a href="https://judge.yosupo.jp/problem/sort_points_by_argument">https://judge.yosupo.jp/problem/sort_points_by_argument</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/geometry/integer-geometry.hpp.html">geometry/integer-geometry.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../competitive-template.hpp"
#include "../../geometry/integer-geometry.hpp"

void solve() {
  ini(N);
  Points ps(N);
  in(ps);
  ArgumentSort(ps);
  each(p, ps) out(p);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-other/yosupo-argument-sort.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

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
#line 3 "geometry/integer-geometry.hpp"
using namespace std;

struct Point {
  using T = long long;
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  Point &operator+=(const Point &p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
  }

  Point &operator-=(const Point &p) {
    this->x -= p.x;
    this->y -= p.y;
    return *this;
  }

  int pos() const {
    if (y < 0) return -1;
    if (y == 0 && 0 <= x) return 0;
    return 1;
  }

  Point operator+(const Point &p) const { return Point(*this) += p; }
  Point operator-(const Point &p) const { return Point(*this) -= p; }
  Point operator-() const { return Point(-this->x, -this->y); }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
  bool operator<(const Point &p) const { return x == p.x ? y < p.y : x < p.x; }

  friend istream &operator>>(istream &is, Point &p) {
    cin >> p.x >> p.y;
    return is;
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    os << p.x << " " << p.y;
    return os;
  }
};
using Points = vector<Point>;

Point::T dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
Point::T cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

// sort by argument (-Pi ~ Pi)
void ArgumentSort(Points &v) {
  sort(begin(v), end(v), [](Point a, Point b) {
    if (a.pos() != b.pos()) return a.pos() < b.pos();
    return cross(a, b) > 0;
  });
}

// 1 ... counterclockwise / 0 straight / -1 clockwise
int ccw(const Point &a, const Point &b, const Point &c) {
  ll t = cross(b - a, c - a);
  return t < 0 ? -1 : t == 0 ? 0 : 1;
}

// v must have sorted by x-coordinate
Points LowerHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  convex.resize(k);
  return convex;
}

Points UpperHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) >= 0) --k;
  }
  convex.resize(k);
  return convex;
}

Points ConvexHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(2 * N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  for (int i = N - 2, t = k + 1; i >= 0; convex[k++] = ps[i--]) {
    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  convex.resize(k - 1);
  return convex;
}
#line 5 "verify/verify-yosupo-other/yosupo-argument-sort.test.cpp"

void solve() {
  ini(N);
  Points ps(N);
  in(ps);
  ArgumentSort(ps);
  each(p, ps) out(p);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

