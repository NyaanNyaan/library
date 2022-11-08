#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/multiprecision-integer.hpp"
//
#include "../../misc/all.hpp"
using namespace Nyaan;

void MultiPrecisionInteger::_test_private_function(const M& A, const M& B) {
  Timer timer;
  const vector<int>& a = A.dat;
  const vector<int>& b = B.dat;

  cerr << "size : " << b.size() << ", ";

  timer.reset();
  auto qr3 = _divmod_newton(a, b);
  cerr << "nt : " << timer.elapsed() << ", ";

  timer.reset();
  auto qr2 = _divmod_dc(a, b);
  cerr << "dc : " << timer.elapsed() << ", ";
  assert(qr2 == qr3);

  long long naive_complexity =
      max<long long>(A._size(), B._size()) * abs(A._size() - B._size());
  if (naive_complexity <= TEN(6)) {
    timer.reset();
    auto qr1 = _divmod_naive(a, b);
    assert(qr1 == qr3 && "_div_test");
    cerr << "na : " << timer.elapsed() << ", ";
  }
  cerr << endl;
}

void q() {
  auto gen = [&](int d) {
    string S;
    S.push_back(rng('1', '9'));
    rep(_, d - 1) S.push_back(rng('0', '9'));
    if (rng() & 1) S.insert(begin(S), '-');
    return S;
  };

  // time
  for (int b = 1; b <= 21; b++) {
    auto S = bigint{gen(1 << b)};
    auto T = bigint{gen(1 << (b - 1))};
    bigint::_test_private_function(S, T);
  }
  cerr << "OK" << endl;
}

void Nyaan::solve() {
  q();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
