---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from numba import jit, njit, i8\nimport numpy as np\n\n\n@njit(i8(i8, i8,\
    \ i8), cache=True)\ndef modpow(a, p, m):\n  r = 1\n  while p:\n    if p & 1: r\
    \ = r * a % m\n    a = a * a % m\n    p >>= 1\n  return r\n\n\n@njit(i8[:](i8[:],\
    \ i8[:]), cache=True)\ndef ntt(s, t):\n  mod = 998244353\n  pr = 5\n  sl, tl =\
    \ len(s), len(t)\n  k = 1\n  M = 2\n  while M < sl + tl - 1:\n    k += 1\n   \
    \ M *= 2\n  w = np.zeros(M // 2, np.int64)\n  y = np.zeros(M // 2, np.int64)\n\
    \n  def init():\n    nonlocal w, y, M, mod, pr\n    z = modpow(pr, (mod - 1) //\
    \ M, mod)\n    x = modpow(z, mod - 2, mod)\n    j = M // 4\n    while j:\n   \
    \   w[j] = z\n      z = z * z % mod\n      y[j] = x\n      x = x * x % mod\n \
    \     j //= 2\n    y[0] = 1\n    w[0] = 1\n    j = M // 2\n    js = 2\n    while\
    \ js < j:\n      z = w[js]\n      x = y[js]\n      for k2 in range(js):\n    \
    \    w[k2 + js] = w[k2] * z % mod\n        y[k2 + js] = y[k2] * x % mod\n    \
    \  js *= 2\n\n  def fft(a, k):\n    nonlocal w, y, mod\n    m = 2 ** k\n    u\
    \ = 1\n    v = m // 2\n    i = k\n    while i:\n      jh = 0\n      while jh <\
    \ u:\n        wj = w[jh]\n        j = jh * v * 2\n        je = j + v\n       \
    \ while j < je:\n          ajv = wj * a[j + v] % mod\n          a[j + v] = a[j]\
    \ + mod - ajv\n          if a[j + v] >= mod:\n            a[j + v] -= mod\n  \
    \        a[j] = a[j] + ajv\n          if a[j] >= mod:\n            a[j] -= mod\n\
    \          j += 1\n        jh += 1\n      u *= 2\n      v //= 2\n      i -= 1\n\
    \n  def ifft(a, k):\n    nonlocal w, y, mod\n    m = 2 ** k\n    u = m // 2\n\
    \    v = 1\n    i = 1\n    while i <= k:\n      jh = 0\n      while jh < u:\n\
    \        wj = y[jh]\n        j = jh * v * 2\n        je = j + v\n        while\
    \ j < je:\n          ajv = a[j] + mod - a[j + v]\n          if ajv >= mod:\n \
    \           ajv -= mod\n          a[j] = a[j] + a[j + v]\n          if a[j] >=\
    \ mod:\n            a[j] -= mod\n          a[j + v] = wj * ajv % mod\n       \
    \   j += 1\n        jh += 1\n      u //= 2\n      v *= 2\n      i += 1\n\n  init()\n\
    \  u = np.zeros(M, np.int64); u[:sl] = s; fft(u, k)\n  v = np.zeros(M, np.int64);\
    \ v[:tl] = t; fft(v, k)\n  u *= v; u %= mod; ifft(u, k)\n  u *= modpow(2 ** k,\
    \ mod - 2, mod); u %= mod\n  return u[:sl + tl - 1]\n"
  dependsOn: []
  isVerificationFile: false
  path: unused/python/ntt-numba.py
  requiredBy: []
  timestamp: '2020-08-01 13:45:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unused/python/ntt-numba.py
layout: document
redirect_from:
- /library/unused/python/ntt-numba.py
- /library/unused/python/ntt-numba.py.html
title: unused/python/ntt-numba.py
---
