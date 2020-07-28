import subprocess
import sys
import re

# oj-bundleを使用した際、Windows環境だと
# 「#line 3 "ntt\ntt.hpp"」のような行が発生してしまい、
# yosupo judgeでは'\n'が改行文字と認識されるのかCEになる
# それを防ぐために作った雑なラッパー

args = sys.argv
if len(args) < 2:
  exit()
cmd = "oj-bundle "
cmd += args[1]
src = subprocess.check_output(cmd.split()).decode()
lines = src.split('\n')
for line in lines:
  if not re.match('^#line', line):
    print(line, end='')