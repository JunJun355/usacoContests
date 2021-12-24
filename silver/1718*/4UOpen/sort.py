"""
ID: 06jajun
LANG: PYTHON3
TASK: sort
"""
# * ->
from collections import defaultdict


def main():
    fin = open ('sort.in', 'r')
    fout = open ('sort.out', 'w')

    n = int(fin.readline())
    arr = []
    d = defaultdict(lambda: float('-inf'))
    for i in range(n):
        arr.append(int(fin.readline()))
        d[arr[-1]] = max(i, d[arr[-1]])
    arrs = list(sorted(arr))
    # print(arrs)
    maxi = 0
    # print(arrs, arr)
    for i in range(n - 1):
        # print(arr.index(arrs[i]) - i)
        if arrs[i] == arrs[i + 1]: continue
        # if maxi < d[arrs[i]] - i: print(maxi, d[arrs[i]] - i, i, arr.index(arrs[i]), d[arrs[i]], arrs[i])
        maxi = max(d[arrs[i]] - i, maxi)
    maxi = max(d[arrs[n - 1]] - n + 1, maxi)
    fout.write(str(maxi + 1))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
