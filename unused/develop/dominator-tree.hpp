#pragma once

template <typename G>
struct DominatorTree {
  struct UF {
    vector<int> par, m;
    UF() = default;
    UF(int N) : par(N, -1), m(N) { iota(begin(m), end(m), 0); }

    int find(int i, const function<bool(int, int)>& f) {
      if (par[i] == -1) return i;
      int r = find(par[i], f);
      if (f(m[par[i]], m[i])) m[i] = m[par[i]];
      return par[i] = r;
    }

    int eval(int i, const function<bool(int, int)>& f) {
      find(i, f);
      return m[i];
    }

    void link(int p, int c) {
      assert(par[c] == -1);
      par[c] = p;
    }
  };

  G& g;
  vector<vector<int>> rg;
  UF uf;
  int N;
  vector<int> semi, v, par;
  DominatorTree(G& _g)
      : g(_g), uf(N), N(g.size()), semi(N, -1), v(N), par(N, -1) {
    rg.resize(N);
    for (int i = 0; i < N; i++) {
      for (auto& j : g[i]) {
        rg[j].push_back(i);
      }
    }
  }

  void dfs(int c, int& i) {
    semi[c] = i;
    v[i++] = c;
    for (auto& d : g[c]) {
      if (semi[d] != -1) {
        par[d] = c;
        dfs(c, i);
      }
    }
  }

  void run(int root) {
    {
      int i = 0;
      dfs(root, i);
    }
    auto comp = [&](int i, int j) -> bool { return semi[i] < semi[j]; };

    for (int i = N - 1; i; i--) {
      int w = v[i];
      for (auto& d : rg[w]) {
        int u = uf.eval(d, comp);
        semi[w] = min(semi[w], semi[u]);
      }
      
    }
  }
};
