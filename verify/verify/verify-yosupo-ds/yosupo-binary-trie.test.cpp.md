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


# :heavy_check_mark: verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#350dfa5f4985bc48300c39d2bca2b63d">verify/verify-yosupo-ds</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-18 23:32:19+09:00


* see: <a href="https://judge.yosupo.jp/problem/set_xor_min">https://judge.yosupo.jp/problem/set_xor_min</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/competitive-template.hpp.html">competitive-template.hpp</a>
* :heavy_check_mark: <a href="../../../library/data-structure/binary-trie.hpp.html">Binary Trie <small>(data-structure/binary-trie.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../competitive-template.hpp"
#include "../../data-structure/binary-trie.hpp"

void solve() {
  ini(Q);
  BinaryTrie<int, 30> trie;
  rep(_, Q) {
    ini(c, x);
    if (c == 0) {
      if (trie.find(x).first == 0) {
        trie.add(x);
      }
    } else if (c == 1) {
      if (trie.find(x).first != 0) {
        trie.del(x);
      }
    } else {
      trie.operate_xor(x);
      out(trie.min_element().first);
      trie.operate_xor(x);
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

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
#line 3 "data-structure/binary-trie.hpp"
using namespace std;

template <typename T, int MAX_LOG, int NODES = 16777216>
struct BinaryTrie {
  using Container = vector<int>;
  struct Node {
    Node *nxt[2];
    int exist;
    Container accept;
    Node() {}
  };

  Node *pool;
  int pid;
  T lazy;
  Node *nil;
  Node *root;

  BinaryTrie() : pid(0), lazy(T(0)), nil(nullptr) {
    pool = new Node[NODES];
    nil = my_new();
    nil->nxt[0] = nil->nxt[1] = root = nil;
  }

  Node *my_new(int exist_ = 0, int id = -1) {
    pool[pid].nxt[0] = pool[pid].nxt[1] = nil;
    pool[pid].exist = exist_;
    if (id != -1) pool[pid].accept.push_back(id);
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].nxt[0] = l;
    pool[pid].nxt[1] = r;
    pool[pid].exist = l->exist + r->exist;
    return &(pool[pid++]);
  }

 private:
  Node *add_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      if (n == nil) return my_new(1, id);
      n->exist++;
      n->accept.push_back(id);
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(add_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], add_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void add(const T &x, int id = -1) { root = add_(x, id, root, MAX_LOG); }

 private:
  Node *del_(const T &x, int id, Node *n, int bit_idx) {
    if (bit_idx == -1) {
      n->exist--;
      return n;
    } else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return merge(del_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);
      else
        return merge(n->nxt[0], del_(x, id, n->nxt[1], bit_idx - 1));
    }
  }

 public:
  void del(const T &x, int id = -1) { root = del_(x, id, root, MAX_LOG); }

 private:
  pair<int, Container &> find_(const T &x, Node *n, int bit_idx) {
    if (bit_idx == -1)
      return pair<int, Container &>(n->exist, n->accept);
    else {
      if (((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1))
        return find_(x, n->nxt[0], bit_idx - 1);
      else
        return find_(x, n->nxt[1], bit_idx - 1);
    }
  }

 public:
  pair<int, Container &> find(const T &x) { return find_(x, root, MAX_LOG); }

 private:
  pair<T, Container &> max_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[~(lazy >> bit_idx) & 1]->exist) {
      auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> max_element() { return max_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> min_element_(Node *n, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    if (n->nxt[(lazy >> bit_idx) & 1]->exist) {
      return min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);
    } else {
      auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    }
  }

 public:
  pair<T, Container &> min_element() { return min_element_(root, MAX_LOG); }

 private:
  pair<T, Container &> get_kth_(Node *n, int64_t k, int bit_idx) {
    if (bit_idx == -1) return pair<T, Container &>(0, n->accept);
    int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;
    if (ex0 < k) {
      auto ret = get_kth_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0, bit_idx - 1);
      ret.first |= T(1) << bit_idx;
      return ret;
    } else {
      return get_kth_(n->nxt[(lazy >> bit_idx) & 1], k, bit_idx - 1);
    }
  }

 public:
  pair<T, Container &> get_kth(int64_t k) { return get_kth_(root, k, MAX_LOG); }

  void operate_xor(T x) { lazy ^= x; }
};

/**
 * @brief Binary Trie
 * @docs docs/data-structure/binary-trie.md
 */
#line 5 "verify/verify-yosupo-ds/yosupo-binary-trie.test.cpp"

void solve() {
  ini(Q);
  BinaryTrie<int, 30> trie;
  rep(_, Q) {
    ini(c, x);
    if (c == 0) {
      if (trie.find(x).first == 0) {
        trie.add(x);
      }
    } else if (c == 1) {
      if (trie.find(x).first != 0) {
        trie.del(x);
      }
    } else {
      trie.operate_xor(x);
      out(trie.min_element().first);
      trie.operate_xor(x);
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

