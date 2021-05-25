#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
#include "../../fps/dual-fps.hpp"
//
#include "../../fps/taylor-shift.hpp"
#include "../../modulo/binomial.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;
using dual = DualFPS<fps>;

using namespace Nyaan;

void test2_inner(dual A, dual B, fps _a, fps _b, int repeat = 3) {
  trc();
  trc(repeat);
  fps a = A.get(), b = B.get();
  a.shrink();
  b.shrink();
  _a.shrink();
  _b.shrink();
  trc(A);
  trc(B);
  trc(a, _a);
  trc(b, _b);
  assert(a == _a && b == _b);

  // minus
  trc(-a);
  trc(-A);
  fps MA = (-A).get();
  MA.shrink();
  assert((-a) == MA);
  trc(-b);
  trc(-B);
  fps MB = (-B).get();
  MB.shrink();
  assert((-b) == MB);

  // A + B
  auto ApB = (A + B).get();
  ApB.shrink();
  auto apb = a + b;
  apb.shrink();
  trc(A + B);
  trc(ApB, apb);
  assert(ApB == apb and "A + B");

  // A - B
  auto AsB = (A - B).get();
  AsB.shrink();
  auto asb = a - b;
  asb.shrink();
  trc(A - B);
  trc(AsB, asb);
  assert(AsB == asb and "A - B");

  // A * B
  auto AmB = (A * B).get();
  AmB.shrink();
  auto amb = a * b;
  amb.shrink();
  auto AmBraw = A * B;
  auto AmB2 = AmBraw.get();
  AmB2.shrink();

  trc(A * B);
  trc(AmBraw);
  trc(AmB, amb, AmB2);
  assert(AmB == amb and "A * B");

  // C += B
  {
    auto C{A};
    C += B;
    auto c = C.get();
    c.shrink();
    trc(C);
    trc(c, apb);
    assert(c == apb and "A += B");
    if (repeat) test2_inner(C, A * B, c, amb, repeat - 1);
    if (repeat) test2_inner(A, C, a, c, repeat - 1);
  }

  // C -= B
  {
    auto C{A};
    C -= B;
    auto c = C.get();
    c.shrink();
    trc(C);
    trc(c, asb);
    assert(c == asb and "A -= B");
    if (repeat) test2_inner(C, A + B, c, apb, repeat - 1);
    if (repeat) test2_inner(A, C, a, c, repeat - 1);
  }

  // C *= B
  {
    auto C{A};
    C *= B;
    auto c = C.get();
    c.shrink();
    trc(C);
    trc(c, amb);
    assert(c == amb and "A *= B");
    if (repeat) test2_inner(C, A - B, c, asb, repeat - 1);
    if (repeat) test2_inner(A, C, a, c, repeat - 1);
  }

  // shift
  for (int sl : vector<int>{0, 1, 2, 10}) {
    dual AS = A << sl;
    auto as = AS.get();
    auto as_ = a << sl;
    as.shrink();
    as_.shrink();
    trc(sl, as, as_);
    assert(as == as_);

    dual BS = B << sl;
    auto bs = BS.get();
    auto bs_ = b << sl;
    bs.shrink();
    bs_.shrink();
    trc(sl, bs, bs_);
    assert(bs == bs_);
  }
}

void test3(dual A, fps a) {
  for (int sl : vector<int>{10, 0, 1, 2, 10}) {
    dual AS = A << sl;
    auto as = AS.get();
    auto as_ = a << sl;
    as.shrink();
    as_.shrink();
    trc(sl, as, as_);
    assert(as == as_);
  }
}

void test2(int mx = 10) {
  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < mx; j++) {
      fps a(i), b(j), c(i);
      iota(all(a), 1);
      iota(all(b), 1 + i);
      iota(all(c), 0);
      test2_inner(dual{a}, dual{b}, a, b);
      test2_inner(dual{b}, dual{c}, b, c);
      test2_inner(dual{c}, dual{a}, c, a);
      test3(dual{a}, a);
      test3(dual{b}, b);
      test3(dual{c}, c);
      cerr << "(i, j) = ";
      cerr << "(" << i << ", " << j << ")" << endl;
    }
  }
  cerr << "ok" << endl;
}

void Nyaan::solve() {
  test2(6);

  int a,b;
  cin>>a>>b;
  cout<<a+b<<endl; 
}
