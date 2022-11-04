#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_E"

#include "../../math/multiprecision_integer.hpp"
//
int main() {
  bigint a, b;
  cin >> a >> b;
  cout << a % b << endl;
}
