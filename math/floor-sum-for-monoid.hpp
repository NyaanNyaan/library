#pragma once

// y^f(0) x y^(f(1)-f(0)) ... x y^(f(n)-f(n-1)) を計算
// f(n) = floor((an + b) / m)
// [0,n] 閉区間に注意
//
// イメージ:
// y=(ax+b)/m が x,y=(整数) と交わる過程に対応している, すなわち次の通り
// (0,0) からスタート, また I を持っている
// まず (0,f(0)) まで移動, 移動するたびに y を掛ける
// その後 x=1,2,...,N について次の操作を行う
// - (x-1,f(x-1)) -> (x, f(x-1)) に移動, 移動ごとに x を掛ける
// - (x, f(x-1)) -> (x, f(x)) に移動, 移動ごとに y を掛ける
template <typename T, typename Int>
T floor_sum_for_monoid(Int n, Int m, Int a, Int b, T x, T y, T I) {
  assert(m >= 1 and a >= 0 and b >= 0 and n >= 0);
  auto my_pow = [&I](T z, Int e) {
    T res = I;
    while (e) {
      if (e & 1) res = res * z;
      z = z * z;
      e >>= 1;
    }
    return res;
  };
  Int c = (a * n + b) / m;
  T pre = I, suf = I;
  while (true) {
    Int p = a / m, q = b / m;
    a %= m, b %= m;
    x = x * my_pow(y, p), pre = pre * my_pow(y, q);
    if ((c -= p * n + q) == 0) break;
    Int d = (m * c - b - 1) / a + 1;
    suf = y * my_pow(x, n - d) * suf;
    b = m - b - 1 + a, n = c - 1, c = d;
    swap(m, a), swap(x, y);
  }
  return pre * my_pow(x, n) * suf;
}
