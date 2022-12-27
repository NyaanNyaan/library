#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/multiprecision-integer.hpp"
//
#include "../../misc/rng.hpp"

void MultiPrecisionInteger::_test_private_function(const M& A, const M& B) {
  const vector<int>& a = A.dat;
  const vector<int>& b = B.dat;
  {
    auto m1 = _mul_naive(a, b);
    auto m2 = _mul_fft(a, b);
    assert(m1 == m2 && "_mul_test");
  }
}

//

using namespace Nyaan;

using ll = long long;
using i128 = __int128_t;

void test() {
  auto i128_to_string = [](i128 x) -> string {
    if (x == 0) return "0";
    string S;
    bool neg = false;
    if (x < 0) neg = true, x = -x;
    while (x) S.push_back('0' + x % 10), x /= 10;
    if (neg) S.push_back('-');
    reverse(begin(S), end(S));
    return S;
  };
  // [0, 10^i)
  auto rng128 = [&](int i = 37) {
    assert(0 <= i and i <= 37);
    i128 res = 0;
    rep(_, i) res = res * 10 + rng(0, 9);
    return res;
  };
  auto TEN128 = [&](int i = 37) {
    assert(0 <= i and i <= 37);
    i128 res = 1;
    rep(_, i) res *= 10;
    return res;
  };

  rep(t, 10000) {
    int loga = rng(1, 37);
    int logb = rng(1, 37);
    i128 a = rng128(loga);
    i128 b = rng128(logb);
    if (rng() % 50 == 0) a = 0;
    if (rng() % 50 == 0) b = 0;
    if (rng() % 50 == 0) a = TEN128(loga);
    if (rng() % 50 == 0) a = TEN128(loga) - 1;
    if (rng() % 50 == 0) b = TEN128(logb);
    if (rng() % 50 == 0) b = TEN128(logb) - 1;
    if (rng() % 50 == 0) a = b + TEN128(loga);
    if (rng() % 50 == 0) a = b + TEN128(loga) - 1;
    if (rng() & 1) a = -a;
    if (rng() & 1) b = -b;
    bigint A{a};
    bigint B{b};

    assert(a == A and A == a);
    assert(!(a != A) and !(A != a));
    assert(!(a < A) and !(A < a));
    assert(a <= A and A <= a);
    assert(!(a > A) and !(A > a));
    assert(a >= A and A >= a);

    assert((a < b) == (A < B));
    assert((a > b) == (A > B));
    assert((a <= b) == (A <= B));
    assert((a >= b) == (A >= B));
    assert((a == b) == (A == B));
    assert((a != b) == (A != B));

    assert(+A == +a and -A == -a);
    assert(+B == +b and -B == -b);
    assert(abs(A) == (a >= 0 ? a : -a));
    assert(abs(B) == (b >= 0 ? b : -b));
    assert(A.is_zero() == (a == 0));
    assert(B.is_zero() == (b == 0));

    if (LONG_LONG_MIN <= a and a <= LONG_LONG_MAX) {
      assert(A.to_ll() == a);
    }
    if (LONG_LONG_MIN <= b and b <= LONG_LONG_MAX) {
      assert(B.to_ll() == b);
    }
    assert(A.to_i128() == a);
    assert(B.to_i128() == b);

    bigint C{i128_to_string(a)};
    bigint D{i128_to_string(b)};
    if (A != C or B != D) {
      trc(a, b, A, B, C, D);
    }
    assert(A == C and B == D);
    if (A.to_string() != i128_to_string(a)) {
      trc(A);
      trc(a);
    }
    assert(A.to_string() == i128_to_string(a));
    assert(B.to_string() == i128_to_string(b));

    assert(a + b == A + B);
    assert(a + b == B + A);
    assert(A + B == B + A);
    assert(a - b == A - B);
    assert(b - a == B - A);

    bigint E{A};
    E += B;
    assert(E == a + b);
    E = B;
    E += A;
    assert(E == a + b);
    E = A;
    E -= B;
    assert(E == a - b);
    E = B;
    E -= A;
    assert(E == b - a);
  }

  // *
  rep(t, 1000) {
    ll a = randint(-TEN(18), TEN(18));
    ll b = randint(-TEN(18), TEN(18));
    if (rng() % 100 == 0) a = 0;
    if (rng() % 100 == 0) b = 0;
    if (rng() % 10 == 0) a = b + rng() % 11;
    bigint A{a}, B{b};

    i128 p = i128(a) * b;
    auto S = i128_to_string(p);
    auto C = A * B;
    auto D = B * A;

    assert(C == D);
    assert(C.to_string() == S);
    assert(D.to_string() == S);
    assert(C == p and p == C);
    assert(D == p and p == D);
    assert(C.to_i128() == p);
    assert(D.to_i128() == p);
  }

  // _mul_naive, _mul_fft
  rep(t, 1000) {
    vector<int> a, b;
    a.resize(rng(0, 20));
    b.resize(rng(0, 20));
    for (auto& x : a) x = rng(0, TEN(9) - 1);
    for (auto& x : b) x = rng(0, TEN(9) - 1);
    while (!a.empty() and a.back() == 0) a.pop_back();
    while (!b.empty() and b.back() == 0) b.pop_back();
    bigint::_test_private_function({false, a}, {false, b});
  }

  // dfp
  {
    cerr << fixed << setprecision(21);
    auto test_dfp = [&](string S, long double acc = 1e-18) {
      bigint A{S};
      auto [a, b] = A.dfp();
      // trc(a, b, A.to_ld());
      if (a == 0) {
        assert(b == 0 and S == "0");
        return;
      }
      assert(1.0 <= abs(a) and abs(a) < 10.0);
      if (S[0] == '-') {
        assert(b + 2 == (int)S.size());
      } else {
        assert(b + 1 == (int)S.size());
      }
      long double t1 = A.to_ld();
      long double t2 = strtold(S.c_str(), 0);
      long double d = abs(t1 - t2);
      assert(d / t2 < acc);
    };
    test_dfp("998244353");
    test_dfp("1000000000000000000");
    test_dfp("123456789012345678901234567890");
    for (int i = -111; i <= 111; i++) {
      test_dfp(to_string(i));
    }
    rep(t, 1000) {
      long long x = rng(-TEN(18), TEN(18));
      test_dfp(to_string(x));
    }
    for (int k = 20; k <= 60; k++) {
      test_dfp("1" + string(k, '0'));
      test_dfp(string(k, '9'));
    }
    rep(t, 1000) {
      string s;
      int b = rng(1, 100);
      rep(i, 100) s.push_back(rng('0' + (i == 0), '9'));
      if (rng() % 2) s.insert(begin(s), '-');
      test_dfp(s, 1e-17);
    }
  }

  // to_ld
  rep(t, 1000) {
    long long x = rng(-TEN(16), TEN(16));
    bigint A{x};
    ll y = llround(A.to_ld());
    assert(x == y);
  }

  // _tens
  {
    bigint _m;
    /*
    unsigned long long x = 1;
    for (int i = 0; i < 20; i++) {
      assert(x == _m.tens.ten_ull(i));
      assert(_m.tens.digit(x) == i + 1);
      assert(_m.tens.digit(x - 1) == (x == 1 ? 1 : i));
      x *= 10;
    }
    assert(_m.tens.digit(0) == 1);
    assert(_m.tens.digit(1) == 1);
    */
    for (int i = -_m.tens.offset; i <= _m.tens.offset; i++) {
      long double t1 = _m.tens.ten_ld(i);
      long double t2 = powl(10, i);
      long double d = abs(t1 - t2);
      // trc(i, t1, t2, d / t1);
      // i < 0 -> 桁落ちが発生するため少し面倒
      if (i <= 0) assert(d / t1 < 1e-17);
      if (i >= 0) assert(d / t2 < 1e-19);
    }
  }

  {
    auto validate_divmod = [&](bigint a, bigint b) {
      auto [q, r] = divmod(a, b);

      i128 a2 = a.to_i128();
      i128 b2 = b.to_i128();
      i128 q2 = a2 / b2, r2 = a2 % b2;
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
    };
    auto wrapper = [&](bigint a, bigint b) {
      validate_divmod(+a, +b);
      validate_divmod(+a, -b);
      validate_divmod(-a, +b);
      validate_divmod(-a, -b);
    };

    rep(t, 1000) {
      i128 a = 0;
      if (t < 37) {
        a = TEN128(t);
      } else if (t < 74) {
        a = TEN128(t - 37) - 1;
      } else if (t < 100) {
        a = t - 87;
      } else {
        a = rng();
        a = (a << 63) + rng();
      }
      bigint A = a;
      for (int i = 1; i <= 18; i++) {
        wrapper(A, i);
        wrapper(A, TEN(i) - 1);
      }
      rep(_, 10) wrapper(A, rng(1, TEN(9)));
      rep(_, 10) wrapper(A, rng(1, TEN(18)));
      rep(_, 10) wrapper(A, rng128(27));
    }
  }

  // divmod
  {
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
    };
    auto wrapper = [&](bigint a, bigint b) {
      validate_divmod2(+a, +b);
      validate_divmod2(+a, -b);
      validate_divmod2(-a, +b);
      validate_divmod2(-a, -b);
    };

    rep(t, 1000) {
      vector<int> a, b;
      a.resize(rng(0, 20));
      b.resize(rng(0, 20));
      for (auto& x : a) x = rng(0, TEN(9) - 1);
      for (auto& x : b) x = rng(0, TEN(9) - 1);
      while (!a.empty() and a.back() == 0) a.pop_back();
      while (!b.empty() and b.back() == 0) b.pop_back();
      bigint A{false, a}, B{false, b};
      if (!A.is_zero()) wrapper(B, A);
      if (!B.is_zero()) wrapper(A, B);
    }
  }
  cerr << "OK" << endl;
}

void Nyaan::solve() {
  test();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
