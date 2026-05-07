#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
#include "../../ntt/ntt.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
//
#include "../../modint/modint-2-27p2-25p1.hpp"
//
#include "../../ntt/ntt-avx2-mod2-27p2-25p1.hpp"

using m256 = __m256i;

/*
__attribute__((target("avx2"))) inline m256 add_256(const m256 &A,
                                                    const m256 &B,
                                                    const m256 &M2) {
  m256 ret = _mm256_add_epi32(A, B);
  m256 ret_sub = _mm256_sub_epi32(ret, M2);
  return _mm256_min_epu32(ret, ret_sub);
}
__attribute__((target("avx2"))) inline m256 sub_256(const m256 &A,
                                                    const m256 &B,
                                                    const m256 &M2) {
  m256 ret = _mm256_sub_epi32(A, B);
  m256 ret_add = _mm256_add_epi32(ret, M2);
  return _mm256_min_epu32(ret, ret_add);
}
__attribute__((target("avx2"))) inline m256 mul_256(const m256 &A,
                                                    const m256 &B) {
  m256 a13 = _mm256_shuffle_epi32(A, 0xF5);
  m256 b13 = _mm256_shuffle_epi32(B, 0xF5);
  // | c0 := a0 * b0 | c2 := a2 * b2 |
  m256 prod02 = _mm256_mul_epu32(A, B);
  // | c1 := a1 * b1 | c3 := a3 * b3 |
  m256 prod13 = _mm256_mul_epu32(a13, b13);
  // |  c0l  |  c1l  |  c0h  |  c1h  |
  m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
  // |  c2l  |  c3l  |  c2h  |  c3h  |
  m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
  // |  c0l  |  c1l  |  c2l  |  c3l  |
  m256 prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);
  // |  c0h  |  c1h  |  c2h  |  c3h  |
  // m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);

  m256 losl27 = _mm256_slli_epi32(prodlo, 27);
  m256 losl25 = _mm256_slli_epi32(prodlo, 25);
  m256 xmid = _mm256_add_epi32(losl27, losl25);
  m256 x = _mm256_sub_epi32(xmid, prodlo);

  m256 mask = _mm256_set_epi32(0, -1u, 0, -1u, 0, -1u, 0, -1u);
  m256 x02 = _mm256_and_si256(x, mask);
  m256 x13 = _mm256_and_si256(_mm256_shuffle_epi32(x, 0xF5), mask);

  m256 x02sl27 = _mm256_slli_epi64(x02, 27);
  m256 x02sl25 = _mm256_slli_epi64(x02, 25);
  m256 s02 = _mm256_add_epi64(prod02, x02);
  m256 t02 = _mm256_add_epi64(x02sl27, x02sl25);
  m256 u02 = _mm256_add_epi64(s02, t02);

  m256 x13sl27 = _mm256_slli_epi64(x13, 27);
  m256 x13sl25 = _mm256_slli_epi64(x13, 25);
  m256 s13 = _mm256_add_epi64(prod13, x13);
  m256 t13 = _mm256_add_epi64(x13sl27, x13sl25);
  m256 u13 = _mm256_add_epi64(s13, t13);

  m256 unpalo2 = _mm256_unpacklo_epi32(u02, u13);
  m256 unpahi2 = _mm256_unpackhi_epi32(u02, u13);
  return _mm256_unpackhi_epi64(unpalo2, unpahi2);
}
*/

using namespace Nyaan;

__attribute__((target("avx2"))) void simd_test() {
  using mint = modint2_27p2_25p1;

  mint a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  mint b[8] = {9, 10, 11, 12, 13, 14, 15, 16};
  mint c[8];
  m256 A = _mm256_loadu_si256((m256 *)a);
  m256 B = _mm256_loadu_si256((m256 *)b);
  m256 C = mul_256(A, B);
  _mm256_storeu_si256((m256 *)c, C);
  rep(i, 8) {
    cerr << c[i] << " \n"[i + 1 == 8];
    assert(a[i] * b[i] == c[i]);
  }
}

void q() {
  using mint = modint2_27p2_25p1;
  unsigned mod = mint::get_mod();
  {
    auto check = [&](u64 a, u64 b) {
      assert(a < mod and b < mod);
      mint A = a, B = b;
      assert((A + B).get() == (a + b) % mod);
      assert((A - B).get() == (a + mod - b) % mod);
      assert((A * B).get() == a * b % mod);
    };

    rep(a, 100) rep(b, 100) {
      check(a, b);
      check(a, mod - 1 - b);
      check(mod - 1 - a, b);
      check(mod - 1 - a, mod - 1 - b);
      rep(t, 10) {
        check(a, rng(0, mod - 1));
        check(rng(0, mod - 1), b);
        check(mod - 1 - a, rng(0, mod - 1));
        check(rng(0, mod - 1), mod - 1 - b);
      }
    }
    rep(t, TEN(5)) check(rng(0, mod - 1), rng(0, mod - 1));
    trc2("modint OK");
  }

  simd_test();
  {
    using mint2 = LazyMontgomeryModInt<998244353>;
    NTT_mod2_27p2_25p1<mint> ntt;
    NTT<mint2> ntt2;

    int N = 1 << 20;
    vi a(N), b(N);
    each(x, a) x = rng(0, 1);
    each(x, b) x = rng(0, 1);

    vector<mint2> A2(N), B2(N);
    rep(i, N) A2[i] = a[i], B2[i] = b[i];
    Timer timer2;
    auto C2 = ntt2.multiply(A2, B2);
    int t2 = timer2();

    vector<mint> A(N), B(N);
    rep(i, N) A[i] = a[i], B[i] = b[i];
    Timer timer;
    auto C = ntt.multiply(A, B);
    int t = timer();

    trc2(t, t2);
    rep(i, N) assert(C[i].get() == C2[i].get());
  }

  {
    int a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
