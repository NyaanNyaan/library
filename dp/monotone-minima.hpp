#pragma once

#include <functional>
#include <vector>
using namespace std;

// NxN 行列がある
// m_i := argmin_j (A_{i,j}) が単調増加であるときに m_i を列挙する
// A(i, j) : A[i][j] を返す関数
template <typename T>
vector<int> monotone_minima(int N, const function<T(int, int)>& A) {
  vector<int> res(N);
  auto dfs = [&](auto rc, int is, int ie, int l, int r) -> void {
    if (is == ie) return;
    int i = (is + ie) / 2;
    int m = l;
    T fim = A(i, m);
    for (int k = l + 1; k < r; k++) {
      T fik = A(i, k);
      if (fik < fim) fim = fik, m = k;
    }
    res[i] = m;
    rc(rc, is, i, l, m + 1);
    rc(rc, i + 1, ie, m, r);
  };
  dfs(dfs, 0, N, 0, N);
  return res;
}

/**
 * @brief monotone minima
 */
