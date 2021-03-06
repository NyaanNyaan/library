#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/w-ary-tree.hpp"
#include "../../misc/fastio.hpp"

w_ary_tree<> st;

void Nyaan::solve() {
  unsigned int N, Q;
  rd(N, Q);

  skip_space();
  for (unsigned int i = 0; i < N; i++) {
    char c;
    rd(c);
    if (c == '1') st.insert(i);
  }

  while (Q--) {
    unsigned int c, k;
    rd(c, k);
    if (c == 0) {
      st.insert(k);
    } else if (c == 1) {
      st.erase(k);
    } else if (c == 2) {
      wtn(st.contain(k));
    } else if (c == 3) {
      wtn(st.find_next(k));
    } else if (c == 4) {
      wtn(st.find_prev(k + 1));
    }
  }
}
