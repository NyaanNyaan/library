#pragma once

#include <vector>
using namespace std;

#include "../data-structure/binary-indexed-tree.hpp"

// https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp
template <class I, class T>
class RectangleAddRectangleSum {
  struct AddQuery {
    I xl, xr, yl, yr;
    T val;
  };
  struct SumQuery {
    I xl, xr, yl, yr;
  };
  vector<AddQuery> add_queries;
  vector<SumQuery> sum_queries;

 public:
  RectangleAddRectangleSum() = default;

  void add_rectangle(I xl, I xr, I yl, I yr, T val) {
    add_queries.push_back(AddQuery{xl, xr, yl, yr, val});
  }
  void add_query(I xl, I xr, I yl, I yr) {
    sum_queries.push_back(SumQuery{xl, xr, yl, yr});
  }

  vector<T> solve() const {
    vector<I> ys;
    for (const auto &a : add_queries) {
      ys.push_back(a.yl);
      ys.push_back(a.yr);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    const int Y = ys.size();

    vector<tuple<I, int, int>> ops;
    for (int q = 0; q < int(sum_queries.size()); ++q) {
      ops.emplace_back(sum_queries[q].xl, 0, q);
      ops.emplace_back(sum_queries[q].xr, 1, q);
    }
    for (int q = 0; q < int(add_queries.size()); ++q) {
      ops.emplace_back(add_queries[q].xl, 2, q);
      ops.emplace_back(add_queries[q].xr, 3, q);
    }
    sort(ops.begin(), ops.end());

    BinaryIndexedTree<T> b00(Y), b01(Y), b10(Y), b11(Y);
    vector<T> ret(sum_queries.size());
    for (auto o : ops) {
      int qtype = get<1>(o), q = get<2>(o);
      if (qtype >= 2) {
        const AddQuery &query = add_queries.at(q);
        int i = lower_bound(ys.begin(), ys.end(), query.yl) - ys.begin();
        int j = lower_bound(ys.begin(), ys.end(), query.yr) - ys.begin();
        T x = get<0>(o);
        T yi = query.yl, yj = query.yr;
        if (qtype & 1) swap(i, j), swap(yi, yj);

        b00.add(i, x * yi * query.val);
        b01.add(i, -x * query.val);
        b10.add(i, -yi * query.val);
        b11.add(i, query.val);
        b00.add(j, -x * yj * query.val);
        b01.add(j, x * query.val);
        b10.add(j, yj * query.val);
        b11.add(j, -query.val);
      } else {
        const SumQuery &query = sum_queries.at(q);
        int i = lower_bound(ys.begin(), ys.end(), query.yl) - ys.begin();
        int j = lower_bound(ys.begin(), ys.end(), query.yr) - ys.begin();
        T x = get<0>(o);
        T yi = query.yl, yj = query.yr;
        if (qtype & 1) swap(i, j), swap(yi, yj);

        i--, j--;
        ret[q] +=
            b00.sum(i) + b01.sum(i) * yi + b10.sum(i) * x + b11.sum(i) * x * yi;
        ret[q] -=
            b00.sum(j) + b01.sum(j) * yj + b10.sum(j) * x + b11.sum(j) * x * yj;
      }
    }
    return ret;
  }
};
