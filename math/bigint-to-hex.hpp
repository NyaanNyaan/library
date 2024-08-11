#pragma once

#include <map>
#include <string>
#include <vector>
using namespace std;

#include "bigint.hpp"

// hex to bigint
bigint HtoB(string S) {
  int neg = 0;
  if (S[0] == '-') neg = 1, S.erase(begin(S));

  map<int, bigint> memo;

  auto power = [&](int e) {
    bigint res = 1, x = 16;
    for (; e; e >>= 1, x *= x) {
      if (e & 1) res *= x;
    }
    return res;
  };
  auto pow16 = [&](int e) {
    if (memo.count(e)) return memo[e];
    return memo[e] = power(e);
  };
  auto dfs = [&](auto rc, int l, int r) -> bigint {
    if (l + 1 == r) {
      if ('0' <= S[l] and S[l] <= '9') return S[l] - '0';
      if ('A' <= S[l] and S[l] <= 'F') return S[l] - 'A' + 10;
      return S[l] - 'a' + 10;
    }
    int m = (l + r) / 2;
    auto L = rc(rc, l, m);
    auto R = rc(rc, m, r);
    return L * pow16(r - m) + R;
  };
  bigint res = dfs(dfs, 0, S.size());
  if (neg) res.neg = true;
  return res;
}

// bigint to hex
string BtoH(bigint x) {
  if (x.neg) return "-" + BtoH(-x);
  if (x < 16) {
    if (x < 10) return string(1, '0' + x.to_ll());
    return string(1, 'A' + x.to_ll() - 10);
  }
  static vector<bigint> ys{16};
  int log_e = 0;
  while (true) {
    if (log_e + 1 == (int)ys.size()) ys.push_back(ys.back() * ys.back());
    if (ys[log_e + 1] > x) break;
    log_e++;
  }
  int e = 1 << log_e;
  bigint y = ys[log_e];
  bigint q = x / y;
  bigint r = x - q * y;
  string hi = BtoH(q);
  string lo = BtoH(r);
  return hi + string(e - lo.size(), '0') + lo;
}
