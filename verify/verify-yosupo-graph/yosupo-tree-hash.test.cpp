#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
//
#include "../../template/template.hpp"
//
#include "../../hashmap/hashmap-unerasable.hpp"
//
#include "../../tree/rooted-tree-hash.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  vvi g(N);
  for (int i = 1; i < N; i++) {
    ini(p);
    g[p].push_back(i);
  }
  RootedTreeHash th{g};
  UnerasableHashMap<typename RootedTreeHash<vvi>::Hash, int> mp;
  int K = 0;
  vi ans(N, -1);

  rep(i, N) {
    if (mp.count(th.hash[i]) == 0) {
      mp[th.hash[i]] = ans[i] = K++;
    } else {
      ans[i] = mp[th.hash[i]];
    }
  }
  out(K);
  rep(i, N) cout << ans[i] << " ";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
