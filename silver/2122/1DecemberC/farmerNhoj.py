"""
ID: 06jajun
LANG: PYTHON3
TASK: test
"""
from collections import defaultdict


def main():
    k, m, n = [int(c) for c in input().split()]
    cows = [float('-inf')]
    patches = []
    taste = defaultdict(lambda: 0)
    for i in range(k):
        p, t = [int(c) for c in input().split()]
        patches.append(p)
        taste[p] = t
    for i in range(m):
        cows.append(int(input()))
    patches.sort()
    cows.sort()
    cows.append(float('inf'))
    pprox = []
    curr = cows[0]
    i = 0
    while i < k and patches[i] < curr:
        pprox.append(curr - patches[i])
        i += 1
    j = 0
    while j < m and cows[j + 1] < patches[i]:
        j += 1
    while i < k:
        pprox.append()
        i += 1


if __name__ == '__main__':
    main()
