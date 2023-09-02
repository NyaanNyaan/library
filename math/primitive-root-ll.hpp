#pragma once

#include <algorithm>
#include <vector>
using namespace std;

#include "../internal/internal-math.hpp"
#include "../prime/fast-factorize.hpp"

long long primitive_root_ll(long long p) {
  if (p == 2) return 1;
  auto fs = factorize(p - 1);
  sort(begin(fs), end(fs));
  fs.erase(unique(begin(fs), end(fs)), end(fs));
  for (int g = 2;; g++) {
    int ok = 1;
    for (auto& f : fs) {
      if (internal::modpow<long long, __int128_t>(g, (p - 1) / f, p) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return g;
  }
  exit(1);
}
