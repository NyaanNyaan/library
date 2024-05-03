#pragma once

#include <utility>
#include <vector>
using namespace std;

// {rank, det(非正方行列の場合は未定義)} を返す
// 型が double や Rational でも動くはず？(未検証)
//
// pivot 候補 : [0, pivot_end)
template <typename T>
std::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end = -1,
                                   bool diagonalize = false) {
  if (a.empty()) return {0, 1};
  int H = a.size(), W = a[0].size(), rank = 0;
  if (pivot_end == -1) pivot_end = W;
  T det = 1;
  for (int j = 0; j < pivot_end; j++) {
    int idx = -1;
    for (int i = rank; i < H; i++) {
      if (a[i][j] != T(0)) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      det = 0;
      continue;
    }
    if (rank != idx) det = -det, swap(a[rank], a[idx]);
    det *= a[rank][j];
    if (diagonalize && a[rank][j] != T(1)) {
      T coeff = T(1) / a[rank][j];
      for (int k = j; k < W; k++) a[rank][k] *= coeff;
    }
    int is = diagonalize ? 0 : rank + 1;
    for (int i = is; i < H; i++) {
      if (i == rank) continue;
      if (a[i][j] != T(0)) {
        T coeff = a[i][j] / a[rank][j];
        for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;
      }
    }
    rank++;
  }
  return make_pair(rank, det);
}
