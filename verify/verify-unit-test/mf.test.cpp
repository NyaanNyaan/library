#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../multiplicative-function/divisor-multiple-transform.hpp"
#include "../../multiplicative-function/enamurate-multiplicative-function.hpp"
#include "../../multiplicative-function/mf-famous-series.hpp"
using mint = LazyMontgomeryModInt<998244353>;

#include "../../misc/timer.hpp"

using namespace Nyaan;

#include <cxxabi.h>
string get_name(const type_info& id) {
  int stat;
  char* name = abi::__cxa_demangle(id.name(), 0, 0, &stat);
  assert(name != NULL && stat == 0);
  string res = string(name);
  free(name);
  return res;
}

template <typename T>
void test_moebius(int n = TEN(7)) {
  Timer timer;
  // moebius function
  {
    // cerr << "moebius, " << get_name(typeid(T)) << endl;
    timer.reset();
    auto m1 = mobius_function<T>(n);
    // cerr << "emf : " << timer.elapsed() << endl;

    timer.reset();
    vector<T> m2(n + 1);
    m2[1] = 1;
    divisor_transform::mobius_transform(m2);
    // cerr << "dmt : " << timer.elapsed() << endl;
    assert(m1 == m2);
  }
}

template <typename T>
void test_sigma0(int n = TEN(7)) {
  Timer timer;
  // divisor function
  {
    // cerr << "sigma0, " << get_name(typeid(T)) << endl;
    timer.reset();
    auto m1 = sigma0<T>(n);
    // cerr << "emf : " << timer.elapsed() << endl;

    timer.reset();
    vector<T> m2(n + 1, 1);
    m2[0] = 0;
    divisor_transform::zeta_transform(m2);
    // cerr << "dzt : " << timer.elapsed() << endl;
    assert(m1 == m2);
  }
}

template <typename T>
void test_sigma1(int n = TEN(7)) {
  Timer timer;
  // divisor function
  {
    // cerr << "sigma1, " << get_name(typeid(T)) << endl;
    timer.reset();
    auto m1 = sigma1<T>(n);
    // cerr << "emf : " << timer.elapsed() << endl;

    timer.reset();
    vector<T> m2(n + 1);
    rep(i, n + 1) m2[i] = i;
    divisor_transform::zeta_transform(m2);
    // cerr << "dzt : " << timer.elapsed() << endl;
    assert(m1 == m2);
  }
}

template <typename T>
void test_totient(int n = TEN(7)) {
  Timer timer;
  // divisor function
  {
    // cerr << "totient, " << get_name(typeid(T)) << endl;
    timer.reset();
    auto m1 = totient<T>(n);
    // cerr << "emf : " << timer.elapsed() << endl;

    timer.reset();
    vector<T> m2(n + 1);
    rep(i, n + 1) m2[i] = i;
    divisor_transform::mobius_transform(m2);
    // cerr << "dzt : " << timer.elapsed() << endl;

    assert(m1 == m2);
  }
}

void Nyaan::solve() {
  for (int i : vi{0, 1, 2, 3, TEN(1), TEN(2), TEN(4), TEN(6), 3333333}) {
    cerr << i << endl;
    test_moebius<char>(i);
    test_moebius<int>(i);
    test_moebius<mint>(i);

    test_sigma0<char>(i);
    test_sigma0<int>(i);
    test_sigma0<mint>(i);

    test_sigma1<int>(i);
    test_sigma1<mint>(i);

    test_totient<int>(i);
    test_totient<mint>(i);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
