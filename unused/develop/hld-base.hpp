#include "../../template/template.hpp"

template <typename G>
struct HLDBase {
 private:
  G &g;
  int N;
  vector<int> sub, ord, down, up;
  int root;

  int dfs1(int cur, int par = -1) {
    sub[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub[cur] += dfs1(dst, cur);
      if (sub[dst] > sub[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub[cur];
  }

  void dfs2(int cur, int &i, int par) {
    ord[i] = cur;
    down[cur] = i++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, i, cur);
    }
    up[cur] = i;
  }

 public:
  HLDBase(G &_g, int r = 0)
      : g(_g), N(g.size()), sub(N), ord(N), down(N), up(N), root(r) {
    dfs1(root);
    int i = 0;
    dfs2(root, i, -1);
  }
};
