#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../string/run-length-encoding.hpp"

using namespace Nyaan;

string rev(vector<pair<char, int>>& rle) {
  string res;
  for (auto&& [c, n] : rle) res += string(n, c);
  return res;
}

#include "../../misc/rng.hpp"

void test() {
  using vc = vector<pair<char, int>>;
  int t = 100;
  vc rle;
  rle.emplace_back('a', 1);
  while (t--) {
    char c;
    do
      c = randint(0, 26) + 'a';
    while (c == rle.back().first);
    int n = randint(1, 101);
    rle.emplace_back(c, n);
  }
  string s = rev(rle);
  vector<char> s2;
  for (auto&& c : s) s2.push_back(c);
  assert(rle == RunLengthEncoding(s));
  assert(rle == RunLengthEncoding(s2));
}

void Nyaan::solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;

  rep(i, 100) test();
}
