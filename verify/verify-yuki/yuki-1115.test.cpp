#define PROBLEM "https://yukicoder.me/problems/no/1115"
//
#include "../../template/template.hpp"
//
#include "../../dp/inversion-counting.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  vl a(N), b(N);
  in(a, b);
  out(swap_distance(a, b));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
