#pragma once



#include "../segment-tree/segment-tree.hpp"

// S ... index_type
// T ... value_type
// F ... function_type
template <typename S, typename T, typename F>
struct RangeTree {
  using Seg = SegmentTree<T, F>;
  using P = pair<S, S>;

  S N, M;
  const F f;
  T ti;
  vector<SegmentTree<T, F>> seg;
  vector<vector<S>> ys;
  vector<P> ps;

  RangeTree(const F& f_, const T& ti_) : f(f_), ti(ti_) {}

  void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }

  void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    N = ps.size();
    for (int i = 0; i < 2 * N; ++i) seg.push_back(Seg{f, ti});
    ys.resize(2 * N);
    for (int i = 0; i < N; ++i) {
      ys[i + N].push_back(ps[i].second);
      seg[i + N].init(1);
    }
    for (int i = N - 1; i > 0; --i) {
      ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());
      merge(begin(ys[(i << 1) | 0]), end(ys[(i << 1) | 0]),
            begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));
      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));
      seg[i].init(ys[i].size());
    }
  }

  int id(S x) const {
    return lower_bound(
               begin(ps), end(ps), make_pair(x, S()),
               [](const P& a, const P& b) { return a.first < b.first; }) -
           begin(ps);
  }

  int id(int i, S y) const {
    return lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);
  }

  void add(S x, S y, T a) {
    int i = lower_bound(begin(ps), end(ps), make_pair(x, y)) - begin(ps);
    assert(ps[i] == make_pair(x, y));
    for (i += N; i; i >>= 1) seg[i].add(id(i, y), a);
  }

  T sum(S xl, S yl, S xr, S yr) {
    T L = ti, R = ti;
    int a = id(xl), b = id(xr);
    for (a += N, b += N; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a].query(id(a, yl), id(a, yr))), ++a;
      if (b & 1) --b, R = f(seg[b].query(id(b, yl), id(b, yr)), R);
    }
    return f(L, R);
  }
};

/*
 * @brief 領域木(Segment Tree)
 */
