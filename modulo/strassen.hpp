#pragma once
#include <immintrin.h>
//
#include <bits/stdc++.h>
using namespace std;

#include "fps/formal-power-series.hpp"
#include "modint/montgomery-modint.hpp"
#include "modint/simd-montgomery.hpp"

namespace FastMatProd {

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using m256 = __m256i;

constexpr u32 SHIFT_ = 6;
u32 a[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 b[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 c[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));

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
        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);
        const m256 A01B10 = montgomery_mul_256(A01, B10, R, M1);
        const m256 A02B20 = montgomery_mul_256(A02, B20, R, M1);
        const m256 A03B30 = montgomery_mul_256(A03, B30, R, M1);
        const u32* pc00 = c + (i0 << SHIFT_) + j0;
        const m256 C00 = _mm256_load_si256((m256*)pc00);
        const m256 C00_01 = montgomery_add_256(A00B00, A01B10, M2, M0);
        const m256 C00_23 = montgomery_add_256(A02B20, A03B30, M2, M0);
        const m256 C00_al = montgomery_add_256(C00_01, C00_23, M2, M0);
        const m256 C00_ad = montgomery_add_256(C00, C00_al, M2, M0);
        _mm256_store_si256((m256*)pc00, C00_ad);
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

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vector<fps>
fast_mul(const vector<fps>& s, const vector<fps>& t) {
  int n = s.size(), m = t[0].size(), p = t.size();
  assert(max({n, m, p}) <= (1 << SHIFT_));
  assert(p == (int)s[0].size());
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++)
    memcpy(a + (i << SHIFT_), s[i].data(), p * sizeof(int));
  for (int k = 0; k < p; k++)
    memcpy(b + (k << SHIFT_), t[k].data(), m * sizeof(int));
  inner_simd_mul(n, m, p);
  vector<fps> u(n, fps(m));
  for (int i = 0; i < n; i++)
    memcpy(u[i].data(), (mint*)(c + (i << SHIFT_)), m * sizeof(int));
  return u;
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vector<fps>
fast_mul_2(const vector<fps>& s, const vector<fps>& t) {
  int n = s.size(), m = t[0].size(), p = t.size();
  assert(max({n, p}) <= (1 << SHIFT_));
  assert(p == (int)s[0].size());
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++)
    memcpy(a + (i << SHIFT_), s[i].data(), p * sizeof(int));

  vector<fps> u(n, fps(m));
  for (int l = 0; l < m; l += (1 << SHIFT_)) {
    int bs = l;
    int be = min(m, bs + (1 << SHIFT_));
    if (bs + (1 << SHIFT_) != be) memset(b, 0, sizeof(b));
    for (int k = 0; k < p; k++)
      memcpy(b + (k << SHIFT_), t[k].data() + bs, (be - bs) * sizeof(int));
    inner_simd_mul(n, be - bs, p);
    for (int i = 0; i < n; i++)
      memcpy(u[i].data() + bs, (mint*)(c + (i << SHIFT_)),
             (be - bs) * sizeof(int));
  }
  return u;
}

// for debug
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vvm naive_mul(
    const vvm& a, const vvm& b) {
  int n = a.size(), m = b[0].size(), p = b.size();
  assert(p == (int)a[0].size());
  vvm c(n, fps(m, 0));
  for (int i = 0; i < n; i++)
    for (int k = 0; k < p; k++)
      for (int j = 0; j < m; j++) c[i][j] += a[i][k] * b[k][j];
  return c;
}
}  // namespace FastMatProd

namespace FastMatProd {
struct Mat {
  int H, W, HM, WM;
  mint* a;

