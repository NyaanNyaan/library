#pragma once

vector<pair<int, int>> bfs_restore(vector<vector<int>>& g, int st = 0) {
  vector<pair<int, int>> d(g.size(), make_pair(-1, -1));
  d[st] = make_pair(0, -1);
  queue<int> Q;
  Q.push(st);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    int cd = d[cur].first;
    for (auto&& dst : g[cur]) {
      if (d[dst].first == -1) {
        d[dst].first = cd + 1;
        d[dst].second = cur;
        Q.push(dst);
      }
    }
  }
  return d;
}