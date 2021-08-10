#pragma once

template <typename T>
struct SegmentSet {
  map<T, T> st;
  SegmentSet() = default;

  using iterator = typename map<T, T>::iterator;
  using const_iterator = typename map<T, T>::const_iterator;
  const_iterator begin() const { return st.begin(); }
  const_iterator end() const { return st.end(); }
  const_iterator find(T x) const {
    auto it = st.upper_bound(x);
    if (it == st.begin() || (--it)->second <= x) return st.end();
    return it;
  }

  void insert(T l, T r) {
    auto L = st.upper_bound(l), R = st.upper_bound(r);
    if (L != st.begin() && l <= prev(L)->second) --L;
    if (L != R) {
      l = min(l, L->first);
      r = max(r, prev(R)->second);
      st.erase(L, R);
    }
    st[l] = r;
  }

  void erase(T l, T r) {
    auto L = st.upper_bound(l), R = st.upper_bound(r);
    if (L != st.begin() && l <= prev(L)->second) --L;
    if (L == R) return;
    T nl = min(l, L->first), nr = max(r, prev(R)->second);
    st.erase(L, R);
    if (nl < l) st[nl] = l;
    if (r < nr) st[r] = nr;
  }

  int size() { return st.size(); }
};
