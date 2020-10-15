#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace my_rand {

uint64_t rng() {
  static uint64_t x_ = 88172645463325252ULL;
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}

// [l, r)
int64_t randint(int64_t l, int64_t r) {
  assert(l < r);
  return l + rng() % (r - l);
}

//
vector<int64_t> randset(int64_t l, int64_t r, int64_t n) {
  int64_t d = r - l;
  assert(0 <= d && n <= d);
  unordered_set<int64_t> s;
  for (int64_t i = n; i; --i) {
    int64_t m = randint(l, r + 1 - i);
    if (s.find(m) != s.end()) m = r - i;
    s.insert(m);
  }
  vector<int64_t> ret;
  for (auto& x : s) ret.push_back(x);
  return ret;
}

}  // namespace my_rand

using my_rand::rng;
using my_rand::randint;
using my_rand::randset;

