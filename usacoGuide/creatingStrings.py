from collections import defaultdict
from copy import deepcopy


def main():
    inp = input().strip()
    occurances = defaultdict(lambda: 0)
    ini = set()
    for i in inp:
        occurances[i] += 1
        ini.add(i)
    ini = sorted(list(ini))
    fin = []
    for i in range(len(ini)):
        fin.append([ini[i], occurances[ini[i]]])
    ans = recurse(fin, '')
    print(len(ans))
    print('\n'.join(recurse(fin, '')))


def recurse(fin, currStr):
    # print(currStr, fin)
    ans = []
    tot = 0
    for i in range(len(fin)):
        if fin[i][1] != 0:
            tot += 1
            fin[i][1] -= 1
            ans += recurse(fin, currStr + fin[i][0])
            fin[i][1] += 1
    if tot:
        return ans
    return [currStr]


if __name__ == '__main__':
    main()
