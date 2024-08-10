#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0304"
//
#include "../../template/template.hpp"
//
#include "../../shortest-path/dual-of-shortest-path.hpp"

using namespace Nyaan;

string calc(int n, int c, vector<string> S) {
  using T = tuple<ll, string, ll, string, ll>;
  vector<T> cons;
  vector<int> undef;

  rep(_, c) {
    string& s = S[_];
    ll a = 0, b = 0, d = 0;
    string o, e;

    int i = 0;
    while (isdigit(s[i])) a = a * 10 + s[i++] - '0';
    while (!isdigit(s[i])) o.push_back(s[i++]);
    while (isdigit(s[i])) b = b * 10 + s[i++] - '0';
    while (!isdigit(s[i])) e.push_back(s[i++]);
    while (isdigit(s[i])) d = d * 10 + s[i++] - '0';
    --a, --b;
    cons.emplace_back(a, o, b, e, d);
    if (o == "*") undef.push_back(_);
  }

  ll ans = -1;

  for (int bt = 0; bt < (1 << undef.size()); bt++) {
    rep(i, sz(undef)) get<1>(cons[undef[i]]) = gbit(bt, i) ? ">=" : "<=";

    Dual_of_Shortest_Path<ll> g(n);
    for (auto&& [a, o, b, e, d] : cons) {
      if (o == "<=") {
        g.add_edge(b, a, 0);
        if (e == "+") {
          g.add_edge(b, a, -d);
        } else {
          g.add_edge(a, b, d);
        }
      }
      if (o == ">=") {
        g.add_edge(a, b, 0);
        if (e == "+") {
          g.add_edge(a, b, -d);
        } else {
          g.add_edge(b, a, d);
        }
      }
    }

    auto d = g.solve(0);
    if (sz(d)) {
      if (*min_element(all(d)) < 0) continue;
      amax(ans, *max_element(all(d)));
    }
  }

  if (ans > 1e18) {
    return "inf";
  } else {
    return to_string(ans);
  }
}

void Nyaan::solve() {
  {
    // https://tokoharuland.hateblo.jp/entry/2016/12/01/215953
    int n = 5, c = 4;
    vector<string> S{
        "1<=2-2",
        "4>=3-2",
        "5>=4-1",
        "5>=3+4",
    };
    assert(calc(n, c, S) == "-1"s);
  }

  ini(n, c);
  V<string> S(c);
  in(S);
  out(calc(n, c, S));
}
