#pragma once


vector<mint> LinearEquation_hashmap(vector<HashMap<int, mint>> A,
                                    vector<mint> b, int upper = -1) {
  int H = A.size(), W = b.size();
  if (upper = -1) upper = W;
  vector<int> pivots(W, -1);
  int rank = 0, je = W;
  for (int j = 0; j < je; j++) {
    int idx = -1;
    for (int i = rank; i < H; i++) {
      auto it = A[i].find(j);
      if (it != end(A[i]) and it->second != mint{}) {
        idx = i;
        break;
      }
    }
    if (idx == -1) continue;
    if (rank != idx) {
      swap(A[rank], A[idx]);
      swap(b[rank], b[idx]);
    }
    pivots[j] = rank;
    vector<pair<int, mint>> arank;
    {
      mint coeff = A[rank][j].inverse();
      if (coeff * A[rank][j] != 1) return {};
      for (auto& [k, v] : A[rank]) {
        if (v != mint{}) {
          v *= coeff;
          arank.emplace_back(k, v);
        }
      }
      b[rank] *= coeff;
    }
    for (int i = rank + 1; i < min(H, rank + upper + 1); i++) {
      auto it = A[i].find(j);
      if (it != end(A[i]) and it->second != mint{}) {
        mint coeff = (it->second);
        for (auto& [k, v] : arank) A[i][k] -= v * coeff;
        b[i] -= b[rank] * coeff;
      }
    }
    rank++;
  }
  vector<mint> res(W);
  for (int j = W - 1; j >= 0; j--) {
    if (pivots[j] != -1) {
      int i = pivots[j];
      for (auto& [k, v] : A[i]) b[i] -= v * res[k];
      res[j] = b[i];
    }
  }
  for (int i = rank; i < H; i++) {
    mint l = 0;
    for (auto& [k, v] : A[i]) l += res[k] * v;
    if (l != b[i]) return {};
  }
  return res;
}
