#pragma once

#include <cassert>
#include <iostream>
#include <type_traits>
using namespace std;

#include "../segment-tree/rbst-segment-tree.hpp"

namespace SlopeTrickImpl {

template <typename Int>
using T = pair<Int, Int>;
template <typename Int>
using E = Int;
template <typename Int>
T<Int> f(T<Int> a, T<Int> b) {
  return {a.first + b.first, a.second + b.second};
}
template <typename Int>
T<Int> g(T<Int> a, E<Int> b) {
  return {a.first, a.second + a.first * b};
}
template <typename Int>
E<Int> h(E<Int> a, E<Int> b) {
  return a + b;
}
template <typename Int>
T<Int> ti() {
  return {};
}
template <typename Int>
E<Int> ei() {
  return {};
}
template <typename Int>
using SegTree = RBSTShiftableLazySegmentTree<Int, T<Int>, E<Int>, f<Int>,
                                             g<Int>, h<Int>, ti<Int>, ei<Int>>;
}  // namespace SlopeTrickImpl

template <typename I>
struct WeightedSlopeTrick {
  static constexpr I inf = (I{1} << (sizeof(I) * 8 - 2)) - 1;
  using Seg = typename SlopeTrickImpl::SegTree<I>;
  using T = SlopeTrickImpl::T<I>;
  using E = SlopeTrickImpl::E<I>;

  // x : 座標, c : 傾きの変化量
  struct P {
    I x, c;
    P(I _x, I _c) : x(_x), c(_c) {}
  };

 private:
  Seg L, R;
  I min_y;

  // seg[x] += c
  void _apply(Seg& seg, I x, I c) {
    if (c == 0) return;
    seg.apply_val_fast(x, [&](T& t) {
      t.first += c;
      t.second += x * c;
    });
  }
  void _push_L(I x, I c = 1) { _apply(L, x, c); }
  void _push_R(I x, I c = 1) { _apply(R, x, c); }
  P _get_L() {
    assert(!L.empty());
    auto kv = L.get_max_keyval();
    return P{kv.first, kv.second.first};
  }
  P _get_R() {
    assert(!R.empty());
    auto kv = R.get_min_keyval();
    return P{kv.first, kv.second.first};
  }
  P _getpop_L() {
    assert(!L.empty());
    auto kv = L.pop_max_keyval();
    return P{kv.first, kv.second.first};
  }
  P _getpop_R() {
    assert(!R.empty());
    auto kv = R.pop_min_keyval();
    return P{kv.first, kv.second.first};
  }
  pair<Seg, Seg> _split_L(I c) {
    assert(L.fold_all().first >= c);
    pair<Seg, Seg> res =
        L.split_min_left([&](const T& t) { return t.first <= c; });
    c -= res.second.fold_all().first;
    if (c != 0) {
      I k = res.first.get_max_key();
      _apply(res.first, k, -c);
      _apply(res.second, k, c);
    }
    return res;
  }
  pair<Seg, Seg> _split_R(I c) {
    assert(R.fold_all().first >= c);
    pair<Seg, Seg> res =
        R.split_max_right([&](const T& t) { return t.first <= c; });
    c -= res.first.fold_all().first;
    if (c != 0) {
      I k = res.second.get_min_key();
      _apply(res.first, k, c);
      _apply(res.second, k, -c);
    }
    return res;
  }
  // destructive merge
  Seg _unite(Seg& lhs, Seg& rhs) {
    if (lhs.empty()) return rhs;
    if (rhs.empty()) return lhs;
    assert(lhs.get_max_key() <= rhs.get_min_key() && "WeightSlopTrick::_unite");
    if (lhs.get_max_key() == rhs.get_min_key()) {
      auto [x, p] = lhs.pop_max_keyval();
      _apply(rhs, x, p.first);
    }
    if (lhs.empty()) return rhs;
    if (rhs.empty()) return lhs;
    return ordered_merge(lhs, rhs);
  }

 public:
  WeightedSlopeTrick() : min_y(0) {}

  void debug() {
    auto LL = L.make_array(), RR = R.make_array();
    cerr << "L : ";
    for (auto& [k, v] : LL) cerr << "( " << k << ", " << v.first << " ), ";
    cerr << endl << "R : ";
    for (auto& [k, v] : RR) cerr << "( " << k << ", " << v.first << " ), ";
    cerr << endl << "min : ( ";
    cerr << get_min().first << ", " << get_min().second << " )" << endl;
  }

  // return {x, y} s.t. {argmin, min}
  pair<I, I> get_min() {
    I x = L.empty() ? R.empty() ? 0 : _get_R().x : _get_L().x;
    return {x, min_y};
  }

  void shift_L(I a) { L.shift(a), L.apply_all(a); }
  void shift_R(I a) { R.shift(a), R.apply_all(a); }
  // f(x) <- f(x - a)
  void shift_x(I a) { shift_L(a), shift_R(a); }
  // f(x) <- f(x) + a
  void shift_y(I a) { min_y += a; }

  // add (x-a)_+   _____/
  void add_xma(I a, I c = 1) {
    _apply(L, a, c);
    auto [L1, L2] = _split_L(c);
    auto [c_sum, ac_sum] = L2.fold(a, inf);
    min_y += ac_sum - c_sum * a;
    auto c2 = L2.get_val(a);
    L2.erase(a);
    R = _unite(L2, R);
    _apply(R, a, c2.first);
    L = L1;
  }

  // add (a-x)_+   \_____
  void add_amx(I a, I c = 1) {
    _apply(R, a, c);
    auto [R1, R2] = _split_R(c);
    auto [c_sum, ac_sum] = R1.fold(-inf, a);
    min_y += c_sum * a - ac_sum;
    auto c2 = R1.get_val(a);
    R1.erase(a);
    L = _unite(L, R1);
    _apply(L, a, c2.first);
    R = R2;
  }

  // add |x-a|     \____/
  void add_abs_xma(I a, I c = 1) {
    add_xma(a, c);
    add_amx(a, c);
  }

  //  chmin right side \_/ -> \__
  void chmin_right() { R.clear(); }
  //  chmin left side  \_/ -> __/
  void chmin_left() { L.clear(); }

  // destructive merge
  void merge(WeightedSlopeTrick& r) {
    if (L.size() + R.size() < r.L.size() + r.R.size()) swap(*this, r);
    for (auto& [x, t] : r.L.make_array()) add_amx(x, t.first);
    for (auto& [x, t] : r.R.make_array()) add_xma(x, t.first);
    shift_y(r.min_y);
  }

  I eval(I x) {
    I res = min_y;
    if (!L.empty() && _get_L().x > x) {
      auto [L1, L2] = L.split_by_key(x);
      auto [c_sum, xc_sum] = L2.fold_all();
      res += xc_sum - c_sum * x;
      L = _unite(L1, L2);
    }
    if (!R.empty() && _get_R().x < x) {
      auto [R1, R2] = R.split_by_key(x);
      auto [c_sum, xc_sum] = R1.fold_all();
      res += c_sum * x - xc_sum;
      R = _unite(R1, R2);
    }
    return res;
  }

  void clear() { L.clear(), R.clear(), min_y = 0; }
};

using SlopeTrick = WeightedSlopeTrick<__int128_t>;

/**
 * @brief Weighted Slope Trick
 */
