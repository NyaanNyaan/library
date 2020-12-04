#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../../template/template.hpp"
#include "../../math/elementary-function.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  auto factor = PrimeFactors(N);
  vi ans;
  each(p,factor) rep(_,p.second)ans.push_back(p.first);
  cout << N << ":";
  each(x,ans)cout<< " " << x;
  cout << endl;
}