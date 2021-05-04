#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../data-structure/union-find.hpp"
#include "../../misc/rng.hpp"
#include "../../tree/convert-tree.hpp"
#include "../../tree/pruefer-code.hpp"
#include "../../tree/tree-query.hpp"

using namespace Nyaan;

template <typename G>
bool is_tree(G& g, bool directed = false) {
  int n = g.size();
  UnionFind uf(n);
  rep(i, n) each(j, g[i]) {
    if (!directed and i > j) continue;
    if (!uf.unite(i, j)) return false;
  }
  return uf.size(0) == n;
}

template <typename G>
bool is_rooted_tree(G& g, int root) {
  int n = g.size();
  vector<char> vis(n, false);
  auto dfs = [&](auto rc, int c) -> void {
    vis[c] = true;
    each(d, g[c]) {
      assert(vis[d] == false);
      rc(rc, d);
    }
  };
  dfs(dfs, root);
  int sm = 0;
  each(b, vis) sm += !!b;
  return sm == n;
}

template <typename G>
bool is_inverse_tree(G& g, G& rg) {
  set<pair<int, int>> s, t;
  int n = g.size();
  for (int i = 0; i < n; i++) {
    for (auto& j : g[i]) s.emplace(i, int(j));
    for (auto& j : rg[i]) t.emplace(j, int(i));
  }
  return s == t;
}

void test_tree_query(vvi& g, int root = 0) {
  Tree<vvi> tree(g, root);
  int N = sz(g);
  rep(i, N) rep(j, N) {
    vi p1 = tree.path(i, j);
    vi p2{int(i)};
    for (int k = i; k != j;) {
      p2.push_back(k = tree.nxt(k, j));
    }
    assert(p1 == p2);
    int l = i, ld = tree.depth(i);
    each(x, p1) if (amin(ld, tree.depth(x))) l = x;
    assert(l == tree.lca(i, j));
  }
}

using namespace Nyaan;

void Nyaan::solve() {
  // Random Tree
  for (int N : vi{2, 3, 4, 5, 10, 100}) {
    vvi g = random_tree(N);
    assert(is_tree(g) && "random tree");
    test_tree_query(g);

    int root = randint(0, N);
    vvi rg = rooted_tree(g, root);
    assert(is_tree(rg, true) && "rooted tree");
    test_tree_query(rg, root);

    vvi rh = inverse_tree(rg);
    assert(is_inverse_tree(rg, rh) && "inverse tree");
  }

  for (int N : vi{2, 3, 4, 5, 10, 100}) {
    vvi _g = random_tree(N);
    assert(is_tree(_g) && "random tree");
    WeightedGraph<ll> g(N);
    rep(i, N) each(j, _g[i]) { g[i].emplace_back(i, j, rng() & 15); }

    int root = randint(0, N);
    auto rg = rooted_tree(g, root);
    assert(is_tree(rg, true) && "rooted tree");

    auto rh = inverse_tree(rg);
    assert(is_inverse_tree(rg, rh) && "inverse tree");
  }

  // Line Tree
  for (int N : vi{2, 3, 4, 5, 10, 100}) {
    vvi g(N);
    rep1(i, N - 1) g[i - 1].push_back(i);
    test_tree_query(g);
  }

  // Preufer Code
  {
    V<vvi> gs(125);
    rep(i, 125) {
      vi pr(3);
      for (int j = i, k = 0; k < 3; j /= 5, k++) {
        pr[k] = j % 5;
      }
      gs[i] = pruefer_code(pr);
      for (auto& es : gs[i]) sort(begin(es), end(es));
    }
    rep(i, 125) assert(is_tree(gs[i]));
    rep(i, 125) rep(j, i) assert(gs[i] != gs[j]);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
