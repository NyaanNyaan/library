#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_hex_big_integers"
//
#include "../../template/template.hpp"
//
#include "../../math/bigint-binary.hpp"
//
using namespace Nyaan;

void q() {
  ins(S, T);
  BinaryBigInt A{S, 16};
  BinaryBigInt B{T, 16};
  auto C = A * B;
  out(C.to_hex());
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}
