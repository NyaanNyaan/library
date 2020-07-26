#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

vector<pair<char, int>> RunLengthEncoding(string& S) {
  vector<pair<char, int>> ret;
  char c = -1;
  int n = 0;
  for (char x : S) {
    if (c == x)
      n++;
    else {
      if (n) ret.emplace_back(c, n);
      c = x, n = 1;
    }
  }
  if (n) ret.emplace_back(c, n);
  return ret;
}

template <typename T>
vector<pair<T, int>> RunLengthEncoding(vector<T>& S) {
  vector<pair<T, int>> ret;
  T c = -1;
  int n = 0;
  for (T& x : S) {
    if (c == x)
      n++;
    else {
      if (n) ret.emplace_back(c, n);
      c = x, n = 1;
    }
  }
  if (n) ret.emplace_back(c, n);
  return ret;
}