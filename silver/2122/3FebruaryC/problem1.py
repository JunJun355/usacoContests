"""
ID: 06jajun
LANG: PYTHON3
TASK: meetings
"""


def main():
    n = int(input())
    prefs = []
    pos = []
    for i in range(n):
        new = [int(c) - 1 for c in input().split()]
        nnew = []
        for j in new:
            if j == i:
                break
            nnew.append(j)
        prefs.append(nnew)
        pos.append(set())
    searched = set()
    def recurse(cow):
        npos = pos[nowcow]
        for ncow in prefs[cow]:
            if ncow == nowcow:
                npos.add(cow)
            if ncow not in searched or cow == nowcow:
                searched.add(ncow)
                new = recurse(ncow)
                if new == 1:
                    npos.add(cow)
                    if cow == nowcow:
                        return ncow + 1
        if cow in npos:
            return 1
        if cow == nowcow:
            return cow + 1
    for nowcow in range(n):
        searched.add(nowcow)
        print(recurse(nowcow))
        searched = set()

if __name__ == '__main__':
    main()
