#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

struct Fast_Mo {
  int N, Q, width;
  vector<int> L, R, order;
  bool is_build;
  int nl, nr;

  Fast_Mo(int _n, int _q) : N(_n), Q(_q), order(Q), is_build(false) {
    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q / 2.0)));
    iota(begin(order), end(order), 0);
  }
  // [l, r)
  void insert(int l, int r) {
    assert(0 <= l and l <= r and r <= N);
    L.push_back(l), R.push_back(r);
  }

  void build() { sort(), climb(), is_build = true; }

  template <typename AL, typename AR, typename DL, typename DR, typename REM>
  void run(const AL &add_left, const AR &add_right, const DL &delete_left,
           const DR &delete_right, const REM &rem) {
    if (!is_build) build();
    nl = nr = 0;
    for (auto idx : order) {
      while (nl > L[idx]) add_left(--nl);
      while (nr < R[idx]) add_right(nr++);
      while (nl < L[idx]) delete_left(nl++);
      while (nr > R[idx]) delete_right(--nr);
      rem(idx);
    }
  }

 private:
  void sort() {
    assert((int)order.size() == Q);
    vector<int> cnt(N + 1), buf(Q);
    for (int i = 0; i < Q; i++) cnt[R[i]]++;
    for (int i = 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < Q; i++) buf[--cnt[R[i]]] = i;
    vector<int> b(Q);
    for (int i = 0; i < Q; i++) b[i] = L[i] / width;
    cnt.resize(N / width + 1);
    fill(begin(cnt), end(cnt), 0);
    for (int i = 0; i < Q; i++) cnt[b[i]]++;
    for (int i = 1; i < (int)cnt.size(); i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < Q; i++) order[--cnt[b[buf[i]]]] = buf[i];
    for (int i = 0, j = 0; i < Q; i = j) {
      int bi = b[order[i]];
      j = i + 1;
      while (j != Q and bi == b[order[j]]) j++;
      if (!(bi & 1)) reverse(begin(order) + i, begin(order) + j);
    }
  }

  int dist(int i, int j) { return abs(L[i] - L[j]) + abs(R[i] - R[j]); }

  void climb(int iter = 3, int interval = 5) {
    vector<int> d(Q - 1);
    for (int i = 0; i < Q - 1; i++) d[i] = dist(order[i], order[i + 1]);
    while (iter--) {
      for (int i = 1; i < Q; i++) {
        int pre1 = d[i - 1];
        int js = i + 1, je = min<int>(i + interval, Q - 1);
        for (int j = je - 1; j >= js; j--) {
          int pre2 = d[j];
          int now1 = dist(order[i - 1], order[j]);
          int now2 = dist(order[i], order[j + 1]);
          if (now1 + now2 < pre1 + pre2) {
            reverse(begin(order) + i, begin(order) + j + 1);
            reverse(begin(d) + i, begin(d) + j);
            d[i - 1] = pre1 = now1;
            d[j] = now2;
          }
        }
      }
    }
  }
};
