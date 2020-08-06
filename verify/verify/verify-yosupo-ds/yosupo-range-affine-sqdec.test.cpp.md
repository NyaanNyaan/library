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


# :heavy_check_mark: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#350dfa5f4985bc48300c39d2bca2b63d">verify/verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 01:38:52+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/data-structure/square-decomposition.hpp.html">平方分割 <small>(data-structure/square-decomposition.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../competitive-template.hpp"
#include "../../data-structure/square-decomposition.hpp"
#include "../../modint/montgomery-modint.hpp"

constexpr int B = 300;
using mint = LazyMontgomeryModInt<998244353>;
struct affine {
  mint a, b;
  affine() = default;
  affine(mint a_, mint b_) : a(a_), b(b_) {}
};
affine operator*(const  affine &l,const affine &r) {
  return affine{r.a * l.a, r.a * l.b + r.b};
};

int N, Q;
V<affine> a;
affine id = {1, 0};

void solve() {
  in(N, Q);
  a.resize(N);
  rep(i, N) in(a[i].a, a[i].b);

  struct block {
    // S 作用素の型 T 要素の型
    using S = affine;
    using T = affine;

    int i;

    block() {}

    // i ... 何個目のブロックか
    // i * B + j ... (jをブロック内のidxとして)全体でのidx
    int idx(int j) const { return i * B + j; }

    affine fold;

    // 変数とブロックの初期化を忘れない！
    void init(int _) {
      i = _;
      build();
    }

    void build() {
      fold = {1, 0};
      rep(j, B) if (idx(j) < N) fold = fold * a[idx(j)];
    }

    void update_all(S) { exit(1); }

    void update_part(int l, int r, S x) {
      for (int j = l; j < r; j++) a[idx(j)] = x;
      build();
    }

    T query_all() { return fold; }

    T query_part(int l, int r) {
      affine ret = id;
      for (int i = l; i < r; i++) ret = ret * a[idx(i)];
      return ret;
    }
  };

  auto merge = [](const affine &a,const affine &b) { return a * b; };
  SquareDecomposition<decltype(merge), block, B> sqd(N, merge, id);

  rep(_, Q) {
    ini(cmd);
    if (cmd == 0) {
      ini(p, c, d);
      sqd.update(p, p + 1, {c, d});
    } else {
      ini(l, r, x);
      affine sm = sqd.query(l, r);
      out(sm.a * x + sm.b);
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
#line 3 "data-structure/square-decomposition.hpp"
using namespace std;

// 取得クエリのマージ関数をf、単位元をUNITとする
template <typename MERGE, typename block, int B>
struct SquareDecomposition {
  int N;
  vector<block> sq;
  MERGE merge;
  typename block::T UNIT;
  SquareDecomposition(int N_, MERGE merge_, typename block::T UNIT_)
      : N(N_), sq(N / B + 1), merge(merge_), UNIT(UNIT_) {
    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);
  }

  // 半開区間[ l , r )に対する更新クエリ
  void update(int l, int r, typename block::S x) {
    if (l / B == r / B) {
      sq[l / B].update_part(l % B, r % B, x);
    } else {
      sq[l / B].update_part(l % B, B, x);
      for (int i = l / B + 1; i < r / B; i++) sq[i].update_all(x);
      sq[r / B].update_part(0, r % B, x);
    }
  }

  // 半開区間[ l , r )に対する取得クエリ
  typename block::T query(int l, int r) {
    if (l / B == r / B) return sq[l / B].query_part(l % B, r % B);
    typename block::T ret = UNIT;
    ret = merge(ret, sq[l / B].query_part(l % B, B));
    for (int i = l / B + 1; i < r / B; i++) ret = merge(ret, sq[i].query_all());
    ret = merge(ret, sq[r / B].query_part(0, r % B));
    return ret;
  }
};

/**
 * @brief 平方分割
 * @docs docs/sqrt-dec.md
 */
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
#line 6 "verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp"

constexpr int B = 300;
using mint = LazyMontgomeryModInt<998244353>;
struct affine {
  mint a, b;
  affine() = default;
  affine(mint a_, mint b_) : a(a_), b(b_) {}
};
affine operator*(const  affine &l,const affine &r) {
  return affine{r.a * l.a, r.a * l.b + r.b};
};

int N, Q;
V<affine> a;
affine id = {1, 0};

void solve() {
  in(N, Q);
  a.resize(N);
  rep(i, N) in(a[i].a, a[i].b);

  struct block {
    // S 作用素の型 T 要素の型
    using S = affine;
    using T = affine;

    int i;

    block() {}

    // i ... 何個目のブロックか
    // i * B + j ... (jをブロック内のidxとして)全体でのidx
    int idx(int j) const { return i * B + j; }

    affine fold;

    // 変数とブロックの初期化を忘れない！
    void init(int _) {
      i = _;
      build();
    }

    void build() {
      fold = {1, 0};
      rep(j, B) if (idx(j) < N) fold = fold * a[idx(j)];
    }

    void update_all(S) { exit(1); }

    void update_part(int l, int r, S x) {
      for (int j = l; j < r; j++) a[idx(j)] = x;
      build();
    }

    T query_all() { return fold; }

    T query_part(int l, int r) {
      affine ret = id;
      for (int i = l; i < r; i++) ret = ret * a[idx(i)];
      return ret;
    }
  };

  auto merge = [](const affine &a,const affine &b) { return a * b; };
  SquareDecomposition<decltype(merge), block, B> sqd(N, merge, id);

  rep(_, Q) {
    ini(cmd);
    if (cmd == 0) {
      ini(p, c, d);
      sqd.update(p, p + 1, {c, d});
    } else {
      ini(l, r, x);
      affine sm = sqd.query(l, r);
      out(sm.a * x + sm.b);
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

