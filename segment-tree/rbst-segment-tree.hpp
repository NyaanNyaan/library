#pragma once

#include "../internal/internal-type-traits.hpp"

ENABLE_HAS_VAR(lazy);
ENABLE_HAS_VAR(shift);

template <typename Node, typename I, typename T, typename E, T (*f)(T, T),
          T (*g)(T, E), E (*h)(E, E), T (*ti)(), E (*ei)()>
struct RBSTSegmentTreeBase {
 protected:
  using Ptr = Node *;
  template <typename... Args>
  static Ptr _my_new(Args... args) {
    return new Node(args...);
  }
  static void _my_del(Ptr t) { delete t; }

  static int _count(const Ptr t) { return t ? t->cnt : 0; }

  static T _sum(const Ptr &t) { return t ? t->sum : ti(); }

  static uint64_t _rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  static Ptr _merge(Ptr l, Ptr r) {
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

  static Ptr _build(int l, int r, const vector<pair<I, T>> &dat) {
    if (l == r) return nullptr;
    if (l + 1 == r) return _my_new(dat[l].first, dat[l].second);
    int m = (l + r) / 2;
    return _merge(_build(l, m, dat), _build(m, r, dat));
  };

  static void _push([[maybe_unused]] Ptr t) {
    if constexpr (has_lazy_v<Node>) {
      if (!t) return;
      if (t->lazy != ei()) {
        if (t->l) _propagate(t->l, t->lazy);
        if (t->r) _propagate(t->r, t->lazy);
        t->lazy = ei();
      }
    }
    if constexpr (has_shift_v<Node>) {
      if (!t) return;
      if (t->shift != I{}) {
        if (t->l) _shift(t->l, t->shift);
        if (t->r) _shift(t->r, t->shift);
        t->shift = I{};
      }
    }
  }
  static void _propagate([[maybe_unused]] Ptr t, [[maybe_unused]] const E &x) {
    if constexpr (has_lazy_v<Node>) {
      if (!t) return;
      t->lazy = h(t->lazy, x);
      t->val = g(t->val, x);
      t->sum = g(t->sum, x);
    }
  }
  static void _shift([[maybe_unused]] Ptr t, [[maybe_unused]] const I &sh) {
    if constexpr (has_shift_v<Node>) {
      if (!t) return;
      t->key += sh, t->shift += sh;
    }
  }

  static Ptr _update(Ptr t) {
    if (!t) return t;
    t->cnt = 1;
    t->sum = t->val;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  // key が k であるノードを探す, なければ nullptr
  static Ptr _find(Ptr t, I k) {
    while (t) {
      _push(t);
      if (k == t->key) return t;
      t = k < t->key ? t->l : t->r;
    }
    return nullptr;
  }

  static void _erase(Ptr &t, I k) {
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
  static pair<Ptr, Ptr> _split_by_key(Ptr t, I k) {
    if (!t) return {nullptr, nullptr};
    _push(t);
    if (k == t->key) {
      Ptr tl = t->l;
      t->l = nullptr;
      return {tl, _update(t)};
    } else if (k < t->key) {
      auto s = _split_by_key(t->l, k);
      t->l = s.second;
      return {s.first, _update(t)};
    } else {
      auto s = _split_by_key(t->r, k);
      t->r = s.first;
      return {_update(t), s.second};
    }
  }

  // [k 未満, k, k 超過]
  static array<Ptr, 3> _split_by_key3(Ptr t, I k) {
    if (!t) return {{nullptr, nullptr, nullptr}};
    _push(t);
    if (k == t->key) {
      Ptr tl = t->l, tr = t->r;
      t->l = t->r = nullptr;
      return {{tl, _update(t), tr}};
    } else if (k < t->key) {
      auto s = _split_by_key3(t->l, k);
      t->l = s[2];
      return {{s[0], s[1], _update(t)}};
    } else {
      auto s = _split_by_key3(t->r, k);
      t->r = s[0];
      return {{_update(t), s[1], s[2]}};
    }
  }

  // (-inf, i] の prod について check(prod) の (true / false) で切る
  template <typename C>
  static pair<Ptr, Ptr> _split_max_right(Ptr t, const C &check, T prod = ti()) {
    assert(check(prod));
    if (!t) return {nullptr, nullptr};
    _push(t);
    T p1 = f(prod, _sum(t->l));
    if (check(p1)) {
      prod = p1;
    } else {
      auto s = _split_max_right(t->l, check, prod);
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
      auto s = _split_max_right(t->r, check, prod);
      t->r = s.first;
      return {_update(t), s.second};
    }
  }

  // [i, inf) の prod について check(prod) の (false / true) で切る
  template <typename C>
  static pair<Ptr, Ptr> _split_min_left(Ptr t, const C &check, T prod = ti()) {
    assert(check(prod));
    if (!t) return {nullptr, nullptr};
    _push(t);
    T p1 = f(_sum(t->r), prod);
    if (check(p1)) {
      prod = p1;
    } else {
      auto s = _split_min_left(t->r, check, prod);
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
      auto s = _split_min_left(t->l, check, prod);
      t->l = s.second;
      return {s.first, _update(t)};
    }
  }

  // [l, inf) である地点に apply
  static void _apply_left(Ptr t, I l, const E &e) {
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
  static void _apply_right(Ptr t, I r, const E &e) {
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
  static void _apply(Ptr t, I l, I r, const E &e) {
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
  static T _fold_left(Ptr t, I l) {
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
  static T _fold_right(Ptr t, I r) {
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

  static T _fold(Ptr t, I l, I r) {
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
  static pair<I, T> _get_min_keyval(Ptr t, const I &failed) {
    if (!t) return {failed, ti()};
    while (t->l) _push(t), t = t->l;
    return {t->key, t->val};
  }

  // t を根とする木の上で最小の key は？ (t が空の場合は failed)
  static pair<I, T> _get_max_keyval(Ptr t, const I &failed) {
    if (!t) return {failed, ti()};
    while (t->r) _push(t), t = t->r;
    return {t->key, t->val};
  }

  // t を根とする木のうち、[0, i の区間 fold が true になる最大の i は何か？
  // exclusive かつ (空 または[0,右]が真の場合) の場合は failed(inf)
  // inclusive かつ (空 または[0,0] が偽の場合) の場合は failed
  template <typename C, bool exclusive>
  static I _max_right(Ptr t, C check, const I &failed) {
    if (!t) return failed;
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
  static I _min_left(Ptr t, C check, const I &failed) {
    if (!t) return failed;
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

  static void _clear(Ptr t) {
    if (!t) return;
    if (t->l) _clear(t->l);
    if (t->r) _clear(t->r);
    _my_del(t);
  }

  static Ptr _deepcopy(Ptr t) {
    if (!t) return nullptr;
    Ptr u = _my_new(*t);
    if (u->l) u->l = _deepcopy(u->l);
    if (u->r) u->r = _deepcopy(u->r);
    return u;
  }

  static void _dump(Ptr t) {
    if (!t) return;
    _push(t);
    _dump(t->l);
    cerr << "## key = " << t->key << ",";
    cerr << "\tval = " << t->val << ", ";
    cerr << "\tsum = " << t->sum << ", ";
    cerr << "\tchild = ";
    cerr << "( ";
    if (t->l) cerr << t->l->key;
    if (!t->l) cerr << "nil";
    cerr << ", ";
    if (t->r) cerr << t->r->key;
    if (!t->r) cerr << "nil";
    cerr << " )" << endl;
    _dump(t->r);
  }

  static void _make_array(Ptr t, vector<pair<I, T>> &v) {
    if (!t) return;
    _push(t);
    if (t->l) _make_array(t->l, v);
    v.emplace_back(t->key, t->val);
    if (t->r) _make_array(t->r, v);
  }

 public:
  Ptr root;

  RBSTSegmentTreeBase() : root(nullptr) {}
  RBSTSegmentTreeBase(Ptr t) : root(t) {}
  RBSTSegmentTreeBase(const vector<T> xs, const vector<I> &vals = {}) {
    if (!vals.empty()) assert(xs.size() == vals.size());
    int n = xs.size();
    vector<pair<I, T>> dat(n);
    for (int i = 0; i < n; i++) dat[i] = {vals.empty() ? i : vals[i], xs[i]};
    root = _build(0, n, dat);
  }
  RBSTSegmentTreeBase(RBSTSegmentTreeBase &&rhs) noexcept { root = rhs.root; }
  RBSTSegmentTreeBase(const RBSTSegmentTreeBase &rhs) { root = rhs.root; }
  ~RBSTSegmentTreeBase() = default;

  using RBST = RBSTSegmentTreeBase;
  RBST &operator=(RBST &&rhs) noexcept {
    root = rhs.root;
    return *this;
  }
  RBST &operator=(const RBST &rhs) {
    root = rhs.root;
    return *this;
  }
  RBST deepcopy() { return _deepcopy(root); }

  friend void swap(RBST &lhs, RBST &rhs) { swap(lhs.root, rhs.root); }
  void swap(RBST &rhs) { swap(root, rhs.root); }

  // destructive ordered _merge (max(lhs) < min(rhs))
  friend RBST ordered_merge(RBST &lhs, RBST &rhs) {
    assert(lhs.get_max_key() < rhs.get_min_key());
    return RBST{_merge(lhs.root, rhs.root)};
  }

  // 1 点 値の書き換え
  void set_val(I i, T x) {
    auto s = _split_by_key3(root, i);
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
      t = i < t->key ? t->l : t->r;
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
  bool exist(I i) {
    Ptr p = _find(root, i);
    return p != nullptr;
  }

  // 1 点 値の書き換え
  // func の返り値は void !!!!!!(参照された値を直接更新する)
  void apply_val(I i, const function<void(T &)> &func) {
    auto s = _split_by_key3(root, i);
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
  virtual void erase(I i) { _erase(root, i); }

  // 範囲作用
  void apply(I l, I r, const E &e) {
    if (l >= r) return;
    _apply(root, l, r, e);
  }
  void apply_all(const E &e) { _propagate(root, e); }

  // 範囲取得
  T fold(I l, I r) {
    if (l >= r) return ti();
    return _fold(root, l, r);
  }
  T fold_all() { return _sum(root); }

  void shift(const I &sh) { _shift(root, sh); }

  // key 最小を取得
  I get_min_key(I failed = {}) { return _get_min_keyval(root, failed).first; }
  // key 最大を取得
  I get_max_key(I failed = {}) { return _get_max_keyval(root, failed).first; }
  // (key, val) 最小を取得
  pair<I, T> get_min_keyval(I failed = {}) {
    return _get_min_keyval(root, failed);
  }
  // (key, val) 最大を取得
  pair<I, T> get_max_keyval(I failed = {}) {
    return _get_max_keyval(root, failed);
  }
  // (key, val) 最小を pop
  pair<I, T> pop_min_keyval(I failed = {}) {
    assert(root != nullptr);
    auto kv = _get_min_keyval(root, failed);
    erase(kv.first);
    return kv;
  }
  // (key, val) 最大を取得
  pair<I, T> pop_max_keyval(I failed = {}) {
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
    auto [x, y] = _split_by_key(root, n);
    I res = _min_left<C, true>(x, check, failed);
    root = _merge(x, y);
    return res;
  }

  // n 未満の i のうち、(i, n) の区間 fold が true になる最小の i は何か？
  // (空だったり (左端, n) が 真の場合は minus_infty を返す)
  template <typename C>
  I min_left_exclusive(I n, C check, I minus_infty) {
    assert(check(ti()) == true);
    auto [x, y] = _split_by_key(root, n);
    I res = _min_left<C, false>(x, check, minus_infty);
    root = _merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i) の区間 fold が true になる最大の i は何か？
  // (空だったり [n, 右端] が true の場合は infty を返す)
  template <typename C>
  I max_right(I n, C check, I infty) {
    assert(check(ti()) == true);
    auto [x, y] = _split_by_key(root, n);
    I res = _max_right<C, true>(y, check, infty);
    root = _merge(x, y);
    return res;
  }

  // n 以上の i のうち、[n, i] の区間 fold が true になる最大の i は何か？
  // (存在しない場合は failed を返す)
  template <typename C>
  I max_right_inclusive(I n, C check, I failed) {
    assert(check(ti()) == true);
    auto [x, y] = _split_by_key(root, n);
    I res = _max_right<C, false>(y, check, failed);
    root = _merge(x, y);
    return res;
  }

  // (key 未満, key 以上) で分割
  // 呼び出し後のオブジェクトは空のセグ木になる
  pair<RBST, RBST> split_by_key(const I &key) {
    auto [x, y] = _split_by_key(root, key);
    root = nullptr;
    return make_pair(RBST{x}, RBST{y});
  }
  // [i, inf) の区間積が (false, true) になる境界で分割
  // 呼び出し後のオブジェクトは空のセグ木になる
  template <typename C>
  pair<RBST, RBST> split_min_left(const C &check) {
    assert(check(ti()) == true);
    auto [x, y] = _split_min_left(root, check);
    root = nullptr;
    return make_pair(RBST{x}, RBST{y});
  }
  // (-inf, i] の区間積が (true, false) になる境界で分割
  // 呼び出し後のオブジェクトは空のセグ木になる
  template <typename C>
  pair<RBST, RBST> split_max_right(const C &check) {
    assert(check(ti()) == true);
    auto [x, y] = _split_max_right(root, check);
    root = nullptr;
    return make_pair(RBST{x}, RBST{y});
  }

  void clear() { _clear(root), root = nullptr; }
  int size() { return _count(root); }
  bool empty() { return !root; }
  void dump() {
    cerr << "***** dump start *****" << endl;
    _dump(root);
    cerr << "****** dump end ******" << endl;
  }

  // 列を配列に変換して返す
  vector<pair<I, T>> make_array() {
    vector<pair<I, T>> res;
    _make_array(root, res);
    return res;
  }
};

namespace RBSTSegmentTreeImpl {
bool _ei() { return false; }

template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
struct ShiftableLazySegNode {
  ShiftableLazySegNode *l, *r;
  I key, shift;
  T val, sum;
  E lazy;
  int cnt;
  ShiftableLazySegNode(const I &i, const T &t = ti())
      : l(), r(), key(i), shift(I{}), val(t), sum(t), lazy(ei()), cnt(1) {}
};
template <typename I, typename T, typename E, T (*f)(T, T), T (*g)(T, E),
          E (*h)(E, E), T (*ti)(), E (*ei)()>
using RBSTShiftableLazySegmentTree =
    RBSTSegmentTreeBase<ShiftableLazySegNode<I, T, E, f, g, h, ti, ei>, I, T, E,
                        f, g, h, ti, ei>;

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
                                            nullptr, nullptr, ti, _ei>;

}  // namespace RBSTSegmentTreeImpl

using RBSTSegmentTreeImpl::RBSTLazySegmentTree;
using RBSTSegmentTreeImpl::RBSTSegmentTree;
using RBSTSegmentTreeImpl::RBSTShiftableLazySegmentTree;

/**
 * @brief RBST-based Dynamic Lazy Segment Tree
 */
