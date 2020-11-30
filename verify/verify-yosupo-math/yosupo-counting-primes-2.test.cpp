#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../competitive-template.hpp"
#include "../../multiplicative-function/prime-counting-o2d3.hpp"

void solve() {
  inl(N);
  out(prime_counting(N));
}