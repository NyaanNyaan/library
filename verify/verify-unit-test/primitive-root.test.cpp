#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../atcoder/internal_math.hpp"
#include "../../math/constexpr-primitiveroot.hpp"
#include "../../math/elementary-function.hpp"
#include "../../prime/fast-factorize.hpp"
#include "../../prime/prime-enumerate.hpp"

using namespace Nyaan;

void test(unsigned int mod) {
  int pr1 = atcoder::internal::primitive_root_constexpr(mod);
  int pr2 = constexpr_primitive_root(mod);
  int pr3 = PrimitiveRoot(mod);

  if (pr1 != pr2 or pr2 != pr3) {
    cerr << pr1 << " " << pr2 << " " << pr3 << endl;
  }
}

void Nyaan::solve() {
  auto ps = prime_enumerate(20000);
  each(p, ps) test(p);

  vi rem{1, 7, 11, 13, 17, 19, 23, 29};
  rep(loop, 10000) {
    int x = -1;
    do {
      x = rem[rng() & 7] + rng() & MSK(26);
    } while (!is_prime(x));
    test(x);
  }
  cerr << "ok" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
