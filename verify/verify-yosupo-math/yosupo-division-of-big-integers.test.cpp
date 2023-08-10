#define PROBLEM "https://judge.yosupo.jp/problem/division_of_big_integers"
//
#include "../../template/template.hpp"
//
#include "../../math/bigint.hpp"

using namespace Nyaan;

char buf1[2000000 + 100];
char buf2[2000000 + 100];

void q() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    scanf("%s %s\n", buf1, buf2);
    bigint a = string{buf1};
    bigint b = string{buf2};
    auto [q, r] = divmod(a, b);
    printf("%s %s\n", q.to_string().c_str(), r.to_string().c_str());
    // -a % b
    auto [q2, r2] = divmod(-a, b);
    assert(q == -q2 && r == -r2);
    // a % -b
    auto [q3, r3] = divmod(a, -b);
    assert(q == -q3 && r == r3);
    // -a % -b
    auto [q4, r4] = divmod(-a, -b);
    assert(q == q4 && r == -r4);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}