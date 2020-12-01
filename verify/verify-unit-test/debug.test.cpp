#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../hashmap/hashmap.hpp"
#include "../../hashmap/hashset.hpp"
#include "../../matrix/matrix.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../template/template.hpp"
using namespace Nyaan;

void test() {
  // number
  {
    cerr << "number" << endl;
    trace(1, 2, 3);
    trace(inf, -inf, infLL);
    trace(-infLL, 1.1, (long double)(1.2));
  }
  // pair
  {
    cerr << "pair" << endl;
    pair<int, int> p1{1, 2};
    pair<pair<int, int>, int> p2{p1, 3};
    pair<vector<int>, int> p3{{1, 2}, 3};
    trace(p1, p2, p3);
  }
  // Container
  {
    cerr << "container" << endl;
    vector<int> vc{1, inf};
    set<int> st{2, 3};
    array<int, 3> ar{{1, 2, 3}};
    trace(vc, st, ar);
  }
  // Dict
  {
    cerr << "dict" << endl;
    map<int, int> m;
    m[0] = 1, m[1] = 2;
    trace(m);
  }
  // Native array
  {
    cerr << "native array" << endl;
    int a[] = {1, 2, 3, 4, 5};
    trace(make_pair(a, 2), make_pair(a + 3, 2));
  }
  // string, char
  {
    cerr << "char & string" << endl;
    char c = 'a';
    string s = "abc";
    trace(c, s);
  }
  // other
  {
    cerr << "high-dimensional vector" << endl;
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
  // cv qualifier (int)
  {
    cerr << "cv qualifier (int)" << endl;
    int a0 = 0;
    const int a1 = 1;
    int& a2 = a0;
    const int& a3 = a1;
    trace(a0, a1, a2, a3);
  }
  // cv qualifier (char)
  {
    cerr << "cv qualifier (char)" << endl;
    char a0 = 'a';
    const char a1 = 'b';
    char& a2 = a0;
    const char& a3 = a1;
    trace(a0, a1, a2, a3);
  }
   // cv qualifier (string)
  {
    cerr << "cv qualifier (char)" << endl;
    string a0 = "abc";
    const string a1 = "def";
    string& a2 = a0;
    const string& a3 = a1;
    trace(a0, a1, a2, a3);
  }
  // original iterator
  {
    cerr << "original iterator" << endl;
    HashSet<int> st;
    st.insert(2);
    st.insert(3);
    HashMap<int, int> m;
    m[0] = 1, m[1] = 2;
    trace(st, m);
  }
  // original structure
  {
    cerr << "original strucure" << endl;
    LazyMontgomeryModInt<998244353> a(998244354);
    trace(a);
    Matrix<LazyMontgomeryModInt<998244353>> mat;
    mat = mat.I(3);
    trace(mat);
  }
}

void Nyaan::solve() {
  test();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
