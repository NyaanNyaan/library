#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/fast-multieval.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../matrix/matrix.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../modulo/multipoint-binomial-sum.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vpi = vector<pair<int, int>>;

Binomial<mint> C(1101010);

// naive O(N^2)

mint presum(int n, int m) {
  assert(n >= m);
  mint res = 1;
  rep1(i, m) res += C.C(n, i);
  return res;
}
vm naive(vpi qs) {
  vm ans(sz(qs));
  rep(i, sz(qs)) ans[i] = presum(qs[i].first, qs[i].second);
  return ans;
}

// multipoint_binomial_sum O(N ^ 1.5)

vector<mint> solve2(vpi qs) {
  using fps = FormalPowerSeries<mint>;
  int Q = qs.size();

  int m_max = 0, B = 2;
  for (auto& p : qs) {
    assert(p.first >= p.second);
    m_max = max<int>(m_max, p.second);
  }
  while (B <= m_max) B *= 2;

  using Mat = Matrix<fps>;
  vector<vector<Mat>> ms(__lg(B));
  ms[0].resize(B, Mat(2));
  for (int m = 0; m < B; m++) {
    ms[0][m][0][0] = fps{m + 1};
    ms[0][m][0][1] = fps{-m, 1};
    ms[0][m][1][1] = fps{-m, 1};
  }
  for (int i = 1; i < (int)ms.size(); i++) {
    for (int j = 0; j < (int)ms[i - 1].size(); j += 2) {
      ms[i].push_back(ms[i - 1][j + 1] * ms[i - 1][j]);
    }
  }

  vector<pair<mint, mint>> v(Q, make_pair(mint(1), mint(1)));
  for (int l = __lg(B) - 1; l >= 0; l--) {
    vector<vector<mint>> xs(ms[l].size());
    for (int i = 0; i < Q; i++) {
      if ((qs[i].second >> l) & 1) {
        int m = (qs[i].second >> l) - 1;
        xs[m].push_back(qs[i].first);
      }
    }
    vector<vector<Matrix<mint>>> ys(ms[l].size());
    for (int i = 0; i < (int)ms[l].size(); i++) {
      if (!xs[i].empty()) {
        ys[i].resize(xs[i].size(), Matrix<mint>(2));
        for (int u = 0; u < 2; u++) {
          for (int w = 0; w < 2; w++) {
            vector<mint> y;
            if (u == 0 and w == 0) {
              assert(ms[l][i][u][w].size() == 1);
              y.resize(xs[i].size(), ms[l][i][u][w][0]);
            } else if (u == 1 and w == 0) {
              assert(ms[l][i][u][w].size() == 0);
              y.resize(xs[i].size(), 0);
            } else {
              y = FastMultiEval(ms[l][i][u][w], xs[i]);
            }
            for (int j = 0; j < (int)xs[i].size(); j++) ys[i][j][u][w] = y[j];
          }
        }
      }
    }

    vector<int> is(ms[l].size());
    for (int i = 0; i < Q; i++) {
      if ((qs[i].second >> l) & 1) {
        int m = (qs[i].second >> l) - 1;
        auto& mt = ys[m][is[m]];
        mint nf = v[i].first * mt[0][0] + v[i].second * mt[0][1];
        mint ns = v[i].first * mt[1][0] + v[i].second * mt[1][1];
        v[i] = make_pair(nf, ns);
        is[m]++;
      }
    }
  }

  vector<mint> ans(Q);
  for (int i = 0; i < Q; i++) ans[i] = v[i].first * C.finv(qs[i].second);
  return ans;
}

void verify(int Q, int N) {
  trc(Q, N);
  vpi q;
  rep(i, Q) {
    int u, v;
    do {
      u = randint(0, N + 1);
      v = randint(0, N + 1);
    } while (u < v);
    q.emplace_back(u, v);
  }
  assert(multipoint_binomial_sum<mint>(q) == naive(q));
  assert(multipoint_binomial_sum<mint>(q) == solve2(q));
}

void calc_time(int Q, int N) {
  trc(Q, N);
  vpi q;
  rep(i, Q) {
    int u, v;
    do {
      u = randint(0, N + 1);
      v = randint(0, N + 1);
    } while (u < v);
    q.emplace_back(u, v);
  }
  Timer timer;

  timer.reset();
  auto m = multipoint_binomial_sum<mint>(q);
  out(Q, "Mo", timer.elapsed());

  timer.reset();
  auto f = solve2(q);
  out(Q, "ME", timer.elapsed());

  assert(m == f);

  cout.flush();
}

void Nyaan::solve() {
  /*
  {
    vpi qs;
    rep(i, 4) rep(j, i + 1) qs.emplace_back(i, j);
    auto ans = solve2(qs);
    for (int i = 0; i < sz(qs); i++) out(qs[i], ans[i]);
  }
  */
  rep(i, 65) rep(j, 65) verify(i, j);
  // rep(i, 19) { calc_time(1 << i, 1 << i); }

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}