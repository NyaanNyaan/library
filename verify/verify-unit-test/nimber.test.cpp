#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/nimber.hpp"
#include "../../misc/rng.hpp"

// 古い実装
namespace nimber {
using u64 = uint64_t;

u64 calc(u64, u64, int p, int pre);

struct Precalc {
  u64 dp[256][256];
  Precalc() {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[j][i] = calc(i, j, 8, true);
      }
  }

} precalc;

u64 calc(u64 a, u64 b, int p = 64, int pre = false) {
  if (min(a, b) <= 1) return a * b;
  while (max(a, b) < 1ull << (p >> 1)) p >>= 1;
  if (!pre && p <= 8) return precalc.dp[a][b];
  p >>= 1;
  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);
  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);
  u64 c = calc(a1, b1, p, pre);
  u64 d = calc(a2, b2, p, pre);
  u64 e = calc(a1 ^ a2, b1 ^ b2, p, pre);
  return calc(c, 1ull << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);
}

u64 nim_product(u64 a, u64 b) { return calc(a, b); }

}  // namespace nimber
using nimber::nim_product;

using namespace Nyaan;

void Nyaan::solve() {
  using namespace NimberImpl;

  rep(i, 256) rep(j, 256) {
    auto x1 = nim_product(i, j);
    auto x2 = c8.dp[i][j];
    auto x3 = c16.prod(i, j);
    auto x4 = product32(i, j);
    auto x5 = product64(i, j);
    assert(x1 == x2);
    assert(x1 == x3);
    assert(x1 == x4);
    assert(x1 == x5);
  }
  cerr << "256 OK" << endl;

  rep(t, TEN(6)) {
    u16 i = rng();
    u16 j = rng();
    auto x1 = nim_product(i, j);
    auto x3 = c16.prod(i, j);
    auto x4 = product32(i, j);
    auto x5 = product64(i, j);
    assert(x1 == x3);
    assert(x1 == x4);
    assert(x1 == x5);
  }
  cerr << "65536 OK" << endl;

  rep(t, TEN(6)) {
    u32 i = rng();
    u32 j = rng();
    auto x1 = nim_product(i, j);
    auto x4 = product32(i, j);
    auto x5 = product64(i, j);
    assert(x1 == x4);
    assert(x1 == x5);
  }
  cerr << "2^32 OK" << endl;

  rep(t, TEN(6)) {
    u64 i = rng();
    u64 j = rng();
    auto x1 = nim_product(i, j);
    auto x5 = product64(i, j);
    assert(x1 == x5);
  }
  cerr << "2^64 OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
