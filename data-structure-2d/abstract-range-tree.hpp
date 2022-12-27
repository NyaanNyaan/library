#pragma once

// DS ... data_structure_type
// S ... size_type
// T ... value_type
template <typename DS, typename S, typename T>
struct RangeTree {
  using NEW = function<DS*(int)>;
  using ADD = function<void(DS&, int, T)>;
  using SUM = function<T(DS&, int, int)>;
  using MRG = function<T(T, T)>;
  using P = pair<S, S>;

  S N, M;
  const NEW ds_new;
  const ADD ds_add;
  const SUM ds_sum;
  const MRG t_merge;
  const T ti;
  vector<DS*> ds;
  vector<vector<S>> ys;
  vector<P> ps;

  RangeTree(const NEW& nw, const ADD& ad, const SUM& sm, const MRG& mrg,
            const T& ti_)
      : ds_new(nw), ds_add(ad), ds_sum(sm), t_merge(mrg), ti(ti_) {}

  void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }

  void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    N = ps.size();
    ds.resize(2 * N, nullptr);
    ys.resize(2 * N);
    for (int i = 0; i < N; ++i) {
      ys[i + N].push_back(ps[i].second);
      ds[i + N] = ds_new(1);
    }
    for (int i = N - 1; i > 0; --i) {
      ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());
      merge(begin(ys[(i << 1) | 0]), end(ys[(i << 1) | 0]),
            begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));
      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));
      ds[i] = ds_new(ys[i].size());
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
    for (i += N; i; i >>= 1) ds_add(*ds[i], id(i, y), a);
  }

  T sum(S xl, S yl, S xr, S yr) {
    T L = ti, R = ti;
    int a = id(xl), b = id(xr);
    for (a += N, b += N; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = t_merge(L, ds_sum(*ds[a], id(a, yl), id(a, yr))), ++a;
      if (b & 1) --b, R = t_merge(ds_sum(*ds[b], id(b, yl), id(b, yr)), R);
    }
    return t_merge(L, R);
  }
};

/*
 * @brief 抽象化領域木
 */
