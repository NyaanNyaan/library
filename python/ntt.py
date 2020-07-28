class NumberTheroemTransform:
  def __init__(self, mod, pr):
    self.mod = mod
    self.pr = pr
    self.M = 2
    self.w = [1]
    self.y = [1]

  def setwy(self, M):
    if M <= self.M: return
    self.w += [0] * ((M - self.M) // 2)
    self.y += [0] * ((M - self.M) // 2)
    self.M = M
    z = pow(self.pr, (self.mod - 1) // self.M, self.mod)
    x = pow(z, self.mod - 2, self.mod)
    j = M // 4
    while j:
      self.w[j] = z
      z = z * z % self.mod
      self.y[j] = x
      x = x * x % self.mod
      j //= 2
    self.y[0] = 1
    self.w[0] = 1
    j = self.M // 2
    js = 2
    while js < j:
      z = self.w[js]
      x = self.y[js]
      for k2 in range(js):
        self.w[k2 + js] = self.w[k2] * z % self.mod
        self.y[k2 + js] = self.y[k2] * x % self.mod
      js *= 2

  def fft(self, a):
    mod = self.mod
    self.setwy(len(a))
    u = 1
    v = len(a) >> 1
    while v:
      for j in range(v):
        a[j], a[j + v] = a[j] + a[j + v], a[j] - a[j + v]
        if a[j] >= mod:
          a[j] -= mod
        if a[j + v] < 0:
          a[j + v] += mod
      for jh in range(1, u):
        wj = self.w[jh]
        js = jh * v * 2
        je = js + v
        for j in range(js, je):
          ajv = wj * a[j + v] % mod
          a[j + v] = a[j] - ajv
          if a[j + v] < 0:
            a[j + v] += mod
          a[j] = a[j] + ajv
          if a[j] >= mod:
            a[j] -= mod
      u *= 2
      v >>= 1

  def ifft(self, a):
    mod = self.mod
    self.setwy(len(a))
    u = len(a) >> 1
    v = 1
    while u:
      for j in range(v):
        a[j], a[j + v] = a[j] + a[j + v], a[j] - a[j + v]
        if a[j] >= mod:
          a[j] -= mod
        if a[j + v] < 0:
          a[j + v] += mod
      for jh in range(1, u):
        wj = self.y[jh]
        js = jh * v * 2
        je = js + v
        for j in range(js, je):
          ajv = a[j] - a[j + v]
          if ajv < 0:
            ajv += mod
          a[j] = a[j] + a[j + v]
          if a[j] >= mod:
            a[j] -= mod
          a[j + v] = wj * ajv % mod
      u >>= 1
      v *= 2

  def multiply(self, s, t):
    sl, tl = len(s), len(t)
    L = sl + tl - 1
    M = 2 ** (L - 1).bit_length()
    s += [0] * (M - sl)
    t += [0] * (M - tl)
    self.fft(s)
    self.fft(t)
    for i in range(M):
      s[i] = s[i] * t[i] % self.mod
    self.ifft(s)
    invk = pow(M, self.mod - 2, self.mod)
    for i in range(L):
      s[i] = s[i] * invk % self.mod
    del s[L:]
    return s