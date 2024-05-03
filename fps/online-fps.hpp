#pragma once

#include <cassert>
#include <functional>
#include <vector>
using namespace std;

#include "../modint/montgomery-modint.hpp"
#include "../modulo/binomial.hpp"
#include "ntt-friendly-fps.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

struct ofpsBase {
  using ob = ofpsBase;
  function<mint(int)> func;
  fps f;
  ofpsBase() {
    func = [](int) -> mint { return 0; };
  }
  ofpsBase(const fps& _f) : f(_f) {
    func = [this](int i) { return i < (int)f.size() ? f[i] : 0; };
  }
  ofpsBase(function<mint(int)> _func) : func(_func) {}

  ofpsBase(const ob& rhs) = delete;
  ob& operator=(const ob& rhs) = delete;
  ofpsBase(ob&& rhs) noexcept = delete;
  ob& operator=(ob&& rhs) noexcept = delete;

  void set_corner(const fps& _f) { f = _f; }
  void set_func(function<mint(int)> _func) { func = _func; }

  mint get(int i) {
    while ((int)f.size() <= i) f.push_back(func(f.size()));
    return f[i];
  }
  ob integral() {
    return ob{[this](int i) { return i == 0 ? 0 : get(i - 1) / i; }};
  }
  ob diff() {
    return ob{[this](int i) { return get(i + 1) * (i + 1); }};
  }
  ob operator>>(int s) {
    return ob{[this, s](int i) { return get(i + s); }};
  }
  ob operator<<(int s) {
    return ob{[this, s](int i) { return i < s ? 0 : get(i - s); }};
  }
  friend ob _dot(ob& a, ob& b) {
    return ob{[&a, &b](int i) { return a.get(i) * b.get(i); }};
  }
  friend ob operator+(ob& a, ob& b) {
    return ob{[&a, &b](int i) { return a.get(i) + b.get(i); }};
  }
  friend ob operator-(ob& a, ob& b) {
    return ob{[&a, &b](int i) { return a.get(i) - b.get(i); }};
  }
  friend ob operator*(ob& a, mint b) {
    return ob{[&a, b](int i) { return a.get(i) * b; }};
  }
  friend ob operator*(mint b, ob& a) {
    return ob{[&a, b](int i) { return a.get(i) * b; }};
  }
};

struct ofpsMul : public ofpsBase {
  vector<mint> a, b, c;
  fps F, G;
  vector<fps> as, bs;

  ofpsMul(ob& _a, ob& _b) {
    func = [&_a, &_b, this](int idx) -> mint {
      while ((int)a.size() <= idx) {
        int q = a.size();
        a.push_back(_a.get(q)), b.push_back(_b.get(q));
        if ((int)c.size() <= q) c.resize(q + 1);
        c[q] += a[q] * b[0] + (q ? b[q] * a[0] : 0);

        auto precalc = [&](int lg) {
          if ((int)as.size() <= lg) as.resize(lg + 1), bs.resize(lg + 1);
          if (!as[lg].empty()) return;
          int d = 1 << lg;
          fps s{begin(a), begin(a) + d * 2};
          fps t{begin(b), begin(b) + d * 2};
          s.ntt(), t.ntt();
          as[lg] = s, bs[lg] = t;
        };
        q++;
        for (int d = 1, lg = 0; d <= q; d *= 2, lg++) {
          if (q % (2 * d) != d) continue;
          if (q == d) {
            F.assign(2 * d, mint{});
            G.assign(2 * d, mint{});
            for (int i = 0; i < d; i++) F[i] = a[i];
            for (int i = 0; i < d; i++) G[i] = b[i];
            F.ntt(), G.ntt();
            for (int i = 0; i < d * 2; i++) F[i] *= G[i];
            F.intt();
            if ((int)c.size() < q + d) c.resize(q + d);
            for (int i = q; i < q + d; i++) c[i] += F[d + i - q];
          } else {
            precalc(lg);
            F.assign(2 * d, mint{});
            G.assign(2 * d, mint{});
            for (int i = 0; i < d; i++) F[i] = a[q - d + i];
            for (int i = 0; i < d; i++) G[i] = b[q - d + i];
            F.ntt(), G.ntt();
            fps& s = as[lg];
            fps& t = bs[lg];
            for (int i = 0; i < d * 2; i++) F[i] = F[i] * t[i] + G[i] * s[i];
            F.intt();
            if ((int)c.size() < q + d) c.resize(q + d);
            for (int i = q; i < q + d; i++) c[i] += F[d + i - q];
          }
        }
      }
      return c[idx];
    };
  }
};

struct ofpsInv : public ofpsBase {
  mint oi;
  ob& a;
  ob b;
  ofpsMul s;
  ofpsInv(ob& _a)
      : a(_a), b([this](int j) { return a.get(j + 1); }), s(b, *this) {
    func = [this](int j) -> mint {
      assert(a.get(0) != 0);
      if (j == 0) return oi = a.get(0).inverse();
      get(0);
      return j ? s.get(j - 1) * -oi : oi;
    };
  }
};

struct ofpsExp : public ofpsBase {
  ob& a;
  ob b;
  ofpsMul m;
  ofpsExp(ob& _a)
      : a(_a),
        b([this](int i) { return a.get(i + 1) * (i + 1); }),
        m(b, *this) {
    func = [this](int i) { return i == 0 ? 1 : m.get(i - 1) / i; };
  }
};

struct OnlineFormalPowerSeries {
  using ob = ofpsBase;
  using ofps = OnlineFormalPowerSeries;

  ob* p;
  OnlineFormalPowerSeries() : p(new ob()) {}
  OnlineFormalPowerSeries(const fps& f) : p(new ob(f)) {}
  OnlineFormalPowerSeries(ob* q) : p(q) {}

  void set_corner(const fps& f) { p->set_corner(f); }
  void set(const ofps& f) { p->set_func(f.p->func); }

  mint operator[](int i) { return p->get(i); }
  fps pre(int n) {
    p->get(n - 1);
    return p->f.pre(n);
  }

  ofps integral() { return new ob{p->integral()}; }
  ofps diff() { return new ob{p->diff()}; }
  ofps operator>>(int s) { return new ob{(*p) >> s}; }
  ofps operator<<(int s) { return new ob{(*p) << s}; }
  friend ofps dot(ofps a, ofps b) { return new ob{_dot(*a.p, *b.p)}; }
  friend ofps operator+(ofps a, ofps b) { return new ob{*a.p + *b.p}; }
  friend ofps operator-(ofps a, ofps b) { return new ob{*a.p - *b.p}; }
  friend ofps operator*(ofps a, mint b) { return new ob{*a.p * b}; }
  friend ofps operator*(mint a, ofps b) { return new ob{a * *b.p}; }
  ofps operator-() { return new ob{*p * -1}; }

  friend ofps operator*(ofps a, ofps b) { return new ofpsMul{*a.p, *b.p}; }
  friend ofps operator/(ofps a, ofps b) {
    ofps invb = b.inv();
    return new ofpsMul{*a.p, *invb.p};
  }
  ofps inv() { return new ofpsInv{*p}; }
  ofps exp() { return new ofpsExp{*p}; }
  ofps log() { return (this->diff() / *this).integral(); }
};

using ofps = OnlineFormalPowerSeries;
