#define PROBLEM "https://yukicoder.me/problems/no/886"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../multiplicative-function/gcd-convolution.hpp"
//

using namespace Nyaan;
void Nyaan::solve() {
  inl(H, W);
  int N = max(H, W);
  vector<mint> a(N + 1, 0), b(N + 1, 0);
  mint ans = H * (W - 1) + W * (H - 1);
  rep1(i, H) a[i] = H - i;
  rep1(i, W) b[i] = W - i;
  auto c = gcd_convolution(a, b);
  out(ans + c[1] * 2);
}
