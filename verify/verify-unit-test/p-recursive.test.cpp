#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/find-p-recursive.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

void test(const vector<mint>& a, int p, int d) {
  vector<mint> pre{begin(a), begin(a) + p};

  auto coeff = find_p_recursive<mint>(pre, d);
  int k = coeff.size() - 1;
  rep(i, sz(coeff)) {
    coeff[i].shrink();
    if (i >= 2) cerr << " + ";
    if (i) coeff[i] = -coeff[i];
    if (coeff[i] != fps{1}) {
      if (sz(coeff[i]) > 1) cerr << "(";
      for (int j = sz(coeff[i]); j--;) {
        mint m = coeff[i][j];
        if (j == 0 or m != 1) cerr << m;
        if (j) cerr << "k";
        if (j >= 2) cerr << "^" << j;
        if (j) cerr << " + ";
      }
      cerr << " )"[sz(coeff[i]) > 1];
    }
    cerr << "a_{k";
    if (i != k) cerr << "+" << (k - i);
    cerr << "}";
    if (i == 0) cerr << " = ";
  }
  cerr << endl;

  rep(i, sz(a)) {
    auto b = kth_term_of_p_recursive<mint>(pre, i, d);
    assert(b == a[i]);
  }
}

void verify(int N) {
  Binomial<mint> C;

  // constant function
  {
    cerr << "Constant Function" << endl;
    vector<mint> a(N, mint(1));
    test(a, 4, 0);
  }

  // Identity function
  // (導出方法の関係上a_0 = 0のときは上手くいかないのでa_1=1から始める)
  {
    cerr << "Identity Function" << endl;
    vector<mint> a(N);
    rep(i, N) a[i] = i;
    a.erase(begin(a));
    test(a, 4, 1);
  }

  // factorial
  {
    cerr << "Factorial" << endl;
    vector<mint> fac(N);
    fac[0] = 1;
    reg(i, 1, N) fac[i] = fac[i - 1] * i;
    test(fac, 4, 1);
  }

  // inversion of Factorial
  {
    cerr << "Inversion of Factorial" << endl;
    vector<mint> finv(N);
    finv[0] = 1;
    reg(i, 1, N) finv[i] = finv[i - 1] / i;
    test(finv, 4, 1);
  }

  // Binomial (binomial(i+3, 3))
  {
    cerr << "Binomial" << endl;
    vector<mint> c(N);
    rep(i, N) c[i] = C.C(i + 3, 3);
    test(c, 4, 1);
  }

  // Montmort Number
  {
    cerr << "Montmort Number" << endl;
    vector<mint> montmort(N);
    montmort[0] = 1, montmort[1] = 0;
    reg(i, 2, N) montmort[i] = (montmort[i - 1] + montmort[i - 2]) * (i - 1);
    test(montmort, 7, 1);
  }

  // Catalan Number
  {
    cerr << "Catalan Number" << endl;
    vector<mint> cat(N);
    rep(i, N) cat[i] = C.fac(2 * i) * C.finv(i + 1) * C.finv(i);
    test(cat, 4, 1);
  }

  // Motzkin Number
  {
    cerr << "Motzkin Number" << endl;
    vector<mint> m(N);
    m[0] = m[1] = 1;
    reg(i, 2, N) m[i] =
        (m[i - 1] * (2 * i + 1) + m[i - 2] * (3 * i - 3)) / (i + 2);
    test(m, 7, 1);
  }

  // Schroder number
  {
    cerr << "Schroder number" << endl;
    vector<mint> s(N);
    s[0] = 1, s[1] = 2;
    reg(i, 2, N) {
      s[i] = s[i - 1] * 3;
      reg(k, 1, i - 1) s[i] += s[k] * s[i - k - 1];
    }
    test(s, 7, 1);
  }

  // power
  {
    cerr << "[x^k] f(x)^n" << endl;
    fps f(N);
    rep(i, 5) f[i] = i + 1;
    f = f.pow(1234567);
    test(vector<mint>{begin(f), end(f)}, 13, 1);
  }

  // test(degree = 5)
  {
    cerr << "degree = 5" << endl;
    vector<mint> a(N);
    a[0] = a[1] = a[2] = a[3] = a[4] = 1;
    reg(i, 5, N) {
      a[i] += a[i - 5] * (i + 1) * (i + 2) * (i + 3) * (i + 4) * (i + 5);
      a[i] += a[i - 4] * (i + 1) * (i + 2) * (i + 3) * (i + 4);
      a[i] += a[i - 3] * (i + 1) * (i + 2) * (i + 3);
      a[i] += a[i - 2] * (i + 1) * (i + 2);
      a[i] += a[i - 1] * (i + 1);
    }
    test(a, 40, 5);
  }
}

void Nyaan::solve() {
  verify(100);

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}