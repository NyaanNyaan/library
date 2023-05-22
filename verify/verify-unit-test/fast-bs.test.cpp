#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math-fast/binary-search.hpp"
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
using namespace Nyaan;

template <typename T>
void test(int N, T upper) {
  vector<T> v(N);
  each(x, v) x = rng(-upper, upper);
  sort(all(v));
  rep(_, 100) {
    T x = rng(-upper, upper);
    /*
    if (lb(v, x) != fast_lb(v, x)) {
      trc(v, x);
      trc(lb(v, x));
      trc(fast_lb(v, x));
      exit(1);
    }
    */
    assert(lb(v, x) == fast_lb(v, x));
    assert(ub(v, x) == fast_ub(v, x));
  }
}

void calc_time(int N) {
  const int upper = TEN(9);
  const int loop = TEN(7);

  vector<int> v(N);
  each(x, v) x = rng(-upper, upper);
  sort(all(v));

  Timer timer;

  timer.reset();
  ll s1 = 0, t1 = 0;
  rep(_, loop) s1 += lb<int>(v, rng(-upper, upper));
  t1 = timer.elapsed();

  timer.reset();
  ll s2 = 0, t2 = 0;
  rep(_, loop) s2 += fast_lb<int>(v, rng(-upper, upper));
  t2 = timer.elapsed();

  timer.reset();
  ll s3 = 0, t3 = 0;
  rep(_, loop) s3 += fast_ub<int>(v, rng(-upper, upper));
  t3 = timer.elapsed();

  trc2(N, s1, s2, s3, t1, t2, t3);
}

void q() {
  for (int N : vector{0, 1, 2, 10, 100, 1000}) {
    test<int>(N, 0);
    test<ll>(N, 0);
    rep(b, 30) test<int>(N, PW(b));
    rep(b, 60) test<ll>(N, PW(b));
  }
  cerr << "OK" << endl;

  // rep(d, 20) calc_time(pow(2, 0.5 * d));
  // calc_time(PW(17) - 1);
  // calc_time(PW(17));
  // calc_time(PW(17) + 1);
  ini(a, b);
  out(a + b);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
