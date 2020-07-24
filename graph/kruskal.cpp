struct UF {
  vector<int> par, sizes;
  int cnt;
  UF(int N) : par(N), sizes(N, 1), cnt(N) {
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return sizes[find(x)]; }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
    cnt--;
  }

  int count() const { return cnt; }
};

template <typename T>
T kruskal(int N, Edges<T> &es) {
  sort(begin(es), end(es),
       [&](edge<T> a, edge<T> b) { return a.cost < b.cost; });
  UF uf(N);
  T ret = 0;
  for (edge<T> &e : es) {
    if (uf.same(e.src, e.to)) continue;
    ret += e.cost;
    uf.unite(e.src, e.to);
  }
  return ret;
}