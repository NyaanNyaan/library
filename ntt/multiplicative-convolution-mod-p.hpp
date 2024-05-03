#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include "../math/constexpr-primitive-root.hpp"

template <typename fps>
fps multiplicative_convolution_mod_p(const fps& a, const fps& b, int p) {
  assert((int)a.size() == p);
  assert((int)b.size() == p);
  using mint = typename fps::value_type;
  int r = constexpr_primitive_root(p);
  vector<int> exp(p - 1), log(p);
  exp[0] = 1;
  for (int i = 1; i < p - 1; i++) exp[i] = 1LL * exp[i - 1] * r % p;
  for (int i = 0; i < p - 1; i++) log[exp[i]] = i;
  fps s(p - 1), t(p - 1);
  for (int i = 0; i < p - 1; i++) s[i] = a[exp[i]], t[i] = b[exp[i]];
  fps u = s * t;
  for (int i = p - 1; i < (int)u.size(); i++) u[i % (p - 1)] += u[i];
  fps c(p);
  for (int i = 1; i < p; i++) c[i] = u[log[i]];

  mint sa = accumulate(begin(a), end(a), mint{});
  mint sb = accumulate(begin(b), end(b), mint{});
  c[0] = sa * b[0] + sb * a[0] - a[0] * b[0];
  return c;
}
