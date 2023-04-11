#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math-fast/gcd.hpp"

using namespace Nyaan;

i128 naive_gcd(i128 a, i128 b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (b) swap(a %= b, b);
  return a;
}

ll x_;
void rng_init() { x_ = 88172645463325252ULL; }
i128 rng() {
  ll a = (x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9));
  ll b = (x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9));
  return (i128(a) << 64) + b;
}

void unit_test() {
  using P = pair<i128, i128>;
  using F = i128 (*)(i128, i128);

  vector<P> testcase{P(2, 4),
                     P(100000, 10000),
                     P(998244353, 1000000007),
                     P(1LL << 40, 1LL << 60),
                     P((1LL << 61) - 1, 11111111111111111),
                     P((1LL << 60) + 1, (1LL << 59) + 1),
                     P(1LL << 62, 1LL << 62),
                     P(1LL << 62, 1LL << 61),
                     P(3LL << 61, 9LL << 60),
                     P((1uLL << 63) - 1, (1LL << 62)),
                     P(0, 1),
                     P(1, 0),
                     P(0, 0),
                     P(0, -1),
                     P(-1, 0),
                     P(-1, -1)};
  for (i128 i = 1000; i--;)
    for (i128 j = 1000; j--;) testcase.emplace_back(i, j);
  rng_init();
  for (i128 n = 10000; n--;) {
    i128 i = rng(), j = rng();
    testcase.emplace_back(i, j);
  }

  vector<F> functions{naive_gcd, binary_gcd128};

  for (auto p : testcase) {
    set<i128> s;
    for (auto &f : functions) {
      i128 x = f(p.first, p.second);
      if (x < 0) x = -x;
      s.insert(x);
    }
    if (s.size() != 1u) {
      cerr << "verify failed." << endl;
      cerr << "case : " << p.first << " " << p.second << endl;
      cerr << "output : ";
      for (auto &f : functions) cerr << f(p.first, p.second) << ", ";
      cerr << endl;
      exit(1);
    }
  }
  cerr << "verify passed." << endl;
}

void Nyaan::solve() {
  unit_test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
