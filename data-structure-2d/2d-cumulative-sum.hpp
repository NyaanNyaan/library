#pragma once

template <class T>
struct CumulativeSum2D {
  vector<vector<T> > data;

  CumulativeSum2D(int H, int W) : data(H + 3, vector<T>(W + 3, 0)) {}

  void add(int i, int j, T z) {
    ++i, ++j;
    if (i >= (int)data.size() || j >= (int)data[0].size()) return;
    data[i][j] += z;
  }

  // 半開
  void imos(int i1, int j1, int i2, int j2, T z = 1) {
    add(i1, j1, z);
    add(i1, j2, -z);
    add(i2, j1, -z);
    add(i2, j2, z);
  }

  void build() {
    for (int i = 1; i < (int)data.size(); i++) {
      for (int j = 1; j < (int)data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  // imos (i,j) を get
  T imos_get(int i, int j) { return data[i + 1][j + 1]; }

  // 半開
  T query(int i1, int j1, int i2, int j2) {
    return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);
  }
};

/*
 * @brief 二次元累積和
 */
