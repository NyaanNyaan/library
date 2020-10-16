#include "../../balanced-binary-search-tree/rbst-ordered-map.hpp"
#include "../../misc/rng.hpp"

// n elements, key,val \in [0, m)
void unit_test(int n, int m) {
  OrderedMap<int, int> m1;
  map<int, int> m2;

  auto is_same_map = [&]() {
    // get
    for (int i = 0; i < m; ++i) {
      int n1 = m1.get(i);
      int n2 = m2.find(i) == m2.end() ? 0 : m2.find(i)->second;
      assert(n1 == n2 and "get");
    }

    // enumerate
    auto e = m1.enumerate();
    {
      int i = 0;
      for (auto& p : m2) {
        assert(e[i].first == p.first and "enumerate key");
        assert(e[i].second == p.second and "enumerate val");
        ++i;
      }
    }
  };

  // access
  {
    auto k = randset(0, m, n);
    auto v = randset(0, m, n);
    for (int i = 0; i < n; ++i) {
      m1[k[i]] = v[i];
      m2[k[i]] = v[i];
      is_same_map();
    }
  }

}

int main() { unit_test(100, 300); }
