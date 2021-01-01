#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0077"
//
#include "../../template/template.hpp"
//
#include "../../string/run-length-encoding.hpp"

using namespace Nyaan;

string rev(vector<pair<char, int>>& rle) {
  string res;
  for (auto&& [c, n] : rle) res += string(n, c);
  return res;
}

void Nyaan::solve() {
  string s;
  while (cin >> s) {
    vector<pair<char, int>> rle;
    for (int i = 0; i < sz(s);) {
      if (s[i] == '@') {
        int n = s[i + 1] - '0';
        char c = s[i + 2];
        rle.emplace_back(c, n);
        i += 3;
      } else {
        rle.emplace_back(s[i], 1);
        i += 1;
      }
    }
    string ans = rev(rle);
    auto rle2 = RunLengthEncoding(ans);
    assert(rle == rle2);
    vector<char> buf;
    each(c, ans) buf.push_back(c);
    auto rle3 = RunLengthEncoding(buf);
    assert(rle == rle3);
    out(ans);
  }
}
