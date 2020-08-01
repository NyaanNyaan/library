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


# :heavy_check_mark: verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b501e8320d2b88d7788be7181d2f6d20">verify/verify-aoj-ntl</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-01 13:45:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E</a>


## Depends on

* :question: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/math/elementary-function.hpp.html">math/elementary-function.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../competitive-template.hpp"
#include "../../math/elementary-function.hpp"

void solve() {
  ini(a, b);
  int x, y;
  tie(x, y) = extgcd(a, b);
  out(x, y);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

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
#line 3 "math/elementary-function.hpp"
using namespace std;

long long my_gcd(long long x, long long y) {
  long long z;
  if (x > y) swap(x, y);
  while (x) {
    x = y % (z = x);
    y = z;
  }
  return y;
}
long long my_lcm(long long x, long long y) {
  return 1LL * x / my_gcd(x, y) * y;
}
#define gcd my_gcd
#define lcm my_lcm

// Prime -> 1 {0, 0, 1, 1, 0, 1, 0, 1, ...}
vector<int> Primes(int N) {
  vector<int> A(N + 1, 1);
  A[0] = A[1] = 0;
  for (int i = 2; i * i <= N; i++)
    if (A[i] == 1)
      for (int j = i << 1; j <= N; j += i) A[j] = 0;
  return A;
}

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<long long> PrimeSieve(int N) {
  vector<int> prime = Primes(N);
  vector<long long> ret;
  for (int i = 0; i < (int)prime.size(); i++)
    if (prime[i] == 1) ret.push_back(i);
  return ret;
}

// Factors (using for fast factorization)
// {0, 0, 1, 1, 2, 1, 2, 1, 2, 3, ...}
vector<int> Factors(int N) {
  vector<int> A(N + 1, 1);
  A[0] = A[1] = 0;
  for (int i = 2; i * i <= N; i++)
    if (A[i] == 1)
      for (int j = i << 1; j <= N; j += i) A[j] = i;
  return A;
}

// totient function φ(N)=(1 ~ N , gcd(i,N) = 1)
// {0, 1, 1, 2, 4, 2, 6, 4, ... }
vector<int> EulersTotientFunction(int N) {
  vector<int> ret(N + 1, 0);
  for (int i = 0; i <= N; i++) ret[i] = i;
  for (int i = 2; i <= N; i++) {
    if (ret[i] == i)
      for (int j = i; j <= N; j += i) ret[j] = ret[j] / i * (i - 1);
  }
  return ret;
}

// Divisor ex) 12 -> {1, 2, 3, 4, 6, 12}
vector<long long> Divisor(long long N) {
  vector<long long> v;
  for (long long i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      v.push_back(i);
      if (i * i != N) v.push_back(N / i);
    }
  }
  return v;
}

// Factorization
// ex) 18 -> { (2,1) , (3,2) }
vector<pair<long long, int> > PrimeFactors(long long N) {
  vector<pair<long long, int> > ret;
  for (long long p = 2; p * p <= N; p++)
    if (N % p == 0) {
      ret.emplace_back(p, 0);
      while (N % p == 0) N /= p, ret.back().second++;
    }
  if (N >= 2) ret.emplace_back(N, 1);
  return ret;
}

// Factorization with Prime Sieve
// ex) 18 -> { (2,1) , (3,2) }
vector<pair<long long, int> > PrimeFactors(long long N,
                                           const vector<long long> &prime) {
  vector<pair<long long, int> > ret;
  for (auto &p : prime) {
    if (p * p > N) break;
    if (N % p == 0) {
      ret.emplace_back(p, 0);
      while (N % p == 0) N /= p, ret.back().second++;
    }
  }
  if (N >= 2) ret.emplace_back(N, 1);
  return ret;
}

// modpow for mod < 2 ^ 31
long long modpow(long long a, long long n, long long mod) {
  a %= mod;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret % mod;
};

// Check if r is Primitive Root
bool isPrimitiveRoot(long long r, long long mod) {
  r %= mod;
  if (r == 0) return false;
  auto pf = PrimeFactors(mod - 1);
  for (auto &x : pf) {
    if (modpow(r, (mod - 1) / x.first, mod) == 1) return false;
  }
  return true;
}

// Get Primitive Root
long long PrimitiveRoot(long long mod) {
  long long ret = 1;
  while (isPrimitiveRoot(ret, mod) == false) ret++;
  return ret;
}

// Euler's phi function
long long phi(long long n) {
  auto pf = PrimeFactors(n);
  long long ret = n;
  for (auto p : pf) {
    ret /= p.first;
    ret *= (p.first - 1);
  }
  return ret;
}

// Extended Euclidean algorithm
// solve : ax + by = gcd(a, b)
// return : pair(x, y)
pair<long long, long long> extgcd(long long a, long long b) {
  if (b == 0) return make_pair(1, 0);
  long long x, y;
  tie(y, x) = extgcd(b, a % b);
  y -= a / b * x;
  return make_pair(x, y);
}

// Check if n is Square Number
bool isSquare(long long n) {
  if (n == 0 || n == 1) return true;
  long long d = (long long)sqrt(n) - 1;
  while (d * d < n) ++d;
  return d * d == n;
}

// return a number of n's digit
// zero ... return value if n = 0 (default -> 1)
int isDigit(long long n, int zero = 1) {
  if (n == 0) return zero;
  int ret = 0;
  while (n) {
    n /= 10;
    ret++;
  }
  return ret;
}
#line 6 "verify/verify-aoj-ntl/aoj-ntl-1-e.test.cpp"

void solve() {
  ini(a, b);
  int x, y;
  tie(x, y) = extgcd(a, b);
  out(x, y);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

