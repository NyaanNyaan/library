from numba import jit, njit, i8
import numpy as np


@njit(i8(i8, i8, i8), cache=True)
def modpow(a, p, m):
  r = 1
  while p:
    if p & 1: r = r * a % m
    a = a * a % m
    p >>= 1
  return r


@njit(i8[:](i8[:], i8[:]), cache=True)
def ntt(s, t):
  mod = 998244353
  pr = 5
  sl, tl = len(s), len(t)
  k = 1
  M = 2
  while M < sl + tl - 1:
    k += 1
    M *= 2
  w = np.zeros(M // 2, np.int64)
  y = np.zeros(M // 2, np.int64)

  def init():
    nonlocal w, y, M, mod, pr
    z = modpow(pr, (mod - 1) // M, mod)
    x = modpow(z, mod - 2, mod)
    j = M // 4
    while j:
      w[j] = z
      z = z * z % mod
      y[j] = x
      x = x * x % mod
      j //= 2
    y[0] = 1
    w[0] = 1
    j = M // 2
    js = 2
    while js < j:
      z = w[js]
      x = y[js]
      for k2 in range(js):
        w[k2 + js] = w[k2] * z % mod
        y[k2 + js] = y[k2] * x % mod
      js *= 2

  def fft(a, k):
    nonlocal w, y, mod
    m = 2 ** k
    u = 1
    v = m // 2
    i = k
    while i:
      jh = 0
      while jh < u:
        wj = w[jh]
        j = jh * v * 2
        je = j + v
        while j < je:
          ajv = wj * a[j + v] % mod
          a[j + v] = a[j] + mod - ajv
          if a[j + v] >= mod:
            a[j + v] -= mod
          a[j] = a[j] + ajv
          if a[j] >= mod:
            a[j] -= mod
          j += 1
        jh += 1
      u *= 2
      v //= 2
      i -= 1

  def ifft(a, k):
    nonlocal w, y, mod
    m = 2 ** k
    u = m // 2
    v = 1
    i = 1
    while i <= k:
      jh = 0
      while jh < u:
        wj = y[jh]
        j = jh * v * 2
        je = j + v
        while j < je:
          ajv = a[j] + mod - a[j + v]
          if ajv >= mod:
            ajv -= mod
          a[j] = a[j] + a[j + v]
          if a[j] >= mod:
            a[j] -= mod
          a[j + v] = wj * ajv % mod
          j += 1
        jh += 1
      u //= 2
      v *= 2
      i += 1

  init()
  u = np.zeros(M, np.int64); u[:sl] = s; fft(u, k)
  v = np.zeros(M, np.int64); v[:tl] = t; fft(v, k)
  u *= v; u %= mod; ifft(u, k)
  u *= modpow(2 ** k, mod - 2, mod); u %= mod
  return u[:sl + tl - 1]
