#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../geometry/geometry-base.hpp"

void test() {
  const Point a{1, 2};
  assert(a.x == 1.0 and a.y == 2.0);
  assert(Point().x == 0.0);
  assert(Point().y == 0.0);
  assert(Point(make_pair(1, 2)) == a);

  const Point b{3, 4};
  {
    Point c = a + b;
    assert(c.x == 4.0 and c.y == 6.0);
    Point d = a;
    d += b;
    assert(c == d);
  }
  {
    Point c = a - b;
    assert(c.x == -2.0 and c.y == -2.0);
    Point d = a;
    d -= b;
    assert(c == d);
  }
  {
    Point c = a * 2;
    assert(c.x == 2.0 and c.y == 4.0);
    Point d = a;
    d *= 2;
    assert(c == d);
  }
  {
    Point c = a / 2;
    assert(c.x == 0.5 and c.y == 1.0);
    Point d = a;
    d /= 2;
    assert(c == d);
  }

  assert(real(a) == 1.0 and imag(a) == 2.0);
  assert(dot(a, b) == 11.0);
  assert(cross(a, b) == -2.0);
  assert(norm(a) == 5);
  // assert(abs(a) == sqrtl(5));
  // assert(arg(a) == atan2l(2, 1));
}

using namespace Nyaan;

void q() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
