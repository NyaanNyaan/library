#pragma once
#include <bits/stdc++.h>
using namespace std;

// DS ... pointer ?
// T ... value_type
template <typename DS, typename T>
struct FractionalCascading {
  using NEW = function<DS(void)>;
  using ADD = function<void(DS&, int, const T&)>;
  using SUM = function<T(DS&, int, int)>;

  int N, M;
  const NEW ds_new;
  const ADD ds_add;
  const SUM ds_sum;
  vector<DS> dat;

  FractionalCascading(int n, int m, const NEW& nw, const ADD& ad, const SUM& sm)
      : N(n), M(m), ds_new(nw), ds_add(ad), ds_sum(sm) {
    for (int i = 0; i < N; i++) dat.push_back(ds_new);
  }

  
};
