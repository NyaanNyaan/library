#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/bitset-find-prev.hpp"

using namespace Nyaan;

template <int N>
void verify(int seed) {
  Bitset<N> bs;
  int rng = seed;
  rep(i, N) bs[i] = (rng >> 1) & 1, rng = rng * 1928373 % 10203913;

  int last = N;
  while (true) {
    int i = bs._Find_prev(last);
    if (i == -1) break;
    assert(0 <= i and i < N);
    assert(bs[i] == 1);
    assert(i < last);
    bs[i].flip();
    last = i;
  }
  assert(bs.any() == false);
}

/*

// for time measurement

#include "../../misc/timer.hpp"
void test() {
  constexpr int N = 100000000;
  int loop = 100;
  Bitset<N> *p = new Bitset<N>;
  Bitset<N> &bs = *p;

  Timer timer;
  auto init = [&]() {
    int rng = 10;
    while (rng < N) bs[rng] = 1, rng += 20;
  };

  // prev_naive
  {
    timer.reset();
    rep(_, loop / 10) {
      init();
      int last = N;
      while (true) {
        int i = last - 1;
        while (i != -1 and bs[i] == 0) i--;
        if (i == -1) break;
        bs[i].flip();
        last = i;
      }
    }
    out("naive", timer.elapsed());
    assert(bs.any() == false);
  }

  // prev
  {
    timer.reset();
    rep(i, loop) {
      init();
      int last = N;
      while (true) {
        int i = bs._Find_prev(last);
        if (i == -1) break;
        bs[i].flip();
        last = i;
      }
    }
    out("prev", timer.elapsed());
    assert(bs.any() == false);
  }

  // next
  {
    timer.reset();
    rep(i, loop) {
      init();
      int last = bs._Find_first();
      bs[last].flip();
      while (true) {
        int i = bs._Find_next(last);
        if (i == N) break;
        bs[i].flip();
        last = i;
      }
    }
    out("next", timer.elapsed());
    assert(bs.any() == false);
  }
}
*/

Bitset<TEN(7)> bs;

void Nyaan::solve() {
  // test();
  rep(i, 1000) verify<8191>(i);
  rep(i, 1000) verify<8192>(i);
  rep(i, 1000) verify<8193>(i);

  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
