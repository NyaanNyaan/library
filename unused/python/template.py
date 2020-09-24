from sys import setrecursionlimit, stdin
from functools import lru_cache
from bisect import bisect_left as lb, bisect_right as ub
from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
from math import gcd, ceil, sqrt
setrecursionlimit(10 ** 7)
inf = 1 << 61
rg, wt = range, print
rd = lambda: int(stdin.readline())
rds = lambda: map(int, stdin.readline().split())
rdl = lambda: list(map(int, stdin.readline().split()))
