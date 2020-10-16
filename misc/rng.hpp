#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace my_rand {

uint64_t rng() {
#ifdef NyaanDebug
  static uint64_t x_ =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
#else
  static uint64_t x_ = 88172645463325252ULL;
#endif
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
  assert(l <= r && n <= r - l);
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

using my_rand::randint;
using my_rand::randset;
using my_rand::rng;
