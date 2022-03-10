"""
ID: 06jajun
LANG: PYTHON3
TASK: meetings
"""
from collections import defaultdict


def main():
    n = int(input())
    px, py = [int(c) for c in input().split()]
    instructions = []
    m = n // 2
    all = defaultdict(lambda: [])
    res = [0] * n
    for i in range(n):
        instructions.append([int(c) for c in input().split()])

    def recursea(i=0, x=0, y=0, k=0):
        if i == m:
            all[(px - x, py - y)].append(k)
        else:
            nx, ny = instructions[i]
            recursea(i + 1, x + nx, y + ny, k + 1)
            recursea(i + 1, x, y, k)
    recursea()
    # print(all)

    def recurseb(i=m, x=0, y=0, k=-1):
        if i == n:
            for j in all[(x, y)]:
                res[j + k] += 1
        else:
            nx, ny = instructions[i]
            recurseb(i + 1, x + nx, y + ny, k + 1)
            recurseb(i + 1, x, y, k)
    recurseb()
    print('\n'.join([str(c) for c in res]))


if __name__ == '__main__':
    main()
