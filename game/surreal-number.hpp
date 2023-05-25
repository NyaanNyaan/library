#pragma once

#include <cassert>
#include <iostream>
#include <utility>
using namespace std;

// reference : http://www.ivis.co.jp/text/20111102.pdf
struct SurrealNumber {
  using S = SurrealNumber;
  using i64 = long long;

  // p / 2^q の形で保持
  i64 p, q;
  SurrealNumber(i64 _p = 0, i64 _q = 0) : p(_p), q(_q) {}
  friend ostream& operator<<(ostream& os, const SurrealNumber& r) {
    os << r.p;
    if (r.q != 0) os << " / " << (i64{1} << r.q);
    return os;
  }

  static S normalize(S s) {
    if (s.p != 0) {
      while (s.p % 2 == 0 and s.q != 0) s.p /= 2, s.q--;
    } else {
      s.q = 0;
    }
    return {s.p, s.q};
  }

  // 加算・減算
  friend S operator+(const S& l, const S& r) {
    i64 cq = max(l.q, r.q);
    i64 cp = (l.p << (cq - l.q)) + (r.p << (cq - r.q));
    return normalize(S{cp, cq});
  }
  friend S operator-(const S& l, const S& r) {
    i64 cq = max(l.q, r.q);
    i64 cp = (l.p << (cq - l.q)) - (r.p << (cq - r.q));
    return normalize(S{cp, cq});
  }
  S& operator+=(const S& r) { return (*this) = (*this) + r; }
  S& operator-=(const S& r) { return (*this) = (*this) - r; }

  S operator-() const { return {-p, q}; }
  S operator+() const { return {p, q}; }

  // 大小関係
  friend bool operator<(const S& l, const S& r) { return (r - l).p > 0; }
  friend bool operator<=(const S& l, const S& r) { return (r - l).p >= 0; }
  friend bool operator>(const S& l, const S& r) { return (l - r).p > 0; }
  friend bool operator>=(const S& l, const S& r) { return (l - r).p >= 0; }
  friend bool operator==(const S& l, const S& r) { return (l - r).p == 0; }
  friend bool operator!=(const S& l, const S& r) { return (l - r).p != 0; }

  // 左右の子を返す関数
  pair<S, S> child() const {
    if (p == 0) return {-1, 1};
    if (q == 0 and p > 0) return {S{p * 2 - 1, 1}, p + 1};
    if (q == 0 and p < 0) return {p - 1, S{p * 2 + 1, 1}};
    return {(*this) - S{1, q + 1}, (*this) + S{1, q + 1}};
  }

  S larger() const {
    S root = 0;
    while ((*this) >= root) root = root.child().second;
    return root;
  }
  S smaller() const {
    S root = 0;
    while ((*this) <= root) root = root.child().first;
    return root;
  }
  friend S reduce(const S& l, const S& r) {
    assert(l < r);
    S root = 0;
    while (l >= root or root >= r) {
      auto [lr, rr] = root.child();
      root = (r <= root ? lr : rr);
    }
    return root;
  }
};

/**
 * @brief 超現実数
 */
