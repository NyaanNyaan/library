#pragma once

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ti)(), E (*ei)()>
struct LazySegmentTreeBase {
  int n, log, s;
  vector<T> val;
  vector<E> laz;

  explicit LazySegmentTreeBase() {}
  explicit LazySegmentTreeBase(const vector<T>& vc) { init(vc); }

  void init(const vector<T>& vc) {
    n = 1, log = 0, s = vc.size();
    while (n < s) n <<= 1, log++;
    val.resize(2 * n, ti());
    laz.resize(n, ei());
    for (int i = 0; i < s; ++i) val[i + n] = vc[i];
    for (int i = n - 1; i; --i) _update(i);
  }

  void update(int l, int r, const E& x) {
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

  T query(int l, int r) {
    if (l == r) return ti();
    l += n, r += n;
    T L = ti(), R = ti();
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) _push(l >> i);
      if (((r >> i) << i) != r) _push((r - 1) >> i);
    }
    while (l < r) {
      if (l & 1) L = f(L, val[l++]);
      if (r & 1) R = f(val[--r], R);
      l >>= 1;
      r >>= 1;
    }
    return f(L, R);
  }

  void set_val(int k, const T& x) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    val[k] = x;
    for (int i = 1; i <= log; i++) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _update(k >> i);
    }
  }

  void update_val(int k, const E& x) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    val[k] = g(val[k], x);
    for (int i = 1; i <= log; i++) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _update(k >> i);
    }
  }

  T get_val(int k) {
    k += n;
    for (int i = log; i >= 1; i--) {
      if (((k >> i) << i) != k || (((k + 1) >> i) << i) != (k + 1))
        _push(k >> i);
    }
    return val[k];
  }

  template <class G>
  int max_right(int l, G check) {
    assert(0 <= l && l <= s);
    assert(check(ti()));
    if (l == n) return n;
    l += n;
    for (int i = log; i >= 1; i--) _push(l >> i);
    T sm = ti();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(f(sm, val[l]))) {
        while (l < n) {
          _push(l);
          l = (2 * l);
          if (check(f(sm, val[l]))) {
            sm = f(sm, val[l]);
            l++;
          }
        }
        return l - n;
      }
      sm = f(sm, val[l]);
      l++;
    } while ((l & -l) != l);
    return s;
  }

  template <class G>
  int min_left(int r, G check) {
    assert(0 <= r && r <= s);
    assert(check(ti()));
    if (r == 0) return 0;
    r += n;
    for (int i = log; i >= 1; i--) _push((r - 1) >> i);
    T sm = ti();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(f(val[r], sm))) {
        while (r < n) {
          _push(r);
          r = (2 * r + 1);
          if (check(f(val[r], sm))) {
            sm = f(val[r], sm);
            r--;
          }
        }
        return r + 1 - n;
      }
      sm = f(val[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  void _push(int i) {
    if (laz[i] != ei()) {
      val[2 * i + 0] = g(val[2 * i + 0], laz[i]);
      val[2 * i + 1] = g(val[2 * i + 1], laz[i]);
      if (2 * i < n) {
        compose(laz[2 * i + 0], laz[i]);
        compose(laz[2 * i + 1], laz[i]);
      }
      laz[i] = ei();
    }
  }
  inline void _update(int i) { val[i] = f(val[2 * i + 0], val[2 * i + 1]); }
  inline void _apply(int i, const E& x) {
    if (x != ei()) {
      val[i] = g(val[i], x);
      if (i < n) compose(laz[i], x);
    }
  }
  inline void compose(E& a, const E& b) { a = a == ei() ? b : h(a, b); }
};

namespace SegmentTreeUtil {

template <typename T>
struct Pair {
  T first, second;
  Pair() = default;
  Pair(const T& f, const T& s) : first(f), second(s) {}
  operator T() const { return first; }
  friend ostream& operator<<(ostream& os, const Pair<T>& p) {
    os << T(p.first);
    return os;
  }
};

template <typename T>
T Mx(T a, T b) {
  return max(a, b);
}
template <typename T>
T Mn(T a, T b) {
  return min(a, b);
}
template <typename T>
T Update(T, T b) {
  return b;
}
template <typename T>
T Add(T a, T b) {
  return a + b;
}
template <typename T>
Pair<T> Psum(Pair<T> a, Pair<T> b) {
  return Pair<T>(a.first + b.first, a.second + b.second);
}
template <typename T>
Pair<T> Padd(Pair<T> a, T b) {
  return Pair<T>(a.first + a.second * b, a.second);
}
template <typename T>
Pair<T> PUpdate(Pair<T> a, T b) {
  return Pair<T>(a.second * b, a.second);
}
template <typename T>
Pair<T> Pid() {
  return Pair<T>(T{}, T{});
}
template <typename T>
T Zero() {
  return T{};
}
template <typename T, T val>
T Const() {
  return val;
}

template <typename T, T MINF>
struct AddMax_LazySegmentTree : LazySegmentTreeBase<T, T, Mx<T>, Add<T>, Add<T>,
                                                    Const<T, MINF>, Zero<T>> {
  using base =
      LazySegmentTreeBase<T, T, Mx<T>, Add<T>, Add<T>, Const<T, MINF>, Zero<T>>;
  AddMax_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T INF>
struct AddMin_LazySegmentTree
    : LazySegmentTreeBase<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>> {
  using base =
      LazySegmentTreeBase<T, T, Mn<T>, Add<T>, Add<T>, Const<T, INF>, Zero<T>>;
  AddMin_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T>
struct AddSum_LazySegmentTree
    : LazySegmentTreeBase<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>,
                          Zero<T>> {
  using base = LazySegmentTreeBase<Pair<T>, T, Psum<T>, Padd<T>, Add<T>, Pid<T>,
                                   Zero<T>>;
  AddSum_LazySegmentTree(const vector<T>& v) {
    vector<Pair<T>> w(v.size());
    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i], 1);
    base::init(w);
  }
};

template <typename T, T MINF>
struct UpdateMax_LazySegmentTree
    : LazySegmentTreeBase<T, T, Mx<T>, Update<T>, Update<T>, Const<T, MINF>,
                          Const<T, MINF>> {
  using base = LazySegmentTreeBase<T, T, Mx<T>, Update<T>, Update<T>,
                                   Const<T, MINF>, Const<T, MINF>>;
  UpdateMax_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T INF>
struct UpdateMin_LazySegmentTree
    : LazySegmentTreeBase<T, T, Mn<T>, Update<T>, Update<T>, Const<T, INF>,
                          Const<T, INF>> {
  using base = LazySegmentTreeBase<T, T, Mn<T>, Update<T>, Update<T>,
                                   Const<T, INF>, Const<T, INF>>;
  UpdateMin_LazySegmentTree(const vector<T>& v) : base(v) {}
};

template <typename T, T UNUSED_VALUE>
struct UpdateSum_LazySegmentTree
    : LazySegmentTreeBase<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>, Pid<T>,
                          Const<T, UNUSED_VALUE>> {
  using base = LazySegmentTreeBase<Pair<T>, T, Psum<T>, PUpdate<T>, Update<T>,
                                   Pid<T>, Const<T, UNUSED_VALUE>>;
  UpdateSum_LazySegmentTree(const vector<T>& v) {
    vector<Pair<T>> w(v.size());
    for (int i = 0; i < (int)v.size(); i++) w[i] = Pair<T>(v[i], 1);
    base::init(w);
  }
};

}  // namespace SegmentTreeUtil
using SegmentTreeUtil::AddMax_LazySegmentTree;
using SegmentTreeUtil::AddMin_LazySegmentTree;
using SegmentTreeUtil::AddSum_LazySegmentTree;
using SegmentTreeUtil::UpdateMax_LazySegmentTree;
using SegmentTreeUtil::UpdateMin_LazySegmentTree;
using SegmentTreeUtil::UpdateSum_LazySegmentTree;

/**
 * @brief 使用頻度の高い遅延セグメント木
 * @docs docs/segment-tree/lazy-segment-tree-utility.md
 */
