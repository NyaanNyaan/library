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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c893b3744fd88c0c8b5cf4d75eea5b3a">verify-yosupo-other</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :question: <a href="../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :x: <a href="../../library/data-structure/sparse-table.hpp.html">data-structure/sparse-table.hpp</a>
* :x: <a href="../../library/string/suffix-array.hpp.html">string/suffix-array.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../competitive-template.hpp"
#include "../string/suffix-array.hpp"

void solve(){
  ins(S);
  SuffixArray sa(S);
  LCPArray lcp(sa);
  StringSearch search(lcp);
  rep(i,sz(S)){
    cout << (i?" ":"") << search.ArbitaryLCP(0 , i);
  }
  out();
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

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
#line 3 "string/suffix-array.hpp"
using namespace std;

#line 3 "data-structure/sparse-table.hpp"
using namespace std;

template <typename T>
struct SparseTable {
  vector<vector<T> > table;
  vector<int> log_table;

  inline T f(T a, T b) { return min(a, b); }

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for (int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // [l, r)
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return f(table[b][l], table[b][r - (1 << b)]);
  }
};
#line 6 "string/suffix-array.hpp"

// remind: SA including empty string
// verify https://judge.yosupo.jp/submission/240
struct SuffixArray {
  int _size;
  vector<int> sa;
  string &s;
  SuffixArray(string &str) : _size(str.size()), s(str) {
    s.push_back(0);
    sa.resize(s.size());
    iota(begin(sa), end(sa), 0);
    sort(begin(sa), end(sa),
         [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
    vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
    for (int len = 1; len < (int)s.size(); len <<= 1) {
      for (int i = 0; i < (int)s.size(); i++) {
        if (i > 0 && c[sa[i - 1]] == c[sa[i]] &&
            sa[i - 1] + len < (int)s.size() &&
            c[sa[i - 1] + len / 2] == c[sa[i] + len / 2]) {
          classes[sa[i]] = classes[sa[i - 1]];
        } else {
          classes[sa[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(sa), end(sa), begin(c));
      for (int i = 0; i < (int)s.size(); i++) {
        int s1 = c[i] - len;
        if (s1 >= 0) sa[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
    s.pop_back();
  }

  void output() {
    cout << "SA\tidx\tstr" << endl;
    for (int i = 0; i < size(); i++) {
      cout << i << ": \t" << sa[i] << " \t";
      if (sa[i] != _size)
        cout << s.substr(sa[i], _size - sa[i]) << endl;
      else
        cout << "$" << endl;
    }
    cout << endl;
  }

  int size() const { return _size + 1; }
  int operator[](int k) const { return sa[k]; }
};

struct LCPArray {
  const SuffixArray &SA;
  vector<int> LCP, rank;
  LCPArray(const SuffixArray &sa) : SA(sa) {
    LCP.resize(SA.size());
    rank.resize(SA.size());
    for (int i = 0; i < SA.size(); i++) {
      rank[SA[i]] = i;
    }
    LCP[0] = 0;

    for (int i = 0, h = 0; i < SA.size() - 1; i++) {
      int j = SA[rank[i] - 1];
      h ? h-- : h;
      while ((i > j ? i : j) + h < SA.size() - 1 &&
             SA.s[i + h] == SA.s[j + h] && ++h)
        ;
      LCP[rank[i] - 1] = h;
    }
  }

  void output() {
    cout << "SA\tidx\tLCP\tstr" << endl;
    for (int i = 0; i < SA.size(); i++) {
      cout << i << "\t" << SA[i] << " \t" << LCP[i] << "\t";
      if (SA[i] == SA.size() - 1)
        cout << "$";
      else
        cout << SA.s.substr(SA[i], SA.size() - 1 - SA[i]);
      cout << endl;
    }
  }
};

// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/ALDS1_14_D/judge/3874273/C++14
// https://atcoder.jp/contests/abc135/submissions/7574225
// https://judge.yosupo.jp/submission/241
// https://atcoder.jp/contests/abc141/submissions/7577295
struct StringSearch {
  string &s;
  const SuffixArray &sa;
  const LCPArray &lcp;
  SparseTable<int> sparse;
  StringSearch(LCPArray &lcp)
      : s(lcp.SA.s), sa(lcp.SA), lcp(lcp), sparse(lcp.LCP) {}

 private:
  pair<int, int> comp(const string &t, int len, int si, int ti = 0) {
    int sn = (int)s.size(), tn = (int)t.size();
    si += len, ti += len;
    while (si < sn && ti < tn) {
      if (s[si] != t[ti]) return make_pair(s[si] < t[ti], ti);
      si++, ti++;
    }
    return make_pair((si >= sn && ti < tn), ti);
  }

  pair<int, int> find_range(int left, int med, int right, int len) {
    {
      int ng = left - 1, ok = med;
      while (ng + 1 < ok) {
        int cur = (ng + ok) / 2;
        if (sparse.query(cur, med) >= len)
          ok = cur;
        else
          ng = cur;
      }
      left = ok;
    }
    {
      int ok = med, ng = right + 1;
      while (ok + 1 < ng) {
        int cur = (ng + ok) / 2;
        if (sparse.query(med, cur) >= len)
          ok = cur;
        else
          ng = cur;
      }
      right = ok;
    }
    return make_pair(left, right);
  }

 public:
  // Longest Common Prefix between S[i , N) and S[j , N)
  int ArbitaryLCP(int i, int j) {
    if (i == j) return (int)(s.size()) - i;
    return sparse.query(min(lcp.rank[i], lcp.rank[j]),
                        max(lcp.rank[i], lcp.rank[j]));
  }

  // String Search  O(|T| + log |S|) 
  // return : [l, r], l and r are indices of Suffix Array
  // if T doesn't exist, return (-1, -1)
  pair<int, int> find(string &t) {
    int left = 1, right = sa.size() - 1, med = left;
    int leftlen = 0, rightlen = 0, tlen = t.size();
    pair<int, int> ret;
    while (left + 1 < right) {
      med = (left + right) / 2;
      int corres_len = max(min(leftlen, sparse.query(left, med)),
                           min(rightlen, sparse.query(med, right)));
      if (corres_len < max(leftlen, rightlen)) {
        if (leftlen < rightlen)
          left = med, leftlen = corres_len;
        else
          right = med, rightlen = corres_len;
        continue;
      }
      ret = comp(t, corres_len, sa[med]);
      if (ret.second == tlen) return find_range(left, med, right, tlen);
      if (ret.first == 0)
        right = med, rightlen = ret.second;
      else
        left = med, leftlen = ret.second;
    }
    if (sa.size() <= 3) {
      if (comp(t, 0, sa[left]).second == tlen)
        return find_range(left, left, right, tlen);
      if (comp(t, 0, sa[right]).second == tlen)
        return find_range(left, right, right, tlen);
      return make_pair(-1, -1);
    }
    med = left + right - med;
    ret = comp(t, min(leftlen, rightlen), sa[med]);
    if (ret.second == tlen) return find_range(left, med, right, tlen);
    return make_pair(-1, -1);
  }
};
// Usage:
//  SuffixArray sa(S);
//  LCPArray lcp(sa);
//  StringSearch search(lcp);
#line 5 "verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp"

void solve(){
  ins(S);
  SuffixArray sa(S);
  LCPArray lcp(sa);
  StringSearch search(lcp);
  rep(i,sz(S)){
    cout << (i?" ":"") << search.ArbitaryLCP(0 , i);
  }
  out();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