  Mat(int H_, int W_, mint* a_) : H(H_), W(W_), a(a_) {
    HM = (H >> 1) + (H & 1);
    WM = (W >> 1) + (W & 1);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  range_add(mint* b, int as, int ae, int bs) const {
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
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(b + b0), BA0);
      _mm256_storeu_si256((m256*)(b + b1), BA1);
      _mm256_storeu_si256((m256*)(b + b2), BA2);
      _mm256_storeu_si256((m256*)(b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) b[bs] += a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  range_sub(mint* b, int as, int ae, int bs) const {
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
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_sub_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_sub_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_sub_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_sub_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(b + b0), BA0);
      _mm256_storeu_si256((m256*)(b + b1), BA1);
      _mm256_storeu_si256((m256*)(b + b2), BA2);
      _mm256_storeu_si256((m256*)(b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) b[bs] -= a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  op_range_add(mint* b, int as, int ae, int bs) const {
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
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(a + a0), BA0);
      _mm256_storeu_si256((m256*)(a + a1), BA1);
      _mm256_storeu_si256((m256*)(a + a2), BA2);
      _mm256_storeu_si256((m256*)(a + a3), BA3);
    }
    for (; as < ae; ++as, ++bs) a[bs] += b[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A11(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(b + i * WM, a + i * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A12(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(b + i * WM, a + i * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A21(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(b + i * WM, a + (i + HM) * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(b + i * WM, a + (i + HM) * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA11(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      range_sub(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA12(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W + WM;
      int ae = i * W + W;
      int bs = i * WM;
      range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_sub(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA11(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W, b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA12(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W + WM, b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA21(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W, b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W + WM, b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA11(mint* b) const {
    for (int i = 0; i < HM; i++)
      for (int j = 0; j < WM; j++) a[i * W + j] += b[i * WM + j];
      /*
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      op_range_add(b, as, ae, bs);
    } */
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA12(mint* b) const {
    for (int i = 0; i < HM; i++)
      for (int j = 0; j < W - WM; j++) a[i * W + WM + j] += b[i * WM + j];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA21(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      for (int j = 0; j < WM; j++) a[(i + HM) * W + j] += b[i * WM + j];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      for (int j = 0; j < W - WM; j++)
        a[(i + HM) * W + WM + j] += b[i * WM + j];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA11(mint* b) const {
    for (int i = 0; i < HM; i++)
      for (int j = 0; j < WM; j++) a[i * W + j] -= b[i * WM + j];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      for (int j = 0; j < W - WM; j++)
        a[(i + HM) * W + WM + j] -= b[i * WM + j];
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
#define BUFFER_SIZE (1 << 21)
#endif
mint A[BUFFER_SIZE] __attribute__((aligned(64)));
mint B[BUFFER_SIZE] __attribute__((aligned(64)));
mint C[BUFFER_SIZE] __attribute__((aligned(64)));

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_fast_mul(const Mat* s, const Mat* t, const Mat* u) {
  int n = s->H, m = t->W, p = s->W;
  assert(p == t->H);
  for (int i = 0; i < n; i++)
    memcpy((mint*)(a + (i << SHIFT_)), s->a + i * p, p * sizeof(int));
  for (int i = 0; i < p; i++)
    memcpy((mint*)(b + (i << SHIFT_)), t->a + i * m, m * sizeof(int));
  inner_simd_mul(n, m, p);
  for (int i = 0; i < n; i++)
    memcpy(u->a + i * m, (mint*)(c + (i << SHIFT_)), m * sizeof(int));
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_strassen(const Mat* a, const Mat* b, const Mat* c) {
  int n = a->H, m = b->W, p = a->W;
  assert(p == b->H);
  if (max({n, m, p}) <= (1 << SHIFT_)) {
    inner_fast_mul(a, b, c);
    return;
  }
  int nm = n / 2 + (n & 1);
  int mm = m / 2 + (m & 1);
  int pm = p / 2 + (p & 1);

  Mat s(nm, pm, a->a + n * p);
  Mat t(pm, mm, b->a + p * m);
  Mat u(nm, mm, c->a + n * m);

  // P1 = (A11 + A22) * (B11 + B22)
  a->A11(s.a);
  a->addA22(s.a);
  b->A11(t.a);
  b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  c->updA11(u.a);
  c->updA22(u.a);

  // P2 = (A21 + A22) * B11
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A21(s.a);
  a->addA22(s.a);
  b->A11(t.a);
  inner_strassen(&s, &t, &u);
  c->updA21(u.a);
  c->opsubA22(u.a);

  // P3 = A11 (B12 - B22)
  a->A11(s.a);
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  b->A12(t.a);
  b->subA22(t.a);
  inner_strassen(&s, &t, &u);
  c->updA12(u.a);
  c->opaddA22(u.a);

  // P4 = A22 (B21 - B11)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  b->A21(t.a);
  b->subA11(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA11(u.a);
  c->opaddA21(u.a);

  // P5 = (A11 + A12) B22
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  a->A11(s.a);
  a->addA12(s.a);
  b->A22(t.a);
  inner_strassen(&s, &t, &u);
  c->opsubA11(u.a);
  c->opaddA12(u.a);

  // P6 = (A21 - A11) (B11 + B12)
  memset((int*)s.a + (nm - 1) * pm, 0, pm * sizeof(int));
  a->A21(s.a);
  a->subA11(s.a);
  b->A11(t.a);
  b->addA12(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA22(u.a);

  // P7 = (A12 - A22) (B21 + B22)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A12(s.a);
  a->subA22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  b->A21(t.a);
  b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA11(u.a);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vvm strassen(
    const vvm& s, const vvm& t) {
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
  vvm u(n, vm(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

#ifdef BUFFER_SIZE
#undef BUFFER_SIZE
#endif
}  // namespace FastMatProd