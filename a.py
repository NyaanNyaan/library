import atexit
import os
import sys
import __pypy__


class Fastio:
  def __init__(self):
    self.ibuf = bytes()
    self.pil = 0
    self.pir = 0
    self.sb = __pypy__.builders.StringBuilder()

  def load(self):
    self.ibuf = self.ibuf[self.pil:]
    self.ibuf += os.read(0, 131072)
    self.pil = 0
    self.pir = len(self.ibuf)

  def flush(self):
    os.write(1, self.sb.build().encode())

  def fastin(self):
    if self.pir - self.pil < 32:
      self.load()
    minus = 0
    x = 0
    while self.ibuf[self.pil] < 45:
      self.pil += 1
    if self.ibuf[self.pil] == 45:
      minus = 1
      self.pil += 1
    while self.ibuf[self.pil] >= 48:
      x = x * 10 + (self.ibuf[self.pil] & 15)
      self.pil += 1
    if minus:
      x = -x
    return x

  def fastout(self, x):
    self.sb.append(str(x))

  def fastoutln(self, x):
    self.sb.append(str(x))
    self.sb.append('\n')


fastio = Fastio()
rd = fastio.fastin
wt = fastio.fastout
wtn = fastio.fastoutln
atexit.register(fastio.flush)
sys.stdin, sys.stdout = None, None
