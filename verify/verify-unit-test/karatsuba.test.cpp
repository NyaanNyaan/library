#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/nimber.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/karatsuba.hpp"

using namespace Nyaan;

template <typename T>
vector<T> naive(vector<T>& a, vector<T>& b) {
  vector<T> c(a.size() + b.size() - 1);
  rep(i, sz(a)) rep(j, sz(b)) c[i + j] += a[i] * b[j];
  return c;
}

template <typename T>
void test() {
  int mx = 500;
  rep(_, 100) {
    int s = randint(1, mx);
    int t = randint(1, mx);
    vector<T> a(s), b(t);
    each(x, a) x = rng();
    each(x, b) x = rng();
    auto c = karatsuba(a, b);
    auto d = naive(a, b);
    assert(c == d);
  }
  cerr << "OK" << endl;
}

void Nyaan::solve() {
  test<LazyMontgomeryModInt<998244353>>();
  test<Nimber64>();
  test<Nimber32>();
  test<Nimber16>();
  test<uint32_t>();
  test<uint64_t>();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
