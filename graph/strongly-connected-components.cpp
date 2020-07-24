// Strongly Connected Components
// initialize        ... StronglyConnectedComponents scc(g);
// build             ... vvi h; scc.build(h);
// new node of k     ... scc[k]
// inv of scc[k] = i ... scc.belong(i)

template <typename G>
struct StronglyConnectedComponents {
  const G &g;
  vector<vector<int>> rg;
  vector<int> comp, order;
  vector<char> used;
  vector<vector<int>> blng;

  StronglyConnectedComponents(G &g) : g(g), used(g.size(), 0) {}

  int operator[](int k) { return comp[k]; }

  vector<int> &belong(int i) { return blng[i]; }

  void dfs(int idx) {
    if (used[idx]) return;
    used[idx] = true;
    for (auto to : g[idx]) dfs(int(to));
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if (comp[idx] != -1) return;
    comp[idx] = cnt;
    for (int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector<vector<int>> &t) {
    for (int i = 0; i < (int)g.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    used.clear();
    used.shrink_to_fit();

    comp.resize(g.size(), -1);

    rg.resize(g.size());
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto e : g[i]) {
        rg[(int)e].emplace_back(i);
      }
    }
    int ptr = 0;
    for (int i : order)
      if (comp[i] == -1) rdfs(i, ptr), ptr++;
    rg.clear();
    rg.shrink_to_fit();
    order.clear();
    order.shrink_to_fit();

    t.resize(ptr);
    blng.resize(ptr);
    for (int i = 0; i < (int)g.size(); i++) {
      blng[comp[i]].push_back(i);
      for (auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if (x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};
