#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include "../../template/template.hpp"
#include "../../data-structure/persistent-queue.hpp"

using namespace Nyaan; void Nyaan::solve() {
  PersistentQueue<int> Q;
  ini(q);
  vi roots(q + 1);
  roots[0] = 0;
  rep(_, q) {
    ini(cmd);
    if (cmd) {
      ini(i);
      auto p = Q.pop(roots[i + 1]);
      out(p.first);
      roots[_ + 1] = p.second;
    } else {
      ini(t, x);
      auto rts = Q.push(x, roots[t + 1]);
      roots[_ + 1] = rts;
    }
  }
}