#pragma once

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
struct DualofSlopeTrick {
  T addL, addR, f0;
  priority_queue<T> L;
  priority_queue<T, vector<T>, greater<>> R;

  DualofSlopeTrick() : addL(0), addR(0), f0(0) {}
  DualofSlopeTrick(T _f0, const vector<T>& l, const vector<T>& r)
      : addL(0), addR(0), f0(_f0) {
    assert(!l.empty() and !r.empty());
    for (auto& x : l) L.push(x);
    for (auto& x : r) R.push(x);
  }

  void pushL(T x) { L.push(x - addL); }
  void pushR(T x) { R.push(x - addR); }
  T getL() { return L.top() + addL; }
  T getR() { return R.top() + addR; }
  T popL() {
    T x = L.top();
    L.pop();
    return x + addL;
  }
  T popR() {
    T x = R.top();
    R.pop();
    return x + addR;
  }

  // f(x) <- f(x+1)
  void left_shift() {
    assert(!L.empty());
    T x = popL();
    f0 += x;
    pushR(-x);
    if (L.empty()) pushL(x);
  }
  // f(x) <- f(x-1)
  void right_shift() {
    assert(!R.empty());
    T x = popR();
    f0 += x;
    pushL(-x);
    if (R.empty()) pushR(x);
  }

  // 加算, 破壊的
  void add(DualofSlopeTrick<T>& rhs) {
    f0 += rhs.f0;
    if (L.size() < rhs.L.size()) swap(L, rhs.L), swap(addL, rhs.addL);
    if (R.size() < rhs.R.size()) swap(R, rhs.R), swap(addR, rhs.addR);
    vector<T> v;

    assert(!rhs.L.empty() and !rhs.R.empty());
    while (rhs.L.size() > 1u) v.push_back(popL() + rhs.popL());
    addL += rhs.popL();
    while (v.size()) pushL(v.back()), v.pop_back();
    while (rhs.R.size() > 1u) v.push_back(popR() + rhs.popR());
    addR += rhs.popR();
    while (v.size()) pushR(v.back()), v.pop_back();
  }
  // infimal convolution, 破壊的
  void convolve(DualofSlopeTrick<T>& rhs) {
    f0 += rhs.f0;
    if (L.size() + R.size() < rhs.L.size() + rhs.R.size()) {
      swap(L, rhs.L), swap(addL, rhs.addL);
      swap(R, rhs.R), swap(addR, rhs.addR);
    }
    while (rhs.L.size()) {
      T a = rhs.popL();
      if (!R.empty()) f0 -= max<T>(0, a - getR());
      pushR(a), pushL(popR());
    }
    while (rhs.R.size()) {
      T a = rhs.popR();
      if (!L.empty()) f0 -= max<T>(0, getL() - a);
      pushL(a), pushR(popL());
    }
  }

  void dump() {
    DualofSlopeTrick<T> st{*this};
    cerr << "f0 : " << st.f0 << endl;
    cerr << "L : ";
    while (st.L.size()) cerr << st.popL() << " ";
    cerr << endl;
    cerr << "R : ";
    while (st.R.size()) cerr << st.popR() << " ";
    cerr << endl;
  }
};
