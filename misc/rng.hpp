#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace my_rand {

// [0, 2^64 - 1)
uint64_t rng() {
  static uint64_t x_ =
      uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                   chrono::high_resolution_clock::now().time_since_epoch())
                   .count()) *
      10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

// [l, r)
int64_t randint(int64_t l, int64_t r) {
  assert(l < r);
  return l + rng() % (r - l);
}

// choose n numbers from [l, r) without overlapping
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

// [0.0, 1.0)
double rnd() {
  union raw_cast {
    double t;
    uint64_t u;
  };
  constexpr uint64_t p = uint64_t(1023 - 64) << 52;
  return rnd() * ((raw_cast*)(&p))->t;
}

}  // namespace my_rand

using my_rand::randint;
using my_rand::randset;
using my_rand::rnd;
using my_rand::rng;
