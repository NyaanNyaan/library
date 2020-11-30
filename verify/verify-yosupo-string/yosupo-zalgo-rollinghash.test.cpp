#include "../../template/template.hpp"
//
#include "../../string/rolling-hash.hpp"
//
using namespace Nyaan;
void Nyaan::solve() {
  string s;
  in(s);
  RollingHash<string,2> rori(s);
  vi ans(sz(s));
  rep(i,sz(s))ans[i]=LCP(rori,rori,0,i);
  out(ans);
}
