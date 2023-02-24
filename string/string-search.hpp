#pragma once

#include "../atcoder/string.hpp"
#include "../data-structure/sparse-table.hpp"

template <typename Container>
struct StringSearch {
  const Container& S;
  int N;
  vector<int> sa, la, invsa;
  SparseTable<int> sparse;

  StringSearch(const Container& _s) : S(_s), N(S.size()) {
    sa = atcoder::suffix_array(S);
    la = atcoder::lcp_array(S, sa);
    invsa.resize(N);
    for (int i = 0; i < N; i++) invsa[sa[i]] = i;
    sparse = SparseTable<int>{la};
  }

  // lcp(s[i, N), s[j, N))
  int lcp(int i, int j) {
    assert(0 <= min(i, j) and max(i, j) < N);
    if (i == j) return N - i;
    int x = min(invsa[i], invsa[j]);
    int y = max(invsa[i], invsa[j]);
    return sparse.query(x, y);
  }
  // lcp(s[a, b), s[c, d))
  int lcp(int a, int b, int c, int d) {
    assert(0 <= a and a <= b and b <= N);
    assert(0 <= c and c <= d and d <= N);
    int l = lcp(a, c);
    return min({l, b - a, d - c});
  }
  // lcp(s[a, b), s[c, d))
  template <typename Int>
  int lcp(pair<Int, Int> p, pair<Int, Int> q) {
    return lcp(p.first, p.second, q.first, q.second);
  }

  // s[i, N) > s[j, N) : 1
  // s[i, N) = s[j, N) : 0
  // s[i, N) < s[j, N) : -1
  int strcmp(int i, int j) {
    assert(0 <= min(i, j) and max(i, j) < N);
    if (i == j) return 0;
    return invsa[i] < invsa[j] ? -1 : 1;
  }

  // s[a, b) > s[c, d) : 1
  // s[a, b) = s[c, d) : 0
  // s[a, b) < s[c, d) : -1
  int strcmp(int a, int b, int c, int d) {
    int l = lcp(a, b, c, d);
    return a + l == b            ? (c + l == d ? 0 : -1)
           : c + l == d          ? 1
           : S[a + l] < S[c + l] ? -1
                                 : 1;
  }
  // s[a, b) > s[c, d) : 1
  // s[a, b) = s[c, d) : 0
  // s[a, b) < s[c, d) : -1
  template <typename Int>
  int strcmp(pair<Int, Int> p, pair<Int, Int> q) {
    return strcmp(p.first, p.second, q.first, q.second);
  }
};
