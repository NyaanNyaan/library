#pragma once

template <typename Node>
struct Beats {
  int n, log;
  vector<Node> v;

  template <typename T>
  Beats(vector<T>& vc) {
    n = 1, log = 0;
    while (n < (int)vc.size()) n <<= 1, log++;
    v.resize(2 * n);
    for (int i = 0; i < (int)vc.size(); ++i) v[i + n] = Node(vc[i]);
    for (int i = n - 1; i; --i) _update(i);
  }

  template <typename T>
  void apply(int l, int r, T x) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) _apply(l++, x);
        if (r & 1) _apply(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) _update(l >> i);
      if (((r >> i) << i) != r) _update((r - 1) >> i);
    }
  }

  template <typename F>
  void query(int l, int r, const F& f) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    while (l < r) {
      if (l & 1) f(v[l++]);
      if (r & 1) f(v[--r]);
      l >>= 1;
      r >>= 1;
    }
  }

 private:
  void _push(int i) { v[i].push(v[2 * i + 0], v[2 * i + 1]); }
  void _update(int i) { v[i].update(v[2 * i + 0], v[2 * i + 1]); }
  template <typename T>
  void _apply(int i, T x) {
    bool res = v[i].apply(x);
    if (i < n && res == false) {
      _push(i);
      _apply(i * 2 + 0, x);
      _apply(i * 2 + 1, x);
      _update(i);
    }
  }
};

/**
 * @brief 抽象化Segment Tree Beats!
 * @docs docs/segment-tree/segment-tree-beats-abstract.md
 */
