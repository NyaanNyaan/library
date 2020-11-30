#pragma once
#include <bits/stdc++.h>
using namespace std;

long long floor(long long a,long long b) {
  assert(b > 0);
  return (a / b) - (a < 0 && !!(a % b));
}

long long ceil(long long a,long long b) {
  assert(b > 0);
  return (a / b) + (a > 0 && !!(a % b));
}
