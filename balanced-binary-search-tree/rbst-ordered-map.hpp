#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../misc/vector-pool.hpp"

template <typename Key, typename Val>
struct OrderedMap {
  uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    x_ = x_ ^ (x_ >> 9);
    return x_ & 0xFFFFFFFFull;
  }

  using NodePtr = uint32_t;
  struct Node {
    NodePtr l, r;
    Key key;
    Val val, sum;
    int cnt;
    Node() {}
    Node(const Key &k, const Val &v)
        : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}
  };

  static VectorPool<Node> init_pool() {
    VectorPool<Node> pool;
    pool[0].l = pool[0].r = pool[0].cnt = 0;
    pool[0].key = Key();
    pool[0].val = pool[0].sum = Val();
    return pool;
  }

  using F = function<Val(Val, Val)>;

  static void set_monoid(const F &_f, const Val &I_) {
    f = _f;
    I = I_;
    pool[0].val = pool[0].sum = I_;
  }

  static VectorPool<Node> pool;
  static F f;
  static Val I;
  NodePtr root;

  OrderedMap() : root(0) {}

  NodePtr my_new(const Key &k, const Val &v) {
    NodePtr ret = pool.my_new(k, v);
    assert(ret != 0);
    return ret;
  }

  void my_delete(NodePtr t) {
    assert(t != 0);
    pool.free(t);
  }

  // update (*t)
  inline NodePtr update(NodePtr t) {
    pool[t].cnt = pool[pool[t].l].cnt + pool[pool[t].r].cnt + 1;
    pool[t].sum = f(f(pool[pool[t].l].sum, pool[t].val), pool[pool[t].r].sum);
    return t;
  }

  // assign (*this)[x] = y, and update parent nodes
  void thrust(NodePtr p, const Key &x, const Val &y) {
    if (!p) return;
    if (pool[p].key == x) {
      pool[p].val = y;
      update(p);
      return;
    }
    NodePtr nxt = pool[p].key < x ? pool[p].r : pool[p].l;
    thrust(nxt, x, y);
    update(p);
  }

  // merge (*l, *r)
  NodePtr merge(NodePtr l, NodePtr r) {
    if (!l || !r) return l ? l : r;
    if (int((rng() * (pool[l].cnt + pool[r].cnt)) >> 32) < pool[l].cnt) {
      pool[l].r = merge(pool[l].r, r);
      return update(l);
    } else {
      pool[r].l = merge(l, pool[r].l);
      return update(r);
    }
  }

  // split (*t) to [-inf, x), [x, inf)
  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {
    if (!t) return {0, 0};
    if (x <= pool[t].key) {
      auto s = split(pool[t].l, x);
      pool[t].l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(pool[t].r, x);
      pool[t].r = s.first;
      return {update(t), s.second};
    }
  }

  // split (*t) to [-inf, x], (x, inf)
  pair<NodePtr, NodePtr> split_upper(NodePtr t, const Key &x) {
    if (!t) return {0, 0};
    if (x < pool[t].key) {
      auto s = split(pool[t].l, x);
      pool[t].l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(pool[t].r, x);
      pool[t].r = s.first;
      return {update(t), s.second};
    }
  }

  // find t : t->key == x
  NodePtr find_ptr(const Key &x) const {
    NodePtr p = root;
    while (p) {
      if (x == pool[p].key) return p;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    return 0;
  }

  // find t : t->key is minimum among (ptr n: n->key >= x)
  NodePtr lower_ptr(NodePtr p, const Key &x) const {
    if (!p) return 0;
    if (pool[p].val == x) return p;
    if (pool[p].val < x) return lower_ptr(pool[p].r, x);
    NodePtr q = lower_ptr(pool[p].l, x);
    return q ? q : p;
  }

  // find t : t->key is minimum among (ptr n: n->key > x)
  NodePtr upper_ptr(NodePtr p, const Key &x) const {
    if (!p) return 0;
    if (pool[p].val <= x) return upper_ptr(pool[p].r, x);
    NodePtr q = upper_ptr(pool[p].l, x);
    return q ? q : p;
  }

  // access (*this)[x]
  Val &operator[](const Key &x) {
    NodePtr p = find_ptr(x);
    if (p) return pool[p].val;
    NodePtr l, r;
    tie(l, r) = split(root, x);
    NodePtr n = my_new(x, Val());
    root = merge(merge(l, n), r);
    return pool[n].val;
  }

  // get (*this)[x]
  Val get(const Key &x) const {
    NodePtr p = root;
    while (p) {
      if (x == pool[p].key) return pool[p].val;
      p = x < pool[p].key ? pool[p].l : pool[p].r;
    }
    return Val();
  }

  // getの設計をNodePtrを返す仕様にすべき？
  // (存在しないときにnullptrを返せないと色々都合が悪い)

  // get node, of which key is minimum
  pair<const Key &, Val &> get_first() const {
    assert((*this).size() > 0);
    NodePtr p = root;
    while (!pool[p].l) p = pool[p].l;
    return make_pair(pool[p].key, pool[p].val);
  }

  // get node, of which key is maximum
  pair<const Key &, Val &> get_last() const {
    assert((*this).size() > 0);
    NodePtr p = root;
    while (!pool[p].r) p = pool[p].r;
    return make_pair(pool[p].key, pool[p].val);
  }

  // get pair(key, val) (lower_bound x)
  pair<const Key &, Val &> get_lower_bound(const Key &x) const {
    NodePtr p = lower_ptr(root, x);
    assert(p != 0);
    return make_pair(pool[p].key, pool[p].val);
  }

  // get pair(key, val) (upper_bound x)
  pair<const Key &, Val &> get_upper_bound(const Key &x) const {
    NodePtr p = upper_ptr(root, x);
    assert(p != 0);
    return make_pair(pool[p].key, pool[p].val);
  }

  // enumerate all key in order of increasing
  vector<pair<const Key &, Val &>> enumerate() const {
    vector<pair<const Key &, Val &>> ret;
    auto dfs = [&](auto rec, NodePtr p) -> void {
      if (pool[p].l) rec(rec, pool[p].l);
      if (p) ret.emplace_back(pool[p].key, pool[p].val);
      if (pool[p].r) rec(rec, pool[p].r);
      return;
    };
    dfs(dfs, root);
    return ret;
  }

  // (*this)[x] = y
  void insert(const Key &x, const Val &y) {
    NodePtr p = find_ptr(x);
    if (p) {
      thrust(root, x, y);
      return;
    }
    NodePtr l, r;
    tie(l, r) = split(root, x);
    root = merge(merge(l, my_new(x, y)), r);
  }

  // erase (*this)[x]
  void erase(const Key &x) {
    NodePtr p = find_ptr(x);
    if (!p) return;
    NodePtr l, r;
    tie(l, r) = split(root, x);
    root = merge(l, split_upper(r, x).second);
    my_delete(p);
  }

  // count the number of node: n.key < x
  int lower_bound(const Key &x) const {
    NodePtr p = root;
    int ret = 0;
    while (p) {
      if (x <= pool[p].val) {
        p = pool[p].l;
      } else {
        ret += pool[pool[p].l].cnt + 1;
        p = pool[p].r;
      }
    }
    return ret;
  }

  // count the number of node: n.key <= x
  int upper_bound(const Key &x) const {
    NodePtr p = root;
    int ret = 0;
    while (p) {
      if (x < pool[p].val) {
        p = pool[p].l;
      } else {
        ret += pool[pool[p].l].cnt + 1;
        p = pool[p].r;
      }
    }
    return ret;
  }

  // calculate f([n : l <= n.key < r])
  Val fold(const Key &l, const Key &r) {
    auto x = split(root, l);
    auto y = split(x.second, r);
    Val ret = y.first.sum;
    root = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  // count containing nodes
  int size() const { return pool[root].cnt; }
};

template <typename Key, typename Val>
VectorPool<typename OrderedMap<Key, Val>::Node> OrderedMap<Key, Val>::pool =
    OrderedMap<Key, Val>::init_pool();
template <typename Key, typename Val>
function<Val(Val, Val)> OrderedMap<Key, Val>::f = +[](Val, Val) {
  return Val();
};
template <typename Key, typename Val>
Val OrderedMap<Key, Val>::I = Val();
