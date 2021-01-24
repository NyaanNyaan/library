
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B"
//
#include "../../template/template.hpp"
//
#include "../../dp/knapsack01.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  inl(N, W);
  vl v(N), w(N);
  in2(v, w);
  out(knapsack01(v, w, W));
}
