#pragma once

// enumerate x : x \subset b
vector<int> enumerate_subset(int b) {
  vector<int> res;
  for (int i = b; i >= 0; --i) res.push_back(i &= b);
  return res;
};

// enumerate x : x \in {n} and x \superset b
vector<int> enumerate_superset(int b, int n) {
  vector<int> res;
  for (int i = b; i < (1 << n); i = (i + 1) | b) res.push_back(i);
  return res;
}

/**
 * @brief 下位集合/上位集合の列挙
 */
