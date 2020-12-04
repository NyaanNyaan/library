#pragma once



#include "factor-enumerate.hpp"

template<int MAX>
vector<int> osak(int n){
  static vector<int> f = factor_enumerate(MAX);
  vector<int> ret;
  while(f[n]) ret.push_back(f[n]), n /= f[n];
  return ret;
}