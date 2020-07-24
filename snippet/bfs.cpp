auto bfs = [&](int start = 0) {
  queue<int> Q;
  Q.push(start);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (auto dst : g[cur]) {
      if (/* already visited */) continue;
      // write down here

      Q.push(dst);
    }
  }
};
bfs();