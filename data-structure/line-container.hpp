#pragma once

#include <cassert>
#include <set>
using namespace std;

enum Objective {
  MAXIMIZE = +1,
  MINIMIZE = -1,
};

template <typename T>
struct Line {
  mutable T k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(T x) const { return p < x; }
};

template <typename T>
T lc_inf() {
  return numeric_limits<T>::max();
}
template <>
long double lc_inf<long double>() {
  return 1 / .0;
}

template <typename T>
T lc_div(T a, T b) {
  return a / b - ((a ^ b) < 0 and a % b);
}
template <>
long double lc_div(long double a, long double b) {
  return a / b;
};

template <typename T, Objective objective>
struct LineContainer : multiset<Line<T>, less<>> {
  using super = multiset<Line<T>, less<>>;
  using super::begin, super::end, super::insert, super::erase;
  using super::empty, super::lower_bound;
  const T inf = lc_inf<T>();
  bool insect(typename super::iterator x, typename super::iterator y) {
    if (y == end()) return x->p = inf, false;
    if (x->k == y->k)
      x->p = (x->m > y->m ? inf : -inf);
    else
      x->p = lc_div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(T k, T m) {
    auto z = insert({k * objective, m * objective, 0}), y = z++, x = y;
    while (insect(y, z)) z = erase(z);
    if (x != begin() and insect(--x, y)) insect(x, y = erase(y));
    while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));
  }
  T query(T x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return (l.k * x + l.m) * objective;
  }
};
template <typename T>
using MinLineContainer = LineContainer<T, Objective::MINIMIZE>;
template <typename T>
using MaxLineContainer = LineContainer<T, Objective::MAXIMIZE>;

/**
 * @brief Line container
 */
