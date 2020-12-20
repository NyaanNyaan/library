#pragma once

// Black Algorithm
// http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html
template <typename T>
struct BlackAlgorithm {
  using i64 = long long;
  i64 N, sq, s;
  T ans;
  vector<i64> p, ns, pi;

  BlackAlgorithm(i64 _n) : N(_n), sq(sqrt(N)), ans(T()) {
    assert(N > 0);
    // p
    auto prime = prime_enumerate(sq);
    for (auto &x : prime) p.push_back(x);
    // ns
    ns.push_back(0);
    for (i64 i = N; i > 0; i = div(N, div(N, i) + 1)) ns.push_back(i);
    s = ns.size();
    // pi
    pi = ns;
    for (auto &x : pi) --x;
    for (auto &x : p) {
      i64 x2 = x * x, c = pi[s - x + 1];
      for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i])
        pi[i] -= pi[i * x <= sq ? i * x : s - div(n, x)] - c;
    }
  }

  i64 div(i64 a, i64 b) { return double(a) / b; }
  int idx(i64 n) {
    assert(n > 0);
    return n <= sq ? s - n : div(N, n);
  }

  /**
   * 現在n = (v*p[i]^c)のノードにいる
   * lim = N / n, fv = f(v)
   *
   * 子のノードは(現在のノード * p[i]) ~ (現在のノード * lim)
   * (現在のノード * p[i])はnと互いに素でないため別に計算する
   * それ以外は (limまでの累積和) -
   * (p[i]までの累積和)を上手く利用してまとめて処理
   *
   * 進んでよいノードはp[j] * p[j] <= limを満たすp[j]
   */

  T run() {

  }

  void dfs(int i, int c, i64 v, i64 lim, T fv) {
    // v * p[i] ^ (c + 1)を処理

    // p[i]倍の子に進む
    if (lim >= p[i] * p[i]) dfs(i, c + 1, p[i] * v, lim / p[i], fv);
    // fvをf(v * p[i] ^ c)に更新

    // p[i+1]倍～lim倍の子を計算

    // 進んでよいノードに進む
    for (int j = i + 1; j < s && p[j] * p[j] <= lim; j++)
      dfs(j, 1, p[j], lim / p[j], fv);
  }
};
