#pragma once

#include <vector>
using namespace std;

template <typename T, typename F>
struct SlideWindowAggregationDeque {
  vector<T> a0, a1, r0, r1;
  F f;
  T I;

  SlideWindowAggregationDeque(F _f, T _i) : f(_f), I(_i) {}

 private:
  T get0() const { return r0.empty() ? I : r0.back(); }
  T get1() const { return r1.empty() ? I : r1.back(); }

  void push0(const T &x) {
    a0.push_back(x);
    r0.push_back(f(x, get0()));
  }
  void push1(const T &x) {
    a1.push_back(x);
    r1.push_back(f(get1(), x));
  }
  void rebalance() {
    int n = a0.size() + a1.size();
    int s0 = n / 2 + (a0.empty() ? n % 2 : 0);
    vector<T> a{a0};
    reverse(begin(a), end(a));
    copy(begin(a1), end(a1), back_inserter(a));
    a0.clear(), r0.clear();
    a1.clear(), r1.clear();
    for (int i = s0 - 1; i >= 0; i--) push0(a[i]);
    for (int i = s0; i < n; i++) push1(a[i]);
  }

 public:
  void push_front(const T &t) { push0(t); }
  void push_back(const T &t) { push1(t); }
  T front() const { return a0.empty() ? a1.front() : a0.back(); }
  T back() const { return a1.empty() ? a0.front() : a1.back(); }
  void pop_front() {
    if (a0.empty()) rebalance();
    assert(!a0.empty());
    a0.pop_back(), r0.pop_back();
  }
  void pop_back() {
    if (a1.empty()) rebalance();
    assert(!a1.empty());
    a1.pop_back(), r1.pop_back();
  }
  T query() { return f(get0(), get1()); }
};

/**
 * @brief Slide Window Aggrigation (deque)
 */
