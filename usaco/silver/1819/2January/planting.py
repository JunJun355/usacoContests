"""
ID: 06jajun
LANG: PYTHON3
TASK: planting
"""
# * ->
from collections import defaultdict


def main():
    fin = open ('planting.in', 'r')
    fout = open ('planting.out', 'w')

    n = int(fin.readline())
    counts = defaultdict(lambda: 0)
    def b(num):
        return counts[num]
    for _ in range(n - 1):
        i, j = [int(c) for c in fin.readline().split()]
        counts[i] += 1
        counts[j] += 1
    maxi = 1
    for i in range(1, n + 1):
        maxi = max(i, maxi, key=b)
    fout.write(str(counts[maxi] + 1))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
