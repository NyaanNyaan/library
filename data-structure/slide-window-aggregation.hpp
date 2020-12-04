#pragma once

template <typename T, typename F>
struct SlideWindowAggregation {
  stack<T> a0, a1;
  stack<T> r0, r1;
  F f;
  T I, f0, f1;

  SlideWindowAggregation(F f_, T I_) : f(f_), I(I_), f0(I_), f1(I_) {}

 private:
  void push_s0(const T &x) {
    a0.push(x);
    r0.push(f0 = f(x, f0));
  }
  void push_s1(const T &x) {
    a1.push(x);
    r1.push(f1 = f(f1, x));
  }
  void transfer() {
    while (!a1.empty()) {
      push_s0(a1.top());
      a1.pop();
    }
    while (!r1.empty()) r1.pop();
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
    a0.pop();
    r0.pop();
    f0 = r0.empty() ? I : r0.top();
  }
  T query() { return f(f0, f1); }
};
