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


# :heavy_check_mark: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#350dfa5f4985bc48300c39d2bca2b63d">verify/verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 17:31:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_inversions_query">https://judge.yosupo.jp/problem/static_range_inversions_query</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/data-structure/binary-indexed-tree.hpp.html">data-structure/binary-indexed-tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/misc/compress.hpp.html">misc/compress.hpp</a>
* :heavy_check_mark: <a href="../../../library/misc/fastio.hpp.html">misc/fastio.hpp</a>
* :heavy_check_mark: <a href="../../../library/misc/mo.hpp.html">misc/mo.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../competitive-template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/fastio.hpp"
#include "../../misc/mo.hpp"

void solve() {
  int N, Q;
  rd(N);
  rd(Q);
  vi a(N);
  rep(i, N) rd(a[i]);
  Mo mo(N, Q);
  rep(i, Q) {
    int l, r;
    rd(l);
    rd(r);
    mo.insert(l, r);
  }
  compress<int> zip(a);
  BinaryIndexedTree<int> bit(zip.size() + 1);
  rep(i, N) a[i] = zip.get(a[i]);

  ll cnt = 0;
  vl ans(Q);
  auto addleft = [&](int idx) {
    cnt += bit.sum(0, a[idx] - 1);
    bit.add(a[idx], 1);
  };
  auto addright = [&](int idx) {
    cnt += bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], 1);
  };
  auto delleft = [&](int idx) {
    cnt -= bit.sum(0, a[idx] - 1);
    bit.add(a[idx], -1);
  };
  auto delright = [&](int idx) {
    cnt -= bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], -1);
  };
  auto rem = [&](int idx) { ans[idx] = cnt; };
  mo.run(addleft,addright,delleft,delright,rem);
  each(x, ans) {
    wt(x);
    wt('\n');
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

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
#line 3 "data-structure/binary-indexed-tree.hpp"
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  int N;
  int max_2beki;
  vector<T> data;

  BinaryIndexedTree(int size) {
    N = ++size;
    data.assign(N + 3, 0);
    max_2beki = 1;
    while (max_2beki * 2 <= N) max_2beki *= 2;
  }

  // get sum of [0,k]
  T sum(int k) const {
    if (k < 0) return 0;  // return 0 if k < 0
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // getsum of [l,r]
  inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

  // get value of k
  inline T operator[](int k) const { return sum(k) - sum(k - 1); }

  // data[k] += x
  void add(int k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // range add x to [l,r]
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }

  // minimize i s.t. sum(i) >= w
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // minimize i s.t. sum(i) > w
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};
#line 3 "misc/compress.hpp"
using namespace std;

template<class T>
struct compress{
  vector<T> xs;
  compress(const vector<T>& v){
    xs.reserve(v.size());
    for(T x : v) xs.push_back(x);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()) , xs.end());
  }

  int get(const T& x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
  }
  int size(){
    return xs.size();
  }
  T& operator[](int i){
    return xs[i];
  }
};
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
#line 3 "misc/mo.hpp"
using namespace std;

struct Mo {
  int width;
  vector<int> left, right, order;

  Mo(int N, int Q) : order(Q) {
    width = max(1, N / max<int>(1, sqrt(Q / 3)));
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template <typename AL, typename AR, typename DL, typename DR, typename REM>
  void run(const AL &add_left, const AR &add_right, const DL &delete_left,
           const DR &delete_right, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if (ablock != bblock) return ablock < bblock;
      if (ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    for (auto idx : order) {
      while (nl > left[idx]) add_left(--nl);
      while (nr < right[idx]) add_right(nr++);
      while (nl < left[idx]) delete_left(nl++);
      while (nr > right[idx]) delete_right(--nr);
      rem(idx);
    }
  }
};
#line 8 "verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp"

void solve() {
  int N, Q;
  rd(N);
  rd(Q);
  vi a(N);
  rep(i, N) rd(a[i]);
  Mo mo(N, Q);
  rep(i, Q) {
    int l, r;
    rd(l);
    rd(r);
    mo.insert(l, r);
  }
  compress<int> zip(a);
  BinaryIndexedTree<int> bit(zip.size() + 1);
  rep(i, N) a[i] = zip.get(a[i]);

  ll cnt = 0;
  vl ans(Q);
  auto addleft = [&](int idx) {
    cnt += bit.sum(0, a[idx] - 1);
    bit.add(a[idx], 1);
  };
  auto addright = [&](int idx) {
    cnt += bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], 1);
  };
  auto delleft = [&](int idx) {
    cnt -= bit.sum(0, a[idx] - 1);
    bit.add(a[idx], -1);
  };
  auto delright = [&](int idx) {
    cnt -= bit.sum(a[idx] + 1, zip.size());
    bit.add(a[idx], -1);
  };
  auto rem = [&](int idx) { ans[idx] = cnt; };
  mo.run(addleft,addright,delleft,delright,rem);
  each(x, ans) {
    wt(x);
    wt('\n');
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

