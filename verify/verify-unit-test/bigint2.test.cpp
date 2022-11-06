#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/multiprecision-integer.hpp"
//
#include "../../misc/all.hpp"
using namespace Nyaan;

void MultiPrecisionInteger::_test_private_function(const M& A, const M& B) {
  long long naive_complexity =
      max<long long>(A._size(), B._size()) * abs(A._size() - B._size());
  if (naive_complexity > 100000) return;

  const vector<int>& a = A.dat;
  const vector<int>& b = B.dat;
  if (!B.is_zero()) {
    auto qr1 = _divmod_naive(a, b);
    auto qr2 = _divmod_dc(a, b);
    assert(qr1 == qr2 && "_div_test");
  }
  if (!A.is_zero()) {
    auto qr1 = _divmod_naive(b, a);
    auto qr2 = _divmod_dc(b, a);
    assert(qr1 == qr2 && "_div_test");
  }
}

void q() {
  auto gen = [&](int d) {
    string S;
    S.push_back(rng('1', '9'));
    rep(_, d - 1) S.push_back(rng('0', '9'));
    if (rng() & 1) S.insert(begin(S), '-');
    return S;
  };
  auto validate_divmod2 = [&](bigint a, bigint b) {
    auto [q, r] = divmod(a, b);

    bigint a2 = bigint(a.to_string());
    bigint b2 = bigint(b.to_string());
    bigint q2 = bigint(q.to_string());
    bigint r2 = bigint(r.to_string());
    assert(a == a2 and b == b2 and q == q2 and r == r2);

    assert(q * b + r == a);
    assert(0 <= abs(r) and abs(r) < abs(b));

    if (a >= 0 and b > 0) {
      assert(q >= 0 and r >= 0);
    }
    if (a >= 0 and b < 0) {
      assert(q <= 0 and r >= 0);
    }
    if (a < 0 and b > 0) {
      assert(q <= 0 and r <= 0);
    }
    if (a < 0 and b < 0) {
      assert(q >= 0 and r <= 0);
    }

    bigint::_test_private_function(a, b);
  };

  validate_divmod2(gen(1000), gen(500));

  // small
  rep(i, 150) rep(j, 150) {
    string S = gen(i * 9);
    string T = gen(j * 9);
    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // random
  rep(_, 100) {
    string S = gen(rng(1, 10000));
    string T = gen(rng(1, 10000));
    if (sz(S) < sz(T)) swap(S, T);
    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // 100000000...
  rep(_, 100) {
    string S = gen(rng(1, 10000));
    string T = gen(rng(1, 10000));
    if (sz(S) < sz(T)) swap(S, T);
    T[0] = '1';
    rep1(i, sz(T) - 1) T[i] = '0';

    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // 100000000... + noise
  rep(_, 100) {
    string S = gen(rng(1, 10000));
    string T = gen(rng(1, 10000));
    if (sz(S) < sz(T)) swap(S, T);
    T[0] = '1';
    rep1(i, sz(T) - 1) T[i] = '0';
    T[rng(0, sz(T) - 1)] = rng('1', '9');

    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // 999999999...
  rep(_, 100) {
    string S = gen(rng(1, 10000));
    string T = gen(rng(1, 10000));
    if (sz(S) < sz(T)) swap(S, T);
    rep(i, sz(T)) T[i] = '9';

    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // 999999999... + noise
  rep(_, 100) {
    string S = gen(rng(1, 10000));
    string T = gen(rng(1, 10000));
    if (sz(S) < sz(T)) swap(S, T);
    rep(i, sz(T)) T[i] = '9';
    T[rng(0, sz(T) - 1)] = rng('1', '8');

    bigint A{S}, B{T};
    validate_divmod2(A, B);
  }
  // time
  {
    Timer timer;
    auto S = bigint{gen(1 << 20)};
    auto T = bigint{gen(1 << 19)};
    auto [q, r] = divmod(S, T);
    auto U = q * T + r;
    assert(S == U);
    cerr << "time : " << timer.elapsed() << endl;
  }
  /*
  for (int b = 1; b <= 22; b++) {
    Timer timer;
    rep(_, 10) {
      auto S = bigint{gen(1 << b)};
      auto T = bigint{gen(1 << (b - 1))};
      timer.elapsed();
      auto [q, r] = divmod(S, T);
      auto U = q * T + r;
      assert(S == U);
    }
    cerr << "b : 2^" << b << ", ";
    cerr << "div time : " << timer.elapsed() << endl;
  }
  */

  cerr << "OK" << endl;
}

void Nyaan::solve() {
  q();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}