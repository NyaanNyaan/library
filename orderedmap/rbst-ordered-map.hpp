#pragma once



#include "../misc/vector-pool.hpp"

template <typename Key, typename Val>
struct OrderedMap {
 private:
  uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    x_ = x_ ^ (x_ >> 9);
    return x_ & 0xFFFFFFFFull;
  }

  struct NodePtr;
  struct Node {
    NodePtr l, r;
    Key key;
    Val val, sum;
    int cnt;
    Node() {}
    Node(const Key &k, const Val &v)
        : l(0), r(0), key(k), val(v), sum(v), cnt(1) {}
  };

  struct NodePtr {
    int n;
    explicit constexpr NodePtr() {}
    explicit constexpr NodePtr(int _n) : n(_n) {}
    constexpr bool operator==(const NodePtr &r) { return n == r.n; }
    constexpr bool operator!=(const NodePtr &r) { return n != r.n; }
    explicit constexpr operator int() { return n; }
    explicit constexpr operator bool() { return n != 0; }
    constexpr bool operator!() { return n == 0; }
    Node *operator->() { return &(pool.pool[n]); }
    pair<const Key &, Val &> operator*() {
      assert(n != 0 and "pair<const Key &, Val &> NodePtr::operator*()");
      return make_pair(pool.pool[n].key, pool.pool[n].val);
    }
    static constexpr NodePtr nil() { return NodePtr(0); }
  };

  using F = function<Val(Val, Val)>;

  static VectorPool<Node, NodePtr> pool;
  static F f;
  static Val I;
  static bool fold_flag, lazy_flag;
  NodePtr root;

  NodePtr my_new(const Key &k, const Val &v) {
    NodePtr ret = pool.my_new(k, v);
    assert(bool(ret) && "NodePtr my_new(const Key &k, const Val &v)");
    return ret;
  }

  void my_delete(NodePtr t) {
    assert(bool(t) && "void my_delete(NodePtr t)");
    pool.free(t);
  }

  // inner_update (*t)
  inline NodePtr inner_update(NodePtr t) {
    t->cnt = t->l->cnt + t->r->cnt + 1;
    if (fold_flag) {
      t->sum = f(f(t->l->sum, t->val), t->r->sum);
    }
    return t;
  }

  // assign (*this)[x] = y, and update parent nodes
  void thrust(NodePtr p, const Key &x, const Val &y) {
    if (!p) return;
    if (p->key == x) {
      p->val = y;
      inner_update(p);
      return;
    }
    NodePtr nxt = p->key < x ? p->r : p->l;
    thrust(nxt, x, y);
    inner_update(p);
  }

  // merge (*l, *r)
  NodePtr merge(NodePtr l, NodePtr r) {
    if (!l || !r) return bool(l) ? l : r;
    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
      l->r = merge(l->r, r);
      return inner_update(l);
    } else {
      r->l = merge(l, r->l);
      return inner_update(r);
    }
  }

  // split (*t) to [-inf, x), [x, inf)
  pair<NodePtr, NodePtr> split(NodePtr t, const Key &x) {
    if (!t) return {NodePtr::nil(), NodePtr::nil()};
    if (x <= t->key) {
      auto s = split(t->l, x);
      t->l = s.second;
      return {s.first, inner_update(t)};
    } else {
      auto s = split(t->r, x);
      t->r = s.first;
      return {inner_update(t), s.second};
    }
  }

  // split (*t) to [-inf, x], (x, inf)
  pair<NodePtr, NodePtr> split_upper(NodePtr t, const Key &x) {
    if (!t) return {NodePtr::nil(), NodePtr::nil()};
    if (x < t->key) {
      auto s = split(t->l, x);
      t->l = s.second;
      return {s.first, inner_update(t)};
    } else {
      auto s = split(t->r, x);
      t->r = s.first;
      return {inner_update(t), s.second};
    }
  }

  // find t : t->key == x
  NodePtr find_ptr(const Key &x) const {
    NodePtr p = root;
    while (bool(p)) {
      if (x == p->key) return p;
      p = x < p->key ? p->l : p->r;
    }
    return NodePtr::nil();
  }

  // find t : t->key is minimum among (ptr n: n->key >= x)
  static NodePtr lower_ptr(NodePtr p, const Key &x) {
    if (!p) return NodePtr::nil();
    if (pool[p].val == x) return p;
    if (pool[p].val < x) return lower_ptr(pool[p].r, x);
    NodePtr q = lower_ptr(pool[p].l, x);
    return q ? q : p;
  }

  // find t : t->key is minimum among (ptr n: n->key > x)
  static NodePtr upper_ptr(NodePtr p, const Key &x) {
    if (!p) return NodePtr::nil();
    if (pool[p].val <= x) return upper_ptr(pool[p].r, x);
    NodePtr q = upper_ptr(pool[p].l, x);
    return q ? q : p;
  }

  NodePtr build(int l, int r, const vector<Val> &v) {
    if (l == r) return NodePtr::nil();
    if (l + 1 == r) return my_new(l, v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

 public:
  OrderedMap() : root(NodePtr::nil()) {}

  void build(const vector<Val> &v) { root = build(0, v.size(), v); }

  static void set_monoid(const F &_f, const Val &I_) {
    f = _f;
    I = I_;
    NodePtr root = NodePtr::nil();
    root->val = root->sum = I_;
    fold_flag = true;
  }

  static VectorPool<Node, NodePtr> init_pool() {
    VectorPool<Node, NodePtr> pool;
    NodePtr root = NodePtr::nil();
    root->l = root->r = root;
    root->cnt = 0;
    root->key = Key();
    root->val = root->sum = Val();
    return pool;
  }

  // access (*this)[x]
  Val &operator[](const Key &x) {
    NodePtr p = find_ptr(x);
    if (p) return p->val;
    NodePtr l, r;
    tie(l, r) = split(root, x);
    NodePtr n = my_new(x, Val());
    root = merge(merge(l, n), r);
    return n->val;
  }

  // get (*this)[x]
  Val get(const Key &x) const {
    NodePtr p = root;
    while (p) {
      if (x == p->key) return p->val;
      p = x < p->key ? p->l : p->r;
    }
    return Val();
  }

  // get node, of which key is minimum
  NodePtr first_ptr() const {
    NodePtr p = root;
    while (!pool[p].l) p = pool[p].l;
    return p;
  }

  // get node, of which key is maximum
  NodePtr last_ptr() const {
    NodePtr p = root;
    while (!pool[p].r) p = pool[p].r;
    return p;
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

  void apply(const Key &x, const Val &y) {
    assert(fold_flag = true);
    NodePtr p = find_ptr(x);
    if (p) {
      thrust(root, x, f(p->val, y));
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

  // (0-indexed) kth smallest number
  NodePtr kth_element(int n) {
    if (root->cnt <= n) return NodePtr::nil();
    NodePtr p = root;
    while (bool(p)) {
      int sl = p->l->cnt;
      if (sl + 1 == n) return p;
      if (sl < n) {
        n -= sl + 1;
        p = p->r;
      } else {
        p = p->l;
      }
    }
  }

 private:
  // fold [l, inf]
  Val fold_left(NodePtr p, const Key &l) {
    Val ret = I;
    while (bool(p)) {
      if (p->key == l) {
        ret = f(f(p->val, p->r->sum), ret);
        break;
      } else if (p->key < l) {
        p = p->r;
      } else {
        ret = f(f(p->val, p->r->sum), ret);
        p = p->l;
      }
    }
    return ret;
  }

  // fold [inf, r)
  Val fold_right(NodePtr p, const Key &r) {
    Val ret = I;
    while (bool(p)) {
      if (p->key == r) {
        ret = f(ret, p->l->sum);
        break;
      } else if (p->key < r) {
        ret = f(ret, f(p->l->sum, p->val));
        p = p->r;
      } else {
        p = p->l;
      }
    }
    return ret;
  }

 public:
  // calculate f([n : l <= n.key < r])
  Val fold(const Key &l, const Key &r) {
    NodePtr p = root;
    while (bool(p)) {
      if (p->key < l) {
        p = p->r;
      } else if (r <= p->key) {
        p = p->l;
      } else
        break;
    }
    return f(f(fold_left(p->l, l), p->val), fold_right(p->r, r));
  }

  // count containing nodes
  int size() const { return root->cnt; }
};

template <typename Key, typename Val>
VectorPool<typename OrderedMap<Key, Val>::Node,
           typename OrderedMap<Key, Val>::NodePtr>
    OrderedMap<Key, Val>::pool = OrderedMap<Key, Val>::init_pool();
template <typename Key, typename Val>
function<Val(Val, Val)> OrderedMap<Key, Val>::f = +[](Val, Val) {
  return Val();
};
template <typename Key, typename Val>
Val OrderedMap<Key, Val>::I = Val();

template <typename Key, typename Val>
bool OrderedMap<Key, Val>::fold_flag = false;

template <typename Key, typename Val>
bool OrderedMap<Key, Val>::lazy_flag = false;

/**
 *  @brief OrderedMap(順序付き連想配列)
 *  @docs docs/orderedmap/rbst-ordered-map.md
 */ 
