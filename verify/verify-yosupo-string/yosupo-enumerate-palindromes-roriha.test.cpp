#include "../../template/template.hpp"
//
#include "../../string/rolling-hash.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  string s;
  in(s);
  {
    string b;
    b.push_back('$');
    rep(i, sz(s)) {
      b.push_back(s[i]);
      b.push_back('$');
    }
    swap(s, b);
  }
  auto t = s;
  reverse(all(t));
  roriha rs(s), rt(t);
  int n = sz(s);
  vi ans(n);
  rep(i, n) {
    int ok = 0;
    int ng = min<int>(i, n - 1 - i) + 1;
    while (ok + 1 < ng) {
      int med = (ok + ng) >> 1;
      int l = i - med;
      int r = i + med;
      auto h1 = rs.get(l, r + 1);
      auto h2 = rt.get(n - 1 - r, n - l);
      (h1 == h2 ? ok : ng) = med;
    }
    ans[i] = ok;
  }
  ans.erase(begin(ans));
  ans.pop_back();
  out(ans);
}
