"""
ID: 06jajun
LANG: PYTHON3
TASK: lifeguards
"""
# * ->

def main():
    fin = open ('lifeguards.in', 'r')
    fout = open ('lifeguards.out', 'w')

    n = int(fin.readline())
    lifeguards = [[0, 0]]
    for i in range(n):
        lifeguards.append([int(c) for c in fin.readline().split()])
    lifeguards.sort()
    lifeguards.append([lifeguards[-1][-1]] * 2)
    mini = float('inf')
    currtop = 0
    currbot = 0
    for index, lifeguard in enumerate(lifeguards[1:-1]):
        # print(lifeguard, index)
        index += 1
        if currtop > lifeguard[1]:
            mini = 0
        else:
            mini = min(max(min(lifeguard[1], lifeguards[index + 1][0]) - max(currtop, lifeguard[0]), 0), mini)
            currtop = lifeguard[1]
        print(currtop)

    tot = 0
    i = 1
    curr = lifeguards[1]
    while i < len(lifeguards) - 1:
        # print(curr)
        if curr[1] >= lifeguards[i][0]:
            curr[1] = max(curr[1], lifeguards[i][1])
        else:
            tot += curr[1] - curr[0]
            curr = lifeguards[i]
        # print('-', curr)
        i += 1
    tot += curr[1] - curr[0]

    fout.write(str(tot - mini))

    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
