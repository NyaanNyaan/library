
// PotentialつきUnion-Find
template <class T>
struct UnionFindWithPotential {
  vector<int> par, rank;
  // pot...根に対するポテンシャル
  vector<T> pot;
  T UNIT;

  UnionFindWithPotential(int N, T UNIT_ = 0)
      : par(N), rank(N), pot(N), UNIT(UNIT_) {
    for (int i = 0; i < N; i++) par[i] = i, rank[i] = 0, pot[i] = UNIT;
  }

  // xの根を返す関数
  int root(int x) {
    if (par[x] == x) return x;
    int r = root(par[x]);
    pot[x] += pot[par[x]];
    return par[x] = r;
  }

  // 根に対するポテンシャルを返す関数
  T potential(int x) {
    root(x);
    return pot[x];
  }

  // 根が同じかを判定する関数
  bool same(int x, int y) { return root(x) == root(y); }

  // xのyに対するpotentialを返す関数
  T diff(int x, int y) { return potential(x) - potential(y); }

  // xのyに対するpotentialがpである (xはyよりもp大きい)
  // falseの時、既存の情報と矛盾
  bool merge(int x, int y, T p) {
    p += potential(y) - potential(x);
    x = root(x), y = root(y);
    if (x == y) {
      return p == UNIT;
    }
    if (rank[x] > rank[y]) swap(x, y), p = -p;
    if (rank[x] == rank[y]) ++rank[x];
    par[x] = y, pot[x] = p;
    return true;
  }
};