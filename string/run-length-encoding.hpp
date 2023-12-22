#pragma once

template <typename C>
vector<pair<typename C::value_type, int>> RunLengthEncoding(const C& S) {
  using T = typename C::value_type;
  if (S.empty()) return {};
  vector<pair<T, int>> ret;
  T c = S[0];
  int n = 1;
  for (int i = 1; i < (int)S.size(); i++) {
    if (S[i] == c)
      n++;
    else {
      ret.emplace_back(c, n);
      c = S[i], n = 1;
    }
  }
  ret.emplace_back(c, n);
  return ret;
}

/**
 * @brief Run Length Encoding(連長圧縮)
 */
