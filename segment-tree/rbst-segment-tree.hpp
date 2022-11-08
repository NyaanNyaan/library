#pragma once

#define ENABLE_HAS_VAR(var)                                  \
  template <typename T>                                      \
  class has_##var {                                          \
    template <typename U, int = (&U::var, 0)>                \
    static true_type check(U *);                             \
    static false_type check(...);                            \
    static T *t;                                             \
                                                             \
   public:                                                   \
    static constexpr bool value = decltype(check(t))::value; \
  };                                                         \
  template <typename T>                                      \
  inline constexpr bool has_##var##_v = has_##var<T>::value;

ENABLE_HAS_VAR(lazy);

template <typename Node, typename I, typename T, typename E, T (*f)(T, T),
          T (*g)(T, E), E (*h)(E, E), T (*ti)(), E (*ei)()>
struct RBSTSegmentTreeBase {
 protected:
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr _my_new(Args... args) {
    return new Node(args...);
  }
  inline void _my_del(Ptr t) { delete t; }

  inline int _count(const Ptr t) const { return t ? t->cnt : 0; }

  T _sum(const Ptr &t) { return t ? t->sum : ti(); }

  static uint64_t _rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  Ptr _merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (int((_rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
      _push(l);
      l->r = _merge(l->r, r);
      return _update(l);
    } else {
      _push(r);
      r->l = _merge(l, r->l);
      return _update(r);
    }
  }

  Ptr _build(int l, int r, const vector<pair<I, T>> &dat) {
    if (l == r) return nullptr;
    if (l + 1 == r) return _my_new(dat[l].first, dat[l].second);
    int m = (l + r) / 2;
    return _merge(_build(l, m, dat), _build(m, r, dat));
  };

  void _push([[maybe_unused]] Ptr t) {
    if constexpr (has_lazy_v<Node>) {
      if (!t) return;
      if (t->lazy != ei()) {
        if (t->l) _propagate(t->l, t->lazy);
        if (t->r) _propagate(t->r, t->lazy);
        t->lazy = ei();
      }
    }
  }

  void _propagate([[maybe_unused]] Ptr t, [[maybe_unused]] const E &x) {
    if constexpr (has_lazy_v<Node>) {
      if (!t) return;
      t->lazy = h(t->lazy, x);
      t->val = g(t->val, x);
      t->sum = g(t->sum, x);
    }
  }

  Ptr _update(Ptr t) {
    if (!t) return t;
    t->cnt = 1;
    t->sum = t->val;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  // key が k であるノードを探す, なければ nullptr
  Ptr _find(Ptr t, I k) {
    while (t) {
      _push(t);
      if (k == t->key) return t;
      t = k < t->key ? t->l : t->r;
    }
    return nullptr;
  }

  void _erase(Ptr &t, I k) {
    if (!t) return;
    _push(t);
    if (k == t->key) {
      Ptr tl = t->l, tr = t->r;
      _my_del(t);
      t = _merge(tl, tr);
    } else if (k < t->key) {
      _erase(t->l, k);
      _update(t);
    } else {
      _erase(t->r, k);
      _update(t);
    }
  }

  // [k 未満, k 以上]
  pair<Ptr, Ptr> _split_left(Ptr t, I k) {
    if (!t) return {nullptr, nullptr};
    _push(t);
    if (k == t->key) {
      Ptr tl = t->l;
      t->l = nullptr;
      return {tl, _update(t)};
    } else if (k < t->key) {
      auto s = _split_left(t->l, k);
      t->l = s.second;
      return {s.first, _update(t)};
    } else {
      auto s = _split_left(t->r, k);
      t->r = s.first;
      return {_update(t), s.second};
    }
  }

  // (-inf, i] の prod について check(prod) の (true / false) で切る
  template <typename C>
  pair<Ptr, Ptr> _split_by_cond_left(Ptr t, const C &check, T prod = T{}) {
    assert(check(prod));
    if (!t) return {nullptr, nullptr};
    _push(t);
    T p1 = f(prod, _sum(t->l));
    if (check(p1)) {
      prod = p1;
    } else {
      auto s = _split_by_cond_left(t->l, check, prod);
      t->l = s.second;
      return {s.first, _update(t)};
    }
    prod = f(prod, t->val);
    if (!check(prod)) {
      Ptr tl = t->l;
      t->l = nullptr;
      return {tl, _update(t)};
    }
    p1 = f(prod, _sum(t->r));
    if (check(p1)) {
      return {t, nullptr};
    } else {
      auto s = _split_by_cond_left(t->r, check, prod);
      t->r = s.first;
      return {_update(t), s.second};
    }
  }

  // [i, inf) の prod について check(prod) の (false / true) で切る
  template <typename C>
  pair<Ptr, Ptr> _split_by_cond_right(Ptr t, const C &check, T prod = T{}) {
    assert(check(prod));
    if (!t) return {nullptr, nullptr};
    _push(t);
    T p1 = f(_sum(t->r), prod);
    if (check(p1)) {
      prod = p1;
    } else {
      auto s = _split_by_cond_right(t->r, check, prod);
      t->r = s.first;
      return {_update(t), s.second};
    }
    prod = f(t->val, prod);
    if (!check(prod)) {
      Ptr tr = t->r;
      t->r = nullptr;
      return {_update(t), tr};
    }
    p1 = f(_sum(t->l), prod);
    if (check(p1)) {
      return {nullptr, t};
    } else {
      auto s = _split_by_cond_right(t->l, check, prod);
      t->l = s.second;
      return {s.first, _update(t)};
    }
  }

  // [k 未満, k, k 超過]
  array<Ptr, 3> _split_by_key(Ptr t, I k) {
    if (!t) return {{nullptr, nullptr, nullptr}};
    _push(t);
    if (k == t->key) {
      Ptr tl = t->l, tr = t->r;
      t->l = t->r = nullptr;
      return {{tl, _update(t), tr}};
    } else if (k < t->key) {
      auto s = _split_by_key(t->l, k);
      t->l = s[2];
      return {{s[0], s[1], _update(t)}};
    } else {
      auto s = _split_by_key(t->r, k);
      t->r = s[0];
      return {{_update(t), s[1], s[2]}};
    }
  }

  // [l, inf) である地点に apply
  void _apply_left(Ptr t, I l, const E &e) {
    if (!t) return;
    _push(t);
    if (t->key < l) {
      _apply_left(t->r, l, e);
    } else if (t->key == l) {
      t->val = g(t->val, e);
      _propagate(t->r, e);
    } else {
      _apply_left(t->l, l, e);
      t->val = g(t->val, e);
      _propagate(t->r, e);
    }
    _update(t);
  }

  // [-inf, r) である地点に apply
  void _apply_right(Ptr t, I r, const E &e) {
    if (!t) return;
    _push(t);
    if (t->key < r) {
      _propagate(t->l, e);
      t->val = g(t->val, e);
      _apply_right(t->r, r, e);
    } else if (t->key == r) {
      _propagate(t->l, e);
    } else {
      _apply_right(t->l, r, e);
    }
    _update(t);
  }

  // [l, r) に apply
  void _apply(Ptr t, I l, I r, const E &e) {
    if (!t) return;
    _push(t);
    if (t->key < l) {
      _apply(t->r, l, r, e);
    } else if (t->key == l) {
      t->val = g(t->val, e);
      _apply_right(t->r, r, e);
    } else if (t->key < r) {
      _apply_left(t->l, l, e);
      t->val = g(t->val, e);
      _apply_right(t->r, r, e);
    } else if (t->key == r) {
      _apply_left(t->l, l, e);
    } else {
      _apply(t->l, l, r, e);
    }
    _update(t);
  }

  // l 以上
  T _fold_left(Ptr t, I l) {
    if (!t) return ti();
    _push(t);
    if (t->key < l) {
      return _fold_left(t->r, l);
    } else if (t->key == l) {
      return f(t->val, _fold_left(t->r, l));
    } else {
      T tl = _fold_left(t->l, l);
      return f(f(tl, t->val), _sum(t->r));
    }
  }

  // r 未満
  T _fold_right(Ptr t, I r) {
    if (!t) return ti();
    _push(t);
    if (t->key < r) {
      T tr = _fold_right(t->r, r);
      return f(f(_sum(t->l), t->val), tr);
    } else if (t->key == r) {
      return _sum(t->l);
    } else {
      return _fold_right(t->l, r);
    }
  }

  T _fold(Ptr t, I l, I r) {
    if (!t) return ti();
    _push(t);
    if (t->key < l) {
      return _fold(t->r, l, r);
    } else if (t->key == l) {
      return f(t->val, _fold_right(t->r, r));
    } else if (t->key < r) {
      T tl = _fold_left(t->l, l);
      T tr = _fold_right(t->r, r);
      return f(f(tl, t->val), tr);
    } else if (t->key == r) {
      return _fold_left(t->l, l);
    } else {
      return _fold(t->l, l, r);
    }
  }

  // t を根とする木の上で最小の key は？ (t が空の場合は failed)
  pair<I, T> _get_min_keyval(Ptr t, const I &failed) {
    if (t == nullptr) return {failed, ti()};
    while (t->l) _push(t), t = t->l;
    return {t->key, t->val};
  }

  // t を根とする木の上で最小の key は？ (t が空の場合は failed)
  pair<I, T> _get_max_keyval(Ptr t, const I &failed) {
    if (t == nullptr) return {failed, ti()};
    while (t->r) _push(t), t = t->r;
    return {t->key, t->val};
  }

  // t を根とする木のうち、[0, i の区間 fold が true になる最大の i は何か？
  // exclusive かつ (空 または[0,右]が真の場合) の場合は failed(inf)
  // inclusive かつ (空 または[0,0] が偽の場合) の場合は failed
  template <typename C, bool exclusive>
  I _max_right(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    _push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->l != nullptr) {
        _push(now->l);
        auto pl = f(prod_now, now->l->sum);
        if (check(pl)) {
          prod_now = pl;
        } else {
          now = now->l;
          continue;
        }
      }
      auto pl = f(prod_now, now->val);
      if (!check(pl)) {
        if constexpr (exclusive) {
          return now->key;
        } else {
          return now->l ? _get_max_keyval(now->l, failed).first : prev;
        }
      }
      prod_now = pl;
      if (now->r == nullptr) {
        if constexpr (exclusive) {
          return failed;
        } else {
          return now->key;
        }
      }
      _push(now->r);
      if constexpr (!exclusive) prev = now->key;
      now = now->r;
    }
  }

