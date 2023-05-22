#pragma once

#include "bigint-gcd.hpp"
#include "rational.hpp"

using BigRational = RationalBase<bigint, bigint>;

double to_double(const BigRational& r) {
  pair<long double, int> a = r.x.dfp();
  pair<long double, int> b = r.y.dfp();
  return a.first / b.first * powl(10.0, a.second - b.second);
}
