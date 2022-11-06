#define PROBLEM "https://yukicoder.me/problems/no/303"
//
#include "../../template/template.hpp"
//
#include "../../math/multiprecision-integer.hpp"
//
#include "../../matrix/matrix-fast.hpp"

using namespace Nyaan;
using Mat = Matrix<bigint, 2, 2>;

// a^n
template <typename T, typename U>
T power(const T& a, U n, const T& I) {
  assert(n >= 0);
  if (n == 0) return I;
  T half = power(a, n / 2, I);
  T res = half * half;
  return n % 2 ? res * a : res;
}

void Nyaan::solve() {
  int l;
  cin >> l;
  if (l == 2) die("3\nINF");
  cout << l << endl;
  Mat A, I;
  A[0][0] = A[0][1] = A[1][0] = 1;
  I[0][0] = I[1][1] = 1;
  if (l & 1) {
    cout << power(A, l, I)[1][0] << endl;
  } else {
    auto B = power(A, l / 2, I);
    auto X = (B * B)[1][0];
    auto Y = B[1][0];
    cout << X - Y * Y << endl;
  }
}
