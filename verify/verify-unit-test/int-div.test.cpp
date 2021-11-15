#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../misc/int_div.hpp"
using namespace Nyaan;

vector<long long> test(long long a, long long b) {
  cerr << "floor(" << a << ", " << b << ") = " << floor(a, b) << "\n";
  cerr << "under(" << a << ", " << b << ") = " << under(a, b) << "\n";
  cerr << "ceil(" << a << ", " << b << ") = " << ceil(a, b) << "\n";
  cerr << "over(" << a << ", " << b << ") = " << over(a, b) << "\n";
  cerr << endl;
  return vl{floor(a, b), under(a, b), ceil(a, b), over(a, b)};
}

void Nyaan::solve() {
  assert(test(4, 2) == vl({2, 1, 2, 3}));
  assert(test(5, 2) == vl({2, 2, 3, 3}));
  assert(test(-4, 2) == vl({-2, -3, -2, -1}));
  assert(test(-5, 2) == vl({-3, -3, -2, -2}));

  assert(test(-4, -2) == vl({2, 1, 2, 3}));
  assert(test(-5, -2) == vl({2, 2, 3, 3}));
  assert(test(4, -2) == vl({-2, -3, -2, -1}));
  assert(test(5, -2) == vl({-3, -3, -2, -2}));

  assert(modulo(3, 3) == 0);
  assert(modulo(4, 3) == 1);
  assert(modulo(-3, 3) == 0);
  assert(modulo(-4, 3) == 2);

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
