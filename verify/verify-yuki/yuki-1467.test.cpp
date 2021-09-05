#define PROBLEM "https://yukicoder.me/problems/no/1467"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/slope-trick.hpp"

using namespace Nyaan;

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
    out(st.get_min().second);
  }
}

void Nyaan::solve() {
  // ABC127F();
  // dwacon2016qual_E();
  // utpc2012_L();
  yuki1467();
}
