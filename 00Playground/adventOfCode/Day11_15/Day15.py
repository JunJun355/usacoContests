import re

def main():
    fin = open("Day15.in", "r")
    coor = []
    ans = 0
    inps = []
    for i in range(23):
        inp = re.split("=|:|,", fin.readline().strip())
        # print(inp)
        inps.append([i for i in [inp[1], inp[3], inp[5], inp[7]]])
        # print(" ".join(inps[-1]))
    for j in range(0, 200000):
        for i in range(23):
            curr = inps[i]
            # print(curr)
            manhattan_dist = abs(curr[2] - curr[0]) + abs(curr[3] - curr[1])
            start = curr[0] - (manhattan_dist - abs(j - curr[1]))
            end = curr[0] + (manhattan_dist - abs(j - curr[1]))
            # print(start, end)
            if start <= end:
                coor.append([start, end])
        final = []
        coor.sort()
        curr = coor[0]
        for i in range(1, len(coor)):
            if curr[1] >= coor[i][0]: curr[1] = max(curr[1], coor[i][1])
            else:
                final.append(curr)
                curr = coor[i]
        final.append(curr)
        if len(final) != 1: print(final, j)
        # print(final)


if __name__ == '__main__':
    main()
