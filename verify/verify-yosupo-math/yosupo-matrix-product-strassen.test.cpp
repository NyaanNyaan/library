#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../modulo/strassen.hpp"

void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using Mat = vector<vector<mint>>;
  int N, M, K;
  rd(N, M, K);
  Mat a(N, vector<mint>(M)), b(M, vector<mint>(K));

  uint32_t x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      rd(x);
      a[i][j] = x;
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      rd(x);
      b[i][j] = x;
    }
  }

  auto c = FastMatProd::strassen(a, b);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      wt(c[i][j].get());
      wt(" \n"[j == K - 1]);
    }
  }
}
