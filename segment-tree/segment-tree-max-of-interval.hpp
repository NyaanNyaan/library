#pragma once

#include <algorithm>
using namespace std;

// セグ木用のモノイド (区間更新用のコンストラクタもある)
//
// sum : 全体の sum
// max, lmax, rmax : (連続部分列の要素の和)の max (空の区間を認めない)
// min, lmin, rmin : (連続部分列の要素の和)の min (空の区間を認めない)
// num : 区間の長さ
template <typename T>
struct MaxInterval {
  T sum, max, lmax, rmax, min, lmin, rmin;
  long long num;
  MaxInterval()
      : sum(0), max(0), lmax(0), rmax(0), min(0), lmin(0), rmin(0), num(0) {}
  // [x] 1 個からなる区間
  MaxInterval(T x)
      : sum(x), max(x), lmax(x), rmax(x), min(x), lmin(x), rmin(x), num(1) {}
  // [x] num 個からなる区間
  MaxInterval(T x, long long _num) {
    if (_num == 0) {
      sum = max = lmax = rmax = min = lmin = rmin = num = 0;
    } else {
      sum = x * _num;
      max = lmax = rmax = (x > 0 ? x * _num : x);
      min = lmin = rmin = (x < 0 ? x * _num : x);
      num = _num;
    }
  }
  bool operator==(const MaxInterval& rhs) const {
    return sum == rhs.sum && max == rhs.max && lmax == rhs.lmax &&
           rmax == rhs.rmax && min == rhs.min && lmin == rhs.lmin &&
           rmin == rhs.rmin && num == rhs.num;
  }
  bool operator!=(const MaxInterval& rhs) const { return !(*this == rhs); }

  // 区間のマージ
  friend MaxInterval merge(const MaxInterval& a, const MaxInterval& b) {
    if (a == MaxInterval{}) return b;
    if (b == MaxInterval{}) return a;
    MaxInterval c;
    c.sum = a.sum + b.sum;
    c.max = ::max({a.max, b.max, a.rmax + b.lmax});
    c.lmax = ::max(a.lmax, a.sum + b.lmax);
    c.rmax = ::max(b.rmax, b.sum + a.rmax);
    c.min = ::min({a.min, b.min, a.rmin + b.lmin});
    c.lmin = ::min(a.lmin, a.sum + b.lmin);
    c.rmin = ::min(b.rmin, b.sum + a.rmin);
    c.num = a.num + b.num;
    return c;
  }
};
