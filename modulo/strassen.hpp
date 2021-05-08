#pragma once
#include <immintrin.h>
//

#include "../modint/montgomery-modint.hpp"
#include "../modint/simd-montgomery.hpp"

namespace FastMatProd {

using mint = LazyMontgomeryModInt<998244353>;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using m256 = __m256i;

constexpr u32 SHIFT_ = 6;
u32 a[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 b[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 c[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
normalize_m256(const m256& x, const m256& M1) {
  m256 CMP = _mm256_cmpgt_epi32(x, M1);
  return _mm256_sub_epi32(x, _mm256_and_si256(CMP, M1));
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
simd_mulhi(const m256& _a, const m256& _b) {
  m256 a13 = _mm256_shuffle_epi32(_a, 0xF5);
  m256 b13 = _mm256_shuffle_epi32(_b, 0xF5);
  m256 prod02 = _mm256_mul_epu32(_a, _b);
  m256 prod13 = _mm256_mul_epu32(a13, b13);
  m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
  m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
  m256 prod = _mm256_unpackhi_epi64(unpalo, unpahi);
  return prod;
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
simd_reduct(const m256& prod02, const m256& prod13, const m256& R,
            const m256& M1) {
  m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
  m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
  m256 prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);
  m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);
  m256 hiplm1 = _mm256_add_epi32(prodhi, M1);
  m256 lomulr = _mm256_mullo_epi32(prodlo, R);
  m256 lomulrmulm1 = simd_mulhi(lomulr, M1);
  return _mm256_sub_epi32(hiplm1, lomulrmulm1);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
mul4(const m256& A00, const m256& A01, const m256& A02, const m256& A03,
     const m256& B00, const m256& B10, const m256& B20, const m256& B30,
     const m256& R, const m256& M1) {
  const m256 A00n = normalize_m256(A00, M1);
  const m256 A01n = normalize_m256(A01, M1);
  const m256 A02n = normalize_m256(A02, M1);
  const m256 A03n = normalize_m256(A03, M1);
  const m256 B00n = normalize_m256(B00, M1);
  const m256 B10n = normalize_m256(B10, M1);
  const m256 B20n = normalize_m256(B20, M1);
  const m256 B30n = normalize_m256(B30, M1);

  m256 a013 = _mm256_shuffle_epi32(A00n, 0xF5);
  m256 b013 = _mm256_shuffle_epi32(B00n, 0xF5);
  m256 a113 = _mm256_shuffle_epi32(A01n, 0xF5);
  m256 b113 = _mm256_shuffle_epi32(B10n, 0xF5);
  m256 a213 = _mm256_shuffle_epi32(A02n, 0xF5);
  m256 b213 = _mm256_shuffle_epi32(B20n, 0xF5);
  m256 a313 = _mm256_shuffle_epi32(A03n, 0xF5);
  m256 b313 = _mm256_shuffle_epi32(B30n, 0xF5);
  m256 p0_02 = _mm256_mul_epu32(A00n, B00n);
  m256 p0_13 = _mm256_mul_epu32(a013, b013);
  m256 p1_02 = _mm256_mul_epu32(A01n, B10n);
  m256 p1_13 = _mm256_mul_epu32(a113, b113);
  m256 p2_02 = _mm256_mul_epu32(A02n, B20n);
  m256 p2_13 = _mm256_mul_epu32(a213, b213);
  m256 p3_02 = _mm256_mul_epu32(A03n, B30n);
  m256 p3_13 = _mm256_mul_epu32(a313, b313);
  m256 p02_02 = _mm256_add_epi64(p0_02, p2_02);
  m256 p13_02 = _mm256_add_epi64(p1_02, p3_02);
  m256 prod02 = _mm256_add_epi64(p02_02, p13_02);
  m256 p02_13 = _mm256_add_epi64(p0_13, p2_13);
  m256 p13_13 = _mm256_add_epi64(p1_13, p3_13);
  m256 prod13 = _mm256_add_epi64(p02_13, p13_13);
  return simd_reduct(prod02, prod13, R, M1);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_simd_mul(u32 n, u32 m, u32 p) {
  memset(c, 0, sizeof(c));
  const m256 R = _mm256_set1_epi32(mint::r);
  const m256 M0 = _mm256_set1_epi32(0);
  const m256 M1 = _mm256_set1_epi32(mint::get_mod());
  const m256 M2 = _mm256_set1_epi32(mint::get_mod() << 1);

  u32 k0 = 0;
  for (; i32(k0) < i32(p) - 3; k0 += 4) {
    const u32 k1 = k0 + 1;
    const u32 k2 = k0 + 2;
    const u32 k3 = k0 + 3;
    u32 j0 = 0;
    for (; i32(j0) < i32(m) - 7; j0 += 8) {
      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_) + j0));
      const m256 B10 = _mm256_load_si256((m256*)(b + (k1 << SHIFT_) + j0));
      const m256 B20 = _mm256_load_si256((m256*)(b + (k2 << SHIFT_) + j0));
      const m256 B30 = _mm256_load_si256((m256*)(b + (k3 << SHIFT_) + j0));
      for (u32 i0 = 0; i0 < n; ++i0) {
        const m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);
        const m256 A01 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k1]);
        const m256 A02 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k2]);
        const m256 A03 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k3]);
        const u32* pc00 = c + (i0 << SHIFT_) + j0;
        const m256 C00 = _mm256_load_si256((m256*)pc00);
        const m256 C00_ad = mul4(A00, A01, A02, A03, B00, B10, B20, B30, R, M1);
        const m256 C00sum = montgomery_add_256(C00, C00_ad, M2, M0);
        _mm256_store_si256((m256*)pc00, C00sum);
      }
    }
    for (; j0 < m; j0++) {
      for (u32 i0 = 0; i0 < n; ++i0) {
        u32 ab0 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0 << SHIFT_) | j0]);
        u32 ab1 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k1]) * b[(k1 << SHIFT_) | j0]);
        u32 ab2 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k2]) * b[(k2 << SHIFT_) | j0]);
        u32 ab3 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k3]) * b[(k3 << SHIFT_) | j0]);
        if ((ab0 += ab1) >= 2 * mint::get_mod()) ab0 -= 2 * mint::get_mod();
        if ((ab2 += ab3) >= 2 * mint::get_mod()) ab2 -= 2 * mint::get_mod();
        if ((ab0 += ab2) >= 2 * mint::get_mod()) ab0 -= 2 * mint::get_mod();
        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())
          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();
      }
    }
  }

  for (; k0 < p; k0++) {
    u32 j0 = 0;
    for (; i32(j0) < i32(m) - 7; j0 += 8) {
      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_) + j0));
      for (u32 i0 = 0; i0 < n; ++i0) {
        const m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);
        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);
        const u32* pc00 = c + (i0 << SHIFT_) + j0;
        const m256 C00 = _mm256_load_si256((m256*)pc00);
        const m256 C00_ad = montgomery_add_256(C00, A00B00, M2, M0);
        _mm256_store_si256((m256*)pc00, C00_ad);
      }
    }
    for (; j0 < m; j0++) {
      for (u32 i0 = 0; i0 < n; ++i0) {
        u32 ab0 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0 << SHIFT_) | j0]);
        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())
          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();
      }
    }
  }
}

