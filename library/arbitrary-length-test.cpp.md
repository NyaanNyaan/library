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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: arbitrary-length-test.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/arbitrary-length-test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-26 14:16:53+09:00




## Depends on

* :heavy_check_mark: <a href="competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="misc/fastio.hpp.html">misc/fastio.hpp</a>
* :warning: <a href="misc/timer.hpp.html">misc/timer.hpp</a>
* :heavy_check_mark: <a href="modint/arbitrary-modint.hpp.html">modint/arbitrary-modint.hpp</a>
* :heavy_check_mark: <a href="ntt/cooley-turkey-ntt.hpp.html">ntt/cooley-turkey-ntt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "competitive-template.hpp"
#include "misc/fastio.hpp"
#include "ntt/cooley-turkey-ntt.hpp"

#include "modint/arbitrary-modint.hpp"
#include "misc/timer.hpp"

void solve() {
  using mint = ArbitraryModInt;
  Timer timer;
  int p;
  rd(p);
  if (p == 2) {
    int a, b;
    rd(a, b);
    wt(a, ' ', (a - b + p) % p, '\n');
    return;
  }

  mint::set_mod(p);
  V<mint> a(p);
  for (int i = 0; i < p; i++) {
    int n;
    rd(n);
    a[i] = n;
  }
  ArbitraryLengthNTT<mint> ntt;

  V<mint> b(p - 1);
  for (int m = 0; m < p - 1; m++) b[m] = a[ntt.w[p - 1 - m].get()];
  ntt.ntt(b);

  for (auto &x : b) x = -x;
  b.pb(b[0]);
  b[p - 1] = (b[p - 1] + p - (b[0] = a[0]));
  for (int i = 0; i < p; i++) wt(b[i].get(), " \n"[i == p - 1]);
  cerr << timer.elapsed() << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#line 3 "ntt/cooley-turkey-ntt.hpp"
using namespace std;

namespace FastFourierTransform {
using real = double;

struct C {
  real x, y;

  C() : x(0), y(0) {}

  C(real x, real y) : x(x), y(y) {}

  inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

  inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

  inline C operator*(const C &c) const {
    return C(x * c.x - y * c.y, x * c.y + y * c.x);
  }

  inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  rts.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  while (base < nbase) {
    real angle = PI * 2.0 / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      real angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void fft(vector<C> &a, int n) {
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = a[i + j + k] * rts[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

template <typename mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  vector<C> fa(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i].get() : 0);
    int y = (i < (int)b.size() ? b[i].get() : 0);
    fa[i] = C(x, y);
  }
  fft(fa, sz);
  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
    fa[i] = A0 + A1 * s;
  }
  fft(fa, sz >> 1);
  vector<mint> ret(need);
  for (int i = 0; i < need; i++) {
    ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
  }
  return ret;
}
};  // namespace FastFourierTransform

template <typename T>
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  static vector<T> multiply(const vector<T> &a, const vector<T> &b,
                            int need = -1) {
    if (need == -1) need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    FastFourierTransform::ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for (int i = 0; i < (int)a.size(); i++) {
      fa[i] = C(a[i].get() & ((1 << 15) - 1), a[i].get() >> 15);
    }
    fft(fa, sz);
    vector<C> fb(sz);
    if (a == b) {
      fb = fa;
    } else {
      for (int i = 0; i < (int)b.size(); i++) {
        fb[i] = C(b[i].get() & ((1 << 15) - 1), b[i].get() >> 15);
      }
      fft(fb, sz);
    }
    real ratio = 0.25 / sz;
    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C a1 = (fa[i] + fa[j].conj());
      C a2 = (fa[i] - fa[j].conj()) * r2;
      C b1 = (fb[i] + fb[j].conj()) * r3;
      C b2 = (fb[i] - fb[j].conj()) * r4;
      if (i != j) {
        C c1 = (fa[j] + fa[i].conj());
        C c2 = (fa[j] - fa[i].conj()) * r2;
        C d1 = (fb[j] + fb[i].conj()) * r3;
        C d2 = (fb[j] - fb[i].conj()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<T> ret(need);
    for (int i = 0; i < need; i++) {
      int64_t aa = llround(fa[i].x);
      int64_t bb = llround(fb[i].x);
      int64_t cc = llround(fa[i].y);
      aa = T(aa).get(), bb = T(bb).get(), cc = T(cc).get();
      ret[i] = aa + (bb << 15) + (cc << 30);
    }
    return ret;
  }
};

template <typename mint>
struct ArbitraryLengthNTT {
  using i64 = long long;

  static int modpow(i64 a, i64 p, int m) {
    i64 r = 1 % m;
    for (a %= m; p; a = a * a % m, p >>= 1)
      if (p & 1) r = r * a % m;
    return r;
  }

  static int factor(int n) {
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) return i;
    return n;
  }

  static vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ret.push_back(i);
        ret.push_back(n / i);
      }
    }
    ret.push_back(n);
    sort(begin(ret), end(ret));
    ret.erase(unique(begin(ret), end(ret)), end(ret));
    return ret;
  }

  static int get_pr(int m) {
    vector<int> st;
    for (int i = m - 1; i != 1; i /= st.back()) st.push_back(factor(i));
    st.erase(unique(begin(st), end(st)), end(st));
    for (int pr = 1, flg = 1; pr < m; ++pr, flg = 1) {
      for (auto &x : st)
        if (modpow(pr, (m - 1) / x, m) == 1) flg = 0;
      if (flg) return pr;
    }
    exit(1);
  }

  struct LaderNTT {
    int p, pr;
    vector<int> prs, iprs;
    LaderNTT() {}
    LaderNTT(int p_) : p(p_), pr(get_pr(p_)), prs(p_ - 1), iprs(p_, -1) {
      for (int i = 0; i < p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;
      for (int i = 0; i < p - 1; i++) iprs[prs[i]] = i;
    }

    void ntt(vector<mint> &a) {
      vector<mint> s(p - 1), t(p - 1);
      for (int i = 0; i < p - 1; i++) s[i] = a[prs[i]];
      for (int i = 0, ldp = len / p; i < p - 1; i++)
        t[i] = w[ldp * prs[i ? p - 1 - i : 0]];
      vector<mint> u = ArbitraryModConvolution<mint>::multiply(s, t);
      s.resize(p);
      fill(begin(s), end(s), a[0]);
      for (int i = 1; i < p; i++) s[0] += a[i];
      for (int i = 0, y = 0; i < (int)u.size(); i++) {
        s[prs[y]] += u[i];
        if (--y < 0) y += p - 1;
      }
      swap(a, s);
    }
  };

  static int len;
  static vector<mint> w;
  static vector<int> divisors;
  static map<int, LaderNTT *> lader;

  ArbitraryLengthNTT(int len_ = -1) {
    int mod = mint::get_mod();
    if ((len = len_) == -1) len = mod - 1;
    if (mod >= 3 && len <= 1) len = 2;
    while ((mod - 1) % len != 0) ++len;
    w.resize(len + 1);
    mint pr = mint(get_pr(mod)).pow((mod - 1) / len);
    for (int i = 0; i <= len; i++) w[i] = i ? w[i - 1] * pr : mint(1);
    divisors = divisor(len);
  }

  static void dft(vector<mint> &a) {
    int N = a.size();
    if (N == 2) {
      mint a01 = a[0] + a[1];
      a[1] = a[0] - a[1];
      a[0] = a01;
      return;
    }
    int d = len / N;
    vector<mint> b(N);
    for (int i = 0, dk = 0; i < N; i++, dk += d) {
      for (int j = 0, k = 0; j < N; j++) {
        b[j] += a[i] * w[k];
        if ((k += dk) >= len) k -= len;
      }
    }
    swap(a, b);
  }

  static void ntt_base2(vector<mint> &a) {
    static vector<int> btr;
    int N = a.size();
    assert(N % 2 == 0);

    if (btr.size() != a.size()) {
      btr.resize(N);
      int b = __builtin_ctz(N);
      assert(N == (1 << b));
      for (int i = 0; i < N; i++) {
        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));
      }
    }

    static vector<mint> basis;
    if (basis.size() < a.size()) {
      basis.resize(N);
      mint b = w[len / N];
      for (int i = N >> 1; i > 0; i >>= 1) {
        mint c = 1;
        for (int j = 0; j < i; ++j) {
          basis[i + j] = c;
          c *= b;
        }
        b *= b;
      }
    }

    for (int i = 0; i < N; i++)
      if (i < btr[i]) swap(a[i], a[btr[i]]);

    for (int k = 1; k < N; k <<= 1) {
      for (int i = 0; i < N; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          mint z = a[i + j + k] * basis[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  static void pntt(vector<mint> &a) {
    int P = a.size();
    if (P <= 64) {
      dft(a);
      return;
    }
    if (lader.find(P) == end(lader)) lader[P] = new LaderNTT(P);
    lader[P]->ntt(a);
  }

  static void ntt(vector<mint> &a) {
    assert(len % a.size() == 0);
    int N = (int)a.size();
    if(N <= 1) return;
    if (N <= 64) {
      dft(a);
      return;
    }

    int P = factor(N);
    if (P == N) {
      pntt(a);
      return;
    }
    if (P == 2) {
      P = 1 << __builtin_ctz(N);
      if (N == P) {
        ntt_base2(a);
        return;
      }
    }

    int Q = N / P;
    vector<mint> s(Q), t(N), u(P);
    for (int p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {
      for (int q = 0, qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];
      ntt(s);
      for (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {
        t[pQ + r] = w[n] * s[r];
      }
    }
    for (int r = 0; r < Q; r++) {
      for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];
      if (P <= 64)
        dft(u);
      else if (P & 1)
        pntt(u);
      else
        ntt_base2(u);
      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ + r] = u[s];
    }
  }

  static void intt(vector<mint> &a) {
    reverse(begin(a) + 1, end(a));
    ntt(a);
    mint invn = mint(a.size()).inverse();
    for (auto &x : a) x *= invn;
  }

  static vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    int N = (int)a.size() + (int)b.size() - 1;
    assert(N <= len);
    vector<mint> s(a), t(b);
    int l = *lower_bound(begin(divisors), end(divisors), N);
    s.resize(l, mint(0));
    t.resize(l, mint(0));
    ntt(s);
    ntt(t);
    for (int i = 0; i < l; i++) s[i] *= t[i];
    intt(s);
    s.resize(N);
    return s;
  }
};
template <typename mint>
int ArbitraryLengthNTT<mint>::len;
template <typename mint>
vector<mint> ArbitraryLengthNTT<mint>::w;
template <typename mint>
vector<int> ArbitraryLengthNTT<mint>::divisors;
template <typename mint>
map<int, typename ArbitraryLengthNTT<mint>::LaderNTT *>
    ArbitraryLengthNTT<mint>::lader;
#line 4 "arbitrary-length-test.cpp"

#line 3 "modint/arbitrary-modint.hpp"
using namespace std;

struct ArbitraryModInt {
  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y)
      : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)x * p.x;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }

  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }

  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }

  int get() const { return x; }

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) { get_mod() = md; }
};
#line 3 "misc/timer.hpp"
using namespace std;

struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() { st = chrono::high_resolution_clock::now(); }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();
  }
};
#line 7 "arbitrary-length-test.cpp"

void solve() {
  using mint = ArbitraryModInt;
  Timer timer;
  int p;
  rd(p);
  if (p == 2) {
    int a, b;
    rd(a, b);
    wt(a, ' ', (a - b + p) % p, '\n');
    return;
  }

  mint::set_mod(p);
  V<mint> a(p);
  for (int i = 0; i < p; i++) {
    int n;
    rd(n);
    a[i] = n;
  }
  ArbitraryLengthNTT<mint> ntt;

  V<mint> b(p - 1);
  for (int m = 0; m < p - 1; m++) b[m] = a[ntt.w[p - 1 - m].get()];
  ntt.ntt(b);

  for (auto &x : b) x = -x;
  b.pb(b[0]);
  b[p - 1] = (b[p - 1] + p - (b[0] = a[0]));
  for (int i = 0; i < p; i++) wt(b[i].get(), " \n"[i == p - 1]);
  cerr << timer.elapsed() << endl;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

