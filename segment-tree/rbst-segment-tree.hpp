#pragma once

template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
struct RBSTLazySegmentTree {
  struct Node {
    Node *l, *r;
    I index;
    T key, sum;
    E lazy;
    int cnt;
    Node(const I &i, const T &t = ti())
        : l(), r(), index(i), key(t), sum(t), lazy(ei()), cnt(1) {}
  };

 protected:
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  inline void my_del(Ptr t) { delete t; }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  static uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  Ptr merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
      push(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      push(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  Ptr build(int l, int r, const vector<pair<I, T>> &dat) {
    if (l == r) return nullptr;
    if (l + 1 == r) return my_new(dat[l].first, dat[l].second);
    int m = (l + r) / 2;
    return merge(build(l, m, dat), build(m, r, dat));
  };

  void push(Ptr t) {
    if (!t) return;
    if (t->lazy != ei()) {
      if (t->l) propagate(t->l, t->lazy);
      if (t->r) propagate(t->r, t->lazy);
      t->lazy = ei();
    }
  }

  Ptr update(Ptr t) {
    if (!t) return t;
    //push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void propagate(Ptr t, const E &x) {
    if (!t) return;
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }

  // index が k であるノードを探す, なければ nullptr
  Ptr find(Ptr t, I k) {
    while (t) {
      push(t);
      if (k == t->index) return t;
      if (k < t->index) {
        t = t->l;
      } else {
        t = t->r;
      }
    }
    return nullptr;
  }

  // [k 未満, k 以上]
  pair<Ptr, Ptr> split_left(Ptr t, I k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    if (k == t->index) {
      Ptr tl = t->l;
      t->l = nullptr;
      return {tl, update(t)};
    } else if (k < t->index) {
      auto s = split_left(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split_left(t->r, k);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  // [k 未満, k, k 超過]
  array<Ptr, 3> split_by_index(Ptr t, I k) {
    if (!t) return {{nullptr, nullptr, nullptr}};
    push(t);
    if (k == t->index) {
      Ptr tl = t->l, tr = t->r;
      t->l = t->r = nullptr;
      return {{tl, update(t), tr}};
    } else if (k < t->index) {
      auto s = split_by_index(t->l, k);
      t->l = s[2];
      return {{s[0], s[1], update(t)}};
    } else {
      auto s = split_by_index(t->r, k);
      t->r = s[0];
      return {{update(t), s[1], s[2]}};
    }
  }

  // r 未満
  T _fold_left(Ptr t, I r) {
    if (!t) return ti();
    push(t);
    if (t->index == r) {
      return t->l ? t->l->sum : ti();
    } else if (t->index > r) {
      return _fold_left(t->l, r);
    } else {
      T l = t->l ? t->l->sum : ti();
      l = f(l, t->key);
      return f(l, _fold_left(t->r, r));
    }
  }

  // l 以上
  T _fold_right(Ptr t, I l) {
    if (!t) return ti();
    push(t);
    if (t->index == l) {
      T r = t->r ? t->r->sum : ti();
      return f(t->key, r);
    } else if (t->index < l) {
      return _fold_right(t->r, l);
    } else {
      T r = t->r ? t->r->sum : ti();
      r = f(t->key, r);
      return f(_fold_right(t->l, l), r);
    }
  }

  T _fold(Ptr t, I l, I r) {
    if (!t) return ti();
    push(t);
    if (t->index < l) return _fold(t->r, l, r);
    if (t->index >= r) return _fold(t->l, l, r);
    // l <= t->index < r
    T tl = _fold_right(t->l, l);
    T tr = _fold_left(t->r, r);
    return f(f(tl, t->key), tr);
  }

  // t を根とする木の上で最小の index は？ (t が空の場合は failed)
  I _min_index(Ptr t, const I &failed) {
    if (t == nullptr) return failed;
    while (t->l) t = t->l;
    return t->index;
  }

  // t を根とする木の上で最大の index は？ (t が空の場合は failed)
  I _max_index(Ptr t, const I &failed) {
    if (t == nullptr) return failed;
    while (t->r) t = t->r;
    return t->index;
  }

  // t を根とする木のうち、[0, i の区間 fold が true になる最大の i は何か？
  // exclusive かつ (空 または[0,右]が真の場合) の場合は failed(inf)
  // inclusive かつ (空 または[0,0] が偽の場合) の場合は failed
  template <typename C, bool exclusive>
  I _max_right(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->l != nullptr) {
        push(now->l);
        auto pl = f(prod_now, now->l->sum);
        if (check(pl)) {
          prod_now = pl;
        } else {
          now = now->l;
          continue;
        }
      }
      auto pl = f(prod_now, now->key);
      if (!check(pl)) {
        if constexpr (exclusive) {
          return now->index;
        } else {
          return now->l ? _max_index(now->l, failed) : prev;
        }
      }
      prod_now = pl;
      if (now->r == nullptr) {
        if constexpr (exclusive) {
          return failed;
        } else {
          return now->index;
        }
      }
      push(now->r);
      if constexpr (!exclusive) prev = now->index;
      now = now->r;
    }
  }

  // t を根とする木のうち、i, inf) の区間 fold が true になる最小の i は何か？
  // inclusive かつ (空 または 存在しない) 場合は failed
  // exlucisve かつ (空 または [左, inf) が真) の場合は failed
  template <typename C, bool inclusive>
  I _min_left(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->r != nullptr) {
        push(now->r);
        auto pr = f(now->r->sum, prod_now);
        if (check(pr)) {
          prod_now = pr;
        } else {
          now = now->r;
          continue;
        }
      }
      auto pr = f(now->key, prod_now);
      if (!check(pr)) {
        if constexpr (inclusive) {
          return now->r ? _min_index(now->r, failed) : prev;
        } else {
          return now->index;
        }
      }
      prod_now = pr;
      if (now->l == nullptr) {
        if constexpr (inclusive) {
          return now->index;
        } else {
          return failed;
        }
      }
      push(now->l);
      if constexpr (inclusive) prev = now->index;
      now = now->l;
    }
  }

  void inner_dump(Ptr t) {
    push(t);
    if (t->l) inner_dump(t->l);
    cerr << "## i = " << t->index << ", ";
    cerr << "\tkey = " << t->key << ", ";
    cerr << "\tsum = " << t->sum << ", ";
    cerr << "\tchild = ";
    cerr << "( " << (t->l ? to_string(t->l->index) : "nil");
    cerr << ", ";
    cerr << (t->r ? to_string(t->r->index) : "nil");
    cerr << " )" << endl;
    if (t->r) inner_dump(t->r);
  }

 public:
  Ptr root;

  RBSTLazySegmentTree() : root(nullptr) {}
  RBSTLazySegmentTree(const vector<T> xs, const vector<I> &is = {}) {
    if (!is.empty()) assert(xs.size() == is.size());
    int n = xs.size();
    vector<pair<I, T>> dat(n);
    for (int i = 0; i < n; i++) dat[i] = {is.empty() ? i : is[i], xs[i]};
    root = build(0, n, dat);
  }

  // 1 点 値の書き換え
  void set_val(I i, T x) {
    auto s = split_by_index(root, i);
    if (s[1] == nullptr) {
      s[1] = my_new(i, x);
    } else {
      s[1]->key = x;
    }
    root = merge(merge(s[0], update(s[1])), s[2]);
  }

  // すでに要素が存在するときに値を set する。おそらく少し早い
  void set_val_fast(I i, T x) {
    static vector<Ptr> ps;
    ps.clear();

    Ptr t = root;
    while (t) {
      push(t);
      ps.push_back(t);
      if (i == t->index) break;
      if (i < t->index) {
        t = t->l;
      } else {
        t = t->r;
      }
    }
    if (!t) {
      set_val(i, x);
      return;
    }
    t->key = x;
    for (int j = ps.size() - 1; j >= 0; j--) update(ps[j]);
  }

  // 1 点取得
  T get_val(I i) {
    Ptr p = find(root, i);
    return p ? p->key : ti();
  }

  // 頂点の削除
  void erase(I i) {
    auto s = split_by_index(root, i);
    if (s[1]) my_del(s[1]);
    root = merge(s[0], s[2]);
  }

  // 範囲作用
  void apply(I l, I r, const E &e) {
    auto [x, aux] = split_left(root, l);
    auto [y, z] = split_left(aux, r);
    propagate(y, e);
    root = merge(merge(x, y), z);
  }

  // 範囲取得
  T fold(I l, I r) {
    return _fold(root, l, r);
    // auto [x, aux] = split_left(root, l);
    // auto [y, z] = split_left(aux, r);
    // T res = y ? y->sum : ti();
    // root = merge(merge(x, y), z);
    // return res;
  }

  // n 未満の i のうち、[i, n) の区間 fold が true になる最小の i は何か？
  // (存在しない場合は failed を返す)
  template <typename C>
  I min_left(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _min_left<C, true>(x, check, failed);
    root = merge(x, y);
    return res;
  }

  // n 未満の i のうち、(i, n) の区間 fold が true になる最小の i は何か？
  // (空だったり (左端, n) が 真の場合は minus_infty を返す)
  template <typename C>
  I min_left_exclusive(I n, C check, I minus_infty) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _min_left<C, false>(x, check, minus_infty);
    root = merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i) の区間 fold が true になる最大の i は何か？
  // (空だったり [n, 右端] が true の場合は infty を返す)
  template <typename C>
  I max_right(I n, C check, I infty) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _max_right<C, true>(y, check, infty);
    root = merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i] の区間 fold が true になる最大の i は何か？
  // (存在しない場合は failed を返す)
  template <typename C>
  I max_right_inclusive(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = split_left(root, n);
    I res = _max_right<C, false>(y, check, failed);
    root = merge(x, y);
    return res;
  }

  void dump() { inner_dump(root); }
};

namespace RBSTSegmentTreeImpl {

template <typename T>
T g(T l, bool) {
  return l;
}
bool h(bool, bool) { return false; }
bool ei() { return false; }

template <typename I, typename T, T (*f)(T, T), T (*ti)()>
using RBSTSegmentTree = RBSTLazySegmentTree<I, T, bool, f, g, h, ti, ei>;
}  // namespace RBSTSegmentTreeImpl

using RBSTSegmentTreeImpl::RBSTSegmentTree;

/**
 * @brief RBST-based Dynamic Lazy Segment Tree
 */
