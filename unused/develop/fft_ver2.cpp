#pragma once

#include "template/template.hpp"
//

namespace ArbitraryModConvolution2 {
#pragma GCC target("avx2,fma")

constexpr int max_fft_size = 1 << 20;
const long double PI = acosl(-1);

__attribute__((aligned(32))) double alr[max_fft_size + 4];
__attribute__((aligned(32))) double ali[max_fft_size + 4];
__attribute__((aligned(32))) double ahr[max_fft_size + 4];
__attribute__((aligned(32))) double ahi[max_fft_size + 4];
__attribute__((aligned(32))) double blr[max_fft_size + 4];
__attribute__((aligned(32))) double bli[max_fft_size + 4];
__attribute__((aligned(32))) double bhr[max_fft_size + 4];
__attribute__((aligned(32))) double bhi[max_fft_size + 4];

__attribute__((aligned(32))) double wr[max_fft_size >> 1];
__attribute__((aligned(32))) double wi[max_fft_size >> 1];

complex<long double> base[__lg(max_fft_size)];

using m256 = __m256d;

inline void mmul(m256& xr, m256& xi, const m256& yr, const m256& yi) {
  m256 tmp1 = _mm256_mul_pd(xi, yi);
  m256 tmp2 = _mm256_mul_pd(xr, yi);
  m256 nxr = _mm256_fmsub_pd(xr, yr, tmp1);
  m256 nxi = _mm256_fmadd_pd(yr, xi, tmp2);
  xr = nxr;
  xi = nxi;
}

inline void mul(double& xr, double& xi, double yr, double yi) {
  double tmp = xr * yr - xi * yi;
  xi = xr * yi + yr * xi;
  xr = tmp;
}

void genw(int i, int b, complex<long double> z) {
  if (b == -1) {
    wr[i] = z.real(), wi[i] = z.imag();
  } else {
    genw(i, b - 1, z);
    genw(i | (1 << b), b - 1, z * base[b]);
  }
}

void Setw(int k) {
  --k;
  assert(1 << (k - 1) <= (max_fft_size >> 1));
  const long double arg = PI / (1 << k);
  for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {
    base[i] = exp(complex<long double>(1i) * (arg * j));
  }
  genw(0, k - 1, 1);
}

/*
void block_fft(double* ar, double* ai, int l, int v) {
  int lgv = __lg(v);
  int u = 1;

  while (v) {
    for (int jh = 0; jh < u; ++jh) {
      int j0 = l + jh * v * 4;
      int j1 = j0 + v;
      int j2 = j1 + v;
      int j3 = j2 + v;
      int je = j1;
      int wid = j0 >> (lgv + 2);
      int xid = j0 >> (lgv + 1);
      double Wr = wr[wid], Wi = wi[wid];
      double Xr = wr[xid], Xi = wi[xid];
      double WXr = Wr, WXi = Wi;
      mul(WXr, WXi, Xr, Xi);
      for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
        double t0r = ar[j0], t0i = ai[j0];
        double t1r = ar[j1], t1i = ai[j1];
        double t2r = ar[j2], t2i = ai[j2];
        double t3r = ar[j3], t3i = ai[j3];
        mul(t1r, t1i, Xr, Xi);
        mul(t2r, t2i, Wr, Wi);
        mul(t3r, t3i, WXr, WXi);
        double t0p2r = t0r + t2r, t0p2i = t0i + t2i;
        double t1p3r = t1r + t3r, t1p3i = t1i + t3i;
        double t0m2r = t0r - t2r, t0m2i = t0i - t2i;
        double t1m3r = t1r - t3r, t1m3i = t1i - t3i;
        mul(t1m3r, t1m3i, wr[1], wi[1]);
        ar[j0] = t0p2r + t1p3r, ai[j0] = t0p2i + t1p3i;
        ar[j1] = t0p2r - t1p3r, ai[j1] = t0p2i - t1p3i;
        ar[j2] = t0m2r + t1m3r, ai[j2] = t0m2i + t1m3i;
        ar[j3] = t0m2r - t1m3r, ai[j3] = t0m2i - t1m3i;
      }
    }
    u <<= 2, v >>= 2, lgv -= 2;
  }
}
*/

void fft(double* ar, double* ai, int k) {
  if (k == 0) return;
  if (k == 1) {
    double ar1 = ar[1], ai1 = ai[1];
    ar[1] = ar[0] - ar1, ai[1] = ai[0] - ai1;
    ar[0] = ar[0] + ar1, ai[0] = ai[0] + ai1;
    return;
  }
  
  for (int i = 0; i < (1 << k); i += 4) {
    _mm_prefetch(ar + i, _MM_HINT_T2);
    _mm_prefetch(ai + i, _MM_HINT_T2);
  }
  
  if (k & 1) {
    int v = 1 << (k - 1);
    for (int j = 0; j < v; ++j) {
      double arjv = ar[j + v], aijv = ai[j + v];
      ar[j + v] = ar[j] - arjv, ai[j + v] = ai[j] - aijv;
      ar[j] = ar[j] + arjv, ai[j] = ai[j] + aijv;
    }
  }
  int u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));
  while (v) {
    {
      int j0 = 0;
      int j1 = v;
      int j2 = j1 + v;
      int j3 = j2 + v;
      int je = j1;
      for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
        double t0r = ar[j0], t0i = ai[j0];
        double t1r = ar[j1], t1i = ai[j1];
        double t2r = ar[j2], t2i = ai[j2];
        double t3r = ar[j3], t3i = ai[j3];
        double t0p2r = t0r + t2r, t0p2i = t0i + t2i;
        double t1p3r = t1r + t3r, t1p3i = t1i + t3i;
        double t0m2r = t0r - t2r, t0m2i = t0i - t2i;
        double t1m3r = t1r - t3r, t1m3i = t1i - t3i;
        mul(t1m3r, t1m3i, wr[1], wi[1]);
        ar[j0] = t0p2r + t1p3r, ai[j0] = t0p2i + t1p3i;
        ar[j1] = t0p2r - t1p3r, ai[j1] = t0p2i - t1p3i;
        ar[j2] = t0m2r + t1m3r, ai[j2] = t0m2i + t1m3i;
        ar[j3] = t0m2r - t1m3r, ai[j3] = t0m2i - t1m3i;
      }
    }

    /**/ if (v < 4) {
      //*/ if (true) {
      for (int jh = 1; jh < u; ++jh) {
        int j0 = jh * v * 4;
        int j1 = j0 + v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = j1;
        double Wr = wr[jh], Wi = wi[jh];
        double Xr = wr[jh << 1], Xi = wi[jh << 1];
        double WXr = Wr, WXi = Wi;
        mul(WXr, WXi, Xr, Xi);
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          double t0r = ar[j0], t0i = ai[j0];
          double t1r = ar[j1], t1i = ai[j1];
          double t2r = ar[j2], t2i = ai[j2];
          double t3r = ar[j3], t3i = ai[j3];
          mul(t1r, t1i, Xr, Xi);
          mul(t2r, t2i, Wr, Wi);
          mul(t3r, t3i, WXr, WXi);
          double t0p2r = t0r + t2r, t0p2i = t0i + t2i;
          double t1p3r = t1r + t3r, t1p3i = t1i + t3i;
          double t0m2r = t0r - t2r, t0m2i = t0i - t2i;
          double t1m3r = t1r - t3r, t1m3i = t1i - t3i;
          mul(t1m3r, t1m3i, wr[1], wi[1]);
          ar[j0] = t0p2r + t1p3r, ai[j0] = t0p2i + t1p3i;
          ar[j1] = t0p2r - t1p3r, ai[j1] = t0p2i - t1p3i;
          ar[j2] = t0m2r + t1m3r, ai[j2] = t0m2i + t1m3i;
          ar[j3] = t0m2r - t1m3r, ai[j3] = t0m2i - t1m3i;
        }
      }
    }
    /**/
    else {
      for (int jh = 1; jh < u; ++jh) {
        int j0 = jh * v * 4;
        int je = j0 + v;
        double Wr = wr[jh], Wi = wi[jh];
        double Xr = wr[jh << 1], Xi = wi[jh << 1];
        double WXr = Wr, WXi = Wi;
        mul(WXr, WXi, Xr, Xi);
        m256 mwr = _mm256_set1_pd(Wr);
        m256 mwi = _mm256_set1_pd(Wi);
        m256 mxr = _mm256_set1_pd(Xr);
        m256 mxi = _mm256_set1_pd(Xi);
        m256 mwxr = _mm256_set1_pd(WXr);
        m256 mwxi = _mm256_set1_pd(WXi);
        for (; j0 < je; j0 += 4) {
          _mm_prefetch(ar + j0 + 4 + v * 0, _MM_HINT_T1);
          _mm_prefetch(ar + j0 + 4 + v * 1, _MM_HINT_T1);
          m256 mt0r = _mm256_load_pd(ar + j0 + v * 0);
          m256 mt0i = _mm256_load_pd(ai + j0 + v * 0);
          m256 mt1r = _mm256_load_pd(ar + j0 + v * 1);
          m256 mt1i = _mm256_load_pd(ai + j0 + v * 1);
          m256 mt2r = _mm256_load_pd(ar + j0 + v * 2);
          m256 mt2i = _mm256_load_pd(ai + j0 + v * 2);
          m256 mt3r = _mm256_load_pd(ar + j0 + v * 3);
          m256 mt3i = _mm256_load_pd(ai + j0 + v * 3);
          _mm_prefetch(ar + j0 + 4 + v * 2, _MM_HINT_T1);
          _mm_prefetch(ar + j0 + 4 + v * 3, _MM_HINT_T1);
          mmul(mt1r, mt1i, mxr, mxi);
          mmul(mt2r, mt2i, mwr, mwi);
          mmul(mt3r, mt3i, mwxr, mwxi);
          m256 mt0p2r = _mm256_add_pd(mt0r, mt2r);
          m256 mt0p2i = _mm256_add_pd(mt0i, mt2i);
          m256 mt1p3r = _mm256_add_pd(mt1r, mt3r);
          m256 mt1p3i = _mm256_add_pd(mt1i, mt3i);
          m256 mt0m2r = _mm256_sub_pd(mt0r, mt2r);
          m256 mt0m2i = _mm256_sub_pd(mt0i, mt2i);
          m256 mt1m3r = _mm256_sub_pd(mt1r, mt3r);
          m256 mt1m3i = _mm256_sub_pd(mt1i, mt3i);
          _mm_prefetch(ai + j0 + 4 + v * 0, _MM_HINT_T1);
          _mm_prefetch(ai + j0 + 4 + v * 1, _MM_HINT_T1);
          m256 mwr1 = _mm256_set1_pd(wr[1]);
          m256 mwi1 = _mm256_set1_pd(wi[1]);
          mmul(mt1m3r, mt1m3i, mwr1, mwi1);
          m256 marj0 = _mm256_add_pd(mt0p2r, mt1p3r);
          m256 maij0 = _mm256_add_pd(mt0p2i, mt1p3i);
          m256 marj1 = _mm256_sub_pd(mt0p2r, mt1p3r);
          m256 maij1 = _mm256_sub_pd(mt0p2i, mt1p3i);
          m256 marj2 = _mm256_add_pd(mt0m2r, mt1m3r);
          m256 maij2 = _mm256_add_pd(mt0m2i, mt1m3i);
          m256 marj3 = _mm256_sub_pd(mt0m2r, mt1m3r);
          m256 maij3 = _mm256_sub_pd(mt0m2i, mt1m3i);
          _mm_prefetch(ai + j0 + 4 + v * 2, _MM_HINT_T1);
          _mm_prefetch(ai + j0 + 4 + v * 3, _MM_HINT_T1);
          _mm256_store_pd(ar + j0 + v * 0, marj0);
          _mm256_store_pd(ai + j0 + v * 0, maij0);
          _mm256_store_pd(ar + j0 + v * 1, marj1);
          _mm256_store_pd(ai + j0 + v * 1, maij1);
          _mm256_store_pd(ar + j0 + v * 2, marj2);
          _mm256_store_pd(ai + j0 + v * 2, maij2);
          _mm256_store_pd(ar + j0 + v * 3, marj3);
          _mm256_store_pd(ai + j0 + v * 3, maij3);
        }
      }
    }
    //*/
    u <<= 2, v >>= 2;
  }

  /*
  if (v) {
    for (int l = 0; l < (1 << k); l += v * 4) block_fft(ar, ai, l, v);
  }
  */
}

