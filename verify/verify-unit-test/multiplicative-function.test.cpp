#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../competitive-template.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;

#include "../../multiplicative-function/divisor-multiple-transform.hpp"
void test() {
  // 約数・倍数ゼータ/メビウス変換のverify
  auto map_transform = [](int n) {
    map<ll, mint> a;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        a[i] = rng();
        a[n / i] = rng();
      }
    }
    auto a1 = a;
    divisor_transform::zeta_transform(a1);
    divisor_transform::mobius_transform(a1);
    assert(a1 == a && "divisor_transform");

    multiple_transform::zeta_transform(a1);
    multiple_transform::mobius_transform(a1);
    assert(a1 == a && "multiple_transform");
  };
  rep(i, 1000) { map_transform(rng() % 100000 + 1); }
  rep1(i, 100) { map_transform(840 * i); }

  

}

void solve() {
  test();
  trc("test OK");
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}