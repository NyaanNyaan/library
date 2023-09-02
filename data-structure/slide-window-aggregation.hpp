#pragma once

#include <vector>
using namespace std;

template <typename T, typename F>
struct SlideWindowAggregation {
  vector<T> a0, a1, r0, r1;
  F f;
  T I, f0, f1;

  SlideWindowAggregation(F _f, T _i) : f(_f), I(_i), f0(_i), f1(_i) {}

 private:
  void push_s0(const T &x) {
    a0.push_back(x);
    r0.push_back(f0 = f(x, f0));
  }
  void push_s1(const T &x) {
    a1.push_back(x);
    r1.push_back(f1 = f(f1, x));
  }
  void transfer() {
    while (!a1.empty()) {
      push_s0(a1.back());
      a1.pop_back();
    }
    while (!r1.empty()) r1.pop_back();
    f1 = I;
  }

 public:
  void push(const T &x) {
    if (a0.empty()) {
      push_s0(x);
      transfer();
    } else {
      push_s1(x);
    }
  }
  void pop() {
    if (a0.empty()) transfer();
    a0.pop_back();
    r0.pop_back();
    f0 = r0.empty() ? I : r0.back();
  }
  T query() { return f(f0, f1); }
};

/**
 * @brief Slide Window Aggrigation
 * @docs docs/data-structure/slide-window-aggregation.md
 */
