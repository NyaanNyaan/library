#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/van-emde-boas-tree.hpp"
#include "../../misc/fastio.hpp"

van_Emde_Boas_tree vEB;

void Nyaan::solve() {
  unsigned int N, Q;
  rd(N, Q);

  skip_space();
  for (unsigned int i = 0; i < N; i++) {
    char c;
    rd(c);
    if (c == '1') vEB.insert(i);
  }

  while (Q--) {
    unsigned int c, k;
    rd(c, k);
    if (c == 0) {
      vEB.insert(k);
    } else if (c == 1) {
      vEB.erase(k);
    } else if (c == 2) {
      wtn(vEB.contain(k));
    } else if (c == 3) {
      wtn(vEB.find_next(k));
    } else if (c == 4) {
      wtn(vEB.find_prev(k + 1));
    }
  }
}