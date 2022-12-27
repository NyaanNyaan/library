#pragma once



#include "../segment-tree/persistent-segment-tree.hpp"

template <typename T, typename U, typename F>
struct RectangleSum {
  PersistentSegmentTree<U, F> seg;
  vector<T> xs, ys;
  vector<U> ws;
  vector<int> ord;

  RectangleSum(const vector<T> &xs_, const vector<T> &ys_, const vector<U> &ws_,
               const F &f)
      : seg({(int)xs_.size() + 1, f, U(0)}) {
    int N = xs_.size();
    xs.reserve(N);
    ys.reserve(N);
    ws.reserve(N);
    ord.resize(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return xs_[i] < xs_[j]; });
    for (auto &i : ord) {
      xs.push_back(xs_[i]);
      ys.push_back(ys_[i]);
      ws.push_back(ws_[i]);
    }
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return ys[i] < ys[j]; });
    vector<T> ys2;
    ys2.reserve(N);
    for (auto &i : ord) {
      seg.add(i, ws[i]);
      ys2.push_back(ys[i]);
    }
    ys.swap(ys2);
  }

  // [ [x1, 0], [x2, y] )
  U rect_sum(T x1, T x2, T y) {
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int u = lower_bound(begin(ys), end(ys), y) - begin(ys);
    return seg.query(u, l, r);
  }

  // [ [x1, y1], [x2, y2] )
  U rect_sum(T x1, T y1, T x2, T y2) {
    if (x1 >= x2 || y1 >= y2) return U(0);
    int l = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), x2) - begin(xs);
    int d = lower_bound(begin(ys), end(ys), y1) - begin(ys);
    int u = lower_bound(begin(ys), end(ys), y2) - begin(ys);
    return seg.query(u, l, r) - seg.query(d, l, r);
  }
};

/*
 * @brief 矩形和(永続セグメント木)
 */
