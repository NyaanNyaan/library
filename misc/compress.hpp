#pragma once

template <class T>
struct compress {
  vector<T> xs;
  compress(const vector<T>& v) {
    xs.reserve(v.size());
    for (T x : v) xs.push_back(x);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
  }
  int get(const T& x) const {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
  }
  inline int operator()(const T& x) const { return get(x); }
  T operator[](int i) { return xs[i]; }
  int size() const { return xs.size(); }
};

/**
 * 座標圧縮
 */
