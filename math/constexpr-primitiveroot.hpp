#pragma once

constexpr unsigned int constexpr_primitive_root(unsigned int mod) {
  using u32 = unsigned int;
  using u64 = unsigned long long;
  if(mod == 2) return 1;
  u64 m = mod - 1, ds[32] = {}, idx = 0;
  for (u64 i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      ds[idx++] = i;
      while (m % i == 0) m /= i;
    }
  }
  if (m != 1) ds[idx++] = m;
  for (u32 _pr = 2, flg = true;; _pr++, flg = true) {
    for (u32 i = 0; i < idx && flg; ++i) {
      u64 a = _pr, b = (mod - 1) / ds[i], r = 1;
      for (; b; a = a * a % mod, b >>= 1)
        if (b & 1) r = r * a % mod;
      if (r == 1) flg = false;
    }
    if (flg == true) return _pr;
  }
}

