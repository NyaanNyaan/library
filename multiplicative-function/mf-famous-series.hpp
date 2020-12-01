#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "divisor-multiple-transform.hpp"

template <typename T>
static constexpr vector<T> mobius_function(int N) {
  vector<T> a(N + 1, 0);
  a[1] = 1;
  divisor_transform::mobius_transform(a);
  return a;
}
