#pragma once

#include <utility>
#include <vector>
using namespace std;

// fast BS-GS
// period = (order of g)
// s should be around sqrt(mod * Q).
template <typename T>
struct FastBSGS {
  T gpow;
  int size, mask, period;
  vector<pair<T, int>> vs;
  vector<int> os;
  FastBSGS(const T& g, int s, int _period)
      : size(1 << __lg(max(1, min(s, _period)))),
        mask(size - 1),
        period(_period),
        vs(size),
        os(size + 1) {
    T x(1);
    for (int i = 0; i < size; ++i, x *= g) os[x.get() & mask]++;
    for (int i = 1; i < size; ++i) os[i] += os[i - 1];
    x = 1;
    for (int i = 0; i < size; ++i, x *= g) vs[--os[x.get() & mask]] = {x, i};
    gpow = x;
    os[size] = size;
  }
  int find(T x) const {
    for (int t = 0; t < period; t += size, x *= gpow) {
      for (int m = (x.get() & mask), i = os[m]; i < os[m + 1]; ++i) {
        if (x == vs[i].first) {
          int ret = vs[i].second - t;
          return ret < 0 ? ret + period : ret;
        }
      }
    }
    assert(false);
  }
};
