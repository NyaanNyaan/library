#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../competitive-template.cpp"
#include "../math/elementary-function.cpp"

void solve() {
  ini(a, b);
  int x, y;
  tie(x, y) = extgcd(a, b);
  out(x, y);
}