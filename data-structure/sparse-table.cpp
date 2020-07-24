#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

template <typename T>
struct SparseTable {
  vector<vector<T> > table;
  vector<int> log_table;

  inline T f(T a, T b) { return min(a, b); }

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for (int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // [l, r)
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return f(table[b][l], table[b][r - (1 << b)]);
  }
};