#define PROBLEM "https://yukicoder.me/problems/no/2661"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-compositional-inverse.hpp"
#include "../../fps/newton-method.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  inl(N, K, M);
  vl X(M);
  in(X);

  /**
   * f = x + f^K / (1 - f^{K-1})
   * g = 2 f - x
   * g(h(x)) = x
   * としたとき
   * [x^N] g^k = k/N [x^{N-k}] (x/h)^N
   * を k について列挙 -> h が分かれば解ける
   *
   * Easy : K=2 のときは f = (x + g) / 2 を代入して
   * x = g (1 - g) / (1 + g) を得られる
   * -> h = x (1 - x) / (1 + x) になる
   * K 一般では h = F(g) 型で表すのは困難
   *
   * A(h) := g(h(x)) - x = 0 とする
   * -> FPS s に対して A(s) = g(s) - x = 2 f(s) - s - x
   * が高速に計算できればニュートン法できる
   * (自分の代入逆元ライブラリでは g(s) を引数に取るのに注意する)
   *
   * given s, calc f(s) をしたい。t = f(s) とおくと t は
   * t = s + t^K / (1 - t^{K-1})
   * B(t) = t^K / (1 - t^{K-1}) - t + s = 0
   * なのでニュートン法できる
   * ([x^0]A(s) = 0 が必要 -> [x^0]t = 0 がニュートン法の初期解)
   */

  fps h = compositional_inverse<fps>(
      [&](fps s, int deg) -> fps {
        fps fs = newton_method<fps>(
            [&](fps t, int deg2) -> pair<fps, fps> {
              // B(t) = t^K / (1 - t^{K-1}) - t + s
              t = t.pre(deg2);
              fps t_pow_Km1 = t.pow(K - 1);
              fps t_pow_K = (t_pow_Km1 * t).pre(deg2);

              fps inv = (fps{1} - t_pow_Km1).inv();
              fps Bt = t_pow_K * inv - t + s;

              // B'(t)
              // = K t^{K-1} / (1 - t^{K-1})
              // + (K-1) t^{2K-2} / (1 - t^{K-1})^2
              // - 1
              fps dBdt;
              dBdt += t_pow_Km1 * K * inv;
              dBdt += (t_pow_Km1 * t_pow_Km1).pre(deg2) * (K - 1) *
                      (inv * inv).pre(deg2);
              dBdt -= fps{1};

              return mkp(Bt.pre(deg2), dBdt.pre(deg2));
            },
            fps{0}, deg);
        return (fs * 2 - s).pre(deg);
      },
      N + 2);

  fps ans = (h >> 1).inv().pow(N);
  each(k, X) out(ans[N - k] * k / N);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
