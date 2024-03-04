#pragma once

#include <cassert>
#include <functional>
using namespace std;

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"
#include "fps-composition.hpp"

// f を入力として, f(g(x)) = x を満たす g(x) mod x^{deg} を返す
template <typename fps>
fps compositional_inverse(fps f, int deg = -1) {
  using mint = typename fps::value_type;
  if (deg == -1) deg = f.size();
  assert((int)f.size() >= 2 && f[0] == 0 && f[1] != 0);
  fps g{0, f[1].inverse()};
  Binomial<mint> binom;
  for (int d = 2; d < deg; d *= 2) {
    fps f2{begin(f), begin(f) + min(2 * d + 1, (int)f.size())};
    fps fg = Composition<mint>(g, f2, binom, 2 * d + 1);
    fps fdg = (fg.diff() * g.diff().inv(2 * d)).pre(2 * d);
    assert(fdg[0] != 0);
    g = (g - (fg - fps{0, 1}) * fdg.inv(2 * d)).pre(2 * d);
  }
  return {begin(g), begin(g) + deg};
}

// f(g(x)) = x を満たす g(x) mod x^{deg} を返す
// calc_f(g, d) は f(g(x)) mod x^d を計算する関数
template <typename fps>
fps compositional_inverse(function<fps(fps, int)> calc_f, int deg) {
  if (deg <= 2) {
    fps g = calc_f(fps{0, 1}, 2);
    assert(g[0] == 0 && g[1] != 0);
    g[1] = g[1].inverse();
    return g.pre(deg);
  }
  fps g = compositional_inverse(calc_f, (deg + 1) / 2);
  fps fg = calc_f(g, deg + 1);
  fps fdg = (fg.diff() * g.diff().inv(deg)).pre(deg);
  return (g - (fg - fps{0, 1}) * fdg.inv()).pre(deg);
}

/*
 *  @brief 逆関数
 */
