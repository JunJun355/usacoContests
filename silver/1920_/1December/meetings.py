"""
ID: 06jajun
LANG: PYTHON3
TASK: meetings
"""


def main():
    fin = open ('meetings.in', 'r')
    fout = open ('meetings.out', 'w')

    n, p = [int(c) for c in fin.readline().split()]
    cows = []
    for _ in range(n):
        cows.append([int(c) for c in fin.readline().split()])
    cows.sort(key=lambda x: x[1])
    # print(cows)
    arrival_first = []
    arrival_second = []
    w, y, z = 0, 0, 0
    for i in range(n):
        w += cows[i][0]
        if cows[i][2] == -1:
            y += 1
            arrival_first.append(cows[i][1])
        else:
            z += 1
            arrival_second.append(p - cows[i][1])
    for i in range(n):
        if i < y:
            cows[i][1] = arrival_first[i]
        else:
            cows[i][1] = arrival_second[i - y]
    cows.sort(key=lambda x: x[1])
    # print(cows)
    # print(w)
    cw = 0
    i = 0
    while cw < w / 2:
        cw += cows[i][0]
        i += 1
    t = cows[i - 1][1]
    # print(t)
    pass
    # cow_weights = dict()
    # cow_positions = dict()
    # cow_directions = dict()
    # arrival_first = []
    # arrival_second = []
    # y = 0
    # z = 0
    # for i in range(n):
    #     a, b, c = [int(c) for c in fin.readline().split()]
    #     if c == -1:
    #         arrival_first.append(b)
    #     else:
    #         arrival_second.append(p - b)
    #     cow_weights[i], cow_positions[i], cow_directions[i] = a, b, c
    #     if cow_directions[i] == -1:
    #         y += 1
    #     else:
    #         z += 1
    # arrival_first.sort()
    # arrival_second.sort()



    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
