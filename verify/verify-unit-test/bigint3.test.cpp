#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/bigint.hpp"
//
#include "../../misc/all.hpp"
using namespace Nyaan;

pair<vector<int>, vector<int>> MultiPrecisionInteger::_divmod_dc(
    const vector<int>& a, const vector<int>& b) {
  if (_is_zero(b)) {
    cerr << "Divide by Zero Exception" << endl;
    exit(1);
  }
  if ((int)b.size() <= 64) return _divmod_naive(a, b);
  if ((int)a.size() - (int)b.size() <= 64) return _divmod_naive(a, b);

  int norm = D / (b.back() + 1);
  vector<int> x = _mul(a, {norm});
  vector<int> y = _mul(b, {norm});

  int s = x.size(), t = y.size();
  int yu = (t + 1) / 2, yv = t - yu;
  vector<int> yh{end(y) - yu, end(y)};
  int xv = max<int>(yv, s - (yu * 2 - 1));
  int xu = s - xv;
  vector<int> xh{end(x) - xu, end(x)};
  vector<int> rem{end(x) - xu - yv, end(x)};
  auto [qh, _unused] = _divmod_dc(xh, yh);
  vector<int> yqh = _mul(y, qh);
  while (_lt(rem, yqh)) _sub(qh, {1}), yqh = _sub(yqh, y);
  rem = _sub(rem, yqh);
  while (_leq(y, rem)) _add(qh, {1}), rem = _sub(rem, y);
  vector<int> q, r;
  if (xu + yv == s) {
    swap(q, qh), swap(r, rem);
  } else {
    vector<int> xnxt{begin(x), end(x) - xu - yv};
    copy(begin(rem), end(rem), back_inserter(xnxt));
    tie(q, r) = _divmod_dc(xnxt, y);
    q.resize(s - xu - yv, 0);
    copy(begin(qh), end(qh), back_inserter(q));
  }
  _shrink(q), _shrink(r);
  auto [q2, r2] = _divmod_1e9(r, {norm});
  assert(_is_zero(r2));
  return {q, q2};
}

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
