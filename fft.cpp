#include "template/template.hpp"
//

#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx2,fma")

namespace ArbitraryModConvolution {

template <typename T>
struct Cp {
  T x, y;
  constexpr Cp() : x(0), y(0) {}
  constexpr Cp(T _x, T _y) : x(_x), y(_y) {}
  constexpr inline Cp operator+(const Cp& c) const {
    return Cp(x + c.x, y + c.y);
  }
  constexpr inline Cp operator-(const Cp& c) const {
    return Cp(x - c.x, y - c.y);
  }
  constexpr inline Cp operator*(const Cp& c) const {
    return Cp(x * c.x - y * c.y, x * c.y + y * c.x);
  }
  constexpr inline Cp operator-() const { return Cp(-x, -y); }
  constexpr inline Cp conj() const { return Cp(x, -y); }
  constexpr inline Cp rotl() const { return Cp(-y, x); }
  friend ostream& operator<<(ostream& os, const Cp& c) {
    os << "(" << c.x << ", " << c.y << ")" << endl;
    return os;
  }
};

using C = Cp<double>;
const long double PI = acosl(-1);

struct CooleyTukey {
  static vector<C> w;
  static vector<Cp<long double>> base;

  static void Setw(int k) {
    --k;
    if ((int)w.size() >= (1 << k)) return;
    w.resize(1 << k);
    base.resize(k);
    const long double arg = PI / (1 << k);
    for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {
      complex<long double> z = exp(complex<long double>(1i) * (arg * j));
      base[i] = Cp<long double>{z.real(), z.imag()};
    }
    genw(0, k - 1, Cp<long double>{1, 0});
  }

  static void genw(int i, int b, Cp<long double> z) {
    if (b == -1) {
      w[i].x = z.x, w[i].y = z.y;
    } else {
      genw(i, b - 1, z);
      genw(i | (1 << b), b - 1, z * base[b]);
    }
  }

  static void fft(vector<C>& a, int k) {
    if (k <= 0) return;
    if (k == 1) {
      C a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        C ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] = a[j] + ajv;
      }
    }
    int u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));
    while (v) {
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = v;
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p2 = t0 + t2, t1p3 = t1 + t3;
          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      // jh >= 1
      for (int jh = 1; jh < u; ++jh) {
        int j0 = jh * v * 4;
        int j1 = j0 + v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = j1;
        C ww = w[jh];
        C xx = w[jh << 1];
        C wx = ww * xx;
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1] * xx, t2 = a[j2] * ww, t3 = a[j3] * wx;
          C t0p2 = t0 + t2, t1p3 = t1 + t3;
          C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      u <<= 2, v >>= 2;
    }
  }

  static void ifft(vector<C>& a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      C a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    while (u) {
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p1 = t0 + t1, t2p3 = t2 + t3;
          C t0m1 = t0 - t1, t2m3 = (t2 - t3) * w[1].conj();
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      // jh >= 1
      for (int jh = 1; jh < u; ++jh) {
        int j0 = (jh * v) << 2;
        int j1 = j0 + v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        int je = j1;
        C ww = w[jh].conj();
        C xx = w[jh << 1].conj();
        C yy = w[(jh << 1) + 1].conj();
        for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
          C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          C t0p1 = t0 + t1, t2p3 = t2 + t3;
          C t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j1] = t0m1 + t2m3, a[j3] = (t0m1 - t2m3) * ww;
        }
      }
      u >>= 2;
      v <<= 2;
    }
    if (k & 1) {
      u = 1 << (k - 1);
      for (int j = 0; j < u; j++) {
        C ajv = a[j] - a[j + u];
        a[j] = a[j] + a[j + u];
        a[j + u] = ajv;
      }
    }
  }

  static void fft_real(vector<C>& AL, vector<C>& AH, int k) {
    fft(AL, k);
    AH[0] = C{AL[0].y * 2.0, 0};
    AL[0] = C{AL[0].x * 2.0, 0};
    AH[1] = C{AL[1].y * 2.0, 0};
    AL[1] = C{AL[1].x * 2.0, 0};
    for (int i = 2, y = 2; y < (1 << k); y <<= 1) {
      for (; i < 2 * y; i += 2) {
        int j = i ^ (y - 1);
        AH[i] = (AL[j].conj() - AL[i]).rotl();
        AL[i] = (AL[j].conj() + AL[i]);
        AH[j] = AH[i].conj();
        AL[j] = AL[i].conj();
      }
    }
  }

  template <unsigned int MOD>
  static vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    using u64 = unsigned long long;
    constexpr unsigned int B = 32000;
    static_assert(1uLL * B * B < 1uLL << 32);
    int l = a.size() + b.size() - 1;
    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    Setw(k);

    vector<C> AL(M), AH(M), BL(M), BH(M);
    for (int i = 0; i < (int)a.size(); i++) {
      AL[i] = C{double(a[i] % B), double(a[i] / B)};
    }
    for (int i = 0; i < (int)b.size(); i++) {
      BL[i] = C{double(b[i] % B), double(b[i] / B)};
    }

    fft_real(AL, AH, k);
    fft_real(BL, BH, k);

    for (int i = 0; i < M; i++) {
      C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();
      BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();
      BL[i] = tmp;
    }

    ifft(BL, k);
    ifft(BH, k);

    vector<int> u(l);
    double im = 1.0 / (4.0 * M);
    for (int i = 0; i < l; i++) {
      BL[i].x *= im, BL[i].y *= im;
      BH[i].x *= im, BH[i].y *= im;
      int x1 = u64(llround(BL[i].x)) % MOD;
      int x2 = u64(llround(BH[i].x) + llround(BH[i].y)) % MOD * B % MOD;
      int x3 = u64(llround(BL[i].y)) % MOD * (B * B % MOD) % MOD;
      if ((x1 += x2) >= (int)MOD) x1 -= MOD;
      if ((x1 += x3) >= (int)MOD) x1 -= MOD;
      u[i] = x1;
    }
    return u;
  }
};
vector<C> CooleyTukey::w;
vector<Cp<long double>> CooleyTukey::base;

}  // namespace ArbitraryModConvolution

#include "fft_verify.cpp"

using namespace Nyaan;
void Nyaan::solve() {
  using namespace ArbitraryModConvolution;
#ifdef NyaanDebug
  verify();
#endif
  calc_time();
  int N, M;
  rd(N, M);
  vector<int> a(N), b(M);
  for (auto& x : a) rd(x);
  for (auto& x : b) rd(x);

  auto c = CooleyTukey::karatsuba<1000000007>(a, b);
  for (int i = 0; i < N + M - 1; i++) {
    wt(c[i], " \n"[i == N + M - 2]);
  }
}
