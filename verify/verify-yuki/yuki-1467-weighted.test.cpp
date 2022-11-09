#define PROBLEM "https://yukicoder.me/problems/no/1467"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/slope-trick-weighted.hpp"

using namespace Nyaan;

/*

// https://atcoder.jp/contests/abc127/tasks/abc127_f
void ABC127F() {
  ini(Q);
  SlopeTrick st;
  rep(i, Q) {
    ini(c);
    if (c == 1) {
      inl(a, b);
      st.add_abs_xma(a);
      st.shift_y(b);
    } else {
      out(st.get_min());
    }
  }
}

// https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e
void dwacon2016qual_E() {
  ini(N, L);
  vvi ls(TEN(5) + 10);
  rep(i, N) {
    ini(t, l);
    ls[t].push_back(l);
  }
  SlopeTrick st;
  rep(i, sz(ls)) {
    if (ls.empty()) continue;
    st.chmin_right();
    each(x, ls[i]) st.add_abs_xma(x);
  }
  out(st.get_min().second);
}

// https://atcoder.jp/contests/utpc2012/tasks/utpc2012_12
void utpc2012_L() {
  ini(N, C0);
  vl C(N);
  C[0] = C0;
  vvi g(N);
  rep1(i, N - 1) {
    ini(p, c);
    --p;
    g[p].push_back(i);
    C[i] = c;
  }
  auto dfs = [&](auto rc, int c) -> SlopeTrick {
    SlopeTrick st;
    each(d, g[c]) {
      SlopeTrick stc = rc(rc, d);
      stc.shift_x(1);
      st.merge(stc);
    }
    st.add_abs_xma(C[c]);
    st.chmin_right();
    return move(st);
  };
  out(dfs(dfs, 0).get_min().second);
}

// https://atcoder.jp/contests/arc070/tasks/arc070_c
void ARC070C() {
  inl(N);
  vl a(N), b(N);
  in2(a, b);
  SlopeTrick st;
  rep(i, N) {
    if (i) {
      st.shift_L(a[i] - b[i]);
      st.shift_R(b[i - 1] - a[i - 1]);
    }
    st.add_abs_xma(a[i]);
  }
  out(st.get_min().second);
}

#include "../../segment-tree/segment-tree.hpp"

// https://atcoder.jp/contests/abc275/tasks/abc275_h
void ABC275Ex() {
  inl(N);
  vl A(N), B(N);
  in(A, B);
  vp init(N);
  rep(i, N) init[i] = {B[i], i};
  SegmentTree seg(
      init, [](pl a, pl b) { return max(a, b); }, pl{-infLL, -1});
  i128 ans = 0;
  auto dfs = [&](auto rc, int l, int r) -> SlopeTrick {
    if (l == r) return {};
    auto [v, m] = seg.query(l, r);
    SlopeTrick L = rc(rc, l, m + 0);
    SlopeTrick R = rc(rc, m + 1, r);
    L.merge(R);
    L.add_amx(A[m], infLL);
    L.add_xma(0, v);
    L.chmin_left();
    L.add_amx(inf, v);
    ans += -ll(inf) * v;
    return L;
  };
  auto f0 = dfs(dfs, 0, N);
  out(ans + f0.eval(0));
}

void ABC217H() {
  inl(N);
  SlopeTrick st;
  st.add_abs_xma(0, 1e6);
  ll last = 0;
  rep(i, N) {
    inl(t, d, x);
    st.shift_L(-(t - last));
    st.shift_R(t - last);
    last = t;
    if (d == 0) {
      st.add_amx(x);
    } else {
      st.add_xma(x);
    }
  }
  out(st.get_min().second);
}

*/

// https://yukicoder.me/problems/no/1467
void yuki1467() {
  ini(M, N);
  vl A(M), B(N);
  in(A, B);
  vl zip{A};
  each(x, B) zip.push_back(x);
  zip = mkuni(zip);
  vl as(sz(zip)), bs(sz(zip));
  each(x, A) as[lb(zip, x)]++;
  each(x, B) bs[lb(zip, x)]++;
  rep1(k, M) {
    SlopeTrick st;
    st.add_amx(0, TEN(10));
    rep(i, sz(zip)) {
      st.shift_x(as[i] - bs[i] * k);
      st.chmin_right();
      if (i != sz(zip) - 1) {
        st.add_abs_xma(0, zip[i + 1] - zip[i]);
      } else {
        st.add_xma(0, 1e10);
      }
    }
    out(ll(st.get_min().second));
    st.clear();
  }
}

void Nyaan::solve() {
  // ABC127F();
  // dwacon2016qual_E();
  // utpc2012_L();
  // ARC070C();
  yuki1467();
  // ABC275Ex();
  // ABC217H();
}
