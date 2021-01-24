#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include "../../template/template.hpp"
//
#include "../../dp/maximal-rectangle.hpp"
//
using namespace Nyaan;

void Nyaan::solve() {
  ini(N);
  vl a(N);
  in(a);
  out(MaximalRectangle(a));
}