  // t を根とする木のうち、i, inf) の区間 fold が true になる最小の i は何か？
  // inclusive かつ (空 または 存在しない) 場合は failed
  // exlucisve かつ (空 または [左, inf) が真) の場合は failed
  template <typename C, bool inclusive>
  I _min_left(Ptr t, C check, const I &failed) {
    if (t == nullptr) return failed;
    _push(t);
    Ptr now = t;
    T prod_now = ti();
    [[maybe_unused]] I prev = failed;
    while (true) {
      if (now->r != nullptr) {
        _push(now->r);
        auto pr = f(now->r->sum, prod_now);
        if (check(pr)) {
          prod_now = pr;
        } else {
          now = now->r;
          continue;
        }
      }
      auto pr = f(now->val, prod_now);
      if (!check(pr)) {
        if constexpr (inclusive) {
          return now->r ? _get_min_keyval(now->r, failed).first : prev;
        } else {
          return now->key;
        }
      }
      prod_now = pr;
      if (now->l == nullptr) {
        if constexpr (inclusive) {
          return now->key;
        } else {
          return failed;
        }
      }
      _push(now->l);
      if constexpr (inclusive) prev = now->key;
      now = now->l;
    }
  }

  void _clear(Ptr t) {
    if (!t) return;
    if (t->l) _clear(t->l);
    if (t->r) _clear(t->r);
    _my_del(t);
  }

