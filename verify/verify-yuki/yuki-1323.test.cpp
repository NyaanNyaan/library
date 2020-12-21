#define PROBLEM "https://yukicoder.me/problems/no/1323"

#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../shortest-path/bfs-restore.hpp"

void Nyaan::solve() {
  ini(H, W);
  ini(ra, ca, rb, cb);
  ra--, ca--, rb--, cb--;
  vs gr(H);
  in(gr);
  auto idx = [&](int i, int j) { return i * W + j; };
  int ids = idx(ra, ca), idt = idx(rb, cb);
  V<P<int, int>> near{mkp(1, 0), mkp(-1, 0), mkp(0, -1), mkp(0, 1)};

  vvi g;
  auto mk = [&]() {
    g.clear();
    g.resize(H * W);
    reg(i, 1, H - 1) reg(j, 1, W - 1) {
      if (gr[i][j] == '#') continue;
      if (gr[i + 1][j] == '.') g[idx(i + 1, j)].push_back(idx(i, j));
      if (gr[i - 1][j] == '.') g[idx(i - 1, j)].push_back(idx(i, j));
      if (gr[i][j + 1] == '.') g[idx(i, j + 1)].push_back(idx(i, j));
      if (gr[i][j - 1] == '.') g[idx(i, j - 1)].push_back(idx(i, j));
    }
  };
  mk();

  auto d0 = bfs_restore(g, ids);
  auto d1 = bfs_restore(g, idt);
  if (d0[idt].first == -1) die(-1);
  ll ans0 = d0[idt].first;
  vi path;
  for (int i = idt; i != -1; i = d0[i].second) {
    path.push_back(i);
  }

  each(p, path) {
    int hh = p / W, ww = p % W;
    gr[hh][ww] = '#';
  }

  ll mn = inf;
  {
    vi d2(H * W * 2, -1);
    d2[idx(ra, ca)] = 0;
    queue<int> Q;
    Q.push(ids);
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      int codin = cur >= H * W ? cur - H * W : cur;
      int f = (cur != codin);
      int h = codin / W;
      int w = codin % W;
      if (codin == idt) continue;
      int dc = d2[cur];
      f |= gr[h][w] == '.';
      each(dst, g[codin]) {
        int nh = dst / W, nw = dst % W;
        int nf = f | (gr[nh][nw] == '.');
        if (dst == ids) nf = 0;
        int nid = nf * H * W + idx(nh, nw);
        if (d2[nid] == -1) {
          d2[nid] = dc + 1;
          Q.push(nid);
        }
      }
    }
    if (d2[H * W + idt] != -1) amin(mn, d2[H * W + idt]);
  }

  bool nukemiti = 0, mawarimiti = 0;
  int mws = 0, mwt = 0;
  vi mwrs;
  each(p, path) {
    int hh = p / W, ww = p % W;
    each2(dh, dw, near) if (gr[hh + dh][ww + dw] == '.') {
      if (p != ids and p != idt)
        nukemiti = true;
      else {
        mawarimiti = true, mwrs.push_back(idx(hh + dh, ww + dw));
        if (ids == p) mws++;
        if (idt == p) mwt++;
      }
    }
  }
  if (!nukemiti and !mawarimiti) die(-1);

  if (nukemiti) {
    out(ans0 + min(ans0 + 2, mn));
    return;
  }
  if (mws >= 2 or mwt >= 2) {
    out(ans0 + min(ans0 + 4, mn));
    return;
    exit(1);
  }

  mk();

  ll mrval = inf;
  each(p, mwrs) {
    auto d2 = bfs_restore(g, p);
    rep(i, H) rep(j, W) {
      if (gr[i][j] == '#') continue;
      int id = idx(i, j);
      if (d2[id].first == -1) continue;
      int masu = 0;
      each2(di, dj, near) masu += gr[i + di][j + dj] == '.';
      if (p == idx(i, j) and masu >= 2) mrval = 0;
      if (masu <= 2) continue;
      amin(mrval, d2[id].first);
    }
  }

  if (mn == inf and mrval == inf) die(-1);
  amin(mn, (mrval + 2) * 4 + ans0);
  out(ans0 + mn);
}
