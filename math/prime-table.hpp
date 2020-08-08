#pragma once
#include <bits/stdc++.h>
using namespace std;

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> PrimeTable(int N) {
  vector<bool> sieve(N / 2 + 1, 1);
  for (int p = 5, d = 4, p2 = p * p;; p += d = 6 - d) {
    if ((p2 = p * p) > N) break;
    if (!sieve[p >> 1]) continue;
    for (int q = p2, r = d * p, s = 6 * p; q <= N; q += r = s - r)
      sieve[q >> 1] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4; p <= N; p += d = 6 - d)
    if (sieve[p >> 1]) ret.push_back(p);
  while (ret.back() > N) ret.pop_back();
  return ret;
}