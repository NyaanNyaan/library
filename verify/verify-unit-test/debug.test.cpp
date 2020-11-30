#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
#include "../../hashmap/hashmap.hpp"
#include "../../hashmap/hashset.hpp"

using namespace Nyaan;

void test() {
  // Integral
  {
    trace(1, 2, 3);
    trace(inf, -inf, infLL);
    trace(-infLL, 1001001000, 1LL << 61);
  }
  // pair
  {
    pair<int, int> p1{1, 2};
    pair<pair<int, int>, int> p2{p1, 3};
    pair<vector<int>, int> p3{{1, 2}, 3};
    trace(p1, p2, p3);
  }
  // Container
  {
    vector<int> vc{1, inf};
    set<int> st{2, 3};
    array<int, 3> ar{{1, 2, 3}};
    trace(vc, st, ar);
  }
  // Dict
  {
    map<int, int> m;
    m[0] = 1, m[1] = 2;
    trace(m);
  }
  // Native array
  {
    int a[] = {1, 2, 3, 4, 5};
    trace(make_pair(a, 2), make_pair(a + 3, 2));
  }
  // string, char
  {
    char c = 'a';
    string s = "abc";
    trace(c, s);
  }
  // other
  {
    vector<pair<int, int>> v;
    v.push_back({0, 1});
    v.push_back({2, 3});
    trace(v);
    vector<vector<int>> a(2);
    a[0] = vector<int>{0, 1};
    a[1] = vector<int>{2, 3};
    trace(a);
    vector<vector<vector<int>>> b(2);
    b[0] = b[1] = a;
    trace(b);
  }
  // original structure
  {
    HashSet<int> st;
    st.insert(2);
    st.insert(3);
    HashMap<int, int> m;
    m[0] = 1, m[1] = 2;
    trace(st, m);
  }
  // cv qualifier
  {
    int a0 = 0;
    const int a1 = 1;
    int& a2 = a0;
    const int& a3 = a1;
    trace(a0, a1, a2, a3);
  }
}

void Nyaan::solve() {
  test();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