void ifft(double* ar, double* ai, int k) {
  if (k == 0) return;
  if (k == 1) {
    double ar1 = ar[1], ai1 = ai[1];
    ar[1] = ar[0] - ar1, ai[1] = ai[0] - ai1;
    ar[0] = ar[0] + ar1, ai[0] = ai[0] + ai1;
    return;
  }
  int u = 1 << (k - 2);
  int v = 1;
  while (u) {
    {
      int j0 = 0;
      int j1 = v;
      int j2 = j1 + v;
      int j3 = j2 + v;
      for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
        double t0r = ar[j0], t0i = ai[j0];
        double t1r = ar[j1], t1i = ai[j1];
        double t2r = ar[j2], t2i = ai[j2];
        double t3r = ar[j3], t3i = ai[j3];
        double t0p1r = t0r + t1r, t0p1i = t0i + t1i;
        double t2p3r = t2r + t3r, t2p3i = t2i + t3i;
        double t0m1r = t0r - t1r, t0m1i = t0i - t1i;
        double t2m3r = t2r - t3r, t2m3i = t2i - t3i;
        mul(t2m3r, t2m3i, wr[1], -wi[1]);
        ar[j0] = t0p1r + t2p3r, ai[j0] = t0p1i + t2p3i;
        ar[j2] = t0p1r - t2p3r, ai[j2] = t0p1i - t2p3i;
        ar[j1] = t0m1r + t2m3r, ai[j1] = t0m1i + t2m3i;
        ar[j3] = t0m1r - t2m3r, ai[j3] = t0m1i - t2m3i;
      }
    }
    // jh >= 1
    for (int jh = 1; jh < u; ++jh) {
      int j0 = jh * v * 4;
      int j1 = j0 + v;
      int j2 = j1 + v;
      int j3 = j2 + v;
      int je = j1;
      double Wr = wr[jh], Wi = -wi[jh];
      double Xr = wr[(jh << 1) + 0], Xi = -wi[(jh << 1) + 0];
      double Yr = wr[(jh << 1) + 1], Yi = -wi[(jh << 1) + 1];
      for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
        double t0r = ar[j0], t0i = ai[j0];
        double t1r = ar[j1], t1i = ai[j1];
        double t2r = ar[j2], t2i = ai[j2];
        double t3r = ar[j3], t3i = ai[j3];
        double t0p1r = t0r + t1r, t0p1i = t0i + t1i;
        double t2p3r = t2r + t3r, t2p3i = t2i + t3i;
        double t0m1r = t0r - t1r, t0m1i = t0i - t1i;
        double t2m3r = t2r - t3r, t2m3i = t2i - t3i;
        mul(t0m1r, t0m1i, Xr, Xi);
        mul(t2m3r, t2m3i, Yr, Yi);
        ar[j0] = t0p1r + t2p3r, ai[j0] = t0p1i + t2p3i;
        ar[j2] = t0p1r - t2p3r, ai[j2] = t0p1i - t2p3i;
        ar[j1] = t0m1r + t2m3r, ai[j1] = t0m1i + t2m3i;
        ar[j3] = t0m1r - t2m3r, ai[j3] = t0m1i - t2m3i;
        mul(ar[j2], ai[j2], Wr, Wi);
        mul(ar[j3], ai[j3], Wr, Wi);
      }
    }
    u >>= 2;
    v <<= 2;
  }
  if (k & 1) {
    u = 1 << (k - 1);
    for (int j = 0; j < u; j++) {
      double arju = ar[j] - ar[j + u];
      double aiju = ai[j] - ai[j + u];
      ar[j] = ar[j] + ar[j + u], ai[j] = ai[j] + ai[j + u];
      ar[j + u] = arju, ai[j + u] = aiju;
    }
  }
}

