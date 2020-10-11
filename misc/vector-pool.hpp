#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct VectorPool {
  using ptr_t = int;
  vector<T> pool;
  vector<ptr_t> st;
  int idx;
  int cap;

  VectorPool(int s = 4) : pool(s), st(), idx(0), cap(s) { assert(s > 0); }

  inline T& operator[](ptr_t i) { return pool[i]; }

  void reallocate() {
    assert(st.size() == 0);
    cap *= 2;
    pool.resize(cap);
  }

  ptr_t alloc() {
    if (idx != cap) return idx++;
    if (st.empty()) reallocate();
    ptr_t ret = st.back();
    st.pop_back();
    return ret;
  }

  template <typename... Args>
  ptr_t my_new(Args... args) {
    ptr_t ret = alloc();
    pool[ret] = T(args...);
    return ret;
  }

  void free(ptr_t i) { st.push_back(i); }

  void clear() {
    idx = 0;
    st.clear();
  }
};
