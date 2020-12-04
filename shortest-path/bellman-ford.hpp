#pragma once



#include "../graph/graph-template.hpp"

// bellman-ford法
// goalが存在しないとき-> 負閉路が存在するときは空列を返す
// goalが存在するとき  -> startとgoalの間に負閉路が存在する時に負閉路を返す
template <typename T>
vector<T> bellman_ford(int N, Edges<T> &es, int start = 0, int goal = -1) {
  T INF = numeric_limits<T>::max() / 2;
  vector<T> d(N, INF);
  d[start] = 0;
  for (int i = 0; i < N; i++) {
    bool update = false;
    for (auto &e : es) {
      if (d[e.src] == INF) continue;
      if (d[e.to] > d[e.src] + e.cost) {
        update = true, d[e.to] = d[e.src] + e.cost;
      }
    }
    if (!update) return d;
  }

  if (goal == -1) return vector<T>();
  vector<bool> negative(N, false);
  for (int i = 0; i < N; i++) {
    for (auto &e : es) {
      if (d[e.src] == INF) continue;
      if (d[e.to] > d[e.src] + e.cost)
        negative[e.to] = true, d[e.to] = d[e.src] + e.cost;
      if (negative[e.src] == true) negative[e.to] = true;
    }
  }

  if (negative[goal] == true)
    return vector<T>();
  else
    return d;
}