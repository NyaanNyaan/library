#pragma once

// [0, N) の包含関係に関する木
//
// 入力 : 区間[L, R) の組 (包含 OK, 交差 NG)
// 出力 : g : グラフ
//   AB : 破壊的, (first, -second) の昇順でソートされる
//        & AB[0] に超頂点 (-1, N + 1) が入る
template <typename Pair>
vector<vector<int>> inclusion_tree(vector<Pair>& AB, int N) {
  int M = AB.size();
  AB.emplace_back(-1, N + 1);
  sort(begin(AB), end(AB), [](auto l, auto r) {
    return l.first == r.first ? l.second > r.second : l.first < r.first;
  });
  vector<vector<int>> g(M + 1);
  vector<int> par(M + 1, -1);
  for (int i = 1; i <= M; i++) {
    auto [a, b] = AB[i];
    int p = i - 1;
    while (p <= M) {
      trc(i, p);
      auto [v, pb] = AB[p];
      assert(v <= a);
      if (b <= pb) break;
      assert(!(a < pb && pb < b));
      p = par[p];
    }
    g[p].push_back(i);
    par[i] = p;
  }
  return g;
}
