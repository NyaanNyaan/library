#pragma once



template <typename T, typename E>
struct Range_Weighted_Add_Range_Sum_SegTree {
  int n, height;
  T ti = {0, 0};
  E ei = 0;
  vector<T> dat;
  vector<E> laz;
  Range_Weighted_Add_Range_Sum_SegTree(const vector<T> &v) {
    init((int)v.size());
    build(v);
  }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--) {
      dat[i].first = dat[(i << 1) | 0].first + dat[(i << 1) | 1].first;
      dat[i].second = dat[(i << 1) | 0].second + dat[(i << 1) | 1].second;
    }
  }
  inline T reflect(int k) {
    return laz[k] == ei
               ? dat[k]
               : T{dat[k].first + laz[k] * dat[k].second, dat[k].second};
  }
  inline void eval(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] += laz[k];
    laz[(k << 1) | 1] += laz[k];
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1)
      dat[k].first = reflect((k << 1) | 0).first + reflect((k << 1) | 1).first;
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] += x, l++;
      if (r & 1) --r, laz[r] += x;
    }
    recalc(a);
    recalc(b);
  }
  void update(int a, E x) {
    thrust(a += n);
    laz[a] += x;
    recalc(a);
  }

  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }

  E query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    E ret = ei;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += reflect(l++).first;
      if (r & 1) ret += reflect(--r).first;
    }
    return ret;
  }

  E query(int a) {
    thrust(a += n);
    return reflect(a).first;
  }
};
