#pragma once

#include "../atcoder/math.hpp"
#include "../modint/barrett-reduction.hpp"

#define PRIME_POWER_BINOMIAL_M_MAX ((1LL << 30) - 1)
#define PRIME_POWER_BINOMIAL_N_MAX 20000000

struct simd_prime_binomial {
  using u32 = unsigned int;
  using i64 = long long;
  using u64 = unsigned long long;
  using m256 = __m256i;

  u32 get_r(u32 _mod) {
    u32 ret = _mod;
    for (int i = 0; i < 4; ++i) ret *= 2 - _mod * ret;
    return ret;
  }
  inline u32 reduce(const u64& b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }
  inline u32 mul(const u32& a, const u32& b) { return reduce(u64(a) * b); }
  inline u32 add(const u32& a, const u32& b) {
    u32 c = a + b - 2 * mod;
    if (c > 2 * mod) c += 2 * mod;
    return c;
  }
  inline u32 cast(const i64& b) { return reduce(u64(b % mod + mod) * n2); }
  inline u32 raw_cast(const u64& b) { return reduce(b * n2); }
  u64 get(const u32& b) {
    u32 a = reduce(b);
    return a >= mod ? a - mod : a;
  }
  u32 inv(u32 b) {
    u32 e = mod - 2, a = raw_cast(1);
    while (e) {
      if (e & 1) a = mul(a, b);
      b = mul(b, b);
      e >>= 1;
    }
    return a;
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
  simd_mulhi(const m256& a, const m256& b) {
    m256 a13 = _mm256_shuffle_epi32(a, 0xF5);
    m256 b13 = _mm256_shuffle_epi32(b, 0xF5);
    m256 prod02 = _mm256_mul_epu32(a, b);
    m256 prod13 = _mm256_mul_epu32(a13, b13);
    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
    m256 prod = _mm256_unpackhi_epi64(unpalo, unpahi);
    return prod;
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
  simd_sub(const m256& a, const m256& b) {
    m256 ret = _mm256_sub_epi32(a, b);
    m256 cmp = _mm256_cmpgt_epi32(M0, ret);
    m256 add = _mm256_and_si256(cmp, M2);
    return _mm256_add_epi32(add, ret);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline m256
  simd_mul(const m256& A, const m256& B) {
    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);
    m256 b13 = _mm256_shuffle_epi32(B, 0xF5);
    m256 prod02 = _mm256_mul_epu32(A, B);
    m256 prod13 = _mm256_mul_epu32(a13, b13);
    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
    m256 prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);
    m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);
    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);
    m256 lomulr = _mm256_mullo_epi32(prodlo, R);
    m256 lomulrmulm1 = simd_mulhi(lomulr, M1);
    return _mm256_sub_epi32(hiplm1, lomulrmulm1);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  transpose8_ps(__m256& row0, __m256& row1, __m256& row2, __m256& row3,
                __m256& row4, __m256& row5, __m256& row6, __m256& row7) {
    __m256 __t0, __t1, __t2, __t3, __t4, __t5, __t6, __t7;
    __m256 __tt0, __tt1, __tt2, __tt3, __tt4, __tt5, __tt6, __tt7;
    __t0 = _mm256_unpacklo_ps(row0, row1);
    __t1 = _mm256_unpackhi_ps(row0, row1);
    __t2 = _mm256_unpacklo_ps(row2, row3);
    __t3 = _mm256_unpackhi_ps(row2, row3);
    __t4 = _mm256_unpacklo_ps(row4, row5);
    __t5 = _mm256_unpackhi_ps(row4, row5);
    __t6 = _mm256_unpacklo_ps(row6, row7);
    __t7 = _mm256_unpackhi_ps(row6, row7);
    __tt0 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(1, 0, 1, 0));
    __tt1 = _mm256_shuffle_ps(__t0, __t2, _MM_SHUFFLE(3, 2, 3, 2));
    __tt2 = _mm256_shuffle_ps(__t1, __t3, _MM_SHUFFLE(1, 0, 1, 0));
    __tt3 = _mm256_shuffle_ps(__t1, __t3, _MM_SHUFFLE(3, 2, 3, 2));
    __tt4 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(1, 0, 1, 0));
    __tt5 = _mm256_shuffle_ps(__t4, __t6, _MM_SHUFFLE(3, 2, 3, 2));
    __tt6 = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(1, 0, 1, 0));
    __tt7 = _mm256_shuffle_ps(__t5, __t7, _MM_SHUFFLE(3, 2, 3, 2));
    row0 = _mm256_permute2f128_ps(__tt0, __tt4, 0x20);
    row1 = _mm256_permute2f128_ps(__tt1, __tt5, 0x20);
    row2 = _mm256_permute2f128_ps(__tt2, __tt6, 0x20);
    row3 = _mm256_permute2f128_ps(__tt3, __tt7, 0x20);
    row4 = _mm256_permute2f128_ps(__tt0, __tt4, 0x31);
    row5 = _mm256_permute2f128_ps(__tt1, __tt5, 0x31);
    row6 = _mm256_permute2f128_ps(__tt2, __tt6, 0x31);
    row7 = _mm256_permute2f128_ps(__tt3, __tt7, 0x31);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  precalc() {
    __attribute__((aligned(32))) u32 b1[32];
    __attribute__((aligned(32))) __m256 b2[8];
    int max = ((mod / 2) / v + 12) / 8 * 8;
    f.resize(max + 1, raw_cast(1));
    for (int i = 0; i < 32; i++) b1[i] = raw_cast(i + 1);
    m256 A0 = _mm256_set1_epi32(b1[0]);
    m256 A1 = _mm256_set1_epi32(b1[0]);
    m256 A2 = _mm256_set1_epi32(b1[0]);
    m256 A3 = _mm256_set1_epi32(b1[0]);
    m256 B0 = _mm256_load_si256((m256*)(b1 + 0));
    m256 B1 = _mm256_load_si256((m256*)(b1 + 8));
    m256 B2 = _mm256_load_si256((m256*)(b1 + 16));
    m256 B3 = _mm256_load_si256((m256*)(b1 + 24));
    m256 DI = _mm256_set1_epi32(mod * 2 - b1[31]);
    for (int i = 1; i < (int)f.size(); i += 8) {
      for (int j = 0; j < 8; j++) {
        for (u32 loop = 0; loop < v / 32; loop++) {
          A0 = simd_mul(A0, B0), A1 = simd_mul(A1, B1);
          A2 = simd_mul(A2, B2), A3 = simd_mul(A3, B3);
          B0 = simd_sub(B0, DI), B1 = simd_sub(B1, DI);
          B2 = simd_sub(B2, DI), B3 = simd_sub(B3, DI);
        }
        m256 C0 = simd_mul(A0, A1);
        m256 C1 = simd_mul(A2, A3);
        m256 C2 = simd_mul(C0, C1);
        _mm256_store_si256((m256*)(b2 + j), C2);
      }
      transpose8_ps(b2[0], b2[1], b2[2], b2[3], b2[4], b2[5], b2[6], b2[7]);
      m256 D0 = simd_mul(m256(b2[0]), m256(b2[1]));
      m256 D1 = simd_mul(m256(b2[2]), m256(b2[3]));
      m256 D2 = simd_mul(m256(b2[4]), m256(b2[5]));
      m256 D3 = simd_mul(m256(b2[6]), m256(b2[7]));
      m256 D4 = simd_mul(D0, D1);
      m256 D5 = simd_mul(D2, D3);
      m256 D6 = simd_mul(D4, D5);
      _mm256_storeu_si256((m256*)(f.data() + i), D6);
    }
  }

  u32 mod, r, n2;
  Barrett bm;
  m256 R, M0, M1, M2;
  static constexpr u32 v = 128;
  static_assert(v % 32 == 0);
  vector<u32> f;

  simd_prime_binomial() = default;

  __attribute__((target("avx2"), optimize("O3", "unroll-loops")))
  simd_prime_binomial(u32 _mod)
      : mod(_mod) {
    assert(2 < mod && mod < (1u << 30));
    assert(mod % 2 != 0);
    r = get_r(mod);
    n2 = -u64(mod) % mod;
    bm = Barrett(mod);
    R = _mm256_set1_epi32(r);
    M0 = _mm256_set1_epi32(0);
    M1 = _mm256_set1_epi32(mod);
    M2 = _mm256_set1_epi32(mod * 2);
    precalc();
  }

  u32 raw_fac(u64 n) {
    assert(n < mod);
    if (n * 2 > mod + 2) {
      u64 x = raw_fac(mod - 1 - n);
      if (n % 2 == 0) x = mod * 2 - x;
      return inv(x);
    }
    u32 a = f[n / v], i = n / v * v + 1;
    u32 j = raw_cast(i), o = raw_cast(1);
    while (i++ <= n) {
      a = mul(a, j), j = add(j, o);
    }
    return a;
  }

  inline u32 fac(u64 n) {
    if (n >= mod) return 0;
    return get(raw_fac(n));
  }

  u32 C(long long n, long long m) {
    if (n < 0 or m < 0 or n < m) return 0;
    u32 num = raw_cast(1), denom = raw_cast(1);
    while (n) {
      long long n0, m0;
      tie(n, n0) = bm.quorem(n);
      tie(m, m0) = bm.quorem(m);
      if (n0 < m0) return 0;
      num = mul(num, raw_fac(n0));
      denom = mul(denom, raw_fac(n0 - m0));
      denom = mul(denom, raw_fac(m0));
    }
    return get(mul(num, inv(denom)));
  }
};