  Ptr _copy(Ptr t) {
    if (!t) return nullptr;
    Ptr u = _my_new(*t);
    if (u->l) u->l = _copy(u->l);
    if (u->r) u->r = _copy(u->r);
    return u;
  }

  void _dump(Ptr t) {
    _push(t);
    if (t->l) _dump(t->l);
    cerr << "## i = " << t->key << ", ";
    cerr << "\tkey = " << t->val << ", ";
    cerr << "\tsum = " << t->sum << ", ";
    cerr << "\tchild = ";
    cerr << "( " << (t->l ? to_string(t->l->key) : "nil");
    cerr << ", ";
    cerr << (t->r ? to_string(t->r->key) : "nil");
    cerr << " )" << endl;
    if (t->r) _dump(t->r);
  }

  void _make_array(Ptr t, vector<pair<I, T>> &v) {
    if (!t) return;
    _push(t);
    if (t->l) _make_array(t->l, v);
    v.emplace_back(t->key, t->val);
    if (t->r) _make_array(t->r, v);
  }

 public:
  Ptr root;

  RBSTSegmentTreeBase() : root(nullptr) {}
  RBSTSegmentTreeBase(const vector<T> xs, const vector<I> &vals = {}) {
    if (!vals.empty()) assert(xs.size() == vals.size());
    int n = xs.size();
    vector<pair<I, T>> dat(n);
    for (int i = 0; i < n; i++) dat[i] = {vals.empty() ? i : vals[i], xs[i]};
    root = _build(0, n, dat);
  }
  RBSTSegmentTreeBase(RBSTSegmentTreeBase &&rhs) noexcept { root = rhs.root; }
  RBSTSegmentTreeBase(const RBSTSegmentTreeBase &rhs) {
    root = _copy(rhs.root);
  }
  ~RBSTSegmentTreeBase() = default;

