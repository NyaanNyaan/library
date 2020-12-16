#pragma once

template <typename Node>
struct RBSTBase {
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  inline void my_del(Ptr t) { delete t; }
  inline Ptr make_tree() const { return nullptr; }

  // for avoiding memory leak, activate below
  /*
  using Ptr = shared_ptr<Node>;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return make_shared<Node>(args...);
  }
  inline void my_del(Ptr t) {}
  Ptr make_tree() {return Ptr();}
  */

  int size(Ptr t) const { return count(t); }

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

  Ptr build(int l, int r, const vector<decltype(Node::key)> &v) {
    if (l + 1 == r) return my_new(v[l]);
    int m = (l + r) >> 1;
    Ptr pm = my_new(v[m]);
    if (l < m) pm->l = build(l, m, v);
    if (m + 1 < r) pm->r = build(m + 1, r, v);
    return update(pm);
  }

  Ptr build(const vector<decltype(Node::key)> &v) {
    return build(0, (int)v.size(), v);
  }

  template <typename... Args>
  void insert(Ptr &t, int k, const Args &... args) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(args...)), x.second);
  }

  void erase(Ptr &t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    my_del(y.first);
    t = merge(x.first, y.second);
  }

 protected:
  static uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  virtual void push(Ptr) = 0;

  virtual Ptr update(Ptr) = 0;
};

/**
 * @brief 乱択平衡二分木(基底クラス)
 */
