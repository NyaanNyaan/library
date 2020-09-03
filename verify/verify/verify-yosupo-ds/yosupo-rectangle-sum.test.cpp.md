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


# :heavy_check_mark: verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#350dfa5f4985bc48300c39d2bca2b63d">verify/verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 12:40:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/data-structure/rectangle-sum.hpp.html">data-structure/rectangle-sum.hpp</a>
* :heavy_check_mark: <a href="../../../library/segment-tree/persistent-segment-tree.hpp.html">永続セグメント木 <small>(segment-tree/persistent-segment-tree.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../competitive-template.hpp"
#include "../../data-structure/rectangle-sum.hpp"

void solve() {
  ini(N, Q);
  vl xs(N), ys(N), ws(N);
  in3(xs, ys, ws);
  auto f = [](ll u, ll v) { return u + v; };
  RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);
  rep(_, Q) {
    inl(l, d, r, u);
    out(rect.rect_sum(l, d, r, u));
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

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
#line 3 "data-structure/rectangle-sum.hpp"
using namespace std;

#line 3 "segment-tree/persistent-segment-tree.hpp"
using namespace std;

template <typename T, typename F, int NODES = 20000000>
struct PersistentSegmentTree {
  using ll = long long;
  struct Node {
    T data;
    Node *l, *r;
    Node() {}
    Node(const T &_data) : data(_data), l(nullptr), r(nullptr) {}
  };

  Node *pool;
  int pid;
  ll N;
  const F f;
  const T ID;
  Node *nil;
  vector<Node *> roots;

  PersistentSegmentTree(const vector<T> &v, const F &f_, const T &ID_)
      : pid(0), f(f_), ID(ID_), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new(ID);
    nil->l = nil->r = nil;
    roots.reserve(262144);
    roots.push_back(build(v));
  }

  PersistentSegmentTree(const ll &N_, const F &f_, const T &ID_)
      : pid(0), N(N_), f(f_), ID(ID_), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new(ID);
    nil->l = nil->r = nil;
    roots.reserve(262144);
    roots.push_back(nil);
  }

  Node *my_new(const T &data) {
    pool[pid].data = data;
    pool[pid].l = pool[pid].r = nil;
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].data = f(l->data, r->data);
    pool[pid].l = l;
    pool[pid].r = r;
    return &(pool[pid++]);
  }

  Node *build(const vector<T> &v) {
    N = (ll)v.size();
    return build(0, (ll)v.size(), v);
  }

  Node *build(ll l, ll r, const vector<T> &v) {
    if (l + 1 == r) return my_new(v[l]);
    ll m = (l + r) >> 1;
    return merge(build(l, m, v), build(m, r, v));
  }

 private:
  Node *update_(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(x);
    ll m = (l + r) >> 1;
    if (a < m) return merge(update_(a, x, n->l, l, m), n->r);
    return merge(n->l, update_(a, x, n->r, m, r));
  }
  Node *add_(ll a, const T &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return my_new(f(x, n->data));
    ll m = (l + r) >> 1;
    if (a < m) return merge(add_(a, x, n->l, l, m), n->r);
    return merge(n->l, add_(a, x, n->r, m, r));
  }
  T query_(ll a, ll b, Node *n, ll l, ll r) {
    if (n == nil) return ID;
    if (r <= a or b <= l) return ID;
    if (a <= l and r <= b) return n->data;
    ll m = (l + r) >> 1;
    return f(query_(a, b, n->l, l, m), query_(a, b, n->r, m, r));
  }

 public:
  Node *update(Node *n, ll k, const T &x) {
    Node *root = update_(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(int t, ll k, const T &x) {
    Node *root = update_(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *update(ll k, const T &x) {
    Node *root = update_(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  Node *add(Node *n, ll k, const T &x) {
    Node *root = add_(k, x, n, 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(int t, ll k, const T &x) {
    Node *root = add_(k, x, roots[t], 0, N);
    roots.push_back(root);
    return root;
  }
  Node *add(ll k, const T &x) {
    Node *root = add_(k, x, roots.back(), 0, N);
    roots.push_back(root);
    return root;
  }

  T query(Node *n, ll a, ll b) { return query_(a, b, n, 0, N); }
  T query(int t, ll a, ll b) { return query_(a, b, roots[t], 0, N); }
  T query(ll a, ll b) { return query_(a, b, roots.back(), 0, N); }

  Node *new_tree() { return nil; }
};

/**
 * @brief 永続セグメント木
 * @docs docs/segment-tree/persistent-segtree.md
 */
#line 6 "data-structure/rectangle-sum.hpp"

template <typename T, typename U, typename F>
struct RectangleSum {
  PersistentSegmentTree<U, F> seg;
  vector<T> xs, ys;
  vector<U> ws;
  vector<int> ord;

  RectangleSum(const vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,
               const F &f)
      : seg({(int)xs_.size() + 1, f, U(0)}) {
    int N = xs_.size();
    xs.reserve(N);
    ys.reserve(N);
    ws.reserve(N);
    ord.resize(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return xs_[i] < xs_[j]; });
    for (auto &i : ord) {
      xs.push_back(xs_[i]);
      ys.push_back(ys_[i]);
      ws.push_back(ws_[i]);
    }
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i] < ys[j]; });
    vector<T> ys2;
    ys2.reserve(N);
    for (auto &i : ord) {
      seg.add(i, ws[i]);
      ys2.push_back(ys[i]);
    }
    ys.swap(ys2);
  }

  // [ [x1, 0], [x2, y] )
  U rect_sum(T x1, T x2, T y) {
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int u = lower_bound(begin(ys), end(ys), y) - begin(ys);
    return seg.query(u, l, r);
  }

  // [ [x1, y1], [x2, y2] )
  U rect_sum(T x1, T y1, T x2, T y2) {
    if (x1 >= x2 || y1 >= y2) return U(0);
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int d = lower_bound(begin(ys), end(ys), y1) - begin(ys);
    int u = lower_bound(begin(ys), end(ys), y2) - begin(ys);
    return seg.query(u, l, r) - seg.query(d, l, r);
  }
};
#line 5 "verify/verify-yosupo-ds/yosupo-rectangle-sum.test.cpp"

void solve() {
  ini(N, Q);
  vl xs(N), ys(N), ws(N);
  in3(xs, ys, ws);
  auto f = [](ll u, ll v) { return u + v; };
  RectangleSum<ll, ll, decltype(f)> rect(xs, ys, ws, f);
  rep(_, Q) {
    inl(l, d, r, u);
    out(rect.rect_sum(l, d, r, u));
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

