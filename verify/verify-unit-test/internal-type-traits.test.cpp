#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../hashmap/hashmap-unerasable.hpp"
#include "../../internal/internal-hash-function.hpp"
#include "../../internal/internal-type-traits.hpp"
using namespace Nyaan;

template <typename T, bool low>
T gen() {
  if constexpr (internal::is_broadly_integral_v<T>) {
    if (low) return rng(0, 5);
    if constexpr (sizeof(T) == 16) {
      return T(rng(0, TEN(18))) * TEN(18) + rng(0, TEN(18));
    } else {
      return rng(0, numeric_limits<T>::max() / 2);
    }
  } else if constexpr (internal::has_first_type_v<T> &&
                       internal::has_second_type_v<T>) {
    return T{gen<decltype(T::first), low>(), gen<decltype(T::second), low>()};
  } else {
    static_assert(internal::has_iterator_v<T>);
    T t;
    int n = rng(0, 10);
    rep(_, n) t.push_back(gen<typename T::value_type, low>());
    return t;
  }
}

template <typename T, bool low>
void test() {
  map<T, int> mp1;
  UnerasableHashMap<T, int> mp2(-1);
  assert(mp2.get(T{}) == -1);

  rep(t, 3000) {
    int cmd = rng(0, 1);
    if (cmd == 0) {
      T x = gen<T, low>();
      mp1[x] = mp2[x] = t;
    } else {
      T x = gen<T, low>();
      int u = mp2.get(x);
      int v = mp1.count(x) ? mp1[x] : -1;
      assert(u == v);
    }
    assert(sz(mp1) == sz(mp2));
  }
}

template <typename T>
void test2() {
  test<T, true>(), test<T, false>();
}

void q() {
  test2<char>();
  test2<unsigned char>();
  test2<short>();
  test2<unsigned short>();
  test2<int>();
  test2<unsigned int>();
  test2<long long>();
  test2<unsigned long long>();
  test2<__int128_t>();
  test2<__uint128_t>();

  test2<vector<int>>();

  test2<pair<int, int>>();
  test2<pair<__int128_t, __int128_t>>();

  test2<vvi>();
  test2<VV<vvi>>();
  test2<V<pl>>();
  test2<pair<VV<pl>, V<pl>>>();
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}