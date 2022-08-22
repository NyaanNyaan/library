#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math/rational.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  Rational a{4, 3}, b{2, 3};

  trc(a + b);
  assert(a + b == 2);
  trc(a - b);
  assert(a - b == Rational(2, 3));
  trc(a * b);
  assert(a * b == Rational(8, 9));
  trc(a / b);
  assert(a / b == 2);
  trc(a.inverse());
  assert(a.inverse() == Rational(3, 4));
  trc(a.pow(3));
  assert(a.pow(3) == Rational(64, 27));

  trc(a > b);
  assert(a > b == true);
  trc(a >= b);
  assert(a >= b == true);
  trc(a < b);
  assert(a < b == false);
  trc(a <= b);
  assert(a <= b == false);

  Binomial<Rational> C;
  assert(C.fac(3) == 6);
  assert(C.finv(3) == Rational(1, 6));
  assert(C(4, 2) == 6);
  assert(C(vi{3, 2}) == 10);
  trc("OK");

  {
    int s, t;
    cin >> s >> t;
    cout << s + t << "\n";
  }
}