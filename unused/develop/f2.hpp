// 参考：https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/bitset
// なぜかnextより遅いのでお蔵入り…

#include "../../template/template.hpp"
//
using namespace Nyaan;

#pragma GCC target("avx2,bmi,bmi2,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
template <size_t Nb>
struct Bitset : bitset<Nb> {
  template <typename... Args>
  Bitset(Args... args) : bitset<Nb>(args...) {}

  static constexpr int N = Nb;
  static constexpr int array_size = (Nb + 63) / 64;
  union raw_cast {
    array<uint64_t, array_size> a;
    Bitset b;
  };

  int _Find_prev(size_t i) const {
    if (i == 0) return -1;
    size_t M = --i / 64;
    auto& a = ((raw_cast*)(this))->a;
    uint64_t buf = _bzhi_u64(a[M], (i & 63) + 1);
    if (buf != 0) return M * 64 + 63 - __builtin_clzll(buf);
    while (M--)
      if (a[M] != 0) return M * 64 + 63 - __builtin_clzll(a[M]);
    return -1;
  }

  inline int _Find_last() const { return _Find_prev(N); }
};

#include "misc/timer.hpp"

void test() {
  constexpr int N = 100000000;
  Bitset<N> bs;

  Timer timer;
  auto init = [&]() {
    int rng = 10;
    while (rng < N) bs[rng] = 1, rng += 50;
    timer.reset();
  };

  // prev_naive
  {
    init();
    int last = N;
    while (true) {
      int i = last - 1;
      while (i != -1 and bs[i] == 0) i--;
      if (i == -1) break;
      bs[i].flip();
      last = i;
    }
    out("naive", timer.elapsed());
    assert(bs.any() == false);
  }

  // prev
  {
    init();
    int last = N;
    while (true) {
      int i = bs._Find_prev(last);
      if (i == -1) break;
      bs[i].flip();
      last = i;
    }
    out("prev", timer.elapsed());
    assert(bs.any() == false);
  }

  // next
  {
    init();
    int last = bs._Find_first();
    bs[last].flip();
    while (true) {
      int i = bs._Find_next(last);
      if (i == N) break;
      bs[i].flip();
      last = i;
    }
    out("next", timer.elapsed());
    assert(bs.any() == false);
  }
}

void Nyaan::solve() {
  test();
  Bitset<1000> bs;
  int rng = 10;
  rep(i, 1000) bs[i] = (rng >> 1) & 1, rng = rng * 1928373 % 10203913;

  int last = 1000;
  while (true) {
    int i = bs._Find_prev(last);
    trc(i);
    if (i == -1) break;
    assert(0 <= i and i < 1000);
    assert(bs[i] == 1);
    assert(i < last);
    bs[i].flip();
    last = i;
  }
  assert(bs.any() == false);
}
