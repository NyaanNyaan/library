#pragma once
#include "./randomized-binary-search-tree.hpp"

template <typename T, int S = 2000000, bool MULTI = false>
struct OrderedSet {
  using F = function<T(T, T)>;
  using RBST = RandomizedBinarySearchTree<T, F>;
  using Node = typename RBST::Node;

  static RBST* rbst;
  Node* t;

  OrderedSet() {
    if (!rbst) rbst = new RBST([](T, T) { return T(); }, T(), S);
    t = rbst->make();
  }

  T kth_element(int k) {
    Node* p = t;
    int l;
    while (k != (l = rbst->count(p->l))) {
      if (k < l) {
        p = p->l;
      } else {
        p = p->r;
        k -= l + 1;
      }
    }
    return p->key;
  }

  void insert(const T& x) {
    int l = lower_bound(x);
    int r = upper_bound(x);
    if (!MULTI and l != r) return;
    rbst->insert(t, l, x);
  }

  void erase(const T& x) {
    int l = lower_bound(x);
    int r = upper_bound(x);
    if (l == r) return;
    rbst->erase(t, l);
  }

  int count(const T& x) { return upper_bound(t, x) - lower_bound(t, x); }

  int size() { return rbst->count(t); }

  int lower_bound(const T& x) {
    Node* p = t;
    int ret = 0;
    while (p) {
      if (x <= p->key) {
        p = p->l;
      } else {
        ret += rbst->count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int upper_bound(const T& x) {
    Node* p = t;
    int ret = 0;
    while (p) {
      if (x < p->key) {
        p = p->l;
      } else {
        ret += rbst->count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  vector<string> dump() {
    int width = 128;
    string emp(width, ' ');
    string data;
    data += string("  DUMP ... size : ") + to_string(rbst->size(t));

    vector<string> ret(width, emp);
    ret[0] = data;

    int max_dep = 0;
    dump(ret, t, 1, width / 2, width / 4, 0, &max_dep);
    while (ret.size() and ret.back() == emp) ret.pop_back();
    ret[0] += string(" depth : ") + to_string(max_dep);
    return ret;
  }

  void dump(vector<string>& s, const Node* t, int i, int j, int off,
            int cdep = 0, int* mdep = nullptr) {
    if (!t) return;
    *mdep = max(cdep, *mdep);

    string n = to_string(t->key);
    copy(begin(n), end(n), begin(s[i]) + j);

    if (t->l) {
      s[i + 1][j - off / 2] = 'L';
      dump(s, t->l, i + 2, j - off, off / 2, cdep + 1, mdep);
    }
    if (t->r) {
      s[i + 1][j + off / 2] = 'R';
      dump(s, t->r, i + 2, j + off, off / 2, cdep + 1, mdep);
    }
  }
};
template <typename T, int S, bool MULTI>
typename OrderedSet<T, S, MULTI>::RBST* OrderedSet<T, S, MULTI>::rbst = nullptr;
