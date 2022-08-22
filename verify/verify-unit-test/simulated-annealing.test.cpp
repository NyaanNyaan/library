#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../marathon/simulated-annealing.hpp"
#include "../../misc/rng.hpp"

using namespace Nyaan;

using score_t = double;
struct Input {
  int N;
  V<P<double, double>> ps;
  Input() = default;
  void scan() {
    in(N);
    ps.resize(N);
    in(ps);
  }
};

struct State {
  int N;
  V<P<double, double>> ps;
  vi used;
  P<double, double> res;

  struct Diff {
    const State *st;
    int n;
    P<double, double> res;
    double d;
    Diff() = default;
    Diff(const State &state) : st(&state), res(state.res) {
      n = rng() % state.N;
      if (state.used[n]) {
        res -= state.ps[n];
      } else {
        res += state.ps[n];
      }
      d = res.first * res.first + res.second * res.second - state.score();
    }
    double diff() const { return d; }
  };

  State() = default;
  State(const Input &input) : N(input.N), ps(input.ps) {
    used.resize(N);
    rep(i, N) used[i] = rng() & 1;
    res = P<double, double>(0, 0);
    rep(i, N) {
      if (used[i]) res += ps[i];
    }
  }
  void update(const Diff &b) {
    res = b.res;
    used[b.n] ^= 1;
  }
  void undo(const Diff &) {}
  score_t score() const {
    return res.first * res.first + res.second * res.second;
  }

  bool operator>(const State &s) { return score() > s.score(); };
  void dump() {}
};
using SA = Simulated_Annealing<Input, State, typename State::Diff>;

using pd = Nyaan::P<double, double>;

double yakinamashi(int n, V<pd> ps) {
  Input ip;
  ip.N = n;
  ip.ps = ps;
  SA sa(10, 1000, 1);
  State ans{};
  rep(i, 10) {
    sa.reset();
    auto s = sa.run(ip);
    if (s > ans) swap(ans, s);
  }
  return sqrt(ans.score());
}

double argsort(int N, V<pd> v) {
  repr(i, N) {
    if (v[i] == pd(0, 0)) v.erase(v.begin() + i);
  }
  N = sz(v);
  sort(all(v), [](pd a, pd b) {
    return atan2(double(a.second), double(a.first)) <
           atan2(double(b.second), double(b.first));
  });
  double ans = 0;
  rep(i, N) rep(j, N) {
    double cx = 0, cy = 0;
    for (int ii = i;; ii = (ii + 1) % N) {
      cx += v[ii].first, cy += v[ii].second;
      if (ii == j) break;
    }
    amax(ans, sqrt(cx * cx + cy * cy));
  }
  return ans;
}

void Nyaan::solve() {
  rep(i, 20) {
    int n = 100;
    V<pd> v(n);
    rep(j, n) v[j] = pd(randint(0, 2 * TEN(6) + 1) + TEN(6),
                        randint(0, 2 * TEN(6) + 1) + TEN(6));
    auto ans1 = argsort(n, v);
    auto ans2 = yakinamashi(n, v);
    cerr << abs(ans1 - ans2) << endl;
  }

  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
