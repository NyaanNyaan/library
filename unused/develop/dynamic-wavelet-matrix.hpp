#pragma once



// 実装破綻した　おわり

template <typename S, typename T, T (*f)(T, T), T (*I)(), int LOG = 20>
struct DynamicWaveletMatrix {
  static uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    x_ = x_ ^ (x_ << 7);
    x_ = x_ ^ (x_ >> 9);
    return x_ & 0xFFFFFFFFull;
  }

  using P = pair<S, T>;
  struct MultiSet {
    struct MSNode {
      MSNode *l, *r;
      P key;
      int cnt;
      MSNode(const P &p) : l(nullptr), r(nullptr), key(p), cnt(1) {}
    };

    MultiSet() {}

    static inline int count(const MSNode *t) { return t ? t->cnt : 0; }
    static MSNode *update(MSNode *t) {
      t->cnt = count(t->l) + count(t->r) + 1;
      return t;
    }

    static MSNode *merge(MSNode *l, MSNode *r) {
      if (!l || !r) return l ? l : r;
      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
        l->r = merge(l->r, r);
        return update(l);
      } else {
        r->l = merge(l, r->l);
        return update(r);
      }
    }

    static pair<MSNode *, MSNode *> split(MSNode *t, int k) {
      if (!t) return {nullptr, nullptr};
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

    static void insert(MSNode *&t, int k, const S &key, const T &val) {
      auto x = split(t, k);
      t = merge(merge(x.first, new MSNode(make_pair(key, val))), x.second);
    }

    static pair<int, bool> lower_bound(MSNode *t, const S &x, const T &y) {
      MSNode *p = t;
      int ret = 0;
      P k = make_pair(x, y);
      int exist = false;
      while (p) {
        if (k == p->key) exist = true;
        if (k <= p->key) {
          p = p->l;
        } else {
          ret += count(p->l) + 1;
          p = p->r;
        }
      }
      return make_pair(ret, exist);
    }
  };

  struct BBST {
    struct BNode {
      BNode *l, *r;
      T key, sum;
      int b, cnt, cnt1;

      BNode() {}

      BNode(const T &k, bool _b)
          : l(nullptr), r(nullptr), key(k), sum(k), b(_b), cnt(1), cnt1(_b) {}
    };

    BBST() {}

    static inline int count(const BNode *t) { return t ? t->cnt : 0; }

    static inline int count1(const BNode *t) { return t ? t->cnt1 : 0; }

    static inline T sum(const BNode *t) { return t ? t->sum : I(); }

    static BNode *update(BNode *t) {
      t->cnt = count(t->l) + count(t->r) + 1;
      t->cnt1 = count1(t->l) + count1(t->r) + t->b;
      t->sum = f(f(sum(t->l), t->key), sum(t->r));
      return t;
    }

    static BNode *merge(BNode *l, BNode *r) {
      if (!l || !r) return l ? l : r;
      if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
        l->r = merge(l->r, r);
        return update(l);
      } else {
        r->l = merge(l, r->l);
        return update(r);
      }
    }

    static pair<BNode *, BNode *> split(BNode *t, int k) {
      if (!t) return {nullptr, nullptr};
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

    static int insert(BNode *&t, int k, const T &key, bool b) {
      auto x = split(t, k);
      int c1 = count1(x.first);
      t = merge(merge(x.first, new BNode(key, b)), x.second);
      return c1;
    }

    static BNode *kth_element(BNode *t, int k) {
      assert(k < count(t));
      while (t) {
        int l = count(t->l);
        if (k == l) return t;
        if (k < l) {
          t = t->l;
        } else {
          t = t->r;
          k -= l + 1;
        }
      }
      exit(1);
    }

    static pair<BNode *, int> add(BNode *t, int k, const T &y) {
      assert(k < count(t));
      int l = count(t->l);
      int c1;
      BNode *ret;
      if (k == l) {
        t->key += y;
        ret = t;
        c1 = count1(t->l);
      } else if (k < l) {
        tie(ret, c1) = add(t->l, k, y);
      } else {
        tie(ret, c1) = add(t->r, k - l - 1, y);
        c1 += count(t->l);
      }
      t->sum = f(f(sum(t->l), t->key), sum(t->r));
      return make_pair(ret, c1);
    }

    //  fold [0, k)
    static pair<T, int> presum(BNode *t, int k) {
      assert(k <= count(t));
      T s = I();
      int c1 = 0;
      while (t != nullptr and k != 0) {
        int l = count(t->l);
        if (k == l) {
          s = f(s, t->l->sum);
          c1 += t->l->cnt1;
          break;
        } else if (k < l) {
          t = t->l;
        } else {
          s = f(s, f(sum(t->l), t->key));
          c1 += count1(t->l) + t->b;
          k -= l + 1;
          t = t->r;
        }
      }
      return make_pair(s, c1);
    }

    static int size(BNode*t){return count(t);}
  };

  struct Node {
    typename BBST::BNode *bv;
    Node *p[2];
    Node() : bv(nullptr) { p[0] = p[1] = nullptr; }
  };

  typename MultiSet::MSNode *xs;
  Node *root;

  DynamicWaveletMatrix() : xs(nullptr), root(new Node) {}

  void add(const S &x, const T &y) {
    int k;
    bool exist;
    tie(k, exist) = MultiSet::lower_bound(xs, x, y);
    Node *n = root;
    if (exist) {
      for (int h = LOG - 1; h >= 0; h--) {
        int b = (y >> h) & 1;
        typename BBST::BNode *bv_node;
        int c1;
        tie(bv_node, c1) = BBST::add(n->bv, k, y);
        if (b) {
          k = c1;
        } else {
          k -= c1;
        }
        assert(k >= 0);
        assert(h == 0 or n->p[b] != nullptr);
        n = n->p[b];
      }
    } else {
      MultiSet::insert(xs, k, x, y);
      for (int h = LOG - 1; h >= 0; h--) {
        int b = (y >> h) & 1;
        int c1 = BBST::insert(n->bv, k, x, y);
        if (b) {
          k = c1;
        } else {
          k -= c1;
        }
        if (h != 0 and n->p[b] == nullptr) n->p[b] = new Node;
        n = n->p[b];
      }
    }
  }

  T sum(int l, int r, T upper) {
    assert(upper < (1LL << LOG));
    T res = 0;
    auto n = root;
    for (int h = LOG - 1; h >= 0; --h) {
      if(n == nullptr) break;
      auto L = BBST::presum(n->bv, l);
      auto R = BBST::presum(n->bv, r);
      int s = size(n->bv);
      if((upper >> h) & 1) {
        
      }
    }
  }
};

int f(int a, int b) { return a + b; }

int e() { return 0; }

void solve() {
  DynamicWaveletMatrix<int,int,f,e> wm;
  wm.add(1,2);
}
