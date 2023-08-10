#pragma once

#include "../misc/rng.hpp"

template <typename Node>
struct TreapBase {
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  Ptr make_tree() { return nullptr; }

  // for avoiding memory leak, activate below
  /*
  using Ptr = shared_ptr<Node>;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return make_shared<Node>(args...);
  }
  Ptr make_tree() {return Ptr();}
  */

  int size(Ptr t) const { return count(t); }

  Ptr merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (l->pr >= r->pr) {
      push(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      push(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Ptr, Ptr> split(Ptr t, int k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Ptr build(const vector<decltype(Node::key)> &v) {
    int n = v.size();
    vector<Ptr> ps;
    ps.reserve(n);
    for (int i = 0; i < n; i++) ps.push_back(my_new(v[i]));
    vector<int> p(n, -1), st;
    for (int i = 0; i < n; i++) {
      int prv = -1;
      while (!st.empty() && ps[i]->pr > ps[st.back()]->pr) {
        prv = st.back();
        st.pop_back();
      }
      if (prv != -1) p[prv] = i;
      if (!st.empty()) p[i] = st.back();
      st.push_back(i);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) {
        if (i < p[i]) {
          ps[p[i]]->l = ps[i];
        } else {
          ps[p[i]]->r = ps[i];
        }
      } else
        root = i;
    }
    dfs(ps[root]);
    return ps[root];
  }

  template <typename... Args>
  void insert(Ptr &t, int k, const Args &...args) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(args...)), x.second);
  }

  void erase(Ptr &t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

 protected:
  void dfs(Ptr r) {
    if (r->l) dfs(r->l);
    if (r->r) dfs(r->r);
    update(r);
  }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  virtual void push(Ptr) {}

  virtual Ptr update(Ptr) = 0;
};

template <typename T, typename E>
struct LazyReversibleTreapNode {
  using Treap = TreapBase<LazyReversibleTreapNode>;
  typename Treap::Ptr l, r;
  T key, sum;
  E lazy;
  int cnt;
  uint32_t pr;
  bool rev;

  LazyReversibleTreapNode(const T &t = T(), const E &e = E())
      : l(),
        r(),
        key(t),
        sum(t),
        lazy(e),
        cnt(1),
        pr(my_rand::rng()),
        rev(false) {}
};

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ts)(T)>
struct LazyReversibleTreap : TreapBase<LazyReversibleTreapNode<T, E>> {
  using Node = LazyReversibleTreapNode<T, E>;
  using base = TreapBase<LazyReversibleTreapNode<T, E>>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  LazyReversibleTreap() = default;

  void toggle(Ptr t) {
    if (!t) return;
    swap(t->l, t->r);
    t->sum = ts(t->sum);
    t->rev ^= true;
  }

  T fold(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  void reverse(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    toggle(y.first);
    t = merge(x.first, merge(y.first, y.second));
  }

  void apply(Ptr &t, int a, int b, const E &e) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    propagate(y.first, e);
    t = merge(x.first, merge(y.first, y.second));
  }

 protected:
  inline T sum(const Ptr t) const { return t ? t->sum : T(); }

  Ptr update(Ptr t) override {
    push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void push(Ptr t) override {
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
    if (t->lazy != E()) {
      if (t->l) propagate(t->l, t->lazy);
      if (t->r) propagate(t->r, t->lazy);
      t->lazy = E();
    }
  }

  void propagate(Ptr t, const E &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }
};

/**
 * @brief 遅延伝搬反転可能Treap
 */
