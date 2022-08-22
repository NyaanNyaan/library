#pragma once
#include <algorithm>
using namespace std;

#include "line-container.hpp"

struct LineContainer2D {
  using ld = long double;
  using ll = long long;

  ld Xmax, Xmin, Ymax, Ymin;
  static constexpr ld INF = 4.1e18;
  MinLineContainer<ld> minlc;
  MaxLineContainer<ld> maxlc;
  LineContainer2D() : Xmax(-INF), Xmin(INF), Ymax(-INF), Ymin(INF) {}

  void add(ld x, ld y) {
    Xmax = max(Xmax, x), Xmin = min(Xmin, x);
    Ymax = max(Ymax, y), Ymin = min(Ymin, y);
    minlc.add(y, x), maxlc.add(y, x);
  }

  ld max_ld(ld a, ld b) {
    if (a == 0) return b * (b > 0 ? Ymax : Ymin);
    if (b == 0) return a * (a > 0 ? Xmax : Xmin);
    ld c = b / a;
    if (a > 0) {
      auto l = maxlc.lower_bound(c);
      ld x = l->m, y = l->k;
      return a * x + b * y;
    } else {
      auto l = minlc.lower_bound(c);
      ld x = -l->m, y = -l->k;
      return a * x + b * y;
    }
  }
  ld min_ld(ld a, ld b) { return -max_ld(-a, -b); }
  ll max_ll(ll a, ll b) { return round(clamp<ll>(max_ld(a, b), -INF, INF)); }
  ll min_ll(ll a, ll b) { return round(clamp<ll>(min_ld(a, b), -INF, INF)); }

 private:
  ll round(ld a) { return a >= 0.0 ? a + 0.5 : a - 0.5; }
};

/**
 * @brief Line container (for max(ax + by) query)
 */
