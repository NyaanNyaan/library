#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../template/template.hpp"
#include "../../math/elementary-function.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(a, b);
  int x, y;
  tie(x, y) = extgcd(a, b);
  out(x, y);
}