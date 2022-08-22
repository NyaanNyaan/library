import ctypes

ENABLE_PROCESSED_OUTPUT = 0x0001
ENABLE_WRAP_AT_EOL_OUTPUT = 0x0002
ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004
MODE = ENABLE_PROCESSED_OUTPUT + ENABLE_WRAP_AT_EOL_OUTPUT + ENABLE_VIRTUAL_TERMINAL_PROCESSING

kernel32 = ctypes.windll.kernel32
handle = kernel32.GetStdHandle(-11)
kernel32.SetConsoleMode(handle, MODE)

def color_words(s: str, word: str, num: int):
  escape_seq = "\033[" + str(num) + "m"
  end = '\033[0m'
  return s.replace(word, escape_seq + word + end)

def coloring(s: str):
  res = s[:]
  res = color_words(res, "FAILURE", 31)
  res = color_words(res, "SUCCESS", 32)
  res = color_words(res, "WARNING", 33)
  res = color_words(res, "INFO", 34)
  res = color_words(res, "NETWORK", 35)
  return res


import subprocess
import re
import time

url = "https://atcoder.jp/contests/ahc012/tasks/ahc012_a"
cmd = ["oj", "submit", "--no-open", "--yes", url, "./unused/a.cpp"]
overhead = 2.5
interval = 300.0
epsilon = 0.1

while True:
  while True:
    print("Start submission...", flush=True)
    proc = subprocess.run(cmd, stdout=subprocess.PIPE)
    err = proc.stdout.decode()
    returncode = proc.returncode

    print(coloring(err), flush=True)
    print("return code : ", returncode, flush=True)
    if returncode == 0:
      break
    pattern = r"Wait for [0-9]* second to submit again."
    sentence = re.search(pattern, err)[0]
    print(sentence, type(sentence))
    must_wait = int(re.findall(r"\d+", sentence)[0])
    print("second : ", must_wait)
    time.sleep(max(epsilon, must_wait - overhead))

  s = time.time()
  while time.time() - s < interval - overhead:
    time.sleep(epsilon)
