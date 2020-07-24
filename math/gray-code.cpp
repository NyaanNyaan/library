#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

vector<int> gray_code(int n) {
  if (n == 1) return vi{0, 1};
  vi ret = gray_code(n - 1);
  vi inv = ret;
  reverse(all(inv));
  each(x, inv) x |= 1 << (n - 1);
  copy(all(inv), back_inserter(ret));
  return ret;
};