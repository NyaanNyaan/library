#pragma once

template <typename T,typename ptr_t = int>
struct VectorPool {
  vector<T> pool;
  vector<ptr_t> st;
  int idx;
  int cap;

  // pool[0] is missing number (assuming nil)
  VectorPool(int s = 4) : pool(s), st(), idx(1), cap(s) { assert(s > 0); }

  inline T& operator[](ptr_t i) { return pool[int(i)]; }

  void reallocate() {
    assert(idx == cap && st.size() == 0);
    cap *= 2;
    pool.resize(cap, T());
  }

  ptr_t alloc() {
    if (idx != cap) return ptr_t(idx++);
    if (st.empty()) {
      reallocate();
      return ptr_t(idx++);
    }
    ptr_t ret = st.back();
    st.pop_back();
    return ret;
  }

  template <typename... Args>
  ptr_t my_new(Args... args) {
    ptr_t ret = alloc();
    pool[int(ret)] = T(args...);
    return ret;
  }

  void free(ptr_t i) { st.push_back(i); }

  void clear() {
    idx = 1;
    st.clear();
  }
};