static void fft_real(double* ALr, double* ALi, double* AHr, double* AHi,
                     int k) {
  fft(ALr, ALi, k);
  AHr[0] = ALi[0] * 2.0, AHi[0] = 0.0;
  ALr[0] = ALr[0] * 2.0, ALi[0] = 0.0;
  AHr[1] = ALi[1] * 2.0, AHi[1] = 0.0;
  ALr[1] = ALr[1] * 2.0, ALi[1] = 0.0;
  for (int i = 2, y = 2; y < (1 << k); y <<= 1) {
    for (; i < 2 * y; i += 2) {
      int j = i ^ (y - 1);
      AHr[i] = ALi[j] + ALi[i], AHi[i] = ALr[j] - ALr[i];
      ALr[i] = ALr[j] + ALr[i], ALi[i] = -ALi[j] + ALi[i];
      AHr[j] = AHr[i], AHi[j] = -AHi[i];
      ALr[j] = ALr[i], ALi[j] = -ALi[i];
    }
  }
}

template <unsigned int MOD>
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
  using u64 = unsigned long long;
  constexpr unsigned int B = 32000;
  static_assert(1uLL * B * B < 1uLL << 32);
  auto round = [](double x) -> u64 { return u64(x + 0.5); };

  int l = a.size() + b.size() - 1;
  int k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  Setw(k);

  memset(alr, 0, sizeof(double) * M);
  memset(ali, 0, sizeof(double) * M);
  memset(blr, 0, sizeof(double) * M);
  memset(bli, 0, sizeof(double) * M);

  for (int i = 0; i < (int)a.size(); i++) {
    alr[i] = double(a[i] % B), ali[i] = double(a[i] / B);
  }
  for (int i = 0; i < (int)b.size(); i++) {
    blr[i] = double(b[i] % B), bli[i] = double(b[i] / B);
  }

  fft_real(alr, ali, ahr, ahi, k);
  fft_real(blr, bli, bhr, bhi, k);

  for (int i = 0; i < M; i++) {
    double tmp1r = alr[i], tmp1i = ali[i];
    double tmp2r = -ahi[i], tmp2i = ahr[i];
    double tmp3r = tmp1r, tmp3i = tmp1i;
    double tmp4r = tmp2r, tmp4i = tmp2i;
    mul(tmp1r, tmp1i, blr[i], bli[i]);
    mul(tmp2r, tmp2i, bhr[i], bhi[i]);
    mul(tmp3r, tmp3i, bhr[i], bhi[i]);
    mul(tmp4r, tmp4i, blr[i], bli[i]);
    blr[i] = tmp1r + tmp2r, bli[i] = tmp1i + tmp2i;
    bhr[i] = tmp3r + tmp4r, bhi[i] = tmp3i + tmp4i;
  }

  ifft(blr, bli, k);
  ifft(bhr, bhi, k);

  vector<int> u(l);
  double im = 1.0 / (4.0 * M);
  for (int i = 0; i < l; i++) {
    blr[i] *= im, bli[i] *= im;
    bhr[i] *= im, bhi[i] *= im;
    int x1 = round(blr[i]) % MOD;
    int x2 = (round(bhr[i]) + round(bhi[i])) % MOD * B % MOD;
    int x3 = round(bli[i]) % MOD * (B * B % MOD) % MOD;
    if ((x1 += x2) >= (int)MOD) x1 -= MOD;
    if ((x1 += x3) >= (int)MOD) x1 -= MOD;
    u[i] = x1;
  }
  return u;
}

}  // namespace ArbitraryModConvolution2

