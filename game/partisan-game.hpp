#pragma once

#include <map>
#include <vector>
using namespace std;

#include "surreal-number.hpp"

// F : pair(vector<Game>, vector<Game>) を返す関数
template <typename Game, typename F>
struct PartisanGameSolver {
  using Games = vector<Game>;
  using S = SurrealNumber;

  map<Game, S> mp;
  F f;

  PartisanGameSolver(const F& _f) : f(_f) {}

  S zero() const { return S{0}; }

  S get(Game g) {
    if (mp.count(g)) return mp[g];
    return mp[g] = _get(g);
  }

 private:
  S _get(Game g) {
    Games gl, gr;
    tie(gl, gr) = f(g);
    if (gl.empty() and gr.empty()) return 0;
    vector<S> l, r;
    for (auto& cg : gl) l.push_back(get(cg));
    for (auto& cg : gr) r.push_back(get(cg));
    S sl, sr;
    if (!l.empty()) sl = *max_element(begin(l), end(l));
    if (!r.empty()) sr = *min_element(begin(r), end(r));
    if (r.empty()) return sl.larger();
    if (l.empty()) return sr.smaller();
    assert(sl < sr);
    return reduce(sl, sr);
  }
};

/**
 * @brief 非不偏ゲーム
 */
