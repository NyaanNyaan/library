#pragma once

#include <random>
#include <vector>
using namespace std;

#include "formal-power-series.hpp"
#include "mod-pow.hpp"
#include "polynomial-gcd.hpp"

template <typename mint>
vector<mint> root_finding(const FormalPowerSeries<mint>& f) {
  using fps = FormalPowerSeries<mint>;
  long long p = mint::get_mod();
  vector<mint> ans;
  if (p == 2) {
    for (int i = 0; i < 2; i++) {
      if (f.eval(i) == 0) ans.push_back(i);
    }
    return ans;
  }
  vector<fps> fs;
  fs.push_back(PolyGCD(mod_pow(p, fps{0, 1}, f) - fps{0, 1}, f));
  mt19937_64 rng(58);
  while (!fs.empty()) {
    auto g = fs.back();
    fs.pop_back();
    if (g.size() == 2) ans.push_back(-g[0]);
    if (g.size() <= 2) continue;
    fps s = fps{(long long)(rng() % p), 1};
    fps t = PolyGCD(mod_pow((p - 1) / 2, s, g) - fps{1}, g);
    fs.push_back(t);
    if (g.size() != t.size()) fs.push_back(g / t);
  }
  return ans;
}
