import subprocess
import sys
import re
import io

# oj-bundleを使用した際、Windows環境だと
# 「#line 3 "ntt\ntt.hpp"」のような行が発生してしまい、
# yosupo judgeでは'\n'が改行文字と認識されるのかCEになる
# それを防ぐために作った雑なラッパー

# 出力をutf-8にする(これをしないとwinでは文字化けする)
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

args = sys.argv
if len(args) < 2:
    exit()
buffer = 'buf.cpp'

buf = open(buffer, mode='w', encoding='utf-8')
with open(args[1], mode='r', encoding='utf-8') as f:
    lines = f.readlines()   
    for line in lines:
        buf.write(line)
        # #include同士は1行空ける
        if len(line) > 0 and line[0] == '#':
            buf.write('\n')
buf.close()

cmd = "oj-bundle " + buffer
src = subprocess.check_output(cmd.split()).decode("utf-8")
lines = src.split('\n')
for line in lines:
    if not re.match('^#line', line):
        print(line, end='')
