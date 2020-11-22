#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "berlekamp-massey.hpp"
#include "kitamasa.hpp"

template <typename mint>
mint nth_term(int n, const vector<mint> &s) {
  return kitamasa(n, BerlekampMassey<mint>(s), s);
}
