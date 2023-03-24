#pragma once

#include <vector>
using namespace std;

#include "rbst-segment-tree.hpp"

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ti)(), E (*ei)()>
struct Sequence : RBSTShiftableLazySegmentTree<int, T, E, f, g, h, ti, ei> {
  using Base = RBSTShiftableLazySegmentTree<int, T, E, f, g, h, ti, ei>;
  using Base::_clear;
  using Base::_count;
  using Base::_make_array;
  using Base::_merge;
  using Base::_my_del;
  using Base::_my_new;
  using Base::_shift;
  using Base::_split_by_key;
  using Base::_split_by_key3;

  Sequence() : Base() {}
  Sequence(const vector<T>& v) : Base(v) {}
  Sequence(int n) : Base(vector<T>(n, ti())) {}

  void insert(int i, const T& x) {
    auto [l, r] = _split_by_key(this->root, i);
    _shift(r, 1);
    this->root = _merge(_merge(l, _my_new(i, x)), r);
  }
  void push_back(const T& x) { insert(_count(this->root), x); }

  // 列のマージ　破壊的
  void append(Sequence& r) {
    _shift(r.root, _count(this->root));
    this->root = _merge(this->root, r.root);
    r.root = nullptr;
  }
  void append(const vector<T>& r) {
    Sequence s{r};
    append(s);
  }

  void erase(int i) override {
    auto s = _split_by_key3(this->root, i);
    _my_del(s[1]), _shift(s[2], -1);
    this->root = _merge(s[0], s[2]);
  }
  void pop_back() { erase(_count(this->root) - 1); }

  void erase(int l, int r) {
    if (l >= r) return;
    auto s = _split_by_key3(this->root, l);
    auto [t, u] = _split_by_key(s[2], r);
    _my_del(s[1]), _clear(t), _shift(u, l - r);
    this->root = _merge(s[0], u);
  }

  vector<T> get_vector() {
    vector<pair<int, T>> buf;
    _make_array(this->root, buf);
    vector<T> res;
    for (auto& p : buf) res.push_back(p.second);
    return res;
  }

  friend ostream& operator<<(ostream& os, const Sequence& s) {
    vector<pair<int, T>> p = s.make_array();
    for (int i = 0; i < (int)p.size(); i++) {
      os << (i ? " " : "") << p[i].second;
    }
    os << "\n";
    return os;
  }
};
