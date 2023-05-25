#define PROBLEM "https://yukicoder.me/problems/no/2"
//
#include "../../template/template.hpp"
//
#include "../../game/impartial-game.hpp"
#include "../../prime/fast-factorize.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  auto fs = factorize(N);
  fs = mkuni(fs);
  auto func = [&](ll n) {
    vl res;
    each(f, fs) {
      ll x = n;
      while (x % f == 0) res.push_back(x /= f);
    }
    return res;
  };
  ImpartialGameSolver<ll> game(func);
  out(game.get(N) ? "Alice" : "Bob");
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
