#pragma once

template <typename Container>
vector<int> z_algorithm(const Container& s) {
  int n = s.size();
  if(n == 0) return {};
  vector<int> a(n);
  a[0] = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i + j < n && s[j] == s[i + j]) j++;
    a[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (i + k < n && k + a[k] < j) a[i + k] = a[k], k++;
    i += k, j -= k;
  }
  return a;
}

/**
 * @brief Z algorithm
 */
