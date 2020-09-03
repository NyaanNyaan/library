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


# :heavy_check_mark: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7298ccfe146a0dd6796a2b3f9ffabb95">verify/verify-yosupo-math</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 01:02:38+09:00


* see: <a href="https://judge.yosupo.jp/problem/counting_primes">https://judge.yosupo.jp/problem/counting_primes</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/math/prime-counting-o2d3.hpp.html">素数カウント( $\mathrm{O}(N^{\frac{2}{3}})$ ) <small>(math/prime-counting-o2d3.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/prime-table.hpp.html">math/prime-table.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../competitive-template.hpp"
#include "../../math/prime-counting-o2d3.hpp"

void solve() {
  inl(N);
  out(prime_counting(N));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

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
#line 3 "math/prime-counting-o2d3.hpp"
using namespace std;

#line 3 "math/prime-table.hpp"
using namespace std;

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> PrimeTable(int N) {
  vector<bool> sieve(N / 3 + 1, 1);
  for (int p = 5, d = 4, i = 1, sqn = int(sqrt(N) + 0.1); p <= sqn;
       p += d = 6 - d, i++) {
    if (!sieve[i]) continue;
    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,
             qe = sieve.size();
         q < qe; q += r = s - r)
      sieve[q] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
    if (sieve[i]) ret.push_back(p);
  while (!ret.empty() && ret.back() > N) ret.pop_back();
  return ret;
}
#line 6 "math/prime-counting-o2d3.hpp"

inline int64_t my_div(int64_t n, int64_t p) { return double(n) / p; };

int64_t prime_counting(long long N) {
  using i64 = long long;

  i64 N6, N3, N2, N23, nsz;
  vector<i64> ns, h;
  vector<int> bit;

  // calculate N^{1/2}, N^{1/3}, N{1/6}, N{2/3}
  N2 = sqrt(N);
  N3 = pow(N, 1.0 / 3.0);
  while (N3 * N3 * N3 > N) N3--;
  while ((N3 + 1) * (N3 + 1) * (N3 + 1) <= N) N3++;
  N6 = sqrt(N3);
  N23 = N / N3;

  // precalc prime sieve below N ^ {1/2}
  auto prime = PrimeTable(N2 + 1000);
  // index of prime
  int pidx = 0;
  // restore pi(p - 1)
  i64 pi = 0;

  // initialize ns
  ns.reserve(N2 * 2 + 2);
  ns.push_back(0);
  for (int i = 1; i <= N2; i++) ns.push_back(my_div(N, i));
  for (int i = ns.back() - 1; i > 0; i--) ns.push_back(i);
  nsz = ns.size();

  // initialize h
  copy(begin(ns), end(ns), back_inserter(h));
  for (auto &i : h) --i;

  // p <= N ^ {1/6}
  while (prime[pidx] <= N6) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    for (i64 i = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])
      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n, p)] - pi;
    ++pidx;
    ++pi;
  }

  // fenwick tree, which restore [ h(p, 1), h(p, N ^ {2/3}) )
  // bit[i] corresponds to h[i + N3] (1 <= i)
  bit.resize(nsz - N3);

  auto dfs = [&](auto rec, i64 cur, int pid, int flag) -> void {
    if (flag) {
      // if cur > N^{1/2} :
      // cur <= floor(N / id)
      // -> cur * id + n = N, n < id < cur
      // -> id <= floor(N / cur)
      int id = cur <= N2 ? nsz - cur : my_div(N, cur);
      // decrease h[N3] ~ h[id]
      if (id > N3)
        for (id -= N3; id; id -= id & -id) --bit[id];
    }
    for (int dst = pid; cur * prime[dst] < N23; dst++)
      rec(rec, cur * prime[dst], dst, true);
  };

  // N ^ {1/6} < p <= N ^ {1/3}
  while (prime[pidx] <= N3) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    // update N ^ {2/3} <= n <= N
    for (i64 i = 1; i <= N3; i++) {
      // ns[i] >= p2 > N^{1/3}
      if (p2 > ns[i]) break;
      // id of floor(N/ip)
      int id = i * p <= N2 ? i * p : nsz - my_div(ns[i], p);
      // current value of h[id]

      i64 sm = h[id];
      // if floor(N/ip) < N^{2/3}, add sum of fenwick tree
      if (id > N3)
        for (id -= N3; id < (int)bit.size(); id += id & -id) sm += bit[id];
      h[i] -= sm - pi;
    }

    // update N ^ {1/3} <= n < N ^ {2/3}, using dfs
    dfs(dfs, p, pidx, false);

    ++pidx;
    ++pi;
  }

  // reflect fenwick tree
  for (int i = (int)bit.size() - 1; i; i--) {
    int j = i + (i & -i);
    if (j < (int)bit.size()) bit[i] += bit[j];
  }
  for (int i = 1; i < (int)bit.size(); i++) h[i + N3] += bit[i];

  // N ^ {1/3} < p <= N ^ {1/2}
  while (prime[pidx] <= N2) {
    int p = prime[pidx];
    i64 p2 = i64(p) * p;
    for (i64 i = 1, n = ns[i]; i < nsz && n >= p2; n = ns[++i])
      h[i] -= h[i * p <= N2 ? i * p : nsz - my_div(n, p)] - pi;
    ++pidx;
    ++pi;
  }

  return h[1];
}

/**
 * @brief 素数カウント( $\mathrm{O}(N^{\frac{2}{3}})$ )
 * @docs docs/math/prime-counting-o2d3.md
 */
#line 5 "verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp"

void solve() {
  inl(N);
  out(prime_counting(N));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

