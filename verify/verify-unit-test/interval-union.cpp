#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../misc/interval-union.hpp"
#include "../../misc/rng.hpp"

using namespace Nyaan;

void test(int N) {
  vector<int> a(N + 1);
  int t = randint(0, N / 2);
  t = min<int>(t, randint(0, N / 2));
  vector<pair<int, int>> buf;
  while (t--) {
    int l, r;
    do {
      l = randint(0, N);
      r = randint(0, N + 1);
    } while (l > r or abs(l - r) > 10);
    buf.emplace_back(l, r);
    reg(i, l, r) a[i] = 1;
  }
  auto res = interval_union(buf);
  rep(i, sz(res) - 1) assert(res[i].second < res[i + 1].first);
  each(p, res) {
    reg(i, p.first, p.second) {
      assert(a[i] == 1);
      a[i] = 0;
    }
  }
  assert(accumulate(all(a), 0) == 0);
}

void Nyaan::solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
  rep(i, 100000) test(10);
  rep(i, 10000) test(100);
  rep(i, 1000) test(1000);
}
