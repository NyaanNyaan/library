#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

#include "../misc/rng.hpp"

// N 択, 報酬最大化
struct MultiArmedBandit {
  MultiArmedBandit(int n)
      : N(n), last(-1), iter(0), thres(N * 5), num(N), v(N), e(N), t(1) {}

  int N, last;
  long long iter, thres;
  vector<long long> num;
  vector<double> v, e;
  double t;

  int play() {
    assert(last == -1);
    iter++;
    if (iter <= thres) return last = iter % N;

    double s = accumulate(begin(e), end(e), 0.0);
    double x = rnd() * s;
    for (int i = 0; i < N; i++) {
      if ((x -= e[i]) <= 0) return last = i;
    }
    return last = N - 1;
  }

  // 重み付け用の関数
  double f(double x) { return exp(x / t); }

  void reward(double y) {
    assert(last != -1);
    v[last] += y;
    num[last] += 1;
    e[last] = f(v[last] / num[last]);
    last = -1;

    static double u = 1.0;
    static double du = 0.01;
    // iter % thres == 0 になったら t を再決定
    if (iter % thres == 0) {
      u = max(0.7, u - du);
      double average = accumulate(begin(v), end(v), 0.0) / thres;
      t = average < 0.0 ? 1.0 : pow(average, u);
      for (int i = 0; i < N; i++) e[i] = f(v[i] / num[i]);
    }
  }
  int best() { return max_element(begin(e), end(e)) - begin(e); }
};
