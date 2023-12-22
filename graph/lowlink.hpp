#pragma once

#include <vector>
using namespace std;

#include "./graph-template.hpp"

// bridge ... 橋 (辺 (u, v) が u < v となるように格納)
// articulation point ... 関節点
template <typename G>
struct LowLink {
  const G &g;
  int N;
  vector<int> ord, low, articulation;
  vector<pair<int, int> > bridge;

  LowLink(const G &_g) : g(_g), N(g.size()), ord(N, -1), low(N, -1) {
    for (int i = 0, k = 0; i < N; i++) {
      if (ord[i] == -1) {
        k = dfs(i, k, -1);
      }
    }
  }

  int dfs(int idx, int k, int par) {
    low[idx] = (ord[idx] = k++);
    int cnt = 0;
    bool arti = false, second = false;
    for (auto &to : g[idx]) {
      if (ord[to] == -1) {
        cnt++;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        arti |= (par != -1) && (low[to] >= ord[idx]);
        if (ord[idx] < low[to]) {
          bridge.emplace_back(minmax(idx, (int)to));
        }
      } else if (to != par || second) {
        low[idx] = min(low[idx], ord[to]);
      } else {
        second = true;
      }
    }
    arti |= par == -1 && cnt > 1;
    if (arti) articulation.push_back(idx);
    return k;
  }
};
