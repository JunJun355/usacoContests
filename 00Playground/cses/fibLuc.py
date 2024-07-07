from collections import defaultdict;
from functools import cache, lru_cache;

@cache
def fib(n):
    if n == 1 or n == 2: return 1
    hf = fib(n // 2)
    hl = luc(n // 2)
    if n % 2 == 0:
        ans = hf * hl
    else:
        hfs = (hf + hl) // 2
        hls = (5 * hf + hl) // 2
        ans = (hf * hls + hfs * hl) // 2
    return ans

@cache
def luc(n):
    if n == 1: return 1
    if n == 2: return 3
    hf = fib(n // 2)
    hl = luc(n // 2)
    if n % 2 == 0:
        ans = (5 * hf ** 2 + hl ** 2) // 2
    else:
        hfs = (hf + hl) // 2
        hls = (5 * hf + hl) // 2
        ans = (5 * hf * hfs + hl * hls) // 2
    
    return ans

# @lru_cache(maxsize=2)
def convfib(n):
    arr = [1, 1]
    for i in range(n - 2):
        arr[i % 2] = sum(arr)
    return arr[(n + 1) % 2]

# fib(3)
x = 2 ** 21
# print(convfib(x))
print(fib(x))
# fib(x)
# fib(5)