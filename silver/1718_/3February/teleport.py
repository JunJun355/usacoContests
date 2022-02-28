"""
ID: 06jajun
LANG: PYTHON3
TASK: teleport
"""
# * ->
from collections import defaultdict


def main():
    fin = open ('teleport.in', 'r')
    fout = open ('teleport.out', 'w')

    n = int(fin.readline())
    points = []
    tot = 0
    for i in range(n):
        a, b = [int(c) for c in fin.readline().split()]
        tot += abs(a - b)
        points.append([a, b])
    slopechanges = defaultdict(lambda: 0)
    changes = [0]
    for a, b in points:
        if abs(a) >= abs(b - a):
            continue
        if (a < 0 and b < 0) or (a >= 0 and b >= 0):
            slopechanges[2 * b - 2 * a] -= 1
            slopechanges[2 * a] -= 1
            slopechanges[b] += 2
            changes.append(2 * b - 2 * a)
            changes.append(2 * a)
            changes.append(b)
        else:
            slopechanges[2 * b] -= 1
            slopechanges[b] += 2
            slopechanges[0] -= 1
            changes.append(2 * b)
            changes.append(b)
    changes.sort()
    # print(changes)
    # print(slopechanges)
    best = 0
    slope = 0
    currp = -int(2e8)
    curr = 0
    for i in changes:
        if i == currp:
            continue
        curr += slope * (i - currp)
        best = min(curr, best)
        slope += slopechanges[i]
        currp = i
        # print(i, best)
    fout.write(str(tot + best))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
