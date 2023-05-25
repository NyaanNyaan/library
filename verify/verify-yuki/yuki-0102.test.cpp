#define PROBLEM "https://yukicoder.me/problems/no/102"
//
#include "../../template/template.hpp"
//
#include "../../game/impartial-game.hpp"
using namespace Nyaan;

void q() {
  vi A(4);
  in(A);
  ImpartialGameSolver<int, void, true> game;
  using T = typename decltype(game)::States;
  auto f = [&](int x) -> T {
    T res;
    rep1(i, 3) {
      if (x < i) break;
      res.push_back(vi{int(x - i)});
    }
    return res;
  };
  game.set_func(f);
  out(game.get(A) ? "Taro" : "Jiro");
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}