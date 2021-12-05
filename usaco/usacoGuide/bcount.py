"""
ID: 06jajun
LANG: PYTHON3
TASK: bcount
"""


def main():
    fin = open ('bcount.in', 'r')
    fout = open ('bcount.out', 'w')

    holsteins = [0]
    guernseys = [0]
    jerseys = [0]

    n, q = [int(c) for c in fin.readline().split()]
    for _ in range(n):
        newID = int(fin.readline())
        if newID == 1:
            holsteins.append(holsteins[-1] + 1)
            guernseys.append(guernseys[-1])
            jerseys.append(jerseys[-1])
        elif newID == 2:
            holsteins.append(holsteins[-1])
            guernseys.append(guernseys[-1] + 1)
            jerseys.append(jerseys[-1])
        elif newID == 3:
            holsteins.append(holsteins[-1])
            guernseys.append(guernseys[-1])
            jerseys.append(jerseys[-1] + 1)
    for _ in range(q):
        start, end = [int(c) for c in fin.readline().split()]
        ans = [holsteins[end] - holsteins[start - 1], guernseys[end] - guernseys[start - 1], jerseys[end] - jerseys[start - 1]]
        fout.write(' '.join([str(c) for c in ans]))
        fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
