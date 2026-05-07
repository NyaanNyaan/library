#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
#include "../../modint/simd-montgomery-avx512.hpp"
using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;

__attribute__((target("avx2"))) void simd_test() {
  mint a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  mint b[8] = {9, 10, 11, 12, 13, 14, 15, 16};
  mint c[8];
  {
    m128 A = _mm_loadu_si128((m128 *)a);
    m128 B = _mm_loadu_si128((m128 *)b);
    m128 C = mul_128(A, B);
    _mm_storeu_si128((m128 *)c, C);
    rep(i, 4) {
      cerr << c[i] << " \n"[i + 1 == 4];
      assert(a[i] * b[i] == c[i]);
    }
  }
  {
    m256 A = _mm256_loadu_si256((m256 *)a);
    m256 B = _mm256_loadu_si256((m256 *)b);
    m256 C = mul_256(A, B);
    _mm256_storeu_si256((m256 *)c, C);
    rep(i, 8) {
      cerr << c[i] << " \n"[i + 1 == 8];
      assert(a[i] * b[i] == c[i]);
    }
  }
}

__attribute__((target("avx512f"))) void simd_test512() {
  mint a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  mint b[16] = {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
  mint c[16];
  m512 A = _mm512_loadu_epi32(a);
  m512 B = _mm512_loadu_epi32(b);

  m512 C = mul_512(A, B);
  _mm512_storeu_epi32(c, C);
  rep(i, 16) {
    cerr << c[i] << " \n"[i + 1 == 16];
    assert(a[i] * b[i] == c[i]);
  }
}

void q() {
  simd_test();
  simd_test512();

  trc2("OK");

  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
