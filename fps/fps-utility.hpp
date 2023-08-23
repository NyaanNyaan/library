#pragma once
#include "../modulo/binomial.hpp"
#include "./formal-power-series.hpp"

template <typename fps>
fps Pi(vector<fps> v) {
  if ((int)v.size() == 0) return fps{1};
  while ((int)v.size() >= 2) {
    vector<fps> nx;
    for (int i = 0; i + 1 < (int)v.size(); i += 2)
      nx.push_back(v[i] * v[i + 1]);
    if (v.size() % 2) nx.push_back(v.back());
    v = nx;
  }
  return v.back();
}
