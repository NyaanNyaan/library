#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/erasable-priority-queue.hpp"
using namespace Nyaan;

void q() {
  ErasablePriorityQueue<int> Q;
  Q.push(1);
  Q.push(3);
  Q.push(5);
  assert(Q.top() == 1);
  Q.pop();
  assert(Q.top() == 3);
  Q.erase(5);
  Q.push(6);
  assert(Q.top() == 3);
  Q.pop();
  assert(Q.top() == 6);

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
