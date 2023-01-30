#pragma once

#include <vector>
using namespace std;

template <typename Container>
vector<int> manacher(const Container& S) {
  vector<int> res(S.size());
  int i = 0, j = 0;
  while (i < int(S.size())) {
    while (i - j >= 0 and i + j < int(S.size()) and S[i - j] == S[i + j]) j++;
    res[i] = j;
    int k = 1;
    while (i - k >= 0 and i + k < int(S.size()) and k + res[i - k] < j)
      res[i + k] = res[i - k], k++;
    i += k, j -= k;
  }
  return res;
}

// 中心軸を固定したときの各軸に対して極大な回文を左から列挙(空文字列を含む)
template <typename Container>
vector<pair<int, int>> enumerate_palindromes(const Container& vec) {
  using T = typename Container::value_type;
  vector<T> v;
  const int N = vec.size();
  for (int i = 0; i < N - 1; i++) {
    v.push_back(vec[i]);
    v.push_back(-1);
  }
  v.push_back(vec.back());
  const auto man = manacher(v);
  vector<pair<int, int>> ret;
  for (int i = 0; i < N * 2 - 1; i++) {
    if (i & 1) {
      int w = man[i] / 2;
      ret.emplace_back((i + 1) / 2 - w, (i + 1) / 2 + w);
    } else {
      int w = (man[i] - 1) / 2;
      ret.emplace_back(i / 2 - w, i / 2 + w + 1);
    }
  }
  return ret;
}

// ret[r] : s[l, r] が回文である最小の l
template <typename Container>
vector<int> enumerate_leftmost_palindromes(const Container& vec) {
  vector<int> v(vec.size(), 1);
  for (auto& [l, r] : enumerate_palindromes(vec)) {
    v[r - 1] = max(v[r - 1], r - l);
  }
  for (int i = (int)vec.size() - 2; i >= 0; i--) v[i] = max(v[i], v[i + 1] - 2);
  vector<int> ret(vec.size());
  for (int i = 0; i < (int)vec.size(); i++) ret[i] = i + 1 - v[i];
  return ret;
}

/**
 * @brief Manacher's algorithm
 */
