#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../competitive-template.hpp"
#include "../../math/prime-counting-faster.hpp"

void solve() {
  inl(N);
  out(PrimeCounting::prime_counting(N));
}
