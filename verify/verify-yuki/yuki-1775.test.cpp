#define PROBLEM "https://yukicoder.me/problems/no/1775"

#include "../../template/template.hpp"
//
#include "../../math/nimber.hpp"
#include "../../misc/rng.hpp"

using namespace Nyaan;

Nimber64 dp[2][2][128][128];
Nimber64 nx[2][2][128][128];
Nimber64 w[128][128];

void Nyaan::solve() {
  i64 N, M, X, Y, Z, u, v;
  cin >> N >> M >> X >> Y >> Z;
  --X, --Y, --Z;
  rep(i, N) rep(j, i) {
    u64 x = u64(rng()) % u64(-1) + 1;
    w[i][j] = w[j][i] = x;
  }
  rep(i, M) {
    cin >> u >> v;
    --u, --v;
    w[u][v] = w[v][u] = 0;
  }
  // y 訪問済み / z 訪問済み / 今のマス / 前のマス
  dp[0][0][X][X] = 1;
  rep1(L, N) {
    memset(nx, 0, sizeof(nx));
    rep(ky, 2) rep(kz, 2) rep(c, N) rep(d, N) {
      if (w[c][d] == 0) continue;
      if (ky == 1 and d == Y) continue;
      if (kz == 1 and d == Z) continue;
      int nky = ky | (d == Y), nkz = kz | (d == Z);
      rep(p, N) if (p != d) nx[nky][nkz][d][c] += dp[ky][kz][c][p];
    }
    rep(ky, 2) rep(kz, 2) rep(i, N) rep(j, N) {
      if (w[i][j] != 0) nx[ky][kz][i][j] *= w[i][j];
    }
    swap(dp, nx);
    rep(i, N) if (dp[1][1][X][i] != 0) die(L);
  }
  die(-1);
}