  using RBST = RBSTSegmentTreeBase;
  RBST &operator=(RBST &&rhs) noexcept {
    root = rhs.root;
    return *this;
  }
  RBST &operator=(const RBST &rhs) {
    root = _copy(rhs.root);
    return *this;
  }

  friend void swap(RBST &lhs, RBST &rhs) { swap(lhs.root, rhs.root); }
  void swap(RBST &rhs) { swap(root, rhs.root); }

  // destructive ordered _merge (max(lhs) < min(rhs))
  friend RBST ordered_merge(RBST &lhs, RBST &rhs) {
    assert(lhs.get_max_key() < rhs.get_min_key());
    RBST res;
    res.root = res._merge(lhs, rhs);
    return res;
  }

  // 1 点 値の書き換え
  void set_val(I i, T x) {
    auto s = _split_by_key(root, i);
    if (s[1] == nullptr) {
      s[1] = _my_new(i, x);
    } else {
      s[1]->val = x;
    }
    root = _merge(_merge(s[0], _update(s[1])), s[2]);
  }

  // すでに要素が存在するときに値を set する。おそらく少し早い
  void set_val_fast(I i, T x) {
    static vector<Ptr> ps;
    ps.clear();

    Ptr t = root;
    while (t) {
      _push(t);
      ps.push_back(t);
      if (i == t->key) break;
      if (i < t->key) {
        t = t->l;
      } else {
        t = t->r;
      }
    }
    if (!t) {
      set_val(i, x);
      return;
    }
    t->val = x;
    for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);
  }

  // 1 点取得
  T get_val(I i) {
    Ptr p = _find(root, i);
    return p ? p->val : ti();
  }

  // 1 点 値の書き換え
  // func の返り値は void !!!!!!(参照された値を直接更新する)
  void apply_val(I i, const function<void(T &)> &func) {
    auto s = _split_by_key(root, i);
    if (s[1] == nullptr) s[1] = _my_new(i);
    func(s[1]->val);
    root = _merge(_merge(s[0], _update(s[1])), s[2]);
  }
  // 1 点 値の書き換え 値が既に存在するときに早い
  // func の返り値は void !!!!!!(参照された値を直接更新する)
  void apply_val_fast(I i, const function<void(T &)> &func) {
    static vector<Ptr> ps;
    ps.clear();
    Ptr t = root;
    while (t) {
      _push(t);
      ps.push_back(t);
      if (i == t->key) break;
      t = i < t->key ? t->l : t->r;
    }
    if (!t) {
      apply_val(i, func);
      return;
    }
    func(t->val);
    for (int j = ps.size() - 1; j >= 0; j--) _update(ps[j]);
  }

  // 頂点の削除
  void erase(I i) { _erase(root, i); }

  // 範囲作用
  void apply(I l, I r, const E &e) {
    if (l >= r) return;
    _apply(root, l, r, e);
  }

  // 範囲取得
  T fold(I l, I r) {
    if (l >= r) return ti();
    return _fold(root, l, r);
  }
  T fold_all() { return _sum(root); }

  // key 最小を取得
  I get_min_key(I failed = -1) { return _get_min_keyval(root, failed).first; }
  // key 最大を取得
  I get_max_key(I failed = -1) { return _get_max_keyval(root, failed).first; }
  // (key, val) 最小を取得
  pair<I, T> get_min_keyval(I failed = -1) {
    return _get_min_keyval(root, failed);
  }
  // (key, val) 最大を取得
  pair<I, T> get_max_keyval(I failed = -1) {
    return _get_max_keyval(root, failed);
  }
  // (key, val) 最小を pop
  pair<I, T> pop_min_keyval(I failed = -1) {
    assert(root != nullptr);
    auto kv = _get_min_keyval(root, failed);
    erase(kv.first);
    return kv;
  }
  // (key, val) 最大を取得
  pair<I, T> pop_max_keyval(I failed = -1) {
    assert(root != nullptr);
    auto kv = _get_max_keyval(root, failed);
    erase(kv.first);
    return kv;
  }

  // n 未満の i のうち、[i, n) の区間 fold が true になる最小の i は何か？
  // (存在しない場合は failed を返す)
  template <typename C>
  I min_left(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = _split_left(root, n);
    I res = _min_left<C, true>(x, check, failed);
    root = _merge(x, y);
    return res;
  }

  // n 未満の i のうち、(i, n) の区間 fold が true になる最小の i は何か？
  // (空だったり (左端, n) が 真の場合は minus_infty を返す)
  template <typename C>
  I min_left_exclusive(I n, C check, I minus_infty) {
    assert(check(ti()) == true);
    auto [x, y] = _split_left(root, n);
    I res = _min_left<C, false>(x, check, minus_infty);
    root = _merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i) の区間 fold が true になる最大の i は何か？
  // (空だったり [n, 右端] が true の場合は infty を返す)
  template <typename C>
  I max_right(I n, C check, I infty) {
    assert(check(ti()) == true);
    auto [x, y] = _split_left(root, n);
    I res = _max_right<C, true>(y, check, infty);
    root = _merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i] の区間 fold が true になる最大の i は何か？
  // (存在しない場合は failed を返す)
  template <typename C>
  I max_right_inclusive(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = _split_left(root, n);
    I res = _max_right<C, false>(y, check, failed);
    root = _merge(x, y);
    return res;
  }

  void clear() { _clear(root), root = nullptr; }
  int size() { return _count(root); }
  bool empty() { return !root; }
  void dump() { _dump(root); }

  // 列を配列に変換して返す
  vector<pair<I, T>> make_array() {
    vector<pair<I, T>> res;
    _make_array(root, res);
    return res;
  }
};

