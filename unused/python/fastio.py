import atexit
import os


class Fastio:
    def __init__(self):
        self.ibuf = bytes()
        self.obuf = bytearray()
        self.pil = 0
        self.pir = 0
        self.buf = bytearray(21)
        self.buf[20] = 10

    def load(self):
        self.ibuf = self.ibuf[self.pil:]
        self.ibuf += os.read(0, 131072)
        self.pil = 0
        self.pir = len(self.ibuf)

    def flush(self):
        os.write(1, self.obuf)
        self.obuf = bytearray()

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

    def fastoutln(self, x):
        i = 19
        if x == 0:
            self.buf[i] = 48
            i -= 1
        else:
            if x < 0:
                self.obuf.append(45)
                x = -x
            while x != 0:
                x, r = divmod(x, 10)
                self.buf[i] = 48 + r
                i -= 1
        self.obuf.extend(self.buf[i+1:21])
        if len(self.obuf) > 262144:
            self.flush()


fastio = Fastio()
rd = fastio.fastin
wtn = fastio.fastoutln
atexit.register(fastio.flush)
