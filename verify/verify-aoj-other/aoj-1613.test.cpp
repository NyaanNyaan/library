#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1613"

#include "../../template/template.hpp"
//
#include "../../tree/tree-hash.hpp"

using namespace Nyaan;

// https://kimiyuki.net/writeups/algo-etc-icpc-2016-domestic-f/

#define whole(f, x, ...) \
  ([&](decltype((x)) y) { return (f)(begin(y), end(y), ##__VA_ARGS__); })(x)
template <typename T, typename X>
auto vectors(T a, X x) {
  return vector<T>(x, a);
}
template <typename T, typename X, typename Y, typename... Zs>
auto vectors(T a, X x, Y y, Zs... zs) {
  auto cont = vectors(a, y, zs...);
  return vector<decltype(cont)>(x, cont);
}

const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dx[] = {0, 0, 1, -1, -1, 1, 1, -1};

vector<vector<bool> > load_image() {
  int h, w;
  cin >> h >> w;
  if (h == 0 and w == 0) return vector<vector<bool> >();
  vector<vector<bool> > f = vectors(false, h + 2, w + 2);
  rep(y, h) rep(x, w) {
    char c;
    cin >> c;
    f[y + 1][x + 1] = c == '#';
  }
  return f;
}

vector<set<int> > make_tree(vector<vector<bool> > const& f) {
  int h = f.size();
  int w = f.front().size();
  vector<vector<int> > k = vectors(-1, h, w);
  vector<set<int> > g;
  function<void(int, int, int)> dfs = [&](int y, int x, int cur_k) {
    k[y][x] = cur_k;
    rep(i, f[y][x] ? 8 : 4) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 or h <= ny or nx < 0 or w <= nx) continue;
      if (f[ny][nx] == f[y][x]) {
        if (k[ny][nx] == -1) {
          dfs(ny, nx, cur_k);
        }
      } else {
        if (k[ny][nx] != -1) {
          g[k[ny][nx]].insert(k[y][x]);
        }
      }
    }
  };
  rep(y, h) rep(x, w) if (k[y][x] == -1) {
    g.emplace_back();
    dfs(y, x, g.size() - 1);
  }
  return g;
}

using Hash = typename TreeHash<vvi>::Hash;

Hash tree_hash(vector<set<int> > f) {
  vvi g(sz(f));
  rep(i, sz(f)) {
    each(x, f[i]) {
      g[i].push_back(x);
      g[x].push_back(i);
    }
  }
  TreeHash hash(g);
  return hash.hash[0];
}

void Nyaan::solve() {
  while (true) {
    auto g1 = load_image();
    if (g1.empty()) exit(0);
    auto g2 = load_image();
    auto t1 = make_tree(g1);
    auto t2 = make_tree(g2);
    auto h1 = tree_hash(t1);
    auto h2 = tree_hash(t2);
    out(h1 == h2 ? "yes" : "no");
  }
}