namespace RBSTSegmentTreeImpl {

template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
struct LazySegNode {
  LazySegNode *l, *r;
  I key;
  T val, sum;
  E lazy;
  int cnt;
  LazySegNode(const I &i, const T &t = ti())
      : l(), r(), key(i), val(t), sum(t), lazy(ei()), cnt(1) {}
};
template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
using RBSTLazySegmentTree =
    RBSTSegmentTreeBase<LazySegNode<I, T, E, f, g, h, ti, ei>, I, T, E, f, g, h,
                        ti, ei>;

bool ei() { return false; }
template <typename I, typename T, T (*f)(T, T), T (*ti)()>
struct SegNode {
  SegNode *l, *r;
  I key;
  T val, sum;
  int cnt;
  SegNode(const I &i, const T &t = ti())
      : l(), r(), key(i), val(t), sum(t), cnt(1) {}
};
template <typename I, typename T, T (*f)(T, T), T (*ti)()>
using RBSTSegmentTree = RBSTSegmentTreeBase<SegNode<I, T, f, ti>, I, T, bool, f,
                                            nullptr, nullptr, ti, ei>;

}  // namespace RBSTSegmentTreeImpl

using RBSTSegmentTreeImpl::RBSTLazySegmentTree;
using RBSTSegmentTreeImpl::RBSTSegmentTree;

/**
 * @brief RBST-based Dynamic Lazy Segment Tree
 */
