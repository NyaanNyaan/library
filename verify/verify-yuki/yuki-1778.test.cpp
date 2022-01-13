#define PROBLEM "https://yukicoder.me/problems/no/1778"
//
#include "../../template/template.hpp"
//
#include "../../tree/heavy-light-decomposition.hpp"
#include "../../tree/inclusion-tree.hpp"
//
using namespace Nyaan;

void Nyaan::solve() {
  inl(N, Q);
  ins(S);

  vp vc;
  vector<int> a(N);

  {
    vi st;
    rep(j, N) {
      if (S[j] == ')') {
        int i = st.back();
        st.pop_back();
        vc.emplace_back(i, j + 1);
        a[i] = j, a[j] = i;
      } else {
        st.push_back(j);
      }
    }
  }

  auto g = inclusion_tree(vc, N);
  HeavyLightDecomposition hld(g);
  map<pl, int> mp;
  rep(i, sz(vc)) mp[vc[i]] = i;

  while (Q--) {
    ini(u, v);
    --u, --v;
    int uu = a[u];
    if (u > uu) swap(u, uu);
    int vv = a[v];
    if (v > vv) swap(v, vv);

    int s = mp[{u, uu + 1}];
    int t = mp[{v, vv + 1}];

    int l = hld.lca(s, t);
    if (l == 0) {
      out(-1);
    } else {
      out(vc[l].fi + 1, vc[l].se);
    }
  }
}
