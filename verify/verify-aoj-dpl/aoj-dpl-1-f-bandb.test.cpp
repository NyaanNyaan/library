#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"
//
#include "../../template/template.hpp"
//
#include "../../dp/branch-and-bound.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  inl(N, W);
  vl v(N), w(N);
  in2(v, w);
  BranchAndBound<ll, ll> bb(v, w);
  out(bb.run(W));
}