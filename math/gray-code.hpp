#pragma once



vector<int> gray_code(int n) {
  vector<int> ret(1 << n);
  for (int i = 0; i < (int)ret.size(); i++) ret[i] = i ^ (i >> 1);
  return ret;
};

/**
 * @brief Gray code
 */ 