struct prime_power_binomial {
  int p, q, M;
  vector<int> fac, ifac, inv;
  int delta;
  Barrett bm, bp;

  prime_power_binomial() = default;

  prime_power_binomial(int _p, int _q) : p(_p), q(_q) {
    assert(1 < p && p <= PRIME_POWER_BINOMIAL_M_MAX);
    assert(_q > 0);
    long long m = 1;
    while (_q--) {
      m *= p;
      assert(m <= PRIME_POWER_BINOMIAL_M_MAX);
    }
    M = m;
    bm = Barrett(M), bp = Barrett(p);
    enumerate();
    delta = (p == 2 && q >= 3) ? 1 : M - 1;
  }

  void enumerate() {
    int MX = min<int>(M, PRIME_POWER_BINOMIAL_N_MAX + 10);
    fac.resize(MX);
    ifac.resize(MX);
    inv.resize(MX);
    fac[0] = ifac[0] = inv[0] = 1;
    fac[1] = ifac[1] = inv[1] = 1;
    for (int i = 2; i < MX; i++) {
      if (i % p == 0) {
        fac[i] = fac[i - 1];
        fac[i + 1] = bm.rem(1LL * fac[i - 1] * (i + 1));
        i++;
      } else {
        fac[i] = bm.rem(1LL * fac[i - 1] * i);
      }
    }
    ifac[MX - 1] = bm.pow(fac[MX - 1], M / p * (p - 1) - 1);
    for (int i = MX - 2; i > 1; --i) {
      if (i % p == 0) {
        ifac[i] = bm.rem(1LL * ifac[i + 1] * (i + 1));
        ifac[i - 1] = ifac[i];
        i--;
      } else {
        ifac[i] = bm.rem(1LL * ifac[i + 1] * (i + 1));
      }
    }
  }

