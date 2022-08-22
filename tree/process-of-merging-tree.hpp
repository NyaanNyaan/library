#pragma once

// マージ過程を表す木
// es の昇順に木をマージしていく。(es にはマージに使わない辺が入っていてよい)
//
// 返り値 : (graph, 補助的な頂点に対応する辺の重み, root)
template <typename T>
tuple<WeightedGraph<T>, vector<T>, int> process_of_merging_tree(
    const Edges<T>& es) {
  int n = 1;
  for (auto& e : es) n = max(n, max(e.src, e.to) + 1);
 
  WeightedGraph<T> g(n * 2 - 1);
  vector<T> nodes(n - 1);
 
  UnionFind uf(n);
  vector<int> roots(n);
  iota(begin(roots), end(roots), 0);
  int aux = n;
 
  for (auto& e : es) {
    int u = e.src, v = e.to;
    if (uf.same(u, v)) continue;
    T w = e.cost;
    auto f = [&](int x, int y) {
      g[aux].emplace_back(aux, roots[x], w);
      g[aux].emplace_back(aux, roots[y], w);
      roots[x] = roots[y] = aux;
    };
    uf.unite(u, v, f);
    nodes[aux - n] = w;
    aux++;
  }
  assert(aux == 2 * n - 1);
 
  return {g, nodes, 2 * n - 2};
}
