#pragma once

#include <functional>
#include <utility>
using namespace std;

// (x, f(x)) を返す
template <typename T, bool get_min = true, int ITER = 100>
pair<T, T> ternary(const function<T(T)>& f, double l, double r) {
  for (int iter = 0; iter < ITER; iter++) {
    double llr = (l + l + r) / 3;
    double lrr = (l + r + r) / 3;
    if (get_min ? f(llr) > f(lrr) : f(llr) < f(lrr)) {
      l = llr;
    } else {
      r = lrr;
    }
  }
  double x = (l + r) / 2;
  return make_pair(x, f(x));
}