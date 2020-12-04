#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"



#include "../../data-structure-2d/wavelet-matrix.hpp"

uint64_t rng() {
  static uint64_t x_ =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);
}

int randint(int l, int r) {
  assert(l < r);
  return rng() % (r - l) + l;
}

void test(int n, int q, bool all_zero = false, bool large = false) {
  assert(n > 0);
  WaveletMatrix<int> wm(n);
  vector<int> v(n, 0);
  vector<int> buffer;

  if (large) {
    for (int i = 0; i < n; ++i) v[i] = randint(0, 1 << 30);
  } else if (!all_zero) {
    iota(begin(v), end(v), 0);
  }

  mt19937_64 mt;
  shuffle(begin(v), end(v), mt);
  for (int i = n; i--;) wm.set(i, v[i]);
  wm.build();

  // access
  for (int Q = q; Q--;) {
    int i = randint(0, n);
    assert(wm.access(i) == v[i]);
  }

  // kth-smallest / kth-largest
  for (int Q = q; Q--;) {
    int len = randint(1, n + 1);
    int l = randint(0, n - len + 1);
    int r = l + len;
    int k = randint(0, len);

    buffer.clear();
    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));
    sort(begin(buffer), end(buffer));

    assert(wm.kth_smallest(l, r, k) == buffer[k]);
    assert(wm.kth_largest(l, r, k) == buffer[len - k - 1]);
  }

  // range-freq
  for (int Q = q; Q--;) {
    int len = randint(1, n + 1);
    int l = randint(0, n - len + 1);
    int r = l + len;
    int lower, upper;
    do {
      lower = randint(0, n + 5);
      upper = randint(0, n + 5);
      if (lower > upper) swap(lower, upper);
    } while (lower != upper);

    buffer.clear();
    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));
    sort(begin(buffer), end(buffer));

    int up = lower_bound(begin(buffer), end(buffer), upper) - begin(buffer);
    assert(wm.range_freq(l, r, upper) == up);
    int lo = lower_bound(begin(buffer), end(buffer), lower) - begin(buffer);
    assert(wm.range_freq(l, r, lower, upper) == up - lo);

    int pv = len - 1;
    while (pv != -1 and buffer[pv] >= upper) --pv;
    assert(wm.prev_value(l, r, upper) == (pv == -1 ? -1 : buffer[pv]));

    int nv = 0;
    while (nv != len and buffer[nv] < lower) ++nv;
    assert(wm.next_value(l, r, lower) == (nv == len ? -1 : buffer[nv]));
  }
}

int main() {
  test(63, 1000);
  test(64, 1000);
  test(65, 1000);
  test(63, 1000, true);
  test(64, 1000, true);
  test(65, 1000, true);
  test(63, 1000, false, true);
  test(64, 1000, false, true);
  test(65, 1000, false, true);
  for (int i = 100; i--;) {
    test(1, 1);
    test(1, 1, true);
    test(1, 1, false, true);
    test(2, 10);
    test(2, 10, true);
    test(2, 10, false, true);
  }

  test(65535, 10);
  test(65536, 10);
  test(65537, 10);
  test(65535, 10, false, true);
  test(65536, 10, false, true);
  test(65537, 10, false, true);
  
  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}