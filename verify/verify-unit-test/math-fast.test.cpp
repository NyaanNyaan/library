#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math-fast/gcd.hpp"

namespace fast_gcd_verify {

using i64 = long long;

i64 naive_gcd(i64 a, i64 b) {
  while (b) swap(a %= b, b);
  return a;
}

i64 x_;
void rng_init() { x_ = 88172645463325252ULL; }
i64 rng() { return x_ = x_ ^ (x_ << 7), x_ = x_ ^ (x_ >> 9); }

void unit_test() {
  using P = pair<i64, i64>;
  using F = i64 (*)(i64, i64);

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
  for (i64 i = 1000; i--;)
    for (i64 j = 1000; j--;) testcase.emplace_back(i, j);
  rng_init();
  for (i64 n = 10000; n--;) {
    i64 i = rng(), j = rng();
    testcase.emplace_back(i, j);
  }

  vector<F> functions{std::__gcd<i64>, naive_gcd, gcd};

  for (auto p : testcase) {
    unordered_set<i64> s;
    for (auto &f : functions) {
      s.insert(abs(f(p.first, p.second)));
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
}  // namespace fast_gcd_verify

using namespace Nyaan;

void Nyaan::solve() {
  fast_gcd_verify::unit_test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
