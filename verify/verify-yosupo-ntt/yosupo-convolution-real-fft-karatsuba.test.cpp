#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../ntt/real-fft.hpp"

void Nyaan::solve() {
  using namespace ArbitraryModConvolution;
  int N, M;
  rd(N, M);
  vector<int> a(N), b(M);
  for (auto& x : a) rd(x);
  for (auto& x : b) rd(x);

  // auto c = toom_3<1000000007>(a, b);
  auto c = CooleyTukey::karatsuba<1000000007>(a, b);
  for (int i = 0; i < N + M - 1; i++) {
    wt(c[i], " \n"[i == N + M - 2]);
  }
}