#pragma once

#include <vector>
using namespace std;

struct UnionFindEnumerate {
  vector<int> data, nxt;
  UnionFindEnumerate(int N) : data(N, -1), nxt(N) {
    for (int i = 0; i < N; i++) nxt[i] = i;
  }

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    swap(nxt[x], nxt[y]);
    return true;
  }

  // f(x, y) : x に y をマージ
  template <typename F>
  int unite(int x, int y, const F &f) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    f(x, y);
    swap(nxt[x], nxt[y]);
    return true;
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }

  vector<int> enumerate(int i) {
    vector<int> res{i};
    for (int j = nxt[i]; j != i; j = nxt[j]) res.push_back(j);
    return res;
  }
};
