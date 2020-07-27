#pragma once
#ifndef Nyaan_template
#include "../competitive-template.hpp"
#endif

struct DynamicUnionFind {
  unordered_map<int, int> m;
  DynamicUnionFind() {}

  int data(int k) {
    auto itk = m.find(k);
    return itk == m.end() ? m[k] = -1 : itk->second;
  }
  int find(int k) {
    int datk = data(k);
    return datk < 0 ? k : m[k] = find(datk);
  }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    auto itx = m.find(x), ity = m.find(y);
    if (itx->second > ity->second) {
      ity->second += itx->second;
      itx->second = y;
    } else {
      itx->second += ity->second;
      ity->second = x;
    }
    return true;
  }

  int size(int k) { return -data(find(k)); }

  int same(int x, int y) { return find(x) == find(y); }
};