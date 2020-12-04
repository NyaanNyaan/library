#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../template/template.hpp"
#include "../../multiplicative-function/prime-counting-faster.hpp"

using namespace Nyaan; void Nyaan::solve() {
  inl(N);
  out(PrimeCounting::prime_counting(N));
}
