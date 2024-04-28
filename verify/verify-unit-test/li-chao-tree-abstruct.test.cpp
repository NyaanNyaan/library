#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/li-chao-tree-abstruct.hpp"
//
#include "../../misc/rng.hpp"
using namespace Nyaan;

struct Line {
  ll a, b;
  ll operator()(ll x) { return a * x + b; };
};

template <bool MINIMIZE>
void test() {
  int N = rng(1, 100);
  int M = TEN(9);
  ll INF = MINIMIZE ? infLL : -infLL;
  vl xs = randset(0, M, N);
  sort(begin(xs), end(xs));
  xs.push_back(inf);
  Line I{0, INF};
  LiChaoTree<Line, MINIMIZE, true> lct(xs, I);

  vl ys(N, INF);
  rep(i, N) assert(lct.get_val(xs[i]).fi == ys[i]);
  rep(t, 100) {
    {
      ll l = rng(0, M);
      ll r = rng(0, M);
      if (l > r) swap(l, r);
      ll a = rng(-M, M);
      ll b = rng(-M, M);
      Line line{a, b};
      lct.add_segment(l, r, line);
      rep(i, N) {
        if (l <= xs[i] and xs[i] < r) {
          if (MINIMIZE == 1) amin(ys[i], line(xs[i]));
          if (MINIMIZE == 0) amax(ys[i], line(xs[i]));
        }
      }
    }
    {
      int j = rng(0, N - 1);
      assert(lct.get_val(xs[j]).fi == ys[j]);
    }
    {
      int l = rng(0, N - 1);
      int r = rng(0, N - 1);
      if (l > r) swap(l, r);
      r++;
      auto [x, y] = lct.get(xs[l], xs[r]);
      if (MINIMIZE) {
        assert(*min_element(begin(ys) + l, begin(ys) + r) == y);
      }
      if (!MINIMIZE) {
        assert(*max_element(begin(ys) + l, begin(ys) + r) == y);
      }
    }
  }
}

void q() {
  rep(t, 10000) {
    test<1>();
    test<0>();
  }
  trc2("OK");

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
