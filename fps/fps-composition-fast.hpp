#pragma once
#include "../fps/formal-power-series.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../modulo/strassen.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

// Q(P(x))
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) fps Composition(
    fps P, fps Q, int deg = -1) {
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};
  P.resize(N);

  int K = max<int>(ceil(sqrt(N)), 2);
  assert(N <= K * K);

  vector<fps> PS(K + 1);
  {
    // step 1
    PS[0].resize(N, mint());
    PS[0][0] = 1;
    PS[1] = P;
    fps::set_fft();
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i <= K; i++) PS[i] = (PS[i - 1] * P).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Pomega = P;
      Pomega.resize(len);
      Pomega.ntt();
      for (int i = 2; i <= K; i++) {
        PS[i].resize(len);
        for (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];
        PS[i].ntt();
        for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];
        PS[i].intt();
        PS[i].resize(N);
        PS[i].shrink_to_fit();
      }
    }
  }

  vector<fps> TS(K);
  {
    // step 2
    TS[0].resize(N, mint());
    TS[0][0] = 1;
    TS[1] = PS[K];
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Tomega = TS[1];
      Tomega.resize(len);
      Tomega.ntt();
      for (int i = 2; i < K; i++) {
        TS[i].resize(len);
        for (int j = 0; j < N; j++) TS[i][j] = TS[i - 1][j];
        TS[i].ntt();
        for (int j = 0; j < len; j++) TS[i][j] *= Tomega[j];
        TS[i].intt();
        TS[i].resize(N);
        TS[i].shrink_to_fit();
      }
    }
  }

  // step 3
  vector<fps> QP;
  {
    PS.pop_back();
    vector<fps> QS(K, fps(K, mint()));
    for (int i = 0; i < K; i++)
      for (int j = 0; j < K; j++) {
        QS[i][j] = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();
      }
    QP = FastMatProd::strassen(QS, PS);
  }

  fps ans(N, mint());
  {
    // step 4,5
    for (int i = 0; i < K; i++) ans += (QP[i] * TS[i]).pre(N);
  }
  return ans;
}

/**
 * @brief 関数の合成( $\mathrm{O}(N^2)$ )
 */
