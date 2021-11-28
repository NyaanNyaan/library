#pragma once



// S ... size_type
// T ... value_type
template <typename S, typename T>
struct FenwickRangeTree {
  struct BIT {
    int N;
    vector<T> data;

    BIT() = default;
    BIT(int size) { init(size); }

    void init(int size) {
      N = size;
      data.assign(N + 1, 0);
    }

    void add(int k, T x) {
      for (++k; k <= N; k += k & -k) data[k] += x;
    }

    T sum(int k) const {
      T ret = T();
      for (; k; k -= k & -k) ret += data[k];
      return ret;
    }

    inline T sum(int l, int r) const {
      T ret = T();
      while (l != r) {
        if (l < r) {
          ret += data[r];
          r -= r & -r;
        } else {
          ret -= data[l];
          l -= l & -l;
        }
      }
      return ret;
    }
  };

  using P = pair<S, S>;
  S N, M;
  vector<BIT> bit;
  vector<vector<S>> ys;
  vector<P> ps;

  FenwickRangeTree() = default;

  void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }

  void build() {
    sort(begin(ps), end(ps));
    ps.erase(unique(begin(ps), end(ps)), end(ps));
    N = ps.size();
    bit.resize(N + 1);
    ys.resize(N + 1);
    for (int i = 0; i <= N; ++i) {
      for (int j = i + 1; j <= N; j += j & -j) ys[j].push_back(ps[i].second);
      sort(begin(ys[i]), end(ys[i]));
      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));
      bit[i].init(ys[i].size());
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
    for (++i; i <= N; i += i & -i) bit[i].add(id(i, y), a);
  }

  T sum(S x, S y) const {
    T ret = T();
    for (int a = id(x); a; a -= a & -a) ret += bit[a].sum(id(a, y));
    return ret;
  }

  T sum(S xl, S yl, S xr, S yr) const {
    T ret = T();
    int a = id(xl), b = id(xr);
    while (a != b) {
      if (a < b) {
        ret += bit[b].sum(id(b, yl), id(b, yr));
        b -= b & -b;
      } else {
        ret -= bit[a].sum(id(a, yl), id(a, yr));
        a -= a & -a;
      }
    }
    return ret;
  }
};

/*
 * @brief 領域木(Binary Indexed Tree)
 */
