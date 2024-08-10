#pragma once

#include <queue>
#include <type_traits>
using namespace std;

template <typename T, bool Minimize = true>
struct ErasablePriorityQueue {
  using Queue =
      conditional_t<Minimize, priority_queue<T, vector<T>, greater<T>>,
                    priority_queue<T>>;
  Queue Q, Q2;

  ErasablePriorityQueue() = default;

  void push(const T& t) { Q.push(t); }
  T top() {
    normalize();
    assert(!Q.empty());
    return Q.top();
  }
  void pop() {
    normalize();
    assert(!Q.empty());
    Q.pop();
  }
  void erase(const T& t) { Q2.push(t); }

 private:
  void normalize() {
    while (!Q.empty() and !Q2.empty() and Q.top() == Q2.top()) {
      Q.pop(), Q2.pop();
    }
  }
};
