#pragma once

// a/b 以下の最大の整数
long long floor(long long a, long long b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a / b - (a % b < 0);
}
// a/b 未満の最大の整数
long long under(long long a, long long b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a / b - (a % b <= 0);
}
// a/b 以上の最小の整数
long long ceil(long long a, long long b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a / b + (a % b > 0);
}
// a/b 超過の最小の整数
long long over(long long a, long long b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  return a / b + (a % b >= 0);
}
// a mod b (b > 0)
long long modulo(long long a, long long b) {
  assert(b >= 0);
  long long c = a % b;
  return c < 0 ? c + b : c;
}
