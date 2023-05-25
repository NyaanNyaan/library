#define PROBLEM "https://yukicoder.me/problems/no/361"
//
#include "../../template/template.hpp"
//
#include "../../game/impartial-game.hpp"
using namespace Nyaan;

void q() {
  ini(L, D);
  auto f = [&](int x) -> vvi {
    vvi res;
    for (int a = 1; a <= x; a++) {
      int bs = a + 1;
      int be = x - a;
      for (int b = bs; b <= be; b++) {
        int c = x - a - b;
        if (b < c and c <= a + D) {
          res.push_back(vi{a, b, c});
        }
      }
    }
    return res;
  };
  ImpartialGameSolver<int, void, true> game(f);
  out(game.get(L) ? "kado" : "matsu");
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