  long long Lucas(long long n, long long m) {
    int res = 1;
    while (n) {
      int n0, m0;
      tie(n, n0) = bp.quorem(n);
      tie(m, m0) = bp.quorem(m);
      if (n0 < m0) return 0;
      res = bm.rem(1LL * res * fac[n0]);
      int buf = bm.rem(1LL * ifac[n0 - m0] * ifac[m0]);
      res = bm.rem(1LL * res * buf);
    }
    return res;
  }

  long long C(long long n, long long m) {
    if (n < m || n < 0 || m < 0) return 0;
    if (q == 1) return Lucas(n, m);
    long long r = n - m;
    int e0 = 0, eq = 0, i = 0;
    int res = 1;
    while (n) {
      res = bm.rem(1LL * res * fac[bm.rem(n)]);
      res = bm.rem(1LL * res * ifac[bm.rem(m)]);
      res = bm.rem(1LL * res * ifac[bm.rem(r)]);
      n = bp.quo(n);
      m = bp.quo(m);
      r = bp.quo(r);
      int eps = n - m - r;
      e0 += eps;
      if (e0 >= q) return 0;
      if (++i >= q) eq += eps;
    }
    if (eq & 1) res = bm.rem(1LL * res * delta);
    res = bm.rem(1LL * res * bm.pow(p, e0));
    return res;
  }
};

// constraints:
// M <= 1e9 and max(N) <= 1e18
struct arbitrary_mod_binomial {
  int mod;
  vector<int> M1, M2;
  vector<prime_power_binomial> cs1;
  vector<simd_prime_binomial> cs2;

  void push_cs(int i, int j, int k) {
    if (i < PRIME_POWER_BINOMIAL_N_MAX || j != 1) {
      cs1.emplace_back(i, j);
      M1.push_back(k);
    } else {
      assert(j == 1);
      cs2.emplace_back(i);
      M2.push_back(k);
    }
  }

  arbitrary_mod_binomial(long long md) : mod(md) {
    assert(1 <= md);
    assert(md <= PRIME_POWER_BINOMIAL_M_MAX);
    for (int i = 2; i * i <= md; i++) {
      if (md % i == 0) {
        int j = 0, k = 1;
        while (md % i == 0) md /= i, j++, k *= i;
        push_cs(i, j, k);
      }
    }
    if (md != 1) push_cs(md, 1, md);
    assert(M1.size() == cs1.size());
    assert(M2.size() == cs2.size());
  }

  long long C(long long n, long long m) {
    if (mod == 1) return 0;
    vector<long long> rem, d;
    for (int i = 0; i < (int)cs1.size(); i++) {
      rem.push_back(cs1[i].C(n, m));
      d.push_back(M1[i]);
    }
    for (int i = 0; i < (int)cs2.size(); i++) {
      rem.push_back(cs2[i].C(n, m));
      d.push_back(M2[i]);
    }
    return atcoder::crt(rem, d).first;
  }
};

#undef PRIME_POWER_BINOMIAL_M_MAX
#undef PRIME_POWER_BINOMIAL_N_MAX
