#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>> v) {
  using fps = FormalPowerSeries<mint>;
  auto comp = [](fps &a, fps &b) { a.size() > b.size(); };
  priority_queue<fps, vector<fps>, decltype(comp)> Q(comp);
  while (Q.size() != 1) {
    fps f1 = Q.top();
    Q.pop();
    fps f2 = Q.top();
    Q.pop();
    Q.push(f1 * f2);
  }
  return Q.top();
}