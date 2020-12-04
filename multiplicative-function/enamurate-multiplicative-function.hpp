#pragma once



// f(n, p, c) : n = pow(p, c), f is multiplicative function
template <typename mint, typename F>
vector<mint> enamurate_multiplicative_function(const F& func, int n) {
  assert(n < (1LL << 30));
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = func(i, i, 1);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      if (i % ps[j] == 0) {
        int c = 0, x = i, y = 1;
        while (x % ps[j] == 0) x /= ps[j], y *= ps[j], ++c;
        if (x == 1)
          f[i * ps[j]] = func(i * ps[j], i, c + 1);
        else
          f[i * ps[j]] = f[x] * f[y];
        break;
      } else
        f[i * ps[j]] = f[i] * f[ps[j]];
    }
  }
  return std::move(f);
}
