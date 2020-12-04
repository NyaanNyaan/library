#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
#include "../../data-structure/radix-heap.hpp"
#include "../../misc/rng.hpp"

template <typename Key, typename Val>
void test() {
  auto t = [](Key mx, Key d, double ratio) {
    RadixHeap<Key, Val> q1;
    map<Key, Val> q2;
    Key i = 0;
    while (i < mx) {
      assert(q1.empty() == q2.empty());
      assert(q1.size() == (int)q2.size());
      if (q1.empty() or random() < ratio) {
#pragma GCC diagnostic ignored "-Wnarrowing"
        Val j{rng()};
#pragma GCC diagnostic warning "-Wnarrowing"
        q1.push(i, j);
        q2.emplace(i, j);
        i += d;
      } else {
        auto t1 = q1.pop();
        decltype(t1) t2 = *begin(q2);
        assert(t1 == t2);
        q2.erase(begin(q2));
      }
    }
    while (q1.size() != 0) {
      auto t1 = q1.pop();
      decltype(t1) t2 = *begin(q2);
      assert(t1 == t2);
      q2.erase(begin(q2));
    }
  };
  t(10, 1, 0.5);
  t(10, 1, 0.7);
  t(10, 1, 0.9);
  t(1000, 1, 0.5);
  t(1000, 1, 0.7);
  t(1000, 1, 0.9);
  t(TEN(8), 334, 0.5);
  t(TEN(8), 1333, 0.9);
  t(TEN(9), 13333, 0.7);
}

using namespace Nyaan; void Nyaan::solve() {
  test<int32_t, int64_t>();
  test<int64_t, int64_t>();
  test<uint32_t, int64_t>();
  test<uint64_t, int64_t>();
  test<uint64_t, uint64_t>();
  test<uint64_t, vector<int> >();

  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
