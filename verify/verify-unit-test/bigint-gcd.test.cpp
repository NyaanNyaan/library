#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
//
#include "../../math/bigint-gcd.hpp"
//
#include "../../math/bigint.hpp"
#include "../../matrix/matrix.hpp"

namespace GCDforBigintImpl {

using Mat = Matrix<bigint>;

// 下位 d 桁を除く
bigint suf(const bigint& n, int d) {
  d = min(d, (int)n.dat.size());
  return bigint{false, vector<int>{begin(n.dat) + d, end(n.dat)}};
}

// 縦ベクトル (p00, p10) を作る
Mat make_vec(const bigint& p00, const bigint& p10) {
  Mat m(2, 1);
  m[0][0] = p00, m[1][0] = p10;
  return m;
}

template <typename I>
Mat inner_naive(Mat& p) {
  assert(p[0][0] >= p[1][0]);
  assert((int)p[0][0].dat.size() <= 4);
  I g = 1;
  // solve : ax + by = gcd(a, b)
  // return : pair(x, y)
  auto extgcd = [&](auto rc, I a, I b) -> pair<I, I> {
    if (b == 0) {
      g = a;
      return make_pair(1, 0);
    }
    I x, y;
    tie(y, x) = rc(rc, b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
  };
  I a = p[0][0].to_i128(), b = p[1][0].to_i128(), x, y;
  tie(x, y) = extgcd(extgcd, a, b);
  Mat m(2);
  m[0][0] = x, m[0][1] = y;
  m[1][0] = b / g, m[1][1] = -a / g;
  return m;
}
// p_0 >= p_1, 1 手進める
void inner_succ(Mat& m, Mat& p) {
  assert(p[0][0] >= p[1][0]);
  if (p[1][0] == 0) return;
  auto [quo, rem] = divmod(p[0][0], p[1][0]);
  m[0][0] -= m[1][0] * quo;
  m[0][1] -= m[1][1] * quo;
  swap(m[0][0], m[1][0]), swap(m[0][1], m[1][1]);
  p[0][0] = p[1][0], p[1][0] = rem;
}
Mat inner_half_gcd(Mat p) {
  assert(p[0][0] >= p[1][0]);
  int n = p[0][0].dat.size(), m = p[1][0].dat.size();
  if (n <= 2) return inner_naive<long long>(p);
  if (n <= 4) return inner_naive<__int128_t>(p);
  int k = (n + 1) / 2;
  if (m <= k) return Mat::I(2);
  Mat m1 = inner_half_gcd(make_vec(suf(p[0][0], k), suf(p[1][0], k)));
  p = m1 * p;
  for (int i = 0; i < 2; i++) {
    if (p[i][0] < 0) {
      m1[i][0] = -m1[i][0], m1[i][1] = -m1[i][1], p[i][0] = -p[i][0];
    }
  }
  if (p[0][0] < p[1][0]) {
    swap(m1[0][0], m1[1][0]), swap(m1[0][1], m1[1][1]);
    swap(p[0][0], p[1][0]);
  }
  if ((int)p[1][0].dat.size() <= k) return m1;
  for (int i = 0; i < 20; i++) inner_succ(m1, p);
  if ((int)p[1][0].dat.size() <= k) return m1;
  int j = (k + 1) / 2;
  Mat m2 = inner_half_gcd(make_vec(suf(p[0][0], j), suf(p[1][0], j)));
  return m2 * m1;
}

__int128_t gcd_naive_i128(__int128_t a, __int128_t b) {
  assert(a >= 0 and b >= 0);
  while (b) swap(a %= b, b);
  return a;
}
bigint gcd_naive(bigint a, bigint b) {
  a = abs(a), b = abs(b);
  if (a < b) swap(a, b);
  while (b != bigint{}) {
    if ((int)a.dat.size() <= 4) {
      return gcd_naive_i128(a.to_i128(), b.to_i128());
    }
    swap(a %= b, b);
  }
  return a;
}

bigint gcd_half(bigint a, bigint b) {
  a = abs(a), b = abs(b);
  if (a < b) swap(a, b);
  Mat p = make_vec(a, b);
  while (p[1][0] != 0) {
    Mat m1 = inner_half_gcd(p);
    p = m1 * p;
    p[0][0].neg = p[1][0].neg = false;
    if (p[0][0] < p[1][0]) swap(p[0][0], p[1][0]);
    inner_succ(m1, p);
  }
  return p[0][0];
}

}  // namespace GCDforBigintImpl

using GCDforBigintImpl::gcd_d_ary;
using GCDforBigintImpl::gcd_half;
using GCDforBigintImpl::gcd_naive;

using namespace Nyaan;

void q() {
  {
    bigint a =
        "1234567900000000000000000000000000000000000000000000000000000000000"s;
    bigint b =
        "111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"s;
    bigint g = gcd_half(a, b);
    trc(a, b, g);
  }
  auto gen = [&](int d) {
    string S(d, '0');
    each(c, S) c += rng(0, 9);
    while (sz(S) and S[0] == '0') S.erase(begin(S));
    if (S.empty()) return bigint{};
    return bigint{S};
  };

#ifdef PROFILER
  {
    for (int d = 1; d <= 256; d *= 2) {
      V<bigint> as, bs;
      int T = 1000;
      rep(i, T) {
        as.push_back(gen(d));
        bs.push_back(gen(d));
      }

      Timer timer;
      bigint g1 = 0, g2 = 0;

      timer.reset();
      rep(i, T) g2 += gcd_d_ary(as[i], bs[i]);
      ll t2 = timer.elapsed();

      trc2(d, t2);
    }
    exit(0);
  }
#endif

  auto check = [&](bigint a, bigint b) -> void {
    bigint g1 = gcd_half(a, b);
    bigint g2 = gcd_naive(a, b);
    bigint g3 = gcd_d_ary<false>(a, b);
    bigint g4 = gcd_d_ary<true>(a, b);
    if (g1 != g2 or g2 != g3 or g3 != g4) {
      trc2(a, b);
      trc2(g1);
      trc2(g2);
      trc2(g3);
      trc2(g4);
      trc2(divmod(g3, g4));
      exit(1);
    }
    if (g1 == 0) return;
    auto [aq, ar] = divmod(a, g1);
    auto [bq, br] = divmod(b, g1);
    assert(ar == 0 and br == 0);
    assert(gcd_half(aq, bq) == 1);
    assert(gcd_naive(aq, bq) == 1);
    assert(gcd_d_ary<false>(aq, bq) == 1);
    assert(gcd_d_ary<true>(aq, bq) == 1);
  };

  rep(s, 100) rep(t, 100) {
    bigint a = s;
    bigint b = t;
    check(a, b);
    if (a != 0) check(-a, b);
    if (b != 0) check(a, -b);
    if (a != 0 and b != 0) check(-a, -b);
  }
  rep(t, 500) {
    bigint a = gen(rng(1, 100));
    bigint b = gen(rng(1, 100));
    check(a, b);
    if (a != 0) check(-a, b);
    if (b != 0) check(a, -b);
    if (a != 0 and b != 0) check(-a, -b);
  }
  rep(t, 500) {
    bigint a = gen(rng(1, 50));
    bigint b = gen(rng(1, 50));
    bigint c = gen(rng(1, 50));
    a *= c, b *= c;
    check(a, b);
    if (a != 0) check(-a, b);
    if (b != 0) check(a, -b);
    if (a != 0 and b != 0) check(-a, -b);
  }
  reg(a, 90, 110) reg(b, 90, 110) {
    string s(a + 1, '0'), t(b + 1, '0');
    s[0] = t[0] = '1';
    check(s, t);
  }

  cerr << "OK" << endl;

  // 実行時間の比較
  /**
  for (int d = 1; d <= 256; d *= 2) {
    V<bigint> as, bs;
    int T = 1000;
    rep(i, T) {
      as.push_back(gen(d));
      bs.push_back(gen(d));
    }

    Timer timer;
    bigint g1 = 0, g2 = 0, g3 = 0;

    timer.reset();
    rep(i, T) g1 += gcd_half(as[i], bs[i]);
    ll t1 = timer.elapsed();

    timer.reset();
    rep(i, T) g2 += gcd_d_ary(as[i], bs[i]);
    ll t2 = timer.elapsed();

    timer.reset();
    rep(i, T) g3 += gcd_d_ary<true>(as[i], bs[i]);
    ll t3 = timer.elapsed();

    assert(g1 == g2 and g2 == g3);
    trc2(d, t1, t2, t3);
  }
  //*/

  {
    int a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
