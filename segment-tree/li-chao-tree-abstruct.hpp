#pragma once

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

// Line : T operator(ll) を定義する
template <typename Line, bool MINIMIZE = true, bool RANGE_GET = false>
struct LiChaoTree {
  using T = decltype(Line{}(0));

  vector<long long> xs;
  vector<Line> dat;
  vector<pair<int, T>> val;  // (評価点(座圧後), 評価した値)
  int n, size;
  T inf;

  LiChaoTree(const vector<long long>& _xs, Line I) { init(_xs, I); }
  LiChaoTree(int _n, Line I) {
    vector<long long> _xs(_n);
    for (int i = 0; i < _n; i++) _xs[i] = i;
    init(_xs, I);
  }

  int get_idx(long long x) {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  void add_line(Line f) { return apply(1, f); }

  // [xl, xr) 半開
  void add_segment(long long xl, long long xr, Line f) {
    xl = get_idx(xl), xr = get_idx(xr);
    if (xl == xr) return;
    xl += size, xr += size;
    int l = xl, r = xr;
    for (; xl < xr; xl >>= 1, xr >>= 1) {
      if (xl & 1) apply(xl++, f);
      if (xr & 1) apply(--xr, f);
    }
    if (RANGE_GET) {
      for (int i = 1; i <= __builtin_ctz(size); i++) {
        if (((l >> i) << i) != l) update(l >> i);
        if (((r >> i) << i) != r) update((r - 1) >> i);
      }
    }
  }

  // (値, Line) の組
  pair<T, Line> get_val(long long x) {
    int i = get_idx(x);
    assert(0 <= i and i < n);
    Line f = dat[0];
    T fx = f(x);
    for (i += size; i; i >>= 1) {
      Line g = dat[i];
      T gx = g(x);
      if ((MINIMIZE && gx < fx) || (!MINIMIZE && gx > fx)) {
        f = g, fx = gx;
      }
    }
    return {fx, f};
  }

  // [xl, xr) 半開
  // 返り値 : (評価点 x, x で評価した値)
  // 追加する直線に単調性がある時のみ使用可能
  // RANGE_GET を true にする必要がある
  pair<long long, T> get(long long xl, long long xr) {
    assert(RANGE_GET == true);
    xl = get_idx(xl), xr = get_idx(xr);
    assert(xl != xr);
    pair<int, T> best = _get(1, 0, size, xl, xr);
    assert(best.first != -1);
    return make_pair(xs[best.first], best.second);
  }

 private:
  void init(const vector<long long>& _xs, Line I) {
    xs = _xs;
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    n = xs.size();
    int lg = 1;
    while ((1 << lg) < n) lg++;
    size = 1 << lg;
    dat.resize(size * 2, I);
    inf = (MINIMIZE ? numeric_limits<T>::max() : numeric_limits<T>::min()) / 2;
    val.resize(size * 2, make_pair(-1, inf));
    for (int i = size * 2 - 1; i; i--) update(i);
  }

  T eval(int i, Line f) { return f(xs[min(i, n - 1)]); }

  void apply(int i, Line f) {
    int upper_bit = 31 - __builtin_clz(i);
    int l = (size >> upper_bit) * (i - (1 << upper_bit));
    int r = l + (size >> upper_bit);
    Line g = dat[i];
    T fl = eval(l, f), fr = eval(r - 1, f);
    T gl = eval(l, g), gr = eval(r - 1, g);
    bool bl = (MINIMIZE ? fl < gl : fl > gl);
    bool br = (MINIMIZE ? fr < gr : fr > gr);
    if (!bl and !br) return;
    if (bl and br) {
      dat[i] = f;
    } else {
      int m = (l + r) / 2;
      T fm = eval(m, f), gm = eval(m, g);
      bool bm = (MINIMIZE ? fm < gm : fm > gm);
      if (bm) {
        dat[i] = f;
        f = g;
        apply(i * 2 + bl, f);
      } else {
        apply(i * 2 + 1 - bl, f);
      }
    }
    update(i);
  }

  void update(int i) {
    if constexpr (RANGE_GET) {
      if (i == 0) return;
      int upper_bit = 31 - __builtin_clz(i);
      int l = (size >> upper_bit) * (i - (1 << upper_bit));
      int r = l + (size >> upper_bit);
      val[i] = make_pair(-1, inf);
      auto chmin = [&](int x, T y) {
        if (MINIMIZE ? y < val[i].second : val[i].second < y) {
          val[i] = make_pair(x, y);
        }
      };
      if (l < n) {
        chmin(l, eval(l, dat[i]));
        chmin(min(r - 1, n - 1), eval(r - 1, dat[i]));
      }
      if (i < size) {
        chmin(val[i * 2 + 0].first, val[i * 2 + 0].second);
        chmin(val[i * 2 + 1].first, val[i * 2 + 1].second);
      }
    }
  }

  pair<int, T> _get(int idx, int l, int r, int xl, int xr) {
    assert(l < r and xl < xr);
    assert(l <= xl and xr <= r);
    if (xl == l and xr == r) return val[idx];

    pair<int, T> best = make_pair(-1, inf);
    auto chmin = [&](int x, T y) {
      if (MINIMIZE ? y < best.second : y > best.second) {
        best = make_pair(x, y);
      }
    };

    chmin(xl, eval(xl, dat[idx]));
    chmin(xr - 1, eval(xr - 1, dat[idx]));

    int m = (l + r) / 2;
    if (xl < m) {
      auto [x, y] = _get(idx * 2 + 0, l, m, xl, min(xr, m));
      chmin(x, y);
    }
    if (m < xr) {
      auto [x, y] = _get(idx * 2 + 1, m, r, max(xl, m), xr);
      chmin(x, y);
    }
    return best;
  }
};
