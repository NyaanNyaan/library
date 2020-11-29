#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename E>
struct AddSum_LazySegmentTree {
  int n, height;
  using T = pair<E, E>;
  T f(T a, T b) { return T(a.first + b.first, a.second + b.second); };
  T g(T a, E b) { return T(a.first + b * a.second, a.second); };
  E h(E a, E b) { return a + b; };
  T ti = T(0, 0);
  E ei = 0;
  vector<T> dat;
  vector<E> laz;

  AddSum_LazySegmentTree(const vector<E> &v) { build(v); }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }

  void build(const vector<E> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = T(v[i], 1);
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }

  inline void propagate(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }

  inline void thrust(int k) {
    for (int i = height; i; i--) propagate(k >> i);
  }

  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }

  void update(int a, int b, E x) {
    if (a >= b) return;
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }

  E query(int a, int b) {
    if (a >= b) return ti.first;
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr).first;
  }
};