namespace ArbitraryModConvolution2 {

// naive convolution
template <typename T>
static vector<long long> multiply(const vector<T>& s, const vector<T>& t) {
  int l = s.size() + t.size() - 1;
  int k = 2, M = 4;
  while (M < l) M <<= 1, ++k;
  Setw(k);

  memset(alr, 0, sizeof(double) * M);
  memset(ali, 0, sizeof(double) * M);
  for (int i = 0; i < (int)s.size(); i++) alr[i] = s[i];
  for (int i = 0; i < (int)t.size(); i++) ali[i] = t[i];
  fft(alr, ali, k);

  ali[0] = 4.0 * alr[0] * ali[0];
  ali[1] = 4.0 * alr[1] * ali[1];
  alr[0] = alr[1] = 0.0;
  for (int i = 2; i < M; i += 2) {
    int c = 1 << (31 - __builtin_clz(i));
    int j = i ^ (c - 1);
    double tr = alr[i] - alr[j], ti = ali[i] + ali[j];
    alr[i] = alr[i] + alr[j], ali[i] = ali[i] - ali[j];
    mul(alr[i], ali[i], tr, ti);
    alr[j] = -alr[i], ali[j] = ali[i];
  }

  for (int j = 0; j < M / 2; j++) {
    double tmp1r = alr[j * 2 + 0] + alr[j * 2 + 1];
    double tmp1i = ali[j * 2 + 0] + ali[j * 2 + 1];
    double tmp2r = alr[j * 2 + 0] - alr[j * 2 + 1];
    double tmp2i = ali[j * 2 + 0] - ali[j * 2 + 1];
    mul(tmp2r, tmp2i, wr[j], -wi[j]);
    alr[j] = tmp1r - tmp2i, ali[j] = tmp1i + tmp2r;
  }
  ifft(alr, ali, k - 1);

  vector<long long> u(l);
  for (int i = 0; i < l; i++) {
    if (i & 1) {
      u[i] = llround(-alr[i >> 1] / (4.0 * M));
    } else {
      u[i] = llround(ali[i >> 1] / (4.0 * M));
    }
  }
  return u;
}

}  // namespace ArbitraryModConvolution2