struct Mat {
  int H, W, HM, WM;
  mint* a;

  Mat(int H_, int W_, mint* a_) : H(H_), W(W_), a(a_) {
    HM = (H >> 1) + (H & 1);
    WM = (W >> 1) + (W & 1);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  range_add(mint* _b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(_b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(_b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(_b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(_b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(_b + b0), BA0);
      _mm256_storeu_si256((m256*)(_b + b1), BA1);
      _mm256_storeu_si256((m256*)(_b + b2), BA2);
      _mm256_storeu_si256((m256*)(_b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) _b[bs] += a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  range_sub(mint* _b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(_b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(_b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(_b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(_b + b3));
      const m256 BA0 = montgomery_sub_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_sub_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_sub_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_sub_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(_b + b0), BA0);
      _mm256_storeu_si256((m256*)(_b + b1), BA1);
      _mm256_storeu_si256((m256*)(_b + b2), BA2);
      _mm256_storeu_si256((m256*)(_b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) _b[bs] -= a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  op_range_add(mint* _b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(_b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(_b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(_b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(_b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(a + a0), BA0);
      _mm256_storeu_si256((m256*)(a + a1), BA1);
      _mm256_storeu_si256((m256*)(a + a2), BA2);
      _mm256_storeu_si256((m256*)(a + a3), BA3);
    }
    for (; as < ae; ++as, ++bs) a[as] += _b[bs];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  op_range_sub(mint* _b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(_b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(_b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(_b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(_b + b3));
      const m256 BA0 = montgomery_sub_256(A0, B0, M2, M0);
      const m256 BA1 = montgomery_sub_256(A1, B1, M2, M0);
      const m256 BA2 = montgomery_sub_256(A2, B2, M2, M0);
      const m256 BA3 = montgomery_sub_256(A3, B3, M2, M0);
      _mm256_storeu_si256((m256*)(a + a0), BA0);
      _mm256_storeu_si256((m256*)(a + a1), BA1);
      _mm256_storeu_si256((m256*)(a + a2), BA2);
      _mm256_storeu_si256((m256*)(a + a3), BA3);
    }
    for (; as < ae; ++as, ++bs) a[as] -= _b[bs];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A11(mint* _b) const {
    for (int i = 0; i < HM; i++)
      memcpy(_b + i * WM, a + i * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A12(mint* _b) const {
    for (int i = 0; i < HM; i++)
      memcpy(_b + i * WM, a + i * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A21(mint* _b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(_b + i * WM, a + (i + HM) * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A22(mint* _b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(_b + i * WM, a + (i + HM) * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA11(mint* _b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      range_sub(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA12(mint* _b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W + WM;
      int ae = i * W + W;
      int bs = i * WM;
      range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA22(mint* _b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA22(mint* _b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_sub(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA11(mint* _b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W, _b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA12(mint* _b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W + WM, _b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA21(mint* _b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W, _b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA22(mint* _b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W + WM, _b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA11(mint* _b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      op_range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA12(mint* _b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W + WM;
      int ae = i * W + W;
      int bs = i * WM;
      op_range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA21(mint* _b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W;
      int ae = (i + HM) * W + WM;
      int bs = i * WM;
      op_range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA22(mint* _b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = (i + HM) * W + W;
      int bs = i * WM;
      op_range_add(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA11(mint* _b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      op_range_sub(_b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA22(mint* _b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = (i + HM) * W + W;
      int bs = i * WM;
      op_range_sub(_b, as, ae, bs);
    }
  }

  void dump() const {
    cerr << "[ " << endl << " ";
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        cerr << a[i * W + j] << (j == W - 1 ? ",\n " : " ");
    cerr << "] " << endl;
  }
};

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1 << 23)
#endif
mint A[BUFFER_SIZE] __attribute__((aligned(64)));
mint B[BUFFER_SIZE] __attribute__((aligned(64)));
mint C[BUFFER_SIZE] __attribute__((aligned(64)));

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_fast_mul(const Mat* s, const Mat* t, const Mat* u) {
  int n = s->H, m = t->W, p = s->W;
  for (int i = 0; i < n; i++)
    memcpy((mint*)(a + (i << SHIFT_)), s->a + i * p, p * sizeof(int));
  for (int i = 0; i < p; i++)
    memcpy((mint*)(b + (i << SHIFT_)), t->a + i * m, m * sizeof(int));
  inner_simd_mul(n, m, p);
  for (int i = 0; i < n; i++)
    memcpy(u->a + i * m, (mint*)(c + (i << SHIFT_)), m * sizeof(int));
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_block_dec_mul(const Mat* s, const Mat* t, const Mat* u) {
  int n = s->H, m = t->W, p = s->W;
  memset((int*)(u->a), 0, n * m * sizeof(int));
  for (int is = 0; is < n; is += (1 << SHIFT_))
    for (int ks = 0; ks < p; ks += (1 << SHIFT_))
      for (int js = 0; js < m; js += (1 << SHIFT_)) {
        int ie = min(is + (1 << SHIFT_), n);
        int je = min(js + (1 << SHIFT_), m);
        int ke = min(ks + (1 << SHIFT_), p);
        for (int l = is; l < ie; l++)
          memcpy((mint*)(a + ((l - is) << SHIFT_)), s->a + l * p + ks,
                 (ke - ks) * sizeof(int));
        for (int l = ks; l < ke; l++)
          memcpy((mint*)(b + ((l - ks) << SHIFT_)), t->a + l * m + js,
                 (je - js) * sizeof(int));
        inner_simd_mul(ie - is, je - js, ke - ks);
        for (int l = is; l < ie; l++) {
          for (int ll = js; ll < je; ll++) {
            u->a[l * m + ll] +=
                *reinterpret_cast<mint*>(c + ((l - is) << SHIFT_) + (ll - js));
          }
        }
      }
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_strassen(const Mat* _a, const Mat* _b, const Mat* _c) {
  int n = _a->H, m = _b->W, p = _a->W;
  if (max({n, m, p}) <= (1 << SHIFT_)) {
    inner_fast_mul(_a, _b, _c);
    return;
  }
  if (min({n, m, p}) <= (1 << (SHIFT_ - 2))) {
    inner_block_dec_mul(_a, _b, _c);
    return;
  }
  int nm = n / 2 + (n & 1);
  int mm = m / 2 + (m & 1);
  int pm = p / 2 + (p & 1);

  Mat s(nm, pm, _a->a + n * p);
  Mat t(pm, mm, _b->a + p * m);
  Mat u(nm, mm, _c->a + n * m);

  // P1 = (A11 + A22) * (B11 + B22)
  _a->A11(s.a);
  _a->addA22(s.a);
  _b->A11(t.a);
  _b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  _c->updA11(u.a);
  _c->updA22(u.a);

  // P2 = (A21 + A22) * B11
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  _a->A21(s.a);
  _a->addA22(s.a);
  _b->A11(t.a);
  inner_strassen(&s, &t, &u);
  _c->updA21(u.a);
  _c->opsubA22(u.a);

  // P3 = A11 (B12 - B22)
  _a->A11(s.a);
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  _b->A12(t.a);
  _b->subA22(t.a);
  inner_strassen(&s, &t, &u);
  _c->updA12(u.a);
  _c->opaddA22(u.a);

  // P4 = A22 (B21 - B11)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  _a->A22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  _b->A21(t.a);
  _b->subA11(t.a);
  inner_strassen(&s, &t, &u);
  _c->opaddA11(u.a);
  _c->opaddA21(u.a);

  // P5 = (A11 + A12) B22
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  _a->A11(s.a);
  _a->addA12(s.a);
  _b->A22(t.a);
  inner_strassen(&s, &t, &u);
  _c->opsubA11(u.a);
  _c->opaddA12(u.a);

  // P6 = (A21 - A11) (B11 + B12)
  memset((int*)s.a + (nm - 1) * pm, 0, pm * sizeof(int));
  _a->A21(s.a);
  _a->subA11(s.a);
  _b->A11(t.a);
  _b->addA12(t.a);
  inner_strassen(&s, &t, &u);
  _c->opaddA22(u.a);

  // P7 = (A12 - A22) (B21 + B22)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  _a->A12(s.a);
  _a->subA22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  _b->A21(t.a);
  _b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  _c->opaddA11(u.a);
}

template <typename fps>
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vector<fps>
block_dec(const vector<fps>& s, const vector<fps>& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_block_dec_mul(&S, &T, &U);
  vector<fps> u(n, fps(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

template <typename fps>
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vector<fps>
strassen(const vector<fps>& s, const vector<fps>& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_strassen(&S, &T, &U);
  vector<fps> u(n, fps(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

#ifdef BUFFER_SIZE
#undef BUFFER_SIZE
#endif
}  // namespace FastMatProd
