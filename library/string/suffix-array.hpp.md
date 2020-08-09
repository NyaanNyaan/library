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


# :heavy_check_mark: string/suffix-array.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffix-array.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 23:27:32+09:00




## Depends on

* :heavy_check_mark: <a href="../data-structure/sparse-table.hpp.html">data-structure/sparse-table.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp.html">verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-other/yosupo-suffix-array.test.cpp.html">verify/verify-yosupo-other/yosupo-suffix-array.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp.html">verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/sparse-table.hpp"

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/suffix-array.hpp"
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

