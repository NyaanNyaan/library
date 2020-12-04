#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../../template/template.hpp"
#include "../../multiplicative-function/prime-counting-o2d3.hpp"

using namespace Nyaan; void Nyaan::solve() {
  inl(N);
  out(prime_counting(N));
}