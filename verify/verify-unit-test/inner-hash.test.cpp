#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../inner/inner-hash.hpp"
using namespace Nyaan;

using Hash = inner::Hash<3>;

void Nyaan::solve() {
  u64 mod = (1uLL << 61) - 1;

  Hash a;
  a[0] = 3, a[1] = 4, a[2] = 5;
  trc(a);
  Hash b = Hash::set(2);
  trc(b);

  auto c = a + b;
  trc(c);
  assert(c[0] == 5 and c[1] == 6 and c[2] == 7);
  auto d = a + 2;
  trc(d);
  assert(c == d);

  auto e = a - b;
  trc(e);
  assert(e[0] == 1 and e[1] == 2 and e[2] == 3);
  auto f = a - 2;
  trc(f);
  assert(e == f);

  auto g = a * b;
  trc(g);
  assert(g[0] == 6 and g[1] == 8 and g[2] == 10);
  auto h = a * 2;
  trc(h);
  assert(g == h);

  auto i = -a;
  trc(i);
  assert(i[0] == mod - 3);
  auto j = a + i;
  trc(j);
  assert(j == Hash::set(0));

  auto k = pfma(a, b, b);
  trc(k);
  auto l = pfma(a, b, 2);
  trc(l);
  auto m = a * b + b;
  trc(m);
  assert(k[0] == 8 and k[1] == 10 and k[2] == 12);
  assert(k == l and l == m);

  int A, B;
  cin >> A >> B;
  cout << A + B << endl;
}
